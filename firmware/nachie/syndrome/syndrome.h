/*
Copyright 2021 Nachie

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

#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
    k58,                                k59, k68, k69, k78,\
    k00, k01, k10, k11, k20, k21, k30, k31, k40, k41, k47, \
     k02,  k03, k12, k13, k22, k23, k32, k33, k42,  k43,    \
      k04  , k05, k14, k15, k24, k25, k34, k35, k44,  k45,  \
     k06,  k07,  k16, k17, k27, k36, k37, k46 \
) { \
    { k00, k10, k20, k30, k40, XXX, XXX, XXX }, \
    { k01, k11, k21, k31, k41, XXX, XXX, XXX }, \
    { k02, k12, k22, k32, k42, XXX, XXX, XXX }, \
    { k03, k13, k23, k33, k43, XXX, XXX, XXX }, \
    { k04, k14, k24, k34, k44, XXX, XXX, XXX }, \
    { k05, k15, k25, k35, k45, XXX, XXX, XXX }, \
    { k06, k16, XXX, k36, k46, XXX, XXX, XXX }, \
    { k07, k17, k27, k37, k47, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, k58, k68, k78 }, \
    { XXX, XXX, XXX, XXX, XXX, k59, k69, XXX } \
}
