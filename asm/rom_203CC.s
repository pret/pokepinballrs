#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_203CC
sub_203CC: @ 0x080203CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl sub_20EC0
	ldr r6, _0802042C @ =gCurrentPinballGame
	ldr r5, [r6]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa7
	ble _0802044C
	ldr r4, _08020430 @ =gUnknown_086ADF48
	ldr r0, _08020434 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0xa0
	bl __umodsi3
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r3, _08020438 @ =0x00000744
	adds r0, r5, r3
	strb r1, [r0]
	ldr r2, [r6]
	movs r4, #0xf1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020440
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, #6
	ldr r5, _0802043C @ =0x00000745
	adds r1, r2, r5
	strb r0, [r1]
	b _0802049C
	.align 2, 0
_0802042C: .4byte gCurrentPinballGame
_08020430: .4byte gUnknown_086ADF48
_08020434: .4byte gMain
_08020438: .4byte 0x00000744
_0802043C: .4byte 0x00000745
_08020440:
	ldr r7, _08020448 @ =0x00000744
	adds r0, r2, r7
	b _08020494
	.align 2, 0
_08020448: .4byte 0x00000744
_0802044C:
	ldr r0, _08020484 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	ldr r4, _08020488 @ =0x00000744
	adds r1, r5, r4
	strb r0, [r1]
	ldr r2, [r6]
	movs r5, #0xf1
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020490
	adds r0, r2, r4
	ldrb r0, [r0]
	adds r0, #9
	ldr r7, _0802048C @ =0x00000745
	adds r1, r2, r7
	strb r0, [r1]
	b _0802049C
	.align 2, 0
_08020484: .4byte gMain
_08020488: .4byte 0x00000744
_0802048C: .4byte 0x00000745
_08020490:
	ldr r1, _080204C8 @ =0x00000744
	adds r0, r2, r1
_08020494:
	ldrb r1, [r0]
	ldr r3, _080204CC @ =0x00000745
	adds r0, r2, r3
	strb r1, [r0]
_0802049C:
	ldr r1, _080204D0 @ =gCurrentPinballGame
	ldr r5, [r1]
	movs r4, #0xf1
	lsls r4, r4, #1
	adds r3, r5, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	mov sl, r1
	cmp r0, #2
	bne _080204D8
	ldr r7, _080204D4 @ =0x000001E3
	adds r0, r5, r7
	movs r1, #1
	strb r1, [r0]
	mov r2, sl
	ldr r0, [r2]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	b _08020500
	.align 2, 0
_080204C8: .4byte 0x00000744
_080204CC: .4byte 0x00000745
_080204D0: .4byte gCurrentPinballGame
_080204D4: .4byte 0x000001E3
_080204D8:
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldr r3, _0802060C @ =0x000001E3
	adds r0, r5, r3
	adds r0, r0, r1
	movs r4, #0
	movs r2, #1
	strb r2, [r0]
	mov r5, sl
	ldr r0, [r5]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r1, r0, r7
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r2, r2, r1
	adds r0, r0, r3
	adds r0, r0, r2
	strb r4, [r0]
_08020500:
	mov r0, sl
	ldr r1, [r0]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r4, [r2]
	cmp r4, #0
	bne _08020512
	b _0802073A
_08020512:
	cmp r4, #0x78
	beq _08020518
	b _080206CC
_08020518:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08020538
	b _080206CC
_08020538:
	movs r6, #0xe3
	lsls r6, r6, #1
	adds r0, r1, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa7
	ble _08020630
	movs r5, #0
	movs r3, #1
	strb r3, [r1, #0x1f]
	mov r7, sl
	ldr r0, [r7]
	ldr r1, _08020610 @ =0x0000061C
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, [r7]
	movs r7, #0xef
	lsls r7, r7, #1
	adds r2, r1, r7
	movs r0, #0
	mov r8, r0
	strh r4, [r2]
	adds r7, #2
	adds r0, r1, r7
	strh r4, [r0]
	ldrh r2, [r2]
	ldr r4, _08020614 @ =0x0000061E
	adds r0, r1, r4
	strh r2, [r0]
	ldr r7, _08020618 @ =0x000005F7
	adds r1, r1, r7
	strb r3, [r1]
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0x82
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _0802061C @ =0x0000020A
	adds r0, r0, r3
	mov r4, r8
	strb r4, [r0]
	mov r7, sl
	ldr r2, [r7]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _080205E4
	adds r0, r2, r6
	strh r5, [r0]
	subs r3, #0x42
	adds r0, r2, r3
	strh r5, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r5, [r0]
	movs r7, #0xe5
	lsls r7, r7, #1
	adds r0, r2, r7
	strh r5, [r0]
	subs r1, #0xe
	adds r0, r2, r1
	strh r5, [r0]
	adds r3, #0xe
	adds r1, r2, r3
	ldr r0, _08020620 @ =0x0000FFFC
	strh r0, [r1]
	adds r4, #0xc
	adds r0, r2, r4
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r7, #0x10
	adds r0, r2, r7
	strh r1, [r0]
	adds r1, #0xce
	adds r0, r2, r1
	strh r5, [r0]
	subs r3, #6
	adds r0, r2, r3
	strh r5, [r0]
_080205E4:
	mov r4, sl
	ldr r1, [r4]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r2, r1, r5
	ldr r7, _08020624 @ =0x0000132C
	adds r0, r1, r7
	ldr r0, [r0]
	ldr r0, [r0, #0x28]
	str r0, [r2]
	ldr r0, _08020628 @ =0x00007530
	str r0, [r1, #0x3c]
	ldr r0, _0802062C @ =0x0000062E
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802063C
	adds r0, #1
	strb r0, [r1]
	b _0802063C
	.align 2, 0
_0802060C: .4byte 0x000001E3
_08020610: .4byte 0x0000061C
_08020614: .4byte 0x0000061E
_08020618: .4byte 0x000005F7
_0802061C: .4byte 0x0000020A
_08020620: .4byte 0x0000FFFC
_08020624: .4byte 0x0000132C
_08020628: .4byte 0x00007530
_0802062C: .4byte 0x0000062E
_08020630:
	movs r0, #0x3c
	strh r0, [r2]
	ldr r0, _0802067C @ =gMPlayInfo_SE1
	ldr r1, _08020680 @ =gUnknown_086A2FA0
	bl MPlayStart
_0802063C:
	ldr r0, _08020684 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #2
	bne _0802068C
	lsls r3, r2, #0x10
	asrs r1, r3, #0x10
	ldr r4, _08020688 @ =0x00000744
	adds r2, r5, r4
	adds r2, r2, r1
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, #2
	strb r0, [r2]
	mov r8, r3
	b _0802069C
	.align 2, 0
_0802067C: .4byte gMPlayInfo_SE1
_08020680: .4byte gUnknown_086A2FA0
_08020684: .4byte gCurrentPinballGame
_08020688: .4byte 0x00000744
_0802068C:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldr r7, _08020700 @ =0x00000744
	adds r0, r5, r7
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	mov r8, r2
_0802069C:
	ldr r3, _08020704 @ =0x040000D4
	mov r1, sl
	ldr r0, [r1]
	mov r4, r8
	asrs r2, r4, #0x10
	ldr r5, _08020700 @ =0x00000744
	adds r0, r0, r5
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020708 @ =gUnknown_084C07EC
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r7, _0802070C @ =0x06010480
	adds r0, r0, r7
	str r0, [r3, #4]
	ldr r0, _08020710 @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
_080206CC:
	mov r0, sl
	ldr r2, [r0]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020714
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	ldr r4, _08020700 @ =0x00000744
	adds r2, r2, r4
	adds r2, r2, r0
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, #2
	strb r1, [r2]
	b _0802072A
	.align 2, 0
_08020700: .4byte 0x00000744
_08020704: .4byte 0x040000D4
_08020708: .4byte gUnknown_084C07EC
_0802070C: .4byte 0x06010480
_08020710: .4byte 0x800000C0
_08020714:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r2, r0
	ldr r7, _080207B4 @ =0x00000743
	adds r0, r0, r7
	movs r1, #2
	strb r1, [r0]
_0802072A:
	mov r0, sl
	ldr r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0802073A:
	mov r3, sl
	ldr r5, [r3]
	ldr r4, _080207B8 @ =0x0000061C
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0802074E
	b _08020D82
_0802074E:
	ldr r7, _080207BC @ =0x0000061E
	mov sb, r7
	mov r0, sb
	adds r6, r5, r0
	ldrh r7, [r6]
	mov r8, r7
	mov r1, r8
	cmp r1, #1
	bhi _08020762
	b _08020928
_08020762:
	movs r2, #0xef
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	subs r0, r7, #1
	strh r0, [r6]
	ldrh r0, [r4]
	cmp r0, #0
	beq _08020796
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bne _08020796
	ldrh r0, [r6]
	cmp r0, #0x28
	bls _08020796
	movs r0, #0x3c
	strh r0, [r4]
_08020796:
	ldr r3, _080207C0 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _080207BC @ =0x0000061E
	adds r2, r1, r4
	ldrh r0, [r2]
	cmp r0, #0x74
	bne _08020832
	adds r1, #0xe4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080207C4
	movs r0, #0x78
	strh r0, [r2]
	b _08020832
	.align 2, 0
_080207B4: .4byte 0x00000743
_080207B8: .4byte 0x0000061C
_080207BC: .4byte 0x0000061E
_080207C0: .4byte gCurrentPinballGame
_080207C4:
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r3]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020820
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080207FC
	ldr r0, _080207F4 @ =gMPlayInfo_SE1
	ldr r1, _080207F8 @ =gUnknown_086A0328
	bl MPlayStart
	b _08020804
	.align 2, 0
_080207F4: .4byte gMPlayInfo_SE1
_080207F8: .4byte gUnknown_086A0328
_080207FC:
	ldr r0, _08020810 @ =gMPlayInfo_SE1
	ldr r1, _08020814 @ =gUnknown_086A0368
	bl MPlayStart
_08020804:
	ldr r0, _08020818 @ =gMPlayInfo_BGM
	ldr r1, _0802081C @ =0x0000FFFF
	movs r2, #0x40
	bl m4aMPlayVolumeControl
	b _08020832
	.align 2, 0
_08020810: .4byte gMPlayInfo_SE1
_08020814: .4byte gUnknown_086A0368
_08020818: .4byte gMPlayInfo_BGM
_0802081C: .4byte 0x0000FFFF
_08020820:
	ldr r0, _08020900 @ =gMPlayInfo_SE1
	ldr r1, _08020904 @ =gUnknown_086A0328
	bl MPlayStart
	ldr r0, _08020908 @ =gMPlayInfo_BGM
	ldr r1, _0802090C @ =0x0000FFFF
	movs r2, #0x40
	bl m4aMPlayVolumeControl
_08020832:
	ldr r0, _08020910 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _08020914 @ =0x0000061E
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x73
	bne _08020856
	adds r0, r1, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #1
	bne _08020856
	ldr r0, _08020900 @ =gMPlayInfo_SE1
	ldr r1, _0802090C @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #2
	bl m4aMPlayVolumeControl
_08020856:
	adds r0, r5, #0
	bl Sin
	adds r1, r0, #0
	ldr r0, _08020910 @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r5, _08020918 @ =0x0000132C
	adds r5, r5, r4
	mov r8, r5
	ldr r7, [r5]
	mov sb, r7
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r6, r4, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0802091C @ =0x00004E20
	bl __divsi3
	ldrh r5, [r6]
	adds r5, r5, r0
	ldr r1, _08020920 @ =gUnknown_086ADF8A
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	subs r2, r2, r0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r6, r4, r0
	ldrh r1, [r6]
	movs r3, #0xef
	lsls r3, r3, #1
	adds r7, r4, r3
	ldrh r0, [r7]
	subs r0, r1, r0
	muls r0, r2, r0
	bl __divsi3
	adds r5, r5, r0
	mov r0, sb
	strh r5, [r0, #0x28]
	ldrh r1, [r6]
	ldrh r2, [r7]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	bl __divsi3
	mov r1, r8
	ldr r2, [r1]
	ldr r3, _08020924 @ =0x00000622
	adds r4, r4, r3
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r2, #0x2a]
	mov r4, r8
	ldr r1, [r4]
	movs r5, #0x28
	ldrsh r0, [r1, r5]
	lsls r0, r0, #7
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r7, #0x2a
	ldrsh r0, [r1, r7]
	lsls r0, r0, #7
	str r0, [r1, #0x38]
	b _080209FE
	.align 2, 0
_08020900: .4byte gMPlayInfo_SE1
_08020904: .4byte gUnknown_086A0328
_08020908: .4byte gMPlayInfo_BGM
_0802090C: .4byte 0x0000FFFF
_08020910: .4byte gCurrentPinballGame
_08020914: .4byte 0x0000061E
_08020918: .4byte 0x0000132C
_0802091C: .4byte 0x00004E20
_08020920: .4byte gUnknown_086ADF8A
_08020924: .4byte 0x00000622
_08020928:
	mov r0, r8
	cmp r0, #1
	bne _080209FE
	ldr r1, _08020A3C @ =0x0000132C
	adds r2, r5, r1
	ldr r3, [r2]
	ldr r1, _08020A40 @ =gUnknown_086ADF8A
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #1
	movs r6, #0
	movs r5, #0
	strh r0, [r3, #0x28]
	ldr r1, [r2]
	ldr r0, _08020A44 @ =0x000002BE
	strh r0, [r1, #0x2a]
	ldr r1, [r2]
	movs r7, #0x28
	ldrsh r0, [r1, r7]
	lsls r0, r0, #7
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r3, #0x2a
	ldrsh r0, [r1, r3]
	lsls r0, r0, #7
	str r0, [r1, #0x38]
	ldr r0, [r2]
	strh r5, [r0, #0x30]
	ldr r1, [r2]
	ldr r0, _08020A48 @ =0x0000FED4
	strh r0, [r1, #0x32]
	movs r0, 0x7C @=SE_UNKNOWN_0x7C
	bl m4aSongNumStart
	mov r7, sl
	ldr r1, [r7]
	mov r2, sb
	adds r0, r1, r2
	strh r5, [r0]
	strb r6, [r1, #0x1f]
	ldr r0, [r7]
	ldr r3, _08020A4C @ =0x000005F7
	adds r0, r0, r3
	strb r6, [r0]
	ldr r2, [r7]
	adds r4, r2, r4
	movs r0, #0
	ldrsb r0, [r4, r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r4, #0xe2
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r2, r1
	mov r5, r8
	strb r5, [r2]
	ldr r3, [r7]
	ldr r7, _08020A50 @ =0x00000714
	adds r4, r3, r7
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080209F8
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08020A54 @ =0x00000711
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r5, _08020A58 @ =0x00000712
	adds r1, r3, r5
	ldrb r1, [r1]
	ands r0, r1
	subs r7, #1
	adds r1, r3, r7
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _080209F8
	mov r0, r8
	strb r0, [r4]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08020A5C @ =0x00000715
	adds r0, r0, r2
	movs r1, #0x7e
	strb r1, [r0]
	mov r3, sl
	ldr r1, [r3]
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
_080209F8:
	movs r0, #0xb
	bl sub_11B0
_080209FE:
	ldr r0, _08020A60 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r4, _08020A64 @ =0x0000061E
	adds r1, r3, r4
	ldrh r1, [r1]
	mov sl, r0
	cmp r1, #0x63
	bls _08020AFC
	movs r5, #0xf1
	lsls r5, r5, #1
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020A6C
	movs r7, #0xe1
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	ldr r1, _08020A68 @ =0x00000744
	adds r2, r3, r1
	adds r2, r2, r0
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, #2
	strb r1, [r2]
	b _08020A82
	.align 2, 0
_08020A3C: .4byte 0x0000132C
_08020A40: .4byte gUnknown_086ADF8A
_08020A44: .4byte 0x000002BE
_08020A48: .4byte 0x0000FED4
_08020A4C: .4byte 0x000005F7
_08020A50: .4byte 0x00000714
_08020A54: .4byte 0x00000711
_08020A58: .4byte 0x00000712
_08020A5C: .4byte 0x00000715
_08020A60: .4byte gCurrentPinballGame
_08020A64: .4byte 0x0000061E
_08020A68: .4byte 0x00000744
_08020A6C:
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r3, r0
	ldr r3, _08020AC4 @ =0x00000743
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
_08020A82:
	mov r4, sl
	ldr r2, [r4]
	ldr r5, _08020AC8 @ =0x0000061E
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0x64
	beq _08020A92
	b _08020D82
_08020A92:
	ldr r0, _08020ACC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x98
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020AD8
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020AD8
	ldr r1, _08020AD0 @ =0x040000D4
	ldr r0, _08020AD4 @ =gUnknown_08395A4C
	b _08020ADC
	.align 2, 0
_08020AC4: .4byte 0x00000743
_08020AC8: .4byte 0x0000061E
_08020ACC: .4byte gMain
_08020AD0: .4byte 0x040000D4
_08020AD4: .4byte gUnknown_08395A4C
_08020AD8:
	ldr r1, _08020AEC @ =0x040000D4
	ldr r0, _08020AF0 @ =gUnknown_08397E6C
_08020ADC:
	str r0, [r1]
	ldr r0, _08020AF4 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08020AF8 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08020D82
	.align 2, 0
_08020AEC: .4byte 0x040000D4
_08020AF0: .4byte gUnknown_08397E6C
_08020AF4: .4byte 0x06015800
_08020AF8: .4byte 0x80001200
_08020AFC:
	ldr r2, _08020B24 @ =gUnknown_086ADEE0
	ldr r6, _08020B28 @ =0x0000020A
	adds r4, r3, r6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, r2, #2
	adds r0, r0, r1
	movs r5, #0x82
	lsls r5, r5, #2
	adds r1, r3, r5
	ldrh r3, [r1]
	ldrh r0, [r0]
	mov r8, r2
	cmp r0, r3
	bls _08020B2C
	adds r0, r3, #1
	strh r0, [r1]
	b _08020C1C
	.align 2, 0
_08020B24: .4byte gUnknown_086ADEE0
_08020B28: .4byte 0x0000020A
_08020B2C:
	movs r5, #0
	movs r7, #0
	strh r7, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08020BC0 @ =0x0000020A
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x17
	bne _08020B5C
	movs r0, #0x7c
	bl m4aSongNumStop
	ldr r0, _08020BC4 @ =gMPlayInfo_BGM
	ldr r1, _08020BC8 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_08020B5C:
	mov r3, sl
	ldr r0, [r3]
	adds r1, r0, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x19
	ble _08020C1C
	movs r0, #0x19
	strb r0, [r1]
	mov r4, sl
	ldr r0, [r4]
	ldr r1, _08020BCC @ =0x0000061C
	adds r0, r0, r1
	strb r5, [r0]
	ldr r2, _08020BD0 @ =gMain
	ldr r0, [r2, #0x44]
	adds r0, #0x98
	ldr r0, [r0]
	strh r7, [r0]
	ldr r0, [r4]
	adds r0, #0xe4
	strb r5, [r0]
	ldr r4, [r4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020BD8
	lsls r3, r2, #0x10
	asrs r1, r3, #0x10
	ldr r0, _08020BD4 @ =0x00000744
	adds r2, r4, r0
	adds r2, r2, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	strb r0, [r2]
	mov r8, r3
	b _08020BE6
	.align 2, 0
_08020BC0: .4byte 0x0000020A
_08020BC4: .4byte gMPlayInfo_BGM
_08020BC8: .4byte 0x0000FFFF
_08020BCC: .4byte 0x0000061C
_08020BD0: .4byte gMain
_08020BD4: .4byte 0x00000744
_08020BD8:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldr r3, _08020C48 @ =0x00000744
	adds r0, r4, r3
	adds r0, r0, r1
	strb r5, [r0]
	mov r8, r2
_08020BE6:
	ldr r3, _08020C4C @ =0x040000D4
	ldr r4, _08020C50 @ =gCurrentPinballGame
	ldr r0, [r4]
	mov r5, r8
	asrs r2, r5, #0x10
	ldr r7, _08020C48 @ =0x00000744
	adds r0, r0, r7
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020C54 @ =gUnknown_084C07EC
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r1, _08020C58 @ =0x06010480
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _08020C5C @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, r4
	ldr r2, _08020C60 @ =gUnknown_086ADEE0
	mov r8, r2
_08020C1C:
	mov r3, sl
	ldr r1, [r3]
	ldr r4, _08020C64 @ =0x0000020A
	adds r0, r1, r4
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bhi _08020C76
	ldr r5, _08020C68 @ =gMain
	ldr r0, [r5, #0x4c]
	movs r2, #3
	ands r0, r2
	lsrs r0, r0, #1
	cmp r0, #0
	beq _08020C70
	adds r1, #0x4c
	ldr r0, _08020C6C @ =0x0000FFFD
	strh r0, [r1]
	b _08020C76
	.align 2, 0
_08020C48: .4byte 0x00000744
_08020C4C: .4byte 0x040000D4
_08020C50: .4byte gCurrentPinballGame
_08020C54: .4byte gUnknown_084C07EC
_08020C58: .4byte 0x06010480
_08020C5C: .4byte 0x800000C0
_08020C60: .4byte gUnknown_086ADEE0
_08020C64: .4byte 0x0000020A
_08020C68: .4byte gMain
_08020C6C: .4byte 0x0000FFFD
_08020C70:
	adds r0, r1, #0
	adds r0, #0x4c
	strh r2, [r0]
_08020C76:
	mov r7, sl
	ldr r3, [r7]
	ldr r1, _08020CD8 @ =0x0000020A
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, r8
	ldrh r5, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r4, _08020CDC @ =gMain
	ldr r0, [r4, #0x44]
	adds r0, #0x98
	ldr r6, [r0]
	subs r2, r1, #1
	movs r0, #0xb1
	adds r1, r2, #0
	muls r1, r0, r1
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r0, #0x10
	subs r1, r1, r0
	strh r1, [r6, #2]
	ldr r7, _08020CE0 @ =0x0000061C
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08020CE8
	adds r0, r3, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r7, _08020CE4 @ =0x000001E3
	adds r0, r3, r7
	adds r0, r0, r2
	movs r1, #0
	b _08020CF4
	.align 2, 0
_08020CD8: .4byte 0x0000020A
_08020CDC: .4byte gMain
_08020CE0: .4byte 0x0000061C
_08020CE4: .4byte 0x000001E3
_08020CE8:
	movs r0, #0xb4
	strh r0, [r6, #4]
	ldr r1, _08020E14 @ =0x000001E3
	adds r0, r3, r1
	adds r0, r0, r2
	movs r1, #1
_08020CF4:
	strb r1, [r0]
	movs r4, #0
	lsls r1, r5, #0x10
	ldr r2, _08020E18 @ =gOamBuffer
	mov sb, r2
	ldr r3, _08020E1C @ =gUnknown_086B4922
	mov r8, r3
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov ip, r0
	ldr r5, _08020E20 @ =0xFFFFFE00
	mov sl, r5
_08020D10:
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, ip
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08020E24 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _08020D10
_08020D82:
	ldr r0, _08020E28 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r6, [r1, #0x74]
	ldrh r1, [r6]
	cmp r1, #0
	bne _08020D90
	b _08020EA4
_08020D90:
	movs r2, #0
	ldr r3, _08020E2C @ =0x040000D4
	mov sl, r3
_08020D96:
	lsls r2, r2, #0x10
	asrs r5, r2, #0x10
	ldr r4, _08020E28 @ =gMain
	ldr r1, [r4, #0x44]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r6, [r0, #0x74]
	movs r0, #0xb1
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r7, _08020E30 @ =gCurrentPinballGame
	ldr r4, [r7]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r0, #0x10
	subs r1, r1, r0
	strh r1, [r6, #2]
	ldr r1, _08020E14 @ =0x000001E3
	adds r0, r4, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r2
	cmp r0, #0
	beq _08020E44
	ldr r2, _08020E28 @ =gMain
	ldr r0, [r2, #0x50]
	movs r1, #5
	bl __umodsi3
	cmp r0, #0
	bne _08020E02
	ldr r3, _08020E34 @ =0x00000744
	adds r0, r4, r3
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020E38 @ =gUnknown_084C07EC
	adds r0, r0, r1
	mov r4, sl
	str r0, [r4]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #7
	ldr r5, _08020E3C @ =0x06010480
	adds r0, r0, r5
	str r0, [r4, #4]
	ldr r0, _08020E40 @ =0x800000C0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_08020E02:
	ldr r7, _08020E30 @ =gCurrentPinballGame
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	b _08020E46
	.align 2, 0
_08020E14: .4byte 0x000001E3
_08020E18: .4byte gOamBuffer
_08020E1C: .4byte gUnknown_086B4922
_08020E20: .4byte 0xFFFFFE00
_08020E24: .4byte 0x000001FF
_08020E28: .4byte gMain
_08020E2C: .4byte 0x040000D4
_08020E30: .4byte gCurrentPinballGame
_08020E34: .4byte 0x00000744
_08020E38: .4byte gUnknown_084C07EC
_08020E3C: .4byte 0x06010480
_08020E40: .4byte 0x800000C0
_08020E44:
	movs r0, #0xc8
_08020E46:
	strh r0, [r6, #4]
	movs r4, #0
	ldr r7, _08020EB4 @ =gOamBuffer
	ldr r3, _08020EB8 @ =0xFFFFFE00
	mov sb, r3
_08020E50:
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	movs r4, #2
	ldrsh r1, [r5, r4]
	movs r4, #2
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r4, _08020EBC @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _08020E50
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08020EA4
	b _08020D96
_08020EA4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020EB4: .4byte gOamBuffer
_08020EB8: .4byte 0xFFFFFE00
_08020EBC: .4byte 0x000001FF
