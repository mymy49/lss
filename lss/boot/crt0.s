	.global _start
	.extern APP_ENTRY_POINT
	.global exit

	.section .init, "ax"
	.code 16
	.align 2
	.thumb_func

_start:
	ldr r1, =__stack_end__
	mov r2, #0x7
	bic r1, r2
	mov sp, r1

	/* Set up process stack if size > 0 */
	ldr r1, =__stack_process_end__
	mov r2, #0x7
	bic r1, r2
	msr psp, r1
	mov r2, #2
	msr control, r2
1:

  /* Copy initialised memory sections into RAM (if necessary). */
  ldr r0, =__data_load_start__
  ldr r1, =__data_start__
  ldr r2, =__data_end__
  bl memory_copy
  ldr r0, =__text_load_start__
  ldr r1, =__text_start__
  ldr r2, =__text_end__
  bl memory_copy
  ldr r0, =__fast_load_start__
  ldr r1, =__fast_start__
  ldr r2, =__fast_end__
  bl memory_copy
  ldr r0, =__ctors_load_start__
  ldr r1, =__ctors_start__
  ldr r2, =__ctors_end__
  bl memory_copy
  ldr r0, =__dtors_load_start__
  ldr r1, =__dtors_start__
  ldr r2, =__dtors_end__
  bl memory_copy
  ldr r0, =__rodata_load_start__
  ldr r1, =__rodata_start__
  ldr r2, =__rodata_end__
  bl memory_copy

  /* Zero the bss. */
  ldr r0, =__bss_start__
  ldr r1, =__bss_end__
  mov r2, #0
  bl memory_set

  /* Call constructors */
  ldr r0, =__ctors_start__
  ldr r1, =__ctors_end__
ctor_loop:
  cmp r0, r1
  beq ctor_end
  ldr r2, [r0]
  add r0, #4
  push {r0-r1}  
  blx r2
  pop {r0-r1}
  b ctor_loop
ctor_end:

  /* Setup initial call frame */
  mov r0, #0
  mov lr, r0
  mov r12, sp

  .type start, function
start:
  /* Jump to application entry point */
  mov r0, #0
  mov r1, #0
  bl initLss
  bl main

  /* Returned from application entry point, loop forever. */
exit_loop:
  b exit_loop

  .thumb_func
memory_copy:
  cmp r0, r1
  beq 2f
  sub r2, r2, r1
  beq 2f
1:
  ldrb r3, [r0]
  add r0, r0, #1
  strb r3, [r1]
  add r1, r1, #1
  sub r2, r2, #1
  bne 1b
2:
  bx lr

  .thumb_func
memory_set:
  cmp r0, r1
  beq 1f
  strb r2, [r0]
  add r0, r0, #1
  b memory_set
1:
  bx lr

  .global __getchar
  .weak __getchar
  .global __putchar
  .weak __putchar
  .thumb_func
__getchar:
  .thumb_func
__putchar:
  ldr r0, =-1 // EOF
  bx lr

  /* Setup attibutes of stack and heap sections so they don't take up room in the elf file */
  .section .stack, "wa", %nobits
  .section .stack_process, "wa", %nobits
  .section .heap, "wa", %nobits

