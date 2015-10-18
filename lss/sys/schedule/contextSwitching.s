	.thumb_func
	.syntax unified
    .func SysTick_Handler
   	.type SysTick_Handler, %function
	.global SysTick_Handler
	.section .text, "ax"
SysTick_Handler:
	push {lr}
	mrs r0, psp
	stmdb   R0!, {R4-R11}
	sub R0, R0, #64
	vstm R0,{S16-S31}
	bl getNextContext
	vldm R0,{S16-S31}
	add R0, R0, #64
	ldmia   r0!, {r4-r11}
	msr psp, r0
	pop {pc}
	nop

	.global getNextContext
