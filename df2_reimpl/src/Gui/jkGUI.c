#include "jkGUI.h"

#include "General/Darray.h"
#include "General/stdBitmap.h"
#include "General/stdFont.h"
#include "General/stdString.h"
#include "Engine/rdMaterial.h" // TODO move stdVBuffer
#include "Primitives/rdVector.h"
#include "Win95/stdDisplay.h"
#include "Win95/stdControl.h"
#include "Win95/Window.h"
#include "Win95/stdGdi.h"
#include "Win95/wuRegistry.h"
#include "Win95/Windows.h"
#include "stdPlatform.h"
#include "jk.h"
#include "Gui/jkGUIRend.h"
#include "Gui/jkGUITitle.h"
#include "World/jkPlayer.h"
#include "Main/Main.h"
#include "Main/jkGame.h"
#include "Cog/jkCog.h"

const char* jkGui_aBitmaps[35] = {
    "bkMain.bm",
    "bkSingle.bm",
    "bkMulti.bm",
    "bkSetup.bm",
    "bkEsc.bm",
    "bkLoading.bm",
    "bkFieldLog.bm",
    "bkDialog.bm",
    "bkEsc.bm",
    "bkForce.bm",
    "bkTally.bm",
    "bkBuildMulti.bm",
    "bkBuildLoad.bm",
    "up15.bm",
    "down15.bm",
    "check.bm",
    "objectivescheck.bm",
    "sliderThumb.bm",
    "sliderBack.bm",
    "sliderBack200.bm",
    "flOk.bm",
    "flRotLef.bm",
    "flRotRig.bm",
    "flRotUp.bm",
    "flRotDow.bm",
    "flPlus.bm",
    "flMinus.bm",
    "flTransLeft.bm",
    "flTransRight.bm",
    "flTransUp.bm",
    "flTransDown.bm",
    "flSpin.bm",
    "flReset.bm",
    "arrowLeft.bm",
    "arrowRight.bm"
};

const char* jkGui_aFonts[12] = {
    "small0.sft",
    "small1.sft",
    "med0.sft",
    "med1.sft",
    "med2.sft",
    "large0.sft",
    "large1.sft",
    "large2.sft",
    "FLFont0.sft",
    "FLFont1.sft",
    "FLFont2.sft",
    "FLTitle.sft"
};

static int jkGui_bInitialized;

void jkGui_InitMenu(jkGuiMenu *menu, stdBitmap *bgBitmap)
{
    if ( bgBitmap )
    {
        menu->palette = (char *)bgBitmap->palette;
        menu->texture = bgBitmap->mipSurfaces[0];
    }
    
    jkGuiElement* iter = menu->clickables;
    while ( iter->type != 9 )
    {
        if ( iter->hintText )
        {
            wchar_t* text = jkStrings_GetText2((const char *)iter->hintText);
            if ( text )
                iter->hintText = (jkGuiStringEntry *)text;
        }

        if ( !iter->type || iter->type == 2 || iter->type == 3 )
        {
            if ( iter->unistr )
            {
                wchar_t* text = jkStrings_GetText2((const char *)iter->unistr);
                if ( text )
                    iter->unistr = (jkGuiStringEntry *)text;
            }
        }
        ++iter;
    }
}

int jkGui_MessageBeep()
{
    return jk_MessageBeep(0x30u);
}

int jkGui_Initialize()
{
    char playerShortName[32];
    char tmp[128];

    stdString_WcharToChar(playerShortName, jkPlayer_playerShortName, 31);
    playerShortName[31] = 0;
    wuRegistry_GetString("playerShortName", (LPBYTE)playerShortName, 32, playerShortName);
    stdString_CharToWchar(jkPlayer_playerShortName, playerShortName, 31);
    jkPlayer_playerShortName[31] = 0;

    for (int i = 0; i < 12; i++)
    {
        stdString_snprintf(tmp, 128, "ui\\sft\\%s", jkGui_aFonts[i]);
        jkGui_stdFonts[i] = stdFont_Load(tmp, 1, 0);
        if (jkGui_stdFonts[i] == NULL)
            Windows_GameErrorMsgbox("ERR_CANNOT_LOAD_FILE %s", tmp);
    }

    for (int i = 0; i < 35; i++)
    {
        stdString_snprintf(tmp, 128, "ui\\bm\\%s", jkGui_aBitmaps[i]);
        jkGui_stdBitmaps[i] = stdBitmap_Load(tmp, 1, 0);
        if (jkGui_stdBitmaps[i] == NULL)
            Windows_GameErrorMsgbox("ERR_CANNOT_LOAD_FILE %s", tmp);
    }

    Window_ShowCursorUnwindowed(Main_bWindowGUI == 0);
    jkGuiRend_SetPalette(jkGui_stdBitmaps[0]->palette);
    jkGui_bInitialized = 1;
    return 1;
}

void jkGui_Shutdown()
{
    char playerShortName[32];

    for (int i = 0; i < 12; i++)
    {
        stdFont_Free(jkGui_stdFonts[i]);
        jkGui_stdFonts[i] = NULL;
    }

    for (int i = 0; i < 35; i++)
    {
        stdBitmap_Free(jkGui_stdBitmaps[i]);
        jkGui_stdBitmaps[i] = NULL;
    }

    stdString_WcharToChar(playerShortName, jkPlayer_playerShortName, 31);
    playerShortName[31] = 0;
    wuRegistry_SetString("playerShortName", playerShortName);

    stdDisplay_422A50();
    jkGui_bInitialized = 0;
}

int jkGui_SetModeMenu(const void *palette)
{
    signed int result; // eax
    int v2; // edi
    signed int v3; // edi
    int v4; // eax
    stdDeviceParams params; // [esp+Ch] [ebp-68h]
    render_pair mode; // [esp+20h] [ebp-54h]

    params.field_0 = 1;
    params.field_4 = 0;
    params.field_8 = 0;
    params.field_C = 1;
    params.field_10 = 1;
    mode.render_8bpp.bpp = 0;
    mode.render_8bpp.rBpp = 0x3F800000;
    mode.render_8bpp.width = 640;
    mode.render_8bpp.height = 480;
    mode.render_8bpp.rShift = 0;
    mode.render_8bpp.gShift = 0;
    mode.render_8bpp.bShift = 0;
    mode.render_8bpp.palBytes = 0;
    mode.render_rgb.bpp = 8;
    mode.render_rgb.rBpp = 0;
    mode.render_rgb.gBpp = 0;
    mode.render_rgb.bBpp = 0;
    mode.render_rgb.rShift = 0;
    mode.render_rgb.gShift = 0;
    mode.render_rgb.bShift = 0;
    mode.render_rgb.rBytes = 0;
    mode.render_rgb.gBytes = 0;
    mode.render_rgb.bBytes = 0;
    mode.field_48 = 0;
    mode.field_4C = 0;
    mode.field_50 = 0;
    ++jkGui_modesets;
    if ( jkGui_GdiMode )
        return 0;
    params.field_10 = Main_bWindowGUI == 0;
    v2 = stdDisplay_FindClosestDevice(&params);
    v3 = 1;
    if ( stdDisplay_bOpen )
    {
        if ( Video_dword_866D78 == v2 )
        {
            v3 = 0;
        }
        if ( stdDisplay_bOpen )
            stdDisplay_Close();
    }
    if ( !stdDisplay_bOpen && !stdDisplay_Open(v2) )
    {
        stdPrintf((int)pHS->errorPrint, ".\\Gui\\jkGUI.c", 400, "Error opening display device.\n", 0, 0, 0, 0);
        return 0;
    }

    if ( Main_bWindowGUI )
        Window_ShowCursorUnwindowed(0);
    else
        Window_ShowCursorUnwindowed(1);

    v4 = stdDisplay_FindClosestMode(&mode, Video_renderSurface, stdDisplay_numVideoModes);
    if ( !v3 && stdDisplay_bModeSet && v4 == Video_curMode && stdDisplay_bPaged == 1 || stdDisplay_SetMode(v4, palette, 1) )
    {
        jkGuiRend_Open(&Video_menuBuffer, &Video_otherBuf, 0);
        jkGui_GdiMode = 1;
        return 1;
    }
    else
    {
        stdPrintf(
            (int)pHS->errorPrint,
            ".\\Gui\\jkGUI.c",
            426,
            "Unable to set video mode to %d x %d, %d bits-per-pixel.\n",
            mode.render_8bpp.width,
            mode.render_8bpp.height,
            mode.render_rgb.bpp,
            0);
        return 0;
    }
    return result;
}

void jkGui_SetModeGame()
{
    if ( jkGui_GdiMode )
    {
        if ( --jkGui_modesets <= 0 )
        {
            jkGuiRend_Close();
            jkGui_GdiMode = 0;
        }
    }
}

void jkGui_sub_412E20(jkGuiMenu *menu, int a2, int a3, int a4)
{
    for (int i = a2; i <= a3; i++)
    {
        jkGuiElement* element = jkGuiRend_MenuGetClickableById(menu, i);
        if ( element )
        {
            element->field_8 = 2;
            element->type = 0;
        }
    }

    if ( a4 >= a2 && a4 <= a3 )
    {
        jkGuiElement* element = jkGuiRend_MenuGetClickableById(menu, a4);
        if ( element )
        {
            element->field_8 = 3;
            element->type = 2;
        }
    }
    menu->lastMouseOverClickable = 0;
    menu->lastMouseDownClickable = 0;
}

void jkGui_copies_string(char* out)
{
    _strncpy(jkGui_unkstr, out, 0x1Fu);
    jkGui_unkstr[31] = 0;
}

char* jkGui_sub_412EC0()
{
    return jkGui_unkstr;
}

wchar_t* jkGui_sub_412ED0()
{
    return jkGuiTitle_quicksave_related_func1(&jkCog_strings, jkGui_unkstr);
}