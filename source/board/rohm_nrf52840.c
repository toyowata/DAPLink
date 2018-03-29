/**
 * @file    rohm_nrf52840.c
 * @brief   board ID for the Rohm nRF52840 board
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2017, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "virtual_fs.h"
#include "target_config.h"

const char *board_id = "1150";

const vfs_filename_t daplink_drive_name =     "MBED       ";

extern target_cfg_t target_device_nrf52840;

void prerun_board_config(void)
{
    target_device = target_device_nrf52840;
}
