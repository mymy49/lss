	.thumb_func
	.syntax unified
    .func SVC_Handler
   	.type SVC_Handler, %function
	.global SVC_Handler
	.section .text, "ax"
SVC_Handler:
	push {lr}
	ldr r2, systickCtrl
	ldr r1, [r2]
	bic r1, r1, #3
	str r1, [r2]
	mrs r2, psp
	ldr r1, [r2]
	add r2, r2, #4
	ldr r0, [r2]
	blx r1
	ldr r2, systickCtrl
	ldr r1, [r2]
	orr r1, r1, #3
	str r1, [r2]
	pop {pc}

systickCtrl:
	.word 0xe000e010
