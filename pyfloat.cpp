#include "pyfloat.hpp"
#include "number.hpp"

int
PyFlt_Check(PyObject* object)
{
    return PyObject_IsInstance(object, (PyObject*)&PyFlt_Type);
}

PyObject*
PyFlt_FromFlt(ieee754 x)
{
    PyFlt* p = (PyFlt*)PyFlt_Type.tp_alloc(&PyFlt_Type, 0);
    if (p) {
        p->obval = x;
    }
    return (PyObject*)p;
}

PyObject *
pyfloat_new(PyTypeObject *NPY_UNUSED(type), PyObject *args, PyObject *NPY_UNUSED(kwds)) {
     float c_float;
    
    if(!PyArg_ParseTuple(args,"f", &c_float)) 
        return NULL;
    
    ieee754 q = c_float;
    return PyFlt_FromFlt(q);
}


PyObject *
pyfloat_str(PyObject *self)
{
    char str[128];
    int st;
    ieee754 q = ((PyFlt*)self)->obval;

    st = snprintf(str, sizeof(str), "%f", float(q));
    if (st < 0) {
        fprintf(stderr, "BAD\n");
    }
    return PyString_FromString(str);
}

PyObject *
pyfloat_repr(PyObject *self)
{
    char str[128];
    int st;
    ieee754 q = ((PyFlt*)self)->obval;

    st = snprintf(str, sizeof(str), "%f", float(q));
    if (st < 0) {
        fprintf(stderr, "BAD\n");
    }
    return PyString_FromString(str);
}

PyObject *
castToFloat(PyObject *self)
{
    ieee754 q = ((PyFlt*)self)->obval;
    return PyFloat_FromDouble(float(q)); 
}


static PyMethodDef Float_methods[] = {
    {"castToFloat", (PyCFunction)castToFloat, METH_NOARGS,
     "Return the 32bit float representation"
    },
    {NULL}  /* Sentinel */
};

PyTypeObject PyFlt_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                        /* ob_size */
    "pyfloat",                                   /* tp_name */
    sizeof(PyFlt),                   /* tp_basicsize */
    0,                                        /* tp_itemsize */
    0,                                        /* tp_dealloc */
    0,                                        /* tp_print */
    0,                                        /* tp_getattr */
    0,                                        /* tp_setattr */
    0,                                        /* tp_compare */
    pyfloat_repr,                              /* tp_repr */
    &pyflt_as_number,                         /* tp_as_number */
    0,                                        /* tp_as_sequence */
    0,                                        /* tp_as_mapping */
    0,                                        /* tp_hash */
    0,                                        /* tp_call */
    pyfloat_str,                               /* tp_str */
    0,                                        /* tp_getattro */
    0,                                        /* tp_setattro */
    0,                                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_CHECKTYPES, /* tp_flags */
    "Float precision floating numbers",        /* tp_doc */
    0,                                        /* tp_traverse */
    0,                                        /* tp_clear */
    0,                                        /* tp_richcompare */
    0,                                        /* tp_weaklistoffset */
    0,                                        /* tp_iter */
    0,                                        /* tp_iternext */
    Float_methods,                                        /* tp_methods */
    0,                                        /* tp_members */
    0,        			              /* tp_getset */
    0,                                        /* tp_base */
    0,                                        /* tp_dict */
    0,                                        /* tp_descr_get */
    0,                                        /* tp_descr_set */
    0,                                        /* tp_dictoffset */
    0,                                        /* tp_init */
    0,                                        /* tp_alloc */
    pyfloat_new,                               /* tp_new */
    0,                                        /* tp_free */
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

int
init_flt_type(PyObject *m, PyTypeObject* tp)
{
    PyFlt_Type.tp_base = tp;
    PyFlt_Type.tp_new = pyfloat_new;

    if (PyType_Ready(&PyFlt_Type) < 0) {
        return 0;
    }

    Py_INCREF(&PyFlt_Type);
    PyModule_AddObject(m, "myType", (PyObject*)&PyFlt_Type);
    return 1;
}
