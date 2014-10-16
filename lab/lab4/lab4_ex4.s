	.file	1 "lab4_ex4.c"
	.section .mdebug.eabi32
	.previous
	.section .gcc_compiled_long32
	.previous
	.gnu_attribute 4, 1
	.text
	.align	2
	.globl	main
	.set	nomips16
	.ent	main
	.type	main, @function
main:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	lui		$6,%hi(source)			# load upper 16 bits of source to $6
	lw		$3,%lo(source)($6)		# load 32 bits of source to $3
	beq		$3,$0,$L2 				# goto L2 if $3 == 0
	lui		$7,%hi(dest)
	addiu	$7,$7,%lo(dest)			# $7 = dest
	addiu	$6,$6,%lo(source)		# $6 = source
	move	$2,$0 					# $2 = 0
$L3:
	addu	$5,$7,$2 				# $5 = pointer to dest
	addu	$4,$6,$2 				# $4 = pointer to source
	sw		$3,0($5) 				# save $3 to 0($5)
	lw		$3,4($4)				# load 4($4) to $3
	addiu	$2,$2,4 				# $2 += 4
	bne		$3,$0,$L3 				# goto L3 if $3 != 0
$L2:
	move	$2,$0 					# $2 = 0
	j		$31 					# exit
	.end	main
	.size	main, .-main
	.globl	source
	.data
	.align	2
	.type	source, @object
	.size	source, 28
source:
	.word	3
	.word	1
	.word	4
	.word	1
	.word	5
	.word	9
	.word	0

	.comm	dest,40,4
	.ident	"GCC: (GNU) 4.4.1"
