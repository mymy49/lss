#ifndef STM32F429_FMC__H_
#define STM32F429_FMC__H_

#include "peripheral.h"

// @brief Flexible Memory Controller

typedef struct
{
  volatile unsigned long BTCR[8];    //!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C     
} FMC_Bank1_TypeDef; 


// @brief Flexible Memory Controller Bank1E
 
typedef struct
{
  volatile unsigned long BWTR[7];    //!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C  
} FMC_Bank1E_TypeDef;


// @brief Flexible Memory Controller Bank2
  
typedef struct
{
  volatile unsigned long PCR2;       //!< NAND Flash control register 2,                       Address offset: 0x60  
  volatile unsigned long SR2;        //!< NAND Flash FIFO status and interrupt register 2,     Address offset: 0x64  
  volatile unsigned long PMEM2;      //!< NAND Flash Common memory space timing register 2,    Address offset: 0x68  
  volatile unsigned long PATT2;      //!< NAND Flash Attribute memory space timing register 2, Address offset: 0x6C  
  unsigned long      RESERVED0;  //!< Reserved, 0x70                                                             
  volatile unsigned long ECCR2;      //!< NAND Flash ECC result registers 2,                   Address offset: 0x74  
  unsigned long      RESERVED1;  //!< Reserved, 0x78                                                             
  unsigned long      RESERVED2;  //!< Reserved, 0x7C                                                             
  volatile unsigned long PCR3;       //!< NAND Flash control register 3,                       Address offset: 0x80  
  volatile unsigned long SR3;        //!< NAND Flash FIFO status and interrupt register 3,     Address offset: 0x84  
  volatile unsigned long PMEM3;      //!< NAND Flash Common memory space timing register 3,    Address offset: 0x88  
  volatile unsigned long PATT3;      //!< NAND Flash Attribute memory space timing register 3, Address offset: 0x8C  
  unsigned long      RESERVED3;  //!< Reserved, 0x90                                                             
  volatile unsigned long ECCR3;      //!< NAND Flash ECC result registers 3,                   Address offset: 0x94  
} FMC_Bank2_3_TypeDef;


// @brief Flexible Memory Controller Bank4
   
typedef struct
{
  volatile unsigned long PCR4;       //!< PC Card  control register 4,                       Address offset: 0xA0  
  volatile unsigned long SR4;        //!< PC Card  FIFO status and interrupt register 4,     Address offset: 0xA4  
  volatile unsigned long PMEM4;      //!< PC Card  Common memory space timing register 4,    Address offset: 0xA8  
  volatile unsigned long PATT4;      //!< PC Card  Attribute memory space timing register 4, Address offset: 0xAC  
  volatile unsigned long PIO4;       //!< PC Card  I/O space timing register 4,              Address offset: 0xB0  
} FMC_Bank4_TypeDef; 


// @brief Flexible Memory Controller Bank5_6
   
typedef struct
{
  volatile unsigned long SDCR[2];        //!< SDRAM Control registers ,      Address offset: 0x140-0x144   
  volatile unsigned long SDTR[2];        //!< SDRAM Timing registers ,       Address offset: 0x148-0x14C   
  volatile unsigned long SDCMR;       //!< SDRAM Command Mode register,    Address offset: 0x150   
  volatile unsigned long SDRTR;       //!< SDRAM Refresh Timer register,   Address offset: 0x154   
  volatile unsigned long SDSR;        //!< SDRAM Status register,          Address offset: 0x158   
} FMC_Bank5_6_TypeDef; 

#define FMC_SDRAM_BANK1		0
#define FMC_SDRAM_BANK2		1

#define FMC_SDRAM_RPIPE_NO_HCLK_DELAY	0
#define FMC_SDRAM_RPIPE_1_HCLK_DELAY	1
#define FMC_SDRAM_RPIPE_2_HCLK_DELAY	2

#define FMC_SDRAM_INT_BANK_TWO			false
#define FMC_SDRAM_INT_BANK_FOUR			true

#define FMC_SDRAM_DBUS_WIDTH_8BIT		0
#define FMC_SDRAM_DBUS_WIDTH_16BIT		1
#define FMC_SDRAM_DBUS_WIDTH_32BIT		2

#define FMC_SDRAM_ROW_ADDR_11BIT		0
#define FMC_SDRAM_ROW_ADDR_12BIT		1
#define FMC_SDRAM_ROW_ADDR_13BIT		2

#define FMC_SDRAM_COL_ADDR_8BIT			0
#define FMC_SDRAM_COL_ADDR_9BIT			1
#define FMC_SDRAM_COL_ADDR_10BIT		2
#define FMC_SDRAM_COL_ADDR_11BIT		3

#define FMC_SDRAM_SDCMR_BURST_LENGTH_1				((unsigned short)0x0000)
#define FMC_SDRAM_SDCMR_BURST_LENGTH_2				((unsigned short)0x0001)
#define FMC_SDRAM_SDCMR_BURST_LENGTH_4				((unsigned short)0x0002)
#define FMC_SDRAM_SDCMR_BURST_LENGTH_8				((unsigned short)0x0004)
#define FMC_SDRAM_SDCMR_BURST_TYPE_SEQUENTIAL		((unsigned short)0x0000)
#define FMC_SDRAM_SDCMR_BURST_TYPE_INTERLEAVED		((unsigned short)0x0008)
#define FMC_SDRAM_SDCMR_CAS_LATENCY_2				((unsigned short)0x0020)
#define FMC_SDRAM_SDCMR_CAS_LATENCY_3				((unsigned short)0x0030)
#define FMC_SDRAM_SDCMR_OPERATING_MODE_STANDARD		((unsigned short)0x0000)
#define FMC_SDRAM_SDCMR_WRITEBURST_MODE_PROGRAMMED	((unsigned short)0x0000) 
#define FMC_SDRAM_SDCMR_WRITEBURST_MODE_SINGLE		((unsigned short)0x0200)      


#include "fmc/sdram.h"

#endif
