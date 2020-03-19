#ifndef _PYFLOAT_H_
#define _PYFLOAT_H_

#include "common.hpp"

int PyFlt_Check(PyObject* object);
ieee754 PyFlt_AsFlt(PyObject* p);
PyObject* PyFlt_FromFlt(ieee754 x);

typedef struct {
        PyObject_HEAD
        ieee754 obval;
} PyFlt;

extern PyTypeObject PyFlt_Type;

int
init_flt_type(PyObject *m, PyTypeObject* tp);

#endif
