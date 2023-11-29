/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

// clang-format off
#define LAYOUT_6x8(                                                                                           \
  k00,    k01,    k02,    k03,    k04,    k05,    k06,       k67,  k66,  k65,  k64,  k63,  k62,  k61,  k60,   \
  k10,    k11,    k12,    k13,    k14,    k15,    k16,       k77,  k76,  k75,  k74,  k73,  k72,  k71,  k70,   \
  k20,    k21,    k22,    k23,    k24,            k26,       k87,  k86,  k85,  k84,  k83,  k82,  k81,  k80,   \
  k30,    k31,    k32,    k33,    k34,            k36,       k97,  k96,  k95,  k94,  k93,  k92,  k91,  k90,   \
  k40,    k41,    k42,    k43,    k44,    k45,    k46,       k107, k106, k105, k104, k103, k102, k101, k100,  \
  k50,    k51,            k53,    k54,            k56,       k117, k116, k115, k114, k113, k112, k111, k110  \
)                                                                                                                                         \
{                                                                                                                                         \
  {k00,    k01,    k02,    k03,    k04,    k05,    k06,    KC_NO  },                                                                       \
  {k10,    k11,    k12,    k13,    k14,    k15,    k16,    KC_NO  },                                                                       \
  {k20,    k21,    k22,    k23,    k24,    KC_NO,  k26,    KC_NO  },                                                                       \
  {k30,    k31,    k32,    k33,    k34,    KC_NO,  k36,    KC_NO  },                                                                       \
  {k40,    k41,    k42,    k43,    k44,    k45,    k46,    KC_NO  },                                                                       \
  {k50,    k51,    KC_NO,  k53,    k54,    KC_NO,  k56,    KC_NO  },                                                                       \
                                                                                                                                          \
  {k60,    k61,    k62,    k63,    k64,    k65,    k66,    k67    },                                                                      \
  {k70,    k71,    k72,    k73,    k74,    k75,    k76,    k77    },                                                                      \
  {k80,    k81,    k82,    k83,    k84,    k85,    k86,    k87    },                                                                      \
  {k90,    k91,    k92,    k93,    k94,    k95,    k96,    k97    },                                                                      \
  {k100,   k101,   k102,   k103,   k104,   k105,   k106,   k107   },                                                                      \
  {k110,   k111,   k112,   k113,   k114,   k115,   k116,   k117   },                                                                      \
}
// clang-format on


