/* Software License Agreement
 * 
 *     Copyright(C) 1994-2018 David Lindauer, (LADSoft)
 * 
 *     This file is part of the Orange C Compiler package.
 * 
 *     The Orange C Compiler package is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version, with the addition of the 
 *     Orange C "Target Code" exception.
 * 
 *     The Orange C Compiler package is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with Orange C.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *     contact information:
 *         email: TouchStone222@runbox.com <David Lindauer>
 * 
 */

#include "AsmMain.h"
#include "AsmFile.h"

#include "Utils.h"
#include "CmdFiles.h"
#include "PreProcessor.h"
#include "Listing.h"
#include "UTF8.h"
#include <stdlib.h>
#include <io.h>

CmdSwitchParser AsmMain::SwitchParser;
CmdSwitchBool AsmMain::CaseInsensitive(SwitchParser, 'i');
CmdSwitchCombo AsmMain::CreateListFile(SwitchParser, 'l',"m");
CmdSwitchFile AsmMain::File(SwitchParser, '@');
CmdSwitchBool AsmMain::PreprocessOnly(SwitchParser, 'e');
CmdSwitchOutput AsmMain::OutputFile(SwitchParser, 'o', ".res");
CmdSwitchDefine AsmMain::Defines(SwitchParser, 'D');
CmdSwitchCombineString AsmMain::includePath(SwitchParser, 'I', ';');

const char *AsmMain::usageText = "[options] file"
"\n"
"  @filename  use response file\n"
"  /e              Preprocess only                  /i     Case Insensitive Labels\n"
"  /l[m]           Listing file [macro expansions]  /oxxx  Set output file name\n"
"  /Dxxx           Define something                 /Ixxx  Set include file path\n"
"  /V, --version   Show version and date            /!,--nologo No logo\n"
"\n"
"Time: " __TIME__ "  Date: " __DATE__;

int main(int argc, char *argv[])
{
    AsmMain rc;
    return rc.Run(argc, argv);
}
void AsmMain::CheckAssign(std::string &line, PreProcessor &pp)
{
    int npos = line.find_first_not_of(" \t\r\n\v");
    if (npos != std::string::npos)
    {
        if (line[npos] == '%')
        {
            npos = line.find_first_not_of(" \t\r\b\v", npos + 1);
            bool caseInsensitive = false;
            bool assign = false;
            if (npos != std::string::npos)
            {
                if (line.size() - 7 > npos && line.substr(npos,6) == "assign" && isspace(line[npos+6]))
                {
                    assign = true;
                }
                else if (line.size() - 8 > npos && line.substr(npos, 7) == "iassign" && isspace(line[npos+7]))
                {
                    assign = true;
                    caseInsensitive = true;
                }
            }
            if (assign)
            {
                std::string name;
                int value = 0;
                npos = line.find_first_not_of(" \t\r\b\v", npos+6 + (caseInsensitive ? 1 : 0));
                if (npos == std::string::npos || !IsSymbolStartChar(line.c_str() + npos))
                {
                    Errors::Error("Expected identifier");
                }
                else
                {
                    int npos1 = npos;
                    
                    while (npos1 != line.size() && IsSymbolChar(line.c_str() + npos1))
                    {
                        int n = UTF8::CharSpan(line.c_str() + npos);
                        while (n && npos1 < line.size())
                           npos1 ++,n--;
                    }
                    name = line.substr(npos, npos1-npos);
                    if (!isspace(line[npos1]))
                    {
                        Errors::Error("Invalid arguments to %assign");
                    }
                    else
                    {
                        npos = line.find_first_not_of(" \t\r\n\v", npos1);
                        if (npos == std::string::npos)
                        {
                            Errors::Error("Expected expression");
                        }
                        else
                        {
                            ppExpr e(false);
                            std::string temp = line.substr(npos);
                            value = e.Eval(temp);
                            pp.Assign(name, value, caseInsensitive);
                        }
                    }
                }
                line = "";
            }
        }
    }
}

int AsmMain::Run(int argc, char *argv[])
{
    int rv = 0;
    Utils::banner(argv[0]);
    Utils::SetEnvironmentToPathParent("ORANGEC");
    CmdSwitchFile internalConfig(SwitchParser);
    std::string configName = Utils::QualifiedFile(argv[0], ".cfg");
    std::fstream configTest(configName.c_str(), std::ios::in);
    if (!configTest.fail())
    {
        configTest.close();
        if (!internalConfig.Parse(configName.c_str()))
            Utils::fatal("Corrupt configuration file");
    }
    if (!SwitchParser.Parse(&argc, argv) || (argc == 1 && File.GetCount() <= 1))
    {
        Utils::usage(argv[0], usageText);
    }
    CmdFiles files(argv+1);
    if (File.GetValue())
        files.Add(File.GetValue() + 1);
    if (files.GetSize() > 1 && OutputFile.GetValue().size())
        Utils::fatal("Cannot specify output file for multiple input files");
    std::string sysSrchPth;
    std::string srchPth;
    if (includePath.GetValue().size())
    {
        size_t n = includePath.GetValue().find_first_of(';');
        if (n == std::string::npos)
        {
            sysSrchPth = includePath.GetValue();
        }
        else
        {
            sysSrchPth = includePath.GetValue().substr(0, n);
            srchPth = includePath.GetValue().substr(n+1);
        }
    }
    for (CmdFiles::FileNameIterator it = files.FileNameBegin(); it != files.FileNameEnd(); ++it)
    {
        std::string inName = (*it)->c_str();
        int npos = inName.find_last_of(".");
        if (npos == std::string::npos || (npos && inName[npos-1] == '.')
            || (npos != inName.size()-1 && inName[npos+1] == CmdFiles::DIR_SEP[0]))
        {
            inName = Utils::QualifiedFile( (*it)->c_str(), ".asm");
        }
        PreProcessor pp(inName, srchPth, sysSrchPth,
                 false, false, '%', false, false, true);
        int n = Defines.GetCount();
        for (int i=0; i < n; i++)
        {
            CmdSwitchDefine::define *v = Defines.GetValue(i);
            pp.Define(v->name, v->value, false);
        }
        std::string outName;
        if (OutputFile.GetValue().size() != 0)
            outName = OutputFile.GetValue();
        else
            outName = Utils::QualifiedFile( (*it)->c_str(), ".o");
        if (PreprocessOnly.GetValue())
        {
            std::string working = Utils::QualifiedFile((*it)->c_str(), ".i");
            std::fstream out(working.c_str(), std::ios::out);
            if (!out.is_open())
            {
                Utils::fatal(std::string(std::string("Could not open ") + working.c_str() + " for write.").c_str());
            }
            else
            {
                while (pp.GetLine(working))
                {
                    CheckAssign(working, pp);
                    out << working.c_str() << std::endl;
                }
            }
            out.close();
        }
        else
        {
            Listing listing;
            AsmFile asmFile(pp, CaseInsensitive.GetValue(), listing);
            if (asmFile.Read())
            {
                if (!asmFile.Write(outName, inName) || Errors::ErrorCount())
                {
                    rv = 1;
                }
                else if (CreateListFile.GetValue())
                {
                    std::string listingName = Utils::QualifiedFile( (*it)->c_str(), ".lst");
                    if (!listing.Write(listingName, inName, CreateListFile.GetValue('m')))
                    {
                        rv = 1;
                    }
                }
            }
            else
            {
                rv = 1;
            }
        if (rv)
            _unlink(outName.c_str());
        }
    }
    return rv;
}
