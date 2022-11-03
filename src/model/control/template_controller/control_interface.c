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

#include <Controller.h>
#include <firmament.h>

/* controller output topic */
MCN_DEFINE(control_output, sizeof(Control_Out_Bus));
/* Model information */
fmt_model_info_t control_model_info;

void control_interface_step(void)
{
    /* Add your code here */
}

void control_interface_init(void)
{
    /* Fill in the modle information */
    control_model_info.period = 10;
    control_model_info.info = "Template Controller";

    /* advertise control_output topic */
    mcn_advertise(MCN_HUB(control_output), NULL);

    /* Add your code here */
}