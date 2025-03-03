

/*
  data structure
  0x000000 - 0x007FFF
  0x008000 - 0x00FFFF
  0x010000 - 0x017FFF
  0x018000 - 0x01FFFF
  0x020000 - 0x027FFF
  0x028000 - 0x02FFFF
  0x030000 - 0x037FFF
  0x038000 - 0x03FFFF
  0x040000 - 0x047FFF
  0x048000 - 0x04FFFF
  0x050000 - 0x057FFF
  0x058000 - 0x05FFFF
  0x060000 - 0x067FFF
  0x068000 - 0x06FFFF
  0x070000 - 0x077FFF
  0x078000 - 0x07FFFF
  0x080000 - 0x087FFF
  0x087000 - 0x08FFFF
  0x090000 - 0x097FFF
  0x098000 - 0x09FFFF
  0x0A0000 - 0x0A7FFF
  0x0A8000 - 0x0AFFFF
  0x0B0000 - 0x0B7FFF
  0x0B8000 - 0x0BFFFF
  0x0C0000 - 0x0C7FFF
  0x0C8000 - 0x0CFFFF
  0x0D0000 - 0x0D7FFF
  0x0D8000 - 0x0DFFFF
  0x0E0000 - 0x0E7FFF
  0x0E8000 - 0x0EFFFF
  0x0F0000 - 0x0F7FFF
  0x0F8000 - 0x0FFFFF


*/
#ifndef AT25SF_H_
#define AT25SF_H_

#include <util.h>


#define OPCODE_SLOWREAD_ARRAY 0x03
#define OPCODE_FASTREAD_ARRAY 0x0b
#define OPCODE_WRITEENABLE    0x06
#define OPCODE_PROGRAM        0x02
#define OPCODE_04K_ERASE      0x20  // Erase a  4K block
#define OPCODE_32K_ERASE      0x52
#define OPCODE_CHIP_ERASE     0x60
#define OPCODE_READSTATUS     0x05

static const uint32_t memoryBlock34KHeaders[] = {0x000000, 0x008000, 0x010000, 0x018000, 0x020000, 0x028000, 0x030000, 0x038000,
                                                 0x040000, 0x048000, 0x050000, 0x058000, 0x060000, 0x068000, 0x070000, 0x078000,
                                                 0x080000, 0x087000, 0x090000, 0x098000, 0x0A0000, 0x0A8000, 0x0B0000, 0x0B8000,
                                                 0x0C0000, 0x0C8000, 0x0D0000, 0x0D8000, 0x0E0000, 0x0E8000, 0x0F0000, 0x0F8000
                                                };

void AT25SFWriteEnable();

void AT25SFChipErase();

void AT25SFHoldTillReady();

uint8_t AT25SFGetByte(uint32_t address);

void AT25SFWriteBytes(uint32_t address, u8_t len, uint8_t *bytes);

void AT25SFErace32KBlock(uint32_t address);

void AT25SFErace4KBlock(uint32_t address);

u8_t AT25SESplitPageWrite(u8_t startingAddress, u8_t len, u8_t *data);

u8_t AT25SEWritePage(u32_t startingAddress, u8_t *data);

void AT25SEreadSample(u32_t startingAddress, u8_t len, u8_t *data);

void AT25SEreadPage(u32_t startingAddress, u8_t *data);

#endif
