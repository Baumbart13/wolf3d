//
// Created by Baumbart13 on 14.04.2021.
//

////////////////////////////////////////////////////////////////////
//
// WL_MENU.C
// by John Romero (C) 1992 Id Software, Inc.
//
////////////////////////////////////////////////////////////////////
#include "wl_def.h"
#pragma hdrstop

//
// PRIVATE PROTOTYPES
//
namespace WOLF{
	namespace CP{
		void ReadThis(void);

#ifdef SPEAR
	#define STARTITEM newGame
#else // SPEAR
	#ifdef GOODTIMES
		#define STARTITEM newGame
	#else // GOODTIMES
		#define STARTITEM readThis
	#endif // GOODTIMES
#endif // SPEAR
	}
	
	char endStrings[][80] = { //orig: char endStrings[0][80]={
#ifndef SPEAR
			{"Dost thou wish to\n leave with such hasty\nabandon?"},
			{"Chickening out...\nalready?"},
			{"Press N for more carnage.\nPress Y to be a weenie."},
			{"So, you think you can\nquit this easily, huh?"},
			{"Press N to save the world.\nPress Y to abandon it in\nits hour of need."},
			{"Press N if you are brave.\nPress Y to cower in shame."},
			{"Heroes, press N.\nWimps, press Y."},
			{"You are at an intersection.\nA sign says, 'Press Y to quit.'\n>"},
			{"For guns and glory, press N.\nFor work and worry, press Y."}
#else // SPEAR
			ENDSTR1,
			ENDSTR2,
			ENDSTR3,
			ENDSTR4,
			ENDSTR5,
			ENDSTR6,
			ENDSTR7,
			ENDSTR8,
			ENDSTR9
#endif // SPEAR
	};
	
	WOLF
}
