/* Copyright 2022 qpockets
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

extern bool scroll_pressed;

#define XXX KC_NO

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K20, K21, K22, K23, K24,      K26, K27, K28, K29, K2A, \
              K32, K33, K34,      K36, K37, K38            \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A }, \
    { K20, K21, K22, K23, K24, XXX, K26, K27, K28, K29, K2A }, \
    { XXX, XXX, K32, K33, K34, XXX, K36, K37, K38, XXX, XXX }  \
}

enum custom_keycodes {
    KC_SCROLL = SAFE_RANGE,
    KC_CPI_1,
    KC_CPI_2,
    KC_CPI_3
};

