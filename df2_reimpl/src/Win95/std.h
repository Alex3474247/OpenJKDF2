#ifndef _STDLEC_H
#define _STDLEC_H

#define stdStartup_ADDR (0x00426BB0)
#define stdShutdown_ADDR (0x00426C10)
#define stdInitServices_ADDR (0x00426C30)
#define stdFileOpen_ADDR (0x00426C40)
#define stdFileClose_ADDR (0x00426C60)
#define stdFileRead_ADDR (0x00426C70)
#define stdFileWrite_ADDR (0x00426C90)
#define stdFileGets_ADDR (0x00426CB0)
#define stdFileGetws_ADDR (0x00426CD0)
#define stdFeof_ADDR (0x00426CF0)
#define stdFtell_ADDR (0x00426D00)
#define stdFseek_ADDR (0x00426D10)
#define stdFileSize_ADDR (0x00426D30)
#define stdPrintf_ADDR (0x00426D80)
#define stdFilePrintf_ADDR (0x00426E20)
#define stdConsolePrintf_ADDR (0x00426E60)
#define stdAssert_ADDR (0x00426EA0)
#define stdDebugMalloc_ADDR (0x00426EC0)
#define stdDebugFree_ADDR (0x00426F00)
#define stdDebugRealloc_ADDR (0x00426F30)
#define stdDelay_ADDR (0x00426F70)
#define stdReadLine_ADDR (0x00426FB0)
#define stdGetReturnString_ADDR (0x00427020)
#define stdFileFromPath_ADDR (0x00427060)
#define stdCalcBitPos_ADDR (0x00427080)
#define stdReadRaw_ADDR (0x004270A0)
#define stdFGetc_ADDR (0x004270F0)
#define stdFPutc_ADDR (0x00427110)
#define stdLoadImage_ADDR (0x00427130)
#define stdWriteImage_ADDR (0x00427280)
#define stdBuildDisplayEnvironment_ADDR (0x004273E0)
#define stdFreeDisplayEnvironment_ADDR (0x00427730)

char* stdFileFromPath(char *fpath);
int stdCalcBitPos(signed int val);
int stdReadRaw(char *fpath, void *out, signed int len);
char stdFGetc(int fd);
void stdFPutc(char c, int fd);

#endif // _STDLEC_H