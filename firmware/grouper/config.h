/*
Copyright 2021 Noah Kiser (contact@kiserdesigns.com)

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

#ifndef CONFIG_H
#define CONFIG_H


#define MATRIX_ROWS 4
#define MATRIX_COLS 13


#define MATRIX_ROW_PINS { GP1, GP13, GP12, GP8 }
#define MATRIX_COL_PINS { GP24, GP23, GP16, GP17, GP18, GP19, GP20, GP25, GP0, GP7, GP9, GP10, GP11 }


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#endif
