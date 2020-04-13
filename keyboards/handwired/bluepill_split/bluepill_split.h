#pragma once

#include "quantum.h"
#include "led.h"





#define LAYOUT_bluepill_split( \
		K00, K01, K02, K03, K04, K05, K06, \
		K10, K11, K12, K13, K14, K15, K16, \
		K20, K21, K22, K23, K24, K25, K26, \
		K30, K31, K32, K33, K34, K35, K36, K37, \
		K40, K41, K42, K43, K44, K45, K46, K47, \
		K50, K51, K52, K53, K54, K55, K56, K57, \
		K60, K61, K62,      K64,      K66, K67, \
												\
												\
												\
		     K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, \
		     K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, \
		     K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G, \
		K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K3G, \
		K48, K49, K4A, K4B, K4C, K4D, K4E, K4F,      \
		K58, K59, K5A, K5B, K5C, K5D, K5E, 		K5G, \
		K68, K69,      K6B,      K6D, K6E, K6F, K6G) \
												\
												\
												\
/* matrix positions each row below is a column on the keyboard */  	\
	{																\
		{K00, 	K10, 	K20, 	K30, 	K40, 	K50, 	K60		},	\
		{K01, 	K11, 	K21, 	K31, 	K41, 	K51, 	K61		},	\
		{K02, 	K12, 	K22, 	K32, 	K42, 	K52, 	K62		},	\
		{K03, 	K13, 	K23, 	K33, 	K43, 	K53,	KC_NO	},	\
		{K04, 	K14, 	K24, 	K34, 	K44, 	K54, 	K64		},	\
		{K05, 	K15, 	K25, 	K35, 	K45, 	K55, 	KC_NO	},	\
		{K06, 	K16, 	K26, 	K36, 	K46, 	K56, 	K66		},	\
		{KC_NO, KC_NO, 	KC_NO, 	K37, 	K47, 	K57, 	K67		},	\
		{KC_NO, KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO, 	KC_NO		},	\
																	\
																	\
		{KC_NO, KC_NO, 	KC_NO, 	K38, 	K48, 	K58, 	K68		}, 	\
		{K09, 	K19, 	K29, 	K39, 	K49, 	K59, 	K69		}, 	\
		{K0A, 	K1A, 	K2A, 	K3A, 	K4A, 	K5A, 	KC_NO	}, 	\
		{K0B, 	K1B, 	K2B, 	K3B, 	K4B, 	K5B, 	K6B		}, 	\
		{K0C, 	K1C, 	K2C, 	K3C, 	K4C, 	K5C, 	KC_NO	}, 	\
		{K0D, 	K1D, 	K2D, 	K3D, 	K4D, 	K5D, 	K6D		}, 	\
		{K0E, 	K1E, 	K2E, 	K3E, 	K4E, 	K5E, 	K6D		}, 	\
		{K0F,	K1F, 	K2F, 	K3F, 	K4F, 	KC_NO, 	K6F		}, 	\
		{K0G,	K1G, 	K2G, 	K3G, 	KC_NO, 	K5G, 	K6G		}, 	\
	}












/*  ANSI LAYOUT
  ESC| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12| PSC| PGU| PGD
  GRA| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | '  | ¡  |   BCKS  | DEL
  TAB| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | `  | +  |         | HOM
  CAP| A  | S  | D  | F  | G  | H  | J  | K  | L  | Ñ  | ´  | Ç  |   ENTER | END
  LSI| (<)| Z  | X  | C  | V  | B  | N  | M  | ,  | .  | -  |   RSHIF | UP | FNL
  LCT| WIN| ALT|               ESPACE             | ALG| FN | RCT| LEF| DOW| RIG
*/
/*
#define LAYOUT_seventy_ansi( \
  K00, K01, K02, K03,   K04,   K05,   K06, K07,   K08,   K09, K0A, K0B, K0C, K0D, K0E, K0F, \
  K10, K11, K12, K13,   K14,   K15,   K16, K17,   K18,   K19, K1A, K1B, K1C,    K1D,   K1E, \
  K20, K21, K22, K23,   K24,   K25,   K26, K27,   K28,   K29, K2A, K2B, K2C,           K2D, \
  K30, K31, K32, K33,   K34,   K35,   K36, K37,   K38,   K39, K3A, K3B, K3C,      K3D, K3E, \
  K40, K41, K42, K43,   K44,   K45,   K46, K47,   K48,   K49, K4A, K4B,      K4C, K4D, K4E, \
  K50, K51, K52,                      K53,               K54, K55, K56, K57, K58, K59 \
) { \
  { K00, K01, K02, K03,   K04,   K05,   K06, K07,   K08,  K09, K0A, K0B, K0C, K0D, K0F }, \
  { K10, K11, K12, K13,   K14,   K15,   K16, K17,   K18,  K19, K1A, K1B, K1C, K0E, K1E }, \
  { K20, K21, K22, K23,   K24,   K25,   K26, K27,   K28,  K29, K2A, K2B, K2C, K1D, K2D }, \
  { K30, K31, K32, K33,   K34,   K35,   K36, K37,   K38,  K39, K3A, K3B, K3C, K3D, K3E }, \
  { K40, K41, K42, K43,   K44,   K45,   K46, K47,   K48,  K49, K4A, K4B, K4C, K4D, K4E }, \
  { K50, K51, K52, KC_NO, KC_NO, KC_NO, K53, KC_NO, KC_NO,K54, K55, K56, K57, K58, K59 } \
}
*/

/*  ISO LAYOUT
  ESC| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12| PSC| PGU| PGD
  GRA| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | '  | ¡  |   BCKS  | DEL
  TAB| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | `  | +  |         | HOM
  CAP| A  | S  | D  | F  | G  | H  | J  | K  | L  | Ñ  | ´  | Ç  |   ENTER | END
  LSI| <  | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | -  |   RSHIF | UP | FNL
  LCT| WIN| ALT|               ESPACE             | ALG| FN | RCT| LEF| DOW| RIG
*/
/*
#define LAYOUT_seventy_iso( \
  K00, K01, K02, K03,   K04,   K05,   K06, K07,   K08,   K09, K0A, K0B, K0C, K0D, K0E, K0F, \
  K10, K11, K12, K13,   K14,   K15,   K16, K17,   K18,   K19, K1A, K1B, K1C,    K1D,   K1E, \
  K20, K21, K22, K23,   K24,   K25,   K26, K27,   K28,   K29, K2A, K2B, K2C,           K2D, \
  K30, K31, K32, K33,   K34,   K35,   K36, K37,   K38,   K39, K3A, K3B, K3C,      K3D, K3E, \
  K40, K41, K42, K43,   K44,   K45,   K46, K47,   K48,   K49, K4A, K4B,      K4C, K4D, K4E, \
  K50, K51, K52,                      K53,               K54, K55, K56, K57, K58, K59 \
) { \
  { K00, K01, K02, K03,   K04,   K05,   K06, K07,   K08,  K09, K0A, K0B, K0C, K0D, K0F }, \
  { K10, K11, K12, K13,   K14,   K15,   K16, K17,   K18,  K19, K1A, K1B, K1C, K0E, K1E }, \
  { K20, K21, K22, K23,   K24,   K25,   K26, K27,   K28,  K29, K2A, K2B, K2C, K1D, K2D }, \
  { K30, K31, K32, K33,   K34,   K35,   K36, K37,   K38,  K39, K3A, K3B, K3C, K3D, K3E }, \
  { K40, K41, K42, K43,   K44,   K45,   K46, K47,   K48,  K49, K4A, K4B, K4C, K4D, K4E }, \
  { K50, K51, K52, KC_NO, KC_NO, KC_NO, K53, KC_NO, KC_NO,K54, K55, K56, K57, K58, K59 } \
}
*/
