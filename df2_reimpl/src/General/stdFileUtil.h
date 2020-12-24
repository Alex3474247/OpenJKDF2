#ifndef _STDFILEUTIL_H
#define _STDFILEUTIL_H

#define stdFileUtil_NewFind_ADDR (0x00431740)
#define stdFileUtil_DisposeFind_ADDR (0x004317E0)
#define stdFileUtil_FindReset_ADDR (0x00431820)
#define stdFileUtil_FindNext_ADDR (0x00431850)
#define stdFileUtil_FindQuick_ADDR (0x00431910)
#define stdFileUtil_CountMatches_ADDR (0x00431A70)
#define stdFileUtil_MkDir_ADDR (0x00431BC0)
#define stdFileUtil_DirExists_ADDR (0x00431BD0)
#define stdFileUtil_RmDir_ADDR (0x00431C00)
#define stdFileUtil_DelFile_ADDR (0x00431C10)
#define stdFileUtil_Deltree_ADDR (0x00431C20)

typedef struct stdFileSearch
{
  int field_0;
  int field_4;
  char path[128];
  int field_88;
} stdFileSearch;

static int (*stdFileUtil_MkDir)(char* lpPathName) = (void*)stdFileUtil_MkDir_ADDR;
static stdFileSearch* (*stdFileUtil_NewFind)(char *path, int a2, char *extension) = (void*)stdFileUtil_NewFind_ADDR;
static int (*stdFileUtil_FindNext)(stdFileSearch *a1, char *a2) = (void*)stdFileUtil_FindNext_ADDR;
static void (*stdFileUtil_DisposeFind)(stdFileSearch *a1) = (void*)stdFileUtil_DisposeFind_ADDR;

#endif // _STDFILEUTIL_H