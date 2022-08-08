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
#include <FMS.h>
#include <firmament.h>

/* FMS output topic */
MCN_DEFINE(fms_output, sizeof(FMS_Out_Bus));
/* Model information */
fmt_model_info_t fms_model_info;

void fms_interface_step(void)
{
    /* Add your code here */
}

void fms_interface_init(void)
{
    /* Fill in the modle information */
    fms_model_info.period = 10;
    fms_model_info.info = "Template FMS";

    /* advertise fms_output topic */
    mcn_advertise(MCN_HUB(fms_output), NULL);

    /* Add your code here */
}
