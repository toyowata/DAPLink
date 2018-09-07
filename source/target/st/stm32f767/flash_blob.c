/* Flash OS Routines (Automagically Generated)
 * Copyright (c) 2009-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

static const uint32_t stm32f7xx_2048_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x8f4ff3bf, 0xf3c04770, 0x283f300b, 0x2104bf26, 0x1090eb01, 0x477008c0, 0x49774878, 0x49786001,
    0x20006001, 0x60084977, 0x68014877, 0x01f0f041, 0x48766001, 0xf0106800, 0xd1080f20, 0xf2454874,
    0x60015155, 0x60412106, 0x71fff640, 0x20006081, 0x486d4770, 0xf4116801, 0xbf1c3f80, 0x21aaf64a,
    0xd0044a6b, 0x68036011, 0x3f80f413, 0x4869d1fa, 0xf0416801, 0x60014100, 0x47702000, 0x68014862,
    0x22aaf64a, 0x3f80f411, 0xd0044961, 0x6803600a, 0x3f80f413, 0xf8dfd1fa, 0xf8dcc17c, 0xf0433000,
    0xf8cc0304, 0xf8dc3000, 0xf4433000, 0xf8cc3380, 0x68033000, 0x3f80f413, 0x600ad004, 0xf4136803,
    0xd1fa3f80, 0x0000f8dc, 0x0004f020, 0x0000f8cc, 0x47702000, 0x300bf3c0, 0xb430283f, 0x2104bf26,
    0x1c90eb01, 0x0cd0ea4f, 0x68014847, 0x01f0f041, 0x68016001, 0x22aaf64a, 0x3f80f411, 0xd0044944,
    0x6803600a, 0x3f80f413, 0x4c42d1fa, 0x60232302, 0x25f86823, 0x0cccea05, 0x030cea43, 0x68236023,
    0x3380f443, 0x68036023, 0x3f80f413, 0x600ad004, 0xf4136803, 0xd1fa3f80, 0xf0216821, 0x60210102,
    0xf0116801, 0xbf020ff0, 0xbc302000, 0x68014770, 0x01f0f041, 0xbc306001, 0x47702001, 0xc0a8f8df,
    0xb4f01cc9, 0x0103f021, 0x3000f8dc, 0x03f0f043, 0x3000f8cc, 0x3000f8dc, 0x25aaf64a, 0xf4134e24,
    0xd0053f80, 0xf8dc6035, 0xf4133000, 0xd1f93f80, 0x23004c20, 0x29006023, 0xf240bf18, 0xd0282701,
    0x433b6823, 0x68136023, 0xf3bf6003, 0xf8dc8f4f, 0xf4133000, 0xd0053f80, 0xf8dc6035, 0xf4133000,
    0xd1f93f80, 0xf0236823, 0x60230301, 0x3000f8dc, 0x0ff0f013, 0xf8dcd008, 0xf0400000, 0xf8cc00f0,
    0xbcf00000, 0x47702001, 0x1f091d00, 0x0204f102, 0xbcf0d1d6, 0x47702000, 0x45670123, 0x40023c04,
    0xcdef89ab, 0x40023c00, 0x40023c0c, 0x40023c14, 0x40003000, 0x40023c10, 0x00000000
};

// Start address of flash
static const uint32_t flash_start = 0x08000000;
// Size of flash
static const uint32_t flash_size = 0x00200000;

/**
* List of start and size for each size of flash sector - even indexes are start, odd are size
* The size will apply to all sectors between the listed address and the next address
* in the list.
* The last pair in the list will have sectors starting at that address and ending
* at address flash_start + flash_size.
*/
static const uint32_t sectors_info[] = {
    0x08000000, 0x00008000,
    0x08020000, 0x00020000,
    0x08040000, 0x00040000,
};

static const program_target_t flash = {
    0x20020039, // Init
    0x20020073, // UnInit
    0x2002009d, // EraseChip
    0x200200f5, // EraseSector
    0x2002017d, // ProgramPage

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20020001,
        0x20020238,
        0x20020800
    },

    0x20020000 + 0x00000A00,  // mem buffer location
    0x20020000,               // location to write prog_blob in target RAM
    sizeof(stm32f7xx_2048_flash_prog_blob),   // prog_blob size
    stm32f7xx_2048_flash_prog_blob,           // address of prog_blob
    0x00000200       // ram_to_flash_bytes_to_be_written
};