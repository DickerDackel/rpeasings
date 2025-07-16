#ifndef RPEASINGS_H
#define RPEASINGS_H
#ifdef __cplusplus
extern "C" {
#endif

#ifdef RPEASINGS_MODULE
/* easing implementations */

static double rpeasings_impl_null(double t);
static double rpeasings_impl_bounce_out(double t);
static double rpeasings_impl_in_quad(double t);
static double rpeasings_impl_out_quad(double t);
static double rpeasings_impl_in_out_quad(double t);
static double rpeasings_impl_in_cubic(double t);
static double rpeasings_impl_out_cubic(double t);
static double rpeasings_impl_in_out_cubic(double t);
static double rpeasings_impl_in_quart(double t);
static double rpeasings_impl_out_quart(double t);
static double rpeasings_impl_in_out_quart(double t);
static double rpeasings_impl_in_quint(double t);
static double rpeasings_impl_out_quint(double t);
static double rpeasings_impl_in_out_quint(double t);
static double rpeasings_impl_in_sine(double t);
static double rpeasings_impl_out_sine(double t);
static double rpeasings_impl_in_out_sine(double t);
static double rpeasings_impl_in_expo(double t);
static double rpeasings_impl_out_expo(double t);
static double rpeasings_impl_in_out_expo(double t);
static double rpeasings_impl_in_circ(double t);
static double rpeasings_impl_out_circ(double t);
static double rpeasings_impl_in_out_circ(double t);
static double rpeasings_impl_in_back(double t);
static double rpeasings_impl_out_back(double t);
static double rpeasings_impl_in_out_back(double t);
static double rpeasings_impl_in_elastic(double t);
static double rpeasings_impl_out_elastic(double t);
static double rpeasings_impl_in_out_elastic(double t);
static double rpeasings_impl_in_bounce(double t);
static double rpeasings_impl_out_bounce(double t);
static double rpeasings_impl_in_out_bounce(double t);

#else

static void **rpeasings_API;

#define (*(double (*)rpeasings_impl_null(double t)) rpeasings_API[0])
#define (*(double (*)rpeasings_impl_bounce_out(double t)) rpeasings_API[1])
#define (*(double (*)rpeasings_impl_in_quad(double t)) rpeasings_API[2])
#define (*(double (*)rpeasings_impl_out_quad(double t)) rpeasings_API[3])
#define (*(double (*)rpeasings_impl_in_out_quad(double t)) rpeasings_API[4])
#define (*(double (*)rpeasings_impl_in_cubic(double t)) rpeasings_API[5])
#define (*(double (*)rpeasings_impl_out_cubic(double t)) rpeasings_API[6])
#define (*(double (*)rpeasings_impl_in_out_cubic(double t)) rpeasings_API[7])
#define (*(double (*)rpeasings_impl_in_quart(double t)) rpeasings_API[8])
#define (*(double (*)rpeasings_impl_out_quart(double t)) rpeasings_API[9])
#define (*(double (*)rpeasings_impl_in_out_quart(double t)) rpeasings_API[10])
#define (*(double (*)rpeasings_impl_in_quint(double t)) rpeasings_API[11])
#define (*(double (*)rpeasings_impl_out_quint(double t)) rpeasings_API[12])
#define (*(double (*)rpeasings_impl_in_out_quint(double t)) rpeasings_API[13])
#define (*(double (*)rpeasings_impl_in_sine(double t)) rpeasings_API[14])
#define (*(double (*)rpeasings_impl_out_sine(double t)) rpeasings_API[15])
#define (*(double (*)rpeasings_impl_in_out_sine(double t)) rpeasings_API[16])
#define (*(double (*)rpeasings_impl_in_expo(double t)) rpeasings_API[17])
#define (*(double (*)rpeasings_impl_out_expo(double t)) rpeasings_API[18])
#define (*(double (*)rpeasings_impl_in_out_expo(double t)) rpeasings_API[19])
#define (*(double (*)rpeasings_impl_in_circ(double t)) rpeasings_API[20])
#define (*(double (*)rpeasings_impl_out_circ(double t)) rpeasings_API[21])
#define (*(double (*)rpeasings_impl_in_out_circ(double t)) rpeasings_API[22])
#define (*(double (*)rpeasings_impl_in_back(double t)) rpeasings_API[23])
#define (*(double (*)rpeasings_impl_out_back(double t)) rpeasings_API[24])
#define (*(double (*)rpeasings_impl_in_out_back(double t)) rpeasings_API[25])
#define (*(double (*)rpeasings_impl_in_elastic(double t)) rpeasings_API[26])
#define (*(double (*)rpeasings_impl_out_elastic(double t)) rpeasings_API[27])
#define (*(double (*)rpeasings_impl_in_out_elastic(double t)) rpeasings_API[28])
#define (*(double (*)rpeasings_impl_in_bounce(double t)) rpeasings_API[29])
#define (*(double (*)rpeasings_impl_out_bounce(double t)) rpeasings_API[30])
#define (*(double (*)rpeasings_impl_in_out_bounce(double t)) rpeasings_API[31])

static int import_rpeasings(void) {
    rpeasings_API = (void **)PyCapsule_Import("rpeasings._C_API", 0);
    return (rpeasings_API != NULL) ? 0 : -1;
}

#endif

#ifdef __cplusplus
}
#endif

#endif
