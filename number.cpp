#include "number.hpp"
#include <iostream>
#include <stdio.h>
/*
 * Number protocol
 */
static inline float8bit
float_add(float8bit x, float8bit y)
{
    std::cout << "Float8bit add";
    return float(x) + float(y);
}

static inline float8bit
float_subtract(float8bit x, float8bit y)
{
    return x - y;
}

static inline float8bit
float_multiply(float8bit x, float8bit y)
{
    return x * y;
}

static inline float8bit
float_divide(float8bit x, float8bit y)
{
    return x / y;
}

#define _FLOAT_BINOP_IMPL(name, binop) \
    PyObject* \
    pyfloat_##name(PyObject* a, PyObject* b) { \
        float8bit x, y; \
        if(PyFlt_Check(a)) { \
            x = ((PyFlt*)a)->obval; \
        } \
        else { \
            Py_INCREF(Py_NotImplemented); \
            return Py_NotImplemented; \
        } \
        if(PyFlt_Check(b)) { \
            y = ((PyFlt*)b)->obval; \
        } \
        else { \
            Py_INCREF(Py_NotImplemented); \
            return Py_NotImplemented; \
        }\
        return PyFlt_FromFlt(binop(x, y)); \
    }

#define float_BINOP(name) _FLOAT_BINOP_IMPL(name, float_##name)

float_BINOP(add)
float_BINOP(subtract)
float_BINOP(multiply)
float_BINOP(divide)

PyNumberMethods pyflt_as_number = {
    pyfloat_add,          /* nb_add */
    pyfloat_subtract,     /* nb_subtract */
    pyfloat_multiply,     /* nb_multiply */
    pyfloat_divide,       /* nb_divide */
    0,    /* nb_remainder */
    0,                       /* nb_divmod */
    0,                       /* nb_power */
    0,     /* nb_negative */
    0,     /* nb_positive */
    0,     /* nb_absolute */
    0,      /* nb_nonzero */
    0,                       /* nb_invert */
    0,                       /* nb_lshift */
    0,                       /* nb_rshift */
    0,                       /* nb_and */
    0,                       /* nb_xor */
    0,                       /* nb_or */
    0,                       /* nb_coerce */
    0,          /* nb_int */
    0,          /* nb_long */
    0,        /* nb_float */
    0,                       /* nb_oct */
    0,                       /* nb_hex */
    0,                       /* nb_inplace_add */
    0,                       /* nb_inplace_subtract */
    0,                       /* nb_inplace_multiply */
    0,                       /* nb_inplace_divide */
    0,                       /* nb_inplace_remainder */
    0,                       /* nb_inplace_power */
    0,                       /* nb_inplace_lshift */
    0,                       /* nb_inplace_rshift */
    0,                       /* nb_inplace_and */
    0,                       /* nb_inplace_xor */
    0,                       /* nb_inplace_or */

    0, /* nb_floor_divide */
    0,       /* nb_true_divide */
    0,                       /* nb_inplace_floor_divide */
    0,                       /* nb_inplace_true_divide */
    0,                       /* nb_index */
};
