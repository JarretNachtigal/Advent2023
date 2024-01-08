	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48                     ; =48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32                    ; =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	adrp	x8, l___const.main.arr@PAGE
	ldrb	w8, [x8, l___const.main.arr@PAGEOFF]
	sturb	w8, [x29, #-5]
	stur	wzr, [x29, #-12]
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldursw	x8, [x29, #-12]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	sub	x0, x29, #5                     ; =5
	bl	_strlen
	ldr	x8, [sp, #8]                    ; 8-byte Folded Reload
	subs	x8, x8, x0
	b.hi	LBB0_4
; %bb.2:                                ;   in Loop: Header=BB0_1 Depth=1
; %bb.3:                                ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-12]
	add	w8, w8, #1                      ; =1
	stur	w8, [x29, #-12]
	b	LBB0_1
LBB0_4:
	sub	x0, x29, #5                     ; =5
	bl	_strlen
	mov	x8, x0
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	mov	x9, sp
	str	x8, [x9]
	bl	_printf
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48                     ; =48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__const
l___const.main.arr:                     ; @__const.main.arr
	.byte	65

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%lu\n"

.subsections_via_symbols
