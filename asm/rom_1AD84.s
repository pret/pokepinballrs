#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_1B140
sub_1B140: @ 0x0801B140
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r7, #0
	ldr r0, _0801B228 @ =gMain
	ldrb r0, [r0, #0xf]
	ldr r1, _0801B22C @ =gCurrentPinballGame
	mov r8, r1
	cmp r0, #0
	bne _0801B16A
	ldr r0, [r1]
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801B16A
	subs r0, #1
	strh r0, [r1]
_0801B16A:
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	beq _0801B176
	bl sub_1BB68
_0801B176:
	ldr r4, _0801B22C @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r6, #0xdd
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0x95
	bne _0801B1B8
	bl m4aMPlayAllStop
	ldr r0, [r4]
	ldr r2, _0801B230 @ =0x000006DE
	adds r1, r0, r2
	movs r2, #0
	strh r5, [r1]
	ldr r3, _0801B234 @ =0x000006DD
	adds r0, r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _0801B238 @ =0x00000252
	adds r0, r0, r2
	strh r5, [r0]
	ldr r0, _0801B228 @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0xce
	strh r1, [r0, #0x38]
	ldrh r1, [r0, #0x3c]
	strh r5, [r0, #0x3c]
_0801B1B8:
	ldr r1, [r4]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x92
	bne _0801B1E6
	adds r1, #0xe4
	movs r0, #0x12
	strb r0, [r1]
	ldr r1, _0801B23C @ =0x040000D4
	ldr r0, _0801B240 @ =gUnknown_084F61EC
	str r0, [r1]
	ldr r0, _0801B244 @ =0x06015C00
	str r0, [r1, #4]
	ldr r0, _0801B248 @ =0x800004A0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801B24C @ =gUnknown_081B45A4
	str r0, [r1]
	ldr r0, _0801B250 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _0801B254 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0801B1E6:
	ldr r0, [r4]
	adds r2, r0, r6
	ldrh r1, [r2]
	adds r0, r1, #0
	subs r0, #0x91
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r4
	cmp r0, #4
	bls _0801B1FC
	b _0801B332
_0801B1FC:
	cmp r1, #0x92
	bls _0801B2B8
	ldr r1, _0801B228 @ =gMain
	ldrh r0, [r1, #0x3c]
	movs r0, #4
	strh r0, [r1, #0x3c]
	ldrh r0, [r2]
	cmp r0, #0x94
	bls _0801B210
	b _0801B332
_0801B210:
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne _0801B264
	ldr r1, _0801B23C @ =0x040000D4
	ldr r2, _0801B258 @ =gUnknown_02031520
	ldr r0, [r2, #0x30]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B25C @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B260 @ =0x80000060
	b _0801B274
	.align 2, 0
_0801B228: .4byte gMain
_0801B22C: .4byte gCurrentPinballGame
_0801B230: .4byte 0x000006DE
_0801B234: .4byte 0x000006DD
_0801B238: .4byte 0x00000252
_0801B23C: .4byte 0x040000D4
_0801B240: .4byte gUnknown_084F61EC
_0801B244: .4byte 0x06015C00
_0801B248: .4byte 0x800004A0
_0801B24C: .4byte gUnknown_081B45A4
_0801B250: .4byte 0x05000180
_0801B254: .4byte 0x80000010
_0801B258: .4byte gUnknown_02031520
_0801B25C: .4byte 0x05000240
_0801B260: .4byte 0x80000060
_0801B264:
	ldr r1, _0801B29C @ =0x040000D4
	ldr r2, _0801B2A0 @ =gUnknown_02031520
	ldr r0, [r2, #0x30]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B2A4 @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B2A8 @ =0x80000070
_0801B274:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0801B29C @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0801B2AC @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801B2B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0801B2B4 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x6f
	movs r3, #0
	movs r1, #1
	b _0801B328
	.align 2, 0
_0801B29C: .4byte 0x040000D4
_0801B2A0: .4byte gUnknown_02031520
_0801B2A4: .4byte 0x05000240
_0801B2A8: .4byte 0x80000070
_0801B2AC: .4byte 0x05000340
_0801B2B0: .4byte 0x80000030
_0801B2B4: .4byte gCurrentPinballGame
_0801B2B8:
	ldr r1, _0801B2E0 @ =gMain
	ldrh r0, [r1, #0x3c]
	movs r0, #7
	strh r0, [r1, #0x3c]
	ldrh r0, [r2]
	cmp r0, #0x91
	bls _0801B2C8
	b _0801B44A
_0801B2C8:
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne _0801B2F4
	ldr r1, _0801B2E4 @ =0x040000D4
	ldr r2, _0801B2E8 @ =gUnknown_02031520
	ldr r0, [r2, #0x34]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B2EC @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B2F0 @ =0x80000060
	b _0801B304
	.align 2, 0
_0801B2E0: .4byte gMain
_0801B2E4: .4byte 0x040000D4
_0801B2E8: .4byte gUnknown_02031520
_0801B2EC: .4byte 0x05000240
_0801B2F0: .4byte 0x80000060
_0801B2F4:
	ldr r1, _0801B3FC @ =0x040000D4
	ldr r2, _0801B400 @ =gUnknown_02031520
	ldr r0, [r2, #0x34]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B404 @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B408 @ =0x80000070
_0801B304:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0801B3FC @ =0x040000D4
	ldr r0, [r2, #0x34]
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _0801B40C @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801B410 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0801B414 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x6f
	movs r3, #0
	movs r1, #2
_0801B328:
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x70
	strb r3, [r0]
	mov r8, r2
_0801B332:
	mov r5, r8
	ldr r0, [r5]
	movs r6, #0xdd
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0x91
	beq _0801B344
	b _0801B44A
_0801B344:
	movs r0, 0x0B @ =MUS_SHOP
	bl m4aSongNumStart
	ldr r0, [r5]
	movs r1, #0xd3
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r5]
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r3, [r5]
	ldr r2, _0801B418 @ =gUnknown_086AD2DE
	adds r1, r3, r1
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r5, _0801B41C @ =0x000001A7
	adds r1, r3, r5
	strb r0, [r1]
	movs r0, #6
	movs r1, #0
	bl sub_1C7F4
	movs r0, #1
	bl sub_21FBC
	ldr r2, _0801B420 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x1c]
	movs r3, #1
	strh r3, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x20]
	strh r3, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x18]
	strh r3, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x24]
	strh r3, [r0]
	ldr r1, _0801B3FC @ =0x040000D4
	ldr r0, _0801B424 @ =gUnknown_081B8784
	str r0, [r1]
	ldr r0, _0801B428 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0801B42C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801B430 @ =gUnknown_081B8984
	str r0, [r1]
	ldr r0, _0801B434 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0801B438 @ =0x80000620
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r6, _0801B43C @ =0x000002EA
	adds r1, r2, r6
	movs r0, #0x50
	strh r0, [r1]
	strh r4, [r2, #0x2a]
	mov r1, r8
	ldr r0, [r1]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0xf
	strh r1, [r0]
	strh r3, [r2, #0x28]
	movs r0, 0x8F @=SE_UNKNOWN_0x8F
	bl m4aSongNumStart
	mov r5, r8
	ldr r1, [r5]
	movs r6, #0xf1
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0801B440
	movs r0, #0xd5
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #1
	b _0801B448
	.align 2, 0
_0801B3FC: .4byte 0x040000D4
_0801B400: .4byte gUnknown_02031520
_0801B404: .4byte 0x05000240
_0801B408: .4byte 0x80000070
_0801B40C: .4byte 0x05000340
_0801B410: .4byte 0x80000030
_0801B414: .4byte gCurrentPinballGame
_0801B418: .4byte gUnknown_086AD2DE
_0801B41C: .4byte 0x000001A7
_0801B420: .4byte gMain
_0801B424: .4byte gUnknown_081B8784
_0801B428: .4byte 0x050003C0
_0801B42C: .4byte 0x80000010
_0801B430: .4byte gUnknown_081B8984
_0801B434: .4byte 0x06002000
_0801B438: .4byte 0x80000620
_0801B43C: .4byte 0x000002EA
_0801B440:
	movs r2, #0xd5
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r0, #0
_0801B448:
	strb r0, [r1]
_0801B44A:
	mov r4, r8
	ldr r3, [r4]
	movs r5, #0xdd
	lsls r5, r5, #1
	adds r0, r3, r5
	ldrh r0, [r0]
	cmp r0, #0x90
	bls _0801B45C
	b _0801B6F2
_0801B45C:
	movs r6, #0xdc
	lsls r6, r6, #3
	adds r1, r3, r6
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801B4D8 @ =0x000006C4
	adds r1, r3, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801B4DC @ =0x000006DB
	adds r0, r0, r1
	strb r2, [r0]
	movs r7, #0
	ldr r3, [r4]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r1, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0
	ble _0801B552
	subs r0, r1, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _0801B540
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r0, #0x1e
	subs r0, r0, r1
	lsls r1, r0, #3
	subs r1, r1, r0
	subs r4, #2
	adds r0, r3, r4
	strh r1, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0xf
	beq _0801B4B4
	b _0801B614
_0801B4B4:
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r1, r3, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _0801B4F0
	ldr r1, _0801B4E0 @ =0x000005F6
	adds r0, r3, r1
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _0801B4E4
	adds r0, r1, #0
	adds r0, #0xa
	b _0801B526
	.align 2, 0
_0801B4D8: .4byte 0x000006C4
_0801B4DC: .4byte 0x000006DB
_0801B4E0: .4byte 0x000005F6
_0801B4E4:
	ldr r4, _0801B4EC @ =0x000001A7
	adds r1, r3, r4
	movs r0, #0xc
	b _0801B52A
	.align 2, 0
_0801B4EC: .4byte 0x000001A7
_0801B4F0:
	cmp r0, #6
	bne _0801B518
	ldr r0, _0801B504 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0801B50C
	ldr r5, _0801B508 @ =0x000001A7
	adds r1, r3, r5
	movs r0, #0x16
	b _0801B52A
	.align 2, 0
_0801B504: .4byte gMain
_0801B508: .4byte 0x000001A7
_0801B50C:
	ldr r6, _0801B514 @ =0x000001A7
	adds r1, r3, r6
	movs r0, #0x17
	b _0801B52A
	.align 2, 0
_0801B514: .4byte 0x000001A7
_0801B518:
	ldr r0, _0801B538 @ =gUnknown_086AD2DE
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
_0801B526:
	ldr r2, _0801B53C @ =0x000001A7
	adds r1, r3, r2
_0801B52A:
	strb r0, [r1]
	movs r0, #6
	movs r1, #0
	bl sub_1C7F4
	movs r7, #1
	b _0801B614
	.align 2, 0
_0801B538: .4byte gUnknown_086AD2DE
_0801B53C: .4byte 0x000001A7
_0801B540:
	movs r4, #0
	ldrsh r1, [r2, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r5, #0xdb
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	b _0801B614
_0801B552:
	ldr r0, _0801B58C @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801B5B2
	ldr r6, _0801B590 @ =0x000006DD
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801B5B2
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801B594
	subs r0, r2, #1
	b _0801B596
	.align 2, 0
_0801B58C: .4byte gMain
_0801B590: .4byte 0x000006DD
_0801B594:
	movs r0, #7
_0801B596:
	strb r0, [r1]
	ldr r2, _0801B5EC @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0x1e
	strh r1, [r0]
_0801B5B2:
	ldr r0, _0801B5F0 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801B614
	ldr r5, _0801B5EC @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r6, _0801B5F4 @ =0x000006DD
	adds r0, r0, r6
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	bne _0801B614
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	ldr r0, [r5]
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bgt _0801B5F8
	adds r0, r2, #1
	strb r0, [r1]
	b _0801B5FA
	.align 2, 0
_0801B5EC: .4byte gCurrentPinballGame
_0801B5F0: .4byte gMain
_0801B5F4: .4byte 0x000006DD
_0801B5F8:
	strb r4, [r1]
_0801B5FA:
	ldr r2, _0801B63C @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0x1e
	strh r1, [r0]
_0801B614:
	adds r0, r7, #0
	bl sub_21FBC
	ldr r0, _0801B63C @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r5, #0xd4
	lsls r5, r5, #1
	adds r0, r1, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	beq _0801B64A
	ldr r6, _0801B640 @ =0x000001A9
	adds r1, r1, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B644
	subs r0, #1
	strb r0, [r1]
	b _0801B662
	.align 2, 0
_0801B63C: .4byte gCurrentPinballGame
_0801B640: .4byte 0x000001A9
_0801B644:
	movs r0, #7
	strb r0, [r1]
	b _0801B662
_0801B64A:
	ldr r0, _0801B65C @ =0x000001A9
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #6
	bhi _0801B660
	adds r0, #1
	strb r0, [r1]
	b _0801B662
	.align 2, 0
_0801B65C: .4byte 0x000001A9
_0801B660:
	strb r2, [r1]
_0801B662:
	ldr r1, _0801B6C0 @ =0x040000D4
	ldr r3, _0801B6C4 @ =gUnknown_086AD50C
	ldr r4, _0801B6C8 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801B6CC @ =0x000001A9
	adds r0, r2, r5
	ldrb r0, [r0]
	lsrs r0, r0, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0801B6D0 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0801B6D4 @ =0x80000620
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _0801B6D8 @ =gMain
	movs r6, #0x2a
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	movs r1, #0x50
	subs r1, r1, r0
	ldr r5, _0801B6DC @ =0x000002EA
	adds r0, r3, r5
	strh r1, [r0]
	ldr r6, _0801B6E0 @ =0x00000252
	adds r2, r2, r6
	ldrh r0, [r2]
	mov r8, r4
	cmp r0, #0
	beq _0801B6E4
	ldrh r1, [r3, #0x2a]
	movs r2, #0x2a
	ldrsh r0, [r3, r2]
	cmp r0, #0
	ble _0801B6F2
	subs r0, r1, #1
	strh r0, [r3, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0801B6F2
	strh r0, [r3, #0x28]
	movs r0, #0x90
	strh r0, [r3, #0x26]
	b _0801B6F2
	.align 2, 0
_0801B6C0: .4byte 0x040000D4
_0801B6C4: .4byte gUnknown_086AD50C
_0801B6C8: .4byte gCurrentPinballGame
_0801B6CC: .4byte 0x000001A9
_0801B6D0: .4byte 0x06002000
_0801B6D4: .4byte 0x80000620
_0801B6D8: .4byte gMain
_0801B6DC: .4byte 0x000002EA
_0801B6E0: .4byte 0x00000252
_0801B6E4:
	ldrh r1, [r3, #0x2a]
	movs r4, #0x2a
	ldrsh r0, [r3, r4]
	cmp r0, #0x13
	bgt _0801B6F2
	adds r0, r1, #1
	strh r0, [r3, #0x2a]
_0801B6F2:
	mov r5, r8
	ldr r2, [r5]
	movs r6, #0xdc
	lsls r6, r6, #1
	adds r0, r2, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0801B706
	b _0801B85E
_0801B706:
	ldr r0, _0801B76C @ =gMain
	movs r3, #0x2a
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x13
	bgt _0801B714
	b _0801B85E
_0801B714:
	ldrh r1, [r3, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0801B720
	b _0801B82C
_0801B720:
	ldr r4, _0801B770 @ =0x000006DD
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801B730
	b _0801B82C
_0801B730:
	ldr r5, _0801B774 @ =0x000001A7
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801B778 @ =gUnknown_086AD000
	adds r4, r0, r1
	ldr r1, _0801B77C @ =gUnknown_086AD2DE
	subs r6, #0x12
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _0801B784
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0801B784
	ldr r3, _0801B780 @ =0x000003E7
	b _0801B7AC
	.align 2, 0
_0801B76C: .4byte gMain
_0801B770: .4byte 0x000006DD
_0801B774: .4byte 0x000001A7
_0801B778: .4byte gUnknown_086AD000
_0801B77C: .4byte gUnknown_086AD2DE
_0801B780: .4byte 0x000003E7
_0801B784:
	mov r5, r8
	ldr r2, [r5]
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _0801B7AA
	ldr r1, _0801B804 @ =0x000001AF
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r3, _0801B808 @ =0x000003E7
	cmp r0, #0
	bne _0801B7AC
_0801B7AA:
	ldrh r3, [r4, #6]
_0801B7AC:
	ldr r4, _0801B80C @ =gCurrentPinballGame
	ldr r2, [r4]
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _0801B824
	ldr r6, _0801B810 @ =0x000006DD
	adds r1, r2, r6
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	ldr r2, _0801B814 @ =0x000001A7
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r5, _0801B818 @ =0x000006DC
	adds r0, r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	movs r6, #0xc9
	lsls r6, r6, #1
	adds r1, r0, r6
	ldrb r0, [r1]
	subs r0, r0, r3
	strb r0, [r1]
	bl m4aMPlayAllStop
	movs r0, 0x83 @=SE_UNKNOWN_0x83
	bl m4aSongNumStart
	ldr r0, [r4]
	ldr r2, _0801B81C @ =0x000001AB
	adds r1, r0, r2
	movs r0, #0x13
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _0801B820 @ =0x00000376
	adds r0, r0, r3
	movs r1, #0x1e
	strh r1, [r0]
	b _0801B85E
	.align 2, 0
_0801B804: .4byte 0x000001AF
_0801B808: .4byte 0x000003E7
_0801B80C: .4byte gCurrentPinballGame
_0801B810: .4byte 0x000006DD
_0801B814: .4byte 0x000001A7
_0801B818: .4byte 0x000006DC
_0801B81C: .4byte 0x000001AB
_0801B820: .4byte 0x00000376
_0801B824:
	movs r0, 0x8A @ SE_FAILURE
	bl m4aSongNumStart
	b _0801B85E
_0801B82C:
	ldrh r1, [r3, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801B85E
	ldr r0, _0801B928 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r4, _0801B92C @ =0x000006DD
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801B870
	ldr r5, _0801B930 @ =0x00000252
	adds r0, r2, r5
	movs r1, #0x1e
	strh r1, [r0]
	movs r6, #0xdc
	lsls r6, r6, #1
	adds r0, r2, r6
	strh r1, [r0]
	movs r0, 0x66 @=SE_UNKNOWN_0x66
	bl m4aSongNumStart
_0801B85E:
	ldr r0, _0801B928 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0801B92C @ =0x000006DD
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801B8B2
_0801B870:
	bl sub_2A354
	ldr r0, _0801B928 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0801B934 @ =0x000006DE
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0xb3
	bne _0801B8B2
	ldr r4, _0801B930 @ =0x00000252
	adds r0, r2, r4
	movs r1, #0x1e
	strh r1, [r0]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r0, r2, r5
	strh r1, [r0]
	ldr r1, _0801B938 @ =gUnknown_086AD2DE
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _0801B8B2
	ldr r0, _0801B93C @ =0x000001AF
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
_0801B8B2:
	ldr r0, _0801B928 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0801B930 @ =0x00000252
	adds r1, r2, r3
	ldrh r5, [r1]
	mov r8, r0
	cmp r5, #0
	bne _0801B8C6
	bl _0801C554
_0801B8C6:
	subs r0, r5, #1
	strh r0, [r1]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0xe
	bgt _0801B8DC
	movs r0, #0xf
	strh r0, [r1]
_0801B8DC:
	mov r6, r8
	ldr r0, [r6]
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #4
	bls _0801B8EA
	b _0801BA38
_0801B8EA:
	cmp r0, #1
	bls _0801B9A8
	ldr r5, _0801B940 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #4
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #3
	bls _0801B8FE
	b _0801BA38
_0801B8FE:
	ldr r3, _0801B944 @ =0x040000D4
	ldr r1, _0801B948 @ =gUnknown_02031520
	ldr r4, [r1, #0x30]
	str r4, [r3]
	ldr r0, _0801B94C @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801B950 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801B95C
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801B954 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801B958 @ =0x80000060
	b _0801B968
	.align 2, 0
_0801B928: .4byte gCurrentPinballGame
_0801B92C: .4byte 0x000006DD
_0801B930: .4byte 0x00000252
_0801B934: .4byte 0x000006DE
_0801B938: .4byte gUnknown_086AD2DE
_0801B93C: .4byte 0x000001AF
_0801B940: .4byte gMain
_0801B944: .4byte 0x040000D4
_0801B948: .4byte gUnknown_02031520
_0801B94C: .4byte 0x05000200
_0801B950: .4byte 0x80000010
_0801B954: .4byte 0x05000240
_0801B958: .4byte 0x80000060
_0801B95C:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801B994 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801B998 @ =0x80000070
_0801B968:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801B99C @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0801B9A0 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801B9A4 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r3, r8
	ldr r0, [r3]
	adds r0, #0x6f
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0x70
	b _0801BA36
	.align 2, 0
_0801B994: .4byte 0x05000240
_0801B998: .4byte 0x80000070
_0801B99C: .4byte 0x040000D4
_0801B9A0: .4byte 0x05000340
_0801B9A4: .4byte 0x80000030
_0801B9A8:
	ldr r5, _0801B9E4 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #0
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801B9BA
	bl _0801C554
_0801B9BA:
	ldr r3, _0801B9E8 @ =0x040000D4
	ldr r1, _0801B9EC @ =gUnknown_02031520
	ldr r4, [r1, #0x2c]
	str r4, [r3]
	ldr r0, _0801B9F0 @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801B9F4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801BA00
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801B9F8 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801B9FC @ =0x80000060
	b _0801BA0C
	.align 2, 0
_0801B9E4: .4byte gMain
_0801B9E8: .4byte 0x040000D4
_0801B9EC: .4byte gUnknown_02031520
_0801B9F0: .4byte 0x05000200
_0801B9F4: .4byte 0x80000010
_0801B9F8: .4byte 0x05000240
_0801B9FC: .4byte 0x80000060
_0801BA00:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801BA74 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801BA78 @ =0x80000070
_0801BA0C:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801BA7C @ =0x040000D4
	ldr r0, [r2, #0x2c]
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _0801BA80 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801BA84 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r5, r8
	ldr r0, [r5]
	adds r0, #0x6f
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x70
	movs r1, #1
_0801BA36:
	strb r1, [r0]
_0801BA38:
	mov r6, r8
	ldr r1, [r6]
	ldr r2, _0801BA88 @ =0x00000252
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801BA4A
	bl _0801C554
_0801BA4A:
	ldr r0, _0801BA8C @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0801BA9C
	ldr r3, _0801BA90 @ =0x00000283
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0801BA94
	movs r0, 0x1C @ =MUS_FIELD_RUBY
	bl m4aSongNumStart
	b _0801BAC6
	.align 2, 0
_0801BA74: .4byte 0x05000240
_0801BA78: .4byte 0x80000070
_0801BA7C: .4byte 0x040000D4
_0801BA80: .4byte 0x05000340
_0801BA84: .4byte 0x80000030
_0801BA88: .4byte 0x00000252
_0801BA8C: .4byte gMain
_0801BA90: .4byte 0x00000283
_0801BA94:
	movs r0, 0x5B @ =MUS_FIELD_RUBY2
	bl m4aSongNumStart
	b _0801BAC6
_0801BA9C:
	ldr r4, _0801BABC @ =0x00000283
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0801BAC0
	movs r0, 0x20 @ =MUS_FIELD_SAPPHIRE
	bl m4aSongNumStart
	b _0801BAC6
	.align 2, 0
_0801BABC: .4byte 0x00000283
_0801BAC0:
	movs r0, 0x5C @ =MUS_FIELD_SAPPHIRE2
	bl m4aSongNumStart
_0801BAC6:
	ldr r0, _0801BAE4 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801BAEC
	ldr r5, _0801BAE8 @ =0x000006DE
	adds r1, r1, r5
	movs r0, #0xaa
	strh r0, [r1]
	b _0801BAF0
	.align 2, 0
_0801BAE4: .4byte gCurrentPinballGame
_0801BAE8: .4byte 0x000006DE
_0801BAEC:
	movs r0, #0x18
	strh r0, [r1, #0x28]
_0801BAF0:
	ldr r0, _0801BB08 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0801BB0C
	movs r0, #1
	movs r1, #0
	bl sub_1C7F4
	b _0801BB14
	.align 2, 0
_0801BB08: .4byte gCurrentPinballGame
_0801BB0C:
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
_0801BB14:
	ldr r3, _0801BB54 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r6, _0801BB58 @ =0x000006C4
	adds r0, r0, r6
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r3]
	ldr r1, _0801BB5C @ =0x000006DB
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r3]
	ldr r4, _0801BB60 @ =0x000006DD
	adds r0, r0, r4
	strb r2, [r0]
	ldr r1, _0801BB64 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x1c]
	movs r4, #0
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x20]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x18]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x24]
	strh r2, [r0]
	ldr r0, [r3]
	bl _0801C528
	.align 2, 0
_0801BB54: .4byte gCurrentPinballGame
_0801BB58: .4byte 0x000006C4
_0801BB5C: .4byte 0x000006DB
_0801BB60: .4byte 0x000006DD
_0801BB64: .4byte gMain

	thumb_func_start sub_1BB68
sub_1BB68: @ 0x0801BB68
	movs r5, #0
	mov r6, r8
	ldr r1, [r6]
	ldr r2, _0801BD0C @ =0x00000281
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0801BB80
	bl sub_1C544
_0801BB80:
	movs r6, #0xdd
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x95
	bne _0801BC52
	bl m4aMPlayAllStop
	ldr r3, _0801BD10 @ =gMain
	ldrb r1, [r3, #0xf]
	movs r0, #1
	orrs r0, r1
	strb r0, [r3, #0xf]
	mov r0, r8
	ldr r4, [r0]
	adds r0, r4, #0
	adds r0, #0xea
	movs r2, #0
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	strh r5, [r0]
	subs r0, #2
	strh r5, [r0]
	adds r0, #8
	strh r5, [r0]
	adds r1, #6
	movs r0, #3
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	adds r0, #0xfb
	strb r2, [r0]
	ldr r4, [r4]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0801BD14 @ =0x0000F63C
	strh r0, [r1]
	subs r1, #6
	movs r0, #0x32
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf8
	strh r5, [r0]
	ldr r1, _0801BD18 @ =0x040000D4
	ldr r0, _0801BD1C @ =gUnknown_086ACEF8
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r0, _0801BD20 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0801BD24 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801BD28 @ =gUnknown_086ACF18
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r0, _0801BD2C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0801BD30 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r3, #0x38]
	movs r0, #0xce
	strh r0, [r3, #0x38]
	mov r0, r8
	ldr r3, [r0]
	adds r1, r3, r6
	movs r0, #0x94
	strh r0, [r1]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xd3
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r3]
	subs r1, #0x24
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r2, [r0]
	mov r4, r8
	ldr r0, [r4]
	subs r1, #0xaa
	adds r0, r0, r1
	strh r5, [r0]
_0801BC52:
	mov r2, r8
	ldr r1, [r2]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x92
	bne _0801BC82
	adds r1, #0xe4
	movs r0, #0x12
	strb r0, [r1]
	ldr r1, _0801BD18 @ =0x040000D4
	ldr r0, _0801BD34 @ =gUnknown_084F61EC
	str r0, [r1]
	ldr r0, _0801BD38 @ =0x06015C00
	str r0, [r1, #4]
	ldr r0, _0801BD3C @ =0x800004A0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801BD40 @ =gUnknown_081B4584
	str r0, [r1]
	ldr r0, _0801BD44 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _0801BD30 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0801BC82:
	mov r3, r8
	ldr r1, [r3]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x91
	beq _0801BC90
	b _0801BDAC
_0801BC90:
	movs r4, #0xd4
	lsls r4, r4, #1
	adds r0, r1, r4
	strb r5, [r0]
	ldr r1, [r3]
	movs r5, #0xa0
	lsls r5, r5, #2
	adds r0, r1, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r6, #0x9c
	lsls r6, r6, #2
	adds r0, r1, r6
	adds r0, r0, r2
	ldrb r3, [r0]
	movs r0, #0xb3
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r4, #0
	strh r3, [r2]
	ldr r2, _0801BD48 @ =0x0000025D
	adds r1, r1, r2
	strb r4, [r1]
	ldr r6, _0801BD4C @ =gSpeciesInfo
	mov r1, r8
	ldr r5, [r1]
	adds r0, r5, r0
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r4, [r0, #0x15]
	cmp r4, #0xcc
	bgt _0801BCF8
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r0, [r0, #0x15]
	cmp r0, #0xcc
	bgt _0801BCF8
	mov r3, r8
	ldr r1, [r3]
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801BCF8:
	bl sub_22FA4
	ldr r0, _0801BD10 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0801BD50
	movs r0, 0x1E @ =MUS_EVO_MODE
	bl m4aSongNumStart
	b _0801BD56
	.align 2, 0
_0801BD0C: .4byte 0x00000281
_0801BD10: .4byte gMain
_0801BD14: .4byte 0x0000F63C
_0801BD18: .4byte 0x040000D4
_0801BD1C: .4byte gUnknown_086ACEF8
_0801BD20: .4byte 0x06015800
_0801BD24: .4byte 0x80001200
_0801BD28: .4byte gUnknown_086ACF18
_0801BD2C: .4byte 0x050003C0
_0801BD30: .4byte 0x80000010
_0801BD34: .4byte gUnknown_084F61EC
_0801BD38: .4byte 0x06015C00
_0801BD3C: .4byte 0x800004A0
_0801BD40: .4byte gUnknown_081B4584
_0801BD44: .4byte 0x05000180
_0801BD48: .4byte 0x0000025D
_0801BD4C: .4byte gSpeciesInfo
_0801BD50:
	movs r0, 0x22 @ =MUS_EVO_MODE2
	bl m4aSongNumStart
_0801BD56:
	adds r0, r7, #0
	bl sub_21FBC
	ldr r3, _0801BE08 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x20]
	movs r5, #0
	movs r4, #1
	strh r4, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x24]
	strh r4, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x18]
	strh r4, [r0]
	ldr r2, _0801BE0C @ =0x040000D4
	ldr r0, _0801BE10 @ =gUnknown_081B8784
	str r0, [r2]
	ldr r0, _0801BE14 @ =0x050003C0
	str r0, [r2, #4]
	ldr r0, _0801BE18 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r6, _0801BE1C @ =0x000002EA
	adds r1, r3, r6
	movs r0, #0x50
	strh r0, [r1]
	strh r5, [r3, #0x2a]
	ldr r0, _0801BE20 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xf
	strh r1, [r0]
	strh r4, [r3, #0x28]
	ldr r0, _0801BE24 @ =gUnknown_081B4784
	str r0, [r2]
	ldr r0, _0801BE28 @ =0x06002000
	str r0, [r2, #4]
	ldr r0, _0801BE2C @ =0x80000620
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801BDAC:
	ldr r4, _0801BE20 @ =gCurrentPinballGame
	ldr r2, [r4]
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0x90
	bls _0801BDBE
	b _0801C2D8
_0801BDBE:
	movs r5, #0xdc
	lsls r5, r5, #3
	adds r1, r2, r5
	movs r6, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801BE30 @ =0x000006C4
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801BE34 @ =0x000006DB
	adds r0, r0, r1
	strb r6, [r0]
	ldr r3, [r4]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r2, r3, r5
	ldrh r1, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0
	ble _0801BE74
	subs r1, #1
	strh r1, [r2]
	movs r6, #0xd8
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801BE38
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	b _0801BE58
	.align 2, 0
_0801BE08: .4byte gMain
_0801BE0C: .4byte 0x040000D4
_0801BE10: .4byte gUnknown_081B8784
_0801BE14: .4byte 0x050003C0
_0801BE18: .4byte 0x80000010
_0801BE1C: .4byte 0x000002EA
_0801BE20: .4byte gCurrentPinballGame
_0801BE24: .4byte gUnknown_081B4784
_0801BE28: .4byte 0x06002000
_0801BE2C: .4byte 0x80000620
_0801BE30: .4byte 0x000006C4
_0801BE34: .4byte 0x000006DB
_0801BE38:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _0801BE64
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x1e
	subs r0, r0, r1
	lsls r1, r0, #3
	subs r1, r1, r0
	movs r4, #0xdb
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r1, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
_0801BE58:
	cmp r0, #0xf
	beq _0801BE5E
	b _0801C1FA
_0801BE5E:
	bl sub_22FA4
	b _0801C1FA
_0801BE64:
	movs r6, #0
	ldrsh r1, [r2, r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r2, #0xdb
	lsls r2, r2, #1
	adds r1, r3, r2
	b _0801C1F8
_0801BE74:
	ldr r5, _0801BEAC @ =0x00000281
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0801BE84
	b _0801BFA6
_0801BE84:
	ldr r0, _0801BEB0 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801BEEC
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	ldr r2, [r4]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r1, r2, r3
	ldrb r3, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801BEB4
	subs r0, r3, #1
	b _0801BEBA
	.align 2, 0
_0801BEAC: .4byte 0x00000281
_0801BEB0: .4byte gMain
_0801BEB4:
	adds r0, r2, r5
	ldrb r0, [r0]
	subs r0, #1
_0801BEBA:
	strb r0, [r1]
	ldr r5, _0801BEE8 @ =gCurrentPinballGame
	ldr r4, [r5]
	movs r6, #0xa0
	lsls r6, r6, #2
	adds r0, r4, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r0, r4, r2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strh r1, [r0]
	subs r6, #0xd8
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	b _0801BF48
	.align 2, 0
_0801BEE8: .4byte gCurrentPinballGame
_0801BEEC:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801BFA6
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	bge _0801BF1C
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0801BF1E
_0801BF1C:
	strb r6, [r2]
_0801BF1E:
	ldr r5, _0801C000 @ =gCurrentPinballGame
	ldr r4, [r5]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r3, #0x9c
	lsls r3, r3, #2
	adds r0, r4, r3
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strh r1, [r0]
	movs r6, #0xd4
	lsls r6, r6, #1
	adds r0, r4, r6
	strb r2, [r0]
_0801BF48:
	ldr r4, [r5]
	movs r0, #0xdc
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, [r5]
	movs r4, #0xd8
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r5]
	ldr r7, _0801C004 @ =0x0000025D
	adds r0, r0, r7
	strb r2, [r0]
	ldr r6, _0801C008 @ =gSpeciesInfo
	ldr r4, [r5]
	adds r3, r4, r3
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r2, [r0, #0x15]
	cmp r2, #0xcc
	bgt _0801BFA6
	adds r0, r7, #0
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r0, [r0, #0x15]
	cmp r0, #0xcc
	bgt _0801BFA6
	ldr r1, [r5]
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801BFA6:
	ldr r0, _0801C00C @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0801C070
	ldr r6, _0801C000 @ =gCurrentPinballGame
	ldr r1, [r6]
	movs r7, #0x97
	lsls r7, r7, #2
	adds r0, r1, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	bne _0801C014
	ldr r2, _0801C008 @ =gSpeciesInfo
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r5, [r0, #0x15]
	cmp r5, #0xcc
	bgt _0801C058
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r4, _0801C010 @ =0x0000059A
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r2, r1, r5
	movs r0, #0x1e
	strh r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	b _0801C04E
	.align 2, 0
_0801C000: .4byte gCurrentPinballGame
_0801C004: .4byte 0x0000025D
_0801C008: .4byte gSpeciesInfo
_0801C00C: .4byte gMain
_0801C010: .4byte 0x0000059A
_0801C014:
	cmp r4, #1
	bne _0801C058
	ldr r2, _0801C064 @ =gSpeciesInfo
	ldr r3, _0801C068 @ =0x0000059A
	adds r0, r1, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r5, [r0, #0x15]
	cmp r5, #0xcc
	bgt _0801C058
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r2, _0801C068 @ =0x0000059A
	adds r0, r1, r2
	strh r5, [r0]
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0x1e
	strh r0, [r2]
	movs r5, #0xd8
	lsls r5, r5, #1
	adds r1, r1, r5
	strb r4, [r1]
_0801C04E:
	ldr r1, [r6]
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C058:
	ldr r0, _0801C06C @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r6, #0xd9
	lsls r6, r6, #1
	adds r1, r0, r6
	b _0801C116
	.align 2, 0
_0801C064: .4byte gSpeciesInfo
_0801C068: .4byte 0x0000059A
_0801C06C: .4byte gCurrentPinballGame
_0801C070:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0801C11A
	ldr r6, _0801C0BC @ =gCurrentPinballGame
	ldr r1, [r6]
	movs r7, #0x97
	lsls r7, r7, #2
	adds r0, r1, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #1
	bne _0801C0C4
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r5, [r0]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xcc
	bgt _0801C10C
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r2, _0801C0C0 @ =0x0000059A
	adds r0, r1, r2
	strh r5, [r0]
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0x1e
	strh r0, [r2]
	movs r5, #0xd8
	lsls r5, r5, #1
	adds r1, r1, r5
	strb r4, [r1]
	b _0801C102
	.align 2, 0
_0801C0BC: .4byte gCurrentPinballGame
_0801C0C0: .4byte 0x0000059A
_0801C0C4:
	cmp r4, #2
	bne _0801C10C
	ldr r2, _0801C148 @ =gSpeciesInfo
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r5, [r0, #0x15]
	cmp r5, #0xcc
	bgt _0801C10C
	movs r0, 0x82 @=SE_UNKNOWN_0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r4, _0801C14C @ =0x0000059A
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r2, r1, r5
	movs r0, #0x1e
	strh r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
_0801C102:
	ldr r1, [r6]
	adds r1, r1, r7
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0801C10C:
	ldr r0, _0801C150 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r2, #0xd9
	lsls r2, r2, #1
	adds r1, r0, r2
_0801C116:
	movs r0, #0
	strh r0, [r1]
_0801C11A:
	ldr r0, _0801C150 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0801C1FA
	ldr r4, _0801C14C @ =0x0000059A
	adds r2, r1, r4
	ldrh r0, [r2]
	cmp r0, #0x59
	beq _0801C190
	cmp r0, #0x59
	bgt _0801C154
	cmp r0, #0xe
	beq _0801C168
	cmp r0, #0x10
	beq _0801C17C
	b _0801C1EA
	.align 2, 0
_0801C148: .4byte gSpeciesInfo
_0801C14C: .4byte 0x0000059A
_0801C150: .4byte gCurrentPinballGame
_0801C154:
	cmp r0, #0xb0
	beq _0801C1B8
	cmp r0, #0xb0
	bgt _0801C162
	cmp r0, #0x5a
	beq _0801C1A4
	b _0801C1EA
_0801C162:
	cmp r0, #0xb1
	beq _0801C1D2
	b _0801C1EA
_0801C168:
	movs r5, #0xd9
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x10
	b _0801C1CA
_0801C17C:
	movs r6, #0xd9
	lsls r6, r6, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xe
	b _0801C1CA
_0801C190:
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x5a
	b _0801C1CA
_0801C1A4:
	movs r3, #0xd9
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x59
	b _0801C1CA
_0801C1B8:
	movs r4, #0xd9
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xb1
_0801C1CA:
	strh r0, [r2]
	bl sub_22FA4
	b _0801C1EA
_0801C1D2:
	movs r5, #0xd9
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xb0
	strh r0, [r2]
	bl sub_22FA4
_0801C1EA:
	ldr r0, _0801C220 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r6, #0xd9
	lsls r6, r6, #1
	adds r1, r0, r6
	ldrh r0, [r1]
	adds r0, #1
_0801C1F8:
	strh r0, [r1]
_0801C1FA:
	bl sub_23070
	ldr r0, _0801C220 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	beq _0801C22E
	ldr r3, _0801C224 @ =0x000001A9
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801C228
	subs r0, #1
	strb r0, [r1]
	b _0801C246
	.align 2, 0
_0801C220: .4byte gCurrentPinballGame
_0801C224: .4byte 0x000001A9
_0801C228:
	movs r0, #7
	strb r0, [r1]
	b _0801C246
_0801C22E:
	ldr r4, _0801C240 @ =0x000001A9
	adds r1, r1, r4
	ldrb r0, [r1]
	cmp r0, #6
	bhi _0801C244
	adds r0, #1
	strb r0, [r1]
	b _0801C246
	.align 2, 0
_0801C240: .4byte 0x000001A9
_0801C244:
	strb r2, [r1]
_0801C246:
	ldr r1, _0801C2A4 @ =0x040000D4
	ldr r3, _0801C2A8 @ =gUnknown_086AD50C
	ldr r0, _0801C2AC @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r5, _0801C2B0 @ =0x000001A9
	adds r0, r2, r5
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r0, #4
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0801C2B4 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0801C2B8 @ =0x80000620
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _0801C2BC @ =gMain
	movs r6, #0x2a
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	movs r1, #0x50
	subs r1, r1, r0
	ldr r4, _0801C2C0 @ =0x000002EA
	adds r0, r3, r4
	strh r1, [r0]
	adds r5, #0xa9
	adds r2, r2, r5
	ldrh r0, [r2]
	cmp r0, #0
	beq _0801C2C4
	ldrh r1, [r3, #0x2a]
	movs r6, #0x2a
	ldrsh r0, [r3, r6]
	cmp r0, #0
	ble _0801C2D2
	subs r0, r1, #1
	strh r0, [r3, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0801C2D2
	strh r0, [r3, #0x28]
	movs r0, #0x90
	strh r0, [r3, #0x26]
	b _0801C2D2
	.align 2, 0
_0801C2A4: .4byte 0x040000D4
_0801C2A8: .4byte gUnknown_086AD50C
_0801C2AC: .4byte gCurrentPinballGame
_0801C2B0: .4byte 0x000001A9
_0801C2B4: .4byte 0x06002000
_0801C2B8: .4byte 0x80000620
_0801C2BC: .4byte gMain
_0801C2C0: .4byte 0x000002EA
_0801C2C4:
	ldrh r1, [r3, #0x2a]
	movs r2, #0x2a
	ldrsh r0, [r3, r2]
	cmp r0, #0x13
	bgt _0801C2D2
	adds r0, r1, #1
	strh r0, [r3, #0x2a]
_0801C2D2:
	movs r0, #0
	bl sub_21FBC
_0801C2D8:
	ldr r5, _0801C38C @ =gCurrentPinballGame
	ldr r3, [r5]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r3, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	bgt _0801C31A
	ldr r1, _0801C390 @ =gMain
	movs r2, #0x2a
	ldrsh r0, [r1, r2]
	cmp r0, #0x13
	ble _0801C31A
	ldrh r1, [r1, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801C31A
	ldr r6, _0801C394 @ =0x00000252
	adds r0, r3, r6
	movs r1, #0
	movs r2, #0x1e
	strh r2, [r0]
	subs r6, #0xa2
	adds r0, r3, r6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r4
	strh r2, [r0]
	movs r0, 0x83 @=SE_UNKNOWN_0x83
	bl m4aSongNumStart
_0801C31A:
	ldr r0, _0801C38C @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0801C394 @ =0x00000252
	adds r1, r2, r3
	ldrh r5, [r1]
	mov r8, r0
	cmp r5, #0
	bne _0801C32C
	b _0801C554
_0801C32C:
	subs r0, r5, #1
	strh r0, [r1]
	movs r0, #0xdc
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xe
	bgt _0801C342
	movs r0, #0xf
	strh r0, [r1]
_0801C342:
	mov r4, r8
	ldr r0, [r4]
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #4
	bls _0801C350
	b _0801C488
_0801C350:
	cmp r0, #1
	bls _0801C3FC
	ldr r5, _0801C390 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #4
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #3
	bls _0801C364
	b _0801C488
_0801C364:
	ldr r3, _0801C398 @ =0x040000D4
	ldr r1, _0801C39C @ =gUnknown_02031520
	ldr r4, [r1, #0x30]
	str r4, [r3]
	ldr r0, _0801C3A0 @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801C3A4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801C3B0
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C3A8 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C3AC @ =0x80000060
	b _0801C3BC
	.align 2, 0
_0801C38C: .4byte gCurrentPinballGame
_0801C390: .4byte gMain
_0801C394: .4byte 0x00000252
_0801C398: .4byte 0x040000D4
_0801C39C: .4byte gUnknown_02031520
_0801C3A0: .4byte 0x05000200
_0801C3A4: .4byte 0x80000010
_0801C3A8: .4byte 0x05000240
_0801C3AC: .4byte 0x80000060
_0801C3B0:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C3E8 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C3EC @ =0x80000070
_0801C3BC:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801C3F0 @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r0, r0, r5
	str r0, [r1]
	ldr r0, _0801C3F4 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801C3F8 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r6, r8
	ldr r0, [r6]
	adds r0, #0x6f
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0x70
	b _0801C486
	.align 2, 0
_0801C3E8: .4byte 0x05000240
_0801C3EC: .4byte 0x80000070
_0801C3F0: .4byte 0x040000D4
_0801C3F4: .4byte 0x05000340
_0801C3F8: .4byte 0x80000030
_0801C3FC:
	ldr r5, _0801C434 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #0
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801C40C
	b _0801C554
_0801C40C:
	ldr r3, _0801C438 @ =0x040000D4
	ldr r1, _0801C43C @ =gUnknown_02031520
	ldr r4, [r1, #0x2c]
	str r4, [r3]
	ldr r0, _0801C440 @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801C444 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801C450
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C448 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C44C @ =0x80000060
	b _0801C45C
	.align 2, 0
_0801C434: .4byte gMain
_0801C438: .4byte 0x040000D4
_0801C43C: .4byte gUnknown_02031520
_0801C440: .4byte 0x05000200
_0801C444: .4byte 0x80000010
_0801C448: .4byte 0x05000240
_0801C44C: .4byte 0x80000060
_0801C450:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C4B0 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C4B4 @ =0x80000070
_0801C45C:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801C4B8 @ =0x040000D4
	ldr r0, [r2, #0x2c]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0801C4BC @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801C4C0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r3, r8
	ldr r0, [r3]
	adds r0, #0x6f
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0x70
	movs r1, #1
_0801C486:
	strb r1, [r0]
_0801C488:
	mov r4, r8
	ldr r1, [r4]
	ldr r5, _0801C4C4 @ =0x00000252
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0801C554
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801C4CC
	ldr r6, _0801C4C8 @ =0x000006DE
	adds r1, r1, r6
	movs r0, #0xaa
	strh r0, [r1]
	b _0801C4D0
	.align 2, 0
_0801C4B0: .4byte 0x05000240
_0801C4B4: .4byte 0x80000070
_0801C4B8: .4byte 0x040000D4
_0801C4BC: .4byte 0x05000340
_0801C4C0: .4byte 0x80000030
_0801C4C4: .4byte 0x00000252
_0801C4C8: .4byte 0x000006DE
_0801C4CC:
	movs r0, #0x18
	strh r0, [r1, #0x28]
_0801C4D0:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0801C530 @ =0x000006C4
	adds r0, r0, r2
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r1]
	ldr r3, _0801C534 @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r1, _0801C538 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x20]
	movs r4, #0
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x18]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x24]
	strh r2, [r0]
	mov r5, r8
	ldr r0, [r5]
	movs r6, #0xe4
	lsls r6, r6, #3
	adds r0, r0, r6
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _0801C53C @ =0x0000071D
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _0801C540 @ =0x0000071E
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #0x44
	adds r0, r0, r3
	strb r1, [r0]
	bl sub_2310C
	ldr r0, [r5]
_0801C528:
	adds r0, #0xe4
	strb r4, [r0]
	b _0801C554
	.align 2, 0
_0801C530: .4byte 0x000006C4
_0801C534: .4byte 0x000006DB
_0801C538: .4byte gMain
_0801C53C: .4byte 0x0000071D
_0801C540: .4byte 0x0000071E

	thumb_func_start sub_1C544
sub_1C544: @ 0x0801C544
	movs r4, #0xdd
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x32
	bne _0801C554
	movs r0, #0x18
	strh r0, [r1, #0x28]
_0801C554:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_1C560
sub_1C560: @ 0x0801C560
	push {r4, lr}
	ldr r3, _0801C598 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r4, #0
	movs r2, #0
	movs r0, #0x96
	strh r0, [r1, #0x28]
	ldr r0, _0801C59C @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x34]
	strh r2, [r0]
	ldr r0, _0801C5A0 @ =0x000005F3
	adds r1, r1, r0
	strb r4, [r1]
	ldr r0, [r3]
	ldr r1, _0801C5A4 @ =0x00002710
	str r1, [r0, #0x3c]
	ldr r1, _0801C5A8 @ =0x000005F7
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #8
	bl sub_11B0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C598: .4byte gCurrentPinballGame
_0801C59C: .4byte gMain
_0801C5A0: .4byte 0x000005F3
_0801C5A4: .4byte 0x00002710
_0801C5A8: .4byte 0x000005F7

	thumb_func_start sub_1C5AC
sub_1C5AC: @ 0x0801C5AC
	push {r4, r5, r6, lr}
	ldr r5, _0801C614 @ =gCurrentPinballGame
	ldr r2, [r5]
	ldrh r0, [r2, #0x28]
	adds r1, r0, #0
	cmp r1, #0
	bne _0801C5BC
	b _0801C728
_0801C5BC:
	subs r0, #1
	movs r4, #0
	movs r6, #0
	strh r0, [r2, #0x28]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x94
	bls _0801C61C
	ldr r1, _0801C618 @ =0x0000132C
	adds r0, r2, r1
	ldr r0, [r0]
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	strb r4, [r0, #0x1f]
	ldr r3, [r5]
	adds r1, r3, r1
	ldr r0, [r1]
	strh r6, [r0, #0x30]
	ldr r0, [r1]
	strh r6, [r0, #0x32]
	ldr r2, [r1]
	movs r0, #0x77
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	adds r0, #0xa0
	strh r0, [r2, #0x12]
	ldr r0, [r1]
	strh r6, [r0, #6]
	ldr r2, [r1]
	movs r5, #0x10
	ldrsh r0, [r2, r5]
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	movs r5, #0xe6
	lsls r5, r5, #3
	adds r3, r3, r5
	strb r4, [r3]
	b _0801C706
	.align 2, 0
_0801C614: .4byte gCurrentPinballGame
_0801C618: .4byte 0x0000132C
_0801C61C:
	cmp r0, #0x94
	bne _0801C630
	movs r0, #1
	strb r0, [r2, #0x1f]
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	b _0801C706
_0801C630:
	cmp r0, #0x24
	bls _0801C644
	movs r0, #1
	strb r0, [r2, #0x1f]
	ldr r0, [r5]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r4, [r0]
	b _0801C706
_0801C644:
	cmp r0, #0x18
	bls _0801C658
	movs r1, #1
	strb r1, [r2, #0x1f]
	ldr r0, [r5]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r0, r3
	strb r1, [r0]
	b _0801C706
_0801C658:
	cmp r0, #0x18
	bne _0801C6B0
	movs r0, 0x80 @=SE_UNKNOWN_0x80
	bl m4aSongNumStart
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	ldr r3, _0801C6A4 @ =0x0000132C
	adds r1, r1, r3
	ldr r2, [r1]
	movs r0, #0x49
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	movs r0, #0xec
	strh r0, [r2, #0x32]
	ldr r0, [r1]
	strb r4, [r0]
	ldr r0, [r5]
	strb r4, [r0, #0x1f]
	ldr r0, [r5]
	ldr r2, _0801C6A8 @ =0x000005FA
	adds r0, r0, r2
	strb r4, [r0]
	ldr r1, [r5]
	adds r3, r1, r3
	ldr r2, [r3]
	movs r0, #0x88
	strh r0, [r2, #0xe]
	ldr r3, _0801C6AC @ =0x000005F7
	adds r1, r1, r3
	strb r4, [r1]
	b _0801C706
	.align 2, 0
_0801C6A4: .4byte 0x0000132C
_0801C6A8: .4byte 0x000005FA
_0801C6AC: .4byte 0x000005F7
_0801C6B0:
	cmp r0, #0xc
	bls _0801C6FC
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x15
	bls _0801C6E8
	ldr r2, _0801C6E4 @ =0x0000132C
	adds r0, r1, r2
	ldr r4, [r0]
	ldrh r0, [r1, #0x28]
	movs r1, #0x18
	subs r1, r1, r0
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #4
	movs r1, #3
	bl __divsi3
	adds r0, #0x90
	strh r0, [r4, #0xe]
	b _0801C706
	.align 2, 0
_0801C6E4: .4byte 0x0000132C
_0801C6E8:
	ldr r3, _0801C6F8 @ =0x0000132C
	adds r0, r1, r3
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0xe]
	b _0801C706
	.align 2, 0
_0801C6F8: .4byte 0x0000132C
_0801C6FC:
	movs r5, #0xe6
	lsls r5, r5, #3
	adds r1, r2, r5
	movs r0, #1
	strb r0, [r1]
_0801C706:
	ldr r0, _0801C724 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x28
	bhi _0801C736
	adds r1, #0xe6
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0801C736
	subs r0, r2, #1
	strh r0, [r1]
	b _0801C736
	.align 2, 0
_0801C724: .4byte gCurrentPinballGame
_0801C728:
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x25
	strb r1, [r0]
_0801C736:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_1C73C
sub_1C73C: @ 0x0801C73C
	push {r4, r5, r6, r7, lr}
	ldr r7, _0801C7E0 @ =gMain
	ldr r0, [r7, #0x44]
	ldr r0, [r0, #0x34]
	movs r6, #0
	movs r4, #0
	strh r4, [r0]
	movs r0, #0
	bl sub_4B408
	ldr r5, _0801C7E4 @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r2, _0801C7E8 @ =0x0000132C
	adds r1, r1, r2
	ldr r0, [r1]
	strh r4, [r0, #0x30]
	ldr r0, [r1]
	strh r4, [r0, #0x32]
	ldr r0, [r1]
	strb r6, [r0]
	ldr r0, [r5]
	strb r6, [r0, #0x1f]
	ldr r1, [r5]
	adds r2, r1, r2
	ldr r2, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #0xe]
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r1, r0
	strb r6, [r1]
	ldr r0, [r5]
	adds r0, #0x25
	strb r6, [r0]
	ldr r1, [r5]
	ldr r2, _0801C7EC @ =0x00000282
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801C7BA
	ldr r2, _0801C7F0 @ =0x00000723
	adds r0, r1, r2
	strb r6, [r0]
	ldr r0, [r5]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	subs r2, #6
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	subs r1, #2
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, #2
	adds r0, r0, r2
	strb r6, [r0]
_0801C7BA:
	bl m4aMPlayAllStop
	bl sub_0D10
	ldrb r0, [r7, #4]
	strb r0, [r7, #5]
	ldr r0, [r5]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #6]
	strb r6, [r7, #3]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C7E0: .4byte gMain
_0801C7E4: .4byte gCurrentPinballGame
_0801C7E8: .4byte 0x0000132C
_0801C7EC: .4byte 0x00000282
_0801C7F0: .4byte 0x00000723

	thumb_func_start sub_1C7F4
sub_1C7F4: @ 0x0801C7F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x2c]
	lsrs r1, r0, #0x10
	str r1, [sp, #0x28]
	asrs r0, r0, #0x10
	ldr r2, _0801C824 @ =gCurrentPinballGame
	mov sl, r2
	cmp r0, #9
	bls _0801C81A
	bl _0801D0B8
_0801C81A:
	lsls r0, r0, #2
	ldr r1, _0801C828 @ =_0801C82C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C824: .4byte gCurrentPinballGame
_0801C828: .4byte _0801C82C
_0801C82C: @ jump table
	.4byte _0801C854 @ case 0
	.4byte _0801C900 @ case 1
	.4byte _0801C9A8 @ case 2
	.4byte _0801CA4C @ case 3
	.4byte _0801CCB8 @ case 4
	.4byte _0801D0B8 @ case 5
	.4byte _0801CDC0 @ case 6
	.4byte _0801CF6C @ case 7
	.4byte _0801D02C @ case 8
	.4byte _0801CB24 @ case 9
_0801C854:
	ldr r6, _0801C8D0 @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r3, _0801C8D4 @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, [sp, #0x2c]
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	ldr r2, _0801C8D8 @ =0x00000749
	adds r1, r0, r2
	adds r1, r1, r3
	ldr r5, _0801C8DC @ =0x000006D9
	mov r8, r5
	add r0, r8
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r4, _0801C8E0 @ =0x040000D4
	ldr r5, [r6]
	adds r2, r5, r2
	adds r2, r2, r3
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801C8E4 @ =gUnknown_0848D68C
	adds r0, r0, r1
	str r0, [r4]
	lsls r2, r3, #1
	adds r0, r2, r3
	lsls r0, r0, #8
	ldr r1, _0801C8E8 @ =0x06010CA0
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _0801C8EC @ =0x80000180
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	add r5, r8
	adds r5, r5, r3
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #0x14
	lsrs r0, r0, #0xf
	ldr r1, _0801C8F0 @ =gUnknown_081C00E4
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0801C8F4 @ =gUnknown_086AD798
	adds r2, r2, r0
	ldrh r0, [r2]
	lsls r0, r0, #5
	ldr r2, _0801C8F8 @ =0x05000200
	adds r0, r0, r2
	str r0, [r4, #4]
	ldr r0, _0801C8FC @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov sl, r6
	bl _0801D0B8
	.align 2, 0
_0801C8D0: .4byte gCurrentPinballGame
_0801C8D4: .4byte 0x000006DB
_0801C8D8: .4byte 0x00000749
_0801C8DC: .4byte 0x000006D9
_0801C8E0: .4byte 0x040000D4
_0801C8E4: .4byte gUnknown_0848D68C
_0801C8E8: .4byte 0x06010CA0
_0801C8EC: .4byte 0x80000180
_0801C8F0: .4byte gUnknown_081C00E4
_0801C8F4: .4byte gUnknown_086AD798
_0801C8F8: .4byte 0x05000200
_0801C8FC: .4byte 0x80000010
_0801C900:
	ldr r7, _0801C97C @ =gUnknown_086AD070
	ldr r6, _0801C980 @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r3, [sp, #0x2c]
	lsls r4, r3, #0x10
	asrs r4, r4, #0x10
	ldr r5, _0801C984 @ =0x00000749
	mov r8, r5
	adds r5, r0, r5
	adds r5, r5, r4
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	strb r0, [r5]
	ldrh r2, [r7, #4]
	lsls r2, r2, #0x14
	ldr r3, _0801C988 @ =0x040000D4
	ldr r0, [r6]
	add r0, r8
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801C98C @ =gUnknown_083A8EEC
	adds r0, r0, r1
	str r0, [r3]
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r4, r4, #8
	ldr r5, _0801C990 @ =0x06010CA0
	adds r4, r4, r5
	str r4, [r3, #4]
	ldr r0, _0801C994 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	lsrs r2, r2, #0xf
	ldr r0, _0801C998 @ =gUnknown_081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801C99C @ =gUnknown_086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801C9A0 @ =0x05000200
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0801C9A4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, r6
	b _0801D0B8
	.align 2, 0
_0801C97C: .4byte gUnknown_086AD070
_0801C980: .4byte gCurrentPinballGame
_0801C984: .4byte 0x00000749
_0801C988: .4byte 0x040000D4
_0801C98C: .4byte gUnknown_083A8EEC
_0801C990: .4byte 0x06010CA0
_0801C994: .4byte 0x80000180
_0801C998: .4byte gUnknown_081C02E4
_0801C99C: .4byte gUnknown_086AD798
_0801C9A0: .4byte 0x05000200
_0801C9A4: .4byte 0x80000010
_0801C9A8:
	ldr r5, _0801CA1C @ =gCurrentPinballGame
	ldr r3, [r5]
	ldr r4, [sp, #0x2c]
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	ldr r1, _0801CA20 @ =0x000006EC
	adds r0, r3, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801CA24 @ =gUnknown_086AD000
	adds r7, r0, r1
	ldr r1, _0801CA28 @ =0x00000749
	adds r3, r3, r1
	adds r3, r3, r2
	ldrh r0, [r7]
	strb r0, [r3]
	ldrh r3, [r7, #4]
	lsls r3, r3, #0x14
	ldr r4, _0801CA2C @ =0x040000D4
	ldr r0, [r5]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CA30 @ =gUnknown_083A8EEC
	adds r0, r0, r1
	str r0, [r4]
	lsls r1, r2, #1
	adds r2, r1, r2
	lsls r2, r2, #8
	ldr r0, _0801CA34 @ =0x06010CA0
	adds r2, r2, r0
	str r2, [r4, #4]
	ldr r0, _0801CA38 @ =0x80000180
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	lsrs r3, r3, #0xf
	ldr r0, _0801CA3C @ =gUnknown_081C02E4
	adds r3, r3, r0
	str r3, [r4]
	ldr r0, _0801CA40 @ =gUnknown_086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801CA44 @ =0x05000200
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _0801CA48 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov sl, r5
	b _0801D0B8
	.align 2, 0
_0801CA1C: .4byte gCurrentPinballGame
_0801CA20: .4byte 0x000006EC
_0801CA24: .4byte gUnknown_086AD000
_0801CA28: .4byte 0x00000749
_0801CA2C: .4byte 0x040000D4
_0801CA30: .4byte gUnknown_083A8EEC
_0801CA34: .4byte 0x06010CA0
_0801CA38: .4byte 0x80000180
_0801CA3C: .4byte gUnknown_081C02E4
_0801CA40: .4byte gUnknown_086AD798
_0801CA44: .4byte 0x05000200
_0801CA48: .4byte 0x80000010
_0801CA4C:
	ldr r7, _0801CAFC @ =gCurrentPinballGame
	ldr r1, [r7]
	ldr r2, [sp, #0x2c]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	mov r8, r2
	ldr r2, _0801CB00 @ =0x00000749
	adds r0, r1, r2
	add r0, r8
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r1, r1, r3
	ldrh r1, [r1]
	strb r1, [r0]
	ldr r5, _0801CB04 @ =0x040000D4
	ldr r4, _0801CB08 @ =gMonPortraitGroupGfx
	mov sl, r4
	ldr r6, [r7]
	adds r6, r6, r2
	add r6, r8
	ldrb r0, [r6]
	mov sb, r0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, sl
	mov r0, sb
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r5]
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #3
	ldr r2, _0801CB0C @ =0x06010CA0
	adds r0, r0, r2
	str r0, [r5, #4]
	ldr r0, _0801CB10 @ =0x80000180
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r3, _0801CB14 @ =gMonPortraitGroupPals
	mov r8, r3
	ldrb r6, [r6]
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r5]
	ldr r0, _0801CB18 @ =0x050003A0
	str r0, [r5, #4]
	ldr r1, _0801CB1C @ =0x80000010
	str r1, [r5, #8]
	ldr r0, [r5, #8]
	mov r4, r8
	ldr r0, [r4]
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r5]
	ldr r0, _0801CB20 @ =0x050003E0
	str r0, [r5, #4]
	str r1, [r5, #8]
	ldr r0, [r5, #8]
	mov sl, r7
	b _0801D0B8
	.align 2, 0
_0801CAFC: .4byte gCurrentPinballGame
_0801CB00: .4byte 0x00000749
_0801CB04: .4byte 0x040000D4
_0801CB08: .4byte gMonPortraitGroupGfx
_0801CB0C: .4byte 0x06010CA0
_0801CB10: .4byte 0x80000180
_0801CB14: .4byte gMonPortraitGroupPals
_0801CB18: .4byte 0x050003A0
_0801CB1C: .4byte 0x80000010
_0801CB20: .4byte 0x050003E0
_0801CB24:
	ldr r0, _0801CB68 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	ble _0801CBEC
	ldr r0, _0801CB6C @ =gMain+0x74
	ldr r5, _0801CB70 @ =0x0000059A
	adds r1, r4, r5
	ldrh r3, [r1]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801CB80
	ldr r0, [sp, #0x2c]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	ldr r3, _0801CB74 @ =0x00000749
	adds r0, r4, r3
	adds r0, r0, r2
	movs r1, #0xcd
	strb r1, [r0]
	ldr r5, _0801CB78 @ =0x040000D4
	ldr r1, _0801CB7C @ =gMonPortraitGroupPals
	mov r8, r1
	mov r4, sl
	ldr r0, [r4]
	b _0801CC0C
	.align 2, 0
_0801CB68: .4byte gCurrentPinballGame
_0801CB6C: .4byte gMain+0x74
_0801CB70: .4byte 0x0000059A
_0801CB74: .4byte 0x00000749
_0801CB78: .4byte 0x040000D4
_0801CB7C: .4byte gMonPortraitGroupPals
_0801CB80:
	cmp r0, #3
	bhi _0801CBC0
	ldr r5, [sp, #0x2c]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r2, _0801CBAC @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, _0801CBB0 @ =0x040000D4
	ldr r0, _0801CBB4 @ =gMonPortraitGroupPals
	ldr r0, [r0]
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0801CBB8 @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0801CBBC @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0801CC3E
	.align 2, 0
_0801CBAC: .4byte 0x00000749
_0801CBB0: .4byte 0x040000D4
_0801CBB4: .4byte gMonPortraitGroupPals
_0801CBB8: .4byte 0x050003A0
_0801CBBC: .4byte 0x80000010
_0801CBC0:
	ldr r5, [sp, #0x2c]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r2, _0801CBE0 @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r5, _0801CBE4 @ =0x040000D4
	ldr r0, _0801CBE8 @ =gMonPortraitGroupPals
	mov r8, r0
	mov r3, sl
	ldr r0, [r3]
	adds r0, r0, r2
	adds r0, r0, r1
	b _0801CC10
	.align 2, 0
_0801CBE0: .4byte 0x00000749
_0801CBE4: .4byte 0x040000D4
_0801CBE8: .4byte gMonPortraitGroupPals
_0801CBEC:
	ldr r5, [sp, #0x2c]
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	ldr r3, _0801CC98 @ =0x00000749
	adds r0, r4, r3
	adds r0, r0, r2
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r1, r4, r5
	ldrh r1, [r1]
	strb r1, [r0]
	ldr r5, _0801CC9C @ =0x040000D4
	ldr r0, _0801CCA0 @ =gMonPortraitGroupPals
	mov r8, r0
	mov r1, sl
	ldr r0, [r1]
_0801CC0C:
	adds r0, r0, r3
	adds r0, r0, r2
_0801CC10:
	ldrb r6, [r0]
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r5]
	ldr r0, _0801CCA4 @ =0x050003A0
	str r0, [r5, #4]
	ldr r0, _0801CCA8 @ =0x80000010
	str r0, [r5, #8]
	ldr r0, [r5, #8]
_0801CC3E:
	ldr r2, _0801CC9C @ =0x040000D4
	mov r8, r2
	ldr r3, _0801CCAC @ =gMonPortraitGroupGfx
	mov sb, r3
	mov r4, sl
	ldr r0, [r4]
	ldr r1, [sp, #0x2c]
	lsls r5, r1, #0x10
	asrs r5, r5, #0x10
	ldr r2, _0801CC98 @ =0x00000749
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r6, [r0]
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, sb
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	mov r3, r8
	str r0, [r3]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r4, _0801CCB0 @ =0x06010CA0
	adds r0, r0, r4
	str r0, [r3, #4]
	ldr r0, _0801CCB4 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	b _0801D0B8
	.align 2, 0
_0801CC98: .4byte 0x00000749
_0801CC9C: .4byte 0x040000D4
_0801CCA0: .4byte gMonPortraitGroupPals
_0801CCA4: .4byte 0x050003A0
_0801CCA8: .4byte 0x80000010
_0801CCAC: .4byte gMonPortraitGroupGfx
_0801CCB0: .4byte 0x06010CA0
_0801CCB4: .4byte 0x80000180
_0801CCB8:
	ldr r0, _0801CD28 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0x17
	ldrsb r1, [r2, r1]
	mov sl, r0
	cmp r1, #2
	bne _0801CD44
	ldr r0, [sp, #0x2c]
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	ldr r1, _0801CD2C @ =0x00000749
	mov r8, r1
	adds r4, r2, r1
	adds r4, r4, r5
	ldr r6, _0801CD30 @ =gUnknown_086AD000
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x78
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r2, _0801CD34 @ =0x040000D4
	mov r4, sl
	ldr r0, [r4]
	add r0, r8
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CD38 @ =gUnknown_083A8EEC
	adds r0, r0, r1
	str r0, [r2]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #8
	ldr r5, _0801CD3C @ =0x06010CA0
	adds r0, r0, r5
	str r0, [r2, #4]
	ldr r0, _0801CD40 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r6, #0x7c
	ldrh r5, [r6]
	b _0801CF30
	.align 2, 0
_0801CD28: .4byte gCurrentPinballGame
_0801CD2C: .4byte 0x00000749
_0801CD30: .4byte gUnknown_086AD000
_0801CD34: .4byte 0x040000D4
_0801CD38: .4byte gUnknown_083A8EEC
_0801CD3C: .4byte 0x06010CA0
_0801CD40: .4byte 0x80000180
_0801CD44:
	ldr r0, [sp, #0x2c]
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	ldr r1, _0801CDA8 @ =0x00000749
	mov r8, r1
	adds r4, r2, r1
	adds r4, r4, r5
	ldr r6, _0801CDAC @ =gUnknown_086AD000
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x80
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r2, _0801CDB0 @ =0x040000D4
	mov r4, sl
	ldr r0, [r4]
	add r0, r8
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CDB4 @ =gUnknown_083A8EEC
	adds r0, r0, r1
	str r0, [r2]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #8
	ldr r5, _0801CDB8 @ =0x06010CA0
	adds r0, r0, r5
	str r0, [r2, #4]
	ldr r0, _0801CDBC @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r6, #0x84
	ldrh r0, [r6]
	lsls r0, r0, #0x14
	lsrs r5, r0, #0x10
	b _0801CF30
	.align 2, 0
_0801CDA8: .4byte 0x00000749
_0801CDAC: .4byte gUnknown_086AD000
_0801CDB0: .4byte 0x040000D4
_0801CDB4: .4byte gUnknown_083A8EEC
_0801CDB8: .4byte 0x06010CA0
_0801CDBC: .4byte 0x80000180
_0801CDC0:
	ldr r4, _0801CEF8 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801CEFC @ =0x000001A7
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801CF00 @ =gUnknown_086AD000
	adds r7, r0, r1
	ldr r0, [sp, #0x2c]
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	ldr r1, _0801CF04 @ =0x00000749
	adds r2, r2, r1
	adds r2, r2, r3
	ldrh r0, [r7]
	strb r0, [r2]
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x14
	lsrs r5, r0, #0x10
	ldr r2, _0801CF08 @ =0x040000D4
	ldr r0, [r4]
	mov r8, r0
	add r1, r8
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CF0C @ =gUnknown_083A8EEC
	adds r0, r0, r1
	str r0, [r2]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #8
	ldr r1, _0801CF10 @ =0x06010CA0
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _0801CF14 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, r8
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	mov sl, r4
	ldrh r7, [r7, #6]
	cmp r0, r7
	blo _0801CE5A
	ldr r1, _0801CF18 @ =gUnknown_086AD2DE
	movs r4, #0xd3
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #3
	bne _0801CE4C
	adds r3, #0x50
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0801CE5A
_0801CE4C:
	cmp r1, #4
	bne _0801CF30
	ldr r0, _0801CF1C @ =0x000001AF
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801CF30
_0801CE5A:
	ldr r2, _0801CF08 @ =0x040000D4
	lsls r0, r5, #1
	ldr r1, _0801CF20 @ =gUnknown_081C02E4
	adds r0, r0, r1
	str r0, [r2]
	mov r4, sp
	str r4, [r2, #4]
	ldr r0, _0801CF24 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r5, _0801CF28 @ =gUnknown_086AD798
	mov sb, r5
	add r7, sp, #0x20
_0801CE76:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #1
	mov r1, sp
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r0, r0, #1
	movs r1, #3
	bl __divsi3
	mov r8, r0
	mov r2, r8
	strh r2, [r7]
	ldrh r0, [r6]
	movs r3, #0xf8
	lsls r3, r3, #2
	adds r1, r3, #0
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #3
	bl __divsi3
	adds r4, r0, #0
	strh r4, [r7, #2]
	ldrh r0, [r6]
	movs r2, #0xf8
	lsls r2, r2, #7
	adds r1, r2, #0
	ands r0, r1
	lsrs r0, r0, #9
	movs r1, #3
	bl __divsi3
	strh r0, [r7, #4]
	lsls r4, r4, #5
	mov r3, r8
	orrs r4, r3
	lsls r0, r0, #0xa
	orrs r4, r0
	strh r4, [r6]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #0xf
	ble _0801CE76
	ldr r1, _0801CF08 @ =0x040000D4
	mov r4, sp
	str r4, [r1]
	ldr r5, [sp, #0x2c]
	lsls r0, r5, #0x10
	asrs r0, r0, #0xf
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r2, _0801CF2C @ =0x05000200
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _0801CF24 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0801D0B8
	.align 2, 0
_0801CEF8: .4byte gCurrentPinballGame
_0801CEFC: .4byte 0x000001A7
_0801CF00: .4byte gUnknown_086AD000
_0801CF04: .4byte 0x00000749
_0801CF08: .4byte 0x040000D4
_0801CF0C: .4byte gUnknown_083A8EEC
_0801CF10: .4byte 0x06010CA0
_0801CF14: .4byte 0x80000180
_0801CF18: .4byte gUnknown_086AD2DE
_0801CF1C: .4byte 0x000001AF
_0801CF20: .4byte gUnknown_081C02E4
_0801CF24: .4byte 0x80000010
_0801CF28: .4byte gUnknown_086AD798
_0801CF2C: .4byte 0x05000200
_0801CF30:
	ldr r2, _0801CF58 @ =0x040000D4
	lsls r0, r5, #1
	ldr r1, _0801CF5C @ =gUnknown_081C02E4
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0801CF60 @ =gUnknown_086AD798
	ldr r3, [sp, #0x2c]
	lsls r0, r3, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r4, _0801CF64 @ =0x05000200
	adds r0, r0, r4
	str r0, [r2, #4]
	ldr r0, _0801CF68 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0801D0B8
	.align 2, 0
_0801CF58: .4byte 0x040000D4
_0801CF5C: .4byte gUnknown_081C02E4
_0801CF60: .4byte gUnknown_086AD798
_0801CF64: .4byte 0x05000200
_0801CF68: .4byte 0x80000010
_0801CF6C:
	ldr r5, _0801CFFC @ =gCurrentPinballGame
	mov r8, r5
	ldr r2, [r5]
	ldr r0, [sp, #0x2c]
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	ldr r1, _0801D000 @ =0x000006EC
	adds r0, r2, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801D004 @ =gUnknown_086AD000
	adds r7, r0, r1
	ldr r6, _0801D008 @ =0x00000749
	adds r5, r2, r6
	adds r5, r5, r4
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r7, r0
	ldrh r0, [r0]
	strb r0, [r5]
	ldrh r2, [r7, #4]
	lsls r2, r2, #0x14
	ldr r3, _0801D00C @ =0x040000D4
	mov r5, r8
	ldr r0, [r5]
	adds r0, r0, r6
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801D010 @ =gUnknown_083A8EEC
	adds r0, r0, r1
	str r0, [r3]
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r4, r4, #8
	ldr r0, _0801D014 @ =0x06010CA0
	adds r4, r4, r0
	str r4, [r3, #4]
	ldr r0, _0801D018 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	lsrs r2, r2, #0xf
	ldr r0, _0801D01C @ =gUnknown_081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801D020 @ =gUnknown_086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801D024 @ =0x05000200
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0801D028 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, r8
	b _0801D0B8
	.align 2, 0
_0801CFFC: .4byte gCurrentPinballGame
_0801D000: .4byte 0x000006EC
_0801D004: .4byte gUnknown_086AD000
_0801D008: .4byte 0x00000749
_0801D00C: .4byte 0x040000D4
_0801D010: .4byte gUnknown_083A8EEC
_0801D014: .4byte 0x06010CA0
_0801D018: .4byte 0x80000180
_0801D01C: .4byte gUnknown_081C02E4
_0801D020: .4byte gUnknown_086AD798
_0801D024: .4byte 0x05000200
_0801D028: .4byte 0x80000010
_0801D02C:
	ldr r2, _0801D0EC @ =gCurrentPinballGame
	mov sb, r2
	ldr r2, [r2]
	ldr r3, _0801D0F0 @ =0x000006DC
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _0801D0F4 @ =gUnknown_086AD000
	adds r7, r0, r1
	ldr r5, [sp, #0x2c]
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	ldr r0, _0801D0F8 @ =0x00000749
	mov r8, r0
	adds r5, r2, r0
	adds r5, r5, r4
	ldr r6, _0801D0FC @ =gUnknown_086AD79C
	ldr r1, _0801D100 @ =0x000006DE
	adds r2, r2, r1
	ldrh r0, [r2]
	movs r1, #0xc
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r7, r0
	ldrh r0, [r0]
	strb r0, [r5]
	ldrh r2, [r7, #4]
	lsls r2, r2, #0x14
	ldr r3, _0801D104 @ =0x040000D4
	mov r5, sb
	ldr r0, [r5]
	add r0, r8
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801D108 @ =gUnknown_083A8EEC
	adds r0, r0, r1
	str r0, [r3]
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r4, r4, #8
	ldr r0, _0801D10C @ =0x06010CA0
	adds r4, r4, r0
	str r4, [r3, #4]
	ldr r0, _0801D110 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	lsrs r2, r2, #0xf
	ldr r0, _0801D114 @ =gUnknown_081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801D118 @ =gUnknown_086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801D11C @ =0x05000200
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0801D120 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, sb
_0801D0B8:
	mov r2, sl
	ldr r1, [r2]
	ldr r3, [sp, #0x2c]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r4, _0801D124 @ =0x00000747
	adds r1, r1, r4
	adds r1, r1, r0
	add r5, sp, #0x28
	ldrb r5, [r5]
	strb r5, [r1]
	ldr r1, [r2]
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D0EC: .4byte gCurrentPinballGame
_0801D0F0: .4byte 0x000006DC
_0801D0F4: .4byte gUnknown_086AD000
_0801D0F8: .4byte 0x00000749
_0801D0FC: .4byte gUnknown_086AD79C
_0801D100: .4byte 0x000006DE
_0801D104: .4byte 0x040000D4
_0801D108: .4byte gUnknown_083A8EEC
_0801D10C: .4byte 0x06010CA0
_0801D110: .4byte 0x80000180
_0801D114: .4byte gUnknown_081C02E4
_0801D118: .4byte gUnknown_086AD798
_0801D11C: .4byte 0x05000200
_0801D120: .4byte 0x80000010
_0801D124: .4byte 0x00000747

	thumb_func_start sub_1D128
sub_1D128: @ 0x0801D128
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r1, _0801D154 @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r2, _0801D158 @ =0x000006C4
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #3
	bne _0801D15C
	movs r3, #0
	mov r8, r3
	movs r0, #0xb4
	mov sl, r0
	movs r2, #0xb4
	b _0801D1C4
	.align 2, 0
_0801D154: .4byte gCurrentPinballGame
_0801D158: .4byte 0x000006C4
_0801D15C:
	cmp r0, #2
	bne _0801D190
	ldr r0, _0801D174 @ =gMain
	movs r2, #0x2a
	ldrsh r1, [r0, r2]
	cmp r1, #0x13
	bgt _0801D178
	movs r3, #0xb4
	mov sl, r3
	movs r2, #0xb4
	b _0801D18A
	.align 2, 0
_0801D174: .4byte gMain
_0801D178:
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	movs r2, #0x58
_0801D18A:
	movs r3, #0x30
	mov r8, r3
	b _0801D1C4
_0801D190:
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x60
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r3, r1
	movs r1, #0x96
	lsls r1, r1, #1
	adds r2, r1, #0
	ldrh r0, [r0]
	adds r0, r2, r0
	adds r1, r3, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
_0801D1C4:
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x58]
	mov r0, r8
	strh r0, [r6, #2]
	mov r1, sl
	strh r1, [r6, #4]
	mov r3, sb
	ldr r0, [r3]
	ldr r3, _0801D4A8 @ =0x000006E4
	adds r1, r0, r3
	mov r3, r8
	strh r3, [r1]
	ldrh r1, [r6, #4]
	ldr r3, _0801D4AC @ =0x000006E6
	adds r0, r0, r3
	strh r1, [r0]
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0xc7
	ble _0801D1F2
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D1F2:
	movs r0, #0
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp]
	lsls r2, r2, #0x10
	str r2, [sp, #4]
	ldr r7, _0801D4B0 @ =gOamBuffer
	mov ip, sb
_0801D202:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _0801D4B4 @ =0x000006D3
	adds r0, r0, r2
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r1, r1, #4
	ldrb r2, [r3, #5]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _0801D4B8 @ =0x000006DB
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #3
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	subs r0, #0x10
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0801D4C0 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D202
	mov r3, sb
	ldr r0, [r3]
	ldr r1, _0801D4C4 @ =0x000006C4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0801D298
	b _0801D3FA
_0801D298:
	ldr r2, _0801D4A4 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r6, [r0, #0x5c]
	mov r3, r8
	strh r3, [r6, #2]
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x20
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb3
	ble _0801D2B8
	movs r0, #0xb4
	strh r0, [r6, #4]
_0801D2B8:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	ldr r2, _0801D4C0 @ =0xFFFFFE00
	mov ip, r2
_0801D2C0:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrb r1, [r2, #5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0xc0
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D2C0
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x50]
	mov r0, r8
	strh r0, [r6, #2]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r2, _0801D4C8 @ =0x0000010B
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0801D33C
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D33C:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	ldr r3, _0801D4C0 @ =0xFFFFFE00
	mov ip, r3
_0801D344:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D344
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x54]
	mov r0, r8
	strh r0, [r6, #2]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r2, _0801D4CC @ =0x0000014D
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0801D3AE
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D3AE:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	ldr r3, _0801D4C0 @ =0xFFFFFE00
	mov r8, r3
_0801D3B6:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D3B6
_0801D3FA:
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x4c]
	ldr r1, [sp]
	asrs r0, r1, #0x10
	subs r0, #8
	strh r0, [r6, #2]
	ldr r2, [sp, #4]
	asrs r0, r2, #0x10
	subs r0, #8
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0801D41C
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D41C:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	movs r3, #3
	mov ip, r3
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sl, r1
	ldr r2, _0801D4C0 @ =0xFFFFFE00
	mov r8, r2
_0801D42E:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0801D4B8 @ =0x000006DB
	adds r0, r0, r2
	ldrb r1, [r0]
	mov r0, ip
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D42E
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D4A4: .4byte gMain
_0801D4A8: .4byte 0x000006E4
_0801D4AC: .4byte 0x000006E6
_0801D4B0: .4byte gOamBuffer
_0801D4B4: .4byte 0x000006D3
_0801D4B8: .4byte 0x000006DB
_0801D4BC: .4byte 0x000001FF
_0801D4C0: .4byte 0xFFFFFE00
_0801D4C4: .4byte 0x000006C4
_0801D4C8: .4byte 0x0000010B
_0801D4CC: .4byte 0x0000014D

	thumb_func_start sub_1D4D0
sub_1D4D0: @ 0x0801D4D0
	push {r4, r5, r6, r7, lr}
	ldr r0, _0801D5C8 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0801D5CC @ =0x000006C4
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r7, r0, #0
	cmp r1, #1
	bne _0801D5C2
	ldr r0, _0801D5D0 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r4, [r1, #0x58]
	movs r1, #0xb4
	strh r1, [r4, #4]
	movs r1, #0
	adds r6, r0, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D4F6:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D4F6
	ldr r0, [r6, #0x44]
	ldr r4, [r0, #0x5c]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb3
	ble _0801D53A
	movs r0, #0xb4
	strh r0, [r4, #4]
_0801D53A:
	movs r1, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D53E:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D53E
	ldr r0, [r6, #0x44]
	ldr r4, [r0, #0x50]
	movs r0, #0xb4
	strh r0, [r4, #4]
	movs r1, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D56E:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D56E
	ldr r0, [r6, #0x44]
	ldr r4, [r0, #0x54]
	movs r0, #0xb4
	strh r0, [r4, #4]
	movs r1, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D59E:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D59E
_0801D5C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D5C8: .4byte gCurrentPinballGame
_0801D5CC: .4byte 0x000006C4
_0801D5D0: .4byte gMain
_0801D5D4: .4byte gOamBuffer

	