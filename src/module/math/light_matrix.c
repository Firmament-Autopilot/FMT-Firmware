/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <firmament.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "module/math/light_matrix.h"

#define MAT_LEGAL_CHECKING

#define min(a, b) ((a) > (b) ? (b) : (a))
//#define equal(a, b)	((a-b)<1e-7 && (a-b)>-(1e-7))
#define equal(a, b) (((a) - (b)) < (1e-15) && ((a) - (b)) > -(1e-15))

/************************************************************************/
/*                          Private Function                            */
/************************************************************************/

static void swap(int* a, int* b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

static void perm(int list[], int k, int m, int* p, Mat* mat, MAT_TYPE* det)
{
    int i;

    if (k > m) {
        MAT_TYPE res = mat->element[0][list[0]];

        for (i = 1; i < mat->row; i++) {
            res *= mat->element[i][list[i]];
        }

        if (*p % 2) {
            //odd is negative
            *det -= res;
        } else {
            //even is positive
            *det += res;
        }
    } else {
        // if the element is 0, we don't need to calculate the value for this permutation
        //		if(!equal(mat->element[k][list[k]], 0.0f))
        //			perm(list, k + 1, m, p, mat, det);
        perm(list, k + 1, m, p, mat, det);

        for (i = k + 1; i <= m; i++) {
            //			if(equal(mat->element[k][list[i]], 0.0f))
            //				continue;
            swap(&list[k], &list[i]);
            *p += 1;
            perm(list, k + 1, m, p, mat, det);
            swap(&list[k], &list[i]);
            *p -= 1;
        }
    }
}

/************************************************************************/
/*                           Public Function                            */
/************************************************************************/

Mat* MatCreate(Mat* mat, int row, int col)
{
    int i;

    mat->element = (MAT_TYPE**)MAT_MALLOC(row * sizeof(MAT_TYPE*));
    mat->buffer = (MAT_TYPE*)MAT_MALLOC(row * col * sizeof(MAT_TYPE));

    if (mat->element == NULL || mat->buffer == NULL) {
        MatDelete(mat);
        return NULL;
    }

    for (i = 0; i < row; i++) {
        mat->element[i] = &mat->buffer[i * col];
    }

    mat->row = row;
    mat->col = col;

    return mat;
}

void MatDelete(Mat* mat)
{
    MAT_FREE(mat->element);
    MAT_FREE(mat->buffer);
}

Mat* MatSetVal(Mat* mat, MAT_TYPE* val)
{
    int row, col;

    for (row = 0; row < mat->row; row++) {
        for (col = 0; col < mat->col; col++) {
            mat->element[row][col] = val[col + row * mat->col];
        }
    }

    return mat;
}

void MatDump(const Mat* mat)
{
    int row, col;

#ifdef MAT_LEGAL_CHECKING

    if (mat == NULL) {
        return;
    }

#endif

    MAT_PRINTF("Mat %dx%d:\n", mat->row, mat->col);

    for (row = 0; row < mat->row; row++) {
        for (col = 0; col < mat->col; col++) {
            MAT_PRINTF("%.4f\t", mat->element[row][col]);
        }
        MAT_PRINTF("\n");
    }
}

Mat* MatZeros(Mat* mat)
{
    int row, col;

    for (row = 0; row < mat->row; row++) {
        for (col = 0; col < mat->col; col++) {
            mat->element[row][col] = 0.0f;
        }
    }

    return mat;
}

Mat* MatEye(Mat* mat)
{
    int i;

    MatZeros(mat);

    for (i = 0; i < min(mat->row, mat->col); i++) {
        mat->element[i][i] = 1.0f;
    }

    return mat;
}

/* dst = src1 + src2 */
Mat* MatAdd(Mat* src1, Mat* src2, Mat* dst)
{
    int row, col;

#ifdef MAT_LEGAL_CHECKING

    if (!(src1->row == src2->row && src2->row == dst->row && src1->col == src2->col && src2->col == dst->col)) {
        MAT_PRINTF("err check, unmatch matrix for MatAdd\n");
        MatDump(src1);
        MatDump(src2);
        MatDump(dst);
        return NULL;
    }

#endif

    for (row = 0; row < src1->row; row++) {
        for (col = 0; col < src1->col; col++) {
            dst->element[row][col] = src1->element[row][col] + src2->element[row][col];
        }
    }

    return dst;
}

/* dst = src1 - src2 */
Mat* MatSub(Mat* src1, Mat* src2, Mat* dst)
{
    int row, col;

#ifdef MAT_LEGAL_CHECKING

    if (!(src1->row == src2->row && src2->row == dst->row && src1->col == src2->col && src2->col == dst->col)) {
        MAT_PRINTF("err check, unmatch matrix for MatSub\n");
        MatDump(src1);
        MatDump(src2);
        MatDump(dst);
        return NULL;
    }

#endif

    for (row = 0; row < src1->row; row++) {
        for (col = 0; col < src1->col; col++) {
            dst->element[row][col] = src1->element[row][col] - src2->element[row][col];
        }
    }

    return dst;
}

/* dst = src1 * src2 */
Mat* MatMul(Mat* src1, Mat* src2, Mat* dst)
{
    int row, col;
    int i;
    MAT_TYPE temp;

#ifdef MAT_LEGAL_CHECKING

    if (src1->col != src2->row || src1->row != dst->row || src2->col != dst->col) {
        MAT_PRINTF("err check, unmatch matrix for MatMul\n");
        MatDump(src1);
        MatDump(src2);
        MatDump(dst);
        return NULL;
    }

#endif

    for (row = 0; row < dst->row; row++) {
        for (col = 0; col < dst->col; col++) {
            temp = 0.0f;

            for (i = 0; i < src1->col; i++) {
                temp += src1->element[row][i] * src2->element[i][col];
            }

            dst->element[row][col] = temp;
        }
    }

    return dst;
}

/* dst = src' */
Mat* MatTrans(Mat* src, Mat* dst)
{
    int row, col;

#ifdef MAT_LEGAL_CHECKING

    if (src->row != dst->col || src->col != dst->row) {
        MAT_PRINTF("err check, unmatch matrix for MatTranspose\n");
        MatDump(src);
        MatDump(dst);
        return NULL;
    }

#endif

    for (row = 0; row < dst->row; row++) {
        for (col = 0; col < dst->col; col++) {
            dst->element[row][col] = src->element[col][row];
        }
    }

    return dst;
}

// return det(mat)
MAT_TYPE MatDet(Mat* mat)
{
    MAT_TYPE det = 0.0f;
    int plarity = 0;
    int* list;
    int i;

#ifdef MAT_LEGAL_CHECKING

    if (mat->row != mat->col) {
        MAT_PRINTF("err check, not a square matrix for MatDetermine\n");
        MatDump(mat);
        return 0.0f;
    }

#endif

    list = (int*)MAT_MALLOC(sizeof(int) * mat->col);

    if (list == NULL) {
        MAT_PRINTF("malloc list fail\n");
        return 0.0f;
    }

    for (i = 0; i < mat->col; i++)
        list[i] = i;

    perm(list, 0, mat->row - 1, &plarity, mat, &det);
    MAT_FREE(list);

    return det;
}

// dst = adj(src)
Mat* MatAdj(Mat* src, Mat* dst)
{
    Mat smat;
    int row, col;
    int i, j, r, c;
    MAT_TYPE det;

#ifdef MAT_LEGAL_CHECKING

    if (src->row != src->col || src->row != dst->row || src->col != dst->col) {
        MAT_PRINTF("err check, not a square matrix for MatAdj\n");
        MatDump(src);
        MatDump(dst);
        return NULL;
    }

#endif

    MatCreate(&smat, src->row - 1, src->col - 1);

    for (row = 0; row < src->row; row++) {
        for (col = 0; col < src->col; col++) {
            r = 0;

            for (i = 0; i < src->row; i++) {
                if (i == row)
                    continue;

                c = 0;

                for (j = 0; j < src->col; j++) {
                    if (j == col)
                        continue;

                    smat.element[r][c] = src->element[i][j];
                    c++;
                }

                r++;
            }

            det = MatDet(&smat);

            if ((row + col) % 2)
                det = -det;

            dst->element[col][row] = det;
        }
    }

    MatDelete(&smat);

    return dst;
}

// dst = src^(-1)
Mat* MatInv(Mat* src, Mat* dst)
{
    Mat adj_mat;
    MAT_TYPE det;
    int row, col;

#ifdef MAT_LEGAL_CHECKING

    if (src->row != src->col || src->row != dst->row || src->col != dst->col) {
        MAT_PRINTF("err check, not a square matrix for MatInv\n");
        MatDump(src);
        MatDump(dst);
        return NULL;
    }

#endif
    //MAT_PRINTF("create\n");
    MatCreate(&adj_mat, src->row, src->col);
    //MAT_PRINTF("create finish\n");
    MatAdj(src, &adj_mat);
    //MAT_PRINTF("adj\n");
    det = MatDet(src);
    //MAT_PRINTF("inv det:%f\n", det);

    if (equal(det, 0.0f)) {
        MAT_PRINTF("err, determinate is 0 for MatInv\n");
        return NULL;
    }

    for (row = 0; row < src->row; row++) {
        for (col = 0; col < src->col; col++)
            dst->element[row][col] = adj_mat.element[row][col] / det;
    }

    MatDelete(&adj_mat);

    return dst;
}

void MatCopy(Mat* src, Mat* dst)
{
    int row, col;

#ifdef MAT_LEGAL_CHECKING

    if (src->row != dst->row || src->col != dst->col) {
        MAT_PRINTF("err check, unmathed matrix for MatCopy\n");
        MatDump(src);
        MatDump(dst);
        return;
    }

#endif

    for (row = 0; row < src->row; row++) {
        for (col = 0; col < src->col; col++)
            dst->element[row][col] = src->element[row][col];
    }
}

// Calculate eigen value and eigen vector of mat
// eps: accurancy
// njt: maximal iteration count
void MatEig(Mat* mat, MAT_TYPE* eig_val, Mat* eig_vec, MAT_TYPE eps, int njt)
{
    int i, j;
    int nDim = mat->row;

#ifdef MAT_LEGAL_CHECKING

    if (mat->row != mat->col) {
        MAT_PRINTF("err check, not a squre matrix for MatEig\n");
        MatDump(mat);
        return;
    }

#endif

    Mat temp_mat;
    MatCreate(&temp_mat, mat->row, mat->col);
    MatCopy(mat, &temp_mat);

    for (i = 0; i < nDim; i++) {
        eig_vec->element[i][i] = 1.0f;

        for (int j = 0; j < nDim; j++) {
            if (i != j)
                eig_vec->element[i][j] = 0.0f;
        }
    }

    int nCount = 0; //iteration count

    while (1) {
        //find maxial element in non-diagram of mat
        MAT_TYPE dbMax = temp_mat.element[0][1];
        int nRow = 0;
        int nCol = 1;

        for (i = 0; i < nDim; i++) {     //row
            for (j = 0; j < nDim; j++) { //col
                MAT_TYPE d = fabs(temp_mat.element[i][j]);

                if ((i != j) && (d > dbMax)) {
                    dbMax = d;
                    nRow = i;
                    nCol = j;
                }
            }
        }

        if (dbMax < eps) {
            break;
        }

        if (nCount > njt) {
            MAT_PRINTF("reach max njt\n");
            break;
        }

        nCount++;

        MAT_TYPE dbApp = temp_mat.element[nRow][nRow];
        MAT_TYPE dbApq = temp_mat.element[nRow][nCol];
        MAT_TYPE dbAqq = temp_mat.element[nCol][nCol];

        // calculate rotation angle
        MAT_TYPE dbAngle = 0.5 * atan2(-2 * dbApq, dbAqq - dbApp);
        MAT_TYPE dbSinTheta = sin(dbAngle);
        MAT_TYPE dbCosTheta = cos(dbAngle);
        MAT_TYPE dbSin2Theta = sin(2 * dbAngle);
        MAT_TYPE dbCos2Theta = cos(2 * dbAngle);

        temp_mat.element[nRow][nRow] = dbApp * dbCosTheta * dbCosTheta + dbAqq * dbSinTheta * dbSinTheta + 2 * dbApq * dbCosTheta * dbSinTheta;
        temp_mat.element[nCol][nCol] = dbApp * dbSinTheta * dbSinTheta + dbAqq * dbCosTheta * dbCosTheta - 2 * dbApq * dbCosTheta * dbSinTheta;
        temp_mat.element[nRow][nCol] = 0.5 * (dbAqq - dbApp) * dbSin2Theta + dbApq * dbCos2Theta;
        temp_mat.element[nCol][nRow] = temp_mat.element[nRow][nCol];

        for (i = 0; i < nDim; i++) {
            if ((i != nCol) && (i != nRow)) {
                dbMax = temp_mat.element[i][nRow];
                temp_mat.element[i][nRow] = temp_mat.element[i][nCol] * dbSinTheta + dbMax * dbCosTheta;
                temp_mat.element[i][nCol] = temp_mat.element[i][nCol] * dbCosTheta - dbMax * dbSinTheta;
            }
        }

        for (j = 0; j < nDim; j++) {
            if ((j != nCol) && (j != nRow)) {
                dbMax = temp_mat.element[nRow][j];
                temp_mat.element[nRow][j] = temp_mat.element[nCol][j] * dbSinTheta + dbMax * dbCosTheta;
                temp_mat.element[nCol][j] = temp_mat.element[nCol][j] * dbCosTheta - dbMax * dbSinTheta;
            }
        }

        // calculate eigen vector
        for (i = 0; i < nDim; i++) {
            dbMax = eig_vec->element[i][nRow];
            eig_vec->element[i][nRow] = eig_vec->element[i][nCol] * dbSinTheta + dbMax * dbCosTheta;
            eig_vec->element[i][nCol] = eig_vec->element[i][nCol] * dbCosTheta - dbMax * dbSinTheta;
        }
    }

    // calculate eigen value
    for (i = 0; i < nDim; i++) {
        eig_val[i] = temp_mat.element[i][i];
    }

    // set sign
    for (i = 0; i < nDim; i++) {
        MAT_TYPE dSumVec = 0;

        for (j = 0; j < nDim; j++)
            dSumVec += eig_vec->element[j][i];

        if (dSumVec < 0) {
            for (j = 0; j < nDim; j++)
                eig_vec->element[j][i] *= -1;
        }
    }

    MatDelete(&temp_mat);
}

MAT_TYPE MatNorm(Mat* mat)
{
    MAT_TYPE max_eig_val = 0.0f;

#ifdef MAT_LEGAL_CHECKING

    if (mat->row != mat->col) {
        MAT_PRINTF("err check, not a squre matrix for MatEig\n");
        MatDump(mat);
        return 0;
    }

#endif

    MAT_TYPE* eig_val = (MAT_TYPE*)MAT_MALLOC(mat->row * sizeof(MAT_TYPE));
    Mat eig_vec;
    MatCreate(&eig_vec, mat->row, mat->col);

    MatEig(mat, eig_val, &eig_vec, 1e-6, 100);

    for (int i = 0; i < mat->row; i++) {
        if (eig_val[i] > max_eig_val)
            max_eig_val = eig_val[i];
    }

    MAT_FREE(eig_val);
    MatDelete(&eig_vec);

    return max_eig_val;
}
