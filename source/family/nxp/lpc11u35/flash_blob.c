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

static const uint32_t lpc11u35_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x47700b00, 0x22004841, 0x21016302, 0x63426341, 0x63816341, 0x2002493e, 0x46106008, 0x20004770,
    0xb5f84770, 0x20324c3b, 0x444c2500, 0x60a6260f, 0x60654939, 0x44496020, 0x46204f38, 0x47b89100,
    0x28006960, 0x60a6d10b, 0x60652034, 0x48346020, 0x462060e0, 0x47b89900, 0x28006960, 0x2001d000,
    0xb5f8bdf8, 0x0b044d2b, 0x606c444d, 0x2032492a, 0x444960ac, 0x4e296028, 0x4628460f, 0x696847b0,
    0xd10b2800, 0x2034606c, 0x602860ac, 0x60e84824, 0x46284639, 0x696847b0, 0xd0002800, 0xbdf82001,
    0x4614b5f8, 0xd10e0005, 0x68206861, 0x184068e2, 0x188968a1, 0x69211840, 0x69611840, 0x69a11840,
    0x42401840, 0x4e1361e0, 0x444e0b28, 0x60702132, 0x49116031, 0x444960b0, 0x46304f10, 0x47b89100,
    0x28006970, 0x6075d10e, 0x60b42033, 0x20ff6030, 0x60f03001, 0x6130480a, 0x99004630, 0x697047b8,
    0xd0002800, 0xbdf82001, 0x47702000, 0x40048040, 0x40048000, 0x00000004, 0x00000018, 0x1fff1ff1,
    0x00002ee0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000
};

// Start address of flash
static const uint32_t flash_start = 0x00000000;
// Size of flash
static const uint32_t flash_size = 0x00010000;

/**
* List of start and size for each size of flash sector - even indexes are start, odd are size
* The size will apply to all sectors between the listed address and the next address
* in the list.
* The last pair in the list will have sectors starting at that address and ending
* at address flash_start + flash_size.
*/
static const sector_info_t sectors_info[] = {
    0x00000000, 0x00001000,
};

static const program_target_t flash = {
    0x10000025, // Init
    0x1000003f, // UnInit
    0x10000043, // EraseChip
    0x10000083, // EraseSector
    0x100000c1, // ProgramPage
    0,          // Verify

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x10000001,
        0x10000144,
        0x10002000 - 32
    },

    0x10000000 + 0x00000A00,  // mem buffer location
    0x10000000,               // location to write prog_blob in target RAM
    sizeof(lpc11u35_flash_prog_blob),   // prog_blob size
    lpc11u35_flash_prog_blob,           // address of prog_blob
    0x00000100       // ram_to_flash_bytes_to_be_written
};
