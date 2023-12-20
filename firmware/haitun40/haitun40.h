#pragma once

#include "quantum.h"

#define kXX KC_NO

#define LAYOUT( \
      k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C,\
      k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C,\
      k20, k21, k22, k23, k24, k25, k26, k27,      k29, k2A, k2B, k2C,\
      k30, k31,      k33, k34, k35, k36,           k39, k3A, k3B, k3C \
) \
{ \
  { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C }, \
  { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C }, \
  { k20, k21, k22, k23, k24, k25, k26, k27, kXX, k29, k2A, k2B, k2C }, \
  { k30, k31, kXX, k33, k34, k35, k36, kXX, kXX, k39, k3A, k3B, k3C }  \
}
