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

		const unsigned int _MAX_ACTORS = 500;        //150	// max number of nazis, etc / map
		const unsigned int _MAX_STATS = 2000;        //400	// max number of lamps, bonus, etc
		const unsigned int _MAX_DOORS = 64;        //64	// max number of sliding doors
		const unsigned int _MAX_WALL_TILES = 64;        //64	// max number of wall tiles

		//
		// tile constants
		//

		const signed int _ICON_ARROWS = 90;
		const signed int _PUSHABLE_TILE = 98;
		const signed int _EXIT_TILE = 99;        // at end of castle
		const signed int _AREA_TILE = 107;        // first of _NUM_AREAS floor tiles
		const signed int _NUM_AREAS = 37;
		const signed int _ELEVATOR_TILE = 21;
		const signed int _AMBUSH_TILE = 106;
		const signed int _ALT_ELEVATOR_TILE = 107;

		const signed int _NUMBER_CHARS = 9;


		//----------------

		const unsigned int _EXTRAPOINTS = 40000;

		const unsigned int _PLAYER_SPEED = 3000;
		const unsigned int _RUN_SPEED = 6000;

		const unsigned int _SCREEN_SEG = 0xa000;

		const unsigned int _SCREEN_B_WIDE = 80;

		const double _HEIGHT_RATIO = 0.50;        // also defined in id_mm.c

		const unsigned int _BORDER_COLOR = 3;
		const unsigned int _FLASH_COLOR = 5;
		const unsigned int _FLASH_TICS = 4;

		const unsigned long _MIN_ACTOR_DIST = 0x10000l;    // minimum dist from player center
		// to any actor center

		const unsigned int _NUM_LATCH_PICS = 100;

		const long double _PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706; // yep.. that should work for all

		const signed long int _GLOBAL1 = 1L << 16;
		const signed long _TILE_GLOBAL = _GLOBAL1;
		const signed long _PIX_GLOBAL = _GLOBAL1 / 64;
		const signed long _TILE_SHIFT = 16L;
		const signed int _UNSIGNED_SHIFT = 8;

		const double _ANGLES = 360;        // must be divisable by 4
		const double _ANGLE_QUAD = _ANGLES / 4;
		const double _FINE_ANGLES = 3600;
		const double _ANG90 = _FINE_ANGLES / 4;
		const double _ANG180 = _ANG90 * 2;
		const double _ANG270 = _ANG90 * 3;
		const double _ANG360 = _ANG90 * 4;
		const double _V_ANG90 = _ANGLES / 4;
		const double _V_ANG180 = _V_ANG90 * 2;
		const double _V_ANG270 = _V_ANG90 * 3;
		const double _V_ANG360 = _V_ANG90 * 4;

		const signed long _MINDIST = 0x5800L;
		const signed long _PLAYER_SIZE = _MINDIST;    // player radius


		const signed int _MAX_SCALE_HEIGHT = 256;        // largest scale largest view

		const signed int _MAX_VIEW_WIDTH = 320;

		const signed int _MAP_SIZE = 64;        // maps are 64*64 max
		const signed int _NORTH = 0;
		const signed int _EAST = 1;
		const signed int _SOUTH = 2;
		const signed int _WEST = 3;


		const unsigned int _STATUSLINES = 40;

		const unsigned int _SCREEN_SIZE = _SCREEN_B_WIDE * 208;
		const unsigned int _PAGE1_START = 0;
		const unsigned int _PAGE2_START = _SCREEN_SIZE;
		const unsigned int _PAGE3_START = _SCREEN_SIZE * 2u;
		const unsigned int _FREE_START = _SCREEN_SIZE * 3u;

		const unsigned int _PIX_RADIUS = 512;

		const unsigned int _START_AMMO = 8;


		/// object flag values
		typedef enum {
			FL_SHOOTABLE = 0b1,
			FL_BONUS = 0b10,
			FL_NEVERMARK = 0b100,
			FL_VISABLE = 0b1000, // I don't know, but uhm.. you have a typo
			FL_ATTACKMODE = 0b10000,
			FL_FIRSTATTACK = 0b100000,
			FL_AMBUSH = 0b1000000,
			FL_NONMARK = 0b10000000
		} FL;

		///
		/// sprite constants
		///
		const unsigned _DEMO = 0,
				_DEATH_CAM = 1;

		///
		/// static sprites
		///
		typedef enum {
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
		} SPR_STAT;

		///
		/// guard
		///
		typedef enum {
			GRD_S_1, GRD_S_2, GRD_S_3, GRD_S_4, GRD_S_5, GRD_S_6, GRD_S_7, GRD_S_8,
			GRD_W1_1, GRD_W1_2, GRD_W1_3, GRD_W1_4, GRD_W1_5, GRD_W1_6, GRD_W1_7, GRD_W1_8,
			GRD_W2_1, GRD_W2_2, GRD_W2_3, GRD_W2_4, GRD_W2_5, GRD_W2_6, GRD_W2_7, GRD_W2_8,
			GRD_W3_1, GRD_W3_2, GRD_W3_3, GRD_W3_4, GRD_W3_5, GRD_W3_6, GRD_W3_7, GRD_W3_8,
			GRD_W4_1, GRD_W4_2, GRD_W4_3, GRD_W4_4, GRD_W4_5, GRD_W4_6, GRD_W4_7, GRD_W4_8,
			GRD_PAIN_1, GRD_PAIN_2, GRD_DEAD_1, GRD_DEAD_2, GRD_DEAD_3, GRD_DEAD,
			GRD_SHOOT_1, GRD_SHOOT_2, GRD_SHOOT_3
		} SPR_GRD;

		///
		/// dogs
		///
		typedef enum {
			SPR_DOG_W1_1, SPR_DOG_W1_2, SPR_DOG_W1_3, SPR_DOG_W1_4,
			SPR_DOG_W1_5, SPR_DOG_W1_6, SPR_DOG_W1_7, SPR_DOG_W1_8,

			SPR_DOG_W2_1, SPR_DOG_W2_2, SPR_DOG_W2_3, SPR_DOG_W2_4,
			SPR_DOG_W2_5, SPR_DOG_W2_6, SPR_DOG_W2_7, SPR_DOG_W2_8,

			SPR_DOG_W3_1, SPR_DOG_W3_2, SPR_DOG_W3_3, SPR_DOG_W3_4,
			SPR_DOG_W3_5, SPR_DOG_W3_6, SPR_DOG_W3_7, SPR_DOG_W3_8,

			SPR_DOG_W4_1, SPR_DOG_W4_2, SPR_DOG_W4_3, SPR_DOG_W4_4,
			SPR_DOG_W4_5, SPR_DOG_W4_6, SPR_DOG_W4_7, SPR_DOG_W4_8,

			SPR_DOG_DIE_1, SPR_DOG_DIE_2, SPR_DOG_DIE_3, SPR_DOG_DEAD,
			SPR_DOG_JUMP1, SPR_DOG_JUMP2, SPR_DOG_JUMP3
		} SPR_DOG;

		///
		/// SS - can I still call it like this in 2021?
		///
		typedef enum {
			SPR_SS_S_1, SPR_SS_S_2, SPR_SS_S_3, SPR_SS_S_4,
			SPR_SS_S_5, SPR_SS_S_6, SPR_SS_S_7, SPR_SS_S_8,

			SPR_SS_W1_1, SPR_SS_W1_2, SPR_SS_W1_3, SPR_SS_W1_4,
			SPR_SS_W1_5, SPR_SS_W1_6, SPR_SS_W1_7, SPR_SS_W1_8,

			SPR_SS_W2_1, SPR_SS_W2_2, SPR_SS_W2_3, SPR_SS_W2_4,
			SPR_SS_W2_5, SPR_SS_W2_6, SPR_SS_W2_7, SPR_SS_W2_8,

			SPR_SS_W3_1, SPR_SS_W3_2, SPR_SS_W3_3, SPR_SS_W3_4,
			SPR_SS_W3_5, SPR_SS_W3_6, SPR_SS_W3_7, SPR_SS_W3_8,

			SPR_SS_W4_1, SPR_SS_W4_2, SPR_SS_W4_3, SPR_SS_W4_4,
			SPR_SS_W4_5, SPR_SS_W4_6, SPR_SS_W4_7, SPR_SS_W4_8,

			SPR_SS_PAIN_1, SPR_SS_DIE_1, SPR_SS_DIE_2, SPR_SS_DIE_3,
			SPR_SS_PAIN_2, SPR_SS_DEAD,

			SPR_SS_SHOOT1, SPR_SS_SHOOT2, SPR_SS_SHOOT3
		} SPR_SS;

///
/// mutant
///
		typedef enum {
			SPR_MUT_S_1, SPR_MUT_S_2, SPR_MUT_S_3, SPR_MUT_S_4,
			SPR_MUT_S_5, SPR_MUT_S_6, SPR_MUT_S_7, SPR_MUT_S_8,

			SPR_MUT_W1_1, SPR_MUT_W1_2, SPR_MUT_W1_3, SPR_MUT_W1_4,
			SPR_MUT_W1_5, SPR_MUT_W1_6, SPR_MUT_W1_7, SPR_MUT_W1_8,

			SPR_MUT_W2_1, SPR_MUT_W2_2, SPR_MUT_W2_3, SPR_MUT_W2_4,
			SPR_MUT_W2_5, SPR_MUT_W2_6, SPR_MUT_W2_7, SPR_MUT_W2_8,

			SPR_MUT_W3_1, SPR_MUT_W3_2, SPR_MUT_W3_3, SPR_MUT_W3_4,
			SPR_MUT_W3_5, SPR_MUT_W3_6, SPR_MUT_W3_7, SPR_MUT_W3_8,

			SPR_MUT_W4_1, SPR_MUT_W4_2, SPR_MUT_W4_3, SPR_MUT_W4_4,
			SPR_MUT_W4_5, SPR_MUT_W4_6, SPR_MUT_W4_7, SPR_MUT_W4_8,

			SPR_MUT_PAIN_1, SPR_MUT_DIE_1, SPR_MUT_DIE_2, SPR_MUT_DIE_3,
			SPR_MUT_PAIN_2, SPR_MUT_DIE_4, SPR_MUT_DEAD,

			SPR_MUT_SHOOT1, SPR_MUT_SHOOT2, SPR_MUT_SHOOT3, SPR_MUT_SHOOT4,
		} SPR_MUT;
///
/// officer
///
		typedef enum {
			SPR_OFC_S_1, SPR_OFC_S_2, SPR_OFC_S_3, SPR_OFC_S_4,
			SPR_OFC_S_5, SPR_OFC_S_6, SPR_OFC_S_7, SPR_OFC_S_8,

			SPR_OFC_W1_1, SPR_OFC_W1_2, SPR_OFC_W1_3, SPR_OFC_W1_4,
			SPR_OFC_W1_5, SPR_OFC_W1_6, SPR_OFC_W1_7, SPR_OFC_W1_8,

			SPR_OFC_W2_1, SPR_OFC_W2_2, SPR_OFC_W2_3, SPR_OFC_W2_4,
			SPR_OFC_W2_5, SPR_OFC_W2_6, SPR_OFC_W2_7, SPR_OFC_W2_8,

			SPR_OFC_W3_1, SPR_OFC_W3_2, SPR_OFC_W3_3, SPR_OFC_W3_4,
			SPR_OFC_W3_5, SPR_OFC_W3_6, SPR_OFC_W3_7, SPR_OFC_W3_8,

			SPR_OFC_W4_1, SPR_OFC_W4_2, SPR_OFC_W4_3, SPR_OFC_W4_4,
			SPR_OFC_W4_5, SPR_OFC_W4_6, SPR_OFC_W4_7, SPR_OFC_W4_8,

			SPR_OFC_PAIN_1, SPR_OFC_DIE_1, SPR_OFC_DIE_2, SPR_OFC_DIE_3,
			SPR_OFC_PAIN_2, SPR_OFC_DIE_4, SPR_OFC_DEAD,

			SPR_OFC_SHOOT1, SPR_OFC_SHOOT2, SPR_OFC_SHOOT3,
		} SPR_OFC;

#ifndef SPEAR
///
/// ghosts
///
		typedef enum {
			SPR_BLINKY_W1, SPR_BLINKY_W2, SPR_PINKY_W1, SPR_PINKY_W2,
			SPR_CLYDE_W1, SPR_CLYDE_W2, SPR_INKY_W1, SPR_INKY_W2,
		} SPR_GHOST;

		///
		/// hans
		///
		typedef enum {
			SPR_BOSS_W1, SPR_BOSS_W2, SPR_BOSS_W3, SPR_BOSS_W4,
			SPR_BOSS_SHOOT1, SPR_BOSS_SHOOT2, SPR_BOSS_SHOOT3, SPR_BOSS_DEAD,

			SPR_BOSS_DIE1, SPR_BOSS_DIE2, SPR_BOSS_DIE3,
		} SPR_BOSS;

///
/// schabbs
///
		typedef enum {
			SPR_SCHABB_W1, SPR_SCHABB_W2, SPR_SCHABB_W3, SPR_SCHABB_W4,
			SPR_SCHABB_SHOOT1, SPR_SCHABB_SHOOT2,

			SPR_SCHABB_DIE1, SPR_SCHABB_DIE2, SPR_SCHABB_DIE3, SPR_SCHABB_DEAD,
			SPR_HYPO1, SPR_HYPO2, SPR_HYPO3, SPR_HYPO4,
		} SPR_SCHABB;

///
/// fake
///
		typedef enum {
			SPR_FAKE_W1, SPR_FAKE_W2, SPR_FAKE_W3, SPR_FAKE_W4,
			SPR_FAKE_SHOOT, SPR_FIRE1, SPR_FIRE2,

			SPR_FAKE_DIE1, SPR_FAKE_DIE2, SPR_FAKE_DIE3, SPR_FAKE_DIE4,
			SPR_FAKE_DIE5, SPR_FAKE_DEAD,
		} SPR_FAKE;
///
/// hitler
///
		typedef enum {
			SPR_MECHA_W1, SPR_MECHA_W2, SPR_MECHA_W3, SPR_MECHA_W4,
			SPR_MECHA_SHOOT1, SPR_MECHA_SHOOT2, SPR_MECHA_SHOOT3, SPR_MECHA_DEAD,

			SPR_MECHA_DIE1, SPR_MECHA_DIE2, SPR_MECHA_DIE3,

			SPR_HITLER_W1, SPR_HITLER_W2, SPR_HITLER_W3, SPR_HITLER_W4,
			SPR_HITLER_SHOOT1, SPR_HITLER_SHOOT2, SPR_HITLER_SHOOT3, SPR_HITLER_DEAD,

			SPR_HITLER_DIE1, SPR_HITLER_DIE2, SPR_HITLER_DIE3, SPR_HITLER_DIE4,
			SPR_HITLER_DIE5, SPR_HITLER_DIE6, SPR_HITLER_DIE7,
		} SPR_HITLER;

///
/// giftmacher
///
		typedef enum {
			SPR_GIFT_W1, SPR_GIFT_W2, SPR_GIFT_W3, SPR_GIFT_W4,
			SPR_GIFT_SHOOT1, SPR_GIFT_SHOOT2,

			SPR_GIFT_DIE1, SPR_GIFT_DIE2, SPR_GIFT_DIE3, SPR_GIFT_DEAD,
		} SPR_GIFT;

#endif // NOT SPEAR

		///
/// Rocket, smoke and small explosion
///
		typedef enum {
			SPR_ROCKET_1, SPR_ROCKET_2, SPR_ROCKET_3, SPR_ROCKET_4,
			SPR_ROCKET_5, SPR_ROCKET_6, SPR_ROCKET_7, SPR_ROCKET_8,

			SPR_SMOKE_1, SPR_SMOKE_2, SPR_SMOKE_3, SPR_SMOKE_4,
			SPR_BOOM_1, SPR_BOOM_2, SPR_BOOM_3,
		} SPR_ROCKET;

#ifdef SPEAR
		///
		/// Angel of Death's DeathSparks(tm)
		///
		typedef enum{
					SPR_HROCKET_1,SPR_HROCKET_2,SPR_HROCKET_3,SPR_HROCKET_4,
				SPR_HROCKET_5,SPR_HROCKET_6,SPR_HROCKET_7,SPR_HROCKET_8,

				SPR_HSMOKE_1,SPR_HSMOKE_2,SPR_HSMOKE_3,SPR_HSMOKE_4,
				SPR_HBOOM_1,SPR_HBOOM_2,SPR_HBOOM_3,

				SPR_SPARK1,SPR_SPARK2,SPR_SPARK3,SPR_SPARK4,
				} SPR_HROCKET;
#endif

#ifndef SPEAR
///
/// gretel
///
		typedef enum {
			SPR_GRETEL_W1, SPR_GRETEL_W2, SPR_GRETEL_W3, SPR_GRETEL_W4,
			SPR_GRETEL_SHOOT1, SPR_GRETEL_SHOOT2, SPR_GRETEL_SHOOT3, SPR_GRETEL_DEAD,

			SPR_GRETEL_DIE1, SPR_GRETEL_DIE2, SPR_GRETEL_DIE3,
		} SPR_GRETEL;

///
/// fat face
///
		typedef enum {
			SPR_FAT_W1, SPR_FAT_W2, SPR_FAT_W3, SPR_FAT_W4,
			SPR_FAT_SHOOT1, SPR_FAT_SHOOT2, SPR_FAT_SHOOT3, SPR_FAT_SHOOT4,

			SPR_FAT_DIE1, SPR_FAT_DIE2, SPR_FAT_DIE3, SPR_FAT_DEAD,
		} SPR_FAT;

///
/// bj - no, it is not what you think!
///
		typedef enum {
			SPR_BJ_W1, SPR_BJ_W2, SPR_BJ_W3, SPR_BJ_W4,
			SPR_BJ_JUMP1, SPR_BJ_JUMP2, SPR_BJ_JUMP3, SPR_BJ_JUMP4,
		} SPR_BJ;
#else
		//
// THESE ARE FOR 'SPEAR OF DESTINY'
//

///
/// Trans Grosse
///
typedef enum{
	SPR_TRANS_W1,SPR_TRANS_W2,SPR_TRANS_W3,SPR_TRANS_W4,
	SPR_TRANS_SHOOT1,SPR_TRANS_SHOOT2,SPR_TRANS_SHOOT3,SPR_TRANS_DEAD,

	SPR_TRANS_DIE1,SPR_TRANS_DIE2,SPR_TRANS_DIE3,
	}SPR_TRANS;

///
/// Wilhelm
///
typedef enum{
	SPR_WILL_W1,SPR_WILL_W2,SPR_WILL_W3,SPR_WILL_W4,
	SPR_WILL_SHOOT1,SPR_WILL_SHOOT2,SPR_WILL_SHOOT3,SPR_WILL_SHOOT4,

	SPR_WILL_DIE1,SPR_WILL_DIE2,SPR_WILL_DIE3,SPR_WILL_DEAD,
	// TODO: halted in wl_def.h at Wilhelm
	}SPR_WILL;

///
/// UberMutant
///
typedef enum{
	SPR_UBER_W1,SPR_UBER_W2,SPR_UBER_W3,SPR_UBER_W4,
	SPR_UBER_SHOOT1,SPR_UBER_SHOOT2,SPR_UBER_SHOOT3,SPR_UBER_SHOOT4,

	SPR_UBER_DIE1,SPR_UBER_DIE2,SPR_UBER_DIE3,SPR_UBER_DIE4,
	SPR_UBER_DEAD,
	}SPR_UBER;

///
/// Death Knight
///
typedef enum{
	SPR_DEATH_W1,SPR_DEATH_W2,SPR_DEATH_W3,SPR_DEATH_W4,
	SPR_DEATH_SHOOT1,SPR_DEATH_SHOOT2,SPR_DEATH_SHOOT3,SPR_DEATH_SHOOT4,

	SPR_DEATH_DIE1,SPR_DEATH_DIE2,SPR_DEATH_DIE3,SPR_DEATH_DIE4,
	SPR_DEATH_DIE5,SPR_DEATH_DIE6,SPR_DEATH_DEAD,
}SPR_DEATH;

///
/// Ghost
///
typedef enum{
	SPR_SPECTRE_W1,SPR_SPECTRE_W2,SPR_SPECTRE_W3,SPR_SPECTRE_W4,
	SPR_SPECTRE_F1,SPR_SPECTRE_F2,SPR_SPECTRE_F3,SPR_SPECTRE_F4,
	}SPR_SPECTRE;

///
/// Angel of Death
///
typedef enum{
	SPR_ANGEL_W1,SPR_ANGEL_W2,SPR_ANGEL_W3,SPR_ANGEL_W4,
	SPR_ANGEL_SHOOT1,SPR_ANGEL_SHOOT2,SPR_ANGEL_TIRED1,SPR_ANGEL_TIRED2,

	SPR_ANGEL_DIE1,SPR_ANGEL_DIE2,SPR_ANGEL_DIE3,SPR_ANGEL_DIE4,
	SPR_ANGEL_DIE5,SPR_ANGEL_DIE6,SPR_ANGEL_DIE7,SPR_ANGEL_DEAD,
	}SPR_ANGEL;

#endif

///
/// player attack frames
///
		typedef enum {
			SPR_KNIFEREADY, SPR_KNIFEATK1, SPR_KNIFEATK2, SPR_KNIFEATK3,
			SPR_KNIFEATK4,

			SPR_PISTOLREADY, SPR_PISTOLATK1, SPR_PISTOLATK2, SPR_PISTOLATK3,
			SPR_PISTOLATK4,

			SPR_MACHINEGUNREADY, SPR_MACHINEGUNATK1, SPR_MACHINEGUNATK2, MACHINEGUNATK3,
			SPR_MACHINEGUNATK4,

			SPR_CHAINREADY, SPR_CHAINATK1, SPR_CHAINATK2, SPR_CHAINATK3,
			SPR_CHAINATK4,
		} SPR_PLAYER;

	};

	/*
	=============================================================================
							   GLOBAL TYPES
	=============================================================================
	*/

	typedef long fixed;

	typedef enum {
		di_north,
		di_east,
		di_south,
		di_west
	} controldir_t;

	typedef enum {
		dr_normal,
		dr_lock1,
		dr_lock2,
		dr_lock3,
		dr_lock4,
		dr_elevator
	} door_t;

	typedef enum {
		ac_badobject = -1,
		ac_no,
		ac_yes,
		ac_allways
	} activeType;

	typedef enum {
		nothing,
		playerObj,
		inertObj,
		guardObj,
		officerObj,
		ssObj,
		dogObj,
		bossObj,
		schabbObj,
		fakeObj,
		mechaHitlerObj,
		mutantObj,
		needleObj,
		fireObj,
		bjObj,
		ghostObj,
		realHitlerObj,
		gretelObj,
		giftObj,
		fatObj,
		rocketObj,

		spetreObj,
		angelObj,
		transObj,
		uberObj,
		willObj,
		deathObj,
		hRocketObj,
		sparkObj
	} classType;

	typedef enum {
		dressing,
		block,
		bo_gibs,
		bo_alps,
		bo_firstaid,
		bo_key1,
		bo_key2,
		bo_key3,
		bo_key4,
		bo_cross,
		bo_chalice,
		bo_bible,
		bo_crown,
		bo_clip,
		bo_clip2,
		bo_machinegun,
		bo_chaingun,
		bo_food,
		bo_fullHeal,
		bo_25clip,
		bo_spear
	} stat_t;

	typedef enum {
		east,
		northEast,
		north,
		northWest,
		west,
		southWest,
		south,
		southEast,
		noDirection
	} directionType;

	const auto NUM_ENEMIES = 22;
	typedef enum {
		en_guard,
		en_officer,
		en_ss,
		en_dog,
		en_boss,
		en_schabbs,
		en_fake,
		en_hitler,
		en_mutant,
		en_blinky,
		en_clyde,
		en_pinky,
		en_inky,
		en_gretel,
		en_gift,
		en_fat,
		en_spectre,
		en_angel,
		en_trans,
		en_uber,
		en_will,
		en_death
	} enemy_t;

	typedef struct stateStruct {
		bool rotate;
		int shapeNum; // a shapeNum of -1 means get from ob->temp1
		int ticTime;

		void (*think)();

		void (*action)();

		struct stateStruct *next;
	} stateType;

	//---------------------
	//
	// trivial actor structure
	//
	//---------------------

	typedef struct statStruct {
		Baumbart13::byte tileX;
		Baumbart13::byte tileY;
		Baumbart13::byte *visSpot;
		int shapeNum; // if shapeNum == -1 the object has been removed
		Baumbart13::byte flags;
		Baumbart13::byte itemNumber;
	} statObj_t;

	//---------------------
	//
	// door actor structure
	//
	//---------------------
	typedef struct doorStruct {
		Baumbart13::byte tileX;
		Baumbart13::byte tileY;
		bool vertical;
		Baumbart13::byte lock;
		enum {
			dr_open,
			dr_closed,
			dr_opening,
			dr_closing
		} action;
		int ticCount;
	}doorObj_t;

	//---------------------
	//
	// thinking actor structure
	//
	//---------------------
	typedef struct objStruct {
		activeType active;
		int ticCount;
		classType obClass;
		stateType *state;

		Baumbart13::byte flags; // FL_SHOOTABLE, etc

		long distance; // if negative, wait for that door to open
		directionType direction;

		fixed x;
		fixed y;

		unsigned int tileX;
		unsigned int tileY;
		Baumbart13::byte areaNumber;

		int viewX;
		unsigned int viewHeight;
		fixed transX; // in global coord
		fixed transY; // in global coord

		int angle;
		int hitpoints;
		long speed;

		int temp1;
		int temp2;
		int temp3;
		struct objStruct *next;
		struct objStruct *prev;
	}objType;

	const int NUM_BUTTONS = 8;
	enum {
		bttn_noButtons = -1,
		bttn_attack = 0,
		bttn_strafe,
		bttn_run,
		bttn_use,
		bttn_readyKnife,
		bttn_readyPistol,
		bttn_readyMachinegun,
		bttn_readyChaingun
	};
};
#endif //WOLF_OWN_WL_DEF_H
