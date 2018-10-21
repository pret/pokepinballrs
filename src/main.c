#include "global.h"
#include "main.h"

extern void sub_B54(void);
extern void sub_BBC(void);
extern void sub_D74(void);
extern void sub_FE8(void);
extern void ReadKeys(void);
extern u32 IntrMain_Buffer[0x200];
extern u32 IntrMain[];

void AgbMain(void)
{
    RegisterRamReset(0xFF);
    sub_BBC();
    DmaCopy32(3, IntrMain, IntrMain_Buffer, sizeof(IntrMain_Buffer));
    INTR_VECTOR = IntrMain_Buffer;
    sub_B54();
    sub_FE8();
    while (1)
    {
        ReadKeys();
        gMainFuncs[gMain.mainState]();
        sub_D74();
    }
}
