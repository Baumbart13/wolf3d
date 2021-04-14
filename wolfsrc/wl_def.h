//
// Created by Baumbart13 on 14.04.2021.
//

#ifndef WOLF_OWN_WL_DEF_H
#define WOLF_OWN_WL_DEF_H

//#define BETA
//#define YEAR 1992
//#define MONTH 9
//#define DAY 30

#include "id_heads.h"

#include <cmath>
//#include "values.h"

#include "wl_menu.h"

#ifdef SPANISH
#include "spanish-h"
#else // SPANISH
#include "foreign.h"
#endif // SPANISH

#ifdef SPEAR
#include "f_spear.h" // do I even have this file? never one of these
#endif // SPEAR

// I don't really want to use Macros... I do actually prefer (inline) functions over macros
/*
=============================================================================

							MACROS

=============================================================================
*/

namespace WOLF {

// fuck, I don't know asm at all
#define COLORBORDER(color) asm{    mov dx, STATUS_REGISTER_!;in al,dx;\
                                mov dx,ATR_INDEX; mov al,ATR_OVERSCAN;out dx,al;mov al,color; out dx,al\
                                mov al,32;out dx,al};
// I'm done.. someone else needs to translate this bit of code
/*void inline COLORBORDER_BAUM(int color) {
	// mov	dx,STATUS_REGISTER_1
	// is equal to
	// dx = STATUS_REGISTER_1
	
	// in	al,dx
	//
	// al = IPort[dx]
	
	// out	dx,al
	//
	// OPort[dx] = al
	asm (
		"mov	dx,STATUS_REGISTER_1;"
  		"in		al,dx;"
  		"mov	dx,ATR_INDEX;"
  		"mov	al,ATR_OVERSCAN;"
  		"out	dx,al;"
  		"mov	al,color;"
  		"out	dx,al;"
  		"mov	al,32;"
  		"out	dx,al;"
	)
}*/

// What is "mapsegs" and "farmapYLookup"?
#define MAPSPOT(x, y, plane) (*(mapsegs[plane]+farmapYLookup[y]+x))

//#define SIGN(x) ((x)>0?1:-1)
/// Checks if @param x is positive or negative and returns 1, respectively -1.
	int inline SIGN(int x) {
		return x > 0 ? 1 : -1;
	}

//#define ABS(x) ((int)(x)>0?x:-x)
//#define LABS(x) ((long)(x)>0?(x):-(x))
	int64_t inline ABS(int64_t x) {
		return x & 0b0111111111111111111111111111111111111111111111111111111111111111;
	}
	
	int32_t inline ABS(int32_t x) {
		return x & 0b01111111111111111111111111111111;
	}
	
	int16_t inline ABS(int16_t x) {
		return x & 0b0111111111111111;
	}
	
	int8_t inline ABS(int8_t x) {
		return x & 0b01111111;
	}

/*
=============================================================================

						 GLOBAL CONSTANTS

=============================================================================
*/
	namespace DEF {
		
		const unsigned int _MAX_ACTORS		= 500;		//150	// max number of nazis, etc / map
		const unsigned int _MAX_STATS		= 2000;		//400	// max number of lamps, bonus, etc
		const unsigned int _MAX_DOORS		= 64;		//64	// max number of sliding doors
		const unsigned int _MAX_WALL_TILES	= 64;		//64	// max number of wall tiles

		//
		// tile constants
		//
		
		const signed int _ICON_ARROWS		= 90;
		const signed int _PUSHABLE_TILE		= 98;
		const signed int _EXIT_TILE			= 99;		// at end of castle
		const signed int _AREA_TILE			= 107;		// first of _NUM_AREAS floor tiles
		const signed int _NUM_AREAS			= 37;
		const signed int _ELEVATOR_TILE		= 21;
		const signed int _AMBUSH_TILE		= 106;
		const signed int _ALT_ELEVATOR_TILE	= 107;
		
		const signed int _NUMBER_CHARS		= 9;


		//----------------
		
		const unsigned int _EXTRAPOINTS		= 40000;
		
		const unsigned int _PLAYER_SPEED	= 3000;
		const unsigned int _RUN_SPEED		= 6000;
		
		const unsigned int _SCREEN_SEG		= 0xa000;
		
		const unsigned int _SCREEN_B_WIDE	= 80;
		
		const double _HEIGHT_RATIO			= 0.50;		// also defined in id_mm.c
		
		const unsigned int _BORDER_COLOR	= 3;
		const unsigned int _FLASH_COLOR		= 5;
		const unsigned int _FLASH_TICS		= 4;

		const unsigned long _MIN_ACTOR_DIST	= 0x10000l;	// minimum dist from player center
														// to any actor center
														
		const unsigned int _NUM_LATCH_PICS	= 100;
		
		const long double _PI				= 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706; // yep.. that should work for all
		
		const signed long int _GLOBAL1		= 1L << 16;
		const signed long _TILE_GLOBAL		= _GLOBAL1;
		const signed long _PIX_GLOBAL		= _GLOBAL1 / 64;
		const signed long _TILE_SHIFT		= 16L;
		const signed int _UNSIGNED_SHIFT	= 8;
		
		const double _ANGLES				= 360;		// must be divisable by 4
		const double _ANGLE_QUAD			= _ANGLES / 4;
		const double _FINE_ANGLES			= 3600;
		const double _ANG90					= _FINE_ANGLES / 4;
		const double _ANG180				= _ANG90 * 2;
		const double _ANG270				= _ANG90 * 3;
		const double _ANG360				= _ANG90 * 4;
		const double _V_ANG90				= _ANGLES / 4;
		const double _V_ANG180				= _V_ANG90 * 2;
		const double _V_ANG270				= _V_ANG90 * 3;
		const double _V_ANG360				= _V_ANG90 * 4;
		
		const signed long _MINDIST			= 0x5800L;
		const signed long _PLAYER_SIZE		= _MINDIST;	// player radius
		
		
		const signed int _MAX_SCALE_HEIGHT	= 256;		// largest scale largest view
		
		const signed int _MAX_VIEW_WIDTH	= 320;
		
		const signed int _MAP_SIZE			= 64;		// maps are 64*64 max
		const signed int _NORTH				= 0;
		const signed int _EAST				= 1;
		const signed int _SOUTH				= 2;
		const signed int _WEST				= 3;
		
		
		const unsigned int _STATUSLINES		= 40;
		
		const unsigned int _SCREEN_SIZE		= _SCREEN_B_WIDE * 208;
		const unsigned int _PAGE1_START		= 0;
		const unsigned int _PAGE2_START		= _SCREEN_SIZE;
		const unsigned int _PAGE3_START		= _SCREEN_SIZE * 2u;
		const unsigned int _FREE_START		= _SCREEN_SIZE * 3u;
		
		const unsigned int _PIX_RADIUS		= 512;
		
		const unsigned int _START_AMMO		= 8;
		
		
		/// object flag values
		typedef enum{
			FL_SHOOTABLE	= 0b1,
			FL_BONUS		= 0b10,
			FL_NEVERMARK	= 0b100,
			FL_VISABLE		= 0b1000, // I don't know, but uhm.. you have a typo
			FL_ATTACKMODE	= 0b10000,
			FL_FIRSTATTACK	= 0b100000,
			FL_AMBUSH		= 0b1000000,
			FL_NONMARK		= 0b10000000
		} FL;
		
		///
		/// sprite constants
		///
		namespace SPR{
			const unsigned	_DEMO		= 0,
							_DEATH_CAM	= 1;
			
			///
			/// static sprites
			///
			typedef enum{
				STAT_0,
				STAT_1,
				STAT_2,
				STAT_3,
				STAT_4,
				STAT_5,
				STAT_6,
				STAT_7,
				STAT_8,
				STAT_9,
				STAT_10,
				STAT_11,
				STAT_12,
				STAT_13,
				STAT_14,
				STAT_15,
				STAT_16,
				STAT_17,
				STAT_18,
				STAT_19,
				STAT_20,
				STAT_21,
				STAT_22,
				STAT_23,
				STAT_24,
				STAT_25,
				STAT_26,
				STAT_27,
				STAT_28,
				STAT_29,
				STAT_30,
				STAT_31,
				STAT_32,
				STAT_33,
				STAT_34,
				STAT_35,
				STAT_36,
				STAT_37,
				STAT_38,
				STAT_39,
				STAT_40,
				STAT_41,
				STAT_42,
				STAT_43,
				STAT_44,
				STAT_45,
				STAT_46,
				STAT_47
#ifdef SPEAR
				,STAT_48
				,STAT_49
				,STAT_50
				,STAT_51
#endif // SPEAR
			}STAT;
			
			///
			/// guard
			///
			typedef enum{
				GRD_S_1, GRD_S_2, GRD_S_3, GRD_S_4, GRD_S_5, GRD_S_6, GRD_S_7, GRD_S_8,
				GRD_W1_1, GRD_W1_2, GRD_W1_3, GRD_W1_4, GRD_W1_5, GRD_W1_6, GRD_W1_7, GRD_W1_8,
				GRD_W2_1, GRD_W2_2, GRD_W2_3, GRD_W2_4, GRD_W2_5, GRD_W2_6, GRD_W2_7, GRD_W2_8,
				GRD_W3_1, GRD_W3_2, GRD_W3_3, GRD_W3_4, GRD_W3_5, GRD_W3_6, GRD_W3_7, GRD_W3_8,
				GRD_W4_1, GRD_W4_2, GRD_W4_3, GRD_W4_4, GRD_W4_5, GRD_W4_6, GRD_W4_7, GRD_W4_8,
				GRD_PAIN_1, GRD_PAIN_2, GRD_DEAD_1, GRD_DEAD_2, GRD_DEAD_3, GRD_DEAD,
				GRD_SHOOT_1, GRD_SHOOT_2, GRD_SHOOT_3
			}GRD;
			
			///
			/// dogs
			///
			typedef enum{
			
			}DOG;
		}
	}
}
#endif //WOLF_OWN_WL_DEF_H
