/*
 * File: calibration.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 13-Apr-2020 15:45:11
 */

#ifndef CALIBRATION_H
    #define CALIBRATION_H

    /* Include Files */
    #include "calibration_types.h"
    #include "rtwtypes.h"
    #include <stddef.h>
    #include <stdlib.h>

/* Function Declarations */
extern void calibration_initialize(void);
extern void calibration_terminate(void);
extern void ellipsoid_fit_solve(const double v[9], creal_T mat[9], double bias[3],
                                double u[9], creal_T radii[3]);
extern void ellipsoid_fit_step(double x, double y, double z, const double v[9],
                               const double P[81], double R, double next_v[9], double next_P[81]);

#endif

/*
 * File trailer for calibration.h
 *
 * [EOF]
 */
