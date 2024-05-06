/*
Copyright 2024 haizeus

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "cuticle.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
    }, {
        // LED Index to Physical Position
        {21, 15}, {41, 15}, {61, 15}, {81, 15}, {101, 15}, {121, 15}, {141, 15}, {161, 15}, {181, 15}, {201, 15}, // UNDERGLOW
        {222, 37}, {222, 44}, {218, 44}, { 218, 37}, { 212, 37}, { 212, 44}, // BADGE
        {201, 15}, {181, 15}, {161, 15}, {141, 15}, {121, 15}, {101, 15}, {81, 15}, {61, 15}, {41, 15}, {21, 15}, // UNDERGLOW
        {9, 57}, {9, 42}, {9, 27}, {9, 12} // MACROCOLUMN
    }, {
        // LED Index to Flag
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // UNDERGLOW
        4, 4, 4, 4, 4, 4, // BADGE
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // UNDERGLOW
        1, 1, 1, 1 // MACROCOLUMN
    }
};
#endif