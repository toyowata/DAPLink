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
    0x8f4ff3bf, 0xf3c04770, 0x283f300b, 0x2104bf26, 0x1090eb01, 0x477008c0, 0x49654866, 0x49666001,
    0x20006001, 0x60084965, 0x68014865, 0x01f0f041, 0x48646001, 0xf0106800, 0xd1080f20, 0xf2454862,
    0x60015155, 0x60412106, 0x71fff640, 0x20006081, 0x485e4770, 0xf0416801, 0x60014100, 0x47702000,
    0xc168f8df, 0x0000f8dc, 0x0004f040, 0x0000f8cc, 0x0000f8dc, 0x3080f440, 0x0000f8cc, 0x0004f1ac,
    0xf4116801, 0xbf1c3f80, 0x21aaf64a, 0xd0044a4e, 0x68036011, 0x3f80f413, 0xf8dcd1fa, 0xf0200000,
    0xf8cc0004, 0x20000000, 0xf3c04770, 0x283f300b, 0x2104bf26, 0x1190eb01, 0x484108c1, 0xf0426802,
    0x600202f0, 0x0c04f100, 0xf8cc2202, 0xf8dc2000, 0x23f82000, 0x01c1ea03, 0xf8cc4311, 0xf8dc1000,
    0xf4411000, 0xf8cc3180, 0x68011000, 0x3f80f411, 0xf64abf1c, 0x4a3421aa, 0x6011d004, 0xf4136803,
    0xd1fa3f80, 0x1000f8dc, 0x0102f021, 0x1000f8cc, 0xf0116801, 0xbf040ff0, 0x47702000, 0xf0416801,
    0x600101f0, 0x47702001, 0xc094f8df, 0xb4f01cc9, 0x0103f031, 0x3000f8dc, 0x03f0f043, 0x3000f8cc,
    0x0404f10c, 0x0300f04f, 0xd02d6023, 0xf2404e1e, 0xf64a2701, 0x682325aa, 0x6023433b, 0x60036813,
    0x8f4ff3bf, 0x3000f8dc, 0x3f80f413, 0x6035d005, 0x3000f8dc, 0x3f80f413, 0x6823d1f9, 0x0301f023,
    0xf8dc6023, 0xf0133000, 0xd0080ff0, 0x0000f8dc, 0x00f0f040, 0x0000f8cc, 0x2001bcf0, 0x1d004770,
    0xf1021f09, 0xd1d60204, 0x2000bcf0, 0x00004770, 0x45670123, 0x40023c04, 0xcdef89ab, 0x40023c00,
    0x40023c0c, 0x40023c14, 0x40003000, 0x40023c10, 0x00000000
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
    0x20000039, // Init
    0x20000073, // UnInit
    0x20000081, // EraseChip
    0x200000cb, // EraseSector
    0x20000149, // ProgramPage

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000001,
        0x200001f0,
        0x20000800
    },

    0x20000000 + 0x00000A00,  // mem buffer location
    0x20000000,               // location to write prog_blob in target RAM
    sizeof(stm32f7xx_2048_flash_prog_blob),   // prog_blob size
    stm32f7xx_2048_flash_prog_blob,           // address of prog_blob
    0x00000200       // ram_to_flash_bytes_to_be_written
};
