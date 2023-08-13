#include "global.h"
#include "main.h"

#ifdef NONMATCHING
void ResetPokedex(void)
{
    s32 i;
    for (i = NUM_SPECIES - 1; i >= 0; i--)
    {
        gMain_saveData.pokedexFlags[i] = 0;
    }
}
#else
NAKED
void ResetPokedex(void)
{
    asm_unified("\n\
    ldr r1, _08008AD0 @ =gMain+0x74\n\
	movs r2, #0\n\
	adds r0, r1, #0\n\
	adds r0, #0xcc\n\
_08008AC4:\n\
	strb r2, [r0]\n\
	subs r0, #1\n\
	cmp r0, r1\n\
	bge _08008AC4\n\
	bx lr\n\
	.align 2, 0\n\
_08008AD0: .4byte gMain+0x74");
}
#endif // NONMATCHING
