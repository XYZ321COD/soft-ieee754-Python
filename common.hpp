#ifndef _COMMON_H_

#include <Python.h>
#include "soft-ieee754/includes/ieee754.hpp"

#define __COMP_NPY_UNUSED __attribute__ ((__unused__))
#define NPY_UNUSED(x) (__NPY_UNUSED_TAGGED ## x) __COMP_NPY_UNUSED

typedef IEEE754<23,8 > float8bit;

#endif
