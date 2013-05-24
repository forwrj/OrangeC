partition {
  overlay {
	_CODESTART = $;
	CODEBASE = $;
	region {} hdr [ size = RESERVE0];
    region {} code [ align = 2, roundsize = 8];
	region {} const [ align = 8, roundsize = 4];
    _TLSINITSTART = $;
    region {} tls [align = 4, roundsize = 4];
    _TLSINITEND = $;
	RAMBASE = $;
    region {} data [ align = 8, roundsize = 4];
	_INITSTART = $;
	region {} cstartup [ align = 2];
	_INITEND = $;
	_EXITSTART = $;
	region {} crundown [ align = 2];
	_EXITEND = $;
    region {} string [ align = 2];
	INITSIZE = $ - RAMBASE;
	_BSSSTART = $;
	region {} bss [ align = 8, roundsize = 4];
	_BSSEND = $;
	STACKBASE = $;
	STACKTOP = STACKBASE + STACKSIZE;
	RAMSIZE = STACKTOP - RAMBASE;
  } .bin;
} pt1;
