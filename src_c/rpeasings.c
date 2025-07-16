#include <math.h>
#include <Python.h>

#include <docstrings.h>
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"

#define PI 3.141592653589793
#define C1 1.70158
#define C2 (C1 * 1.525)
#define C3 (C1 + 1.0)
#define C4 (2 * PI) / 3.0
#define C5 (2 * PI) / 4.5



/*----------------------------------------------------------------------
 ____        __ _       _ _   _                 
|  _ \  ___ / _(_)_ __ (_) |_(_) ___  _ __  ___ 
| | | |/ _ \ |_| | '_ \| | __| |/ _ \| '_ \/ __|
| |_| |  __/  _| | | | | | |_| | (_) | | | \__ \
|____/ \___|_| |_|_| |_|_|\__|_|\___/|_| |_|___/

----------------------------------------------------------------------*/

/* easing implementations */

double null(double t);
double bounce_out(double t);
double in_quad(double t);
double out_quad(double t);
double in_out_quad(double t);
double in_cubic(double t);
double out_cubic(double t);
double in_out_cubic(double t);
double in_quart(double t);
double out_quart(double t);
double in_out_quart(double t);
double in_quint(double t);
double out_quint(double t);
double in_out_quint(double t);
double in_sine(double t);
double out_sine(double t);
double in_out_sine(double t);
double in_expo(double t);
double out_expo(double t);
double in_out_expo(double t);
double in_circ(double t);
double out_circ(double t);
double in_out_circ(double t);
double in_back(double t);
double out_back(double t);
double in_out_back(double t);
double in_elastic(double t);
double out_elastic(double t);
double in_out_elastic(double t);
double in_bounce(double t);
double out_bounce(double t);
double in_out_bounce(double t);

/* Module level functions */
static PyObject * rpeasings_null(PyObject *self, PyObject *t);
static PyObject * rpeasings_bounce_out(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_quad(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_quad(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_quad(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_cubic(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_cubic(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_cubic(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_quart(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_quart(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_quart(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_quint(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_quint(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_quint(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_sine(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_sine(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_sine(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_expo(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_expo(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_expo(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_circ(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_circ(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_circ(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_back(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_back(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_back(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_elastic(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_elastic(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_elastic(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_bounce(PyObject *self, PyObject *t);
static PyObject * rpeasings_out_bounce(PyObject *self, PyObject *t);
static PyObject * rpeasings_in_out_bounce(PyObject *self, PyObject *t);

/* Module init */
PyMODINIT_FUNC PyInit_rpeasings(void);

/*----------------------------------------------------------------------
     _     _           _ _                 
    | |__ (_)_ __   __| (_)_ __   __ _ ___ 
    | '_ \| | '_ \ / _` | | '_ \ / _` / __|
    | |_) | | | | | (_| | | | | | (_| \__ \
    |_.__/|_|_| |_|\__,_|_|_| |_|\__, |___/
				 |___/     
----------------------------------------------------------------------*/

/* Module level methods */
static PyMethodDef rpeasings_methods[] = {
    {"null", (PyCFunction)rpeasings_null, METH_O, NULL},
    {"bounce_out", (PyCFunction)rpeasings_bounce_out, METH_O, NULL},
    {"in_quad", (PyCFunction)rpeasings_in_quad, METH_O, NULL},
    {"out_quad", (PyCFunction)rpeasings_out_quad, METH_O, NULL},
    {"in_out_quad", (PyCFunction)rpeasings_in_out_quad, METH_O, NULL},
    {"in_cubic", (PyCFunction)rpeasings_in_cubic, METH_O, NULL},
    {"out_cubic", (PyCFunction)rpeasings_out_cubic, METH_O, NULL},
    {"in_out_cubic", (PyCFunction)rpeasings_in_out_cubic, METH_O, NULL},
    {"in_quart", (PyCFunction)rpeasings_in_quart, METH_O, NULL},
    {"out_quart", (PyCFunction)rpeasings_out_quart, METH_O, NULL},
    {"in_out_quart", (PyCFunction)rpeasings_in_out_quart, METH_O, NULL},
    {"in_quint", (PyCFunction)rpeasings_in_quint, METH_O, NULL},
    {"out_quint", (PyCFunction)rpeasings_out_quint, METH_O, NULL},
    {"in_out_quint", (PyCFunction)rpeasings_in_out_quint, METH_O, NULL},
    {"in_sine", (PyCFunction)rpeasings_in_sine, METH_O, NULL},
    {"out_sine", (PyCFunction)rpeasings_out_sine, METH_O, NULL},
    {"in_out_sine", (PyCFunction)rpeasings_in_out_sine, METH_O, NULL},
    {"in_expo", (PyCFunction)rpeasings_in_expo, METH_O, NULL},
    {"out_expo", (PyCFunction)rpeasings_out_expo, METH_O, NULL},
    {"in_out_expo", (PyCFunction)rpeasings_in_out_expo, METH_O, NULL},
    {"in_circ", (PyCFunction)rpeasings_in_circ, METH_O, NULL},
    {"out_circ", (PyCFunction)rpeasings_out_circ, METH_O, NULL},
    {"in_out_circ", (PyCFunction)rpeasings_in_out_circ, METH_O, NULL},
    {"in_back", (PyCFunction)rpeasings_in_back, METH_O, NULL},
    {"out_back", (PyCFunction)rpeasings_out_back, METH_O, NULL},
    {"in_out_back", (PyCFunction)rpeasings_in_out_back, METH_O, NULL},
    {"in_elastic", (PyCFunction)rpeasings_in_elastic, METH_O, NULL},
    {"out_elastic", (PyCFunction)rpeasings_out_elastic, METH_O, NULL},
    {"in_out_elastic", (PyCFunction)rpeasings_in_out_elastic, METH_O, NULL},
    {"in_bounce", (PyCFunction)rpeasings_in_bounce, METH_O, NULL},
    {"out_bounce", (PyCFunction)rpeasings_out_bounce, METH_O, NULL},
    {"in_out_bounce", (PyCFunction)rpeasings_in_out_bounce, METH_O, NULL},
    {NULL, NULL, 0, NULL},
};


static PyModuleDef rpeasings_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "rpeasings",
    .m_doc = MODULE_DOCSTRING,
    .m_size = -1,
    .m_methods = rpeasings_methods,
};


/*----------------------------------------------------------------------
     _____          _                 
    | ____|__ _ ___(_)_ __   __ _ ___ 
    |  _| / _` / __| | '_ \ / _` / __|
    | |__| (_| \__ \ | | | | (_| \__ \
    |_____\__,_|___/_|_| |_|\__, |___/
                            |___/     

----------------------------------------------------------------------*/

double null(double t) {
    return t;
}

double bounce_out(double t) {
    double n1 = 7.5625;
    double d1 = 2.75;

    if (t < 1 / d1) {
        return n1 * t * t;
    }
    else if (t < 2 / d1) {
        double ft = t - 1.5 / d1;
        return n1 * ft * ft + 0.75;
    }
    else if (t < 2.5 / d1) {
        double ft = t - 2.25 / d1;
        return n1 * ft * ft + 0.9375;
    }

    double ft = t - 2.625 / d1;
    return n1 * ft * ft + 0.984375;
}


double in_quad(double t) {
    return t * t;
}


double out_quad(double t) {
    return 1.0 - (1.0 - t) * (1.0 - t);
}


double in_out_quad(double t) {
    double f = -2 * t + 2.0;

    return 
        t < 0.5
        ? 2.0 * t * t
        : 1.0 - f * f / 2.0;
}


double in_cubic(double t) {
    return t * t * t;
}


double out_cubic(double t) {
    double f = 1.0 - t;

    return 1.0 - f * f * f;
}


double in_out_cubic(double t) {
    double f = -2.0 * t + 2.0;

    return 
        t < 0.5
        ? 4 * t * t * t
        : 1.0 - f * f * f / 2.0;
}


double in_quart(double t) {
    return t * t * t * t;
}


double out_quart(double t) {
    double f = 1.0 - t;

    return 1.0 - f * f * f * f;
}


double in_out_quart(double t) {
    double f = -2.0 * t + 2.0;

    return
        t < 0.5
        ? 8 * t * t * t * t 
        : 1.0 - f * f * f * f / 2.0;
}


double in_quint(double t) {
    return t * t * t * t * t;
}


double out_quint(double t) {
    double f = 1.0 - t;

    return 1.0 - f * f * f * f * f;
}


double in_out_quint(double t) {
    double f = -2.0 * t + 2.0;

    return
        t < 0.5
        ? 16 * t * t * t * t * t
        : 1.0 - f * f * f * f * f / 2.0;
}


double in_sine(double t) {
    return 1.0 - cos((t * PI) / 2.0);
}


double out_sine(double t) {
    return sin((t * PI) / 2.0);
}


double in_out_sine(double t) {
    return -(cos(PI * t) - 1.0) / 2.0;
}


double in_expo(double t) {
    return 
        t == 0
        ? 0
        : pow(2.0, 10.0 * t - 10.0);
}


double out_expo(double t) {
    return
        t == 1.0
        ? 1.0
        : 1.0 - pow(2.0, -10.0 * t);
}


double in_out_expo(double t) {
    if (t == 0) {
        return 0;
    }
    else if (t == 1.0) {
        return 1.0;
    }
    else if (t < 0.5) {
        return pow(2.0, 20 * t - 10) / 2.0;
    }
    else {
        return (2.0 - pow(2.0, -20 * t + 10)) / 2.0;
    }

    if (t == 0) {
        return 0;
    }
    else if (t == 1.0) {
        return 1.0;
    }
    else if (t < 0.5) {
        return pow(2.0, 20 * t - 10) / 2.0;
    }
    else {
        return (2.0 - pow(2.0, -20 * t + 10)) / 2.0;
    }
}

double in_circ(double t) {
    return 1.0 - sqrt(1.0 - t * t);
}


double out_circ(double t) {
    return sqrt(1.0 - (t - 1.0) * (t - 1.0));
}


double in_out_circ(double t) {
    double f1 = t + t;
    double f2 = -2.0 * t + 2.0;

    return
        t < 0.5
        ? (1.0 - sqrt(1.0 - f1 * f1)) / 2.0
        : (sqrt(1.0 - f2 * f2) + 1.0) / 2.0;
}


double in_back(double t) {
    return C3 * t * t * t - C1 * t * t;
}


double out_back(double t) {
    double f = t - 1.0;

    return 1.0 + C3 * f * f * f + C1 * f * f;
}


double in_out_back(double t) {
    double f1 = t + t;
    double f2 = f1 - 2.0;

    return
        t < 0.5 
        ? (f1 * f1 * ((C2 + 1.0) * 2.0 * t - C2)) / 2.0
        :(f2 * f2 * ((C2 + 1.0) * (t * 2.0 - 2.0) + C2) + 2.0) / 2.0;
}


double in_elastic(double t) {
    if (t == 0) {
        return 0;
    }
    else if (t == 1.0) {
        return 1.0;
    }

    return -pow(2.0, 10 * t - 10) * sin((t * 10 - 10.75) * C4);
}


double out_elastic(double t) {
    if (t == 0) {
        return 0;
    }
    else if (t == 1.0) {
        return 1.0;
    }

    return pow(2.0, -10 * t) * sin((t * 10 - 0.75) * C4) + 1.0;
}


double in_out_elastic(double t) {
    if (t == 0) {
        return 0;
    }
    else if (t == 1.0) {
        return 1.0;
    }
    else if (t < 0.5) {
        return -(pow(2.0, 20 * t - 10) * sin((20 * t - 11.125) * C5)) / 2.0;
    }

    return (pow(2.0, -20 * t + 10) * sin((20 * t - 11.125) * C5)) / 2.0 + 1.0;
}


double in_bounce(double t) {
    return 1.0 - bounce_out(1.0 - t);
}


double out_bounce(double t) {
    return bounce_out(t);
}


double in_out_bounce(double t) {
    return
        t < 0.5
        ? (1.0 - bounce_out(1.0 - 2.0 * t)) / 2.0
        : (1.0 + bounce_out(2.0 * t - 1.0)) / 2.0;
}


/*----------------------------------------------------------------------
      __                  _   _                 
     / _|_   _ _ __   ___| |_(_) ___  _ __  ___ 
    | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
    |  _| |_| | | | | (__| |_| | (_) | | | \__ \
    |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
                                            
----------------------------------------------------------------------*/
PyObject * get_t_and_call_easing(PyObject *p_t, double (*ease)(double)) {
    double t;

    t = PyFloat_AsDouble((PyObject *)p_t);
    if (t == -1.0 && PyErr_Occurred()) {
        return NULL;
    }

    return PyFloat_FromDouble(ease(t));
}

static PyObject * rpeasings_null(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &null);
}


static PyObject * rpeasings_bounce_out(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &bounce_out);
}


static PyObject * rpeasings_in_quad(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_quad);
}


static PyObject * rpeasings_out_quad(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_quad);
}


static PyObject * rpeasings_in_out_quad(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_quad);
}


static PyObject * rpeasings_in_cubic(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_cubic);
}


static PyObject * rpeasings_out_cubic(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_cubic);
}


static PyObject * rpeasings_in_out_cubic(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_cubic);
}


static PyObject * rpeasings_in_quart(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_quart);
}


static PyObject * rpeasings_out_quart(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_quart);
}


static PyObject * rpeasings_in_out_quart(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_quart);
}


static PyObject * rpeasings_in_quint(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_quint);
}


static PyObject * rpeasings_out_quint(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_quint);
}


static PyObject * rpeasings_in_out_quint(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_quint);
}


static PyObject * rpeasings_in_sine(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_sine);
}


static PyObject * rpeasings_out_sine(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_sine);
}


static PyObject * rpeasings_in_out_sine(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_sine);
}


static PyObject * rpeasings_in_expo(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_expo);
}


static PyObject * rpeasings_out_expo(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_expo);
}


static PyObject * rpeasings_in_out_expo(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_expo);
}


static PyObject * rpeasings_in_circ(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_circ);
}


static PyObject * rpeasings_out_circ(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_circ);
}


static PyObject * rpeasings_in_out_circ(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_circ);
}


static PyObject * rpeasings_in_back(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_back);
}


static PyObject * rpeasings_out_back(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_back);
}


static PyObject * rpeasings_in_out_back(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_back);
}


static PyObject * rpeasings_in_elastic(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_elastic);
}


static PyObject * rpeasings_out_elastic(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_elastic);
}


static PyObject * rpeasings_in_out_elastic(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_elastic);
}


static PyObject * rpeasings_in_bounce(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_bounce);
}


static PyObject * rpeasings_out_bounce(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &out_bounce);
}


static PyObject * rpeasings_in_out_bounce(PyObject *self, PyObject *p_t) {
    return get_t_and_call_easing(p_t, &in_out_bounce);
}

/*----------------------------------------------------------------------
			 _       _      
     _ __ ___   ___   __| |_   _| | ___ 
    | '_ ` _ \ / _ \ / _` | | | | |/ _ \
    | | | | | | (_) | (_| | |_| | |  __/
    |_| |_| |_|\___/ \__,_|\__,_|_|\___|

----------------------------------------------------------------------*/

void add_function_to_dict(PyObject *dict, const char *key, PyMethodDef *func_def) {
    PyObject *func = PyCFunction_New(func_def, NULL);

    if (func != NULL) {
	PyDict_SetItemString(dict, key, func);
	Py_DECREF(func);
    }
}

PyMODINIT_FUNC PyInit_rpeasings(void) {
    PyObject *m;

    m = PyModule_Create(&rpeasings_module);
    if (m == NULL)
	return NULL;

    PyObject *all = Py_BuildValue(
            "(s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s, s)",
            "null", "bounce_out", "in_quad", "out_quad", "in_out_quad",
            "in_cubic", "out_cubic", "in_out_cubic", "in_quart", "out_quart",
            "in_out_quart", "in_quint", "out_quint", "in_out_quint",
            "in_sine", "out_sine", "in_out_sine", "in_expo", "out_expo",
            "in_out_expo", "in_circ", "out_circ", "in_out_circ", "in_back",
            "out_back", "in_out_back", "in_elastic", "out_elastic",
            "in_out_elastic", "in_bounce", "out_bounce", "in_out_bounce");
    if (all != NULL) {
        PyModule_AddObject(m, "__all__", all);
    }
    else {
        Py_CLEAR(all);
    }

    PyObject *easings = PyDict_New();
    add_function_to_dict(easings, "null", &rpeasings_methods[0]);
    add_function_to_dict(easings, "bounce_out", &rpeasings_methods[1]);
    add_function_to_dict(easings, "in_quad", &rpeasings_methods[2]);
    add_function_to_dict(easings, "out_quad", &rpeasings_methods[3]);
    add_function_to_dict(easings, "in_out_quad", &rpeasings_methods[4]);
    add_function_to_dict(easings, "in_cubic", &rpeasings_methods[5]);
    add_function_to_dict(easings, "out_cubic", &rpeasings_methods[6]);
    add_function_to_dict(easings, "in_out_cubic", &rpeasings_methods[7]);
    add_function_to_dict(easings, "in_quart", &rpeasings_methods[8]);
    add_function_to_dict(easings, "out_quart", &rpeasings_methods[9]);
    add_function_to_dict(easings, "in_out_quart", &rpeasings_methods[10]);
    add_function_to_dict(easings, "in_quint", &rpeasings_methods[11]);
    add_function_to_dict(easings, "out_quint", &rpeasings_methods[12]);
    add_function_to_dict(easings, "in_out_quint", &rpeasings_methods[13]);
    add_function_to_dict(easings, "in_sine", &rpeasings_methods[14]);
    add_function_to_dict(easings, "out_sine", &rpeasings_methods[15]);
    add_function_to_dict(easings, "in_out_sine", &rpeasings_methods[16]);
    add_function_to_dict(easings, "in_expo", &rpeasings_methods[17]);
    add_function_to_dict(easings, "out_expo", &rpeasings_methods[18]);
    add_function_to_dict(easings, "in_out_expo", &rpeasings_methods[19]);
    add_function_to_dict(easings, "in_circ", &rpeasings_methods[20]);
    add_function_to_dict(easings, "out_circ", &rpeasings_methods[21]);
    add_function_to_dict(easings, "in_out_circ", &rpeasings_methods[22]);
    add_function_to_dict(easings, "in_back", &rpeasings_methods[23]);
    add_function_to_dict(easings, "out_back", &rpeasings_methods[24]);
    add_function_to_dict(easings, "in_out_back", &rpeasings_methods[25]);
    add_function_to_dict(easings, "in_elastic", &rpeasings_methods[26]);
    add_function_to_dict(easings, "out_elastic", &rpeasings_methods[27]);
    add_function_to_dict(easings, "in_out_elastic", &rpeasings_methods[28]);
    add_function_to_dict(easings, "in_bounce", &rpeasings_methods[29]);
    add_function_to_dict(easings, "out_bounce", &rpeasings_methods[30]);
    add_function_to_dict(easings, "in_out_bounce", &rpeasings_methods[31]);

    if (easings != NULL) {
        PyModule_AddObject(m, "easings", easings);
    }
    else {
        Py_CLEAR(easings);
    }

    return m;
}
