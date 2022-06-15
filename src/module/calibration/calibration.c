/*
 * File: calibration.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 13-Apr-2020 15:45:11
 */

/* Include Files */
#include "calibration.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void b_sqrt(double* x);
static void b_svd(const creal_T A[9], double U[3]);
static void b_xaxpy(int n, const creal_T a, const creal_T x[9], int ix0, creal_T y[3], int iy0);
static double b_xnrm2(int n, const double x[3]);
static void b_xzlartg(const creal_T f, const creal_T g, double* cs, creal_T* sn);
static void c_sqrt(creal_T* x);
static void c_xaxpy(int n, const creal_T a, const creal_T x[3], int ix0, creal_T y[9], int iy0);
static double c_xnrm2(int n, const creal_T x[9], int ix0);
static double d_xnrm2(int n, const creal_T x[3], int ix0);
static void mldivide(const double A[9], const double B[3], double Y[3]);
static double rt_hypotd_snf(double u0, double u1);
static void schur(const double A[9], creal_T V[9], creal_T T[9]);
static void svd(const creal_T A[9], creal_T U[9], double s[3], creal_T V[9]);
static void xaxpy(int n, const creal_T a, int ix0, creal_T y[9], int iy0);
static void xdlanv2(double* a, double* b, double* c, double* d, double* rt1r,
                    double* rt1i, double* rt2r, double* rt2i, double* cs, double* sn);
static creal_T xdotc(int n, const creal_T x[9], int ix0, const creal_T y[9], int iy0);
static void xgemv(int m, int n, const double A[9], int ia0, const double x[9],
                  int ix0, double y[3]);
static void xgerc(int m, int n, double alpha1, int ix0, const double y[3],
                  double A[9], int ia0);
static int xhseqr(double h[9], double z[9]);
static double xnrm2(int n, const double x[9], int ix0);
static void xrot(creal_T x[9], int ix0, int iy0, double c, double s);
static void xrotg(double* a, double* b, double* c, double* s);
static void xswap(creal_T x[9], int ix0, int iy0);
static void xzggev(creal_T A[9], int* info, creal_T alpha1[3], creal_T beta1[3],
                   creal_T V[9]);
static void xzhgeqz(creal_T A[9], int ilo, int ihi, creal_T Z[9], int* info,
                    creal_T alpha1[3], creal_T beta1[3]);
static double xzlanhs(const creal_T A[9], int ilo, int ihi);
static void xzlarf(int m, int n, int iv0, double tau, double C[9], int ic0,
                   double work[3]);
static double xzlarfg(int n, double* alpha1, double x[3]);
static void xzlartg(const creal_T f, const creal_T g, double* cs, creal_T* sn,
                    creal_T* r);
static void xztgevc(const creal_T A[9], creal_T V[9]);

/* Function Definitions */

/*
 * Arguments    : double *x
 * Return Type  : void
 */
static void b_sqrt(double* x)
{
    *x = sqrt(*x);
}

/*
 * Arguments    : const creal_T A[9]
 *                double U[3]
 * Return Type  : void
 */
static void b_svd(const creal_T A[9], double U[3])
{
    creal_T b_A[9];
    creal_T e[3];
    creal_T work[3];
    boolean_T apply_transform;
    double nrm;
    creal_T s[3];
    double rt;
    double sqds;
    int qp1;
    int qjj;
    creal_T b_e;
    double f;
    double brm;
    double z_im;
    double re;
    double sm;
    double scale;
    double e_re;
    int m;
    int iter;
    double snorm;
    int exitg1;
    int q;
    int qs;
    boolean_T exitg2;
    memcpy(&b_A[0], &A[0], 9U * sizeof(creal_T));
    e[0].re = 0.0;
    e[0].im = 0.0;
    work[0].re = 0.0;
    work[0].im = 0.0;
    e[1].re = 0.0;
    e[1].im = 0.0;
    work[1].re = 0.0;
    work[1].im = 0.0;
    e[2].re = 0.0;
    e[2].im = 0.0;
    work[2].re = 0.0;
    work[2].im = 0.0;
    apply_transform = false;
    nrm = c_xnrm2(3, b_A, 1);

    if (nrm > 0.0) {
        apply_transform = true;

        if ((b_A[0].re == 0.0) && (b_A[0].im == 0.0)) {
            sqds = 0.0;
            s[0].re = nrm;
            s[0].im = 0.0;
        } else {
            rt = nrm / rt_hypotd_snf(b_A[0].re, b_A[0].im);
            nrm = rt * b_A[0].re;
            sqds = rt * b_A[0].im;
            s[0].re = nrm;
            s[0].im = sqds;
        }

        if (rt_hypotd_snf(nrm, sqds) >= 1.0020841800044864E-292) {
            if (sqds == 0.0) {
                f = 1.0 / nrm;
                z_im = 0.0;
            } else if (nrm == 0.0) {
                f = 0.0;
                z_im = -(1.0 / sqds);
            } else {
                brm = fabs(nrm);
                sm = fabs(sqds);

                if (brm > sm) {
                    scale = sqds / nrm;
                    sqds = nrm + scale * sqds;
                    f = (1.0 + scale * 0.0) / sqds;
                    z_im = (0.0 - scale) / sqds;
                } else if (sm == brm) {
                    if (nrm > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (sqds > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    f = (scale + 0.0 * sqds) / brm;
                    z_im = (0.0 * scale - sqds) / brm;
                } else {
                    scale = nrm / sqds;
                    sqds += scale * nrm;
                    f = scale / sqds;
                    z_im = (scale * 0.0 - 1.0) / sqds;
                }
            }

            for (qp1 = 1; qp1 < 4; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;
                b_A[qp1 - 1].re = f * rt - z_im * nrm;
                b_A[qp1 - 1].im = f * nrm + z_im * rt;
            }
        } else {
            for (qp1 = 1; qp1 < 4; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;

                if (s[0].im == 0.0) {
                    if (nrm == 0.0) {
                        b_A[qp1 - 1].re = rt / s[0].re;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (rt == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = nrm / s[0].re;
                    } else {
                        b_A[qp1 - 1].re = rt / s[0].re;
                        b_A[qp1 - 1].im = nrm / s[0].re;
                    }
                } else if (s[0].re == 0.0) {
                    if (rt == 0.0) {
                        b_A[qp1 - 1].re = nrm / s[0].im;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (nrm == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = -(rt / s[0].im);
                    } else {
                        b_A[qp1 - 1].re = nrm / s[0].im;
                        b_A[qp1 - 1].im = -(rt / s[0].im);
                    }
                } else {
                    brm = fabs(s[0].re);
                    sm = fabs(s[0].im);

                    if (brm > sm) {
                        scale = s[0].im / s[0].re;
                        sqds = s[0].re + scale * s[0].im;
                        b_A[qp1 - 1].re = (rt + scale * nrm) / sqds;
                        b_A[qp1 - 1].im = (nrm - scale * rt) / sqds;
                    } else if (sm == brm) {
                        if (s[0].re > 0.0) {
                            scale = 0.5;
                        } else {
                            scale = -0.5;
                        }

                        if (s[0].im > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        b_A[qp1 - 1].re = (rt * scale + nrm * sqds) / brm;
                        b_A[qp1 - 1].im = (nrm * scale - rt * sqds) / brm;
                    } else {
                        scale = s[0].re / s[0].im;
                        sqds = s[0].im + scale * s[0].re;
                        b_A[qp1 - 1].re = (scale * rt + nrm) / sqds;
                        b_A[qp1 - 1].im = (scale * nrm - rt) / sqds;
                    }
                }
            }
        }

        b_A[0].re++;
        s[0].re = -s[0].re;
        s[0].im = -s[0].im;
    } else {
        s[0].re = 0.0;
        s[0].im = 0.0;
    }

    for (qp1 = 2; qp1 < 4; qp1++) {
        qjj = 3 * (qp1 - 1);

        if (apply_transform) {
            b_e = xdotc(3, b_A, 1, b_A, qjj + 1);

            if (b_A[0].im == 0.0) {
                if (b_e.im == 0.0) {
                    re = b_e.re / b_A[0].re;
                    sqds = 0.0;
                } else if (b_e.re == 0.0) {
                    re = 0.0;
                    sqds = b_e.im / b_A[0].re;
                } else {
                    re = b_e.re / b_A[0].re;
                    sqds = b_e.im / b_A[0].re;
                }
            } else if (b_A[0].re == 0.0) {
                if (b_e.re == 0.0) {
                    re = b_e.im / b_A[0].im;
                    sqds = 0.0;
                } else if (b_e.im == 0.0) {
                    re = 0.0;
                    sqds = -(b_e.re / b_A[0].im);
                } else {
                    re = b_e.im / b_A[0].im;
                    sqds = -(b_e.re / b_A[0].im);
                }
            } else {
                brm = fabs(b_A[0].re);
                sm = fabs(b_A[0].im);

                if (brm > sm) {
                    scale = b_A[0].im / b_A[0].re;
                    sqds = b_A[0].re + scale * b_A[0].im;
                    re = (b_e.re + scale * b_e.im) / sqds;
                    sqds = (b_e.im - scale * b_e.re) / sqds;
                } else if (sm == brm) {
                    if (b_A[0].re > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (b_A[0].im > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    re = (b_e.re * scale + b_e.im * sqds) / brm;
                    sqds = (b_e.im * scale - b_e.re * sqds) / brm;
                } else {
                    scale = b_A[0].re / b_A[0].im;
                    sqds = b_A[0].im + scale * b_A[0].re;
                    re = (scale * b_e.re + b_e.im) / sqds;
                    sqds = (scale * b_e.im - b_e.re) / sqds;
                }
            }

            b_e.re = -re;
            b_e.im = -sqds;
            xaxpy(3, b_e, 1, b_A, qjj + 1);
        }

        e[qp1 - 1].re = b_A[qjj].re;
        e[qp1 - 1].im = -b_A[qjj].im;
    }

    nrm = d_xnrm2(2, e, 2);

    if (nrm == 0.0) {
        e[0].re = 0.0;
        e[0].im = 0.0;
    } else {
        if ((e[1].re == 0.0) && (e[1].im == 0.0)) {
            e[0].re = nrm;
            e[0].im = 0.0;
        } else {
            rt = nrm / rt_hypotd_snf(e[1].re, e[1].im);
            e[0].re = rt * e[1].re;
            e[0].im = rt * e[1].im;
        }

        f = e[0].re;
        z_im = e[0].im;

        if (rt_hypotd_snf(e[0].re, e[0].im) >= 1.0020841800044864E-292) {
            if (e[0].im == 0.0) {
                f = 1.0 / e[0].re;
                z_im = 0.0;
            } else if (e[0].re == 0.0) {
                f = 0.0;
                z_im = -(1.0 / e[0].im);
            } else {
                brm = fabs(e[0].re);
                sm = fabs(e[0].im);

                if (brm > sm) {
                    scale = e[0].im / e[0].re;
                    sqds = e[0].re + scale * e[0].im;
                    f = (1.0 + scale * 0.0) / sqds;
                    z_im = (0.0 - scale) / sqds;
                } else if (sm == brm) {
                    if (e[0].re > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (e[0].im > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    f = (scale + 0.0 * sqds) / brm;
                    z_im = (0.0 * scale - sqds) / brm;
                } else {
                    scale = e[0].re / e[0].im;
                    sqds = e[0].im + scale * e[0].re;
                    f = scale / sqds;
                    z_im = (scale * 0.0 - 1.0) / sqds;
                }
            }

            for (qp1 = 2; qp1 < 4; qp1++) {
                e_re = e[qp1 - 1].re;
                re = e[qp1 - 1].im;
                e[qp1 - 1].re = f * e_re - z_im * re;
                e[qp1 - 1].im = f * re + z_im * e_re;
            }
        } else {
            for (qp1 = 2; qp1 < 4; qp1++) {
                e_re = e[qp1 - 1].re;
                re = e[qp1 - 1].im;

                if (z_im == 0.0) {
                    if (re == 0.0) {
                        e[qp1 - 1].re = e_re / f;
                        e[qp1 - 1].im = 0.0;
                    } else if (e_re == 0.0) {
                        e[qp1 - 1].re = 0.0;
                        e[qp1 - 1].im = re / f;
                    } else {
                        e[qp1 - 1].re = e_re / f;
                        e[qp1 - 1].im = re / f;
                    }
                } else if (f == 0.0) {
                    if (e_re == 0.0) {
                        e[qp1 - 1].re = re / z_im;
                        e[qp1 - 1].im = 0.0;
                    } else if (re == 0.0) {
                        e[qp1 - 1].re = 0.0;
                        e[qp1 - 1].im = -(e_re / z_im);
                    } else {
                        e[qp1 - 1].re = re / z_im;
                        e[qp1 - 1].im = -(e_re / z_im);
                    }
                } else {
                    brm = fabs(f);
                    sm = fabs(z_im);

                    if (brm > sm) {
                        scale = z_im / f;
                        sqds = f + scale * z_im;
                        e[qp1 - 1].re = (e_re + scale * re) / sqds;
                        e[qp1 - 1].im = (re - scale * e_re) / sqds;
                    } else if (sm == brm) {
                        if (f > 0.0) {
                            scale = 0.5;
                        } else {
                            scale = -0.5;
                        }

                        if (z_im > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        e[qp1 - 1].re = (e_re * scale + re * sqds) / brm;
                        e[qp1 - 1].im = (re * scale - e_re * sqds) / brm;
                    } else {
                        scale = f / z_im;
                        sqds = z_im + scale * f;
                        e[qp1 - 1].re = (scale * e_re + re) / sqds;
                        e[qp1 - 1].im = (scale * re - e_re) / sqds;
                    }
                }
            }
        }

        e[1].re++;
        e[0].re = -e[0].re;

        for (qjj = 2; qjj < 4; qjj++) {
            work[qjj - 1].re = 0.0;
            work[qjj - 1].im = 0.0;
        }

        for (qp1 = 2; qp1 < 4; qp1++) {
            b_xaxpy(2, e[qp1 - 1], b_A, 3 * (qp1 - 1) + 2, work, 2);
        }

        for (qp1 = 2; qp1 < 4; qp1++) {
            rt = -e[qp1 - 1].re;
            nrm = -e[qp1 - 1].im;

            if (e[1].im == 0.0) {
                if (nrm == 0.0) {
                    e_re = rt / e[1].re;
                    re = 0.0;
                } else if (rt == 0.0) {
                    e_re = 0.0;
                    re = nrm / e[1].re;
                } else {
                    e_re = rt / e[1].re;
                    re = nrm / e[1].re;
                }
            } else if (e[1].re == 0.0) {
                if (rt == 0.0) {
                    e_re = nrm / e[1].im;
                    re = 0.0;
                } else if (nrm == 0.0) {
                    e_re = 0.0;
                    re = -(rt / e[1].im);
                } else {
                    e_re = nrm / e[1].im;
                    re = -(rt / e[1].im);
                }
            } else {
                brm = fabs(e[1].re);
                sm = fabs(e[1].im);

                if (brm > sm) {
                    scale = e[1].im / e[1].re;
                    sqds = e[1].re + scale * e[1].im;
                    e_re = (rt + scale * nrm) / sqds;
                    re = (nrm - scale * rt) / sqds;
                } else if (sm == brm) {
                    if (e[1].re > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (e[1].im > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    e_re = (rt * scale + nrm * sqds) / brm;
                    re = (nrm * scale - rt * sqds) / brm;
                } else {
                    scale = e[1].re / e[1].im;
                    sqds = e[1].im + scale * e[1].re;
                    e_re = (scale * rt + nrm) / sqds;
                    re = (scale * nrm - rt) / sqds;
                }
            }

            b_e.re = e_re;
            b_e.im = -re;
            c_xaxpy(2, b_e, work, 2, b_A, 3 * (qp1 - 1) + 2);
        }
    }

    apply_transform = false;
    nrm = c_xnrm2(2, b_A, 5);

    if (nrm > 0.0) {
        apply_transform = true;

        if ((b_A[4].re == 0.0) && (b_A[4].im == 0.0)) {
            sqds = 0.0;
            s[1].re = nrm;
            s[1].im = 0.0;
        } else {
            rt = nrm / rt_hypotd_snf(b_A[4].re, b_A[4].im);
            nrm = rt * b_A[4].re;
            sqds = rt * b_A[4].im;
            s[1].re = nrm;
            s[1].im = sqds;
        }

        if (rt_hypotd_snf(nrm, sqds) >= 1.0020841800044864E-292) {
            if (sqds == 0.0) {
                f = 1.0 / nrm;
                z_im = 0.0;
            } else if (nrm == 0.0) {
                f = 0.0;
                z_im = -(1.0 / sqds);
            } else {
                brm = fabs(nrm);
                sm = fabs(sqds);

                if (brm > sm) {
                    scale = sqds / nrm;
                    sqds = nrm + scale * sqds;
                    f = (1.0 + scale * 0.0) / sqds;
                    z_im = (0.0 - scale) / sqds;
                } else if (sm == brm) {
                    if (nrm > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (sqds > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    f = (scale + 0.0 * sqds) / brm;
                    z_im = (0.0 * scale - sqds) / brm;
                } else {
                    scale = nrm / sqds;
                    sqds += scale * nrm;
                    f = scale / sqds;
                    z_im = (scale * 0.0 - 1.0) / sqds;
                }
            }

            for (qp1 = 5; qp1 < 7; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;
                b_A[qp1 - 1].re = f * rt - z_im * nrm;
                b_A[qp1 - 1].im = f * nrm + z_im * rt;
            }
        } else {
            for (qp1 = 5; qp1 < 7; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;

                if (s[1].im == 0.0) {
                    if (nrm == 0.0) {
                        b_A[qp1 - 1].re = rt / s[1].re;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (rt == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = nrm / s[1].re;
                    } else {
                        b_A[qp1 - 1].re = rt / s[1].re;
                        b_A[qp1 - 1].im = nrm / s[1].re;
                    }
                } else if (s[1].re == 0.0) {
                    if (rt == 0.0) {
                        b_A[qp1 - 1].re = nrm / s[1].im;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (nrm == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = -(rt / s[1].im);
                    } else {
                        b_A[qp1 - 1].re = nrm / s[1].im;
                        b_A[qp1 - 1].im = -(rt / s[1].im);
                    }
                } else {
                    brm = fabs(s[1].re);
                    sm = fabs(s[1].im);

                    if (brm > sm) {
                        scale = s[1].im / s[1].re;
                        sqds = s[1].re + scale * s[1].im;
                        b_A[qp1 - 1].re = (rt + scale * nrm) / sqds;
                        b_A[qp1 - 1].im = (nrm - scale * rt) / sqds;
                    } else if (sm == brm) {
                        if (s[1].re > 0.0) {
                            scale = 0.5;
                        } else {
                            scale = -0.5;
                        }

                        if (s[1].im > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        b_A[qp1 - 1].re = (rt * scale + nrm * sqds) / brm;
                        b_A[qp1 - 1].im = (nrm * scale - rt * sqds) / brm;
                    } else {
                        scale = s[1].re / s[1].im;
                        sqds = s[1].im + scale * s[1].re;
                        b_A[qp1 - 1].re = (scale * rt + nrm) / sqds;
                        b_A[qp1 - 1].im = (scale * nrm - rt) / sqds;
                    }
                }
            }
        }

        b_A[4].re++;
        s[1].re = -s[1].re;
        s[1].im = -s[1].im;
    } else {
        s[1].re = 0.0;
        s[1].im = 0.0;
    }

    for (qp1 = 3; qp1 < 4; qp1++) {
        if (apply_transform) {
            b_e = xdotc(2, b_A, 5, b_A, 8);

            if (b_A[4].im == 0.0) {
                if (b_e.im == 0.0) {
                    re = b_e.re / b_A[4].re;
                    sqds = 0.0;
                } else if (b_e.re == 0.0) {
                    re = 0.0;
                    sqds = b_e.im / b_A[4].re;
                } else {
                    re = b_e.re / b_A[4].re;
                    sqds = b_e.im / b_A[4].re;
                }
            } else if (b_A[4].re == 0.0) {
                if (b_e.re == 0.0) {
                    re = b_e.im / b_A[4].im;
                    sqds = 0.0;
                } else if (b_e.im == 0.0) {
                    re = 0.0;
                    sqds = -(b_e.re / b_A[4].im);
                } else {
                    re = b_e.im / b_A[4].im;
                    sqds = -(b_e.re / b_A[4].im);
                }
            } else {
                brm = fabs(b_A[4].re);
                sm = fabs(b_A[4].im);

                if (brm > sm) {
                    scale = b_A[4].im / b_A[4].re;
                    sqds = b_A[4].re + scale * b_A[4].im;
                    re = (b_e.re + scale * b_e.im) / sqds;
                    sqds = (b_e.im - scale * b_e.re) / sqds;
                } else if (sm == brm) {
                    if (b_A[4].re > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (b_A[4].im > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    re = (b_e.re * scale + b_e.im * sqds) / brm;
                    sqds = (b_e.im * scale - b_e.re * sqds) / brm;
                } else {
                    scale = b_A[4].re / b_A[4].im;
                    sqds = b_A[4].im + scale * b_A[4].re;
                    re = (scale * b_e.re + b_e.im) / sqds;
                    sqds = (scale * b_e.im - b_e.re) / sqds;
                }
            }

            b_e.re = -re;
            b_e.im = -sqds;
            xaxpy(2, b_e, 5, b_A, 8);
        }
    }

    m = 1;
    s[2] = b_A[8];
    e[1] = b_A[7];
    e[2].re = 0.0;
    e[2].im = 0.0;
    iter = 0;
    snorm = 0.0;
    re = s[0].re;

    if ((s[0].re != 0.0) || (s[0].im != 0.0)) {
        rt = rt_hypotd_snf(s[0].re, s[0].im);
        f = s[0].re;
        z_im = s[0].im;
        re = rt;
        s[0].re = rt;
        s[0].im = 0.0;

        if (z_im == 0.0) {
            f /= rt;
            z_im = 0.0;
        } else if (f == 0.0) {
            f = 0.0;
            z_im /= rt;
        } else {
            f /= rt;
            z_im /= rt;
        }

        e_re = e[0].re;

        if (z_im == 0.0) {
            if (e[0].im == 0.0) {
                e[0].re /= f;
                e[0].im = 0.0;
            } else if (e[0].re == 0.0) {
                e[0].re = 0.0;
                e[0].im /= f;
            } else {
                e[0].re /= f;
                e[0].im /= f;
            }
        } else if (f == 0.0) {
            if (e[0].re == 0.0) {
                e[0].re = e[0].im / z_im;
                e[0].im = 0.0;
            } else if (e[0].im == 0.0) {
                e[0].re = 0.0;
                e[0].im = -(e_re / z_im);
            } else {
                e[0].re = e[0].im / z_im;
                e[0].im = -(e_re / z_im);
            }
        } else {
            brm = fabs(f);
            sm = fabs(z_im);

            if (brm > sm) {
                scale = z_im / f;
                sqds = f + scale * z_im;
                e[0].re = (e[0].re + scale * e[0].im) / sqds;
                e[0].im = (e[0].im - scale * e_re) / sqds;
            } else if (sm == brm) {
                if (f > 0.0) {
                    scale = 0.5;
                } else {
                    scale = -0.5;
                }

                if (z_im > 0.0) {
                    sqds = 0.5;
                } else {
                    sqds = -0.5;
                }

                e[0].re = (e[0].re * scale + e[0].im * sqds) / brm;
                e[0].im = (e[0].im * scale - e_re * sqds) / brm;
            } else {
                scale = f / z_im;
                sqds = z_im + scale * f;
                e[0].re = (scale * e[0].re + e[0].im) / sqds;
                e[0].im = (scale * e[0].im - e_re) / sqds;
            }
        }
    }

    if ((e[0].re != 0.0) || (e[0].im != 0.0)) {
        rt = rt_hypotd_snf(e[0].re, e[0].im);
        f = e[0].re;
        z_im = e[0].im;
        e[0].re = rt;
        e[0].im = 0.0;

        if (z_im == 0.0) {
            sm = rt / f;
            rt = 0.0;
        } else if (f == 0.0) {
            if (rt == 0.0) {
                sm = 0.0 / z_im;
                rt = 0.0;
            } else {
                sm = 0.0;
                rt = -(rt / z_im);
            }
        } else {
            brm = fabs(f);
            sm = fabs(z_im);

            if (brm > sm) {
                scale = z_im / f;
                sqds = f + scale * z_im;
                sm = (rt + scale * 0.0) / sqds;
                rt = (0.0 - scale * rt) / sqds;
            } else if (sm == brm) {
                if (f > 0.0) {
                    scale = 0.5;
                } else {
                    scale = -0.5;
                }

                if (z_im > 0.0) {
                    sqds = 0.5;
                } else {
                    sqds = -0.5;
                }

                sm = (rt * scale + 0.0 * sqds) / brm;
                rt = (0.0 * scale - rt * sqds) / brm;
            } else {
                scale = f / z_im;
                sqds = z_im + scale * f;
                sm = scale * rt / sqds;
                rt = (scale * 0.0 - rt) / sqds;
            }
        }

        nrm = s[1].re;
        s[1].re = s[1].re * sm - s[1].im * rt;
        s[1].im = nrm * rt + s[1].im * sm;
    }

    rt = fabs(re);
    nrm = fabs(e[0].re);

    if ((rt > nrm) || rtIsNaN_(nrm)) {
        nrm = rt;
    }

    if (!rtIsNaN_(nrm)) {
        snorm = nrm;
    }

    re = s[1].re;

    if ((s[1].re != 0.0) || (s[1].im != 0.0)) {
        rt = rt_hypotd_snf(s[1].re, s[1].im);
        f = s[1].re;
        z_im = s[1].im;
        re = rt;
        s[1].re = rt;
        s[1].im = 0.0;

        if (z_im == 0.0) {
            f /= rt;
            z_im = 0.0;
        } else if (f == 0.0) {
            f = 0.0;
            z_im /= rt;
        } else {
            f /= rt;
            z_im /= rt;
        }

        if (z_im == 0.0) {
            if (b_A[7].im == 0.0) {
                e[1].re = b_A[7].re / f;
                e[1].im = 0.0;
            } else if (b_A[7].re == 0.0) {
                e[1].re = 0.0;
                e[1].im = b_A[7].im / f;
            } else {
                e[1].re = b_A[7].re / f;
                e[1].im = b_A[7].im / f;
            }
        } else if (f == 0.0) {
            if (b_A[7].re == 0.0) {
                e[1].re = b_A[7].im / z_im;
                e[1].im = 0.0;
            } else if (b_A[7].im == 0.0) {
                e[1].re = 0.0;
                e[1].im = -(b_A[7].re / z_im);
            } else {
                e[1].re = b_A[7].im / z_im;
                e[1].im = -(b_A[7].re / z_im);
            }
        } else {
            brm = fabs(f);
            sm = fabs(z_im);

            if (brm > sm) {
                scale = z_im / f;
                sqds = f + scale * z_im;
                e[1].re = (b_A[7].re + scale * b_A[7].im) / sqds;
                e[1].im = (b_A[7].im - scale * b_A[7].re) / sqds;
            } else if (sm == brm) {
                if (f > 0.0) {
                    scale = 0.5;
                } else {
                    scale = -0.5;
                }

                if (z_im > 0.0) {
                    sqds = 0.5;
                } else {
                    sqds = -0.5;
                }

                e[1].re = (b_A[7].re * scale + b_A[7].im * sqds) / brm;
                e[1].im = (b_A[7].im * scale - b_A[7].re * sqds) / brm;
            } else {
                scale = f / z_im;
                sqds = z_im + scale * f;
                e[1].re = (scale * b_A[7].re + b_A[7].im) / sqds;
                e[1].im = (scale * b_A[7].im - b_A[7].re) / sqds;
            }
        }
    }

    if ((e[1].re != 0.0) || (e[1].im != 0.0)) {
        rt = rt_hypotd_snf(e[1].re, e[1].im);
        f = e[1].re;
        z_im = e[1].im;
        e[1].re = rt;
        e[1].im = 0.0;

        if (z_im == 0.0) {
            sm = rt / f;
            rt = 0.0;
        } else if (f == 0.0) {
            if (rt == 0.0) {
                sm = 0.0 / z_im;
                rt = 0.0;
            } else {
                sm = 0.0;
                rt = -(rt / z_im);
            }
        } else {
            brm = fabs(f);
            sm = fabs(z_im);

            if (brm > sm) {
                scale = z_im / f;
                sqds = f + scale * z_im;
                sm = (rt + scale * 0.0) / sqds;
                rt = (0.0 - scale * rt) / sqds;
            } else if (sm == brm) {
                if (f > 0.0) {
                    scale = 0.5;
                } else {
                    scale = -0.5;
                }

                if (z_im > 0.0) {
                    sqds = 0.5;
                } else {
                    sqds = -0.5;
                }

                sm = (rt * scale + 0.0 * sqds) / brm;
                rt = (0.0 * scale - rt * sqds) / brm;
            } else {
                scale = f / z_im;
                sqds = z_im + scale * f;
                sm = scale * rt / sqds;
                rt = (scale * 0.0 - rt) / sqds;
            }
        }

        s[2].re = b_A[8].re * sm - b_A[8].im * rt;
        s[2].im = b_A[8].re * rt + b_A[8].im * sm;
    }

    rt = fabs(re);
    nrm = fabs(e[1].re);

    if ((rt > nrm) || rtIsNaN_(nrm)) {
        nrm = rt;
    }

    if ((!(snorm > nrm)) && (!rtIsNaN_(nrm))) {
        snorm = nrm;
    }

    re = s[2].re;

    if ((s[2].re != 0.0) || (s[2].im != 0.0)) {
        rt = rt_hypotd_snf(s[2].re, s[2].im);
        re = rt;
        s[2].re = rt;
        s[2].im = 0.0;
    }

    rt = fabs(re);

    if (rt > 0.0) {
        nrm = rt;
    } else {
        nrm = 0.0;
    }

    if ((!(snorm > nrm)) && (!rtIsNaN_(nrm))) {
        snorm = nrm;
    }

    while ((m + 2 > 0) && (iter < 75)) {
        qjj = m;

        do {
            exitg1 = 0;
            q = qjj + 1;

            if (qjj + 1 == 0) {
                exitg1 = 1;
            } else {
                rt = fabs(e[qjj].re);

                if ((rt <= 2.2204460492503131E-16 * (fabs(s[qjj].re) + fabs(s[qjj + 1].re))) || (rt <= 1.0020841800044864E-292) || ((iter > 20) && (rt <= 2.2204460492503131E-16 * snorm))) {
                    e[qjj].re = 0.0;
                    e[qjj].im = 0.0;
                    exitg1 = 1;
                } else {
                    qjj--;
                }
            }
        } while (exitg1 == 0);

        if (qjj + 1 == m + 1) {
            qjj = 4;
        } else {
            qs = m + 2;
            qp1 = m + 2;
            exitg2 = false;

            while ((!exitg2) && (qp1 >= qjj + 1)) {
                qs = qp1;

                if (qp1 == qjj + 1) {
                    exitg2 = true;
                } else {
                    rt = 0.0;

                    if (qp1 < m + 2) {
                        rt = fabs(e[qp1 - 1].re);
                    }

                    if (qp1 > qjj + 2) {
                        rt += fabs(e[qp1 - 2].re);
                    }

                    nrm = fabs(s[qp1 - 1].re);

                    if ((nrm <= 2.2204460492503131E-16 * rt) || (nrm <= 1.0020841800044864E-292)) {
                        s[qp1 - 1].re = 0.0;
                        s[qp1 - 1].im = 0.0;
                        exitg2 = true;
                    } else {
                        qp1--;
                    }
                }
            }

            if (qs == qjj + 1) {
                qjj = 3;
            } else if (qs == m + 2) {
                qjj = 1;
            } else {
                qjj = 2;
                q = qs;
            }
        }

        switch (qjj) {
        case 1:
            f = e[m].re;
            e[m].re = 0.0;
            e[m].im = 0.0;
            qjj = m + 1;
            e_re = e[0].re;
            re = e[0].im;

            for (qp1 = qjj; qp1 >= q + 1; qp1--) {
                rt = s[qp1 - 1].re;
                xrotg(&rt, &f, &nrm, &sm);
                s[qp1 - 1].re = rt;
                s[qp1 - 1].im = 0.0;

                if (qp1 > q + 1) {
                    f = -sm * e_re;
                    e_re *= nrm;
                    re *= nrm;
                }

                e[0].re = e_re;
                e[0].im = re;
            }

            break;

        case 2:
            f = e[q - 1].re;
            e[q - 1].re = 0.0;
            e[q - 1].im = 0.0;

            for (qp1 = q + 1; qp1 <= m + 2; qp1++) {
                rt = s[qp1 - 1].re;
                xrotg(&rt, &f, &re, &sm);
                s[qp1 - 1].re = rt;
                s[qp1 - 1].im = 0.0;
                f = -sm * e[qp1 - 1].re;
                e[qp1 - 1].re *= re;
                e[qp1 - 1].im *= re;
            }

            break;

        case 3:
            qjj = m + 1;
            scale = fabs(s[m + 1].re);
            nrm = fabs(s[m].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            nrm = fabs(e[m].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            nrm = fabs(s[q].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            nrm = fabs(e[q].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            sm = s[m + 1].re / scale;
            rt = s[m].re / scale;
            nrm = e[m].re / scale;
            sqds = s[q].re / scale;
            re = ((rt + sm) * (rt - sm) + nrm * nrm) / 2.0;
            rt = sm * nrm;
            rt *= rt;

            if ((re != 0.0) || (rt != 0.0)) {
                nrm = sqrt(re * re + rt);

                if (re < 0.0) {
                    nrm = -nrm;
                }

                nrm = rt / (re + nrm);
            } else {
                nrm = 0.0;
            }

            f = (sqds + sm) * (sqds - sm) + nrm;
            rt = sqds * (e[q].re / scale);

            for (qp1 = q + 1; qp1 <= qjj; qp1++) {
                xrotg(&f, &rt, &nrm, &sm);

                if (qp1 > q + 1) {
                    e[0].re = f;
                    e[0].im = 0.0;
                }

                f = nrm * s[qp1 - 1].re + sm * e[qp1 - 1].re;
                e[qp1 - 1].re = nrm * e[qp1 - 1].re - sm * s[qp1 - 1].re;
                e[qp1 - 1].im = nrm * e[qp1 - 1].im - sm * s[qp1 - 1].im;
                rt = sm * s[qp1].re;
                re = nrm * s[qp1].re;
                sqds = nrm * s[qp1].im;
                xrotg(&f, &rt, &nrm, &sm);
                s[qp1 - 1].re = f;
                s[qp1 - 1].im = 0.0;
                f = nrm * e[qp1 - 1].re + sm * re;
                re = -sm * e[qp1 - 1].re + nrm * re;
                sqds = -sm * e[qp1 - 1].im + nrm * sqds;
                s[qp1].re = re;
                s[qp1].im = sqds;
                rt = sm * e[qp1].re;
                e[qp1].re *= nrm;
                e[qp1].im *= nrm;
            }

            e[m].re = f;
            e[m].im = 0.0;
            iter++;
            break;

        default:
            if (s[q].re < 0.0) {
                s[q].re = -s[q].re;
                s[q].im = 0.0;
            }

            qp1 = q + 1;

            while ((q + 1 < 3) && (s[q].re < s[qp1].re)) {
                rt = s[q].re;
                s[q].re = s[qp1].re;
                s[q].im = 0.0;
                s[qp1].re = rt;
                s[qp1].im = 0.0;
                q = qp1;
                qp1++;
            }

            iter = 0;
            m--;
            break;
        }
    }

    U[0] = s[0].re;
    U[1] = s[1].re;
    U[2] = s[2].re;
}

/*
 * Arguments    : int n
 *                const creal_T a
 *                const creal_T x[9]
 *                int ix0
 *                creal_T y[3]
 *                int iy0
 * Return Type  : void
 */
static void b_xaxpy(int n, const creal_T a, const creal_T x[9], int ix0, creal_T y[3], int iy0)
{
    int ix;
    int iy;
    int i15;
    int k;

    if ((n < 1) || ((a.re == 0.0) && (a.im == 0.0))) {
    } else {
        ix = ix0 - 1;
        iy = iy0 - 1;
        i15 = n - 1;

        for (k = 0; k <= i15; k++) {
            y[iy].re += a.re * x[ix].re - a.im * x[ix].im;
            y[iy].im += a.re * x[ix].im + a.im * x[ix].re;
            ix++;
            iy++;
        }
    }
}

/*
 * Arguments    : int n
 *                const double x[3]
 * Return Type  : double
 */
static double b_xnrm2(int n, const double x[3])
{
    double y;
    double scale;
    int kend;
    int k;
    double absxk;
    double t;
    y = 0.0;

    if (n >= 1) {
        if (n == 1) {
            y = fabs(x[1]);
        } else {
            scale = 3.3121686421112381E-170;
            kend = n + 1;

            for (k = 2; k <= kend; k++) {
                absxk = fabs(x[k - 1]);

                if (absxk > scale) {
                    t = scale / absxk;
                    y = 1.0 + y * t * t;
                    scale = absxk;
                } else {
                    t = absxk / scale;
                    y += t * t;
                }
            }

            y = scale * sqrt(y);
        }
    }

    return y;
}

/*
 * Arguments    : const creal_T f
 *                const creal_T g
 *                double *cs
 *                creal_T *sn
 * Return Type  : void
 */
static void b_xzlartg(const creal_T f, const creal_T g, double* cs, creal_T* sn)
{
    double y_tmp;
    double scale;
    double b_y_tmp;
    double f2s;
    double f2;
    double fs_re;
    double fs_im;
    double gs_re;
    double gs_im;
    boolean_T guard1 = false;
    double g2s;
    y_tmp = fabs(f.re);
    scale = y_tmp;
    b_y_tmp = fabs(f.im);

    if (b_y_tmp > y_tmp) {
        scale = b_y_tmp;
    }

    f2s = fabs(g.re);
    f2 = fabs(g.im);

    if (f2 > f2s) {
        f2s = f2;
    }

    if (f2s > scale) {
        scale = f2s;
    }

    fs_re = f.re;
    fs_im = f.im;
    gs_re = g.re;
    gs_im = g.im;
    guard1 = false;

    if (scale >= 7.4428285367870146E+137) {
        do {
            fs_re *= 1.3435752215134178E-138;
            fs_im *= 1.3435752215134178E-138;
            gs_re *= 1.3435752215134178E-138;
            gs_im *= 1.3435752215134178E-138;
            scale *= 1.3435752215134178E-138;
        } while (!(scale < 7.4428285367870146E+137));

        guard1 = true;
    } else if (scale <= 1.3435752215134178E-138) {
        if ((g.re == 0.0) && (g.im == 0.0)) {
            *cs = 1.0;
            sn->re = 0.0;
            sn->im = 0.0;
        } else {
            do {
                fs_re *= 7.4428285367870146E+137;
                fs_im *= 7.4428285367870146E+137;
                gs_re *= 7.4428285367870146E+137;
                gs_im *= 7.4428285367870146E+137;
                scale *= 7.4428285367870146E+137;
            } while (!(scale > 1.3435752215134178E-138));

            guard1 = true;
        }
    } else {
        guard1 = true;
    }

    if (guard1) {
        f2 = fs_re * fs_re + fs_im * fs_im;
        scale = gs_re * gs_re + gs_im * gs_im;
        f2s = scale;

        if (1.0 > scale) {
            f2s = 1.0;
        }

        if (f2 <= f2s * 2.0041683600089728E-292) {
            if ((f.re == 0.0) && (f.im == 0.0)) {
                *cs = 0.0;
                scale = rt_hypotd_snf(gs_re, gs_im);
                sn->re = gs_re / scale;
                sn->im = -gs_im / scale;
            } else {
                g2s = sqrt(scale);
                *cs = rt_hypotd_snf(fs_re, fs_im) / g2s;

                if (b_y_tmp > y_tmp) {
                    y_tmp = b_y_tmp;
                }

                if (y_tmp > 1.0) {
                    scale = rt_hypotd_snf(f.re, f.im);
                    fs_re = f.re / scale;
                    fs_im = f.im / scale;
                } else {
                    f2 = 7.4428285367870146E+137 * f.re;
                    f2s = 7.4428285367870146E+137 * f.im;
                    scale = rt_hypotd_snf(f2, f2s);
                    fs_re = f2 / scale;
                    fs_im = f2s / scale;
                }

                gs_re /= g2s;
                gs_im = -gs_im / g2s;
                sn->re = fs_re * gs_re - fs_im * gs_im;
                sn->im = fs_re * gs_im + fs_im * gs_re;
            }
        } else {
            f2s = sqrt(1.0 + scale / f2);
            fs_re *= f2s;
            fs_im *= f2s;
            *cs = 1.0 / f2s;
            scale += f2;
            fs_re /= scale;
            fs_im /= scale;
            sn->re = fs_re * gs_re - fs_im * -gs_im;
            sn->im = fs_re * -gs_im + fs_im * gs_re;
        }
    }
}

/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
static void c_sqrt(creal_T* x)
{
    double xr;
    double xi;
    double yr;
    double absxr;
    xr = x->re;
    xi = x->im;

    if (xi == 0.0) {
        if (xr < 0.0) {
            yr = 0.0;
            xr = sqrt(-xr);
        } else {
            yr = sqrt(xr);
            xr = 0.0;
        }
    } else if (xr == 0.0) {
        if (xi < 0.0) {
            yr = sqrt(-xi / 2.0);
            xr = -yr;
        } else {
            yr = sqrt(xi / 2.0);
            xr = yr;
        }
    } else if (rtIsNaN_(xr)) {
        yr = xr;
    } else if (rtIsNaN_(xi)) {
        yr = xi;
        xr = xi;
    } else if (rtIsInf_(xi)) {
        yr = fabs(xi);
        xr = xi;
    } else if (rtIsInf_(xr)) {
        if (xr < 0.0) {
            yr = 0.0;
            xr = xi * -xr;
        } else {
            yr = xr;
            xr = 0.0;
        }
    } else {
        absxr = fabs(xr);
        yr = fabs(xi);

        if ((absxr > 4.4942328371557893E+307) || (yr > 4.4942328371557893E+307)) {
            absxr *= 0.5;
            yr = rt_hypotd_snf(absxr, yr * 0.5);

            if (yr > absxr) {
                yr = sqrt(yr) * sqrt(1.0 + absxr / yr);
            } else {
                yr = sqrt(yr) * 1.4142135623730951;
            }
        } else {
            yr = sqrt((rt_hypotd_snf(absxr, yr) + absxr) * 0.5);
        }

        if (xr > 0.0) {
            xr = 0.5 * (xi / yr);
        } else {
            if (xi < 0.0) {
                xr = -yr;
            } else {
                xr = yr;
            }

            yr = 0.5 * (xi / xr);
        }
    }

    x->re = yr;
    x->im = xr;
}

/*
 * Arguments    : int n
 *                const creal_T a
 *                const creal_T x[3]
 *                int ix0
 *                creal_T y[9]
 *                int iy0
 * Return Type  : void
 */
static void c_xaxpy(int n, const creal_T a, const creal_T x[3], int ix0, creal_T y[9], int iy0)
{
    int ix;
    int iy;
    int i16;
    int k;

    if ((n < 1) || ((a.re == 0.0) && (a.im == 0.0))) {
    } else {
        ix = ix0 - 1;
        iy = iy0 - 1;
        i16 = n - 1;

        for (k = 0; k <= i16; k++) {
            y[iy].re += a.re * x[ix].re - a.im * x[ix].im;
            y[iy].im += a.re * x[ix].im + a.im * x[ix].re;
            ix++;
            iy++;
        }
    }
}

/*
 * Arguments    : int n
 *                const creal_T x[9]
 *                int ix0
 * Return Type  : double
 */
static double c_xnrm2(int n, const creal_T x[9], int ix0)
{
    double y;
    double scale;
    int kend;
    int k;
    double absxk;
    double t;
    y = 0.0;

    if (n >= 1) {
        if (n == 1) {
            y = rt_hypotd_snf(x[ix0 - 1].re, x[ix0 - 1].im);
        } else {
            scale = 3.3121686421112381E-170;
            kend = (ix0 + n) - 1;

            for (k = ix0; k <= kend; k++) {
                absxk = fabs(x[k - 1].re);

                if (absxk > scale) {
                    t = scale / absxk;
                    y = 1.0 + y * t * t;
                    scale = absxk;
                } else {
                    t = absxk / scale;
                    y += t * t;
                }

                absxk = fabs(x[k - 1].im);

                if (absxk > scale) {
                    t = scale / absxk;
                    y = 1.0 + y * t * t;
                    scale = absxk;
                } else {
                    t = absxk / scale;
                    y += t * t;
                }
            }

            y = scale * sqrt(y);
        }
    }

    return y;
}

/*
 * Arguments    : int n
 *                const creal_T x[3]
 *                int ix0
 * Return Type  : double
 */
static double d_xnrm2(int n, const creal_T x[3], int ix0)
{
    double y;
    double scale;
    int kend;
    int k;
    double absxk;
    double t;
    y = 0.0;

    if (n >= 1) {
        if (n == 1) {
            y = rt_hypotd_snf(x[ix0 - 1].re, x[ix0 - 1].im);
        } else {
            scale = 3.3121686421112381E-170;
            kend = (ix0 + n) - 1;

            for (k = ix0; k <= kend; k++) {
                absxk = fabs(x[k - 1].re);

                if (absxk > scale) {
                    t = scale / absxk;
                    y = 1.0 + y * t * t;
                    scale = absxk;
                } else {
                    t = absxk / scale;
                    y += t * t;
                }

                absxk = fabs(x[k - 1].im);

                if (absxk > scale) {
                    t = scale / absxk;
                    y = 1.0 + y * t * t;
                    scale = absxk;
                } else {
                    t = absxk / scale;
                    y += t * t;
                }
            }

            y = scale * sqrt(y);
        }
    }

    return y;
}

/*
 * Arguments    : const double A[9]
 *                const double B[3]
 *                double Y[3]
 * Return Type  : void
 */
static void mldivide(const double A[9], const double B[3], double Y[3])
{
    double b_A[9];
    int r1;
    int r2;
    int r3;
    double maxval;
    double a21;
    int rtemp;
    memcpy(&b_A[0], &A[0], 9U * sizeof(double));
    r1 = 0;
    r2 = 1;
    r3 = 2;
    maxval = fabs(A[0]);
    a21 = fabs(A[1]);

    if (a21 > maxval) {
        maxval = a21;
        r1 = 1;
        r2 = 0;
    }

    if (fabs(A[2]) > maxval) {
        r1 = 2;
        r2 = 1;
        r3 = 0;
    }

    b_A[r2] = A[r2] / A[r1];
    b_A[r3] /= b_A[r1];
    b_A[3 + r2] -= b_A[r2] * b_A[3 + r1];
    b_A[3 + r3] -= b_A[r3] * b_A[3 + r1];
    b_A[6 + r2] -= b_A[r2] * b_A[6 + r1];
    b_A[6 + r3] -= b_A[r3] * b_A[6 + r1];

    if (fabs(b_A[3 + r3]) > fabs(b_A[3 + r2])) {
        rtemp = r2;
        r2 = r3;
        r3 = rtemp;
    }

    b_A[3 + r3] /= b_A[3 + r2];
    b_A[6 + r3] -= b_A[3 + r3] * b_A[6 + r2];
    Y[1] = B[r2] - B[r1] * b_A[r2];
    Y[2] = (B[r3] - B[r1] * b_A[r3]) - Y[1] * b_A[3 + r3];
    Y[2] /= b_A[6 + r3];
    Y[0] = B[r1] - Y[2] * b_A[6 + r1];
    Y[1] -= Y[2] * b_A[6 + r2];
    Y[1] /= b_A[3 + r2];
    Y[0] -= Y[1] * b_A[3 + r1];
    Y[0] /= b_A[r1];
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
    double y;
    double a;
    double b;
    a = fabs(u0);
    b = fabs(u1);

    if (a < b) {
        a /= b;
        y = b * sqrt(a * a + 1.0);
    } else if (a > b) {
        b /= a;
        y = a * sqrt(b * b + 1.0);
    } else if (rtIsNaN_(b)) {
        y = b;
    } else {
        y = a * 1.4142135623730951;
    }

    return y;
}

/*
 * Arguments    : const double A[9]
 *                creal_T V[9]
 *                creal_T T[9]
 * Return Type  : void
 */
static void schur(const double A[9], creal_T V[9], creal_T T[9])
{
    boolean_T p;
    int rowleft;
    double b_A[9];
    int i3;
    double work[3];
    double alpha1;
    double tau[2];
    double xnorm;
    double beta1;
    int lastv;
    int lastc;
    int knt;
    double a;
    boolean_T exitg2;
    int ix;
    int j;
    int ia;
    int i4;
    int exitg1;
    double Vr[9];
    double d;
    double t1_re;
    double rt1i;
    double rt2r;
    double rt2i;
    double mu1_im;
    double mu1_re;
    p = true;

    for (rowleft = 0; rowleft < 9; rowleft++) {
        if (p && ((!rtIsInf_(A[rowleft])) && (!rtIsNaN_(A[rowleft])))) {
            p = true;
        } else {
            p = false;
        }
    }

    if (!p) {
        for (i3 = 0; i3 < 9; i3++) {
            V[i3].re = rtNaN;
            V[i3].im = 0.0;
        }

        V[2].re = 0.0;
        V[2].im = 0.0;

        for (i3 = 0; i3 < 9; i3++) {
            T[i3].re = rtNaN;
            T[i3].im = 0.0;
        }
    } else {
        memcpy(&b_A[0], &A[0], 9U * sizeof(double));
        work[0] = 0.0;
        work[1] = 0.0;
        work[2] = 0.0;
        alpha1 = b_A[1];
        tau[0] = 0.0;
        xnorm = xnrm2(1, b_A, 3);

        if (xnorm != 0.0) {
            beta1 = rt_hypotd_snf(b_A[1], xnorm);

            if (b_A[1] >= 0.0) {
                beta1 = -beta1;
            }

            if (fabs(beta1) < 1.0020841800044864E-292) {
                knt = -1;

                do {
                    knt++;

                    for (rowleft = 3; rowleft < 4; rowleft++) {
                        b_A[2] *= 9.9792015476736E+291;
                    }

                    beta1 *= 9.9792015476736E+291;
                    alpha1 *= 9.9792015476736E+291;
                } while (!(fabs(beta1) >= 1.0020841800044864E-292));

                beta1 = rt_hypotd_snf(alpha1, xnrm2(1, b_A, 3));

                if (alpha1 >= 0.0) {
                    beta1 = -beta1;
                }

                tau[0] = (beta1 - alpha1) / beta1;
                a = 1.0 / (alpha1 - beta1);

                for (rowleft = 3; rowleft < 4; rowleft++) {
                    b_A[2] *= a;
                }

                for (rowleft = 0; rowleft <= knt; rowleft++) {
                    beta1 *= 1.0020841800044864E-292;
                }

                alpha1 = beta1;
            } else {
                tau[0] = (beta1 - b_A[1]) / beta1;
                a = 1.0 / (b_A[1] - beta1);

                for (rowleft = 3; rowleft < 4; rowleft++) {
                    b_A[2] *= a;
                }

                alpha1 = beta1;
            }
        }

        b_A[1] = 1.0;

        if (tau[0] != 0.0) {
            lastv = 1;
            knt = 2;

            while ((lastv + 1 > 0) && (b_A[knt] == 0.0)) {
                lastv--;
                knt--;
            }

            lastc = 3;
            exitg2 = false;

            while ((!exitg2) && (lastc > 0)) {
                rowleft = 3 + lastc;
                ia = rowleft;

                do {
                    exitg1 = 0;

                    if (ia <= rowleft + lastv * 3) {
                        if (b_A[ia - 1] != 0.0) {
                            exitg1 = 1;
                        } else {
                            ia += 3;
                        }
                    } else {
                        lastc--;
                        exitg1 = 2;
                    }
                } while (exitg1 == 0);

                if (exitg1 == 1) {
                    exitg2 = true;
                }
            }
        } else {
            lastv = -1;
            lastc = 0;
        }

        if (lastv + 1 > 0) {
            if (lastc != 0) {
                memset(&work[0], 0, (unsigned int)(lastc * (int)sizeof(double)));
                ix = 1;
                i3 = 3 * lastv + 4;

                for (knt = 4; knt <= i3; knt += 3) {
                    rowleft = 0;
                    i4 = (knt + lastc) - 1;

                    for (ia = knt; ia <= i4; ia++) {
                        work[rowleft] += b_A[ia - 1] * b_A[ix];
                        rowleft++;
                    }

                    ix++;
                }
            }

            if (!(-tau[0] == 0.0)) {
                knt = 3;
                rowleft = 1;

                for (j = 0; j <= lastv; j++) {
                    if (b_A[rowleft] != 0.0) {
                        xnorm = b_A[rowleft] * -tau[0];
                        ix = 0;
                        i3 = knt + 1;
                        i4 = lastc + knt;

                        for (ia = i3; ia <= i4; ia++) {
                            b_A[ia - 1] += work[ix] * xnorm;
                            ix++;
                        }
                    }

                    rowleft++;
                    knt += 3;
                }
            }
        }

        xzlarf(2, 2, 2, tau[0], b_A, 5, work);
        b_A[1] = alpha1;
        alpha1 = b_A[5];
        tau[1] = 0.0;
        xnorm = xnrm2(0, b_A, 6);

        if (xnorm != 0.0) {
            beta1 = rt_hypotd_snf(b_A[5], xnorm);

            if (b_A[5] >= 0.0) {
                beta1 = -beta1;
            }

            if (fabs(beta1) < 1.0020841800044864E-292) {
                knt = -1;

                do {
                    knt++;
                    beta1 *= 9.9792015476736E+291;
                    alpha1 *= 9.9792015476736E+291;
                } while (!(fabs(beta1) >= 1.0020841800044864E-292));

                beta1 = rt_hypotd_snf(alpha1, xnorm);

                if (alpha1 >= 0.0) {
                    beta1 = -beta1;
                }

                tau[1] = (beta1 - alpha1) / beta1;

                for (rowleft = 0; rowleft <= knt; rowleft++) {
                    beta1 *= 1.0020841800044864E-292;
                }

                alpha1 = beta1;
            } else {
                tau[1] = (beta1 - b_A[5]) / beta1;
                alpha1 = beta1;
            }
        }

        b_A[5] = 1.0;

        if (tau[1] != 0.0) {
            lastv = 0;
            knt = 5;

            while ((lastv + 1 > 0) && (b_A[knt] == 0.0)) {
                lastv--;
                knt--;
            }

            lastc = 3;
            exitg2 = false;

            while ((!exitg2) && (lastc > 0)) {
                rowleft = 6 + lastc;
                ia = rowleft;

                do {
                    exitg1 = 0;

                    if (ia <= rowleft + lastv * 3) {
                        if (b_A[ia - 1] != 0.0) {
                            exitg1 = 1;
                        } else {
                            ia += 3;
                        }
                    } else {
                        lastc--;
                        exitg1 = 2;
                    }
                } while (exitg1 == 0);

                if (exitg1 == 1) {
                    exitg2 = true;
                }
            }
        } else {
            lastv = -1;
            lastc = 0;
        }

        if (lastv + 1 > 0) {
            if (lastc != 0) {
                memset(&work[0], 0, (unsigned int)(lastc * (int)sizeof(double)));
                ix = 5;
                i3 = 3 * lastv + 7;

                for (knt = 7; knt <= i3; knt += 3) {
                    rowleft = 0;
                    i4 = (knt + lastc) - 1;

                    for (ia = knt; ia <= i4; ia++) {
                        work[rowleft] += b_A[ia - 1] * b_A[ix];
                        rowleft++;
                    }

                    ix++;
                }
            }

            if (!(-tau[1] == 0.0)) {
                knt = 6;
                rowleft = 5;

                for (j = 0; j <= lastv; j++) {
                    if (b_A[rowleft] != 0.0) {
                        xnorm = b_A[rowleft] * -tau[1];
                        ix = 0;
                        i3 = knt + 1;
                        i4 = lastc + knt;

                        for (ia = i3; ia <= i4; ia++) {
                            b_A[ia - 1] += work[ix] * xnorm;
                            ix++;
                        }
                    }

                    rowleft++;
                    knt += 3;
                }
            }
        }

        xzlarf(1, 1, 6, tau[1], b_A, 9, work);
        b_A[5] = alpha1;
        memcpy(&Vr[0], &b_A[0], 9U * sizeof(double));

        for (knt = 0; knt < 2; knt++) {
            Vr[6 + knt] = 0.0;
        }

        for (knt = 0; knt < 1; knt++) {
            Vr[3] = 0.0;
        }

        for (knt = 3; knt < 4; knt++) {
            Vr[5] = Vr[2];
        }

        Vr[1] = 0.0;
        Vr[2] = 0.0;
        Vr[0] = 1.0;
        work[0] = 0.0;
        work[1] = 0.0;
        work[2] = 0.0;
        Vr[8] = 1.0 - tau[1];
        Vr[7] = 0.0;
        Vr[4] = 1.0;
        xzlarf(2, 1, 5, tau[0], Vr, 8, work);

        for (rowleft = 6; rowleft < 7; rowleft++) {
            Vr[5] *= -tau[0];
        }

        Vr[4] = 1.0 - tau[0];
        xhseqr(b_A, Vr);

        for (i3 = 0; i3 < 9; i3++) {
            T[i3].re = b_A[i3];
            T[i3].im = 0.0;
            V[i3].re = Vr[i3];
            V[i3].im = 0.0;
        }

        for (lastv = 1; lastv >= 0; lastv--) {
            ix = lastv + 1;
            i3 = lastv + 3 * lastv;
            i4 = i3 + 1;

            if (b_A[i4] != 0.0) {
                a = b_A[i3];
                lastc = 3 * (lastv + 1);
                knt = lastv + lastc;
                xnorm = b_A[knt];
                beta1 = b_A[i4];
                alpha1 = b_A[knt + 1];
                d = alpha1;
                xdlanv2(&a, &xnorm, &beta1, &d, &t1_re, &rt1i, &rt2r, &rt2i, &mu1_im, &mu1_re);
                mu1_re = t1_re - alpha1;
                xnorm = rt_hypotd_snf(rt_hypotd_snf(mu1_re, rt1i), b_A[i4]);

                if (rt1i == 0.0) {
                    mu1_re /= xnorm;
                    mu1_im = 0.0;
                } else if (mu1_re == 0.0) {
                    mu1_re = 0.0;
                    mu1_im = rt1i / xnorm;
                } else {
                    mu1_re /= xnorm;
                    mu1_im = rt1i / xnorm;
                }

                beta1 = b_A[i4] / xnorm;

                for (j = ix; j < 4; j++) {
                    rowleft = lastv + 3 * (j - 1);
                    d = T[lastv + 3 * (j - 1)].im;
                    t1_re = T[rowleft].re;
                    xnorm = d;
                    ia = rowleft + 1;
                    rt2r = T[ia].re;
                    rt2i = T[(lastv + 3 * (j - 1)) + 1].im;
                    alpha1 = (mu1_re * T[rowleft].re + mu1_im * d) + beta1 * T[ia].re;
                    d = (mu1_re * d - mu1_im * T[rowleft].re) + beta1 * rt2i;
                    T[rowleft].re = alpha1;
                    T[rowleft].im = d;
                    T[ia].re = (mu1_re * rt2r - mu1_im * rt2i) - beta1 * t1_re;
                    T[ia].im = (mu1_re * rt2i + mu1_im * rt2r) - beta1 * xnorm;
                }

                for (knt = 0; knt <= lastv + 1; knt++) {
                    rowleft = knt + 3 * lastv;
                    d = T[knt + 3 * lastv].im;
                    t1_re = T[rowleft].re;
                    ia = knt + lastc;
                    alpha1 = T[ia].re;
                    rt2i = T[knt + 3 * (lastv + 1)].im;
                    xnorm = mu1_re * d + mu1_im * T[rowleft].re;
                    T[rowleft].re = (mu1_re * T[rowleft].re - mu1_im * d) + beta1 * T[ia].re;
                    T[rowleft].im = xnorm + beta1 * rt2i;
                    rt2r = alpha1;
                    alpha1 = (mu1_re * alpha1 + mu1_im * rt2i) - beta1 * t1_re;
                    rt2i = (mu1_re * rt2i - mu1_im * rt2r) - beta1 * d;
                    T[ia].re = alpha1;
                    T[ia].im = rt2i;
                }

                alpha1 = V[3 * lastv].re;
                d = V[3 * lastv].im;
                rt2r = V[lastc].re;
                rt2i = V[3 * (lastv + 1)].im;
                V[3 * lastv].re = (mu1_re * alpha1 - mu1_im * d) + beta1 * V[lastc].re;
                V[3 * lastv].im = (mu1_re * d + mu1_im * alpha1) + beta1 * rt2i;
                xnorm = rt2r;
                rt2r = (mu1_re * rt2r + mu1_im * rt2i) - beta1 * alpha1;
                rt2i = (mu1_re * rt2i - mu1_im * xnorm) - beta1 * d;
                V[lastc].re = rt2r;
                V[lastc].im = rt2i;
                rowleft = 1 + 3 * lastv;
                d = V[1 + 3 * lastv].im;
                t1_re = V[rowleft].re;
                ia = 1 + lastc;
                rt2r = V[ia].re;
                rt2i = V[1 + 3 * (lastv + 1)].im;
                xnorm = mu1_re * d + mu1_im * V[rowleft].re;
                V[rowleft].re = (mu1_re * V[rowleft].re - mu1_im * d) + beta1 * V[ia].re;
                V[rowleft].im = xnorm + beta1 * rt2i;
                xnorm = rt2r;
                rt2r = (mu1_re * rt2r + mu1_im * rt2i) - beta1 * t1_re;
                rt2i = (mu1_re * rt2i - mu1_im * xnorm) - beta1 * d;
                V[ia].re = rt2r;
                V[ia].im = rt2i;
                rowleft = 2 + 3 * lastv;
                d = V[2 + 3 * lastv].im;
                t1_re = V[rowleft].re;
                ia = 2 + lastc;
                rt2r = V[ia].re;
                rt2i = V[2 + 3 * (lastv + 1)].im;
                xnorm = mu1_re * d + mu1_im * V[rowleft].re;
                V[rowleft].re = (mu1_re * V[rowleft].re - mu1_im * d) + beta1 * V[ia].re;
                V[rowleft].im = xnorm + beta1 * rt2i;
                xnorm = rt2r;
                rt2r = (mu1_re * rt2r + mu1_im * rt2i) - beta1 * t1_re;
                rt2i = (mu1_re * rt2i - mu1_im * xnorm) - beta1 * d;
                V[ia].re = rt2r;
                V[ia].im = rt2i;
                T[i4].re = 0.0;
                T[i4].im = 0.0;
            }
        }
    }
}

/*
 * Arguments    : const creal_T A[9]
 *                creal_T U[9]
 *                double s[3]
 *                creal_T V[9]
 * Return Type  : void
 */
static void svd(const creal_T A[9], creal_T U[9], double s[3], creal_T V[9])
{
    creal_T b_A[9];
    creal_T e[3];
    creal_T work[3];
    int qjj;
    boolean_T apply_transform;
    double nrm;
    creal_T Vf[9];
    creal_T b_s[3];
    double rt;
    double sm;
    int kase;
    int qp1;
    creal_T b_e;
    double r_re;
    double f;
    double r_im;
    double scale;
    double b;
    double sqds;
    int m;
    int q;
    int qq;
    double snorm;
    int exitg1;
    boolean_T exitg2;
    memcpy(&b_A[0], &A[0], 9U * sizeof(creal_T));
    e[0].re = 0.0;
    e[0].im = 0.0;
    work[0].re = 0.0;
    work[0].im = 0.0;
    e[1].re = 0.0;
    e[1].im = 0.0;
    work[1].re = 0.0;
    work[1].im = 0.0;
    e[2].re = 0.0;
    e[2].im = 0.0;
    work[2].re = 0.0;
    work[2].im = 0.0;

    for (qjj = 0; qjj < 9; qjj++) {
        U[qjj].re = 0.0;
        U[qjj].im = 0.0;
        Vf[qjj].re = 0.0;
        Vf[qjj].im = 0.0;
    }

    apply_transform = false;
    nrm = c_xnrm2(3, b_A, 1);

    if (nrm > 0.0) {
        apply_transform = true;

        if ((b_A[0].re == 0.0) && (b_A[0].im == 0.0)) {
            sm = 0.0;
            b_s[0].re = nrm;
            b_s[0].im = 0.0;
        } else {
            rt = nrm / rt_hypotd_snf(b_A[0].re, b_A[0].im);
            nrm = rt * b_A[0].re;
            sm = rt * b_A[0].im;
            b_s[0].re = nrm;
            b_s[0].im = sm;
        }

        if (rt_hypotd_snf(nrm, sm) >= 1.0020841800044864E-292) {
            if (sm == 0.0) {
                r_re = 1.0 / nrm;
                r_im = 0.0;
            } else if (nrm == 0.0) {
                r_re = 0.0;
                r_im = -(1.0 / sm);
            } else {
                f = fabs(nrm);
                b = fabs(sm);

                if (f > b) {
                    sqds = sm / nrm;
                    b = nrm + sqds * sm;
                    r_re = (1.0 + sqds * 0.0) / b;
                    r_im = (0.0 - sqds) / b;
                } else if (b == f) {
                    if (nrm > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (sm > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    r_re = (sqds + 0.0 * b) / f;
                    r_im = (0.0 * sqds - b) / f;
                } else {
                    sqds = nrm / sm;
                    b = sm + sqds * nrm;
                    r_re = sqds / b;
                    r_im = (sqds * 0.0 - 1.0) / b;
                }
            }

            for (qp1 = 1; qp1 < 4; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;
                b_A[qp1 - 1].re = r_re * rt - r_im * nrm;
                b_A[qp1 - 1].im = r_re * nrm + r_im * rt;
            }
        } else {
            for (qp1 = 1; qp1 < 4; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;

                if (b_s[0].im == 0.0) {
                    if (nrm == 0.0) {
                        b_A[qp1 - 1].re = rt / b_s[0].re;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (rt == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = nrm / b_s[0].re;
                    } else {
                        b_A[qp1 - 1].re = rt / b_s[0].re;
                        b_A[qp1 - 1].im = nrm / b_s[0].re;
                    }
                } else if (b_s[0].re == 0.0) {
                    if (rt == 0.0) {
                        b_A[qp1 - 1].re = nrm / b_s[0].im;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (nrm == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = -(rt / b_s[0].im);
                    } else {
                        b_A[qp1 - 1].re = nrm / b_s[0].im;
                        b_A[qp1 - 1].im = -(rt / b_s[0].im);
                    }
                } else {
                    f = fabs(b_s[0].re);
                    b = fabs(b_s[0].im);

                    if (f > b) {
                        sqds = b_s[0].im / b_s[0].re;
                        b = b_s[0].re + sqds * b_s[0].im;
                        b_A[qp1 - 1].re = (rt + sqds * nrm) / b;
                        b_A[qp1 - 1].im = (nrm - sqds * rt) / b;
                    } else if (b == f) {
                        if (b_s[0].re > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        if (b_s[0].im > 0.0) {
                            b = 0.5;
                        } else {
                            b = -0.5;
                        }

                        b_A[qp1 - 1].re = (rt * sqds + nrm * b) / f;
                        b_A[qp1 - 1].im = (nrm * sqds - rt * b) / f;
                    } else {
                        sqds = b_s[0].re / b_s[0].im;
                        b = b_s[0].im + sqds * b_s[0].re;
                        b_A[qp1 - 1].re = (sqds * rt + nrm) / b;
                        b_A[qp1 - 1].im = (sqds * nrm - rt) / b;
                    }
                }
            }
        }

        b_A[0].re++;
        b_s[0].re = -b_s[0].re;
        b_s[0].im = -b_s[0].im;
    } else {
        b_s[0].re = 0.0;
        b_s[0].im = 0.0;
    }

    for (kase = 2; kase < 4; kase++) {
        qjj = 3 * (kase - 1);

        if (apply_transform) {
            b_e = xdotc(3, b_A, 1, b_A, qjj + 1);

            if (b_A[0].im == 0.0) {
                if (b_e.im == 0.0) {
                    scale = b_e.re / b_A[0].re;
                    sm = 0.0;
                } else if (b_e.re == 0.0) {
                    scale = 0.0;
                    sm = b_e.im / b_A[0].re;
                } else {
                    scale = b_e.re / b_A[0].re;
                    sm = b_e.im / b_A[0].re;
                }
            } else if (b_A[0].re == 0.0) {
                if (b_e.re == 0.0) {
                    scale = b_e.im / b_A[0].im;
                    sm = 0.0;
                } else if (b_e.im == 0.0) {
                    scale = 0.0;
                    sm = -(b_e.re / b_A[0].im);
                } else {
                    scale = b_e.im / b_A[0].im;
                    sm = -(b_e.re / b_A[0].im);
                }
            } else {
                f = fabs(b_A[0].re);
                b = fabs(b_A[0].im);

                if (f > b) {
                    sqds = b_A[0].im / b_A[0].re;
                    b = b_A[0].re + sqds * b_A[0].im;
                    scale = (b_e.re + sqds * b_e.im) / b;
                    sm = (b_e.im - sqds * b_e.re) / b;
                } else if (b == f) {
                    if (b_A[0].re > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (b_A[0].im > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    scale = (b_e.re * sqds + b_e.im * b) / f;
                    sm = (b_e.im * sqds - b_e.re * b) / f;
                } else {
                    sqds = b_A[0].re / b_A[0].im;
                    b = b_A[0].im + sqds * b_A[0].re;
                    scale = (sqds * b_e.re + b_e.im) / b;
                    sm = (sqds * b_e.im - b_e.re) / b;
                }
            }

            b_e.re = -scale;
            b_e.im = -sm;
            xaxpy(3, b_e, 1, b_A, qjj + 1);
        }

        e[kase - 1].re = b_A[qjj].re;
        e[kase - 1].im = -b_A[qjj].im;
    }

    for (qp1 = 1; qp1 < 4; qp1++) {
        U[qp1 - 1] = b_A[qp1 - 1];
    }

    nrm = d_xnrm2(2, e, 2);

    if (nrm == 0.0) {
        e[0].re = 0.0;
        e[0].im = 0.0;
    } else {
        if ((e[1].re == 0.0) && (e[1].im == 0.0)) {
            e[0].re = nrm;
            e[0].im = 0.0;
        } else {
            rt = nrm / rt_hypotd_snf(e[1].re, e[1].im);
            e[0].re = rt * e[1].re;
            e[0].im = rt * e[1].im;
        }

        r_re = e[0].re;
        r_im = e[0].im;

        if (rt_hypotd_snf(e[0].re, e[0].im) >= 1.0020841800044864E-292) {
            if (e[0].im == 0.0) {
                r_re = 1.0 / e[0].re;
                r_im = 0.0;
            } else if (e[0].re == 0.0) {
                r_re = 0.0;
                r_im = -(1.0 / e[0].im);
            } else {
                f = fabs(e[0].re);
                b = fabs(e[0].im);

                if (f > b) {
                    sqds = e[0].im / e[0].re;
                    b = e[0].re + sqds * e[0].im;
                    r_re = (1.0 + sqds * 0.0) / b;
                    r_im = (0.0 - sqds) / b;
                } else if (b == f) {
                    if (e[0].re > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (e[0].im > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    r_re = (sqds + 0.0 * b) / f;
                    r_im = (0.0 * sqds - b) / f;
                } else {
                    sqds = e[0].re / e[0].im;
                    b = e[0].im + sqds * e[0].re;
                    r_re = sqds / b;
                    r_im = (sqds * 0.0 - 1.0) / b;
                }
            }

            for (qp1 = 2; qp1 < 4; qp1++) {
                scale = e[qp1 - 1].re;
                sm = e[qp1 - 1].im;
                e[qp1 - 1].re = r_re * scale - r_im * sm;
                e[qp1 - 1].im = r_re * sm + r_im * scale;
            }
        } else {
            for (qp1 = 2; qp1 < 4; qp1++) {
                scale = e[qp1 - 1].re;
                sm = e[qp1 - 1].im;

                if (r_im == 0.0) {
                    if (sm == 0.0) {
                        e[qp1 - 1].re = scale / r_re;
                        e[qp1 - 1].im = 0.0;
                    } else if (scale == 0.0) {
                        e[qp1 - 1].re = 0.0;
                        e[qp1 - 1].im = sm / r_re;
                    } else {
                        e[qp1 - 1].re = scale / r_re;
                        e[qp1 - 1].im = sm / r_re;
                    }
                } else if (r_re == 0.0) {
                    if (scale == 0.0) {
                        e[qp1 - 1].re = sm / r_im;
                        e[qp1 - 1].im = 0.0;
                    } else if (sm == 0.0) {
                        e[qp1 - 1].re = 0.0;
                        e[qp1 - 1].im = -(scale / r_im);
                    } else {
                        e[qp1 - 1].re = sm / r_im;
                        e[qp1 - 1].im = -(scale / r_im);
                    }
                } else {
                    f = fabs(r_re);
                    b = fabs(r_im);

                    if (f > b) {
                        sqds = r_im / r_re;
                        b = r_re + sqds * r_im;
                        e[qp1 - 1].re = (scale + sqds * sm) / b;
                        e[qp1 - 1].im = (sm - sqds * scale) / b;
                    } else if (b == f) {
                        if (r_re > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        if (r_im > 0.0) {
                            b = 0.5;
                        } else {
                            b = -0.5;
                        }

                        e[qp1 - 1].re = (scale * sqds + sm * b) / f;
                        e[qp1 - 1].im = (sm * sqds - scale * b) / f;
                    } else {
                        sqds = r_re / r_im;
                        b = r_im + sqds * r_re;
                        e[qp1 - 1].re = (sqds * scale + sm) / b;
                        e[qp1 - 1].im = (sqds * sm - scale) / b;
                    }
                }
            }
        }

        e[1].re++;
        e[0].re = -e[0].re;

        for (qp1 = 2; qp1 < 4; qp1++) {
            work[qp1 - 1].re = 0.0;
            work[qp1 - 1].im = 0.0;
        }

        for (kase = 2; kase < 4; kase++) {
            b_xaxpy(2, e[kase - 1], b_A, 3 * (kase - 1) + 2, work, 2);
        }

        for (kase = 2; kase < 4; kase++) {
            rt = -e[kase - 1].re;
            nrm = -e[kase - 1].im;

            if (e[1].im == 0.0) {
                if (nrm == 0.0) {
                    scale = rt / e[1].re;
                    sm = 0.0;
                } else if (rt == 0.0) {
                    scale = 0.0;
                    sm = nrm / e[1].re;
                } else {
                    scale = rt / e[1].re;
                    sm = nrm / e[1].re;
                }
            } else if (e[1].re == 0.0) {
                if (rt == 0.0) {
                    scale = nrm / e[1].im;
                    sm = 0.0;
                } else if (nrm == 0.0) {
                    scale = 0.0;
                    sm = -(rt / e[1].im);
                } else {
                    scale = nrm / e[1].im;
                    sm = -(rt / e[1].im);
                }
            } else {
                f = fabs(e[1].re);
                b = fabs(e[1].im);

                if (f > b) {
                    sqds = e[1].im / e[1].re;
                    b = e[1].re + sqds * e[1].im;
                    scale = (rt + sqds * nrm) / b;
                    sm = (nrm - sqds * rt) / b;
                } else if (b == f) {
                    if (e[1].re > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (e[1].im > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    scale = (rt * sqds + nrm * b) / f;
                    sm = (nrm * sqds - rt * b) / f;
                } else {
                    sqds = e[1].re / e[1].im;
                    b = e[1].im + sqds * e[1].re;
                    scale = (sqds * rt + nrm) / b;
                    sm = (sqds * nrm - rt) / b;
                }
            }

            b_e.re = scale;
            b_e.im = -sm;
            c_xaxpy(2, b_e, work, 2, b_A, 3 * (kase - 1) + 2);
        }
    }

    for (qp1 = 2; qp1 < 4; qp1++) {
        Vf[qp1 - 1] = e[qp1 - 1];
    }

    apply_transform = false;
    nrm = c_xnrm2(2, b_A, 5);

    if (nrm > 0.0) {
        apply_transform = true;

        if ((b_A[4].re == 0.0) && (b_A[4].im == 0.0)) {
            sm = 0.0;
            b_s[1].re = nrm;
            b_s[1].im = 0.0;
        } else {
            rt = nrm / rt_hypotd_snf(b_A[4].re, b_A[4].im);
            nrm = rt * b_A[4].re;
            sm = rt * b_A[4].im;
            b_s[1].re = nrm;
            b_s[1].im = sm;
        }

        if (rt_hypotd_snf(nrm, sm) >= 1.0020841800044864E-292) {
            if (sm == 0.0) {
                r_re = 1.0 / nrm;
                r_im = 0.0;
            } else if (nrm == 0.0) {
                r_re = 0.0;
                r_im = -(1.0 / sm);
            } else {
                f = fabs(nrm);
                b = fabs(sm);

                if (f > b) {
                    sqds = sm / nrm;
                    b = nrm + sqds * sm;
                    r_re = (1.0 + sqds * 0.0) / b;
                    r_im = (0.0 - sqds) / b;
                } else if (b == f) {
                    if (nrm > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (sm > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    r_re = (sqds + 0.0 * b) / f;
                    r_im = (0.0 * sqds - b) / f;
                } else {
                    sqds = nrm / sm;
                    b = sm + sqds * nrm;
                    r_re = sqds / b;
                    r_im = (sqds * 0.0 - 1.0) / b;
                }
            }

            for (qp1 = 5; qp1 < 7; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;
                b_A[qp1 - 1].re = r_re * rt - r_im * nrm;
                b_A[qp1 - 1].im = r_re * nrm + r_im * rt;
            }
        } else {
            for (qp1 = 5; qp1 < 7; qp1++) {
                rt = b_A[qp1 - 1].re;
                nrm = b_A[qp1 - 1].im;

                if (b_s[1].im == 0.0) {
                    if (nrm == 0.0) {
                        b_A[qp1 - 1].re = rt / b_s[1].re;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (rt == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = nrm / b_s[1].re;
                    } else {
                        b_A[qp1 - 1].re = rt / b_s[1].re;
                        b_A[qp1 - 1].im = nrm / b_s[1].re;
                    }
                } else if (b_s[1].re == 0.0) {
                    if (rt == 0.0) {
                        b_A[qp1 - 1].re = nrm / b_s[1].im;
                        b_A[qp1 - 1].im = 0.0;
                    } else if (nrm == 0.0) {
                        b_A[qp1 - 1].re = 0.0;
                        b_A[qp1 - 1].im = -(rt / b_s[1].im);
                    } else {
                        b_A[qp1 - 1].re = nrm / b_s[1].im;
                        b_A[qp1 - 1].im = -(rt / b_s[1].im);
                    }
                } else {
                    f = fabs(b_s[1].re);
                    b = fabs(b_s[1].im);

                    if (f > b) {
                        sqds = b_s[1].im / b_s[1].re;
                        b = b_s[1].re + sqds * b_s[1].im;
                        b_A[qp1 - 1].re = (rt + sqds * nrm) / b;
                        b_A[qp1 - 1].im = (nrm - sqds * rt) / b;
                    } else if (b == f) {
                        if (b_s[1].re > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        if (b_s[1].im > 0.0) {
                            b = 0.5;
                        } else {
                            b = -0.5;
                        }

                        b_A[qp1 - 1].re = (rt * sqds + nrm * b) / f;
                        b_A[qp1 - 1].im = (nrm * sqds - rt * b) / f;
                    } else {
                        sqds = b_s[1].re / b_s[1].im;
                        b = b_s[1].im + sqds * b_s[1].re;
                        b_A[qp1 - 1].re = (sqds * rt + nrm) / b;
                        b_A[qp1 - 1].im = (sqds * nrm - rt) / b;
                    }
                }
            }
        }

        b_A[4].re++;
        b_s[1].re = -b_s[1].re;
        b_s[1].im = -b_s[1].im;
    } else {
        b_s[1].re = 0.0;
        b_s[1].im = 0.0;
    }

    for (kase = 3; kase < 4; kase++) {
        if (apply_transform) {
            b_e = xdotc(2, b_A, 5, b_A, 8);

            if (b_A[4].im == 0.0) {
                if (b_e.im == 0.0) {
                    scale = b_e.re / b_A[4].re;
                    sm = 0.0;
                } else if (b_e.re == 0.0) {
                    scale = 0.0;
                    sm = b_e.im / b_A[4].re;
                } else {
                    scale = b_e.re / b_A[4].re;
                    sm = b_e.im / b_A[4].re;
                }
            } else if (b_A[4].re == 0.0) {
                if (b_e.re == 0.0) {
                    scale = b_e.im / b_A[4].im;
                    sm = 0.0;
                } else if (b_e.im == 0.0) {
                    scale = 0.0;
                    sm = -(b_e.re / b_A[4].im);
                } else {
                    scale = b_e.im / b_A[4].im;
                    sm = -(b_e.re / b_A[4].im);
                }
            } else {
                f = fabs(b_A[4].re);
                b = fabs(b_A[4].im);

                if (f > b) {
                    sqds = b_A[4].im / b_A[4].re;
                    b = b_A[4].re + sqds * b_A[4].im;
                    scale = (b_e.re + sqds * b_e.im) / b;
                    sm = (b_e.im - sqds * b_e.re) / b;
                } else if (b == f) {
                    if (b_A[4].re > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (b_A[4].im > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    scale = (b_e.re * sqds + b_e.im * b) / f;
                    sm = (b_e.im * sqds - b_e.re * b) / f;
                } else {
                    sqds = b_A[4].re / b_A[4].im;
                    b = b_A[4].im + sqds * b_A[4].re;
                    scale = (sqds * b_e.re + b_e.im) / b;
                    sm = (sqds * b_e.im - b_e.re) / b;
                }
            }

            b_e.re = -scale;
            b_e.im = -sm;
            xaxpy(2, b_e, 5, b_A, 8);
        }
    }

    for (qp1 = 2; qp1 < 4; qp1++) {
        U[qp1 + 2] = b_A[qp1 + 2];
    }

    m = 1;
    b_s[2] = b_A[8];
    e[1] = b_A[7];
    e[2].re = 0.0;
    e[2].im = 0.0;
    U[6].re = 0.0;
    U[6].im = 0.0;
    U[7].re = 0.0;
    U[7].im = 0.0;
    U[8].re = 1.0;
    U[8].im = 0.0;

    for (q = 1; q >= 0; q--) {
        qp1 = q + 2;
        qq = q + 3 * q;

        if ((b_s[q].re != 0.0) || (b_s[q].im != 0.0)) {
            for (kase = qp1; kase < 4; kase++) {
                qjj = (q + 3 * (kase - 1)) + 1;
                b_e = xdotc(3 - q, U, qq + 1, U, qjj);

                if (U[qq].im == 0.0) {
                    if (b_e.im == 0.0) {
                        scale = b_e.re / U[qq].re;
                        sm = 0.0;
                    } else if (b_e.re == 0.0) {
                        scale = 0.0;
                        sm = b_e.im / U[qq].re;
                    } else {
                        scale = b_e.re / U[qq].re;
                        sm = b_e.im / U[qq].re;
                    }
                } else if (U[qq].re == 0.0) {
                    if (b_e.re == 0.0) {
                        scale = b_e.im / U[qq].im;
                        sm = 0.0;
                    } else if (b_e.im == 0.0) {
                        scale = 0.0;
                        sm = -(b_e.re / U[qq].im);
                    } else {
                        scale = b_e.im / U[qq].im;
                        sm = -(b_e.re / U[qq].im);
                    }
                } else {
                    f = fabs(U[qq].re);
                    b = fabs(U[qq].im);

                    if (f > b) {
                        sqds = U[qq].im / U[qq].re;
                        b = U[qq].re + sqds * U[qq].im;
                        scale = (b_e.re + sqds * b_e.im) / b;
                        sm = (b_e.im - sqds * b_e.re) / b;
                    } else if (b == f) {
                        if (U[qq].re > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        if (U[qq].im > 0.0) {
                            b = 0.5;
                        } else {
                            b = -0.5;
                        }

                        scale = (b_e.re * sqds + b_e.im * b) / f;
                        sm = (b_e.im * sqds - b_e.re * b) / f;
                    } else {
                        sqds = U[qq].re / U[qq].im;
                        b = U[qq].im + sqds * U[qq].re;
                        scale = (sqds * b_e.re + b_e.im) / b;
                        sm = (sqds * b_e.im - b_e.re) / b;
                    }
                }

                b_e.re = -scale;
                b_e.im = -sm;
                xaxpy(3 - q, b_e, qq + 1, U, qjj);
            }

            for (qp1 = q + 1; qp1 < 4; qp1++) {
                qjj = (qp1 + 3 * q) - 1;
                U[qjj].re = -U[qjj].re;
                U[qjj].im = -U[qjj].im;
            }

            U[qq].re++;

            if (0 <= q - 1) {
                U[3 * q].re = 0.0;
                U[3 * q].im = 0.0;
            }
        } else {
            U[3 * q].re = 0.0;
            U[3 * q].im = 0.0;
            qjj = 1 + 3 * q;
            U[qjj].re = 0.0;
            U[qjj].im = 0.0;
            qjj = 2 + 3 * q;
            U[qjj].re = 0.0;
            U[qjj].im = 0.0;
            U[qq].re = 1.0;
            U[qq].im = 0.0;
        }
    }

    for (q = 2; q >= 0; q--) {
        if ((q + 1 <= 1) && ((e[0].re != 0.0) || (e[0].im != 0.0))) {
            b_e = xdotc(2, Vf, 2, Vf, 5);

            if (Vf[1].im == 0.0) {
                if (b_e.im == 0.0) {
                    scale = b_e.re / Vf[1].re;
                    sm = 0.0;
                } else if (b_e.re == 0.0) {
                    scale = 0.0;
                    sm = b_e.im / Vf[1].re;
                } else {
                    scale = b_e.re / Vf[1].re;
                    sm = b_e.im / Vf[1].re;
                }
            } else if (Vf[1].re == 0.0) {
                if (b_e.re == 0.0) {
                    scale = b_e.im / Vf[1].im;
                    sm = 0.0;
                } else if (b_e.im == 0.0) {
                    scale = 0.0;
                    sm = -(b_e.re / Vf[1].im);
                } else {
                    scale = b_e.im / Vf[1].im;
                    sm = -(b_e.re / Vf[1].im);
                }
            } else {
                nrm = fabs(Vf[1].re);
                rt = fabs(Vf[1].im);

                if (nrm > rt) {
                    rt = Vf[1].im / Vf[1].re;
                    nrm = Vf[1].re + rt * Vf[1].im;
                    scale = (b_e.re + rt * b_e.im) / nrm;
                    sm = (b_e.im - rt * b_e.re) / nrm;
                } else if (rt == nrm) {
                    if (Vf[1].re > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (Vf[1].im > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    scale = (b_e.re * sqds + b_e.im * b) / nrm;
                    sm = (b_e.im * sqds - b_e.re * b) / nrm;
                } else {
                    rt = Vf[1].re / Vf[1].im;
                    nrm = Vf[1].im + rt * Vf[1].re;
                    scale = (rt * b_e.re + b_e.im) / nrm;
                    sm = (rt * b_e.im - b_e.re) / nrm;
                }
            }

            b_e.re = -scale;
            b_e.im = -sm;
            xaxpy(2, b_e, 2, Vf, 5);
            b_e = xdotc(2, Vf, 2, Vf, 8);

            if (Vf[1].im == 0.0) {
                if (b_e.im == 0.0) {
                    scale = b_e.re / Vf[1].re;
                    sm = 0.0;
                } else if (b_e.re == 0.0) {
                    scale = 0.0;
                    sm = b_e.im / Vf[1].re;
                } else {
                    scale = b_e.re / Vf[1].re;
                    sm = b_e.im / Vf[1].re;
                }
            } else if (Vf[1].re == 0.0) {
                if (b_e.re == 0.0) {
                    scale = b_e.im / Vf[1].im;
                    sm = 0.0;
                } else if (b_e.im == 0.0) {
                    scale = 0.0;
                    sm = -(b_e.re / Vf[1].im);
                } else {
                    scale = b_e.im / Vf[1].im;
                    sm = -(b_e.re / Vf[1].im);
                }
            } else {
                f = fabs(Vf[1].re);
                b = fabs(Vf[1].im);

                if (f > b) {
                    sqds = Vf[1].im / Vf[1].re;
                    b = Vf[1].re + sqds * Vf[1].im;
                    scale = (b_e.re + sqds * b_e.im) / b;
                    sm = (b_e.im - sqds * b_e.re) / b;
                } else if (b == f) {
                    if (Vf[1].re > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (Vf[1].im > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    scale = (b_e.re * sqds + b_e.im * b) / f;
                    sm = (b_e.im * sqds - b_e.re * b) / f;
                } else {
                    sqds = Vf[1].re / Vf[1].im;
                    b = Vf[1].im + sqds * Vf[1].re;
                    scale = (sqds * b_e.re + b_e.im) / b;
                    sm = (sqds * b_e.im - b_e.re) / b;
                }
            }

            b_e.re = -scale;
            b_e.im = -sm;
            xaxpy(2, b_e, 2, Vf, 8);
        }

        Vf[3 * q].re = 0.0;
        Vf[3 * q].im = 0.0;
        qjj = 1 + 3 * q;
        Vf[qjj].re = 0.0;
        Vf[qjj].im = 0.0;
        qjj = 2 + 3 * q;
        Vf[qjj].re = 0.0;
        Vf[qjj].im = 0.0;
        qjj = q + 3 * q;
        Vf[qjj].re = 1.0;
        Vf[qjj].im = 0.0;
    }

    qq = 0;
    snorm = 0.0;

    for (q = 0; q < 3; q++) {
        if ((b_s[q].re != 0.0) || (b_s[q].im != 0.0)) {
            rt = rt_hypotd_snf(b_s[q].re, b_s[q].im);

            if (b_s[q].im == 0.0) {
                r_re = b_s[q].re / rt;
                r_im = 0.0;
            } else if (b_s[q].re == 0.0) {
                r_re = 0.0;
                r_im = b_s[q].im / rt;
            } else {
                r_re = b_s[q].re / rt;
                r_im = b_s[q].im / rt;
            }

            b_s[q].re = rt;
            b_s[q].im = 0.0;

            if (q + 1 < 3) {
                scale = e[q].re;

                if (r_im == 0.0) {
                    if (e[q].im == 0.0) {
                        e[q].re /= r_re;
                        e[q].im = 0.0;
                    } else if (e[q].re == 0.0) {
                        e[q].re = 0.0;
                        e[q].im /= r_re;
                    } else {
                        e[q].re /= r_re;
                        e[q].im /= r_re;
                    }
                } else if (r_re == 0.0) {
                    if (e[q].re == 0.0) {
                        e[q].re = e[q].im / r_im;
                        e[q].im = 0.0;
                    } else if (e[q].im == 0.0) {
                        e[q].re = 0.0;
                        e[q].im = -(scale / r_im);
                    } else {
                        e[q].re = e[q].im / r_im;
                        e[q].im = -(scale / r_im);
                    }
                } else {
                    f = fabs(r_re);
                    b = fabs(r_im);

                    if (f > b) {
                        sqds = r_im / r_re;
                        b = r_re + sqds * r_im;
                        e[q].re = (e[q].re + sqds * e[q].im) / b;
                        e[q].im = (e[q].im - sqds * scale) / b;
                    } else if (b == f) {
                        if (r_re > 0.0) {
                            sqds = 0.5;
                        } else {
                            sqds = -0.5;
                        }

                        if (r_im > 0.0) {
                            b = 0.5;
                        } else {
                            b = -0.5;
                        }

                        e[q].re = (e[q].re * sqds + e[q].im * b) / f;
                        e[q].im = (e[q].im * sqds - scale * b) / f;
                    } else {
                        sqds = r_re / r_im;
                        b = r_im + sqds * r_re;
                        e[q].re = (sqds * e[q].re + e[q].im) / b;
                        e[q].im = (sqds * e[q].im - scale) / b;
                    }
                }
            }

            kase = 3 * q;
            qjj = kase + 3;

            for (qp1 = kase + 1; qp1 <= qjj; qp1++) {
                rt = U[qp1 - 1].re;
                nrm = U[qp1 - 1].im;
                U[qp1 - 1].re = r_re * rt - r_im * nrm;
                U[qp1 - 1].im = r_re * nrm + r_im * rt;
            }
        }

        if ((q + 1 < 3) && ((e[q].re != 0.0) || (e[q].im != 0.0))) {
            rt = rt_hypotd_snf(e[q].re, e[q].im);

            if (e[q].im == 0.0) {
                r_re = rt / e[q].re;
                r_im = 0.0;
            } else if (e[q].re == 0.0) {
                if (rt == 0.0) {
                    r_re = 0.0 / e[q].im;
                    r_im = 0.0;
                } else {
                    r_re = 0.0;
                    r_im = -(rt / e[q].im);
                }
            } else {
                f = fabs(e[q].re);
                b = fabs(e[q].im);

                if (f > b) {
                    sqds = e[q].im / e[q].re;
                    b = e[q].re + sqds * e[q].im;
                    r_re = (rt + sqds * 0.0) / b;
                    r_im = (0.0 - sqds * rt) / b;
                } else if (b == f) {
                    if (e[q].re > 0.0) {
                        sqds = 0.5;
                    } else {
                        sqds = -0.5;
                    }

                    if (e[q].im > 0.0) {
                        b = 0.5;
                    } else {
                        b = -0.5;
                    }

                    r_re = (rt * sqds + 0.0 * b) / f;
                    r_im = (0.0 * sqds - rt * b) / f;
                } else {
                    sqds = e[q].re / e[q].im;
                    b = e[q].im + sqds * e[q].re;
                    r_re = sqds * rt / b;
                    r_im = (sqds * 0.0 - rt) / b;
                }
            }

            e[q].re = rt;
            e[q].im = 0.0;
            rt = b_s[q + 1].re;
            nrm = b_s[q + 1].im;
            b_s[q + 1].re = rt * r_re - nrm * r_im;
            b_s[q + 1].im = rt * r_im + nrm * r_re;
            kase = 3 * (q + 1);
            qjj = kase + 3;

            for (qp1 = kase + 1; qp1 <= qjj; qp1++) {
                rt = Vf[qp1 - 1].re;
                nrm = Vf[qp1 - 1].im;
                Vf[qp1 - 1].re = r_re * rt - r_im * nrm;
                Vf[qp1 - 1].im = r_re * nrm + r_im * rt;
            }
        }

        rt = fabs(b_s[q].re);
        nrm = fabs(e[q].re);

        if ((rt > nrm) || rtIsNaN_(nrm)) {
            nrm = rt;
        }

        if ((!(snorm > nrm)) && (!rtIsNaN_(nrm))) {
            snorm = nrm;
        }
    }

    while ((m + 2 > 0) && (qq < 75)) {
        qp1 = m;

        do {
            exitg1 = 0;
            q = qp1 + 1;

            if (qp1 + 1 == 0) {
                exitg1 = 1;
            } else {
                rt = fabs(e[qp1].re);

                if ((rt <= 2.2204460492503131E-16 * (fabs(b_s[qp1].re) + fabs(b_s[qp1 + 1].re))) || (rt <= 1.0020841800044864E-292) || ((qq > 20) && (rt <= 2.2204460492503131E-16 * snorm))) {
                    e[qp1].re = 0.0;
                    e[qp1].im = 0.0;
                    exitg1 = 1;
                } else {
                    qp1--;
                }
            }
        } while (exitg1 == 0);

        if (qp1 + 1 == m + 1) {
            kase = 4;
        } else {
            qjj = m + 2;
            kase = m + 2;
            exitg2 = false;

            while ((!exitg2) && (kase >= qp1 + 1)) {
                qjj = kase;

                if (kase == qp1 + 1) {
                    exitg2 = true;
                } else {
                    rt = 0.0;

                    if (kase < m + 2) {
                        rt = fabs(e[kase - 1].re);
                    }

                    if (kase > qp1 + 2) {
                        rt += fabs(e[kase - 2].re);
                    }

                    nrm = fabs(b_s[kase - 1].re);

                    if ((nrm <= 2.2204460492503131E-16 * rt) || (nrm <= 1.0020841800044864E-292)) {
                        b_s[kase - 1].re = 0.0;
                        b_s[kase - 1].im = 0.0;
                        exitg2 = true;
                    } else {
                        kase--;
                    }
                }
            }

            if (qjj == qp1 + 1) {
                kase = 3;
            } else if (qjj == m + 2) {
                kase = 1;
            } else {
                kase = 2;
                q = qjj;
            }
        }

        switch (kase) {
        case 1:
            f = e[m].re;
            e[m].re = 0.0;
            e[m].im = 0.0;
            qjj = m + 1;
            scale = e[0].re;
            sm = e[0].im;

            for (qp1 = qjj; qp1 >= q + 1; qp1--) {
                rt = b_s[qp1 - 1].re;
                xrotg(&rt, &f, &nrm, &b);
                b_s[qp1 - 1].re = rt;
                b_s[qp1 - 1].im = 0.0;

                if (qp1 > q + 1) {
                    f = -b * scale;
                    scale *= nrm;
                    sm *= nrm;
                }

                xrot(Vf, 1 + 3 * (qp1 - 1), 1 + 3 * (m + 1), nrm, b);
                e[0].re = scale;
                e[0].im = sm;
            }

            break;

        case 2:
            f = e[q - 1].re;
            e[q - 1].re = 0.0;
            e[q - 1].im = 0.0;

            for (qp1 = q + 1; qp1 <= m + 2; qp1++) {
                rt = b_s[qp1 - 1].re;
                xrotg(&rt, &f, &nrm, &b);
                b_s[qp1 - 1].re = rt;
                b_s[qp1 - 1].im = 0.0;
                f = -b * e[qp1 - 1].re;
                e[qp1 - 1].re *= nrm;
                e[qp1 - 1].im *= nrm;
                xrot(U, 1 + 3 * (qp1 - 1), 1 + 3 * (q - 1), nrm, b);
            }

            break;

        case 3:
            kase = m + 1;
            scale = fabs(b_s[m + 1].re);
            nrm = fabs(b_s[m].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            nrm = fabs(e[m].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            nrm = fabs(b_s[q].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            nrm = fabs(e[q].re);

            if ((!(scale > nrm)) && (!rtIsNaN_(nrm))) {
                scale = nrm;
            }

            sm = b_s[m + 1].re / scale;
            rt = b_s[m].re / scale;
            nrm = e[m].re / scale;
            sqds = b_s[q].re / scale;
            b = ((rt + sm) * (rt - sm) + nrm * nrm) / 2.0;
            rt = sm * nrm;
            rt *= rt;

            if ((b != 0.0) || (rt != 0.0)) {
                nrm = b * b + rt;
                b_sqrt(&nrm);

                if (b < 0.0) {
                    nrm = -nrm;
                }

                nrm = rt / (b + nrm);
            } else {
                nrm = 0.0;
            }

            f = (sqds + sm) * (sqds - sm) + nrm;
            rt = sqds * (e[q].re / scale);

            for (qp1 = q + 1; qp1 <= kase; qp1++) {
                xrotg(&f, &rt, &nrm, &b);

                if (qp1 > q + 1) {
                    e[0].re = f;
                    e[0].im = 0.0;
                }

                f = nrm * b_s[qp1 - 1].re + b * e[qp1 - 1].re;
                e[qp1 - 1].re = nrm * e[qp1 - 1].re - b * b_s[qp1 - 1].re;
                e[qp1 - 1].im = nrm * e[qp1 - 1].im - b * b_s[qp1 - 1].im;
                rt = b * b_s[qp1].re;
                scale = nrm * b_s[qp1].re;
                sm = nrm * b_s[qp1].im;
                xrot(Vf, 1 + 3 * (qp1 - 1), 1 + 3 * qp1, nrm, b);
                xrotg(&f, &rt, &nrm, &b);
                b_s[qp1 - 1].re = f;
                b_s[qp1 - 1].im = 0.0;
                f = nrm * e[qp1 - 1].re + b * scale;
                scale = -b * e[qp1 - 1].re + nrm * scale;
                sm = -b * e[qp1 - 1].im + nrm * sm;
                b_s[qp1].re = scale;
                b_s[qp1].im = sm;
                rt = b * e[qp1].re;
                e[qp1].re *= nrm;
                e[qp1].im *= nrm;
                xrot(U, 1 + 3 * (qp1 - 1), 1 + 3 * qp1, nrm, b);
            }

            e[m].re = f;
            e[m].im = 0.0;
            qq++;
            break;

        default:
            if (b_s[q].re < 0.0) {
                b_s[q].re = -b_s[q].re;
                b_s[q].im = 0.0;
                kase = 3 * q;
                qjj = kase + 3;

                for (qp1 = kase + 1; qp1 <= qjj; qp1++) {
                    rt = Vf[qp1 - 1].re;
                    nrm = Vf[qp1 - 1].im;
                    Vf[qp1 - 1].re = -rt - 0.0 * nrm;
                    Vf[qp1 - 1].im = -nrm + 0.0 * rt;
                }
            }

            qp1 = q + 1;

            while ((q + 1 < 3) && (b_s[q].re < b_s[qp1].re)) {
                rt = b_s[q].re;
                b_s[q].re = b_s[qp1].re;
                b_s[q].im = 0.0;
                b_s[qp1].re = rt;
                b_s[qp1].im = 0.0;
                xswap(Vf, 1 + 3 * q, 1 + 3 * (q + 1));
                xswap(U, 1 + 3 * q, 1 + 3 * (q + 1));
                q = qp1;
                qp1++;
            }

            qq = 0;
            m--;
            break;
        }
    }

    for (qp1 = 0; qp1 < 3; qp1++) {
        s[qp1] = b_s[qp1].re;
        V[3 * qp1] = Vf[3 * qp1];
        kase = 1 + 3 * qp1;
        V[kase] = Vf[kase];
        kase = 2 + 3 * qp1;
        V[kase] = Vf[kase];
    }
}

/*
 * Arguments    : int n
 *                const creal_T a
 *                int ix0
 *                creal_T y[9]
 *                int iy0
 * Return Type  : void
 */
static void xaxpy(int n, const creal_T a, int ix0, creal_T y[9], int iy0)
{
    int ix;
    int iy;
    int i14;
    int k;
    double a_im;

    if ((n < 1) || ((a.re == 0.0) && (a.im == 0.0))) {
    } else {
        ix = ix0 - 1;
        iy = iy0 - 1;
        i14 = n - 1;

        for (k = 0; k <= i14; k++) {
            a_im = a.re * y[ix].im + a.im * y[ix].re;
            y[iy].re += a.re * y[ix].re - a.im * y[ix].im;
            y[iy].im += a_im;
            ix++;
            iy++;
        }
    }
}

/*
 * Arguments    : double *a
 *                double *b
 *                double *c
 *                double *d
 *                double *rt1r
 *                double *rt1i
 *                double *rt2r
 *                double *rt2i
 *                double *cs
 *                double *sn
 * Return Type  : void
 */
static void xdlanv2(double* a, double* b, double* c, double* d, double* rt1r,
                    double* rt1i, double* rt2r, double* rt2i, double* cs, double* sn)
{
    double tau;
    double p;
    double z;
    double scale;
    double bcmis;
    double bcmax;
    double b_scale;
    int b_b;
    int b_c;
    double b_p;
    int c_scale;

    if (*c == 0.0) {
        *cs = 1.0;
        *sn = 0.0;
    } else if (*b == 0.0) {
        *cs = 0.0;
        *sn = 1.0;
        z = *d;
        *d = *a;
        *a = z;
        *b = -*c;
        *c = 0.0;
    } else {
        tau = *a - *d;

        if ((tau == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
            *cs = 1.0;
            *sn = 0.0;
        } else {
            p = 0.5 * tau;
            scale = fabs(*b);
            bcmis = fabs(*c);

            if ((scale > bcmis) || rtIsNaN_(bcmis)) {
                bcmax = scale;
            } else {
                bcmax = bcmis;
            }

            if ((scale < bcmis) || rtIsNaN_(bcmis)) {
                b_scale = scale;
            } else {
                b_scale = bcmis;
            }

            if (!(*b < 0.0)) {
                b_b = 1;
            } else {
                b_b = -1;
            }

            if (!(*c < 0.0)) {
                b_c = 1;
            } else {
                b_c = -1;
            }

            bcmis = b_scale * (double)b_b * (double)b_c;
            scale = fabs(p);

            if ((scale > bcmax) || rtIsNaN_(bcmax)) {
            } else {
                scale = bcmax;
            }

            z = p / scale * p + bcmax / scale * bcmis;

            if (z >= 8.8817841970012523E-16) {
                *a = sqrt(scale) * sqrt(z);

                if (!(p < 0.0)) {
                    b_p = *a;
                } else {
                    b_p = -*a;
                }

                z = p + b_p;
                *a = *d + z;
                *d -= bcmax / z * bcmis;
                tau = rt_hypotd_snf(*c, z);
                *cs = z / tau;
                *sn = *c / tau;
                *b -= *c;
                *c = 0.0;
            } else {
                scale = *b + *c;
                tau = rt_hypotd_snf(scale, tau);
                *cs = sqrt(0.5 * (1.0 + fabs(scale) / tau));

                if (!(scale < 0.0)) {
                    c_scale = 1;
                } else {
                    c_scale = -1;
                }

                *sn = -(p / (tau * *cs)) * (double)c_scale;
                bcmax = *a * *cs + *b * *sn;
                bcmis = -*a * *sn + *b * *cs;
                z = *c * *cs + *d * *sn;
                scale = -*c * *sn + *d * *cs;
                *b = bcmis * *cs + scale * *sn;
                *c = -bcmax * *sn + z * *cs;
                z = 0.5 * ((bcmax * *cs + z * *sn) + (-bcmis * *sn + scale * *cs));
                *a = z;
                *d = z;

                if (*c != 0.0) {
                    if (*b != 0.0) {
                        if ((*b < 0.0) == (*c < 0.0)) {
                            scale = sqrt(fabs(*b));
                            bcmis = sqrt(fabs(*c));
                            *a = scale * bcmis;

                            if (!(*c < 0.0)) {
                                p = *a;
                            } else {
                                p = -*a;
                            }

                            tau = 1.0 / sqrt(fabs(*b + *c));
                            *a = z + p;
                            *d = z - p;
                            *b -= *c;
                            *c = 0.0;
                            bcmax = scale * tau;
                            scale = bcmis * tau;
                            z = *cs * bcmax - *sn * scale;
                            *sn = *cs * scale + *sn * bcmax;
                            *cs = z;
                        }
                    } else {
                        *b = -*c;
                        *c = 0.0;
                        z = *cs;
                        *cs = -*sn;
                        *sn = z;
                    }
                }
            }
        }
    }

    *rt1r = *a;
    *rt2r = *d;

    if (*c == 0.0) {
        *rt1i = 0.0;
        *rt2i = 0.0;
    } else {
        *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
        *rt2i = -*rt1i;
    }
}

/*
 * Arguments    : int n
 *                const creal_T x[9]
 *                int ix0
 *                const creal_T y[9]
 *                int iy0
 * Return Type  : creal_T
 */
static creal_T xdotc(int n, const creal_T x[9], int ix0, const creal_T y[9], int iy0)
{
    creal_T d;
    int ix;
    int iy;
    int k;
    d.re = 0.0;
    d.im = 0.0;

    if (n >= 1) {
        ix = ix0 - 1;
        iy = iy0 - 1;

        for (k = 0; k < n; k++) {
            d.re += x[ix].re * y[iy].re + x[ix].im * y[iy].im;
            d.im += x[ix].re * y[iy].im - x[ix].im * y[iy].re;
            ix++;
            iy++;
        }
    }

    return d;
}

/*
 * Arguments    : int m
 *                int n
 *                const double A[9]
 *                int ia0
 *                const double x[9]
 *                int ix0
 *                double y[3]
 * Return Type  : void
 */
static void xgemv(int m, int n, const double A[9], int ia0, const double x[9],
                  int ix0, double y[3])
{
    int iy;
    int i7;
    int iac;
    int ix;
    double c;
    int i8;
    int ia;

    if ((m == 0) || (n == 0)) {
    } else {
        if (0 <= n - 1) {
            memset(&y[0], 0, (unsigned int)(n * (int)sizeof(double)));
        }

        iy = 0;
        i7 = ia0 + 3 * (n - 1);

        for (iac = ia0; iac <= i7; iac += 3) {
            ix = ix0;
            c = 0.0;
            i8 = (iac + m) - 1;

            for (ia = iac; ia <= i8; ia++) {
                c += A[ia - 1] * x[ix - 1];
                ix++;
            }

            y[iy] += c;
            iy++;
        }
    }
}

/*
 * Arguments    : int m
 *                int n
 *                double alpha1
 *                int ix0
 *                const double y[3]
 *                double A[9]
 *                int ia0
 * Return Type  : void
 */
static void xgerc(int m, int n, double alpha1, int ix0, const double y[3],
                  double A[9], int ia0)
{
    int jA;
    int jy;
    int j;
    double temp;
    int ix;
    int i9;
    int i10;
    int ijA;

    if (!(alpha1 == 0.0)) {
        jA = ia0 - 1;
        jy = 0;

        for (j = 0; j < n; j++) {
            if (y[jy] != 0.0) {
                temp = y[jy] * alpha1;
                ix = ix0;
                i9 = jA + 1;
                i10 = m + jA;

                for (ijA = i9; ijA <= i10; ijA++) {
                    A[ijA - 1] += A[ix - 1] * temp;
                    ix++;
                }
            }

            jy++;
            jA += 3;
        }
    }
}

/*
 * Arguments    : double h[9]
 *                double z[9]
 * Return Type  : int
 */
static int xhseqr(double h[9], double z[9])
{
    int info;
    double v[3];
    int i;
    boolean_T exitg1;
    int L;
    boolean_T goto150;
    int its;
    boolean_T exitg2;
    int k;
    boolean_T exitg3;
    double d1;
    double s;
    double tst;
    int i11;
    double aa;
    double ab;
    double bb;
    double ba;
    double h22;
    double rt1r;
    int nr;
    int iy;
    int ix;
    int m;
    double d2;
    int j;
    info = 0;
    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 0.0;
    h[2] = 0.0;
    i = 2;
    exitg1 = false;

    while ((!exitg1) && (i + 1 >= 1)) {
        L = 1;
        goto150 = false;
        its = 0;
        exitg2 = false;

        while ((!exitg2) && (its < 301)) {
            k = i;
            exitg3 = false;

            while ((!exitg3) && (k + 1 > L)) {
                i11 = k + 3 * (k - 1);
                ba = fabs(h[i11]);

                if (ba <= 3.0062525400134592E-292) {
                    exitg3 = true;
                } else {
                    nr = k + 3 * k;
                    bb = fabs(h[nr]);
                    aa = h[i11 - 1];
                    tst = fabs(aa) + bb;

                    if (tst == 0.0) {
                        if (k - 1 >= 1) {
                            tst = fabs(h[(k + 3 * (k - 2)) - 1]);
                        }

                        if (k + 2 <= 3) {
                            tst += fabs(h[nr + 1]);
                        }
                    }

                    if (ba <= 2.2204460492503131E-16 * tst) {
                        tst = fabs(h[nr - 1]);

                        if (ba > tst) {
                            ab = ba;
                            ba = tst;
                        } else {
                            ab = tst;
                        }

                        tst = fabs(aa - h[k + 3 * k]);

                        if (bb > tst) {
                            aa = bb;
                            bb = tst;
                        } else {
                            aa = tst;
                        }

                        s = aa + ab;
                        tst = 2.2204460492503131E-16 * (bb * (aa / s));

                        if ((3.0062525400134592E-292 > tst) || rtIsNaN_(tst)) {
                            d2 = 3.0062525400134592E-292;
                        } else {
                            d2 = tst;
                        }

                        if (ba * (ab / s) <= d2) {
                            exitg3 = true;
                        } else {
                            k--;
                        }
                    } else {
                        k--;
                    }
                }
            }

            L = k + 1;

            if (k + 1 > 1) {
                h[k + 3 * (k - 1)] = 0.0;
            }

            if (k + 1 >= i) {
                goto150 = true;
                exitg2 = true;
            } else {
                if (its == 10) {
                    s = fabs(h[1]) + fabs(h[5]);
                    tst = 0.75 * s + h[0];
                    ab = -0.4375 * s;
                    aa = s;
                    h22 = tst;
                } else if (its == 20) {
                    s = fabs(h[i + 3 * (i - 1)]) + fabs(h[(i + 3 * (i - 2)) - 1]);
                    tst = 0.75 * s + h[i + 3 * i];
                    ab = -0.4375 * s;
                    aa = s;
                    h22 = tst;
                } else {
                    nr = i + 3 * (i - 1);
                    tst = h[nr - 1];
                    aa = h[nr];
                    nr = i + 3 * i;
                    ab = h[nr - 1];
                    h22 = h[nr];
                }

                s = ((fabs(tst) + fabs(ab)) + fabs(aa)) + fabs(h22);

                if (s == 0.0) {
                    rt1r = 0.0;
                    tst = 0.0;
                    ba = 0.0;
                    aa = 0.0;
                } else {
                    tst /= s;
                    aa /= s;
                    ab /= s;
                    h22 /= s;
                    bb = (tst + h22) / 2.0;
                    tst = (tst - bb) * (h22 - bb) - ab * aa;
                    aa = fabs(tst);
                    b_sqrt(&aa);

                    if (tst >= 0.0) {
                        rt1r = bb * s;
                        ba = rt1r;
                        tst = aa * s;
                        aa = -tst;
                    } else {
                        rt1r = bb + aa;
                        ba = bb - aa;

                        if (fabs(rt1r - h22) <= fabs(ba - h22)) {
                            rt1r *= s;
                            ba = rt1r;
                        } else {
                            ba *= s;
                            rt1r = ba;
                        }

                        tst = 0.0;
                        aa = 0.0;
                    }
                }

                m = i - 1;

                if (i - 1 >= 1) {
                    ab = h[0] - ba;
                    s = (fabs(ab) + fabs(aa)) + fabs(h[1]);
                    bb = h[1] / s;
                    v[0] = (bb * h[3] + (h[0] - rt1r) * (ab / s)) - tst * (aa / s);
                    v[1] = bb * (((h[0] + h[4]) - rt1r) - ba);
                    v[2] = bb * h[5];
                    s = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
                    v[0] /= s;
                    v[1] /= s;
                    v[2] /= s;
                }

                for (k = m; k <= i; k++) {
                    nr = (i - k) + 2;

                    if (3 < nr) {
                        nr = 3;
                    }

                    if (k > i - 1) {
                        ix = (k + 3 * (k - 2)) - 1;

                        for (j = 0; j < nr; j++) {
                            v[j] = h[j + ix];
                        }
                    }

                    tst = v[0];
                    bb = xzlarfg(nr, &tst, v);
                    v[0] = tst;

                    if (k > i - 1) {
                        h[(k + 3 * (k - 2)) - 1] = tst;
                        h[k + 3 * (k - 2)] = 0.0;

                        if (k < i) {
                            h[(k + 3 * (k - 2)) + 1] = 0.0;
                        }
                    }

                    d1 = v[1];
                    aa = bb * v[1];

                    if (nr == 3) {
                        s = v[2];
                        tst = bb * v[2];

                        for (j = k; j < 4; j++) {
                            nr = k + 3 * (j - 1);
                            ix = nr - 1;
                            iy = nr + 1;
                            ab = (h[ix] + d1 * h[nr]) + s * h[iy];
                            h[ix] -= ab * bb;
                            h[nr] -= ab * aa;
                            h[iy] -= ab * tst;
                        }

                        if (k + 3 < i + 1) {
                            i11 = k + 2;
                        } else {
                            i11 = i;
                        }

                        for (j = 0; j <= i11; j++) {
                            nr = j + 3 * (k - 1);
                            ix = j + 3 * k;
                            iy = j + 3 * (k + 1);
                            ab = (h[nr] + d1 * h[ix]) + s * h[iy];
                            h[nr] -= ab * bb;
                            h[ix] -= ab * aa;
                            h[iy] -= ab * tst;
                        }

                        for (j = 0; j < 3; j++) {
                            nr = j + 3 * (k - 1);
                            ix = j + 3 * k;
                            iy = j + 3 * (k + 1);
                            ab = (z[nr] + d1 * z[ix]) + s * z[iy];
                            z[nr] -= ab * bb;
                            z[ix] -= ab * aa;
                            z[iy] -= ab * tst;
                        }
                    } else {
                        if (nr == 2) {
                            for (j = k; j < 4; j++) {
                                nr = k + 3 * (j - 1);
                                ix = nr - 1;
                                tst = h[ix];
                                ab = tst + d1 * h[nr];
                                h[ix] = tst - ab * bb;
                                h[nr] -= ab * aa;
                            }

                            for (j = 0; j <= i; j++) {
                                nr = j + 3 * (k - 1);
                                ix = j + 3 * k;
                                ab = h[nr] + d1 * h[ix];
                                h[nr] -= ab * bb;
                                h[ix] -= ab * aa;
                            }

                            for (j = 0; j < 3; j++) {
                                ix = j + 3 * (k - 1);
                                tst = z[ix];
                                nr = j + 3 * k;
                                ab = tst + d1 * z[nr];
                                z[ix] = tst - ab * bb;
                                z[nr] -= ab * aa;
                            }
                        }
                    }
                }

                its++;
            }
        }

        if (!goto150) {
            info = i + 1;
            exitg1 = true;
        } else {
            if ((L != i + 1) && (L == i)) {
                d1 = h[(i + 3 * i) - 1];
                s = h[i + 3 * (i - 1)];
                tst = h[i + 3 * i];
                xdlanv2(&h[(i + 3 * (i - 1)) - 1], &d1, &s, &tst, &aa, &ab, &bb, &ba, &h22, &rt1r);
                h[(i + 3 * i) - 1] = d1;
                h[i + 3 * (i - 1)] = s;
                h[i + 3 * i] = tst;

                if (3 > i + 1) {
                    nr = 1 - i;
                    iy = i + (i + 1) * 3;
                    ix = iy - 1;

                    for (k = 0; k <= nr; k++) {
                        tst = h22 * h[ix] + rt1r * h[iy];
                        h[iy] = h22 * h[iy] - rt1r * h[ix];
                        h[ix] = tst;
                        iy += 3;
                        ix += 3;
                    }
                }

                if (i - 1 >= 1) {
                    ix = (i - 1) * 3;
                    iy = i * 3;

                    for (k = 0; k <= i - 2; k++) {
                        tst = h22 * h[ix] + rt1r * h[iy];
                        h[iy] = h22 * h[iy] - rt1r * h[ix];
                        h[ix] = tst;
                        iy++;
                        ix++;
                    }
                }

                i11 = (i - 1) * 3;
                iy = i * 3;
                tst = h22 * z[i11] + rt1r * z[iy];
                z[iy] = h22 * z[iy] - rt1r * z[i11];
                z[i11] = tst;
                iy++;
                ix = i11 + 1;
                tst = h22 * z[ix] + rt1r * z[iy];
                z[iy] = h22 * z[iy] - rt1r * z[ix];
                z[ix] = tst;
                iy++;
                ix++;
                tst = h22 * z[ix] + rt1r * z[iy];
                z[iy] = h22 * z[iy] - rt1r * z[ix];
                z[ix] = tst;
            }

            i = L - 2;
        }
    }

    return info;
}

/*
 * Arguments    : int n
 *                const double x[9]
 *                int ix0
 * Return Type  : double
 */
static double xnrm2(int n, const double x[9], int ix0)
{
    double y;
    double scale;
    int kend;
    int k;
    double absxk;
    double t;
    y = 0.0;

    if (n >= 1) {
        if (n == 1) {
            y = fabs(x[ix0 - 1]);
        } else {
            scale = 3.3121686421112381E-170;
            kend = (ix0 + n) - 1;

            for (k = ix0; k <= kend; k++) {
                absxk = fabs(x[k - 1]);

                if (absxk > scale) {
                    t = scale / absxk;
                    y = 1.0 + y * t * t;
                    scale = absxk;
                } else {
                    t = absxk / scale;
                    y += t * t;
                }
            }

            y = scale * sqrt(y);
        }
    }

    return y;
}

/*
 * Arguments    : creal_T x[9]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
static void xrot(creal_T x[9], int ix0, int iy0, double c, double s)
{
    int ix;
    int iy;
    double temp_re;
    double temp_im;
    double s_im;
    ix = ix0 - 1;
    iy = iy0 - 1;
    temp_re = c * x[ix].re + (s * x[iy].re - 0.0 * x[iy].im);
    temp_im = c * x[ix].im + (s * x[iy].im + 0.0 * x[iy].re);
    s_im = s * x[ix].im + 0.0 * x[ix].re;
    x[iy].re = c * x[iy].re - (s * x[ix].re - 0.0 * x[ix].im);
    x[iy].im = c * x[iy].im - s_im;
    x[ix].re = temp_re;
    x[ix].im = temp_im;
    iy++;
    ix++;
    temp_re = c * x[ix].re + (s * x[iy].re - 0.0 * x[iy].im);
    temp_im = c * x[ix].im + (s * x[iy].im + 0.0 * x[iy].re);
    s_im = s * x[ix].im + 0.0 * x[ix].re;
    x[iy].re = c * x[iy].re - (s * x[ix].re - 0.0 * x[ix].im);
    x[iy].im = c * x[iy].im - s_im;
    x[ix].re = temp_re;
    x[ix].im = temp_im;
    iy++;
    ix++;
    temp_re = c * x[ix].re + (s * x[iy].re - 0.0 * x[iy].im);
    temp_im = c * x[ix].im + (s * x[iy].im + 0.0 * x[iy].re);
    s_im = s * x[ix].im + 0.0 * x[ix].re;
    x[iy].re = c * x[iy].re - (s * x[ix].re - 0.0 * x[ix].im);
    x[iy].im = c * x[iy].im - s_im;
    x[ix].re = temp_re;
    x[ix].im = temp_im;
}

/*
 * Arguments    : double *a
 *                double *b
 *                double *c
 *                double *s
 * Return Type  : void
 */
static void xrotg(double* a, double* b, double* c, double* s)
{
    double roe;
    double absa;
    double absb;
    double scale;
    double ads;
    double bds;
    roe = *b;
    absa = fabs(*a);
    absb = fabs(*b);

    if (absa > absb) {
        roe = *a;
    }

    scale = absa + absb;

    if (scale == 0.0) {
        *s = 0.0;
        *c = 1.0;
        *a = 0.0;
        *b = 0.0;
    } else {
        ads = absa / scale;
        bds = absb / scale;
        scale *= sqrt(ads * ads + bds * bds);

        if (roe < 0.0) {
            scale = -scale;
        }

        *c = *a / scale;
        *s = *b / scale;

        if (absa > absb) {
            *b = *s;
        } else if (*c != 0.0) {
            *b = 1.0 / *c;
        } else {
            *b = 1.0;
        }

        *a = scale;
    }
}

/*
 * Arguments    : creal_T x[9]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
static void xswap(creal_T x[9], int ix0, int iy0)
{
    int ix;
    int iy;
    double temp_re;
    double temp_im;
    ix = ix0 - 1;
    iy = iy0 - 1;
    temp_re = x[ix].re;
    temp_im = x[ix].im;
    x[ix] = x[iy];
    x[iy].re = temp_re;
    x[iy].im = temp_im;
    ix++;
    iy++;
    temp_re = x[ix].re;
    temp_im = x[ix].im;
    x[ix] = x[iy];
    x[iy].re = temp_re;
    x[iy].im = temp_im;
    ix++;
    iy++;
    temp_re = x[ix].re;
    temp_im = x[ix].im;
    x[ix] = x[iy];
    x[iy].re = temp_re;
    x[iy].im = temp_im;
}

/*
 * Arguments    : creal_T A[9]
 *                int *info
 *                creal_T alpha1[3]
 *                creal_T beta1[3]
 *                creal_T V[9]
 * Return Type  : void
 */
static void xzggev(creal_T A[9], int* info, creal_T alpha1[3], creal_T beta1[3],
                   creal_T V[9])
{
    double absxk;
    double SMLNUM;
    double BIGNUM;
    double anrm;
    int jcol;
    boolean_T exitg1;
    boolean_T ilascl;
    double anrmto;
    int rscale[3];
    boolean_T notdone;
    int ilo;
    int ihi;
    double cfrom1;
    int jcolp1;
    double stemp_re;
    int exitg3;
    int i;
    double stemp_im;
    int j;
    int ii;
    int nzcount;
    creal_T atmp;
    boolean_T exitg4;
    int exitg2;
    signed char b_I[9];
    int jrow;
    *info = 0;
    absxk = 2.2250738585072014E-308;
    b_sqrt(&absxk);
    SMLNUM = absxk / 2.2204460492503131E-16;
    BIGNUM = 1.0 / SMLNUM;
    anrm = 0.0;
    jcol = 0;
    exitg1 = false;

    while ((!exitg1) && (jcol < 9)) {
        absxk = rt_hypotd_snf(A[jcol].re, A[jcol].im);

        if (rtIsNaN_(absxk)) {
            anrm = rtNaN;
            exitg1 = true;
        } else {
            if (absxk > anrm) {
                anrm = absxk;
            }

            jcol++;
        }
    }

    if (rtIsInf_(anrm) || rtIsNaN_(anrm)) {
        alpha1[0].re = rtNaN;
        alpha1[0].im = 0.0;
        beta1[0].re = rtNaN;
        beta1[0].im = 0.0;
        alpha1[1].re = rtNaN;
        alpha1[1].im = 0.0;
        beta1[1].re = rtNaN;
        beta1[1].im = 0.0;
        alpha1[2].re = rtNaN;
        alpha1[2].im = 0.0;
        beta1[2].re = rtNaN;
        beta1[2].im = 0.0;

        for (jcolp1 = 0; jcolp1 < 9; jcolp1++) {
            V[jcolp1].re = rtNaN;
            V[jcolp1].im = 0.0;
        }
    } else {
        ilascl = false;
        anrmto = anrm;

        if ((anrm > 0.0) && (anrm < SMLNUM)) {
            anrmto = SMLNUM;
            ilascl = true;
        } else {
            if (anrm > BIGNUM) {
                anrmto = BIGNUM;
                ilascl = true;
            }
        }

        if (ilascl) {
            absxk = anrm;
            BIGNUM = anrmto;
            notdone = true;

            while (notdone) {
                cfrom1 = absxk * 2.0041683600089728E-292;
                stemp_re = BIGNUM / 4.9896007738368E+291;

                if ((cfrom1 > fabs(BIGNUM)) && (BIGNUM != 0.0)) {
                    stemp_im = 2.0041683600089728E-292;
                    absxk = cfrom1;
                } else if (fabs(stemp_re) > absxk) {
                    stemp_im = 4.9896007738368E+291;
                    BIGNUM = stemp_re;
                } else {
                    stemp_im = BIGNUM / absxk;
                    notdone = false;
                }

                for (jcolp1 = 0; jcolp1 < 9; jcolp1++) {
                    A[jcolp1].re *= stemp_im;
                    A[jcolp1].im *= stemp_im;
                }
            }
        }

        rscale[0] = 1;
        rscale[1] = 1;
        rscale[2] = 1;
        ilo = 1;
        ihi = 3;

        do {
            exitg3 = 0;
            i = 0;
            j = -1;
            notdone = false;
            ii = ihi;
            exitg1 = false;

            while ((!exitg1) && (ii > 0)) {
                nzcount = 0;
                i = ii;
                j = ihi - 1;
                jcol = 0;
                exitg4 = false;

                while ((!exitg4) && (jcol <= ihi - 1)) {
                    if ((A[(ii + 3 * jcol) - 1].re != 0.0) || (A[(ii + 3 * jcol) - 1].im != 0.0) || (ii == jcol + 1)) {
                        if (nzcount == 0) {
                            j = jcol;
                            nzcount = 1;
                            jcol++;
                        } else {
                            nzcount = 2;
                            exitg4 = true;
                        }
                    } else {
                        jcol++;
                    }
                }

                if (nzcount < 2) {
                    notdone = true;
                    exitg1 = true;
                } else {
                    ii--;
                }
            }

            if (!notdone) {
                exitg3 = 2;
            } else {
                if (i != ihi) {
                    atmp = A[i - 1];
                    A[i - 1] = A[ihi - 1];
                    A[ihi - 1] = atmp;
                    atmp = A[i + 2];
                    A[i + 2] = A[ihi + 2];
                    A[ihi + 2] = atmp;
                    atmp = A[i + 5];
                    A[i + 5] = A[ihi + 5];
                    A[ihi + 5] = atmp;
                }

                if (j + 1 != ihi) {
                    for (jcol = 0; jcol < ihi; jcol++) {
                        ii = jcol + 3 * j;
                        atmp = A[ii];
                        jcolp1 = jcol + 3 * (ihi - 1);
                        A[ii] = A[jcolp1];
                        A[jcolp1] = atmp;
                    }
                }

                rscale[ihi - 1] = j + 1;
                ihi--;

                if (ihi == 1) {
                    rscale[0] = 1;
                    exitg3 = 1;
                }
            }
        } while (exitg3 == 0);

        if (exitg3 == 1) {
        } else {
            do {
                exitg2 = 0;
                i = 0;
                j = 0;
                notdone = false;
                jcol = ilo;
                exitg1 = false;

                while ((!exitg1) && (jcol <= ihi)) {
                    nzcount = 0;
                    i = ihi;
                    j = jcol;
                    ii = ilo;
                    exitg4 = false;

                    while ((!exitg4) && (ii <= ihi)) {
                        if ((A[(ii + 3 * (jcol - 1)) - 1].re != 0.0) || (A[(ii + 3 * (jcol - 1)) - 1].im != 0.0) || (ii == jcol)) {
                            if (nzcount == 0) {
                                i = ii;
                                nzcount = 1;
                                ii++;
                            } else {
                                nzcount = 2;
                                exitg4 = true;
                            }
                        } else {
                            ii++;
                        }
                    }

                    if (nzcount < 2) {
                        notdone = true;
                        exitg1 = true;
                    } else {
                        jcol++;
                    }
                }

                if (!notdone) {
                    exitg2 = 1;
                } else {
                    if (i != ilo) {
                        for (jcol = ilo; jcol < 4; jcol++) {
                            ii = 3 * (jcol - 1);
                            nzcount = (i + ii) - 1;
                            atmp = A[nzcount];
                            jcolp1 = (ilo + ii) - 1;
                            A[nzcount] = A[jcolp1];
                            A[jcolp1] = atmp;
                        }
                    }

                    if (j != ilo) {
                        for (jcol = 0; jcol < ihi; jcol++) {
                            ii = jcol + 3 * (j - 1);
                            atmp = A[ii];
                            jcolp1 = jcol + 3 * (ilo - 1);
                            A[ii] = A[jcolp1];
                            A[jcolp1] = atmp;
                        }
                    }

                    rscale[ilo - 1] = j;
                    ilo++;

                    if (ilo == ihi) {
                        rscale[ilo - 1] = ilo;
                        exitg2 = 1;
                    }
                }
            } while (exitg2 == 0);
        }

        for (jcolp1 = 0; jcolp1 < 9; jcolp1++) {
            b_I[jcolp1] = 0;
        }

        b_I[0] = 1;
        b_I[4] = 1;
        b_I[8] = 1;

        for (jcolp1 = 0; jcolp1 < 9; jcolp1++) {
            V[jcolp1].re = b_I[jcolp1];
            V[jcolp1].im = 0.0;
        }

        if (ihi >= ilo + 2) {
            for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
                jcolp1 = jcol + 2;

                for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
                    ii = jrow + 3 * jcol;
                    xzlartg(A[ii - 1], A[ii], &cfrom1, &atmp, &A[(jrow + 3 * jcol) - 1]);
                    A[ii].re = 0.0;
                    A[ii].im = 0.0;

                    for (j = jcolp1; j < 4; j++) {
                        ii = jrow + 3 * (j - 1);
                        nzcount = ii - 1;
                        stemp_re = cfrom1 * A[nzcount].re + (atmp.re * A[ii].re - atmp.im * A[jrow + 3 * (j - 1)].im);
                        stemp_im = cfrom1 * A[(jrow + 3 * (j - 1)) - 1].im + (atmp.re * A[jrow + 3 * (j - 1)].im + atmp.im * A[jrow + 3 * (j - 1)].re);
                        absxk = A[(jrow + 3 * (j - 1)) - 1].im;
                        BIGNUM = A[(jrow + 3 * (j - 1)) - 1].re;
                        A[ii].re = cfrom1 * A[jrow + 3 * (j - 1)].re - (atmp.re * A[(jrow + 3 * (j - 1)) - 1].re + atmp.im * A[(jrow + 3 * (j - 1)) - 1].im);
                        A[ii].im = cfrom1 * A[jrow + 3 * (j - 1)].im - (atmp.re * absxk - atmp.im * BIGNUM);
                        A[nzcount].re = stemp_re;
                        A[nzcount].im = stemp_im;
                    }

                    atmp.re = -atmp.re;
                    atmp.im = -atmp.im;

                    for (i = 1; i <= ihi; i++) {
                        ii = (i + 3 * (jrow - 1)) - 1;
                        nzcount = (i + 3 * jrow) - 1;
                        stemp_re = cfrom1 * A[nzcount].re + (atmp.re * A[ii].re - atmp.im * A[(i + 3 * (jrow - 1)) - 1].im);
                        stemp_im = cfrom1 * A[(i + 3 * jrow) - 1].im + (atmp.re * A[(i + 3 * (jrow - 1)) - 1].im + atmp.im * A[(i + 3 * (jrow - 1)) - 1].re);
                        absxk = A[(i + 3 * jrow) - 1].im;
                        BIGNUM = A[(i + 3 * jrow) - 1].re;
                        A[ii].re = cfrom1 * A[(i + 3 * (jrow - 1)) - 1].re - (atmp.re * A[(i + 3 * jrow) - 1].re + atmp.im * A[(i + 3 * jrow) - 1].im);
                        A[ii].im = cfrom1 * A[(i + 3 * (jrow - 1)) - 1].im - (atmp.re * absxk - atmp.im * BIGNUM);
                        A[nzcount].re = stemp_re;
                        A[nzcount].im = stemp_im;
                    }

                    stemp_re = cfrom1 * V[3 * jrow].re + (atmp.re * V[3 * (jrow - 1)].re - atmp.im * V[3 * (jrow - 1)].im);
                    stemp_im = cfrom1 * V[3 * jrow].im + (atmp.re * V[3 * (jrow - 1)].im + atmp.im * V[3 * (jrow - 1)].re);
                    absxk = V[3 * jrow].re;
                    V[3 * (jrow - 1)].re = cfrom1 * V[3 * (jrow - 1)].re - (atmp.re * V[3 * jrow].re + atmp.im * V[3 * jrow].im);
                    V[3 * (jrow - 1)].im = cfrom1 * V[3 * (jrow - 1)].im - (atmp.re * V[3 * jrow].im - atmp.im * absxk);
                    V[3 * jrow].re = stemp_re;
                    V[3 * jrow].im = stemp_im;
                    ii = 1 + 3 * (jrow - 1);
                    nzcount = 1 + 3 * jrow;
                    stemp_re = cfrom1 * V[nzcount].re + (atmp.re * V[ii].re - atmp.im * V[1 + 3 * (jrow - 1)].im);
                    stemp_im = cfrom1 * V[1 + 3 * jrow].im + (atmp.re * V[1 + 3 * (jrow - 1)].im + atmp.im * V[1 + 3 * (jrow - 1)].re);
                    absxk = V[1 + 3 * jrow].re;
                    V[ii].re = cfrom1 * V[1 + 3 * (jrow - 1)].re - (atmp.re * V[1 + 3 * jrow].re + atmp.im * V[1 + 3 * jrow].im);
                    V[ii].im = cfrom1 * V[ii].im - (atmp.re * V[1 + 3 * jrow].im - atmp.im * absxk);
                    V[nzcount].re = stemp_re;
                    V[nzcount].im = stemp_im;
                    ii = 2 + 3 * (jrow - 1);
                    nzcount = 2 + 3 * jrow;
                    stemp_re = cfrom1 * V[nzcount].re + (atmp.re * V[ii].re - atmp.im * V[2 + 3 * (jrow - 1)].im);
                    stemp_im = cfrom1 * V[2 + 3 * jrow].im + (atmp.re * V[2 + 3 * (jrow - 1)].im + atmp.im * V[2 + 3 * (jrow - 1)].re);
                    absxk = V[2 + 3 * jrow].re;
                    V[ii].re = cfrom1 * V[2 + 3 * (jrow - 1)].re - (atmp.re * V[2 + 3 * jrow].re + atmp.im * V[2 + 3 * jrow].im);
                    V[ii].im = cfrom1 * V[ii].im - (atmp.re * V[2 + 3 * jrow].im - atmp.im * absxk);
                    V[nzcount].re = stemp_re;
                    V[nzcount].im = stemp_im;
                }
            }
        }

        xzhgeqz(A, ilo, ihi, V, info, alpha1, beta1);

        if (*info == 0) {
            xztgevc(A, V);

            if (ilo > 1) {
                for (i = ilo - 2; i + 1 >= 1; i--) {
                    jcol = rscale[i] - 1;

                    if (rscale[i] != i + 1) {
                        atmp = V[i];
                        V[i] = V[jcol];
                        V[jcol] = atmp;
                        atmp = V[i + 3];
                        V[i + 3] = V[jcol + 3];
                        V[jcol + 3] = atmp;
                        atmp = V[i + 6];
                        V[i + 6] = V[jcol + 6];
                        V[jcol + 6] = atmp;
                    }
                }
            }

            if (ihi < 3) {
                jcolp1 = ihi + 1;

                for (i = jcolp1; i < 4; i++) {
                    ii = rscale[i - 1];

                    if (ii != i) {
                        atmp = V[i - 1];
                        V[i - 1] = V[ii - 1];
                        V[ii - 1] = atmp;
                        atmp = V[i + 2];
                        V[i + 2] = V[ii + 2];
                        V[ii + 2] = atmp;
                        atmp = V[i + 5];
                        V[i + 5] = V[ii + 5];
                        V[ii + 5] = atmp;
                    }
                }
            }

            for (ii = 0; ii < 3; ii++) {
                absxk = fabs(V[3 * ii].re) + fabs(V[3 * ii].im);
                BIGNUM = fabs(V[3 * ii + 1].re) + fabs(V[3 * ii + 1].im);

                if (BIGNUM > absxk) {
                    absxk = BIGNUM;
                }

                BIGNUM = fabs(V[3 * ii + 2].re) + fabs(V[3 * ii + 2].im);

                if (BIGNUM > absxk) {
                    absxk = BIGNUM;
                }

                if (absxk >= SMLNUM) {
                    absxk = 1.0 / absxk;
                    V[3 * ii].re *= absxk;
                    V[3 * ii].im *= absxk;
                    jcolp1 = 1 + 3 * ii;
                    V[jcolp1].re *= absxk;
                    V[jcolp1].im *= absxk;
                    jcolp1 = 2 + 3 * ii;
                    V[jcolp1].re *= absxk;
                    V[jcolp1].im *= absxk;
                }
            }

            if (ilascl) {
                notdone = true;

                while (notdone) {
                    cfrom1 = anrmto * 2.0041683600089728E-292;
                    stemp_re = anrm / 4.9896007738368E+291;

                    if ((fabs(cfrom1) > anrm) && (anrm != 0.0)) {
                        stemp_im = 2.0041683600089728E-292;
                        anrmto = cfrom1;
                    } else if (stemp_re > fabs(anrmto)) {
                        stemp_im = 4.9896007738368E+291;
                        anrm = stemp_re;
                    } else {
                        stemp_im = anrm / anrmto;
                        notdone = false;
                    }

                    alpha1[0].re *= stemp_im;
                    alpha1[0].im *= stemp_im;
                    alpha1[1].re *= stemp_im;
                    alpha1[1].im *= stemp_im;
                    alpha1[2].re *= stemp_im;
                    alpha1[2].im *= stemp_im;
                }
            }
        }
    }
}

/*
 * Arguments    : creal_T A[9]
 *                int ilo
 *                int ihi
 *                creal_T Z[9]
 *                int *info
 *                creal_T alpha1[3]
 *                creal_T beta1[3]
 * Return Type  : void
 */
static void xzhgeqz(creal_T A[9], int ilo, int ihi, creal_T Z[9], int* info,
                    creal_T alpha1[3], creal_T beta1[3])
{
    double eshift_re;
    double eshift_im;
    creal_T ctemp;
    double anorm;
    double temp;
    double b_atol;
    double ascale;
    boolean_T failed;
    int jp1;
    int j;
    boolean_T guard1 = false;
    boolean_T guard2 = false;
    int ifirst;
    int istart;
    int ilast;
    int ilastm1;
    int iiter;
    boolean_T goto60;
    boolean_T goto70;
    boolean_T goto90;
    int jiter;
    int exitg1;
    boolean_T b_guard1 = false;
    boolean_T guard3 = false;
    boolean_T exitg2;
    creal_T b_ascale;
    double tempr;
    creal_T shift;
    double ascale_re;
    double ascale_im;
    int A_tmp;
    double stemp_re;
    double stemp_im;
    int shift_re_tmp;
    int stemp_re_tmp;
    double t1_re;
    double t1_im;
    *info = 0;
    alpha1[0].re = 0.0;
    alpha1[0].im = 0.0;
    beta1[0].re = 1.0;
    beta1[0].im = 0.0;
    alpha1[1].re = 0.0;
    alpha1[1].im = 0.0;
    beta1[1].re = 1.0;
    beta1[1].im = 0.0;
    alpha1[2].re = 0.0;
    alpha1[2].im = 0.0;
    beta1[2].re = 1.0;
    beta1[2].im = 0.0;
    eshift_re = 0.0;
    eshift_im = 0.0;
    ctemp.re = 0.0;
    ctemp.im = 0.0;
    anorm = xzlanhs(A, ilo, ihi);
    temp = 2.2204460492503131E-16 * anorm;
    b_atol = 2.2250738585072014E-308;

    if (temp > 2.2250738585072014E-308) {
        b_atol = temp;
    }

    temp = 2.2250738585072014E-308;

    if (anorm > 2.2250738585072014E-308) {
        temp = anorm;
    }

    ascale = 1.0 / temp;
    failed = true;
    jp1 = ihi + 1;

    for (j = jp1; j < 4; j++) {
        alpha1[j - 1] = A[(j + 3 * (j - 1)) - 1];
    }

    guard1 = false;
    guard2 = false;

    if (ihi >= ilo) {
        ifirst = ilo;
        istart = ilo;
        ilast = ihi - 1;
        ilastm1 = ihi - 2;
        iiter = 0;
        goto60 = false;
        goto70 = false;
        goto90 = false;
        jiter = 0;

        do {
            exitg1 = 0;

            if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
                b_guard1 = false;

                if (ilast + 1 == ilo) {
                    goto60 = true;
                    b_guard1 = true;
                } else {
                    jp1 = ilast + 3 * ilastm1;

                    if (fabs(A[jp1].re) + fabs(A[ilast + 3 * ilastm1].im) <= b_atol) {
                        A[jp1].re = 0.0;
                        A[jp1].im = 0.0;
                        goto60 = true;
                        b_guard1 = true;
                    } else {
                        j = ilastm1;
                        guard3 = false;
                        exitg2 = false;

                        while ((!exitg2) && (j + 1 >= ilo)) {
                            if (j + 1 == ilo) {
                                guard3 = true;
                                exitg2 = true;
                            } else {
                                jp1 = j + 3 * (j - 1);

                                if (fabs(A[jp1].re) + fabs(A[j + 3 * (j - 1)].im) <= b_atol) {
                                    A[jp1].re = 0.0;
                                    A[jp1].im = 0.0;
                                    guard3 = true;
                                    exitg2 = true;
                                } else {
                                    j--;
                                    guard3 = false;
                                }
                            }
                        }

                        if (guard3) {
                            ifirst = j + 1;
                            goto70 = true;
                        }

                        if (goto70) {
                            b_guard1 = true;
                        } else {
                            alpha1[0].re = rtNaN;
                            alpha1[0].im = 0.0;
                            beta1[0].re = rtNaN;
                            beta1[0].im = 0.0;
                            alpha1[1].re = rtNaN;
                            alpha1[1].im = 0.0;
                            beta1[1].re = rtNaN;
                            beta1[1].im = 0.0;
                            alpha1[2].re = rtNaN;
                            alpha1[2].im = 0.0;
                            beta1[2].re = rtNaN;
                            beta1[2].im = 0.0;

                            for (jp1 = 0; jp1 < 9; jp1++) {
                                Z[jp1].re = rtNaN;
                                Z[jp1].im = 0.0;
                            }

                            *info = 1;
                            exitg1 = 1;
                        }
                    }
                }

                if (b_guard1) {
                    if (goto60) {
                        goto60 = false;
                        alpha1[ilast] = A[ilast + 3 * ilast];
                        ilast = ilastm1;
                        ilastm1--;

                        if (ilast + 1 < ilo) {
                            failed = false;
                            guard2 = true;
                            exitg1 = 1;
                        } else {
                            iiter = 0;
                            eshift_re = 0.0;
                            eshift_im = 0.0;
                            jiter++;
                        }
                    } else {
                        if (goto70) {
                            goto70 = false;
                            iiter++;

                            if (iiter - iiter / 10 * 10 != 0) {
                                anorm = ascale * A[ilastm1 + 3 * ilastm1].re;
                                temp = ascale * A[ilastm1 + 3 * ilastm1].im;

                                if (temp == 0.0) {
                                    shift.re = anorm / 0.57735026918962584;
                                    shift.im = 0.0;
                                } else if (anorm == 0.0) {
                                    shift.re = 0.0;
                                    shift.im = temp / 0.57735026918962584;
                                } else {
                                    shift.re = anorm / 0.57735026918962584;
                                    shift.im = temp / 0.57735026918962584;
                                }

                                anorm = ascale * A[ilast + 3 * ilast].re;
                                temp = ascale * A[ilast + 3 * ilast].im;

                                if (temp == 0.0) {
                                    stemp_re = anorm / 0.57735026918962584;
                                    stemp_im = 0.0;
                                } else if (anorm == 0.0) {
                                    stemp_re = 0.0;
                                    stemp_im = temp / 0.57735026918962584;
                                } else {
                                    stemp_re = anorm / 0.57735026918962584;
                                    stemp_im = temp / 0.57735026918962584;
                                }

                                t1_re = 0.5 * (shift.re + stemp_re);
                                t1_im = 0.5 * (shift.im + stemp_im);
                                anorm = ascale * A[ilastm1 + 3 * ilast].re;
                                temp = ascale * A[ilastm1 + 3 * ilast].im;

                                if (temp == 0.0) {
                                    ascale_re = anorm / 0.57735026918962584;
                                    ascale_im = 0.0;
                                } else if (anorm == 0.0) {
                                    ascale_re = 0.0;
                                    ascale_im = temp / 0.57735026918962584;
                                } else {
                                    ascale_re = anorm / 0.57735026918962584;
                                    ascale_im = temp / 0.57735026918962584;
                                }

                                anorm = ascale * A[ilast + 3 * ilastm1].re;
                                temp = ascale * A[ilast + 3 * ilastm1].im;

                                if (temp == 0.0) {
                                    tempr = anorm / 0.57735026918962584;
                                    anorm = 0.0;
                                } else if (anorm == 0.0) {
                                    tempr = 0.0;
                                    anorm = temp / 0.57735026918962584;
                                } else {
                                    tempr = anorm / 0.57735026918962584;
                                    anorm = temp / 0.57735026918962584;
                                }

                                temp = shift.re * stemp_im + shift.im * stemp_re;
                                shift.re = ((t1_re * t1_re - t1_im * t1_im) + (ascale_re * tempr - ascale_im * anorm)) - (shift.re * stemp_re - shift.im * stemp_im);
                                shift.im = ((t1_re * t1_im + t1_im * t1_re) + (ascale_re * anorm + ascale_im * tempr)) - temp;
                                c_sqrt(&shift);

                                if ((t1_re - stemp_re) * shift.re + (t1_im - stemp_im) * shift.im <= 0.0) {
                                    shift.re += t1_re;
                                    shift.im += t1_im;
                                } else {
                                    shift.re = t1_re - shift.re;
                                    shift.im = t1_im - shift.im;
                                }
                            } else {
                                temp = ascale * A[ilast + 3 * ilastm1].re;
                                anorm = ascale * A[ilast + 3 * ilastm1].im;

                                if (anorm == 0.0) {
                                    ascale_re = temp / 0.57735026918962584;
                                    ascale_im = 0.0;
                                } else if (temp == 0.0) {
                                    ascale_re = 0.0;
                                    ascale_im = anorm / 0.57735026918962584;
                                } else {
                                    ascale_re = temp / 0.57735026918962584;
                                    ascale_im = anorm / 0.57735026918962584;
                                }

                                eshift_re += ascale_re;
                                eshift_im += ascale_im;
                                shift.re = eshift_re;
                                shift.im = eshift_im;
                            }

                            j = ilastm1;
                            jp1 = ilastm1 + 1;
                            exitg2 = false;

                            while ((!exitg2) && (j + 1 > ifirst)) {
                                istart = j + 1;
                                ctemp.re = ascale * A[j + 3 * j].re - shift.re * 0.57735026918962584;
                                ctemp.im = ascale * A[j + 3 * j].im - shift.im * 0.57735026918962584;
                                temp = fabs(ctemp.re) + fabs(ctemp.im);
                                anorm = ascale * (fabs(A[jp1 + 3 * j].re) + fabs(A[jp1 + 3 * j].im));
                                tempr = temp;

                                if (anorm > temp) {
                                    tempr = anorm;
                                }

                                if ((tempr < 1.0) && (tempr != 0.0)) {
                                    temp /= tempr;
                                    anorm /= tempr;
                                }

                                if ((fabs(A[j + 3 * (j - 1)].re) + fabs(A[j + 3 * (j - 1)].im)) * anorm <= temp * b_atol) {
                                    goto90 = true;
                                    exitg2 = true;
                                } else {
                                    jp1 = j;
                                    j--;
                                }
                            }

                            if (!goto90) {
                                istart = ifirst;
                                ctemp.re = ascale * A[(ifirst + 3 * (ifirst - 1)) - 1].re - shift.re * 0.57735026918962584;
                                ctemp.im = ascale * A[(ifirst + 3 * (ifirst - 1)) - 1].im - shift.im * 0.57735026918962584;
                                goto90 = true;
                            }
                        }

                        if (goto90) {
                            goto90 = false;
                            b_ascale.re = ascale * A[istart + 3 * (istart - 1)].re;
                            b_ascale.im = ascale * A[istart + 3 * (istart - 1)].im;
                            b_xzlartg(ctemp, b_ascale, &tempr, &shift);
                            j = istart;
                            jp1 = istart - 2;

                            while (j < ilast + 1) {
                                if (j > istart) {
                                    A_tmp = j + 3 * jp1;
                                    xzlartg(A[A_tmp - 1], A[A_tmp], &tempr, &shift, &A[(j + 3 * jp1) - 1]);
                                    A[A_tmp].re = 0.0;
                                    A[A_tmp].im = 0.0;
                                }

                                for (jp1 = j; jp1 < 4; jp1++) {
                                    shift_re_tmp = j + 3 * (jp1 - 1);
                                    stemp_re_tmp = shift_re_tmp - 1;
                                    stemp_re = tempr * A[stemp_re_tmp].re + (shift.re * A[shift_re_tmp].re - shift.im * A[j + 3 * (jp1 - 1)].im);
                                    stemp_im = tempr * A[(j + 3 * (jp1 - 1)) - 1].im + (shift.re * A[j + 3 * (jp1 - 1)].im + shift.im * A[j + 3 * (jp1 - 1)].re);
                                    anorm = A[(j + 3 * (jp1 - 1)) - 1].im;
                                    temp = A[(j + 3 * (jp1 - 1)) - 1].re;
                                    A[shift_re_tmp].re = tempr * A[j + 3 * (jp1 - 1)].re - (shift.re * A[(j + 3 * (jp1 - 1)) - 1].re + shift.im * A[(j + 3 * (jp1 - 1)) - 1].im);
                                    A[shift_re_tmp].im = tempr * A[j + 3 * (jp1 - 1)].im - (shift.re * anorm - shift.im * temp);
                                    A[stemp_re_tmp].re = stemp_re;
                                    A[stemp_re_tmp].im = stemp_im;
                                }

                                shift.re = -shift.re;
                                shift.im = -shift.im;
                                jp1 = j;

                                if (ilast + 1 < j + 2) {
                                    jp1 = ilast - 1;
                                }

                                for (A_tmp = 1; A_tmp <= jp1 + 2; A_tmp++) {
                                    shift_re_tmp = (A_tmp + 3 * (j - 1)) - 1;
                                    stemp_re_tmp = (A_tmp + 3 * j) - 1;
                                    stemp_re = tempr * A[stemp_re_tmp].re + (shift.re * A[shift_re_tmp].re - shift.im * A[(A_tmp + 3 * (j - 1)) - 1].im);
                                    stemp_im = tempr * A[(A_tmp + 3 * j) - 1].im + (shift.re * A[(A_tmp + 3 * (j - 1)) - 1].im + shift.im * A[(A_tmp + 3 * (j - 1)) - 1].re);
                                    anorm = A[(A_tmp + 3 * j) - 1].im;
                                    temp = A[(A_tmp + 3 * j) - 1].re;
                                    A[shift_re_tmp].re = tempr * A[(A_tmp + 3 * (j - 1)) - 1].re - (shift.re * A[(A_tmp + 3 * j) - 1].re + shift.im * A[(A_tmp + 3 * j) - 1].im);
                                    A[shift_re_tmp].im = tempr * A[(A_tmp + 3 * (j - 1)) - 1].im - (shift.re * anorm - shift.im * temp);
                                    A[stemp_re_tmp].re = stemp_re;
                                    A[stemp_re_tmp].im = stemp_im;
                                }

                                stemp_re = tempr * Z[3 * j].re + (shift.re * Z[3 * (j - 1)].re - shift.im * Z[3 * (j - 1)].im);
                                stemp_im = tempr * Z[3 * j].im + (shift.re * Z[3 * (j - 1)].im + shift.im * Z[3 * (j - 1)].re);
                                anorm = Z[3 * j].im;
                                temp = Z[3 * j].re;
                                Z[3 * (j - 1)].re = tempr * Z[3 * (j - 1)].re - (shift.re * Z[3 * j].re + shift.im * Z[3 * j].im);
                                Z[3 * (j - 1)].im = tempr * Z[3 * (j - 1)].im - (shift.re * anorm - shift.im * temp);
                                Z[3 * j].re = stemp_re;
                                Z[3 * j].im = stemp_im;
                                shift_re_tmp = 1 + 3 * (j - 1);
                                stemp_re_tmp = 1 + 3 * j;
                                stemp_re = tempr * Z[stemp_re_tmp].re + (shift.re * Z[shift_re_tmp].re - shift.im * Z[1 + 3 * (j - 1)].im);
                                stemp_im = tempr * Z[1 + 3 * j].im + (shift.re * Z[1 + 3 * (j - 1)].im + shift.im * Z[1 + 3 * (j - 1)].re);
                                anorm = Z[1 + 3 * j].im;
                                temp = Z[1 + 3 * j].re;
                                Z[shift_re_tmp].re = tempr * Z[1 + 3 * (j - 1)].re - (shift.re * Z[1 + 3 * j].re + shift.im * Z[1 + 3 * j].im);
                                Z[shift_re_tmp].im = tempr * Z[1 + 3 * (j - 1)].im - (shift.re * anorm - shift.im * temp);
                                Z[stemp_re_tmp].re = stemp_re;
                                Z[stemp_re_tmp].im = stemp_im;
                                shift_re_tmp = 2 + 3 * (j - 1);
                                stemp_re_tmp = 2 + 3 * j;
                                stemp_re = tempr * Z[stemp_re_tmp].re + (shift.re * Z[shift_re_tmp].re - shift.im * Z[2 + 3 * (j - 1)].im);
                                stemp_im = tempr * Z[2 + 3 * j].im + (shift.re * Z[2 + 3 * (j - 1)].im + shift.im * Z[2 + 3 * (j - 1)].re);
                                anorm = Z[2 + 3 * j].im;
                                temp = Z[2 + 3 * j].re;
                                Z[shift_re_tmp].re = tempr * Z[2 + 3 * (j - 1)].re - (shift.re * Z[2 + 3 * j].re + shift.im * Z[2 + 3 * j].im);
                                Z[shift_re_tmp].im = tempr * Z[2 + 3 * (j - 1)].im - (shift.re * anorm - shift.im * temp);
                                Z[stemp_re_tmp].re = stemp_re;
                                Z[stemp_re_tmp].im = stemp_im;
                                jp1 = j - 1;
                                j++;
                            }
                        }

                        jiter++;
                    }
                }
            } else {
                guard2 = true;
                exitg1 = 1;
            }
        } while (exitg1 == 0);
    } else {
        guard1 = true;
    }

    if (guard2) {
        if (failed) {
            *info = ilast + 1;

            for (jp1 = 0; jp1 <= ilast; jp1++) {
                alpha1[jp1].re = rtNaN;
                alpha1[jp1].im = 0.0;
                beta1[jp1].re = rtNaN;
                beta1[jp1].im = 0.0;
            }

            for (jp1 = 0; jp1 < 9; jp1++) {
                Z[jp1].re = rtNaN;
                Z[jp1].im = 0.0;
            }
        } else {
            guard1 = true;
        }
    }

    if (guard1) {
        for (j = 0; j <= ilo - 2; j++) {
            alpha1[j] = A[j + 3 * j];
        }
    }
}

/*
 * Arguments    : const creal_T A[9]
 *                int ilo
 *                int ihi
 * Return Type  : double
 */
static double xzlanhs(const creal_T A[9], int ilo, int ihi)
{
    double f;
    double scale;
    double sumsq;
    boolean_T firstNonZero;
    int j;
    int i5;
    int i;
    double temp1;
    double im;
    double temp2;
    f = 0.0;

    if (ilo <= ihi) {
        scale = 0.0;
        sumsq = 0.0;
        firstNonZero = true;

        for (j = ilo; j <= ihi; j++) {
            i5 = j + 1;

            if (ihi < j + 1) {
                i5 = ihi;
            }

            for (i = ilo; i <= i5; i++) {
                temp1 = A[(i + 3 * (j - 1)) - 1].re;
                im = A[(i + 3 * (j - 1)) - 1].im;

                if (temp1 != 0.0) {
                    temp1 = fabs(temp1);

                    if (firstNonZero) {
                        sumsq = 1.0;
                        scale = temp1;
                        firstNonZero = false;
                    } else if (scale < temp1) {
                        temp2 = scale / temp1;
                        sumsq = 1.0 + sumsq * temp2 * temp2;
                        scale = temp1;
                    } else {
                        temp2 = temp1 / scale;
                        sumsq += temp2 * temp2;
                    }
                }

                if (im != 0.0) {
                    temp1 = fabs(im);

                    if (firstNonZero) {
                        sumsq = 1.0;
                        scale = temp1;
                        firstNonZero = false;
                    } else if (scale < temp1) {
                        temp2 = scale / temp1;
                        sumsq = 1.0 + sumsq * temp2 * temp2;
                        scale = temp1;
                    } else {
                        temp2 = temp1 / scale;
                        sumsq += temp2 * temp2;
                    }
                }
            }
        }

        f = scale * sqrt(sumsq);
    }

    return f;
}

/*
 * Arguments    : int m
 *                int n
 *                int iv0
 *                double tau
 *                double C[9]
 *                int ic0
 *                double work[3]
 * Return Type  : void
 */
static void xzlarf(int m, int n, int iv0, double tau, double C[9], int ic0,
                   double work[3])
{
    int lastv;
    int lastc;
    boolean_T exitg2;
    int coltop;
    int ia;
    int exitg1;

    if (tau != 0.0) {
        lastv = m;
        lastc = iv0 + m;

        while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
            lastv--;
            lastc--;
        }

        lastc = n;
        exitg2 = false;

        while ((!exitg2) && (lastc > 0)) {
            coltop = ic0 + (lastc - 1) * 3;
            ia = coltop;

            do {
                exitg1 = 0;

                if (ia <= (coltop + lastv) - 1) {
                    if (C[ia - 1] != 0.0) {
                        exitg1 = 1;
                    } else {
                        ia++;
                    }
                } else {
                    lastc--;
                    exitg1 = 2;
                }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
                exitg2 = true;
            }
        }
    } else {
        lastv = 0;
        lastc = 0;
    }

    if (lastv > 0) {
        xgemv(lastv, lastc, C, ic0, C, iv0, work);
        xgerc(lastv, lastc, -tau, iv0, work, C, ic0);
    }
}

/*
 * Arguments    : int n
 *                double *alpha1
 *                double x[3]
 * Return Type  : double
 */
static double xzlarfg(int n, double* alpha1, double x[3])
{
    double tau;
    double xnorm;
    double beta1;
    int knt;
    int k;
    tau = 0.0;

    if (n > 0) {
        xnorm = b_xnrm2(n - 1, x);

        if (xnorm != 0.0) {
            beta1 = rt_hypotd_snf(*alpha1, xnorm);

            if (*alpha1 >= 0.0) {
                beta1 = -beta1;
            }

            if (fabs(beta1) < 1.0020841800044864E-292) {
                knt = -1;

                do {
                    knt++;

                    for (k = 2; k <= n; k++) {
                        x[k - 1] *= 9.9792015476736E+291;
                    }

                    beta1 *= 9.9792015476736E+291;
                    *alpha1 *= 9.9792015476736E+291;
                } while (!(fabs(beta1) >= 1.0020841800044864E-292));

                beta1 = rt_hypotd_snf(*alpha1, b_xnrm2(n - 1, x));

                if (*alpha1 >= 0.0) {
                    beta1 = -beta1;
                }

                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);

                for (k = 2; k <= n; k++) {
                    x[k - 1] *= xnorm;
                }

                for (k = 0; k <= knt; k++) {
                    beta1 *= 1.0020841800044864E-292;
                }

                *alpha1 = beta1;
            } else {
                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);

                for (k = 2; k <= n; k++) {
                    x[k - 1] *= xnorm;
                }

                *alpha1 = beta1;
            }
        }
    }

    return tau;
}

/*
 * Arguments    : const creal_T f
 *                const creal_T g
 *                double *cs
 *                creal_T *sn
 *                creal_T *r
 * Return Type  : void
 */
static void xzlartg(const creal_T f, const creal_T g, double* cs, creal_T* sn,
                    creal_T* r)
{
    double y_tmp;
    double scale;
    double b_y_tmp;
    double f2s;
    double f2;
    double fs_re;
    double fs_im;
    double gs_re;
    double gs_im;
    int count;
    int rescaledir;
    boolean_T guard1 = false;
    double g2s;
    y_tmp = fabs(f.re);
    scale = y_tmp;
    b_y_tmp = fabs(f.im);

    if (b_y_tmp > y_tmp) {
        scale = b_y_tmp;
    }

    f2s = fabs(g.re);
    f2 = fabs(g.im);

    if (f2 > f2s) {
        f2s = f2;
    }

    if (f2s > scale) {
        scale = f2s;
    }

    fs_re = f.re;
    fs_im = f.im;
    gs_re = g.re;
    gs_im = g.im;
    count = -1;
    rescaledir = 0;
    guard1 = false;

    if (scale >= 7.4428285367870146E+137) {
        do {
            count++;
            fs_re *= 1.3435752215134178E-138;
            fs_im *= 1.3435752215134178E-138;
            gs_re *= 1.3435752215134178E-138;
            gs_im *= 1.3435752215134178E-138;
            scale *= 1.3435752215134178E-138;
        } while (!(scale < 7.4428285367870146E+137));

        rescaledir = 1;
        guard1 = true;
    } else if (scale <= 1.3435752215134178E-138) {
        if ((g.re == 0.0) && (g.im == 0.0)) {
            *cs = 1.0;
            sn->re = 0.0;
            sn->im = 0.0;
            *r = f;
        } else {
            do {
                count++;
                fs_re *= 7.4428285367870146E+137;
                fs_im *= 7.4428285367870146E+137;
                gs_re *= 7.4428285367870146E+137;
                gs_im *= 7.4428285367870146E+137;
                scale *= 7.4428285367870146E+137;
            } while (!(scale > 1.3435752215134178E-138));

            rescaledir = -1;
            guard1 = true;
        }
    } else {
        guard1 = true;
    }

    if (guard1) {
        f2 = fs_re * fs_re + fs_im * fs_im;
        scale = gs_re * gs_re + gs_im * gs_im;
        f2s = scale;

        if (1.0 > scale) {
            f2s = 1.0;
        }

        if (f2 <= f2s * 2.0041683600089728E-292) {
            if ((f.re == 0.0) && (f.im == 0.0)) {
                *cs = 0.0;
                r->re = rt_hypotd_snf(g.re, g.im);
                r->im = 0.0;
                scale = rt_hypotd_snf(gs_re, gs_im);
                sn->re = gs_re / scale;
                sn->im = -gs_im / scale;
            } else {
                g2s = sqrt(scale);
                *cs = rt_hypotd_snf(fs_re, fs_im) / g2s;

                if (b_y_tmp > y_tmp) {
                    y_tmp = b_y_tmp;
                }

                if (y_tmp > 1.0) {
                    scale = rt_hypotd_snf(f.re, f.im);
                    fs_re = f.re / scale;
                    fs_im = f.im / scale;
                } else {
                    f2 = 7.4428285367870146E+137 * f.re;
                    f2s = 7.4428285367870146E+137 * f.im;
                    scale = rt_hypotd_snf(f2, f2s);
                    fs_re = f2 / scale;
                    fs_im = f2s / scale;
                }

                gs_re /= g2s;
                gs_im = -gs_im / g2s;
                sn->re = fs_re * gs_re - fs_im * gs_im;
                sn->im = fs_re * gs_im + fs_im * gs_re;
                r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
                r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
            }
        } else {
            f2s = sqrt(1.0 + scale / f2);
            r->re = f2s * fs_re;
            r->im = f2s * fs_im;
            *cs = 1.0 / f2s;
            scale += f2;
            f2 = r->re / scale;
            f2s = r->im / scale;
            sn->re = f2 * gs_re - f2s * -gs_im;
            sn->im = f2 * -gs_im + f2s * gs_re;

            if (rescaledir > 0) {
                for (rescaledir = 0; rescaledir <= count; rescaledir++) {
                    r->re *= 7.4428285367870146E+137;
                    r->im *= 7.4428285367870146E+137;
                }
            } else {
                if (rescaledir < 0) {
                    for (rescaledir = 0; rescaledir <= count; rescaledir++) {
                        r->re *= 1.3435752215134178E-138;
                        r->im *= 1.3435752215134178E-138;
                    }
                }
            }
        }
    }
}

/*
 * Arguments    : const creal_T A[9]
 *                creal_T V[9]
 * Return Type  : void
 */
static void xztgevc(const creal_T A[9], creal_T V[9])
{
    double rworka[3];
    double anorm;
    int i;
    double d_re;
    double xmx;
    double ascale;
    int je;
    int x_tmp;
    double temp;
    double salpha_re;
    double salpha_im;
    double acoeff;
    boolean_T lscalea;
    double z;
    boolean_T lscaleb;
    double scale;
    double acoefa;
    creal_T work1[3];
    double dmin;
    int i12;
    int j;
    creal_T work2[3];
    int b_j;
    double d_im;
    int i13;
    rworka[1] = 0.0;
    rworka[2] = 0.0;
    anorm = fabs(A[0].re) + fabs(A[0].im);

    for (i = 0; i < 1; i++) {
        rworka[1] += fabs(A[3].re) + fabs(A[3].im);
    }

    d_re = rworka[1] + (fabs(A[4].re) + fabs(A[4].im));

    if (d_re > anorm) {
        anorm = d_re;
    }

    for (i = 0; i < 2; i++) {
        rworka[2] += fabs(A[i + 6].re) + fabs(A[i + 6].im);
    }

    d_re = rworka[2] + (fabs(A[8].re) + fabs(A[8].im));

    if (d_re > anorm) {
        anorm = d_re;
    }

    xmx = anorm;

    if (2.2250738585072014E-308 > anorm) {
        xmx = 2.2250738585072014E-308;
    }

    ascale = 1.0 / xmx;

    for (je = 0; je < 3; je++) {
        x_tmp = 3 * (2 - je);
        xmx = (fabs(A[(x_tmp - je) + 2].re) + fabs(A[(3 * (2 - je) - je) + 2].im)) * ascale;

        if (1.0 > xmx) {
            xmx = 1.0;
        }

        temp = 1.0 / xmx;
        salpha_re = ascale * (temp * A[(3 * (2 - je) - je) + 2].re);
        salpha_im = ascale * (temp * A[(3 * (2 - je) - je) + 2].im);
        acoeff = temp * ascale;

        if ((temp >= 2.2250738585072014E-308) && (fabs(acoeff) < 3.0062525400134592E-292)) {
            lscalea = true;
        } else {
            lscalea = false;
        }

        z = fabs(salpha_re) + fabs(salpha_im);

        if ((z >= 2.2250738585072014E-308) && (z < 3.0062525400134592E-292)) {
            lscaleb = true;
        } else {
            lscaleb = false;
        }

        scale = 1.0;

        if (lscalea) {
            xmx = anorm;

            if (3.3264005158911995E+291 < anorm) {
                xmx = 3.3264005158911995E+291;
            }

            scale = 3.0062525400134592E-292 / temp * xmx;
        }

        if (lscaleb) {
            d_re = 3.0062525400134592E-292 / z;

            if (d_re > scale) {
                scale = d_re;
            }
        }

        if (lscalea || lscaleb) {
            xmx = fabs(acoeff);

            if (1.0 > xmx) {
                xmx = 1.0;
            }

            if (z > xmx) {
                xmx = z;
            }

            d_re = 1.0 / (2.2250738585072014E-308 * xmx);

            if (d_re < scale) {
                scale = d_re;
            }

            if (lscalea) {
                acoeff = ascale * (scale * temp);
            } else {
                acoeff *= scale;
            }

            salpha_re *= scale;
            salpha_im *= scale;
        }

        acoefa = fabs(acoeff);
        work1[0].re = 0.0;
        work1[0].im = 0.0;
        work1[1].re = 0.0;
        work1[1].im = 0.0;
        work1[2].re = 0.0;
        work1[2].im = 0.0;
        work1[2 - je].re = 1.0;
        work1[2 - je].im = 0.0;
        dmin = 2.2204460492503131E-16 * acoefa * anorm;
        d_re = 2.2204460492503131E-16 * (fabs(salpha_re) + fabs(salpha_im));

        if (d_re > dmin) {
            dmin = d_re;
        }

        if (2.2250738585072014E-308 > dmin) {
            dmin = 2.2250738585072014E-308;
        }

        i12 = 1 - je;

        for (i = 0; i <= i12; i++) {
            work1[i].re = acoeff * A[i + x_tmp].re;
            work1[i].im = acoeff * A[i + 3 * (2 - je)].im;
        }

        work1[2 - je].re = 1.0;
        work1[2 - je].im = 0.0;
        i12 = (int)((1.0 + (-1.0 - ((3.0 + -(double)je) - 1.0))) / -1.0);

        for (j = 0; j < i12; j++) {
            b_j = 1 - (je + j);
            d_re = acoeff * A[b_j + 3 * b_j].re - salpha_re;
            d_im = acoeff * A[b_j + 3 * b_j].im - salpha_im;

            if (fabs(d_re) + fabs(d_im) <= dmin) {
                d_re = dmin;
                d_im = 0.0;
            }

            xmx = fabs(d_re) + fabs(d_im);

            if (xmx < 1.0) {
                z = fabs(work1[b_j].re) + fabs(work1[b_j].im);

                if (z >= 1.4980776123852632E+307 * xmx) {
                    temp = 1.0 / z;
                    i13 = 2 - je;

                    for (i = 0; i <= i13; i++) {
                        work1[i].re *= temp;
                        work1[i].im *= temp;
                    }
                }
            }

            temp = -work1[b_j].re;

            if (d_im == 0.0) {
                if (-work1[b_j].im == 0.0) {
                    work1[b_j].re = -work1[b_j].re / d_re;
                    work1[b_j].im = 0.0;
                } else if (-work1[b_j].re == 0.0) {
                    work1[b_j].re = 0.0;
                    work1[b_j].im = -work1[b_j].im / d_re;
                } else {
                    work1[b_j].re = -work1[b_j].re / d_re;
                    work1[b_j].im = -work1[b_j].im / d_re;
                }
            } else if (d_re == 0.0) {
                if (-work1[b_j].re == 0.0) {
                    work1[b_j].re = -work1[b_j].im / d_im;
                    work1[b_j].im = 0.0;
                } else if (-work1[b_j].im == 0.0) {
                    work1[b_j].re = 0.0;
                    work1[b_j].im = -(temp / d_im);
                } else {
                    work1[b_j].re = -work1[b_j].im / d_im;
                    work1[b_j].im = -(temp / d_im);
                }
            } else {
                scale = fabs(d_re);
                xmx = fabs(d_im);

                if (scale > xmx) {
                    z = d_im / d_re;
                    xmx = d_re + z * d_im;
                    work1[b_j].re = (-work1[b_j].re + z * -work1[b_j].im) / xmx;
                    work1[b_j].im = (-work1[b_j].im - z * temp) / xmx;
                } else if (xmx == scale) {
                    if (d_re > 0.0) {
                        z = 0.5;
                    } else {
                        z = -0.5;
                    }

                    if (d_im > 0.0) {
                        xmx = 0.5;
                    } else {
                        xmx = -0.5;
                    }

                    work1[b_j].re = (-work1[b_j].re * z + -work1[b_j].im * xmx) / scale;
                    work1[b_j].im = (-work1[b_j].im * z - temp * xmx) / scale;
                } else {
                    z = d_re / d_im;
                    xmx = d_im + z * d_re;
                    work1[b_j].re = (z * -work1[b_j].re + -work1[b_j].im) / xmx;
                    work1[b_j].im = (z * -work1[b_j].im - temp) / xmx;
                }
            }

            if (b_j + 1 > 1) {
                xmx = fabs(work1[1].re) + fabs(work1[1].im);

                if (xmx > 1.0) {
                    temp = 1.0 / xmx;

                    if (acoefa * rworka[1] >= 1.4980776123852632E+307 * temp) {
                        i13 = 2 - je;

                        for (i = 0; i <= i13; i++) {
                            work1[i].re *= temp;
                            work1[i].im *= temp;
                        }
                    }
                }

                d_re = acoeff * work1[1].re;
                d_im = acoeff * work1[1].im;
                work1[0].re += d_re * A[3].re - d_im * A[3].im;
                work1[0].im += d_re * A[3].im + d_im * A[3].re;
            }
        }

        work2[0].re = 0.0;
        work2[0].im = 0.0;
        work2[1].re = 0.0;
        work2[1].im = 0.0;
        work2[2].re = 0.0;
        work2[2].im = 0.0;
        i12 = 2 - je;

        for (i = 0; i <= i12; i++) {
            work2[0].re += V[3 * i].re * work1[i].re - V[3 * i].im * work1[i].im;
            work2[0].im += V[3 * i].re * work1[i].im + V[3 * i].im * work1[i].re;
            work2[1].re += V[1 + 3 * i].re * work1[i].re - V[1 + 3 * i].im * work1[i].im;
            work2[1].im += V[1 + 3 * i].re * work1[i].im + V[1 + 3 * i].im * work1[i].re;
            work2[2].re += V[2 + 3 * i].re * work1[i].re - V[2 + 3 * i].im * work1[i].im;
            work2[2].im += V[2 + 3 * i].re * work1[i].im + V[2 + 3 * i].im * work1[i].re;
        }

        xmx = fabs(work2[0].re) + fabs(work2[0].im);
        d_re = fabs(work2[1].re) + fabs(work2[1].im);

        if (d_re > xmx) {
            xmx = d_re;
        }

        d_re = fabs(work2[2].re) + fabs(work2[2].im);

        if (d_re > xmx) {
            xmx = d_re;
        }

        if (xmx > 2.2250738585072014E-308) {
            temp = 1.0 / xmx;
            V[x_tmp].re = temp * work2[0].re;
            V[x_tmp].im = temp * work2[0].im;
            V[1 + 3 * (2 - je)].re = temp * work2[1].re;
            V[1 + 3 * (2 - je)].im = temp * work2[1].im;
            V[2 + 3 * (2 - je)].re = temp * work2[2].re;
            V[2 + 3 * (2 - je)].im = temp * work2[2].im;
        } else {
            V[x_tmp].re = 0.0;
            V[x_tmp].im = 0.0;
            i12 = 1 + x_tmp;
            V[i12].re = 0.0;
            V[i12].im = 0.0;
            i12 = 2 + x_tmp;
            V[i12].re = 0.0;
            V[i12].im = 0.0;
        }
    }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calibration_initialize(void)
{
    rt_InitInfAndNaN_(8U);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calibration_terminate(void)
{
    /* (no terminate code required) */
}

/*
 * Arguments    : const double v[9]
 *                creal_T mat[9]
 *                double bias[3]
 *                double u[9]
 *                creal_T radii[3]
 * Return Type  : void
 */
void ellipsoid_fit_solve(const double v[9], creal_T mat[9], double bias[3],
                         double u[9], creal_T radii[3])
{
    double A[16];
    int i0;
    double b_v[3];
    int info;
    double b_A[9];
    double Tmtx[16];
    static const signed char iv0[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

    int i1;
    int Tmtx_tmp;
    double b_Tmtx[16];
    boolean_T p;
    int br;
    int ar;
    boolean_T exitg2;
    creal_T At[9];
    creal_T V[9];
    int exitg1;
    creal_T alpha1[3];
    creal_T beta1[3];
    double colnorm;
    double scale;
    double t;
    double absxk;
    creal_T g_mat[9];
    creal_T X[9];
    creal_T b_V[9];
    int exponent;
    int r;
    int i2;
    double dv0[3];
    int ia;
    A[0] = v[0];
    A[4] = v[3];
    A[8] = v[4];
    A[12] = v[6];
    A[1] = v[3];
    A[5] = v[1];
    A[9] = v[5];
    A[13] = v[7];
    A[2] = v[4];
    A[6] = v[5];
    A[10] = v[2];
    A[14] = v[8];
    A[3] = v[6];
    A[7] = v[7];
    A[11] = v[8];
    A[15] = -1.0;

    for (i0 = 0; i0 < 3; i0++) {
        info = i0 << 2;
        b_A[3 * i0] = -A[info];
        b_A[1 + 3 * i0] = -A[1 + info];
        b_A[2 + 3 * i0] = -A[2 + info];
    }

    b_v[0] = v[6];
    b_v[1] = v[7];
    b_v[2] = v[8];
    mldivide(b_A, b_v, bias);

    /*  offset is center of ellipsoid */
    for (i0 = 0; i0 < 16; i0++) {
        Tmtx[i0] = iv0[i0];
    }

    Tmtx[3] = bias[0];
    Tmtx[7] = bias[1];
    Tmtx[11] = bias[2];

    for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
            info = i1 << 2;
            Tmtx_tmp = i0 + info;
            b_Tmtx[Tmtx_tmp] = 0.0;
            b_Tmtx[Tmtx_tmp] = ((Tmtx[i0] * A[info] + Tmtx[i0 + 4] * A[1 + info]) + Tmtx[i0 + 8] * A[2 + info]) + Tmtx[i0 + 12] * A[3 + info];
        }
    }

    for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
            info = i0 + (i1 << 2);
            A[info] = 0.0;
            A[info] = ((b_Tmtx[i0] * Tmtx[i1] + b_Tmtx[i0 + 4] * Tmtx[i1 + 4]) + b_Tmtx[i0 + 8] * Tmtx[i1 + 8]) + b_Tmtx[i0 + 12] * Tmtx[i1 + 12];
        }
    }

    /*  ellipsoid translated to (0,0,0) */
    for (i0 = 0; i0 < 3; i0++) {
        info = i0 << 2;
        b_A[3 * i0] = A[info] / -A[15];
        b_A[1 + 3 * i0] = A[1 + info] / -A[15];
        b_A[2 + 3 * i0] = A[2 + info] / -A[15];
    }

    p = true;

    for (br = 0; br < 9; br++) {
        if (p && ((!rtIsInf_(b_A[br])) && (!rtIsNaN_(b_A[br])))) {
            p = true;
        } else {
            p = false;
        }
    }

    if (!p) {
        for (i0 = 0; i0 < 9; i0++) {
            V[i0].re = rtNaN;
            V[i0].im = 0.0;
        }

        At[0].re = rtNaN;
        At[0].im = 0.0;
        At[4].re = rtNaN;
        At[4].im = 0.0;
        At[8].re = rtNaN;
        At[8].im = 0.0;
    } else {
        p = true;
        ar = 0;
        exitg2 = false;

        while ((!exitg2) && (ar < 3)) {
            info = 0;

            do {
                exitg1 = 0;

                if (info <= ar) {
                    if (!(b_A[info + 3 * ar] == b_A[ar + 3 * info])) {
                        p = false;
                        exitg1 = 1;
                    } else {
                        info++;
                    }
                } else {
                    ar++;
                    exitg1 = 2;
                }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
                exitg2 = true;
            }
        }

        if (p) {
            schur(b_A, V, At);
            At[0].im = 0.0;
            At[4].im = 0.0;
            At[8].im = 0.0;

            for (info = 0; info < 2; info++) {
                At[info + 6].re = 0.0;
                At[info + 6].im = 0.0;
            }
        } else {
            for (i0 = 0; i0 < 9; i0++) {
                At[i0].re = b_A[i0];
                At[i0].im = 0.0;
            }

            xzggev(At, &info, alpha1, beta1, V);

            for (Tmtx_tmp = 0; Tmtx_tmp <= 6; Tmtx_tmp += 3) {
                colnorm = 0.0;
                scale = 3.3121686421112381E-170;
                info = Tmtx_tmp + 3;

                for (br = Tmtx_tmp + 1; br <= info; br++) {
                    absxk = fabs(V[br - 1].re);

                    if (absxk > scale) {
                        t = scale / absxk;
                        colnorm = 1.0 + colnorm * t * t;
                        scale = absxk;
                    } else {
                        t = absxk / scale;
                        colnorm += t * t;
                    }

                    absxk = fabs(V[br - 1].im);

                    if (absxk > scale) {
                        t = scale / absxk;
                        colnorm = 1.0 + colnorm * t * t;
                        scale = absxk;
                    } else {
                        t = absxk / scale;
                        colnorm += t * t;
                    }
                }

                colnorm = scale * sqrt(colnorm);
                i0 = Tmtx_tmp + 3;

                for (ar = Tmtx_tmp + 1; ar <= i0; ar++) {
                    scale = V[ar - 1].re;
                    absxk = V[ar - 1].im;

                    if (absxk == 0.0) {
                        V[ar - 1].re = scale / colnorm;
                        V[ar - 1].im = 0.0;
                    } else if (scale == 0.0) {
                        V[ar - 1].re = 0.0;
                        V[ar - 1].im = absxk / colnorm;
                    } else {
                        V[ar - 1].re = scale / colnorm;
                        V[ar - 1].im = absxk / colnorm;
                    }
                }
            }

            if (beta1[0].im == 0.0) {
                if (alpha1[0].im == 0.0) {
                    At[0].re = alpha1[0].re / beta1[0].re;
                    At[0].im = 0.0;
                } else if (alpha1[0].re == 0.0) {
                    At[0].re = 0.0;
                    At[0].im = alpha1[0].im / beta1[0].re;
                } else {
                    At[0].re = alpha1[0].re / beta1[0].re;
                    At[0].im = alpha1[0].im / beta1[0].re;
                }
            } else if (beta1[0].re == 0.0) {
                if (alpha1[0].re == 0.0) {
                    At[0].re = alpha1[0].im / beta1[0].im;
                    At[0].im = 0.0;
                } else if (alpha1[0].im == 0.0) {
                    At[0].re = 0.0;
                    At[0].im = -(alpha1[0].re / beta1[0].im);
                } else {
                    At[0].re = alpha1[0].im / beta1[0].im;
                    At[0].im = -(alpha1[0].re / beta1[0].im);
                }
            } else {
                t = fabs(beta1[0].re);
                scale = fabs(beta1[0].im);

                if (t > scale) {
                    scale = beta1[0].im / beta1[0].re;
                    absxk = beta1[0].re + scale * beta1[0].im;
                    At[0].re = (alpha1[0].re + scale * alpha1[0].im) / absxk;
                    At[0].im = (alpha1[0].im - scale * alpha1[0].re) / absxk;
                } else if (scale == t) {
                    if (beta1[0].re > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (beta1[0].im > 0.0) {
                        absxk = 0.5;
                    } else {
                        absxk = -0.5;
                    }

                    At[0].re = (alpha1[0].re * scale + alpha1[0].im * absxk) / t;
                    At[0].im = (alpha1[0].im * scale - alpha1[0].re * absxk) / t;
                } else {
                    scale = beta1[0].re / beta1[0].im;
                    absxk = beta1[0].im + scale * beta1[0].re;
                    At[0].re = (scale * alpha1[0].re + alpha1[0].im) / absxk;
                    At[0].im = (scale * alpha1[0].im - alpha1[0].re) / absxk;
                }
            }

            if (beta1[1].im == 0.0) {
                if (alpha1[1].im == 0.0) {
                    At[4].re = alpha1[1].re / beta1[1].re;
                    At[4].im = 0.0;
                } else if (alpha1[1].re == 0.0) {
                    At[4].re = 0.0;
                    At[4].im = alpha1[1].im / beta1[1].re;
                } else {
                    At[4].re = alpha1[1].re / beta1[1].re;
                    At[4].im = alpha1[1].im / beta1[1].re;
                }
            } else if (beta1[1].re == 0.0) {
                if (alpha1[1].re == 0.0) {
                    At[4].re = alpha1[1].im / beta1[1].im;
                    At[4].im = 0.0;
                } else if (alpha1[1].im == 0.0) {
                    At[4].re = 0.0;
                    At[4].im = -(alpha1[1].re / beta1[1].im);
                } else {
                    At[4].re = alpha1[1].im / beta1[1].im;
                    At[4].im = -(alpha1[1].re / beta1[1].im);
                }
            } else {
                t = fabs(beta1[1].re);
                scale = fabs(beta1[1].im);

                if (t > scale) {
                    scale = beta1[1].im / beta1[1].re;
                    absxk = beta1[1].re + scale * beta1[1].im;
                    At[4].re = (alpha1[1].re + scale * alpha1[1].im) / absxk;
                    At[4].im = (alpha1[1].im - scale * alpha1[1].re) / absxk;
                } else if (scale == t) {
                    if (beta1[1].re > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (beta1[1].im > 0.0) {
                        absxk = 0.5;
                    } else {
                        absxk = -0.5;
                    }

                    At[4].re = (alpha1[1].re * scale + alpha1[1].im * absxk) / t;
                    At[4].im = (alpha1[1].im * scale - alpha1[1].re * absxk) / t;
                } else {
                    scale = beta1[1].re / beta1[1].im;
                    absxk = beta1[1].im + scale * beta1[1].re;
                    At[4].re = (scale * alpha1[1].re + alpha1[1].im) / absxk;
                    At[4].im = (scale * alpha1[1].im - alpha1[1].re) / absxk;
                }
            }

            if (beta1[2].im == 0.0) {
                if (alpha1[2].im == 0.0) {
                    At[8].re = alpha1[2].re / beta1[2].re;
                    At[8].im = 0.0;
                } else if (alpha1[2].re == 0.0) {
                    At[8].re = 0.0;
                    At[8].im = alpha1[2].im / beta1[2].re;
                } else {
                    At[8].re = alpha1[2].re / beta1[2].re;
                    At[8].im = alpha1[2].im / beta1[2].re;
                }
            } else if (beta1[2].re == 0.0) {
                if (alpha1[2].re == 0.0) {
                    At[8].re = alpha1[2].im / beta1[2].im;
                    At[8].im = 0.0;
                } else if (alpha1[2].im == 0.0) {
                    At[8].re = 0.0;
                    At[8].im = -(alpha1[2].re / beta1[2].im);
                } else {
                    At[8].re = alpha1[2].im / beta1[2].im;
                    At[8].im = -(alpha1[2].re / beta1[2].im);
                }
            } else {
                t = fabs(beta1[2].re);
                scale = fabs(beta1[2].im);

                if (t > scale) {
                    scale = beta1[2].im / beta1[2].re;
                    absxk = beta1[2].re + scale * beta1[2].im;
                    At[8].re = (alpha1[2].re + scale * alpha1[2].im) / absxk;
                    At[8].im = (alpha1[2].im - scale * alpha1[2].re) / absxk;
                } else if (scale == t) {
                    if (beta1[2].re > 0.0) {
                        scale = 0.5;
                    } else {
                        scale = -0.5;
                    }

                    if (beta1[2].im > 0.0) {
                        absxk = 0.5;
                    } else {
                        absxk = -0.5;
                    }

                    At[8].re = (alpha1[2].re * scale + alpha1[2].im * absxk) / t;
                    At[8].im = (alpha1[2].im * scale - alpha1[2].re * absxk) / t;
                } else {
                    scale = beta1[2].re / beta1[2].im;
                    absxk = beta1[2].im + scale * beta1[2].re;
                    At[8].re = (scale * alpha1[2].re + alpha1[2].im) / absxk;
                    At[8].im = (scale * alpha1[2].im - alpha1[2].re) / absxk;
                }
            }
        }
    }

    /*  eigenvectors (rotation) and eigenvalues (gain) */
    if (At[0].im == 0.0) {
        radii[0].re = 1.0 / At[0].re;
        radii[0].im = 0.0;
    } else if (At[0].re == 0.0) {
        radii[0].re = 0.0;
        radii[0].im = -(1.0 / At[0].im);
    } else {
        t = fabs(At[0].re);
        scale = fabs(At[0].im);

        if (t > scale) {
            scale = At[0].im / At[0].re;
            absxk = At[0].re + scale * At[0].im;
            radii[0].re = (1.0 + scale * 0.0) / absxk;
            radii[0].im = (0.0 - scale) / absxk;
        } else if (scale == t) {
            if (At[0].re > 0.0) {
                scale = 0.5;
            } else {
                scale = -0.5;
            }

            if (At[0].im > 0.0) {
                absxk = 0.5;
            } else {
                absxk = -0.5;
            }

            radii[0].re = (scale + 0.0 * absxk) / t;
            radii[0].im = (0.0 * scale - absxk) / t;
        } else {
            scale = At[0].re / At[0].im;
            absxk = At[0].im + scale * At[0].re;
            radii[0].re = scale / absxk;
            radii[0].im = (scale * 0.0 - 1.0) / absxk;
        }
    }

    if (At[4].im == 0.0) {
        radii[1].re = 1.0 / At[4].re;
        radii[1].im = 0.0;
    } else if (At[4].re == 0.0) {
        radii[1].re = 0.0;
        radii[1].im = -(1.0 / At[4].im);
    } else {
        t = fabs(At[4].re);
        scale = fabs(At[4].im);

        if (t > scale) {
            scale = At[4].im / At[4].re;
            absxk = At[4].re + scale * At[4].im;
            radii[1].re = (1.0 + scale * 0.0) / absxk;
            radii[1].im = (0.0 - scale) / absxk;
        } else if (scale == t) {
            if (At[4].re > 0.0) {
                scale = 0.5;
            } else {
                scale = -0.5;
            }

            if (At[4].im > 0.0) {
                absxk = 0.5;
            } else {
                absxk = -0.5;
            }

            radii[1].re = (scale + 0.0 * absxk) / t;
            radii[1].im = (0.0 * scale - absxk) / t;
        } else {
            scale = At[4].re / At[4].im;
            absxk = At[4].im + scale * At[4].re;
            radii[1].re = scale / absxk;
            radii[1].im = (scale * 0.0 - 1.0) / absxk;
        }
    }

    if (At[8].im == 0.0) {
        radii[2].re = 1.0 / At[8].re;
        radii[2].im = 0.0;
    } else if (At[8].re == 0.0) {
        radii[2].re = 0.0;
        radii[2].im = -(1.0 / At[8].im);
    } else {
        t = fabs(At[8].re);
        scale = fabs(At[8].im);

        if (t > scale) {
            scale = At[8].im / At[8].re;
            absxk = At[8].re + scale * At[8].im;
            radii[2].re = (1.0 + scale * 0.0) / absxk;
            radii[2].im = (0.0 - scale) / absxk;
        } else if (scale == t) {
            if (At[8].re > 0.0) {
                scale = 0.5;
            } else {
                scale = -0.5;
            }

            if (At[8].im > 0.0) {
                absxk = 0.5;
            } else {
                absxk = -0.5;
            }

            radii[2].re = (scale + 0.0 * absxk) / t;
            radii[2].im = (0.0 * scale - absxk) / t;
        } else {
            scale = At[8].re / At[8].im;
            absxk = At[8].im + scale * At[8].re;
            radii[2].re = scale / absxk;
            radii[2].im = (scale * 0.0 - 1.0) / absxk;
        }
    }

    c_sqrt(&radii[0]);
    c_sqrt(&radii[1]);
    c_sqrt(&radii[2]);

    /*  gain is radius of the ellipsoid */
    if (radii[0].im == 0.0) {
        alpha1[0].re = 1.0 / radii[0].re;
        alpha1[0].im = 0.0;
    } else if (radii[0].re == 0.0) {
        alpha1[0].re = 0.0;
        alpha1[0].im = -(1.0 / radii[0].im);
    } else {
        t = fabs(radii[0].re);
        scale = fabs(radii[0].im);

        if (t > scale) {
            scale = radii[0].im / radii[0].re;
            absxk = radii[0].re + scale * radii[0].im;
            alpha1[0].re = (1.0 + scale * 0.0) / absxk;
            alpha1[0].im = (0.0 - scale) / absxk;
        } else if (scale == t) {
            if (radii[0].re > 0.0) {
                scale = 0.5;
            } else {
                scale = -0.5;
            }

            if (radii[0].im > 0.0) {
                absxk = 0.5;
            } else {
                absxk = -0.5;
            }

            alpha1[0].re = (scale + 0.0 * absxk) / t;
            alpha1[0].im = (0.0 * scale - absxk) / t;
        } else {
            scale = radii[0].re / radii[0].im;
            absxk = radii[0].im + scale * radii[0].re;
            alpha1[0].re = scale / absxk;
            alpha1[0].im = (scale * 0.0 - 1.0) / absxk;
        }
    }

    if (radii[1].im == 0.0) {
        alpha1[1].re = 1.0 / radii[1].re;
        alpha1[1].im = 0.0;
    } else if (radii[1].re == 0.0) {
        alpha1[1].re = 0.0;
        alpha1[1].im = -(1.0 / radii[1].im);
    } else {
        t = fabs(radii[1].re);
        scale = fabs(radii[1].im);

        if (t > scale) {
            scale = radii[1].im / radii[1].re;
            absxk = radii[1].re + scale * radii[1].im;
            alpha1[1].re = (1.0 + scale * 0.0) / absxk;
            alpha1[1].im = (0.0 - scale) / absxk;
        } else if (scale == t) {
            if (radii[1].re > 0.0) {
                scale = 0.5;
            } else {
                scale = -0.5;
            }

            if (radii[1].im > 0.0) {
                absxk = 0.5;
            } else {
                absxk = -0.5;
            }

            alpha1[1].re = (scale + 0.0 * absxk) / t;
            alpha1[1].im = (0.0 * scale - absxk) / t;
        } else {
            scale = radii[1].re / radii[1].im;
            absxk = radii[1].im + scale * radii[1].re;
            alpha1[1].re = scale / absxk;
            alpha1[1].im = (scale * 0.0 - 1.0) / absxk;
        }
    }

    if (radii[2].im == 0.0) {
        alpha1[2].re = 1.0 / radii[2].re;
        alpha1[2].im = 0.0;
    } else if (radii[2].re == 0.0) {
        alpha1[2].re = 0.0;
        alpha1[2].im = -(1.0 / radii[2].im);
    } else {
        t = fabs(radii[2].re);
        scale = fabs(radii[2].im);

        if (t > scale) {
            scale = radii[2].im / radii[2].re;
            absxk = radii[2].re + scale * radii[2].im;
            alpha1[2].re = (1.0 + scale * 0.0) / absxk;
            alpha1[2].im = (0.0 - scale) / absxk;
        } else if (scale == t) {
            if (radii[2].re > 0.0) {
                scale = 0.5;
            } else {
                scale = -0.5;
            }

            if (radii[2].im > 0.0) {
                absxk = 0.5;
            } else {
                absxk = -0.5;
            }

            alpha1[2].re = (scale + 0.0 * absxk) / t;
            alpha1[2].im = (0.0 * scale - absxk) / t;
        } else {
            scale = radii[2].re / radii[2].im;
            absxk = radii[2].im + scale * radii[2].re;
            alpha1[2].re = scale / absxk;
            alpha1[2].im = (scale * 0.0 - 1.0) / absxk;
        }
    }

    for (i0 = 0; i0 < 9; i0++) {
        g_mat[i0].re = 0.0;
        g_mat[i0].im = 0.0;
    }

    g_mat[0] = alpha1[0];
    g_mat[4] = alpha1[1];
    g_mat[8] = alpha1[2];

    /*  g_mat = diag(sqrt(diag(ev))); */
    /*  g_mat will rotate axis, so we need rotate axis back */
    p = true;

    for (br = 0; br < 9; br++) {
        X[br].re = 0.0;
        X[br].im = 0.0;

        if (p && ((!rtIsInf_(V[br].re)) && (!rtIsInf_(V[br].im)) && ((!rtIsNaN_(V[br].re)) && (!rtIsNaN_(V[br].im))))) {
            p = true;
        } else {
            p = false;
        }
    }

    if (!p) {
        for (i0 = 0; i0 < 9; i0++) {
            X[i0].re = rtNaN;
            X[i0].im = 0.0;
        }
    } else {
        svd(V, At, b_v, b_V);
        absxk = fabs(b_v[0]);

        if ((!rtIsInf_(absxk)) && (!rtIsNaN_(absxk))) {
            if (absxk <= 2.2250738585072014E-308) {
                scale = 4.94065645841247E-324;
            } else {
                frexp(absxk, &exponent);
                scale = ldexp(1.0, exponent - 53);
            }
        } else {
            scale = rtNaN;
        }

        scale *= 3.0;
        r = -1;
        br = 0;

        while ((br < 3) && (b_v[br] > scale)) {
            r++;
            br++;
        }

        if (r + 1 > 0) {
            info = 1;

            for (ar = 0; ar <= r; ar++) {
                t = 1.0 / b_v[ar];
                i0 = info + 2;

                for (br = info; br <= i0; br++) {
                    scale = b_V[br - 1].re;
                    absxk = b_V[br - 1].im;
                    b_V[br - 1].re = t * scale - 0.0 * absxk;
                    b_V[br - 1].im = t * absxk + 0.0 * scale;
                }

                info += 3;
            }

            for (info = 0; info <= 6; info += 3) {
                i0 = info + 1;
                i1 = info + 3;

                for (Tmtx_tmp = i0; Tmtx_tmp <= i1; Tmtx_tmp++) {
                    X[Tmtx_tmp - 1].re = 0.0;
                    X[Tmtx_tmp - 1].im = 0.0;
                }
            }

            br = 0;

            for (info = 0; info <= 6; info += 3) {
                ar = -1;
                br++;
                i0 = br + 3 * r;

                for (exponent = br; exponent <= i0; exponent += 3) {
                    scale = At[exponent - 1].re;
                    absxk = -At[exponent - 1].im;
                    t = scale - 0.0 * absxk;
                    scale = absxk + 0.0 * scale;
                    ia = ar;
                    i1 = info + 1;
                    i2 = info + 3;

                    for (Tmtx_tmp = i1; Tmtx_tmp <= i2; Tmtx_tmp++) {
                        ia++;
                        X[Tmtx_tmp - 1].re += t * b_V[ia].re - scale * b_V[ia].im;
                        X[Tmtx_tmp - 1].im += t * b_V[ia].im + scale * b_V[ia].re;
                    }

                    ar += 3;
                }
            }
        }
    }

    for (i0 = 0; i0 < 3; i0++) {
        for (i1 = 0; i1 < 3; i1++) {
            i2 = i0 + 3 * i1;
            b_V[i2].re = 0.0;
            b_V[i2].im = 0.0;
            b_V[i2].re = ((V[i0].re * g_mat[3 * i1].re - V[i0].im * g_mat[3 * i1].im)
                          + (V[i0 + 3].re * g_mat[1 + 3 * i1].re - V[i0 + 3].im * g_mat[1 + 3 * i1].im))
                + (V[i0 + 6].re * g_mat[2 + 3 * i1].re - V[i0 + 6].im * g_mat[2 + 3 * i1].im);
            b_V[i2].im = ((V[i0].re * g_mat[3 * i1].im + V[i0].im * g_mat[3 * i1].re)
                          + (V[i0 + 3].re * g_mat[1 + 3 * i1].im + V[i0 + 3].im * g_mat[1 + 3 * i1].re))
                + (V[i0 + 6].re * g_mat[2 + 3 * i1].im + V[i0 + 6].im * g_mat[2 + 3 * i1].re);
        }

        for (i1 = 0; i1 < 3; i1++) {
            i2 = i0 + 3 * i1;
            mat[i2].re = 0.0;
            mat[i2].im = 0.0;
            mat[i2].re = ((b_V[i0].re * X[3 * i1].re - b_V[i0].im * X[3 * i1].im) + (b_V[i0 + 3].re * X[1 + 3 * i1].re - b_V[i0 + 3].im * X[1 + 3 * i1].im)) + (b_V[i0 + 6].re * X[2 + 3 * i1].re - b_V[i0 + 6].im * X[2 + 3 * i1].im);
            mat[i2].im = ((b_V[i0].re * X[3 * i1].im + b_V[i0].im * X[3 * i1].re) + (b_V[i0 + 3].re * X[1 + 3 * i1].im + b_V[i0 + 3].im * X[1 + 3 * i1].re)) + (b_V[i0 + 6].re * X[2 + 3 * i1].im + b_V[i0 + 6].im * X[2 + 3 * i1].re);
        }
    }

    /*  main the norm of input data */
    t = 0.0;

    for (ar = 0; ar < 3; ar++) {
        scale = rt_hypotd_snf(mat[3 * ar].re, mat[3 * ar].im);

        if (rtIsNaN_(scale) || (scale > t)) {
            t = scale;
        }

        scale = rt_hypotd_snf(mat[1 + 3 * ar].re, mat[1 + 3 * ar].im);

        if (rtIsNaN_(scale) || (scale > t)) {
            t = scale;
        }

        scale = rt_hypotd_snf(mat[2 + 3 * ar].re, mat[2 + 3 * ar].im);

        if (rtIsNaN_(scale) || (scale > t)) {
            t = scale;
        }
    }

    if ((!rtIsInf_(t)) && (!rtIsNaN_(t))) {
        b_svd(mat, dv0);
        t = dv0[0];
    }

    for (i0 = 0; i0 < 3; i0++) {
        if (-mat[i0].im == 0.0) {
            At[3 * i0].re = mat[i0].re / t;
            At[3 * i0].im = 0.0;
        } else if (mat[i0].re == 0.0) {
            At[3 * i0].re = 0.0;
            At[3 * i0].im = -mat[i0].im / t;
        } else {
            At[3 * i0].re = mat[i0].re / t;
            At[3 * i0].im = -mat[i0].im / t;
        }

        scale = mat[i0 + 3].re;
        absxk = -mat[i0 + 3].im;

        if (absxk == 0.0) {
            At[1 + 3 * i0].re = scale / t;
            At[1 + 3 * i0].im = 0.0;
        } else if (scale == 0.0) {
            At[1 + 3 * i0].re = 0.0;
            At[1 + 3 * i0].im = absxk / t;
        } else {
            i1 = 1 + 3 * i0;
            At[i1].re = scale / t;
            At[i1].im = absxk / t;
        }

        scale = mat[i0 + 6].re;
        absxk = -mat[i0 + 6].im;

        if (absxk == 0.0) {
            At[2 + 3 * i0].re = scale / t;
            At[2 + 3 * i0].im = 0.0;
        } else if (scale == 0.0) {
            At[2 + 3 * i0].re = 0.0;
            At[2 + 3 * i0].im = absxk / t;
        } else {
            i1 = 2 + 3 * i0;
            At[i1].re = scale / t;
            At[i1].im = absxk / t;
        }
    }

    memcpy(&mat[0], &At[0], 9U * sizeof(creal_T));
    memcpy(&u[0], &v[0], 9U * sizeof(double));
}

/*
 * Arguments    : double x
 *                double y
 *                double z
 *                const double v[9]
 *                const double P[81]
 *                double R
 *                double next_v[9]
 *                double next_P[81]
 * Return Type  : void
 */
void ellipsoid_fit_step(double x, double y, double z, const double v[9], const double P[81], double R, double next_v[9], double next_P[81])
{
    double H[9];
    double b_H;
    int i6;
    double S;
    double d0;
    int next_P_tmp;
    int i;
    double K[9];
    double b_K[81];
    H[0] = x * x;
    H[1] = y * y;
    H[2] = z * z;
    H[3] = 2.0 * x * y;
    H[4] = 2.0 * x * z;
    H[5] = 2.0 * y * z;
    H[6] = 2.0 * x;
    H[7] = 2.0 * y;
    H[8] = 2.0 * z;
    b_H = 0.0;

    for (i6 = 0; i6 < 9; i6++) {
        b_H += H[i6] * v[i6];
    }

    /*  S(k) = H(k)*P(k|k-1)*H(k)' + R(k) */
    S = 0.0;

    for (i6 = 0; i6 < 9; i6++) {
        d0 = 0.0;

        for (next_P_tmp = 0; next_P_tmp < 9; next_P_tmp++) {
            d0 += H[next_P_tmp] * P[next_P_tmp + 9 * i6];
        }

        S += d0 * H[i6];
    }

    S += R;

    /*  K(k) = P(k|k-1)*H(k)'*S(k)^-1 */
    /*  X(k|k) = X(k|k-1) + K(k)*Y(k) */
    /*  P(k|k) = P(k|k-1) - K(k)*H(k)*P(k|k-1); */
    for (i = 0; i < 9; i++) {
        d0 = 0.0;

        for (i6 = 0; i6 < 9; i6++) {
            d0 += P[i + 9 * i6] * H[i6];
        }

        d0 /= S;
        K[i] = d0;
        next_v[i] = v[i] + d0 * (1.0 - b_H);

        for (i6 = 0; i6 < 9; i6++) {
            b_K[i + 9 * i6] = K[i] * H[i6];
        }

        for (i6 = 0; i6 < 9; i6++) {
            d0 = 0.0;

            for (next_P_tmp = 0; next_P_tmp < 9; next_P_tmp++) {
                d0 += b_K[i + 9 * next_P_tmp] * P[next_P_tmp + 9 * i6];
            }

            next_P_tmp = i + 9 * i6;
            next_P[next_P_tmp] = P[next_P_tmp] - d0;
        }
    }

    /*      P = (eye(9)-K*H)*P*(eye(9)-K*H)'+K*R*K'; */
}

/*
 * File trailer for calibration.c
 *
 * [EOF]
 */
