#ifndef STM32F429_FMC_SDRAM__H_
#define STM32F429_FMC_SDRAM__H_

inline void setMcuFmcSdramTrcd(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDTR[bank];
	buf &= ~(0xFUL << 24);
	buf |= (val << 24 & 0xFUL << 24);
	FMC_Bank5_6->SDTR[bank] = buf;
}

inline void setMcuFmcSdramTrp(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDTR[bank];
	buf &= ~(0xFUL << 20);
	buf |= (val << 20 & 0xFUL << 20);
	FMC_Bank5_6->SDTR[bank] = buf;
}

inline void setMcuFmcSdramTwr(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDTR[bank];
	buf &= ~(0xFUL << 16);
	buf |= (val << 16 & 0xFUL << 16);
	FMC_Bank5_6->SDTR[bank] = buf;
}

inline void setMcuFmcSdramTrc(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDTR[bank];
	buf &= ~(0xFUL << 12);
	buf |= (val << 12 & 0xFUL << 12);
	FMC_Bank5_6->SDTR[bank] = buf;
}

inline void setMcuFmcSdramTras(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDTR[bank];
	buf &= ~(0xFUL << 8);
	buf |= (val << 8 & 0xFUL << 8);
	FMC_Bank5_6->SDTR[bank] = buf;
}

inline void setMcuFmcSdramTxsr(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDTR[bank];
	buf &= ~(0xFUL << 4);
	buf |= (val << 4 & 0xFUL << 4);
	FMC_Bank5_6->SDTR[bank] = buf;
}

inline void setMcuFmcSdramTmrd(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDTR[bank];
	buf &= ~(0xFUL << 0);
	buf |= (val << 0 & 0xFUL << 0);
	FMC_Bank5_6->SDTR[bank] = buf;
}

inline void setMcuFmcSdramRpipe(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(0x3UL << 13);
	buf |= (val << 13 & 0x3UL << 13);
	FMC_Bank5_6->SDCR[bank] = buf;
}

inline void setMcuFmcSdramRburstEn(unsigned char bank, bool val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(1UL << 12);
	buf |= (val << 12 & 1UL << 12);
	FMC_Bank5_6->SDCR[bank] = buf;
}


inline void setMcuFmcSdramSdclk(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(0x3UL << 10);
	buf |= (val << 10 & 0x3UL << 10);
	FMC_Bank5_6->SDCR[bank] = buf;
}

struct FmcSdramSdcr
{
	unsigned nc : 2;
	unsigned nr : 2;
	unsigned mwid : 2;
	unsigned nb : 1;
	unsigned cas : 2;
	unsigned wp : 1;
	unsigned sdclk : 2;
	unsigned rburst : 1;
	unsigned rpipe : 2;
	unsigned rsv : 16;
};

inline void setMcuFmcSdramSdcr1(FmcSdramSdcr obj)
{
	unsigned long *buf = (unsigned long*)(&obj);
	FMC_Bank5_6->SDCR[0] = *buf;
}

inline void setMcuFmcSdramSdcr2(FmcSdramSdcr obj)
{
	unsigned long lsdcr = FMC_Bank5_6->SDCR[0];
	unsigned long *psdcr = (unsigned long*)(&obj);
	FmcSdramSdcr *ssdcr = (FmcSdramSdcr*)(&lsdcr);

	lsdcr &= ~(0x7fffUL);
	ssdcr->rburst = obj.rburst;
	ssdcr->rpipe = obj.rpipe;
	ssdcr->sdclk = obj.sdclk;
	
    FMC_Bank5_6->SDCR[0] = lsdcr;
	FMC_Bank5_6->SDCR[1] = *psdcr;
}

inline void setMcuFmcSdramWp(unsigned char bank, bool val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(1UL << 9);
	buf |= (val << 9 & 1UL << 9);
	FMC_Bank5_6->SDCR[bank] = buf;
}

inline void setMcuFmcSdramCas(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(0x3UL << 7);
	buf |= (val << 7 & 0x3UL << 7);
	FMC_Bank5_6->SDCR[bank] = buf;
}

inline void setMcuFmcSdramNb(unsigned char bank, bool val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(1UL << 6);
	buf |= (val << 6 & 1UL << 6);
	FMC_Bank5_6->SDCR[bank] = buf;
}

inline void setMcuFmcSdramMwid(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(0x3UL << 4);
	buf |= (val << 4 & 0x3UL << 4);
	FMC_Bank5_6->SDCR[bank] = buf;
}

inline void setMcuFmcSdramNr(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(0x3UL << 2);
	buf |= (val << 2 & 0x3UL << 2);
	FMC_Bank5_6->SDCR[bank] = buf;
}

inline void setMcuFmcSdramNc(unsigned char bank, unsigned char val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDCR[bank];
	buf &= ~(0x3UL << 0);
	buf |= (val << 0 & 0x3UL << 0);
	FMC_Bank5_6->SDCR[bank] = buf;
}

inline void waitMcuFmcSdramBusy(void)
{
	while(FMC_Bank5_6->SDSR & (1 << 5));
}


inline void setMcuFmcSdramCmd(unsigned short mrd, unsigned char nrfs, bool ctb1, bool ctb2, unsigned char mode)
{
	FMC_Bank5_6->SDCMR = (mrd << 9 & 0x1FFFUL << 9) | (nrfs << 5 & 0xFUL << 5) | (ctb1 << 4) | (ctb2 << 3) | (mode & 0x7UL);
}


inline void setMcuFmcSdramRtr(unsigned short val)
{
	unsigned long buf;
	
    buf = FMC_Bank5_6->SDRTR;
	buf &= ~(0xFFFUL << 1);
	buf |= (val << 1 & 0xFFFUL << 1);
	FMC_Bank5_6->SDRTR = buf;
}


#endif
