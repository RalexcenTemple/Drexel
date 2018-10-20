	.file	1 "project2bctest.c"
	.sdata
	.align	2
$LC0:
	.ascii	"error\n\000"
	.text
	.align	2
	.globl	main
	.ent	main
main:
	.frame	$fp,112,$31		# vars= 8, regs= 10/6, args= 16, extra= 0
	.mask	0xc0ff0000,-52
	.fmask	0xfff00000,-8
	subu	$sp,$sp,112
	sw	$31,60($sp)
	sw	$fp,56($sp)
	sw	$23,52($sp)
	sw	$22,48($sp)
	sw	$21,44($sp)
	sw	$20,40($sp)
	sw	$19,36($sp)
	sw	$18,32($sp)
	sw	$17,28($sp)
	sw	$16,24($sp)
	s.d	$f30,104($sp)
	s.d	$f28,96($sp)
	s.d	$f26,88($sp)
	s.d	$f24,80($sp)
	s.d	$f22,72($sp)
	s.d	$f20,64($sp)
	move	$fp,$sp
	jal	__main
	lw	$4,16($fp)
	jal	setjmp
	sw	$2,16($fp)
	lw	$2,16($fp)
	bne	$2,$0,$L2
	jal	fun1
	sw	$0,20($fp)
	j	$L1
$L2:
	la	$4,$LC0
	jal	print_str
	li	$2,2			# 0x2
	sw	$2,20($fp)
$L1:
	lw	$2,20($fp)
	move	$sp,$fp
	lw	$31,60($sp)
	lw	$fp,56($sp)
	lw	$23,52($sp)
	lw	$22,48($sp)
	lw	$21,44($sp)
	lw	$20,40($sp)
	lw	$19,36($sp)
	lw	$18,32($sp)
	lw	$17,28($sp)
	lw	$16,24($sp)
	l.d	$f30,104($sp)
	l.d	$f28,96($sp)
	l.d	$f26,88($sp)
	l.d	$f24,80($sp)
	l.d	$f22,72($sp)
	l.d	$f20,64($sp)
	addu	$sp,$sp,112
	j	$31
	.end	main
	.align	2
	.globl	__main
	.ent	__main
__main:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,8
	sw	$fp,0($sp)
	move	$fp,$sp
	move	$2,$0
	move	$sp,$fp
	lw	$fp,0($sp)
	addu	$sp,$sp,8
	j	$31
	.end	__main
	.align	2
	.globl	dummy
	.ent	dummy
dummy:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,8
	sw	$fp,0($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$fp,0($sp)
	addu	$sp,$sp,8
	j	$31
	.end	dummy
	.align	2
	.globl	setjmp
	.ent	setjmp
setjmp:
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	addu	$2,$fp,32
	sw	$2,16($fp)
	lw	$2,16($fp)
	addu	$2,$2,-4
	sw	$2,RA
	lw	$2,16($fp)
	addu	$2,$2,-8
	sw	$2,FP
	lw	$4,32($fp)
	jal	dummy
	move	$2,$0
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addu	$sp,$sp,32
	j	$31
	.end	setjmp
	.align	2
	.globl	longjmp
	.ent	longjmp
longjmp:
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	addu	$2,$fp,32
	sw	$2,16($fp)
	lw	$2,16($fp)
	addu	$3,$2,-4
	lw	$2,RA
	addu	$2,$2,-24
	lw	$2,0($2)
	sw	$2,0($3)
	lw	$2,16($fp)
	addu	$3,$2,-8
	lw	$2,FP
	lw	$2,0($2)
	sw	$2,0($3)
	lw	$4,32($fp)
	jal	dummy
	li	$2,1			# 0x1
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addu	$sp,$sp,32
	j	$31
	.end	longjmp
	.rdata
	.align	2
$LC1:
	.ascii	"start fun1\n\000"
	.text
	.align	2
	.globl	fun1
	.ent	fun1
fun1:
	.frame	$fp,24,$31		# vars= 0, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,24
	sw	$31,20($sp)
	sw	$fp,16($sp)
	move	$fp,$sp
	la	$4,$LC1
	jal	print_str
	jal	fun2
	move	$2,$0
	move	$sp,$fp
	lw	$31,20($sp)
	lw	$fp,16($sp)
	addu	$sp,$sp,24
	j	$31
	.end	fun1
	.rdata
	.align	2
$LC2:
	.ascii	"start fun2\n\000"
	.text
	.align	2
	.globl	fun2
	.ent	fun2
fun2:
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	la	$4,$LC2
	jal	print_str
	lw	$4,16($fp)
	jal	longjmp
	.end	fun2
	.align	2
	.globl	print_str
	.ent	print_str
print_str:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, extra= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,16
	sw	$fp,8($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	li	$2,4			# 0x4
	sw	$2,0($fp)
	lw	$3,0($fp)
	lw	$2,16($fp)
 #APP
	add $a0,$2,$zero
	add $v0,$3,$zero
	syscall
 #NO_APP
	move	$2,$0
	move	$sp,$fp
	lw	$fp,8($sp)
	addu	$sp,$sp,16
	j	$31
	.end	print_str

	.lcomm	RA,4

	.lcomm	FP,4
