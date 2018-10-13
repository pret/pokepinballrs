    .include "asm/macros.inc"
    .include "constants/gba_constants.inc"

    @ extern

    .syntax unified

    .text

    thumb_func_start sub_554F0
sub_554F0: @ 0x080554F0
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r3, r2, #0
    ldr r2, _08055528 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, _0805552C @ =0x0000FFFC
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    subs r3, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r3, r0
    beq _08055520
    adds r1, r0, #0
_08055512:
    ldrb r0, [r5]
    strb r0, [r4]
    adds r5, #1
    adds r4, #1
    subs r3, #1
    cmp r3, r1
    bne _08055512
_08055520:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
_08055528: .4byte 0x04000204
_0805552C: .4byte 0x0000FFFC

    thumb_func_start sub_55530
sub_55530: @ 0x08055530
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r3, r2, #0
    ldr r2, _08055568 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, _0805556C @ =0x0000FFFC
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    subs r3, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r3, r0
    beq _08055560
    adds r1, r0, #0
_08055552:
    ldrb r0, [r5]
    strb r0, [r4]
    adds r5, #1
    adds r4, #1
    subs r3, #1
    cmp r3, r1
    bne _08055552
_08055560:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
_08055568: .4byte 0x04000204
_0805556C: .4byte 0x0000FFFC

    thumb_func_start sub_55570
sub_55570: @ 0x08055570
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r3, r2, #0
    ldr r2, _080555A4 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, _080555A8 @ =0x0000FFFC
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    subs r3, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r3, r0
    beq _080555B2
    adds r2, r0, #0
_08055592:
    ldrb r1, [r4]
    ldrb r0, [r5]
    adds r5, #1
    adds r4, #1
    cmp r1, r0
    beq _080555AC
    subs r0, r4, #1
    b _080555B4
    .align 2, 0
_080555A4: .4byte 0x04000204
_080555A8: .4byte 0x0000FFFC
_080555AC:
    subs r3, #1
    cmp r3, r2
    bne _08055592
_080555B2:
    movs r0, #0
_080555B4:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_555BC
sub_555BC: @ 0x080555BC
    ldr r2, _080555D0 @ =0x080554F1
    movs r0, #1
    eors r2, r0
    ldr r3, _080555D4 @ =0x02002FD8
    ldr r0, _080555D8 @ =0x08055531
    ldr r1, _080555D0 @ =0x080554F1
    subs r0, r0, r1
    lsls r0, r0, #0xf
    b _080555E8
    .align 2, 0
_080555D0: .4byte 0x080554F1
_080555D4: .4byte 0x02002FD8
_080555D8: .4byte 0x08055531
_080555DC:
    ldrh r0, [r2]
    strh r0, [r3]
    adds r2, #2
    adds r3, #2
    subs r0, r1, #1
    lsls r0, r0, #0x10
_080555E8:
    lsrs r1, r0, #0x10
    cmp r1, #0
    bne _080555DC
    ldr r1, _08055608 @ =0x02032FF0
    ldr r0, _0805560C @ =0x02002FD9
    str r0, [r1]
    ldr r2, _08055610 @ =0x08055571
    movs r0, #1
    eors r2, r0
    ldr r3, _08055614 @ =0x02002F38
    ldr r0, _08055618 @ =0x080555BD
    ldr r1, _08055610 @ =0x08055571
    subs r0, r0, r1
    lsls r0, r0, #0xf
    b _08055628
    .align 2, 0
_08055608: .4byte 0x02032FF0
_0805560C: .4byte 0x02002FD9
_08055610: .4byte 0x08055571
_08055614: .4byte 0x02002F38
_08055618: .4byte 0x080555BD
_0805561C:
    ldrh r0, [r2]
    strh r0, [r3]
    adds r2, #2
    adds r3, #2
    subs r0, r1, #1
    lsls r0, r0, #0x10
_08055628:
    lsrs r1, r0, #0x10
    cmp r1, #0
    bne _0805561C
    ldr r1, _08055644 @ =0x02032FF4
    ldr r0, _08055648 @ =0x02002F39
    str r0, [r1]
    ldr r2, _0805564C @ =0x04000204
    ldrh r0, [r2]
    ldr r1, _08055650 @ =0x0000FFFC
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    bx lr
    .align 2, 0
_08055644: .4byte 0x02032FF4
_08055648: .4byte 0x02002F39
_0805564C: .4byte 0x04000204
_08055650: .4byte 0x0000FFFC

    thumb_func_start sub_55654
sub_55654: @ 0x08055654
    push {r4, r5, r6, r7, lr}
    adds r6, r0, #0
    adds r5, r1, #0
    adds r4, r2, #0
    movs r7, #0
    b _08055666
_08055660:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
_08055666:
    cmp r7, #2
    bhi _08055688
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl sub_55530
    ldr r0, _08055690 @ =0x02032FF4
    ldr r3, [r0]
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl _call_via_r3
    adds r3, r0, #0
    cmp r3, #0
    bne _08055660
_08055688:
    adds r0, r3, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
_08055690: .4byte 0x02032FF4

    .align 2, 0 @ Don't pad with nop.
