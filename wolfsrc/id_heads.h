//
// Created by Baumbart13 on 10.04.2021.
//

#ifndef WOLF_OWN_ID_HEADS_H
#define WOLF_OWN_ID_HEADS_H

//#include <dos.h> // can't find this file, because cygwin is used for compilation instead of borland
#include "../missingIncludes/dos.h"
#include "../baumbartWolfHelp/baumbartWolf_dataTypes.h" // included this file, since byte cannot be used nowadays properly

#include <alloca.h>
#include <cctype>
#include <cerrno>
#include <fcntl.h>
#include <io.h>
#include <memory.h> // changed from "mem.h" to "memory.h"
#include <process.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
//#include <values.h> // removing it for test-purposes
//#include <dir.h> // removing for test-purposes
#define __ID_GLOB__
#include "version.h"

namespace id{
	extern char signon;
#define introscn signon // TODO: gotta work up any pointer hack instead of define

#ifdef JAPAN
#ifdef JAPDEMO
#include "foreign/japan/gfxv_wj1.h"
#else // JAPDEMO
#incldue "foreign/japan/gfxv_wj6.h"
#endif // JAPDEMO
#include "audiowl6.h"
#include "mapswl6.h"
#else // JAPAN

#ifndef SPEAR
#include "gfxv_wl6.h"
#include "audiowl6.h"
#include "mapswl6.h"
#else // SPEAR
#ifndef SPEARDEMO
#include "gfxv_sod.h"
#include "audiosodm.h"
#include "mapssdm.h"
#endif // SPEARDEMO

#endif // SPEAR
#endif // JAPAN

	const char* _GREXT = "VGA";

	//
	// ID Engine
	// Types.h - Generic types, #define, etc.
	// v1.0d1
	//

	//typedef enum {false,true} boolean;  // deprecated, since using using modern C++ 2021
	//#define true true
	//#define false false // ... damn, it hurts.. this code is old
	typedef bool boolean; // ok.. that's ok. even Java says "boolean" instead of "bool"
	typedef uint8_t byte;
	typedef uint16_t word;
	typedef uint32_t longword;
	typedef byte* Ptr;

	typedef struct{
		int x, y;
	} Point;

	typedef struct{
		Point ul, lr;
	} Rect;

#define nil ((void* 0)) // TODO: use a struct/class/enum instead of define?

#include "id_mm.h"
#include "id_pm.h"
#include "id_ca.h"
#include "id_vl.h"
#include "id_vh.h"
#include "id_in.h"
#include "id_sd.h"
#include "id_us.h"


	void Quit(char *error); // defined in user program

	//
	// replacing refresh manager with custom routines
	//

	const unsigned int _PORT_TILES_WIDE = 20; // all drawing takes place inside a
	const unsigned int _PORT_TILES_HIGH = 13; // non displayed port of this size

	const unsigned int _UPDATE_WIDE = _PORT_TILES_WIDE;
	const unsigned int _UPDATE_HIGH = _PORT_TILES_HIGH;
	
	const unsigned int _MAX_TICS = 10;
	const unsigned int _DEMO_TICS = 4;
	
	const unsigned int _UPDATE_TERMINATE = 0x0301;
	
	extern unsigned mapWidth, mapHeight, tics;
	extern bool compatability;
	
	extern byte *updatePrt;
	extern unsigned uWidthTable[_UPDATE_HIGH];
	extern unsigned blockStart[_UPDATE_WIDE * _UPDATE_HIGH];
	
	extern byte fontColor, backColor;
	
	void inline _setFontColor(byte f, byte b){
		fontColor = f;
		backColor = b;
	}
}

#endif //WOLF_OWN_ID_HEADS_H
