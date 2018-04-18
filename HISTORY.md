Release notes:

Version 6.0.35: 04/15/2018
* ocide:  search with replace to '\' actually replaced to ']' when in 'direct' replace mode
* ocide:  fix uninitialized variables in the replace function
* omake:  support both '\' and '/' in filenames
* omake:  support .IGNORE and .SILENT without any prerequisites
* omake:  fix bug where lines other than commands couldn't begin with the tab character
* omake:  when :: is used as a rule separator, mark the target as precious
* omake:  turn a suffix rule with prerequisites into a normal rule (used to generate an error)
* omake:  when a command in a recipe fails and '.POSIX' is not specified, keep going until the end of the recipe
* omake:  add '.LOW_RESOLUTION_TIME' special target
* omake:  add '.NOTPARALLEL' special target (displays a warning since omake won't run things in parallel)
* omake:  add '.ONESHELL' special target
* omake:  add '.POSIX' special target
* omake:  add '.RECURSIVE' special target
* omake:  add '.MFLAGS' and '.MAKEFLAGS' special targets
* omake:  add '.MAIN' special target
* omake:  add '.SILENT' target attribute
* omake:  add '.IGNORE' target attribute
* omake:  add '.DONTCARE' target attribute
* omake:  add '.MAKE' target attribute
* omake:  add '.PRECIOUS' target attribute
* omake:  add '.NOTMAIN' target attribute
* omake:  add warnings for other BSD target attributes we aren't supporting
* omake:  don't treat various GNU and BSD special targets we added as candidates for the first found target
* omake:  fix '.PHONY' special target; omake would crash when it was used
* build:  fix build with MINGW-32 to work again
* build:  fix 'omake fullbuild' to work cleanly again

Version 6.0.34: 02/02/2018
* occ:    fix problems with precision/width in printf string specifiers
* occ:    fix recently introduced problems with C++ object file generation
* install: move examples and default project into the public documents folder

Version 6.0.33: 12/10/2017
* occ:    fix problem where cast operators might not be resolved if they are cast to const arithmetic type
* occ:    when a cast operator that returns a reference type is used in an expression, the return value is not dereferenced
* occ:    flag undefined static functions instead of letting calls to them silently compile

Version 6.0.32: 11/24/2017
* occ:    alignment of a structure with no data members but with virtual functions
            should be sizeof(void*)
* occ:    std::cref<int>(...) worked if assigned to auto, but not to an variable
            explicitly declared with std::reference_wrapper<int const>
* occ:    a usage of std::mem_fn would not compile
* occ:    fix various small bugs related to handling member functions in templates
* occ:    fix expression evaluation of decltype(&struct::member) to return a pointer to member
	    as the type instead of just a standard pointer
* occ:    fix compiling of is_member_function_pointer
* occ:    fix .* and ->* when used with an immediate function name
* occ:    generated copy constructors do not copy variables declared as member pointers
* occ:    fix problem with calling __invoke directly with normal functions

Version 6.0.31: 11/09/2017
* occ:    fix problem compiling if (0 > n) where n is a long long
* occ:    alignment of a structure with no data members was calculated as -1
* occ:    std::cref did not work
* occ:    std::ratio_divide<> was not being handled correctly to to a fix to a bug for bind() - fixed both problems
* occ:    using a namespace which was using a namespace inside it, led to not being able to access the 
		identifiers from the inner namespace when the identifiers were qualified with the outer namespace

Version 6.0.30: 11/04/2017
* occ:    fix various bugs that prevented initializing a std::function with a std::bind() expression

Version 6.0.29: 11/02/2017
* occ:    templatename<int()> now resolves the int() to a function declaration rather than an initialization
* occ:    function<int(void)> = func now works
* occ:    function<int(...)> = func now works when there is more than one parameter
* occ:    bind<function, ...> now works when there is more than one argument being bound
* occ:    sometimes when searching for a template, it would match a 'reference' version of an instantiation to a
            non-reference version of the template
* occ:    typeinfo::name() returns more accurate symbolic representations of basic types

Version 6.0.28: 10/29/2017
* occ:    fix bug with 'using namespace' inside a function
* occ:    fix problem with not being able to resolve the difference between an lref and an rref
* occ:    fix crash in 'dom' routines

Version 6.0.27: 10/26/2017
* occ:    enable debug line information from declarations in C++ headers, takes care of a linker crash
* occ:    functions returning type 'auto' would not return the correct value when returning a c-style string constant
* occ:    functions returning type 'auto' would create an extra instance of return values when the return type is structured, and destroy but not create them
* occ:    if an error occurred while processing a lambda function, occ would abort while printing the error
* occ:    if a template instantiation instantiates changes to base classes, recalculate the structure size

Version 6.0.26: 10/23/2017
* occ:    remove spurious errors with iostream access when <complex> is #included
* occ:    fix a crash under certain error conditions.

Version 6.0.25: 10/22/2017
* occ:    fix problem where functions defined outside class specializations wouldn't be instantiated
* rtl:    more fixes for nl_types.h

Version 6.0.24: 10/21/2017
* ocide:  fix problem with IDE crashing during a build, when there are errors or warnings out of the C compiler
* ocide:  fix random crash due to uninitialized buffer
* occ:    fix problem with templated return values sometimes having size calculated wrong (atc example would not run in DEBUG mode)
* occ:    fix '... = &(struct myStruct) { ... }' to compile properly (the ampersand had broken it)
* occ:    fix variable length arrays to compile properly
* occ:    when a VLA is passed to a function which is unprototyped, treat it as a pointer to its first element
* occ:    enable variable length arrays in C++
* occ:    result of a hook involving nullptr was calculated incorrectly (for example unordered_set insert crashed at runtime)
* rtl:    define thrd_sleep properly and change 'xtime' declarations in threads.h to say 'timespec' to match standard
* rtl:    compile the TLS helper function properly so TLS accesses would work
* rtl:    math.h: define abs() properly for C++11
* rtl:    math.h: define some C99 functions and macros such as isinf in C++ mode
* rtl:    clean up nl_types.h so it can be included alone
* rtl:    clean up nl_types.h so it doesn't collide with wctype.h

version 6.0.23: Oct 16, 2017
* occ:    fix various internal definitions include __func__ so they would be properly processed in type comparisons
* occ:    when a relative file name in an error was processed, an intermediate directory might have the last character chopped off

version 6.0.22: Oct 16, 2017
* occ:    set __STDC_VERSION__ properly in c1x mode
* occ:    handle the /9 flag properly
* occ:    enable _Alignas (C11) and fix so that alignas/_Alignas do something useful
* occ:    when a relative file name in an error was processed, there could be duplicates of intermediate directories
* occ:    problem was introduced when inlining a function with a return statement from an if block (generated bad code)
* rtl:    in strings.h, various macros collided with string.h definitions
* rtl:    stdnoreturn.h had include guards that collided with stdbool.h
* rtl:    struct tm:  isdst should be 'false' after a call to gmtime
* rtl:    add definition of max_align_t to stddef.h (C11/ C++)
* rtl:    add definition of static_assert to assert.h (C11)

version 6.0.21: Sep 23, 2017
* occ:    fix crash when generating debug information
* occ:    set C language default to C11 instead of C89; add switch /8 to get back to C89

version 6.0.20:
* occ:    support C++ 2014
* occ:    c++11 compatibility: handle reference-to-auto properly
* occ:    c++11 compatibility: 'final' and 'override' are not counted as reserved words any more (but still function)
* occ:    c++11 compatibility: allow scoped use of strongly typed enumerations
* occ:    c++11 compatibility: fix problems with assignments and initializations
            that use structured type cast operators with and without 'explicit'
* occ:    c++11 compatibility: implement 'using typename =' for both templates and non-templates
* occ:    c++11 compatibility: allow taking sizeof a nonstatic class member
* occ:    c++11 compatibility: aggregates can have explicitly defaulted or deleted constructors
* occ:    c++11 compatibility: optimize lambda code generator by getting rid of calls to RTL helper functions
* occ:    fix problem with generating object files from sources that had
            the addresses of structure members as initialization data
* occ:    fix problem where initialization of basic types from a structured type did not search the class
		for a suitable conversion function
* occ:    fix problem where implicit cast from a structured type to a basic type during an initialization
		generated bad code
* occ:    fix bug where printf("%d\n", zz().r); generates bad code.   zz() is a function returning struct
* occ:    using decltype in an explict cast failed
* occ:    various bug fixes for access checks
* occ:    enumeration constants inside classes needed to have their access level set
* stl:    enable strong enums, relaxed constexpr, using=

version 6.0.13: April 1, 2017
* occ:    assignment to a large string variable on the stack could result in
            compiler throwing an exception during compile
* occ:    the following snippet wouldn't compile because 'type' was found as
            an argument rather than in the context of std::vector:
                int myfunc(int type, std::vector<int>&a);
* ocide:	default 'Stop First Chance' to 'no' to help dealing with windows
                components that send exceptions internally
* ocide:  don't endlessly grow the code completion database when arrays are
            used.

version 6.0.12: Mar 11, 2017
* ocide:      allow exception unrolling after first chance exception
* ocide:      reenable breakpoints when continuing after an exception
* occil:      add strong name support
* clibs:      fix msxml6.h and runtime support to handle UUIDs more generically

version 6.0.11:  Mar 5, 2017
* occ:        halve compile time for C++ programs
* occ:        fix miscellaneous crashes when compiling invalid sources
* occ:        fix make stub generation when generating for multiple files
* occ:        returning an object which was passed in by reference resulted in the
                move constructor being called on the referenced object, instead 
                of the copy constructor.
* occ:        improve errors when assigning to pointers
* occ:        operator new would not default construct non-structured types
* occ:        operator new/delete could attempt to work with structures that
                haven't been instantiated
* ocide:      fix code completion annoying popup that sometimes occurred when 
                editing a source file with syntax errors.
* ocide:      bug in ocide caused crash when compiled with Embarcadero C++

* clibs:       improve guard against multiple frees
* clibs:       declare a destructor for fstream() and call close()

* build:      builds with itself again
* build:      add Embarcadero C++

version 6.0.10: Feb 28, 2017
* occ:        fix problem where copy constructors sometimes caused a compile error
* occ:        fix problem where sometimes compiling a range based for could fail
* occ:        fix problem with for-range: 'for (auto a : *tt)' compiled incorrectly
* occ:        add delegating constructors
* occ:	    fix problems compiling std::bind
* occ:        fix problems compiling std::call_once
* occ:        fix problems compiling std::function
* occ:        fix problems with destructs and break statements
* occ:        lambda functions used inside namespaces other than the global one crashed the compiler
* occ:        allow decltype() to work on types in addition to expressions
* occ:        defining a function while specifying both a namespace and a class qualifier did not work
		the namespace wasn't used as a reference
* occ:        fix problem with templates sometimes not being instantiated
* occ:        fix many other small bugs in the C++ compiler
* occ:        fix nested anonymous unions in C++ mode
* occ:        fix so that microsoft object headers will compile in C++ mode
* install:    fix so that running the IDE as part of the install works properly
    dlpe:       generate DLLs that don't trigger problems from antivirus programs
* clibs:      reintegrate lscrtl.dll
* clibs:      align malloc'd memory on 8-byte boundaries
* clibs:      fix chdir() to handle drive letters
* clibs:      fix system() to do a chdir() instead of spawning cmd.exe for a 'cd' command
* clibs:      add msxml6.h and rtl support
version 6.0.9: Aug 25, 2016
* occ:        assigning a string to an unsized character array left the array one byte too large
* occ:        export records weren't being placed in the object files
* clibs:      dll startup was broken.   Dlls couldn't be used by .net assemblies.

version 6.0.8: Aug 22, 2016
* occ:        change the behavior on 6.0.7 to keep the original output file if 
                there were errors; otherwise delete it after the compile or replace it
                if there were no errors.

Version 6.0.7: Aug 18, 2016
* occ:        restore the operation where it deletes the output file if there are
                errors in the compile (instead of leaving a 0byte file on the file system).

Version 6.0.5: Aug 17, 2016
* omake:      don't concatenate multiple blank lines when a line ends with '\\'

Version 6.0.4: Aug 15, 2016
* occ:        fix problem with optimizing '%' operator - it could optimize away the instructions
* omake:      increase command line length from 500 to 8190

Version 6.0.3:
* omake:      fix bug where '\' in some file names was interpreted as an 
                escape character rather than a directory delimiter.

Version 6.0.2:  Aug 8, 2016
* occ:        if you specify an output file which is a directory (e.g. it has
                a trailing backslash) then occ will put output files in that directory)

Version 6.0.1: Aug 1, 2016
* ocide:      fix editor lockup

Version 6.0.0: Jul 31, 2016
* ocide:      Support C++ editing and debugging
* ocide:      rewrite of how docking windows work
* ocide:      add breakpoint window
* ocide:      add variable usages window
* ocide:      CTL-Y deletes the current line
* ocide:      CTL-T deletes the word to the right of the cursor
* ocide:      CTRL-SHIFT-1 through CTRL-SHIFT-9 mark up to nine postions in the text;
                CTRL-1 through CTRL-9 jump to them
* occ:        speed up compiles
    examples:   add ATC (air traffic controller) as a C++ example for win32

Version 5.73.1: Jun 28, 2016
* ocide:      fix a problem with undo
* ocide:      fix problems with scrolling being reset while editing images
* ocide:      fix problem with controls not being displayed properly while moving them in a dialog
* ocide:      for dialogex and menuex, would not save the controls/menu items properly when adding new ones
* occ:        fix an obscure compiler crash when presented with functions without proper argument lists

version 5.72.1: Jun 23, 2016
* ocide:      fix several crash conditions
* ocide:      fix redo to work properly
* ocide:      fix various bugs in find dialog & add new features
* ocide:      fix problem where bitmaps defaulted to 16 colors (not all colors could be used)
* ocide:      debugger fix display of enumerated values: was showing random numbers
* ocide:      fix CTL-[ CTL-] ALT-[ and ALT-] to work independently of the installed keyboard
                and not interfere with the keystrokes
* ocide:      in memory window, specifying an expression with '&' should be superfluous
* ocide:      in disassembly window, prefix all constants with 0x to show they are hexadecimal
* ocide:      properly evaluate a selection when adding to the watch window via right-click
* olink:      fix debug info:  ocide call stack, threads windows showed invalid function names
                and global variables were off as well (this was introduced with the C++ debugging info)

version 5.71.1: Jun 9, 2016
* ocide:      fix vagaries between DIALOG and DIALOGEX resources
* ocide:      fix vagaries between MENU and MENUEX resources
* ocide:      fix separators on menus to save properly in both modes
* ocide:      don't automatically attempt to convert MENU or DIALOG to their EX equivalent
* ocide:      add GRAYED and CHECKED options to menu item properties
* ocide:      change the radio button TYPE property to a SELECT MODE property
* ocide:      safely recover if the build options in a project file are corrupt
* ocide:      fix bug where opening multiple resource windows then trying to close them would hang the ide

version 5.70.1: Jun 6, 2016
* help, examples: clarify that creating new resources creates them in the style that requires
                MAKEINTRESOURCE
* ocide:      fix problem with not being able to resize images that had been zoomed  in the icon editor
* ocide:      fix problem with select all in the icon editor not selecting the entire image
* ocide:      add window to show errors more clearly
* ocide:      fix problems where windows would flicker while being resized
* ocide:      fix crash when replacing in a large selection
* ocide:      the RC file parser could not parse 'MENUITEM SEPARATOR'
* ocide:      IDE would crash when loading new resources while a resource editor was opened
* occ:        sometimes static const integral template members could be instantiated
                as empty virtual functions; then they would be initialized but overwrite other memory.
* occ:        when member data was instantiated virtually it could contain an offset into the structure
                virtual member data is separate from the structure's internal placement, so this
                would crash the program
* rtl:        add 'bad_alloc' to the msvcrt dll library so that use of operator new would work.

Version 5.69.1: 05/25/2016
* ocide:      fix crash when reloading resources

version 5.68.1: 05/22/2016
* ocide:      improve disassembly window
* ocide:      add 'locals' window
* ocide:      add toolbar for profile and build type
* ocide:      fix vagary with pressing shift while alt key was held down
                made ALT-{ and ALT-} not work reliably.  Now you don't have to hold
                the shift key down while pressing those key sequences.
* ocide:      fix some display issues with paths having ..\somedir\file
                when they only needed to have 'file'
* ocide:      run without debug not available if there is no active project
                (crashed)
* ocide:      watch info for auto variables was not available on the last
                line of a block
* ocide:      improve display redraw when undocked windows are resized

version 5.67.1: 05/15/2016
* ocide:      24-bit bitmaps not displayed properly in the resource workshop
* ocide:      always save dialogs as DIALOGEX to avoid problems with compiling the RC file
* ocide:      always save menus as MENUEX to avoid problems with compiling the RC file
* ocide:      add CTL-[ and CTL-] to open and close full-size edit window
* ocide:      augment win32 help to have three options depending on how you want to do it.
* ocide:      opening an image in the resource workshop crashed the IDE
* ocide:      when there are two projects, attempting to open resources
                from the two projects simultaneously could result \
                in errors and crashes
* ocide:      #defines weren't being replaced in version and string tables
* ocide:      when saving version info, the FILEFLAGSMASK wasn't set properly
* ocide:      clicking on a 'separator' in the menu design view 
                would crash the IDE
* ocide:      the 'tab' character separating a menu item description from
                its hotkey sequence wasn't honored.
* ocide:      load and save bitmaps with 32-bit colors (you can't edit the alpha)
* ocide:      if a menu item was dragged down onto the next lower item,
                the item would disappear and eventually the IDE would crash

version 5.66.1: 5/11/2016
* ocide:      add ALT+{ and ALT+}  for navigation between braces
    ocide, ORC: fix problems with the system menu font not understanding code pages (convert to unicode in RC file)
* ocide:      fix problems with undo not working during a long edit session
 
version 5.64.1: 5/1/2016
* Add MSDN library help

version 5.63.1: 3/19/2016
* occ:        fix problem with crash when a close brace was missing at the end of the file
* occ:        add support for expressions like a ? : b
* occ:        clean up the error handling when returning structured values the wrong way
* occ:        if you took the address of a static const var two or more times
                it would be replicated in the output file.
* occ:        if the address of a static const var is used in a global declaration,
                a bad output file would be generated
* occ:        the expression optimizer could take an extremely long time for very complex expressions
* occ:        fix a problem where a an x86 comparison opcode could sometimes be optimized to compare two immediates
* occ:        fix problems generating too-large constants in assembly language output causing assemble errors
* occ:        fix problems with csmith output: there is heavy inlining in these files and too many
                were running the compiler out of memory
* occ:        fix a problem where a bit operation was attempted to be generated with an inequality
* setup:      access ORANGEC environment variable off of HKEY_CURRENT_USER instead of HKEY_LOCAL_MACHINE
* setup:      propagate registry changes before running the IDE from the setup program

version 5.62.1: 3/3/2016
* occ:        add support for more C++ intrinsics (to increase compilation speed)
* occ:        auto did not work properly with arrays
* occ:        a newly introduce problem caused returning the return value of a 
                function that returns a structured variable to fail to compile.
* omake:      it crashed when you put '$' right before a three-character command

version 5.61.1: 2/27/2016
* occ:        fix code generation for taking windows API functions by address:
                it should generate a thunk to call through the import table when a
                call through the address is made.
* occ:        casting a pointer to a qualified func ptr (e.g. qualified with stdcall) ignored the qualifier
                whereas declaring the pointer with a stdcall type worked fine.
* occ:        couldn't compare a function address to a pointer for equality in C++ mode
* occ:        shouldn't have to cast a function pointer to void * to assign it to a variable declared as void *
* occ:        generate ASM file in lower case now
* occ:        fix problems generating invalid register sizes in the assembly language file
* occ:        clean up some cases where it should have done function overload resolution for function pointers
                and didn't.
* occ:        matching template specializations with function calls as parameters was broken
* occ:        matching a templated argument type didn't always work
* occ:        there were problems with matching functions to template specializations with functions
* occ:        const/volatile on a typedef within a class caused an error
* occ:        function<...>  didn't match a structure with a matching operator () in argument matching
* occ:        in c++ mode, when an untagged structure is used to define a variable,
                don't expose the variable to the linker (make it local to the file).
* occ:        fix problem where incomplete return statements could crash the compiler       
* occ:        improve handling of 'tuple' templates
* occ:        fix problem where sometimes a call through a pointer would be
                inline expanded (incorrectly)
* occ:        fix problem where returning a boolean by reference crashed the program
* ocide:      fix problem with crashing while typing in a return statement;
* oasm:       fix problems assembling some C++ code
* ocide:      clean up shutdown, fix problem where it hangs in memory after shutdown sometimes
* ocide:      fix build so build with self works on OCIDE
* olink:      update the name unmangling to match current compiler
* omake:      add option to keep response files
* dlpe:       when you specified a .def file, it wouldn't generate an output file
* examples:   add delegate.cpp
* demos:      properly compiles sqlite3 now

version 5.60.1: 2/6/16
* occ:        package compiles itself now, and the results can be used to build other files
* occ:        speed up aliasing code; compiles itself faster now
* olink:      speed up processing of C++ files by an order of magnitude

* occ:        exception table pointers were not being placed in the vtab. (typeid failed)
* occ:        address of structures could get an extra dereference when accessed as a reference member
* occ:        cast operators would not be called as part of a return statement.
* occ:        could generate the exception handling structures for C++ on non-dword boundaries,
                and windows does not like this. (exception handling broken)
* occ:        didn't throw non-structured types properly
* occ:        smart exception table generation for functions that don't allow exceptions to be thrown
* occ:        add profiler functionality
* occ:        taking the address of a templated function could cause the function to be undefined
                in the object file if the address was taken as a function argument.
* occ:        fix problems with aliasing of structure assignments
* occ:        declarations like : int a[][]; where multiple braces are empty could crash the compiler
* occ:        do branch optimizations at the beginning of the optimizer pass; this will result in better
                optimizations.
* occ:        sometimes as with a return at the end of the first part of an if statement
                multiple gotos could be generated in the back end, and this would confuse the flow analyzer and
                result in invalid code being generated.
* occ:        treat nullptr_t as a first-class citizen in function arguments (argument matching
                was allowing nonnull pointers to match)
* occ:        fix problems the types of template selectors that are found in the shared_ptr constructors
* occ:        fix problems with internally generated qualifiers on class assigners causing a crash
* occ:        remove some test code that performed an infinite loop
* occ:        if a pointer to a structure was returned from a function, the copy by rvalue would be done instead of copy by lvalue
* olink:      virtual sections were not matched to externals in the same file, so they would be dragged
                out of a library if they existed in the library and this could cause collisions
* oasm::       virtual sections were sent to the object file with the wrong attributes, so link failed
* ocide:      fix problem with 'flashing' gui
* ocide:      fix database problems: colorization and hints were broken
* ocide:      fix ctrl-f and ctrl-h to do the expected thing when the find/replace window has focus
* ocide:      after a replace in selection, restore the selection.
* ocide:      after a replace in selection, don't scroll the screen.
* ocide:      debugger: stepping over a windows function call didn't stop after the call.
* ocide:      call stack window function name list doesn;t work for static functions
* ocide:      call stack window can correlate last line of a function to first line of next function
* ocide:      when bringing up find/replace window, fetch word under cursor (or word in toolbar)
* occpr:      fix crash condition
* clibs:      couldn't throw a non-structured type without it crashing.
* clibs:      fix profiler to work with orange c; fix problems in profiler code; Use QueryPerformanceCounter
* clibs:      set_unexpected would set the unexpected handler but return the terminate handler
* clibs:      realloc(ptr, 0) did not free ptr and return NULL.
* clibs:      fix the definition of NEWTEXTMETRICEX

version 5.52.1: 1/22/16
* occ:        expressions involving bit fields did not get evaluated properly
                unless the expression was an assignment or comparison
* occ:        fix bug with operator-> returning pointer to class: if this was used as
                a function argument bad code would be generated
* occ:        move constructors or assignment operators could sometimes be called when unintended
                when invoked in a return statement.
                (e.g. it would zero out strings during a construction or copy to another string)
* occ:        there were bugs comparing a member pointer variable against zero
* occ:        member pointer function variable could not be compare to a function
* occ:        for a reference type, it didn't call virtual functions properly
* occ:        sometimes an object would be considered by-ref when it wasn't really
                messed up function returns from constructors and other functions that return a pointer
                to structure
* occ:        during global destruction of objects, destructor call for an array could zero 
                out the object before destroying it
* occ:        constructor calls qualified with class/namespace selectors could be treated as declarations
* occ:        references to member pointers as function parameters resulted in invalid code
* occ:        taking the address of a reference to a pointer and passing it to a function resulted in bad code
* occ:        in initializing a structure from another structure, a this pointer could be inserted when it shouldn't be
* occ:        temporary classes created during an expression would not get a destructor call
* occ:        ! and some other unary operators generated code to perform the function even after
                calling an overloaded operator function. (so the function got applied twice)
* occ:        when objects that have to be constructed are default parameters, the
                space for the objects does not get allocated if they are used.
* occ:        fix bug when using function arguments as function arguments to an inline function.
* libcxx:     fix problem with not enough space being allocated for locale in ios structure
* clibs:      fix malloc/free to detect doubly freed pointers with more alacrity
Version 5.51.1: 1/16/16
* occ:        fix a compiler crash when compiling boolinq.h
* occ:        trailing return did not parse correctly if the function had a qualifier, e.g.
                if it was a const function (fix for cpplinq.hpp)
* occ:        lambda functions defined at global scope would crash the compiler
* occ:        initialized structures involving substructures could crash the compiler
* occ:        fix some problems with typedefs being used to denote base classes
* occ:        auto variables of class and template type were problematic when used inside lambda functions
* occ:        lambda functions without a trailing return would not get an inferred return type
* occ:        size of an unsized array was calculated as number of bytes not number of elements when used
                in a template parameter
* occ:        overloaded functions found in different namespaces would be ambiguous even
                without the same signatures
* occ:        if an overloaded symbol was found in the main namespace,
                'using' namespaces wouldn't be searched.
* occ:        new of pointer type didn't work (e.g new char *[10])
* occ:        specifying an exception specifier with an undefined type crashed the compiler
* occ:        uninitialized unsized arrays found in a structure definition could crash the compiler
* occ:        class objects at global scope could sometimes generate bad code for the constructor call
                (would not link)
* occ:        overloaded cast operators didn't work
* occ:        there were problems with member pointers in nested classes
* occ:        nonconst variables declared inside a const function were considered const variables
* occ:        if the first type in a map declaration was a string, the [] operator didn't work on literals
* occ:        ::id()   didn't work when id was both a global function and a class member variable
* occ:        cast operators might not be resolved when duplicates are found due to a
                virtual base class being included twice 
* occ:        creating a cast function with an undefined type crashes the compiler
* occ:        initializing a member pointer with NULL could cause the compiler to crash.
* occ:        there were problems with instantiating a template that was previously declared 'external'
                (link errors)
* occ:        a template class that included template functions did not compile properly if the
                instantiation took place within an argument in a class member function
* occ:        'template' and 'friend' together sometimes resulted in unfindable functions
* occ:        fix some problems compiling manipulators
* occ:        compiling an argument style class initializer with the first argument being an explicit constructor
                caused the declaration to parse as a function instead of a class initialization.
* occ:        allow initialization of references to memberpointers
* occ:        returning a reference to a member pointer may not work
* occ:        inlined friend templates were treated as extern when no definition appears outside the class
* occ:        const and nonconst args were ambiguous when the argument matching involved a derived to base conversion
* occ:        missing template types e.g. as a result of a 'false' arg to enable if were not always counted as missing
* occ:        fix problem with sometimes not flagging virtual functions as virtual (caused invalid output file)
* occ:        fix some problems compiling variabidc template parameters properly
* occ:        fix problem with optimizer memory being accessed out of range (could rarely crash compiler)
* omake:      change references to 'override' to 'dooverride' to avoid keyword clash with C++2011
* clibs:      put the initializer_list definitions into the libcxx inline namespace
* clibs:      move __argc and __argv and _environ to the global namespace
* clibs:      add IMAGE_SCN and IMAGE_SUBSYSTEM definitions to win32 headers

Version 5.50.1: 12/27/15
* occ:        many changes to templates et.al. made to fix bugs while compiling libcxx
* occ:        fix problem with control statements: an unbracketed statement
                right after the control statement could not be preceded by a label
                (change to compile TCC)
* occ:        generated copy constructors would not copy members that were member pointers
* occ:        initialization of an auto array did not result in unused chars being zeroed
* occ:        cast operators located in a base class did not get the correct THIS pointer when called
                on a derived object
* occ:        optimizing out the 'default' clause of a switch statement can result in a crash during inlining
* occ:        a template function that starts with a switch crashes compiler
* occ:        a non-virtual base class of a virtual base class that was inherited multiple times caused a compiler error
* occ:        fix problems with initialization by constructor argument being treated as a function
* occ:        assigning the return value of a function to a member pointer var resulted in a 'need lvalue' diagnostic
* occ:        when a map is created with a first template parameter of 'const std::string'
                the bracket operator does not work on arguments of type 'char *'
* occ:        virtual functions shouldn't be inlined
* occ:        in C mode don't do an exact match of function arguments for pointers to functions
* occ:        problems when a variadic template argument varied in both type and value
* ocide:      adjust sources to compile with OCC
* occ:        adjust sources to compile with OCC
* orc:        add switch to specify default language settings
* clibs:      add WIN32 support for TCC
* clibs:      if a memory block was freed twice, a subsequent malloc might enter an infinite loop

Version 5.42.1: 10/09/15
* occ:        many changes made to fix bugs while compiling libcxx
* occ:        fix problem with bogus code gen when doing an unsigned div of a constant
* clibs:      strcat() did not work if the destination was an empty string not 
                on a 4 byte boundary
* clibs:      ctype macros needed to be turned off when compiling for MSVCRT.DLL 
                or CRTDLL.DLL (isspace and friends did not work)
* clibs:      msdos stdio file handling was broken for the default handles, 
                so for example printf and scanf wouldn't work
    
Version 5.41.1: 09/04/15
* occ:        fix member pointer handling in general - both parsing and code gen was broken
* occ:        add an error if trying to implicitly take the address of a member function
* occ:        allow matching of the arguments to pointers to function in template matching
* occ:        allow matching of pointers to class members and any arguments in template matching
* occ:        fix some problems where explicit use of explicit constructors still caused an error
* occ:        fix typeid with class types to use the XT table of the object instance when available
* occ:        instantiation of multiple functions in a class with packed template args 
                could result in bad code
* occ:        &cls->memberdata returned the wrong value when memberdata was a reference type
                (not dereferenced)
* occ:        fix problem compiling declarations like int (*(xx))() where the pointer 
                variable is surrounded by parenthesis
* occ:        anonymous structures and unions declared inside functions resulted in an error.
* clibs:      problem with fopen caused problems if you opened a TTY, and put all other files
                in linebuffered mode which resulted in a significant performance penalty
* clibs:      creat() without S_IWRITE made the file readonly
* clibs:      speed up printf() and friends with ints and doubles by using better algorithms
* clibs:      speed up atof() by fixing a bug that made it flush the mantissa to float too soon
Version 5.40.1:  8/9/15

* occ:        multiplies were not being converted to shifts for powers of two
* occ:        optimize a sequence of store to memory followed by load from same memory
* occ:        perform aggressive inlining as a speed optimization
* occ:        fix problems where backend constant folding did not always fold constants
* occ:        fix problems with taking the address of an inlined function
                the function was not instantiated
* occ:        fix problems with prototyping an inline function after it has a body
                the code generation would be incorrect
* occ:        fix problems with not adding extensions when the file name had extra '.' characters
                the compiler would use incorrect file names and become confused
* occ:        fix bug in divide signed value by power of two (could result in the wrong answer)
* occ:        fix bug where complicated critical sections that had been removed 
                as dead code were later processed again
* occ:        returning 0 from a function returning long long was broken
* occ:        don't allow inlining of functions with variadic parameter lists
* oasm::       fix problem with fixed up values not being displayed correctly in the listing file

version 5.39.1: 8/4/15

* system:     recompile with various compilers
* occ:        fix name unmangling of references and pointers to template names
* occ:        fix __inline keyword to work properly
* occ:        C99 inlines didn't inline
* occ:        prototyping a function after it has an inline body resulted in inlining not working
* occ:        add reference qualified functions
* occ:        fix various C++11 parsing bugs
* occ:        add errors when trying to bind an lvalue to an rvalue reference
* occ:        int f(int &&);  f(5); did not resolve the function call
* occ:        in some cases 'decltype' was being treated as an expression
* occ:        int nn (int (int)) didn't resolve the parameter of 'nn' to a function pointer.
* occ:        decltype((*x)()) wouldn't parse correctly
* occ:        enable decltype(some template expression) as a return value from a template function
* occ:        static_assert:  allow string concatenation
* occ:        static_assert:  don't emit an error while initially parsing a template
* occ:        disable various errors while initially parsing templates
* occ:        enable the 'enable_if' style template expansions when used as a default in template parameter list
* occ:        don't make an error if a using statement appears more than once
* occ:        various variadic template fixes
* ocide:      fix problems with the code completion compiler crashing
* ocide:      fix annoying problem where focus could be 'stolen' while code completion compiler is running
* olib, oimplib, olink: rewrite dictionary handling
* coff2ieee:  rewrite dictionary handling

version 5.38.1: 05/14/2015
* occ:        when a structure or union is inside another structure or union, the
                size of the inner structure or union could be miscalculated in C++ mode.
* occ:        an enumeration defined inside a structure got allocated twice
* occ:        ignore utf8 file marker instead of making an error
* occ:        allow non-type template parameters to go unnamed
* occ:        fix problem where instantiated templates used as base classes
                would cause a 'needs specialization' error
* occ:        fix crash when placing things into inline namespaces
* occ:        search inline namespaces properly
* occ:        allow __VA_ARGS__ for C++ preprocessor
* occ:        add char16_t and char32_t as keywords for C++
* occ:        'typename templatename<T>::vv' was not properly interpreted as a type
* rtl:        fix cassert to not cause an error

version 5.37.1: 5/3/2015
* occ:        global arrays of objects could get initialized more than once/
                compiler could run out of memory when compiling them
* occ:        an stl container used for the first time inside a class could cause a hang when
                for-each was used to iterate through it.
* occ:        clean up variadic template support
* occ:        allow more than one level of nesting for initializer-lists.
* occ:        modulus of a negative integer by a power of two resulted in a number with the wrong sign
* occ:        use multiplicative inverse for modulus functions as well
* occ:        'for (const auto& v : c)' generated errors because of the const and the reference
* occ:        statements such as 'return a + myfunc(b,c)' would not work when a,b,c 
                are all structures and myfunc returns a structure and the return returns a structure
* occ:        initializations of a typedef'd structure could get into an infinite loop, 
                running the compiler out of memory
* rtl:        improvements to win32 structures and include stdlib.h in windows.h
* rtl:        copy size_t to root namespace when it is defined

version 5.36.1: 4/25/2015
* occ:        replace divide by constant with multiplicative inverse
* occ:        fix problem with implicit casting:  using an int constant as an 
                argument wouldn't be cast to float or double properly
* occ:        fix problem with passing a structure as an argument to a function declared with ...
* rtl:        correct definition of fpos_t for standard usage
* rtl:        add itoa and friends to cstdlib.h

version 5.35.1: 4/22/2015
* occ:        fix crash when using auto in a forrange statement and the selection type is undefined
* occ:        fix crash when compiling with debug information

version 5.34.1: 4/19/2015
* occ:        lambda functions didn't work in conjunction with STL templates such as std::for_each
* occ:        fix lambda helper functions to use correct naming convention
* occ:        for (auto n : mycollection) didn't compile - complained n was not initialized
* occ:        for ( type n : mycollection) was buggy for various edge cases
* occ:        add initializer_list support
* occ:        in '&(a += b)'  it would take the address of a, but not add b in first.
* rtl:        add initializer_list header and constructors to containers

version 5.33.1: 4/11/2015
	general:	fix errors when compiling the package with various compilers
* occ:        C++ fixes
* ocide:		don't colorize #if #else #endif blocks if colorizing is turned off
* ocide:		if an edit window is resized that has line numbers, redraw the line numbers
* ocide:		fix problem where #if #else #endif block processing could result in
				random lines becoming grey
* olink:      speed up linker
* olink:      optimize C++ programs for size
* rtl:        C++ fixes
* rtl:        fix scanf("%c", &c); it would look ahead one character which required that something be typed at 
                the console if processing the '\n' character at the end of a line.

version 5.32.1: 03/24/2015
* olink:      add the system library path to the front of the include path list, instead of replacing it
* ocide:      fix potential crash condition when switching projects
* ocide:      fix several compiler properties that would show as blanks when the IDE was reopened
* coff2ieee:  handle unique COMDATS like normal sections, and define their symbols
* rtl:        add __alloca_probe and friends; add security stuff to msvcrt.l

version 5.31.1: 03/21/2015
* occ:        if a multiply of two constants made it to the back end (e.g. when not optimizing), 
                code generation would be incorrect
* occ/occpr:  could crash if a return statement was incomplete, e.g. for 'return( }'
* occ:        using __cdecl on a function in an extern "C" block turned it into a C++ function
* olink:      default case sensitivity to TRUE
* coff2ieee:  automatically rename _WinMain@16 to WinMain to handle the difference in name mangling
* ocide:      took care of an allocation error that could cause project settings to change randomly
* ocide:      disable code completion inside strings
* ocide:      add an option to allow automatic variables to be bolded or italicized
* ocide:      cause a project to be rebuilt if files have been removed from it
* oimplib:    allow '@' to be inside names in the def file.   But not at the beginning...
* rtl:        global_unwind was in the data segment
* rtl:        add many C99 and C++ functions to msvcrt.l
* rtl:        added more imports from msvcrt.dll, kernel32.dll and user32.dll to allow linking with microsoft files

version 5.30.1: 3/12/2015
* rtl:        sscanf was broken for floating point numbers

version 5.29.1: 03/12/2015
    create new program 'coff2ieee' to convert msvc object files to ieee format
* occ/dlpe:   minimize import thunking to support the import format in microsoft object files
* olib/olink: debug information in a library was sometimes parsed incorrectly
* olink:      optimized library searches, much faster when parsing libraries now
* ocide:      add CTL-F1 to navigate to the help documentation for a windows function
* ocide:      add more colorization options
	* ocide:		fix problem with sometimes crashing when selecting text backwards in the editor and deleting it
* rtl:        add minimal support for vs2010 object files

version 5.28.1: 02/25/2015
* occ:    fix memory allocation in register allocator to not grow without bounds
* occ:    increase macro buffer size to 128k - openjpeg.l used > 64K in an input sequence
* occ:    make anonymous type names random to support reuse of same declaration in same header file
* occ:    if specifying a file to compile that is in another directory, put the output files in the current directory
* occ:    debug info was broken

version 5.27.1: 2/21/2015
* occ:    add wildcard processing to command line
* occ:    allow arithmetic on 'void *' (treat as char *)
* occ:    c99:  if an index variable was defined in a for statement, it would not get optimized into a register
* occ:    variables referenced inside a sizeof() expression should not be marked as externs
* occ:    c language: allow structures without members (but they have size 0)
* occ:    allow empty initializers for structures and arrays
* ocide:      create the orange c projects directory if installing from ZIPPED executables file
* install:    fix so that OCIDE would work if installed from the ZIPPED executables file
* install:    add the appdata directory to the ZIPPED executables file 

version 5.26.1: 2/16/2015
* occ:    package now compiles 'lame' and 'x264' correctly
* occ:    allow linkage specifiers to be specified multiple times.
* occ:    autoincrement/decrement of floating point numbers did not work properly
* occ:    fixed minor bug in optimizer for floating point, introduced last version
* occ:    in c++ mode using a variable with an enumerated type as an array index didn't work
* occ:    fix problem with loop invariant code motion being too liberal
* occ:    fix problem with floating point comparisions that were not part of a control statement
* occ:    c99: allow variable length macro arguments list to be length zero
* occ:    replacing __VA_ARGS__ would terminate a replacement sequence
* occ:    inline functions with parameters of type 'array' crashed the compiler
* occ:    fix c99 designator syntax to compile properly
* occ:    fix c99 cast to structure initialization not to crash
* occ:    macro invocations that spanned lines could fail with an error
* occ:    fix pointer aliasing code to deal with multiplies by zero making it through from the front end
* occ:    relax the requirement that an index variable declared in a for statement be immediately initialized
* occ:    promotion of integer initializations to constant values won't occur unless the declaration is static storage class
* occ:    initializing an auto variable of structured type didn't erase the uninitialized portions of the structure
* occ:    put a limit on the size of functions that may be inlined.
* occ:    fix problem in constant propagation: size of constant could change, disrupting function calls
* occ:    c *= a * b would convert the rhs to the type of c before doing the *= (sometimes resulting in truncation)
* occ:    when the compiler invoked the linker, files on the command line specified with .\ 
            (e.g. .\test.c) wouldn't be passed to the linker properly
* ocide:  fix crash when trying to add an array element to the watch window (example: argv[0])
* clibs:  add InitializeCriticalSectionAndSpinCount
* clibs:  update printf of floating point numbers to make it faster
* clibs:  fix definition of S_ISREG & friends to make it more friendly

version 5.25.1: 2/10/2015
* occ:    some floating point optimizations - moves without involving FPU, reordering
* occ:    reduced register pressure during calls embedded in expressions
* occ:    minor loop optimization - register was getting copied to another register
* occ:    allow floating point parsing to parse constants with very large mantissas
* occ:    allow taking the address of an assignment, preincrement, or predecrement expression
* clibs:  sanitize C language headers for use with C++
* clibs:  speed up an very slow atof

version 5.24.1:  2/2/2015
* ocide:  'make' of a project wouldn't work unless a full make had been done first.
* ocl:    wouldn't run on DOS properly
* dlpe:   wouldn't find dpmist32.bin

version 5.23.1: 1/25/2015
* ocide: new feature: project auto dependencies and calculate build order
* ocide: update documentation/pictures to latest gui and add project auto dependencies
* ocide: when a file was edited, old dependencies weren't being removed.
            This could cause compilation where none was needed when the old dependency was modified
* ocide: dependencies weren't being calculated properly, when they were on the include
            path rather than in the project.
* ocide: when adding an existing file, immediately scan it for dependencies
* ocide: when changing project properties (e.g. the include path) recalculate the project
            dependencies
* ocide: remove 'exit process' dialog from debugger, show exit status in information window
            'exit process' is still in the 'run without debug' view.
* ocide: on the right-click from the edit window 'add to watch',
            pop up the add watch dialog if the word under the cursor isn't a known variable
* ocide: gray out the 'remove from watch' item if you didn't click on an item 
            that could be removed
* ocide: change text of a button from 'build all' to 'make' in the toolbar.
* ocide: resource files with non-standard control names couldn't be reloaded after save
* ocide: some resource file comments disappearing
* ocide: don't allow workarea to be reloaded while debugging
* ocide: when 'remove all bookmarks' is pressed, prompt to see if that is the intended activity
* ocide: fix crash when trying to rename a project in the workarea window
* ocide: fix crash while loading resource file
* ocide: fix crash when loading invalid work area from command line
* ocide: opening the debug/memory window could crash the IDE
* ocide: when using tabbed windows, don't switch back to nontabbed mode0
* ocide: generated makefile did not work with 'include' paths
* ocide: generated makefile can be saved in more locations than before
* occ:   prototyping a function, then prototyping it again inside another function body
           would fail with an error
* omake: quoting an existing file as a dependency results in the dependency not being resolved
* clibs: add more to win32 headers

version 5.22.1: 01/19/15
    general:    increase compatibility when building the tools with openwatcom
* ocide:  ungray 'make' and 'rebuild' and 'build active project' in menus
* ocide:  adjust right click version of 'make' and 'rebuild' to make the 
            selected project instead of making/building everything
* ocide:  fix 'generate make file' to work with non-relative paths and paths 
            with spaces in them
* ocide:  stepping over a function such as gets() that asks for console input 
            would leave the 'stop debugging' icon available, and if you pressed 
            it the IDE would lock up.
* ocide:  make '.l' files in projects a dependency of the project EXE to help 
            the make process work better
* ocide:  editor: only need to click once on the tabs at the top of the screen, 
            to change the file being viewed
* ocide:  editor: holding shift down and left-clicking will select lines from 
            the old cursor position to the new one.
* occ:    alloca and _alloca changed to __alloca in the compiler keyword list, 
            then defined again as a preprocessor define in 'malloc.h' to match GNU-C
* occ:    more work done on C++ STL compatibility (work in progress)
* omake:  exit if the dependency nesting is too deep, as it is likely due to recursive rules
* omake:  support quotes on rules and dependencies - the quotes are part of the name
* olink:  fix bug where a ".l" inside a file name (not at the end) would cause a crash
* olib:   fix bug where debug info of structures inside a library would cause 
            the link stage to fail
* olib:   fix bug where +- with fully specified paths could fail
* clibs:  make adjustments for having changed 'alloca' to a #define    
    documentation:  document predefined preprocessor definitions in various places

version 5.21.1: 01/14/15
* occ:    invariant code motion optimization fixed and put back in the code
* occ:    the constant '0 || 0' would not be evaluated at compile time and
            in some contexts would cause an error about needing a constant value
            (compiles lpng now)
* occ:    allow #defines to be utilized properly inside the quotes on #includes
* occ:    make some improvements that speed up the comparison part of generated loops
* olib:   fix 'replace' mode to add a file if it doesn't already exist
* ocide:  fix problems with building static libraries
* oasm::   update preprocessor
* orc:    update preprocessor
* clibs:  add InterlockedCompareExchange
    
version 5.20.1: 12/7/14
* general: use fflush() liberally throughout to speed disk access
* general: fix sources to compile with OPENWATCOM & MINGW compilers
* general: switch to #include <sstream> instead of #include <strstream> when 
             possible (e.g. except when utilizing OPENWATCOM)
* occ:    defining the same typedef inside of multiple functions resulted in 
            an error
* occ:    rewrite inlining code to make it work better
* occ:    basic support for C++ (no debugging, may have some bugs)
* occ:    fix problem where using debug information while specifying multiple 
            files on the command line would crash the compiler
* occ:    fix problem where browse information would take exponential time due 
            to excess list traversal
* occ:    "array[*index++] ++;"   would increment 'index' twice.
* occ:    don't expand inline functions when generating debug code
* occ:    typing "int a int b;" at the beginning of a function body
            wouldn't result in an error in C99/C11/C++ mode
* occ:    conversion of integers to pointers and vice versa in a function argument
            was allowed with a warning.   Now it is an error.
* occ:    add make dependency generation similar to gnu C
* occ:    fix all the bugs in the string merging algorithm
* ocide:  prettifying/ use default shell font throughout
* ocide:  default to Consolas font for edit windows on vista/7/8, use 
            bitstream mono font on XP.
* ocide:  fix a crash that could occur if you debug a file that was built in release mode
* ocide:  fix a crash that could occur when closing windows
* ocide:  fix a crash due to multiple threads doing a find simultaneously
* ocide:  fix crash that could occur sometime after removing the 'startup' project
* ocide:  fix crash that could occur when clicking the arrow in the title bar
            on for example the build window
* ocide:  fix crash that could occur when debugger's "stop running" button was pressed
* ocide:  fix crash that could occur sometime after doing a multi-file replace of text
* ocide:  fix random crash in BCC32 compile due to use of the dlawrence memory allocator
* ocide:  fix random crashes due to multiple threads utilizing the open window list
* ocide:  fix various problems with string resources
* ocide:  fix various problems with accelerator resources
* ocide:  fix various problems with menu resources
* ocide:  fix various problems with dialog/control resources
* ocide:  fix various problems with image editor
* ocide:  allow editing font-related meta data
* ocide:  fix problem when specifying the \0 at the end of a version resource string
* ocide:  fix problem parsing generated versioninfo structures
* ocide:  fix problem when changing a resource id from the property window
* dlpe/orc/* ocide: fix problems where version information wouldn't be displayed 
            in OS file details window
* occ/ocide: allow looking at variables declared in for statements (c99)
* occ/ocide: allow looking at variables declared in 'static' functions 
* occ/ocide: improve debugging of control statements
* olink/ocide: fix debug type information
* ocide:  set debugger's 'stop on exception' to default to 'yes'
* ocide:  debugger: adjust the search for lines matching an address to use the next lower
            line if the PC isn't parked exactly on a line's first address.
* ocide:  if a symbol is not found in the statics of the current file or the globals
            do an unqualified search of all statics to see if it can be found anywhere
* ocide:  allow debugger to stop cleanly when program is still running
* ocide:  enable code completion again (it was broken during code cleanup)
* ocide:  don't close code completion window so gratuitously, but close if a 
            non-symbol character is typed
* ocide:  enable find-next immediately after opening ide
* ocide:  enable finds in files without an extension
* ocide:  editor:  in typeover mode, typing at end of line will insert 
            characters on line instead of typing over the end of line character
* ocide:  resolve disparaties between find and find in files
* ocide:  fix problems with context sensitive help not being right in some
            dialogs
* ocide:  fix problems with cancel buttons on the external tools dialogs not working
* ocide:  default new files to a format notepad can read properly
* ocide:  when selecting an error from the information window, the cursor
            might move to the wrong line if lines were inserted or deleted
* ocide:  fix backups of project and workspace files
* ogrep:  when the -d option was used with an explicit filename, ogrep would
            complain 'file not found' in any directory that didn't have the file
* orc:    allow specifying extended font parameters on the DIALOGEX FONT line            
* orc:    allow path specifications in file names
* oasm::   __db was considered same as 'db' and so forth...
* omake:  add support for common TREE builds
* clibs:   fix _beginthreadex to return the thread id properly
* clibs:  add a #define for the more or less standard variable 'environ'
* clibs:  add a bunch of C++ templates and support functions
* clibs:  no longer distributing lscrtl.dll
* examples: fix xmlview example

version 5.0.10: 3/29/14
* misc:   various code cleanup and improvements suggested by Kirill Joss
* misc:   include dlea allocator in most C++ apps (borland compile only)  this helps speed it up
* occ:    inlining functions that took the address of parameters was broken
* occ:    fixed bug with optimizing of inlined functions generating incorrect code
* occ:    fix so that external references will show up in the output file when included with a C++ using directive
* occ:    fix bug where debug info of arrays was wrong
* occ:    fix basic types in debug information
* occ:    fix bug in register allocation that may speed up the compile
* occ:    fix problem with generating DOUBLE sized constants for negative FLOAT constants
* occ:    fix some error messages
* ogrep:  fix crash under some circumstances
* olib:   fix bug that caused libraries to be generated incorrectly, this will probably also speed up links
* olink:  fix bug where a debug info table that didn't exist was referenced
* ocide:  fix find dialog to not crash when invoked
* ocide:  after debugging, a build would not work (said file in relative format)
* ocide:  show types in watch window correctly
* clibs:  fix fputc and friends to match const correctness in headers
* clibs:  remove some shellapi stuff from the main windows headers
* build:  remove all references to PEPATCH
        
version 5.0.9: 12/1/2013
* ocide: fix problem where function prompt window would go away randomly
* ocide: handle parenthesis when in function prompt window
* ocide: save the text of find and replace more consistently
* ocide: fix code completion for structures with bit fields (it was recently broken)
* occ:   fix problem with two labels in a row generating errors
* occ:   fix crash with forward declared labels in inline assembler

version 5.0.8: 10/3/2013
* occ: fix problem where using a global's address but never its value in a function
         could crash the optimizer
* occ: fix C++ function-like operator to work
* occ: further work on constructors and destructors
* occ: fix bug where stack framing could be off on rare occasions
* occ: allow taking the address of a thread local variable
* occ: varname || 0 would be optimized to FALSE
* clibs: add coinitialize and friends back into windows.h


version 5.0.7: 06/19/2013

* occ: make __DATE__ work like asctime as per the spec
* occ: more preprocessor fixes ported from cc386
* occ: allow unsigneds in preprocessor expressions
* occ: fix #line directive, could overflow a buffer
* occ: improve parsing of floating point numbers
* occ: floating point improvements from Frank Uberto
* occ: when a function returning floating point was called without using
            its return value, the value would remain on the floating point stack.
* occ: fix inline functions with local vars that are of structured type
* occ: add __inline keyword
* occ: fix nested inlines, where the inlines have local variables
* omake: fixed command line switches to work again

version 5.0.6: 06/05/2013
* occ:    fixed type of __func__ to use const correctly
* occ:    fixed aliasing, wasn't handling parameters right...
* occ:    improved preprocessor, now compiles many tests from mcpp
* occ:    predefine _WIN32 again
* occ:    compiles itself properly again
* occ:    fix problems with pushing 16-bit values on stack
* infopad: fix funky array and page keys behavior

version 5.0.5: 06/04/2013

*            fixes as per Franck Uberto
* occ:    improve handling of trigraphs and digraphs
* occ:    improve #define processing
* occ:    improve search order for #includes
* occ:    improve floating point handling
* occ:    ! (not operator) would sometimes cast the argument down, losing high order bits
* occ:    allow declaration of externs with incomplete type
* occ:    sped up compile of sqlite3
* occ:    sped up aliasing
* occ:    make -1.0 an intrinsic value
    orc:    &tools in general - searching complex paths could lead to lockup or crash
    ocpp:   make it friendly to avast, fix it to parse the correct configuration file
* clibs:  improve various functions, add various functions, improve various headers
* clibs:  use floating point emulation for floating point functions that convert a number to ASCII

version 5.0.4: 5/25/2013

* occ:    add support for #pragma pack syntax with keywords push and pop 
		(i.e. #pragma pack(push,1), #pragma pack(pop)
* occ:    static initialization of anonymous unions was broken
* clibs:  fix problems with asctime and ctime not working

version 5.0.3:
* ocide:  workaround for i.e. flagging help files as dangerous content
* ocide:  fix bug with debugger sometimes crashing

version 5.0.2:
* ocide: fix problems with help files, help/about

version 5.0.1:

* ocide: with RC Editor, many many bug fixes and some new features


version 4.2.1:
* occ:        fix '--(char *)myvar;' to work again
* occ:        sequences of the form:
                    void *a();
                    return (long long)a();
                resulted in bad code
* occ:        casting an integer constant to void * within a function argument
                resulted in a warning
* occ:        "#pragma rundown aa" would crash the compiler if aa was undefined
    olink:      fix bug where section alignments could be off
* rtl:        add threads.h & its functionality
* rtl:        add stdatomic.h & its functionality
* rtl:        add uchar.h & its functionality
* rtl:        add aligned_alloc
* rtl:        add at_quick_exit and quick_exit
* rtl:        increase maximum number of atexit functions to 100
* rtl:        add support for exclusive file access
* rtl:        fix problems with wsprintf and friends not producing legible output
* rtl:        updated wsprintf, wsscanf and friends to latest
* rtl:        changed byte order of fputwc (and thus all wide character output functions)
                to be little endian.
* rtl:        updated wcs versions of atoi and atof and friends to latest 

version 4.1.25:
* occ:    miscellaneous internal improvements
* occ:    improved how casts are parsed
    ocpp, orc, oasm:    fix '#if defined(MYDIR)'  when MYDIR is defined
    orc:    wasn't concatenating strings when they came one after the other
    orc:    fix NOT keyword to do a one's complement

version 4.1.24:
* occ:  in C99 mode, __VA_ARGS__ not handled properly
* occ:  fix "int a = b + c; int j = sizeof(double[a]);" to work in C99 mode...
* occ:  allow (void)myStructVar to work
* occ:  improve the accepted sequencing of storage class specifiers, type 
            qualifiers, and types in declaration
* occ:  allow declarations like "extern int aa[]" within a function body
* occ:  miscellaneous internal improvements...
    olink: if the same symbol is used in multiple libraries, don't generate an
            error
* rtl:    fix problems with _splitpath and _makepath
* rtl:    fix more problems with truncating various unsigned types in sprintf.c and sscanf.c
* rtl:    lscrtl.dll wouldn't be linked to properly
* rtl:    when compiling for system RTL DLLs, use the old prototype for
            swprintf and friends

version 4.1.23:
* occ:  fix sizeof(("my string")) where the extra parenthesis caused a wrong
            value to be returned

version 4.1.22:
* occ/olink:  workaround for FREEDOS: write a version of SYSTEM() that does not
                use the freedos command processor to allow spawns to work
* occ:  things like the following generated errors due to a preprocessor bug
            #include <limits.h>
            #define UL (unsigned long)
            int a = ULONG_MAX;
* occ:    CONSTANT-VALUE optimizations were broken for long-long types
* rtl:    fix bug in _sscanf that made it max out at half the requested int size

version 4.1.21:
* occ:	'signed int' is a valid type specification
* occ:	add '#pragma warning'
* occ:	allow prototypes such as the following:	void MyFunc(struct aa []);
* occ:	fix problem with sizeof("string") returning the size of a pointer
* occ:	add unordered floating point comparisons

* rtl:	fix problems with snprintf not working to the standard, exception
		when buffer was exactly the right size
* rtl:	add code-page related windows functions (e.g. widechartomultibyte)
* rtl:	update WIN32 headers SHELLAPI and WINERROR, add headers SHLOBJ and friends	
* rtl:	add imports for msimg32.dll

version 4.1.20:
* occ:	fix problems with crashing when boolean operations were combined with long longs
* occ:	promote unsigned constants to unsigned long long if necessary
* occ:	fix crash in register allocator
* occ:	'const long long aa = 4;' for example, the optimization to constant resulted
		in truncation to int.
* occ:	fix crash when calculating offsets for const struct members
* occ:	improve speed of parsing floating point numbers, useful for big arrays
		of floating point values
* rtl:	change 'DLLEntryPoint' to 'DllMain'
* rtl:	make wide character versions of some win32 header structures
* rtl:	add win32 spooler defines and win32 common dialog errors
* rtl:	remove DLLCANUNLOADNOW and DLLGETCLASSNAME references from the import library
* rtl:	restore ftime.c
* rtl:	improve string handling on command line
* rtl:	allow NULL to be passed as first argument to sprintf and friends
* rtl:	week number in strftime was wrong first and last week of year
* rtl:	fix minor bug in threading support
* rtl:	fix %.0f and %.0g to work properly in printf format strings
* rtl:	add _wcsicmp, _wcsnicmp
* rtl:	add vsnwprintf _vsnwprintf snwprintf _snwprintf
* rtl:	fix return value of 'div' function

version 4.1.19:

* occ:	fix problem with nested anonymous unions: wasn't supported
* occ:	fix recursion problem int the optimizer that could lead to a crash 
		for some source files
* occ:	modify preprocessor to handle recursion and tokenizing properly
* occ:	make 'i64' and 'ui64' suffixes on numbers case-insensitive
* occ:	fixed 'whereis' example
* rtl:	fix _splitpath to allow null for arguments
* rtl:	added delay(), sound(), nosound(), and int386() without underscores
* rtl:	fix stack allocation code for large stacks, could crash the program 
		if the allocated amount of space was an even multiple of the page size.
version 4.1.18:
* occ:	preprocessing stringizer sometimes got confused by quotes
* rtl:	add mousewheel support to WIN32 headers
* rtl:	fix stdout & friends with CRTDLL.DLL
* rtl:	fix sprintf & family, there was a space between a negative sign and its number

version 4.1.17:
* occ:	fix the macro preprocessor to handle a wider variety of standard cases
* occ/dlpe/rtl: revert the import behavior, needed to be allowed to link to C-style
	functions without fully prototyping everything...
* orc:	further improve internationalization
* orc:	fix broken string table and language resource handling
	(neither case should need a resource id)
* rtl:	change definition of ffs();
	RTL/DOS: fix CTRL-C and CTRL-BREAK to not crash

version 4.1.16
* occ:	macro arguments were getting substituted twice
* occ:	loop invariant calculations could move floating point expressions,
		which doesn't work well on the x86 because they aren't real registers
* occ:	local definitions of a structure that is cyclical would cause a crash
* occ:	bad structure declarations such as this would crash the compiler:
		struct nn
		{
			struct nn *p, // note the comma
			int a;
		};
* oasm:	allow '%%' style labels
* ocl:	used ONASM in compile-via-assembly mode instead make it use OASM
* orc:	fix bug: if you get a non-ansi character into the RC file, ORC 
		wouldn't handle it correctly
* orc:	treat BEGIN the same as '{' and END the same as '}'
* orc:	allow C-style escape sequence inside strings
* rtl:	fgets was going one character past the end of the supplied buffer...
* rtl:	fix custcntl.h to have A and W structure names
* rtl:	fix definition of wsprintf
* rtl:	fix wildargsw, needed hInstance.
* rtl:	fix dll startup routines, was crashing when dll created by the tools loaded
* rtl:	fix fputc, if it happened at the end of a buffer it wouldn't flush the buffer
		but would instead overrun memory...	
* rtl:	exit routines not being called, e.g. automatic end-of-program
		behaviors such as files being flushed when not explicitly closed 
		would not occur
* rtl:	rewrote printf & family to handle "%s" using arbitrarily large strings...
* rtl:	fixed MSDOS debugger

version 4.1.15
* occ:	support signed zero
* rtl:	fix a bug where flushing a file in text read mode could result in a seek
		to the wrong file position
* rtl:	fix integer to ascii functions to use lower case letters for hex, only
		do negative signs in base 10, buffer overflow problems.
* rtl:	add ffs() and 'strings.h' and related functions
* rtl:	fix definition of size_t in sys\types.h
* rtl:	fix isctrl('\0') to return true
* rtl:	fix isspace('\t') to return false
* rtl:	treat buffered strings as binary...
* rtl:	miscelleneous updates to floating point display handling, including 
		improved handling of nans and signed zero

version 4.1.14
* occ: fix problem where registers used for long long calculations could
		sometimes collide
* occ: fix new problem where sometimes function calls would cause the compiler to crash
* occ: fix new problem where local statics could collide, resulting in
		a redefinition error, when they were previously declared external
* occ: - reorder commutative expressions to generate better code, needed especially
		to reduce the number of floating point registers in use simultaneously

version 4.1.12
* rtl:	fix WIN32 header bug that caused CCIDE to not work reliably

version 4.1.11
* occ: remove import record from ASM file, when DLL name not specified
* occ: fix problems with statements such as:
>			typedef void AA(int b);
>			AA ss,*tt;
>			ss(4);
>			tt(4);
	the typedef wasn't processed right and it resulted in errors
* occ: add __int8, __int16, __int32
*occ, dlpe, rtl: adjust for optimized imports
* rtl:	work with RTL DLLs

version 4.1.10
* occ: - problem with declaring things like void (*printf)(...) in a structure 
	would cause a redefined identifier error
* occ: problem with assigning to the first member of a structure, when the member
	was a pointer, would crash the compiler
			
version 4.1.9
* occ: there was a problem with sign extensions in statements such as p+=c 
	where p is a pointer and c is a character value - the sign extension
	would be done after multiplying by the size of a pointer leading to
	overflow

version 4.1.8
* occ: 4.1.7 broke some programs with infinite loops
* occ: fix problem where strength reduction could be incorrectly applied
		when induction variables of nested loops were multiplied together
* occ: fix problem with division: sequences such as:

			a = t %60
			t = t / 60
			b = t % 60
			t = t / 60

			would incorrectly generate code for:

			a = t % 60
			t = t / 60 / 60
			b = t % 60
			t = t / 60 / 60

			because of bugs in dealing with the x86 IDIV instruction

version 4.17
* occ: comment out some test code that is no longer needed
* occ: fix problems with functions returning a structured value

version 4.16
* occ: fix problem that broke the runtime library
* occ: fix problems with statically initialized bit fields
	* occ: deal with zero-length anonymous bit fields properly
* occ: more speedups
* occ: deal with several crash conditions
* occ: deal with some incorrect code generation problems
* occ: fix some floating point problems

version 4.15
* oasm - fix problems with constants, structures, and improve code gen for move immediate to reg
* occ - speed up compilations, fix bugs, add a branch optimization
* omake - fix bugs
* orc: allow integer values for resource types, e.g. for manifests

version 4.1.4
* oasm: some floating point instructions involving memory access were generated incorrectly
* occ:  floating point - use memory access more often
* occ:   floating point - change div by a constant into mul by a constant
* occ:   loops - generate code at the top of the loop to test the loop condition
			instead of branching to the bottom of the loop
			(while and for loops) and optimize such code away when possible.
* occ:   worked on constant propagation code, was not folding assignments
* ocl: use OASM instead of ONASM
* omake: fix problem where VPATH would not be considered if a file did not exist
* omake: fix 'F' and 'D' suffixes on special macros, for example $@F and $@D

version 4.1.3
* occ: fix two crash conditions in code generator
* occ: some algorithmic rewrites to get an order of magnitude speed improvement
		on large bulky functions.
* occ: fix problem with register allocator, on very complex programs register
		usage could sometimes overlap when it shouldn't
* occ: fix problem in static initialization when fixed point constants are 
		stored as floating point constants:  size of the storage did not match
		size when the value was loaded
* occ: fix peephole optimization problem that caused code to disappear
* occ: fix floating point global optimization to adjust properly for x86 FP unit
* occ: fix register allocation/peephole optimization in the presence of infinite loops
* occ: add the functionality to use two-character character constants
* occ: fix packing of unions to work according to the windows standard...
* occ: fix problems with cascaded shift operations
* occ: fix problems with aliasing in the presence of assignments of structures
* omake: dependencies were correctly qualified off VPATH, but when they showed up
			in a command the VPATH path was missing
* omake: enable searching for implicit rules when explicit rules exist for dependencies
			but there are no commands
* orc: add LOADONCALL parsing (doesn't do anything)
* orc: scan for bitmap files etc... on the include path
* rtl: utime.h is now in *both* include and include\sys for portability
* rtl: add VOS__ constants to windows.h
* rtl: toolchain and generated programs would crash if an environment variable was greater than 1024 bytes long
* rtl: fix console mode of stdin to allow echoed line input on windows 7
* rtl: fix getch() and friends - were broken because of the compiler union packing issue
* rtl: rename winversion.h to winver.h

Version 4.1.2
* oasm: was generating an error when a large number was used as
	a byte operand to a math instruction but it was in-range for a signed value.
* occ: feature addition - OCC will look in its home directory for olink.exe
* occ: prototype warnings - only warn once, remove superfluous warnings
* occ: /O switch would add a .o extension to an executable and use it as an object file
	which resulted in duplicate modules being passed to the linker and linker errors.
	fix the /O switch to only register the exe name.
* occ: if a continuation character '\' was used in strings, and it was followed
	by a // style comment within the string, this generated parser errors.
* occ: was filling out the entire BSS with zeros, which resulted in very 
	large object files when there is a lot of static uninitialized data
* occ: when compile fails, delete the output file
* occ: correct code gen/register allocation/peephole optimization bugs
* olink: documentation changed to use correct target names for windows targets
* rtl: when the following was done in the source prior to including files:

		#define size_t int

		then there was a collision between string.h and memory.h
