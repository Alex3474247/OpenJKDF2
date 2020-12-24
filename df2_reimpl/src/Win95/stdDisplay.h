#ifndef _STDDISPLAY_H
#define _STDDISPLAY_H

#include "Engine/rdMaterial.h"
#include "Primitives/rdRect.h"
#include "types.h"

#define stdDisplay_Startup_ADDR (0x0421FC0)
#define stdDisplay_RestoreDisplayMode_ADDR (0x04220B0)
#define stdDisplay_Open_ADDR (0x04220E0)
#define stdDisplay_Close_ADDR (0x04224D0)
#define stdDisplay_SetMode_ADDR (0x04226A0)
#define stdDisplay_422A50_ADDR (0x0422A50)
#define stdDisplay_ClearMode_ADDR (0x0422C30)
#define stdDisplay_DrawAndFlipGdi_ADDR (0x0422E80)
#define stdDisplay_SetCooperativeLevel_ADDR (0x0422F90)
#define stdDisplay_ddraw_surface_flip_ADDR (0x0422FC0)
#define stdDisplay_ddraw_surface_flip2_ADDR (0x0423050)
#define stdDisplay_ddraw_waitforvblank_ADDR (0x04230A0)
#define stdDisplay_VBufferNew_ADDR (0x04230C0)
#define stdDisplay_free_texture_ADDR (0x04232F0)
#define stdDisplay_423360_ADDR (0x0423360)
#define stdDisplay_VBufferLock_ADDR (0x04233C0)
#define stdDisplay_VBufferUnlock_ADDR (0x0423450)
#define stdDisplay_VBufferFill_ADDR (0x04234E0)
#define stdDisplay_streamidk_ADDR (0x0423740)
#define stdDisplay_VBufferCopy_ADDR (0x04237B0)
#define stdDisplay_VBufferSetColorKey_ADDR (0x0423830)
#define stdDisplay_VBufferConvertColorFormat_ADDR (0x0423880)
#define stdDisplay_sub_423B80_ADDR (0x0423B80)
#define stdDisplay_SetMasterPalette_ADDR (0x0423BB0)
#define stdDisplay_GammaCorrect_ADDR (0x0423CB0)
#define stdDisplay_GammaCorrect2_ADDR (0x0423D10)
#define stdDisplay_SetGammaTable_ADDR (0x0423E10)
#define stdDisplay_GammaCorrect3_ADDR (0x0423E30)
#define stdDisplay_GammaCorrect4_ADDR (0x0423F80)
#define stdDisplay_GetPalette_ADDR (0x0423FF0)
#define stdDisplay_SetPalette_ADDR (0x0424000)
#define stdDisplay_TextOut_ADDR (0x04240F0)
#define stdDisplay_FindClosestDevice_ADDR (0x04242B0)
#define stdDisplay_FindClosestMode_ADDR (0x0424340)
#define stdDisplay_GetModeInfo_ADDR (0x04243F0)
#define stdDisplay_sub_424440_ADDR (0x0424440)
#define stdDisplay_SortVideoModes_ADDR (0x04246E0)

typedef struct stdDeviceParams
{
  int field_0;
  int field_4;
  int field_8;
  int field_C;
  int field_10;
} stdDeviceParams;

typedef struct video_device
{
  int device_active;
  int hasGUID;
  int has3DAccel;
  int hasNoGuid;
  int windowedMaybe;
  int dwVidMemTotal;
  int dwVidMemFree;
} video_device;

typedef struct stdVideoMode
{
  int field_0;
  float widthMaybe;
  texture_format format;
} stdVideoMode;

typedef struct stdVideoDevice
{
  char driverDesc[128];
  char driverName[128];
  video_device video_device[14];
  GUID guid;
  int max_modes;
  stdVideoMode *stdVideoMode;
  uint32_t gap2A0;
  int field_2A4;
} stdVideoDevice;

typedef struct render_8bpp
{
  int bpp;
  int rBpp;
  int width;
  int height;
  int rShift;
  int gShift;
  int bShift;
  int palBytes;
} render_8bpp;

typedef struct render_rgb
{
  int bpp;
  int rBpp;
  int gBpp;
  int bBpp;
  int rShift;
  int gShift;
  int bShift;
  int rBytes;
  int gBytes;
  int bBytes;
} render_rgb;

typedef struct render_pair
{
  render_8bpp render_8bpp;
  render_rgb render_rgb;
  uint32_t field_48;
  uint32_t field_4C;
  uint32_t field_50;
} render_pair;

static int (*stdDisplay_FindClosestMode)(render_pair *a1, struct stdVideoMode *render_surface, unsigned int max_modes) = (void*)stdDisplay_FindClosestMode_ADDR;
static int (*stdDisplay_FindClosestDevice)(stdDeviceParams *a1) = (void*)stdDisplay_FindClosestDevice_ADDR;
static void (*stdDisplay_Close)() = (void*)stdDisplay_Close_ADDR;
static int (*stdDisplay_Open)(unsigned int index) = (void*)stdDisplay_Open_ADDR;
static int (*stdDisplay_SetMode)(unsigned int modeIdx, const void *palette, int paged) = (void*)stdDisplay_SetMode_ADDR;
static void (*stdDisplay_ddraw_waitforvblank)(void) = (void*)stdDisplay_ddraw_waitforvblank_ADDR;
static void (__cdecl *stdDisplay_free_texture)(stdVBuffer *a1) = (void*)stdDisplay_free_texture_ADDR;

static stdVBuffer* (__cdecl *stdDisplay_VBufferNew)(texture_format *a1, int create_ddraw_surface, int gpu_mem, int is_paletted) = (void*)stdDisplay_VBufferNew_ADDR;
static int (__cdecl *stdDisplay_VBufferSetColorKey)(stdVBuffer *a1, int color) = (void*)stdDisplay_VBufferSetColorKey_ADDR;
static int (__cdecl *stdDisplay_VBufferLock)(stdVBuffer *a1) = (void*)stdDisplay_VBufferLock_ADDR;
static void (__cdecl *stdDisplay_VBufferUnlock)(stdVBuffer *a1) = (void*)stdDisplay_VBufferUnlock_ADDR;
static int (*stdDisplay_VBufferCopy)(stdVBuffer *vbuf, stdVBuffer *vbuf2, unsigned int blit_x, int blit_y, rdRect *rect, int alpha_maybe) = (void*)stdDisplay_VBufferCopy_ADDR;
static int (*stdDisplay_SetMasterPalette)(uint8_t* pal) = (void*)stdDisplay_SetMasterPalette_ADDR;
static int (*stdDisplay_streamidk)(stdVBuffer *buf, int fillColor, rdRect *rect) = (void*)stdDisplay_streamidk_ADDR;
static void (*stdDisplay_DrawAndFlipGdi)() = (void*)stdDisplay_DrawAndFlipGdi_ADDR;
static void (*stdDisplay_SetCooperativeLevel)() = (void*)stdDisplay_SetCooperativeLevel_ADDR;
static int (*stdDisplay_ddraw_surface_flip)() = (void*)stdDisplay_ddraw_surface_flip_ADDR;
static void (*stdDisplay_422A50)() = (void*)stdDisplay_422A50_ADDR;

#define Video_curMode (*(int*)0x00866D7C)
#define Video_otherBuf (*(stdVBuffer*)0x866CA0)
#define Video_dword_866D78 (*(int*)0x866D78)
#define Video_menuBuffer (*(stdVBuffer*)0x86AC00)
#define Video_renderSurface ((stdVideoMode*)0x00866D80)
#define stdDisplay_pCurDevice (*(stdVideoDevice**)0x0055B3E8)
#define stdDisplay_pCurVideoMode (*(stdVideoMode **)0x0055B3F0)
#define stdDisplay_bOpen (*(int*)0x55B3DC)
#define stdDisplay_bModeSet (*(int*)0x55B3E0)
#define stdDisplay_numVideoModes (*(int*)0x055B3EC)
#define stdDisplay_bPaged (*(int*)0x55B3F4)

#endif // _STDDISPLAY_H