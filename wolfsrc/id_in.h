//
// Created by Baumbart13 on 10.04.2021.
//

#ifndef WOLF_OWN_ID_IN_H
#define WOLF_OWN_ID_IN_H

//#include "id_heads.h" // why does the orig-source doesn't need this include?
namespace id {
	
	namespace in {
#ifdef __DEBUG__
#define __DEBUG_InputMgr__
#endif
		
		const unsigned int _MAX_PLAYERS = 4;
		const unsigned int _MaxKbds = 2;
		const unsigned int _MAX_JOYS = 2;
		const unsigned int _NUM_CODES = 128;
		
		typedef byte ScanCode;
		// Wouldn't it be better to use an enum here instead of the standard way of defining constants? just wondering
		typedef enum {
			sc_None = 0,
			sc_Bad = 0xff,
			sc_Return = 0x1c,
			sc_Enter = sc_Return,
			sc_Escape = 0x01,
			sc_Space = 0x39,
			sc_BackSpace = 0x0e,
			sc_Tab = 0x0f,
			sc_Alt = 0x38,
			sc_Control = 0x1d,
			sc_CapsLock = 0x3a,
			sc_LShift = 0x2a,
			sc_RShift = 0x36,
			sc_UpArrow = 0x48,
			sc_DownArrow = 0x50,
			sc_LeftArrow = 0x4b,
			sc_RightArrow = 0x4d,
			sc_Insert = 0x52,
			sc_Delete = 0x53,
			sc_Home = 0x47,
			sc_End = 0x4f,
			sc_PgUp = 0x49,
			sc_PgDn = 0x51,
			sc_F1 = 0x3b,
			sc_F2 = 0x3c,
			sc_F3 = 0x3d,
			sc_F4 = 0x3e,
			sc_F5 = 0x3f,
			sc_F6 = 0x40,
			sc_F7 = 0x41,
			sc_F8 = 0x42,
			sc_F9 = 0x43,
			sc_F10 = 0x44,
			sc_F11 = 0x57,
			sc_F12 = 0x59,
			
			sc_1 = 0x02,
			sc_2 = 0x03,
			sc_3 = 0x04,
			sc_4 = 0x05,
			sc_5 = 0x06,
			sc_6 = 0x07,
			sc_7 = 0x08,
			sc_8 = 0x09,
			sc_9 = 0x0a,
			sc_0 = 0x0b,
			
			sc_A = 0x1e,
			sc_B = 0x30,
			sc_C = 0x2e,
			sc_D = 0x20,
			sc_E = 0x12,
			sc_F = 0x21,
			sc_G = 0x22,
			sc_H = 0x23,
			sc_I = 0x17,
			sc_J = 0x24,
			sc_K = 0x25,
			sc_L = 0x26,
			sc_M = 0x32,
			sc_N = 0x31,
			sc_O = 0x18,
			sc_P = 0x19,
			sc_Q = 0x10,
			sc_R = 0x13,
			sc_S = 0x1f,
			sc_T = 0x14,
			sc_U = 0x16,
			sc_V = 0x2f,
			sc_W = 0x11,
			sc_X = 0x2d,
			sc_Y = 0x15,
			sc_Z = 0x2c,
		} sc;
		
		typedef enum {
			key_None = 0,
			key_Return = 0x0d,
			key_Enter = key_Return,
			key_Escape = 0x1b,
			key_Space = 0x20,
			key_BackSpace = 0x08,
			key_Tab = 0x09,
			key_Delete = 0x7f
		} key;
		
		/// Stuff for the mouse
		typedef enum {
			MReset = 0,
			MButtons = 3,
			MDelta = 11,
			MouseInt = 0x33
		} M;
		//const unsigned int MouseInt = 0x33;
#define Mouse(x) _AX = x,geninterrupt(id::M::MouseInt) // TODO: how the heck, would the inline function look like of this?
		
		typedef enum {
			demo_Off,
			demo_Record,
			demo_Playback,
			demo_Playdone
		} Demo;
		
		typedef enum {
			ctrl_Keyboard,
			ctrl_Keyboard1 = ctrl_Keyboard,
			ctrl_Keyboard2,
			ctrl_Joystick,
			ctrl_Joystick1 = ctrl_Joystick,
			ctrl_Joystick2,
			ctrl_Mouse
		} ControlType;
		
		typedef enum {
			motion_Left = -1,
			motion_Up = -1,
			motion_None = 0,
			motion_Right = 1,
			motion_Down = 1
		} Motion;
		
		typedef enum {
			dir_North,
			dir_NorthEast,
			dir_East,
			dir_SouthEast,
			dir_South,
			dir_SouthWest,
			dir_West,
			dir_NorthWest,
			dir_None
		} Direction;
		
		typedef struct ControlInfo {
			bool button0,
					button1,
					button2,
					button3;
			int x,
					y;
			Motion xAxis,
					yAxis;
			Direction dir;
		} CursorInfo;
		
		typedef struct {
			ScanCode	button0,
						button1,
					
						upLeft,		up,		upRight,
						left,				right,
						downLeft,	down,	downRight;
		} KeyboardDef;
		
		typedef struct {
			word	joyMinX,	joyMinY,
					threshMinX,	threshMinY,
					threshMaxX,	threshMaxY,
					joyMaxX,	joyMaxY,
					joyMultXL,	joyMultYL,
					joyMultXH,	joyMultYH;
		} JoystickDef;
		
		
		// Global variables
		using namespace id::in;
		
		extern bool	Keyboard[],
					MousePresent,
					JoysPresent[],
					Paused;
		extern char LastASCII;
		extern ScanCode	LastScan;
		extern KeyboardDef KeyboardDefs;
		extern JoystickDef JoyDefs[];
		extern ControlType Controls[_MAX_PLAYERS];
		
		extern Demo	DemoMode;
		extern byte	*DemoBuffer;
		extern word	DemoOffset,
					DemoSize;
		
		//Function prototypes // Well... they are macros, which are quite good defined for just being prototypes
		//#define IN_KeyDown(code) (KeyBoard[(code)])
		bool inline KeyDown(int code){return Keyboard[code];}
		//#define IN_ClearKey(code) {Keyboard[code] = false; if(code==LastScan)LastScan=sc_None;}
		void inline ClearKey(int code){Keyboard[code] = false; if(code==LastScan)LastScan=sc_None;}
		
		//DEBUG - put names in prototypes
		extern void		Startup(void),
						Shutdown(void),
						Default(bool gotIt, ControlType in),
						SetKeyHook(void(*)()),
						ClearKeysDown(void),
						ReadCursor(CursorInfo *),
						ReadControl(int, ControlInfo *),
						SetControlType(int, ControlType),
						GetJoyAbs(word joy, word *xp, word *yp),
						SetupJoy(word joy, word *xp, word *yp, word miny, word maxy),
						StopDemo(void),
						FreeDemoBuffer(void),
						Ack(void),
						AckBack(void);
		extern bool 	UserInput(longword delay);
		extern char		WaitForASCII(void);
		extern ScanCode	WaitForKey(void);
		extern word		GetJoyButtonsDB(word joy);
		extern byte		GetScanName(ScanCode);
		
		byte MouseButtons(void);
		byte JoyButtons(void);
	}
	namespace inl{
		void GetJoyDelta(word joy, int *dx, int *dy);
	}
	namespace in{
		void StartAck(void);
		bool CheckAck(void);
	}
}

#endif //WOLF_OWN_ID_IN_H
