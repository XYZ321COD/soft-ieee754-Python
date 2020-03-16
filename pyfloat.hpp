#ifndef _PYFLOAT_H_
#define _PYFLOAT_H_

#include "common.hpp"

int PyFlt_Check(PyObject* object);
float8bit PyFlt_AsFlt(PyObject* p);
PyObject* PyFlt_FromFlt(float8bit x);

typedef struct {
        PyObject_HEAD
        float8bit obval;
} PyFlt;

extern PyTypeObject PyFlt_Type;

int
init_flt_type(PyObject *m, PyTypeObject* tp);

#endif
