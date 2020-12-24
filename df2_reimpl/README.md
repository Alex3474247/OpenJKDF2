# DF2 Reimplementation

This directory contains a WIP reimplementation of DF2 in C. Files are organized as closely to the original game as possible, based on symbols from the Grim Fandango Remaster Android/Linux/macOS port. It also contains the original versions of `byacc` and `flex` for COG script parsing.

## Methodology
Most functions are a copy-paste from IDA's Hex-Rays decompiler into the source material, with some cleanup and renaming. Most functions decompile fairly well as long as the structures are correct, though for loops often need reworking. If you'd like a copy of my IDB, let me know.

## Current Progress

Generated using `analyze.py`. Some filenames may be inaccurate or incomplete (see `ida_copypaste_funclist.txt` for a full function name listing).

```
[file]                         [size]     [% of text]   [% complete]  [decomp / total] 
jkGob                          0x29       0.004%        100.000%        2 / 2          
jkGuiDecision                  0x45       0.006%        100.000%        3 / 3          
sithStrTable                   0x5b       0.008%        100.000%        4 / 4          
sithCopyright                  0x67       0.010%        100.000%        1 / 1          
jkStrings                      0x89       0.013%        100.000%        5 / 5          
rdFace                         0xf6       0.023%        100.000%        4 / 4          
stdHashKey                     0x107      0.024%        100.000%       10 / 10         
rdCanvas                       0x113      0.025%        100.000%        4 / 4          
jkGuiEsc                       0x18f      0.037%        100.000%        3 / 3          
rdroid                         0x1f6      0.046%        100.000%       27 / 27         
sithHeader                     0x1f9      0.047%        100.000%        1 / 1          
sithTime                       0x213      0.049%        100.000%        6 / 6          
sithItem                       0x275      0.058%        100.000%        5 / 5          
sithTimer                      0x2e3      0.068%        100.000%        9 / 9          
stdMci                         0x2ef      0.070%        100.000%        7 / 7          
stdString                      0x3b3      0.088%        100.000%       11 / 11         
sithModel                      0x3f1      0.093%        100.000%        8 / 8          
stdHashTable                   0x42c      0.099%        100.000%        8 / 8          
rdThing                        0x42f      0.099%        100.000%       12 / 12         
sithKeyFrame                   0x44e      0.102%        100.000%        5 / 5          
stdPcx                         0x45e      0.104%        100.000%        2 / 2          
rdMath                         0x47d      0.106%        100.000%        6 / 6          
rdLight                        0x49f      0.110%        100.000%        8 / 8          
stdFnames                      0x4ee      0.117%        100.000%       14 / 14         
sithSprite                     0x4f1      0.117%        100.000%        6 / 6          
jkGui                          0x4fb      0.118%        100.000%       10 / 10         
stdGob                         0x6dd      0.163%        100.000%       14 / 14         
rdSprite                       0x76d      0.176%        100.000%        5 / 5          
stdConffile                    0x78d      0.179%        100.000%       13 / 13         
sithTemplate                   0x79d      0.180%        100.000%       10 / 10         
jkGuiSingleplayer              0x8d8      0.210%        100.000%        7 / 7          
jkGuiForce                     0x9dd      0.234%        100.000%       11 / 11         
rdParticle                     0xa0d      0.238%        100.000%       10 / 10         
rdKeyframe                     0xa99      0.251%        100.000%        8 / 8          
rdPolyLine                     0xb42      0.267%        100.000%        6 / 6          
rdVector                       0xd29      0.312%        100.000%       55 / 55         
stdConsole                     0xfff      0.379%        100.000%       20 / 20         
sithCogUtil                    0x26c2     0.919%        100.000%      119 / 119        
rdModel3                       0x2a7e     1.007%        100.000%       23 / 23         
rdMatrix                       0x2c85     1.055%        100.000%       56 / 56         
jkGuiRend                      0x2cd7     1.063%        100.000%       68 / 68         
jkPlayer                       0x2da2     1.082%        100.000%       45 / 45         
sithCogThing                   0x3a4c     1.382%        100.000%      142 / 142        
DirectX                        0x1e       0.003%        0.000%          0 / 5          
jkGuiGeneral                   0xc5       0.018%        0.000%          0 / 3          
jkSmack                        0xee       0.022%        0.000%          0 / 4          
jkGuiControlOptions            0x105      0.024%        0.000%          0 / 3          
stdHashtable                   0x1aa      0.039%        0.000%          0 / 2          
jkGuiSingleTally               0x21b      0.050%        0.000%          0 / 4          
jkGuiSetup                     0x240      0.053%        0.000%          0 / 4          
jkGuiSound                     0x274      0.058%        0.000%          0 / 3          
jkGuiGameplay                  0x2b2      0.064%        0.000%          0 / 3          
stdMemory                      0x2ba      0.065%        0.000%          0 / 7          
jkGuiObjectives                0x308      0.072%        0.000%          0 / 4          
jkControl                      0x331      0.076%        0.000%          0 / 4          
Windows                        0x39a      0.085%        0.000%          0 / 11         
jkGuiDialog                    0x3e0      0.092%        0.000%          0 / 6          
stdGdi                         0x430      0.099%        0.000%          0 / 10         
jkCutscene                     0x443      0.101%        0.000%          0 / 7          
sithThingPlayer                0x460      0.104%        0.000%          0 / 4          
smack                          0x466      0.104%        0.000%          0 / 6          
jkGuiMain                      0x4b1      0.111%        0.000%          0 / 6          
jkGuiTitle                     0x4fb      0.118%        0.000%          0 / 10         
sithMaterial                   0x4fd      0.118%        0.000%          0 / 9          
sithDplay                      0x53c      0.124%        0.000%          0 / 17         
sithActor                      0x559      0.127%        0.000%          0 / 5          
wuRegistry                     0x5b2      0.135%        0.000%          0 / 12         
Video                          0x5dc      0.139%        0.000%          0 / 5          
DebugConsole                   0x5de      0.139%        0.000%          0 / 13         
sithExplosion                  0x61d      0.145%        0.000%          0 / 4          
stdFileUtil                    0x687      0.155%        0.000%          0 / 11         
sithAIClass                    0x689      0.155%        0.000%          0 / 7          
rdPrimit2                      0x69a      0.156%        0.000%          0 / 5          
stdBmp                         0x6b8      0.159%        0.000%          0 / 3          
sithCogScript                  0x6ca      0.161%        0.000%          0 / 9          
sithAnimClass                  0x6cc      0.161%        0.000%          0 / 5          
Window                         0x6db      0.162%        0.000%          0 / 13         
jkAI                           0x6e7      0.164%        0.000%          0 / 5          
sith                           0x72b      0.170%        0.000%          0 / 16         
jkGuiControlSaveLoad           0x732      0.171%        0.000%          0 / 6          
jkGuiPlayer                    0x73a      0.171%        0.000%          0 / 5          
jkGuiMultiplayer               0x749      0.173%        0.000%          0 / 3          
jkGuiMap                       0x793      0.180%        0.000%          0 / 8          
stdStrTable                    0x7b6      0.183%        11.905%         3 / 6          
sithParticle                   0x7f5      0.189%        0.000%          0 / 10         
Main                           0x87b      0.201%        0.000%          0 / 4          
jkGuiMultiTally                0x8aa      0.205%        0.000%          0 / 7          
jkCredits                      0x8e4      0.211%        0.000%          0 / 6          
sithCogSector                  0x93a      0.219%        22.820%         1 / 22         
sithCogAI                      0x943      0.220%        14.720%         1 / 20         
jkGuiNet                       0x94e      0.221%        0.000%          0 / 10         
stdColor                       0x97e      0.225%        0.000%          0 / 11         
jkGame                         0x98f      0.227%        0.000%          0 / 13         
stdSound                       0x9bf      0.231%        0.000%          0 / 27         
sithSave                       0x9bf      0.231%        0.000%          0 / 7          
sithSound                      0xa00      0.237%        0.000%          0 / 13         
rdMaterial                     0xa2d      0.241%        68.599%         6 / 9          
sithSoundClass                 0xa46      0.243%        0.000%          0 / 16         
stdPalEffects                  0xa66      0.246%        0.000%          0 / 21         
sithCogSound                   0xa97      0.251%        9.369%          1 / 14         
rdCamera                       0xaa8      0.253%        0.000%          0 / 26         
jkGuiSaveLoad                  0xb21      0.264%        0.000%          0 / 9          
jkGuiKeyboard                  0xb57      0.269%        0.000%          0 / 14         
jkGuiNetHost                   0xbc6      0.279%        0.000%          0 / 6          
sithMapView                    0xbf8      0.284%        0.000%          0 / 9          
stdLbm                         0xc24      0.288%        0.000%          0 / 3          
rdColormap                     0xcf4      0.307%        26.327%         6 / 12         
sithTrackThing                 0xd6b      0.318%        0.000%          0 / 13         
jkGuiMouse                     0xdb5      0.325%        0.000%          0 / 14         
DirectDraw                     0xdd4      0.328%        0.000%          0 / 16         
jkEpisode                      0xdd9      0.328%        0.000%          0 / 10         
stdPlatform                    0xdde      0.329%        4.930%          5 / 43         
sithCogPlayer                  0xdf0      0.330%        22.029%         1 / 42         
sithUnk4                       0xdfd      0.332%        0.000%          0 / 12         
jkHudInv                       0xe43      0.338%        0.000%          0 / 9          
sithPlayer                     0xe72      0.342%        0.000%          0 / 27         
sithCogSurface                 0xe92      0.345%        21.582%         1 / 38         
stdBitmap                      0xeb6      0.349%        0.000%          0 / 14         
rdPuppet                       0x101f     0.382%        0.000%          0 / 19         
DirectPlay                     0x10cc     0.398%        0.000%          0 / 31         
VBuffer                        0x10dc     0.400%        0.000%          0 / 4          
stdGif                         0x1162     0.412%        0.000%          0 / 4          
sithDebugConsole               0x11b2     0.419%        0.000%          0 / 20         
jkCog                          0x11b8     0.420%        16.049%         2 / 40         
sithPuppet                     0x1222     0.430%        0.000%          0 / 17         
sithCamera                     0x124b     0.434%        0.000%          0 / 23         
sithCollide                    0x12a8     0.442%        0.000%          0 / 12         
jkGuiDisplay                   0x12ff     0.450%        0.000%          0 / 11         
stdControl                     0x1323     0.454%        0.000%          0 / 23         
jkGuiJoystick                  0x13f0     0.473%        0.000%          0 / 19         
sithCogYACC                    0x152b     0.502%        0.000%          0 / 10         
jkRes                          0x15b6     0.515%        0.000%          0 / 23         
jkMain                         0x16cd     0.540%        0.000%          0 / 53         
rdPrimit3                      0x16e0     0.542%        0.017%          1 / 9          
sithWorld                      0x1718     0.547%        21.262%         6 / 22         
stdFont                        0x181a     0.571%        0.000%          0 / 20         
stdMath                        0x182a     0.573%        32.218%        13 / 23         
rdActive                       0x1a55     0.624%        0.000%          0 / 8          
sithCogParse                   0x1b2a     0.644%        10.282%         4 / 26         
sithSurface                    0x1c6a     0.673%        0.000%          0 / 35         
jkHud                          0x1c9b     0.678%        0.000%          0 / 17         
jkDev                          0x1e60     0.720%        0.000%          0 / 39         
sithCog                        0x1ed3     0.731%        16.918%         2 / 28         
jkSaber                        0x1f4a     0.742%        33.296%         5 / 40         
sithInventory                  0x2150     0.790%        72.256%        57 / 62         
sithCogVm                      0x22f7     0.829%        80.751%        36 / 42         
sithRender                     0x23de     0.850%        0.000%          0 / 22         
sithMulti                      0x250c     0.878%        0.000%          0 / 34         
jkGuiBuildMulti                0x258b     0.890%        0.000%          0 / 24         
sithSoundSys                   0x2626     0.904%        0.000%          0 / 37         
stdDisplay                     0x267b     0.912%        0.000%          0 / 37         
sithControl                    0x2723     0.928%        0.000%          0 / 32         
sithAI                         0x2771     0.935%        2.209%          2 / 35         
sithUnk3                       0x2827     0.952%        6.275%          4 / 22         
std3D                          0x2c4a     1.050%        0.000%          0 / 39         
sithAICmd                      0x2cc0     1.061%        4.958%          1 / 22         
sithWeapon                     0x32a8     1.201%        0.987%          1 / 33         
rdCache                        0x331c     1.211%        39.315%        12 / 16         
sithThing                      0x3c4c     1.429%        0.000%          0 / 54         
sithSector                     0x79f9     2.891%        0.000%          0 / 96         
rdClip                         0x81f2     3.080%        2.567%          2 / 17         
rdRaster                       0xf04d     5.695%        0.000%          0 / 89         
rdZRaster                      0x15fb4    8.335%        0.000%          0 / 73         
rdAFRaster                     0x1620d    8.391%        0.000%          0 / 122        
rdNRaster                      0x304d4    18.316%       0.000%          0 / 87         
------------------------------

Total completion: 14.019%
```