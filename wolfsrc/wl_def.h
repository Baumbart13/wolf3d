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
				GRD_PAIN_1, GRD_PAIN_2, GRD_DIE_1, GRD_DIE_2, GRD_DIE_3, GRD_DEAD,
				GRD_SHOOT_1, GRD_SHOOT_2, GRD_SHOOT_3
			}GRD;
			
			///
			/// dogs
			///
			typedef enum{
				DOG_W1_1, DOG_W1_2, DOG_W1_3, DOG_W1_4, DOG_W1_5, DOG_W1_6, DOG_W1_7, DOG_W1_8,
				DOG_W2_1, DOG_W2_2, DOG_W2_3, DOG_W2_4, DOG_W2_5, DOG_W2_6, DOG_W2_7, DOG_W2_8,
				DOG_W3_1, DOG_W3_2, DOG_W3_3, DOG_W3_4, DOG_W3_5, DOG_W3_6, DOG_W3_7, DOG_W3_8,
				DOG_W4_1, DOG_W4_2, DOG_W4_3, DOG_W4_4, DOG_W4_5, DOG_W4_6, DOG_W4_7, DOG_W4_8,
				DOG_DIE_1, DOG_DIE_2, DOG_DIE_3, DOG_DIE_DEAD,
				DOG_JUMP_1, DOG_JUMP_2, DOG_JUMP_3,
			}DOG;
			
			///
			/// ss
			///
			typedef enum{ // Is this still ok in 2021?
				SS_S_1, SS_S_2, SS_S_3, SS_S_4, SS_S_5, SS_S_6, SS_S_7, SS_S_8,
				SS_W1_1, SS_W1_2, SS_W1_3, SS_W1_4, SS_W1_5, SS_W1_6, SS_W1_7, SS_W1_8,
				SS_W2_1, SS_W2_2, SS_W2_3, SS_W2_4, SS_W2_5, SS_W2_6, SS_W2_7, SS_W2_8,
				SS_W3_1, SS_W3_2, SS_W3_3, SS_W3_4, SS_W3_5, SS_W3_6, SS_W3_7, SS_W3_8,
				SS_W4_1, SS_W4_2, SS_W4_3, SS_W4_4, SS_W4_5, SS_W4_6, SS_W4_7, SS_W4_8,
				SS_PAIN_1, SS_PAIN_2, SS_DIE_1, SS_DIE_2, SS_DIE_3, SS_DEAD,
				SS_SHOOT_1, SS_SHOOT_2, SS_SHOOT_3
			}SS;
			
			///
			/// mutant
			///
			typedef enum{
				MUT_S_1, MUT_S_2, MUT_S_3, MUT_S_4, MUT_S_5, MUT_S_6, MUT_S_7, MUT_S_8,
				MUT_W1_1, MUT_W1_2, MUT_W1_3, MUT_W1_4, MUT_W1_5, MUT_W1_6, MUT_W1_7, MUT_W1_8,
				MUT_W2_1, MUT_W2_2, MUT_W2_3, MUT_W2_4, MUT_W2_5, MUT_W2_6, MUT_W2_7, MUT_W2_8,
				MUT_W3_1, MUT_W3_2, MUT_W3_3, MUT_W3_4, MUT_W3_5, MUT_W3_6, MUT_W3_7, MUT_W3_8,
				MUT_W4_1, MUT_W4_2, MUT_W4_3, MUT_W4_4, MUT_W4_5, MUT_W4_6, MUT_W4_7, MUT_W4_8,
				MUT_PAIN_1, MUT_PAIN_2, MUT_DIE_1, MUT_DIE_2, MUT_DIE_3, MUT_DIE_4, MUT_DEAD,
				MUT_SHOOT_1, MUT_SHOOT_2, MUT_SHOOT_3, MUT_SHOOT_4
			}MUT;
			
			///
			/// officer
			///
			typedef enum{
				OFC_S_1, OFC_S_2, OFC_S_3, OFC_S_4, OFC_S_5, OFC_S_6, OFC_S_7, OFC_S_8,
				OFC_W1_1, OFC_W1_2, OFC_W1_3, OFC_W1_4, OFC_W1_5, OFC_W1_6, OFC_W1_7, OFC_W1_8,
				OFC_W2_1, OFC_W2_2, OFC_W2_3, OFC_W2_4, OFC_W2_5, OFC_W2_6, OFC_W2_7, OFC_W2_8,
				OFC_W3_1, OFC_W3_2, OFC_W3_3, OFC_W3_4, OFC_W3_5, OFC_W3_6, OFC_W3_7, OFC_W3_8,
				OFC_W4_1, OFC_W4_2, OFC_W4_3, OFC_W4_4, OFC_W4_5, OFC_W4_6, OFC_W4_7, OFC_W4_8,
				OFC_PAIN_1, OFC_PAIN_2, OFC_DIE_1, OFC_DIE_2, OFC_DIE_3, OFC_DIE_4, OFC_DEAD,
				OFC_SHOOT_1, OFC_SHOOT_2, OFC_SHOOT_3
			}OFC;

#ifndef SPEAR
			///
			/// ghosts
			///
			typedef enum{
				BLINKY_W1, PINKY_W1, CLYDE_W1, INKY_W1,
				BLINKY_W2, PINKY_W2, CLYDE_W2, INKY_W2
			}ghosts;
			
			///
			/// hans
			///
			typedef enum{
				BOSS_W1, BOSS_W2, BOSS_W3, BOSS_W4,
				BOSS_SHOOT1, BOSS_SHOOT2, BOSS_SHOOT3,
				BOSS_DEAD, BOSS_DIE1, BOSS_DIE2, BOSS_DIE3
			}BOSS;
			
			///
			/// schabbs
			///
			typedef enum{
				SCHABB_W1, SCHABB_W2, SCHABB_W3, SCHABB_W4,
				SCHABB_SHOOT1, SCHABB_SHOOT2,
				SCHABB_DIE1, SCHABB_DIE2, SCHABB_DIE3, SCHABB_DEAD,
				SCHABB_HYPO1, SCHABB_HYPO2, SCHABB_HYPO3, SCHABB_HYPO4,
			}SCHABB;
			
			///
			/// fake
			///
			typedef enum{
				FAKE_W1, FAKE_W2, FAKE_W3, FAKE_W4,
				FAKE_SHOOT, FIRE1, FIRE2, //"FIRE1, FIRE2"?! WHAT?!
				FAKE_DIE1, FAKE_DIE2, FAKE_DIE3, FAKE_DIE4, FAKE_DIE5, FAKE_DEAD
			}FAKE;
			
			///
			/// hitler
			///
			typedef enum MECHA{
				MECHA_W1, MECHA_W2, MECHA_W3, MECHA_W4,
				MECHA_SHOOT1, MECHA_SHOOT2, MECHA_SHOOT3, MECHA_DEAD,
				MECHA_DIE1, MECHA_DIE2, MECHA_DIE3,
				
				
				HITLER_W1, HITLER_W2, HITLER_W3, HITLER_W4,
				HITLER_SHOOT1, HITLER_SHOOT2, HITLER_SHOOT3, HITLER_DEAD,
				HITLER_DIE1, HITLER_DIE2, HITLER_DIE3, HITLER_DIE4, HITLER_DIE5, HITLER_DIE6, HITLER_DIE7,
			} HITLER; // is this still ok in 2021?
			
			///
			/// giftmacher
			///
			typedef enum{
				GIFT_W1, GIFT_W2, GIFT_W3, GIFT_W4,
				GIFT_SHOOT1, GIFT_SHOOT2,
				GIFT_DIE1, GIFT_DIE2, GIFT_DIE3, GIFT_DEAD
			}GIFT;
#endif // SPEAR
			
			///
			/// Rocket, smoke and small explosion
			///
			typedef enum ROCKET{
				ROCKET_1, ROCKET_2, ROCKET_3, ROCKET_4, ROCKET_5, ROCKET_6, ROCKET_7, ROCKET_8,
				SMOKE_1, SMOKE_2, SMOKE_3, SMOKE_4,
				BOOM_1, BOOM_2, BOOM_3
			}SMOKE, BOOM;

#ifdef SPEAR
			///
			/// Angel of Death's DeathSparks(tm)
			///
			typedef enum HROCKET{
				ROCKET_1, ROCKET_2, ROCKET_3, ROCKET_4, ROCKET_5, ROCKET_6, ROCKET_7, ROCKET_8,
				SMOKE_1, SMOKE_2, SMOKE_3, SMOKE_4,
				BOOM_1, BOOM_2, BOOM_3,
				SPARK1, SPARK2, SPARK3, SPARK4
			}HSMOKE, HBOOM, SPARK;
#endif // SPEAR

#ifndef SPEAR
			///
			/// gretel
			///
			typedef enum{
				GRETEL_W1, GRETEL_W2, GRETEL_W3, GRETEL_W4,
				GRETEL_SHOOT1, GRETEL_SHOOT2, GRETEL_SHOOT3,
				GRETEL_DIE1, GRETEL_DIE2, GRETEL_DIE3, GRETEL_DEAD
			}GRETEL;
			
			///
			/// fat face
			///
			typedef enum{
				FAT_W1, FAT_W2, FAT_W3, FAT_W4,
				FAT_SHOOT1, FAT_SHOOT2, FAT_SHOOT3, FAT_SHOOT4,
				FAT_DIE1, FAT_DIE2, FAT_DIE3, FAT_DEAD,
			}FAT;
			
			///
			/// bj
			///
			typedef enum{
				BJ_W1, BJ_W2, BJ_W3, BJ_W4,
				BJ_JUMP1, BJ_JUMP2, BJ_JUMP3, BJ_JUMP4
			}BJ;
#else // SPEAR
			//
			// THESE ARE FOR 'SPEAR OF DESTINY'
			//
			
			///
			/// Trans Grosse
			///
			typedef enum{ // is this still ok in 2021?
				TRANS_W1, TRANS_W2, TRANS_W3, TRANS_W4,
				TRANS_SHOOT1, TRANS_SHOOT2, TRANS_SHOOT3,
				TRANS_DIE1, TRANS_DIE2, TRANS_DIE3, TRANS_DEAD
			}TRANS;
			
			///
			/// Wilhelm
			///
			typedef enum{
			
			}WILL;

			// TODO: halted in wl_def.h at Wilhelm
			
#endif // SPEAR
		}
	}
}
#endif //WOLF_OWN_WL_DEF_H
