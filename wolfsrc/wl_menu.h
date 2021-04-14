//
// Created by Baumbart13 on 09.04.2021.
//

#ifndef WOLF3D_OWN_WL_MENU_H
#define WOLF3D_OWN_WL_MENU_H


#ifdef SPEAR

const unsigned char _BORD_COLOR =	0x99;
const unsigned char _BORD2_COLOR =	0x93;
const unsigned char _DEACTIVE =		0x9b;
const unsigned char _BKGD_COLOR =	0x9d;
const unsigned char _STRIPE =		0x9c;
//#define MenuFadeOut() VL_FadeOut(0,255,0,0,51,10) // TODO: inline Function with different params, according to if SPEAR is defined or not

#else // SPEAR
namespace WOLF {
	namespace MENU {
		const unsigned int _BORD_COLOR = 0x29;
		const unsigned int _BORD2_COLOR = 0x23;
		const unsigned int _DEACTIVE = 0x2b;
		const unsigned int _BKGD_COLOR = 0x2d;
		const unsigned int _STRIPE = 0x2c;
//#define MenuFadeOut() VL_FadeOut(0,255,0,0,51,10) // TODO: inline Function with different params, according to if SPEAR is defined or not

#endif // SPEAR
		
		const unsigned int _READ_COLOR = 0x4a;
		const unsigned int _READ_HCOLOR = 0x47;
		const unsigned int _VIEW_COLOR = 0x7f;
		const unsigned int _TEXT_COLOR = 0x17;
		const unsigned int _HIGHLIGHT = 0x13;
//#define MenuFadeIn() VL_FadeIn(0,255,&gamepal,10) // TODO: inline Function with different params, according to different DEFINITIONS

// TODO: change *_MUS to an enum.. maybe
#define MENUSONG WONDERIN_MUS

#ifndef SPEAR
#define INTROSONG NAZI_NOR_MUS
#else // SPEAR
#define INTROSONG XTOWER2_MUS
#endif // SPEAR
		
		const unsigned int _SENSITIVE = 60;
		const unsigned int _CENTER = _SENSITIVE * 2;
		
		/// Probably the dimensions of the menu screen
		namespace MENU{
			const unsigned int	x = 76,
								y = 55,
#ifndef SPEAR
								h = 13 * 10 + 6,
#else
								h = 13 * 9 + 6,
#endif
								w = 178;
		}

		/// What does "SM" stands for?... it's at least some size/dimension.. but what size/dimension?
		/// Well... i'll pack it also into an enum
		namespace SM {
			const unsigned int	x = 48,
								w = 250,
								
								y1 = 20,
								h1 = 4 * 13 - 7,
								y2 = y1 + 5 * 13,
								h2 = 4 * 13 - 7,
								y3 = y2 + 5 * 13,
								h3 = 3 * 13 - 7;
		}
		
		/// What does "CTL" stands for?... it's at least some size/dimension.. but what
		namespace CTL{
			const unsigned int	x =	24,
								y =	70,
								w =	284,
								h =	13 * 7 - 7;
		}
		
		namespace LSM{
			const unsigned int	x =	24,
								y =	70,
								w =	284,
								h =	13 * 7 - 7;
		}
		
		namespace NM{
			const unsigned int	x =	50,
								y =	100,
								w =	225,
								h =	13 * 4 + 15;
		}
		
		namespace NE{
			const unsigned int	x =	10,
								y =	23,
								w =	320 - x * 2,
								h =	200 - y * 2;
		}
		
		namespace CST{
			const unsigned int	x =		20,
								y =		48,
								start =	60,
								spc =	60;
		}
		
		//
		// TYPEDEFS
		//
		
		namespace CP {
			
			typedef struct {
				int	x,
					y,
					amount,
					curpos,
					indent;
			} itemInfo;
			
			typedef struct {
				int active;	// is this item active?
				char string[36];  // name of this item// TODO: maybe change WOLF::MENU::CP::itemType to std::string
				void (*routine)(int temp1); // WHAT?!
			} itemType;
			
			extern itemType MainMenu[], NewEMenu[];
			extern itemInfo MainItems[];
		}
		
		/// Custom Key mapping for controls, I guess?
		typedef struct{
			int allowed[4]; // orig: turn left, turn right, forwards, backwards.. but in which order?
		} CustomCtrls;
		
		/// Just a helper struct for rectangles. There were too many arguments on a single window/rectangle, so I
		/// ended up with this little helper.
		typedef struct{
			int	x,
				y,
				w,
				h;
		}rectangleDimension_BAUM;
		
		//
		// FUNCTION PROTOTYPES
		//
		void	SetupControlPanel(void),
				CleanupControlPanel(void),
				DrawMenu(CP::itemInfo *itemInfo, CP::itemType *items);
		int		HandleMenu(CP::itemInfo *itemInfo, CP::itemType *items, void(*routine)(int w));
		void	clearMScreen(void),
				DrawWindow(rectangleDimension_BAUM, int wColor),
				DrawOutline(rectangleDimension_BAUM, int color1, int color2),
				WaitKeyUp(void),
				ReadAnyControl(ControlInfo *ci),
				TicDelay(int count),
				CacheLump(int lumpStart, int lumpEnd),
				UnCacheLump(int lumpStart, int lumpEnd),
				StartCPMusic(int song);
		int 	Confirm(char *string); // TODO: maybe change WOLF::MENU to std::string
		void	Message(char *string), // TODO: maybe change WOLF::MENU to std::string
				CheckPause(void),
				ShootSnd(void),
				CheckSecretMissions(void),
				BossKey(void);
		
		void	DrawGun(CP::itemInfo *itemInfo, CP::itemType *items, int x, int *y, int which, int baseY, void (*routine)(int w)),
				DrawHalfStep(int x, int y),
				EraseGun(CP::itemInfo *itemInfo, CP::itemType *items, int x, int y, int which),
				SetTextColor(CP::itemInfo *itemInfo, int hLight),
				DrawMenuGun(CP::itemInfo *itemInfo),
				DrawStripes(int y);
		
		void	DefineMouseBtns(void),
				DefineJoyBtns(void),
				DefineKeyBtns(void),
				DefineKeyMove(void),
				EnterCtrlDelete(int index, CustomCtrls *customCtrls, void (*DrawRtn)(int), void (*PrintRtn)(int), int type);
		
		void	DrawMainMenu(void),
				DrawSoundMenu(void),
				DrawLoadSaceScreen(int loadSave),
				DrawNewEpisode(void),
				DrawNewGame(void),
				DrawChangeView(void),
				DrawMouseSens(void),
				DrawCtrlScreen(void),
				DrawCustomScreen(void),
				DrawLSAction(int which),
				DrawCustMouse(int hilight),
				DrawCustJoy(int hilight),
				DrawCustKeyboard(int hilight),
				DrawCustKeys(int hilight),
				PrintCustMouse(int i),
				PrintCustJoy(int i),
				PrintCustKeyboard(int i),
				PrintCustKeys(int i);
		
		void	PrintLSEntry(int w, int color),
				TrackWhichGame(int w),
				DrawNewGameDiff(int w),
				FixupCustom(int w);
		
		namespace CP{
			void	NewGame(void),
					Sound(void),
					LoadGame(void),
					SaveGame(void),
					Control(void),
					ChangeView(void),
					ExitOptions(void),
					Quit(void),
					ViewScores(void);
			int		EndGame(void),
					CheckQuick(unsigned scanCode);
		}
		
		void	CustomControls(void),
				MouseSensitivity(void);
		
		void	CheckForEpisodes(void);
		
		//
		// VARIABLES
		//
		extern int	SaveFamesAvail[10],
					StartGame,
					SoundStatus;
		extern char	SaveGameName[10][32], // TODO: maybe change this to std::string[10]
					SaveName[13]; // TODO: lookup if this is a 13-long string or an array with 13 elements
					
		enum {
			MOUSE,
			JOYSTICK,
			KEYBOARD_BTNS,
			KEYBOARD_MOVE
		}; // FOR INPUT TYPES // Why did id create an anonymous enum? weird way of creating constants maybe?
		
		enum{
			newGame,
			soundMenu,
			control,
			loadGame,
			saveGame,
			changeView,

#ifndef GOODTIMES
#ifndef SPEAR
			readThis,
#endif // SPEAR
#endif // GOODTIMES

			viewScores,
			backToDemo,
			quit
		}menuItems;
		
		//
		// WL_INTER
		//
		// TODO: maybe move this part from WOLF::MENU to WOLF::INTER
		typedef struct{
			int 	kill,
					secret,
					treasure;
			long	time;
		} LRstruct;
		
		extern LRstruct LevelRatios[];
		
		void Write(int x, int y, char *string); // TODO: maybe change WOLF::MENU to std::string
		void NonShareware(void);
		int GetYorN(int x, int y, int pic);
	}
}

#endif //WOLF3D_OWN_WL_MENU_H
