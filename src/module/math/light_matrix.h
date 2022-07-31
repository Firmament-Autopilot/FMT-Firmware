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

#ifndef LIGHT_MATRIX__
#define LIGHT_MATRIX__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAT_TYPE   float
#define MAT_MALLOC rt_malloc
#define MAT_FREE   rt_free
#define MAT_PRINTF console_printf

typedef struct {
    int row, col;
    MAT_TYPE** element;
    MAT_TYPE* buffer;
} Mat;

Mat* MatCreate(Mat* mat, int row, int col);
void MatDelete(Mat* mat);
Mat* MatSetVal(Mat* mat, MAT_TYPE* val);
void MatDump(const Mat* mat);

Mat* MatZeros(Mat* mat);
Mat* MatEye(Mat* mat);

Mat* MatAdd(Mat* src1, Mat* src2, Mat* dst);
Mat* MatSub(Mat* src1, Mat* src2, Mat* dst);
Mat* MatMul(Mat* src1, Mat* src2, Mat* dst);
Mat* MatTrans(Mat* src, Mat* dst);
MAT_TYPE MatDet(Mat* mat);
Mat* MatAdj(Mat* src, Mat* dst);
Mat* MatInv(Mat* src, Mat* dst);

MAT_TYPE MatNorm(Mat* mat);
void MatEig(Mat* mat, MAT_TYPE* eig_val, Mat* eig_vec, MAT_TYPE eps, int njt);

void MatCopy(Mat* src, Mat* dst);

#ifdef __cplusplus
}
#endif

#endif
