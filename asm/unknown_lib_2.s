    .include "asm/macros.inc"

    .syntax unified

    .text

    thumb_func_start sub_55A24
sub_55A24: @ 0x08055A24
    push {r4, r5, lr}
    adds r1, r0, #0
    adds r5, r1, #0
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne _08055A5C
    adds r2, r1, #0
    ldr r1, [r2]
    ldr r4, _08055A40 @ =0xFEFEFEFF
    adds r0, r1, r4
    bics r0, r1
    ldr r3, _08055A44 @ =0x80808080
    b _08055A50
    .align 2, 0
_08055A40: .4byte 0xFEFEFEFF
_08055A44: .4byte 0x80808080
_08055A48:
    adds r2, #4
    ldr r1, [r2]
    adds r0, r1, r4
    bics r0, r1
_08055A50:
    ands r0, r3
    cmp r0, #0
    beq _08055A48
    adds r1, r2, #0
    b _08055A5C
_08055A5A:
    adds r1, #1
_08055A5C:
    ldrb r0, [r1]
    cmp r0, #0
    bne _08055A5A
    subs r0, r1, r5
    pop {r4, r5, pc}

    .align 2, 0 @ Don't pad with nop.
