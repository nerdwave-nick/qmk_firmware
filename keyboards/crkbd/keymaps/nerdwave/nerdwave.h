#ifndef NERDWAVE_H
#define NERDWAVE_H

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "progmem.h"
#include "split_util.h"


#if defined(OLED_ENABLE)
#    include "wpm.h"
#    include "oled.h"
#endif

#ifndef LAYOUT_split_3x6_3
#define LAYOUT_split_3x6_3(k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k40, k41, k32) k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36
#endif

enum layer_names {
    LBASE,
    LGAMING,
    LNAV,
    LMOUSE,
    LMEDIA,
    LNUM,
    LSYM,
    LFN,
};

#endif
