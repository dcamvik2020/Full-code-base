	.file	"Complex0.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.section	.text._ZStanSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStanSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStanSt13_Ios_FmtflagsS_
	.type	_ZStanSt13_Ios_FmtflagsS_, @function
_ZStanSt13_Ios_FmtflagsS_:
.LFB1087:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	andl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1087:
	.size	_ZStanSt13_Ios_FmtflagsS_, .-_ZStanSt13_Ios_FmtflagsS_
	.section	.text._ZStorSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStorSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStorSt13_Ios_FmtflagsS_
	.type	_ZStorSt13_Ios_FmtflagsS_, @function
_ZStorSt13_Ios_FmtflagsS_:
.LFB1088:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	orl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1088:
	.size	_ZStorSt13_Ios_FmtflagsS_, .-_ZStorSt13_Ios_FmtflagsS_
	.section	.text._ZStcoSt13_Ios_Fmtflags,"axG",@progbits,_ZStcoSt13_Ios_Fmtflags,comdat
	.weak	_ZStcoSt13_Ios_Fmtflags
	.type	_ZStcoSt13_Ios_Fmtflags, @function
_ZStcoSt13_Ios_Fmtflags:
.LFB1090:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	notl	%eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1090:
	.size	_ZStcoSt13_Ios_Fmtflags, .-_ZStcoSt13_Ios_Fmtflags
	.section	.text._ZStoRRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStoRRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStoRRSt13_Ios_FmtflagsS_
	.type	_ZStoRRSt13_Ios_FmtflagsS_, @function
_ZStoRRSt13_Ios_FmtflagsS_:
.LFB1091:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStorSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1091:
	.size	_ZStoRRSt13_Ios_FmtflagsS_, .-_ZStoRRSt13_Ios_FmtflagsS_
	.section	.text._ZStaNRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStaNRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStaNRSt13_Ios_FmtflagsS_
	.type	_ZStaNRSt13_Ios_FmtflagsS_, @function
_ZStaNRSt13_Ios_FmtflagsS_:
.LFB1092:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStanSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1092:
	.size	_ZStaNRSt13_Ios_FmtflagsS_, .-_ZStaNRSt13_Ios_FmtflagsS_
	.section	.text._ZNSt8ios_base4setfESt13_Ios_Fmtflags,"axG",@progbits,_ZNSt8ios_base4setfESt13_Ios_Fmtflags,comdat
	.align 2
	.weak	_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	.type	_ZNSt8ios_base4setfESt13_Ios_Fmtflags, @function
_ZNSt8ios_base4setfESt13_Ios_Fmtflags:
.LFB1120:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movl	24(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	leaq	24(%rax), %rdx
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZStoRRSt13_Ios_FmtflagsS_
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1120:
	.size	_ZNSt8ios_base4setfESt13_Ios_Fmtflags, .-_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	.section	.text._ZNSt8ios_base6unsetfESt13_Ios_Fmtflags,"axG",@progbits,_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags,comdat
	.align 2
	.weak	_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags
	.type	_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags, @function
_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags:
.LFB1122:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	_ZStcoSt13_Ios_Fmtflags
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	addq	$24, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStaNRSt13_Ios_FmtflagsS_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1122:
	.size	_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags, .-_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags
	.section	.text._ZSt7showposRSt8ios_base,"axG",@progbits,_ZSt7showposRSt8ios_base,comdat
	.weak	_ZSt7showposRSt8ios_base
	.type	_ZSt7showposRSt8ios_base, @function
_ZSt7showposRSt8ios_base:
.LFB1137:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$2048, %esi
	movq	%rax, %rdi
	call	_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1137:
	.size	_ZSt7showposRSt8ios_base, .-_ZSt7showposRSt8ios_base
	.section	.text._ZSt9noshowposRSt8ios_base,"axG",@progbits,_ZSt9noshowposRSt8ios_base,comdat
	.weak	_ZSt9noshowposRSt8ios_base
	.type	_ZSt9noshowposRSt8ios_base, @function
_ZSt9noshowposRSt8ios_base:
.LFB1138:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$2048, %esi
	movq	%rax, %rdi
	call	_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1138:
	.size	_ZSt9noshowposRSt8ios_base, .-_ZSt9noshowposRSt8ios_base
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZNSt7complexIdEC2Edd,"axG",@progbits,_ZNSt7complexIdEC5Edd,comdat
	.align 2
	.weak	_ZNSt7complexIdEC2Edd
	.type	_ZNSt7complexIdEC2Edd, @function
_ZNSt7complexIdEC2Edd:
.LFB1910:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	-16(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm1, (%rax)
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1910:
	.size	_ZNSt7complexIdEC2Edd, .-_ZNSt7complexIdEC2Edd
	.weak	_ZNSt7complexIdEC1Edd
	.set	_ZNSt7complexIdEC1Edd,_ZNSt7complexIdEC2Edd
	.section	.text._ZNKSt7complexIdE4realB5cxx11Ev,"axG",@progbits,_ZNKSt7complexIdE4realB5cxx11Ev,comdat
	.align 2
	.weak	_ZNKSt7complexIdE4realB5cxx11Ev
	.type	_ZNKSt7complexIdE4realB5cxx11Ev, @function
_ZNKSt7complexIdE4realB5cxx11Ev:
.LFB1915:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1915:
	.size	_ZNKSt7complexIdE4realB5cxx11Ev, .-_ZNKSt7complexIdE4realB5cxx11Ev
	.section	.text._ZNKSt7complexIdE4imagB5cxx11Ev,"axG",@progbits,_ZNKSt7complexIdE4imagB5cxx11Ev,comdat
	.align 2
	.weak	_ZNKSt7complexIdE4imagB5cxx11Ev
	.type	_ZNKSt7complexIdE4imagB5cxx11Ev, @function
_ZNKSt7complexIdE4imagB5cxx11Ev:
.LFB1916:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1916:
	.size	_ZNKSt7complexIdE4imagB5cxx11Ev, .-_ZNKSt7complexIdE4imagB5cxx11Ev
	.section	.text._ZNSt7complexIdEaSEd,"axG",@progbits,_ZNSt7complexIdEaSEd,comdat
	.align 2
	.weak	_ZNSt7complexIdEaSEd
	.type	_ZNSt7complexIdEaSEd, @function
_ZNSt7complexIdEaSEd:
.LFB1919:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm1
	pxor	%xmm0, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm1, (%rax)
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1919:
	.size	_ZNSt7complexIdEaSEd, .-_ZNSt7complexIdEaSEd
	.section	.text._ZNSt7complexIdEpLEd,"axG",@progbits,_ZNSt7complexIdEpLEd,comdat
	.align 2
	.weak	_ZNSt7complexIdEpLEd
	.type	_ZNSt7complexIdEpLEd, @function
_ZNSt7complexIdEpLEd:
.LFB1920:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	8(%rax), %xmm1
	addsd	-16(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm1, (%rax)
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1920:
	.size	_ZNSt7complexIdEpLEd, .-_ZNSt7complexIdEpLEd
	.section	.text._ZNSt7complexIdEmIEd,"axG",@progbits,_ZNSt7complexIdEmIEd,comdat
	.align 2
	.weak	_ZNSt7complexIdEmIEd
	.type	_ZNSt7complexIdEmIEd, @function
_ZNSt7complexIdEmIEd:
.LFB1921:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	8(%rax), %xmm1
	subsd	-16(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm1, (%rax)
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1921:
	.size	_ZNSt7complexIdEmIEd, .-_ZNSt7complexIdEmIEd
	.section	.text._ZNSt7complexIdEmLEd,"axG",@progbits,_ZNSt7complexIdEmLEd,comdat
	.align 2
	.weak	_ZNSt7complexIdEmLEd
	.type	_ZNSt7complexIdEmLEd, @function
_ZNSt7complexIdEmLEd:
.LFB1922:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	8(%rax), %xmm2
	movapd	%xmm0, %xmm1
	movsd	-16(%rbp), %xmm0
	mulsd	%xmm0, %xmm1
	mulsd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm1, (%rax)
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1922:
	.size	_ZNSt7complexIdEmLEd, .-_ZNSt7complexIdEmLEd
	.section	.text._ZNSt7complexIdEdVEd,"axG",@progbits,_ZNSt7complexIdEdVEd,comdat
	.align 2
	.weak	_ZNSt7complexIdEdVEd
	.type	_ZNSt7complexIdEdVEd, @function
_ZNSt7complexIdEdVEd:
.LFB1923:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	8(%rax), %xmm2
	movapd	%xmm0, %xmm1
	movsd	-16(%rbp), %xmm0
	divsd	%xmm0, %xmm1
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm1, (%rax)
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1923:
	.size	_ZNSt7complexIdEdVEd, .-_ZNSt7complexIdEdVEd
	.section	.text._ZN7ComplexC2Edd,"axG",@progbits,_ZN7ComplexC5Edd,comdat
	.align 2
	.weak	_ZN7ComplexC2Edd
	.type	_ZN7ComplexC2Edd, @function
_ZN7ComplexC2Edd:
.LFB2018:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movq	-8(%rbp), %rax
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movq	-8(%rbp), %rax
	movsd	-24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2018:
	.size	_ZN7ComplexC2Edd, .-_ZN7ComplexC2Edd
	.weak	_ZN7ComplexC1Edd
	.set	_ZN7ComplexC1Edd,_ZN7ComplexC2Edd
	.section	.text._ZN7ComplexaSERKS_,"axG",@progbits,_ZN7ComplexaSERKS_,comdat
	.align 2
	.weak	_ZN7ComplexaSERKS_
	.type	_ZN7ComplexaSERKS_, @function
_ZN7ComplexaSERKS_:
.LFB2020:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movsd	(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, (%rax)
	movq	-16(%rbp), %rax
	movsd	8(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movdqa	-32(%rbp), %xmm0
	movq	%rdx, -32(%rbp)
	movsd	-32(%rbp), %xmm1
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2020:
	.size	_ZN7ComplexaSERKS_, .-_ZN7ComplexaSERKS_
	.section	.text._ZNK7Complex2ReEv,"axG",@progbits,_ZNK7Complex2ReEv,comdat
	.align 2
	.weak	_ZNK7Complex2ReEv
	.type	_ZNK7Complex2ReEv, @function
_ZNK7Complex2ReEv:
.LFB2021:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2021:
	.size	_ZNK7Complex2ReEv, .-_ZNK7Complex2ReEv
	.section	.text._ZNK7Complex2ImEv,"axG",@progbits,_ZNK7Complex2ImEv,comdat
	.align 2
	.weak	_ZNK7Complex2ImEv
	.type	_ZNK7Complex2ImEv, @function
_ZNK7Complex2ImEv:
.LFB2022:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2022:
	.size	_ZNK7Complex2ImEv, .-_ZNK7Complex2ImEv
	.text
	.globl	_ZplRK7ComplexS1_
	.type	_ZplRK7ComplexS1_, @function
_ZplRK7ComplexS1_:
.LFB2023:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -64(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movapd	%xmm0, %xmm2
	addsd	-64(%rbp), %xmm2
	movsd	%xmm2, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -72(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	addsd	-72(%rbp), %xmm0
	leaq	-32(%rbp), %rax
	movsd	-64(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L42
	call	__stack_chk_fail@PLT
.L42:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2023:
	.size	_ZplRK7ComplexS1_, .-_ZplRK7ComplexS1_
	.globl	_ZpsRK7Complex
	.type	_ZpsRK7Complex, @function
_ZpsRK7Complex:
.LFB2024:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movdqa	-32(%rbp), %xmm0
	movq	%rdx, -32(%rbp)
	movsd	-32(%rbp), %xmm1
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2024:
	.size	_ZpsRK7Complex, .-_ZpsRK7Complex
	.globl	_ZngRK7Complex
	.type	_ZngRK7Complex, @function
_ZngRK7Complex:
.LFB2025:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movapd	%xmm0, %xmm1
	movq	.LC1(%rip), %xmm0
	xorpd	%xmm0, %xmm1
	movsd	%xmm1, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movapd	%xmm0, %xmm1
	movq	.LC1(%rip), %xmm0
	xorpd	%xmm1, %xmm0
	leaq	-32(%rbp), %rax
	movsd	-64(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L47
	call	__stack_chk_fail@PLT
.L47:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2025:
	.size	_ZngRK7Complex, .-_ZngRK7Complex
	.globl	_ZmiRK7ComplexS1_
	.type	_ZmiRK7ComplexS1_, @function
_ZmiRK7ComplexS1_:
.LFB2026:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -64(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	-64(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movsd	%xmm2, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -72(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	-72(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	leaq	-32(%rbp), %rax
	movsd	-64(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L50
	call	__stack_chk_fail@PLT
.L50:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2026:
	.size	_ZmiRK7ComplexS1_, .-_ZmiRK7ComplexS1_
	.globl	_ZmlRK7Complexd
	.type	_ZmlRK7Complexd, @function
_ZmlRK7Complexd:
.LFB2027:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movsd	%xmm0, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	mulsd	-48(%rbp), %xmm0
	movsd	%xmm0, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	mulsd	-48(%rbp), %xmm0
	leaq	-32(%rbp), %rax
	movsd	-64(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L53
	call	__stack_chk_fail@PLT
.L53:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2027:
	.size	_ZmlRK7Complexd, .-_ZmlRK7Complexd
	.globl	_ZmlRK7ComplexS1_
	.type	_ZmlRK7ComplexS1_, @function
_ZmlRK7ComplexS1_:
.LFB2028:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -64(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movapd	%xmm0, %xmm3
	mulsd	-64(%rbp), %xmm3
	movsd	%xmm3, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -72(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	mulsd	-72(%rbp), %xmm0
	addsd	-64(%rbp), %xmm0
	movsd	%xmm0, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -72(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movapd	%xmm0, %xmm2
	mulsd	-72(%rbp), %xmm2
	movsd	%xmm2, -72(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -80(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	mulsd	-80(%rbp), %xmm0
	movsd	-72(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	leaq	-32(%rbp), %rax
	movsd	-64(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L56
	call	__stack_chk_fail@PLT
.L56:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2028:
	.size	_ZmlRK7ComplexS1_, .-_ZmlRK7ComplexS1_
	.globl	_ZdvRK7Complexd
	.type	_ZdvRK7Complexd, @function
_ZdvRK7Complexd:
.LFB2029:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movsd	%xmm0, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	pxor	%xmm0, %xmm0
	ucomisd	-48(%rbp), %xmm0
	jp	.L62
	pxor	%xmm0, %xmm0
	ucomisd	-48(%rbp), %xmm0
	je	.L63
.L62:
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	divsd	-48(%rbp), %xmm0
	movsd	%xmm0, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	divsd	-48(%rbp), %xmm0
	leaq	-32(%rbp), %rax
	movsd	-64(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	jmp	.L60
.L63:
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
.L60:
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L61
	call	__stack_chk_fail@PLT
.L61:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2029:
	.size	_ZdvRK7Complexd, .-_ZdvRK7Complexd
	.globl	_ZdvRK7ComplexS1_
	.type	_ZdvRK7ComplexS1_, @function
_ZdvRK7ComplexS1_:
.LFB2030:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jp	.L65
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.L65
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jp	.L65
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	je	.L72
.L65:
	movl	$1, %eax
	jmp	.L68
.L72:
	movl	$0, %eax
.L68:
	testb	%al, %al
	je	.L69
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -80(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movapd	%xmm0, %xmm2
	mulsd	-80(%rbp), %xmm2
	movsd	%xmm2, -80(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -88(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	mulsd	-88(%rbp), %xmm0
	addsd	-80(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movapd	%xmm0, %xmm1
	movq	.LC1(%rip), %xmm0
	xorpd	%xmm0, %xmm1
	movsd	%xmm1, -88(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	leaq	-48(%rbp), %rax
	movsd	-88(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-48(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmlRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -32(%rbp)
	movsd	%xmm0, -24(%rbp)
	leaq	-32(%rbp), %rax
	movsd	-80(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZdvRK7Complexd
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	jmp	.L70
.L69:
	movq	-56(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
.L70:
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movdqa	-80(%rbp), %xmm0
	movq	%rdx, -80(%rbp)
	movsd	-80(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L71
	call	__stack_chk_fail@PLT
.L71:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2030:
	.size	_ZdvRK7ComplexS1_, .-_ZdvRK7ComplexS1_
	.globl	_ZpLR7ComplexRKS_
	.type	_ZpLR7ComplexRKS_, @function
_ZpLR7ComplexRKS_:
.LFB2031:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZplRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -32(%rbp)
	movsd	%xmm0, -24(%rbp)
	leaq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L75
	call	__stack_chk_fail@PLT
.L75:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2031:
	.size	_ZpLR7ComplexRKS_, .-_ZpLR7ComplexRKS_
	.globl	_ZmIR7ComplexRKS_
	.type	_ZmIR7ComplexRKS_, @function
_ZmIR7ComplexRKS_:
.LFB2032:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmiRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -32(%rbp)
	movsd	%xmm0, -24(%rbp)
	leaq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L78
	call	__stack_chk_fail@PLT
.L78:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2032:
	.size	_ZmIR7ComplexRKS_, .-_ZmIR7ComplexRKS_
	.globl	_ZmLR7ComplexRKS_
	.type	_ZmLR7ComplexRKS_, @function
_ZmLR7ComplexRKS_:
.LFB2033:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmlRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -32(%rbp)
	movsd	%xmm0, -24(%rbp)
	leaq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L81
	call	__stack_chk_fail@PLT
.L81:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2033:
	.size	_ZmLR7ComplexRKS_, .-_ZmLR7ComplexRKS_
	.globl	_ZdVR7ComplexRKS_
	.type	_ZdVR7ComplexRKS_, @function
_ZdVR7ComplexRKS_:
.LFB2034:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZdvRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -32(%rbp)
	movsd	%xmm0, -24(%rbp)
	leaq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movdqa	-64(%rbp), %xmm0
	movq	%rdx, -64(%rbp)
	movsd	-64(%rbp), %xmm1
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L84
	call	__stack_chk_fail@PLT
.L84:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2034:
	.size	_ZdVR7ComplexRKS_, .-_ZdVR7ComplexRKS_
	.globl	_ZrsRSiR7Complex
	.type	_ZrsRSiR7Complex, @function
_ZrsRSiR7Complex:
.LFB2035:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -48(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERd@PLT
	movq	(%rax), %rdx
	subq	$24, %rdx
	movq	(%rdx), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv@PLT
	testb	%al, %al
	je	.L86
	leaq	-40(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERd@PLT
	movq	(%rax), %rdx
	subq	$24, %rdx
	movq	(%rdx), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv@PLT
	testb	%al, %al
	je	.L86
	leaq	-49(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_@PLT
	movq	(%rax), %rdx
	subq	$24, %rdx
	movq	(%rdx), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv@PLT
	xorl	$1, %eax
	testb	%al, %al
	jne	.L87
	movzbl	-49(%rbp), %eax
	cmpb	$105, %al
	je	.L88
.L87:
	movl	$1, %eax
	jmp	.L89
.L88:
	movl	$0, %eax
.L89:
	testb	%al, %al
	je	.L86
	movq	-72(%rbp), %rax
	movq	(%rax), %rax
	subq	$24, %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE8setstateESt12_Ios_Iostate@PLT
.L86:
	movsd	-40(%rbp), %xmm0
	movq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-32(%rbp), %rdx
	movq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-72(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L91
	call	__stack_chk_fail@PLT
.L91:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2035:
	.size	_ZrsRSiR7Complex, .-_ZrsRSiR7Complex
	.section	.rodata
.LC2:
	.string	"i"
	.text
	.globl	_ZlsRSoRK7Complex
	.type	_ZlsRSoRK7Complex, @function
_ZlsRSoRK7Complex:
.LFB2036:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSolsEd@PLT
	leaq	_ZSt7showposRSt8ios_base(%rip), %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movq	%rbx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	_ZSt9noshowposRSt8ios_base(%rip), %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	-24(%rbp), %rax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2036:
	.size	_ZlsRSoRK7Complex, .-_ZlsRSoRK7Complex
	.section	.rodata
.LC4:
	.string	" + "
.LC5:
	.string	" = "
.LC8:
	.string	"PASSED"
.LC9:
	.string	"!!! FAILED !!!"
.LC10:
	.string	" - "
.LC11:
	.string	" * "
.LC12:
	.string	" += "
.LC13:
	.string	" -= "
.LC14:
	.string	" *= "
.LC15:
	.string	" /= "
.LC16:
	.string	" = +("
.LC17:
	.string	")"
.LC18:
	.string	" = -("
	.align 8
.LC3:
	.long	0
	.long	0
	.long	0
	.long	0
	.text
	.globl	main
	.type	main, @function
main:
.LFB2037:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$232, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-192(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-176(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-160(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-144(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-192(%rbp), %rax
	movq	%rax, -208(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-192(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZrsRSiR7Complex
	movq	%rax, %rdx
	leaq	-176(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZrsRSiR7Complex
	movq	%rax, %rdx
	leaq	-216(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSirsERd@PLT
	leaq	-192(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-192(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	leaq	-128(%rbp), %rax
	movsd	-232(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZNSt7complexIdEC1Edd
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	leaq	-112(%rbp), %rax
	movsd	-232(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZNSt7complexIdEC1Edd
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8+.LC3(%rip), %xmm0
	movsd	%xmm0, -88(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	8+.LC3(%rip), %xmm0
	movsd	%xmm0, -72(%rbp)
	movq	-200(%rbp), %rdx
	movq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZplRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStplIdESt7complexIT_ERKS2_S4_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L95
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L95
	leaq	.LC8(%rip), %rax
	jmp	.L98
.L95:
	leaq	.LC9(%rip), %rax
.L98:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-64(%rbp), %rdx
	movq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZplRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-216(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStplIdESt7complexIT_ERKS2_RKS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movapd	%xmm4, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L99
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm5
	subsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L99
	leaq	.LC8(%rip), %rax
	jmp	.L102
.L99:
	leaq	.LC9(%rip), %rax
.L102:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-200(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZplRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-216(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStplIdESt7complexIT_ERKS1_RKS2_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm6
	subsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L103
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm7
	subsd	%xmm0, %xmm7
	movapd	%xmm7, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L103
	leaq	.LC8(%rip), %rax
	jmp	.L106
.L103:
	leaq	.LC9(%rip), %rax
.L106:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-200(%rbp), %rdx
	movq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmiRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStmiIdESt7complexIT_ERKS2_S4_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L107
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L107
	leaq	.LC8(%rip), %rax
	jmp	.L110
.L107:
	leaq	.LC9(%rip), %rax
.L110:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-64(%rbp), %rdx
	movq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmiRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-216(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStmiIdESt7complexIT_ERKS2_RKS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movapd	%xmm4, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L111
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm5
	subsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L111
	leaq	.LC8(%rip), %rax
	jmp	.L114
.L111:
	leaq	.LC9(%rip), %rax
.L114:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-200(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmiRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-216(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStmiIdESt7complexIT_ERKS1_RKS2_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm6
	subsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L115
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm7
	subsd	%xmm0, %xmm7
	movapd	%xmm7, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L115
	leaq	.LC8(%rip), %rax
	jmp	.L118
.L115:
	leaq	.LC9(%rip), %rax
.L118:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-200(%rbp), %rdx
	movq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmlRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStmlIdESt7complexIT_ERKS2_S4_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L119
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L119
	leaq	.LC8(%rip), %rax
	jmp	.L122
.L119:
	leaq	.LC9(%rip), %rax
.L122:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	movq	-208(%rbp), %rax
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZmlRK7Complexd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-216(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStmlIdESt7complexIT_ERKS2_RKS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movapd	%xmm4, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L123
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm5
	subsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L123
	leaq	.LC8(%rip), %rax
	jmp	.L126
.L123:
	leaq	.LC9(%rip), %rax
.L126:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	movq	-200(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmlRK7ComplexS1_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-216(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStmlIdESt7complexIT_ERKS1_RKS2_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC11(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm6
	subsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L127
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm7
	subsd	%xmm0, %xmm7
	movapd	%xmm7, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L127
	leaq	.LC8(%rip), %rax
	jmp	.L130
.L127:
	leaq	.LC9(%rip), %rax
.L130:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-200(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-112(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-104(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L131
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L131
	leaq	.LC8(%rip), %rax
	jmp	.L134
.L131:
	leaq	.LC9(%rip), %rax
.L134:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-64(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEaSEd
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movapd	%xmm4, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L135
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm5
	subsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L135
	leaq	.LC8(%rip), %rax
	jmp	.L138
.L135:
	leaq	.LC9(%rip), %rax
.L138:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-200(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZpLR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7complexIdEpLIdEERS0_RKS_IT_E
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm6
	subsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L139
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm7
	subsd	%xmm0, %xmm7
	movapd	%xmm7, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L139
	leaq	.LC8(%rip), %rax
	jmp	.L142
.L139:
	leaq	.LC9(%rip), %rax
.L142:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-64(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZpLR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEpLEd
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC12(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L143
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L143
	leaq	.LC8(%rip), %rax
	jmp	.L146
.L143:
	leaq	.LC9(%rip), %rax
.L146:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-200(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmIR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmIIdEERS0_RKS_IT_E
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movapd	%xmm4, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L147
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm5
	subsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L147
	leaq	.LC8(%rip), %rax
	jmp	.L150
.L147:
	leaq	.LC9(%rip), %rax
.L150:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-64(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmIR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmIEd
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC13(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm6
	subsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L151
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm7
	subsd	%xmm0, %xmm7
	movapd	%xmm7, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L151
	leaq	.LC8(%rip), %rax
	jmp	.L154
.L151:
	leaq	.LC9(%rip), %rax
.L154:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-200(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmLR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmLIdEERS0_RKS_IT_E
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L155
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L155
	leaq	.LC8(%rip), %rax
	jmp	.L158
.L155:
	leaq	.LC9(%rip), %rax
.L158:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-64(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZmLR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmLEd
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC14(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movapd	%xmm4, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L159
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm5
	subsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L159
	leaq	.LC8(%rip), %rax
	jmp	.L162
.L159:
	leaq	.LC9(%rip), %rax
.L162:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-200(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZdVR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-200(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-112(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7complexIdEdVIdEERS0_RKS_IT_E
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm6
	subsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L163
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm7
	subsd	%xmm0, %xmm7
	movapd	%xmm7, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L163
	leaq	.LC8(%rip), %rax
	jmp	.L166
.L163:
	leaq	.LC9(%rip), %rax
.L166:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-192(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
	leaq	-64(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZdVR7ComplexRKS_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	-128(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	-120(%rbp), %xmm0
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-216(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEdVEd
	movsd	(%rax), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -88(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC15(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-216(%rbp), %rax
	movq	%rax, -232(%rbp)
	movsd	-232(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm2
	subsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L167
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm3
	subsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L167
	leaq	.LC8(%rip), %rax
	jmp	.L170
.L167:
	leaq	.LC9(%rip), %rax
.L170:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-208(%rbp), %rax
	movq	%rax, %rdi
	call	_ZpsRK7Complex
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC16(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC17(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZStpsIdESt7complexIT_ERKS2_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC16(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC17(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movapd	%xmm4, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L171
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm5
	subsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L171
	leaq	.LC8(%rip), %rax
	jmp	.L174
.L171:
	leaq	.LC9(%rip), %rax
.L174:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-208(%rbp), %rax
	movq	%rax, %rdi
	call	_ZngRK7Complex
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexaSERKS_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC18(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-208(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZlsRSoRK7Complex
	leaq	.LC17(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZStngIdESt7complexIT_ERKS2_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC18(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIdcSt11char_traitsIcEERSt13basic_ostreamIT0_T1_ES6_RKSt7complexIT_E@PLT
	leaq	.LC17(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ReEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movsd	-232(%rbp), %xmm6
	subsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L175
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK7Complex2ImEv
	movsd	%xmm0, -232(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movsd	-232(%rbp), %xmm7
	subsd	%xmm0, %xmm7
	movapd	%xmm7, %xmm0
	movq	.LC6(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movsd	.LC7(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L175
	leaq	.LC8(%rip), %rax
	jmp	.L178
.L175:
	leaq	.LC9(%rip), %rax
.L178:
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movl	$0, %eax
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L180
	call	__stack_chk_fail@PLT
.L180:
	addq	$232, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2037:
	.size	main, .-main
	.section	.text._ZStplIdESt7complexIT_ERKS2_S4_,"axG",@progbits,_ZStplIdESt7complexIT_ERKS2_S4_,comdat
	.weak	_ZStplIdESt7complexIT_ERKS2_S4_
	.type	_ZStplIdESt7complexIT_ERKS2_S4_, @function
_ZStplIdESt7complexIT_ERKS2_S4_:
.LFB2282:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7complexIdEpLIdEERS0_RKS_IT_E
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L225
	call	__stack_chk_fail@PLT
.L225:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2282:
	.size	_ZStplIdESt7complexIT_ERKS2_S4_, .-_ZStplIdESt7complexIT_ERKS2_S4_
	.section	.text._ZStplIdESt7complexIT_ERKS2_RKS1_,"axG",@progbits,_ZStplIdESt7complexIT_ERKS2_RKS1_,comdat
	.weak	_ZStplIdESt7complexIT_ERKS2_RKS1_
	.type	_ZStplIdESt7complexIT_ERKS2_RKS1_, @function
_ZStplIdESt7complexIT_ERKS2_RKS1_:
.LFB2283:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEpLEd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L228
	call	__stack_chk_fail@PLT
.L228:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2283:
	.size	_ZStplIdESt7complexIT_ERKS2_RKS1_, .-_ZStplIdESt7complexIT_ERKS2_RKS1_
	.section	.text._ZStplIdESt7complexIT_ERKS1_RKS2_,"axG",@progbits,_ZStplIdESt7complexIT_ERKS1_RKS2_,comdat
	.weak	_ZStplIdESt7complexIT_ERKS1_RKS2_
	.type	_ZStplIdESt7complexIT_ERKS1_RKS2_, @function
_ZStplIdESt7complexIT_ERKS1_RKS2_:
.LFB2284:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEpLEd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L231
	call	__stack_chk_fail@PLT
.L231:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2284:
	.size	_ZStplIdESt7complexIT_ERKS1_RKS2_, .-_ZStplIdESt7complexIT_ERKS1_RKS2_
	.section	.text._ZStmiIdESt7complexIT_ERKS2_S4_,"axG",@progbits,_ZStmiIdESt7complexIT_ERKS2_S4_,comdat
	.weak	_ZStmiIdESt7complexIT_ERKS2_S4_
	.type	_ZStmiIdESt7complexIT_ERKS2_S4_, @function
_ZStmiIdESt7complexIT_ERKS2_S4_:
.LFB2285:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmIIdEERS0_RKS_IT_E
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L234
	call	__stack_chk_fail@PLT
.L234:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2285:
	.size	_ZStmiIdESt7complexIT_ERKS2_S4_, .-_ZStmiIdESt7complexIT_ERKS2_S4_
	.section	.text._ZStmiIdESt7complexIT_ERKS2_RKS1_,"axG",@progbits,_ZStmiIdESt7complexIT_ERKS2_RKS1_,comdat
	.weak	_ZStmiIdESt7complexIT_ERKS2_RKS1_
	.type	_ZStmiIdESt7complexIT_ERKS2_RKS1_, @function
_ZStmiIdESt7complexIT_ERKS2_RKS1_:
.LFB2286:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmIEd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L237
	call	__stack_chk_fail@PLT
.L237:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2286:
	.size	_ZStmiIdESt7complexIT_ERKS2_RKS1_, .-_ZStmiIdESt7complexIT_ERKS2_RKS1_
	.section	.text._ZStmiIdESt7complexIT_ERKS1_RKS2_,"axG",@progbits,_ZStmiIdESt7complexIT_ERKS1_RKS2_,comdat
	.weak	_ZStmiIdESt7complexIT_ERKS1_RKS2_
	.type	_ZStmiIdESt7complexIT_ERKS1_RKS2_, @function
_ZStmiIdESt7complexIT_ERKS1_RKS2_:
.LFB2287:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movapd	%xmm0, %xmm1
	movq	.LC1(%rip), %xmm0
	xorpd	%xmm1, %xmm0
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-32(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEC1Edd
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmIEd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L240
	call	__stack_chk_fail@PLT
.L240:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2287:
	.size	_ZStmiIdESt7complexIT_ERKS1_RKS2_, .-_ZStmiIdESt7complexIT_ERKS1_RKS2_
	.section	.text._ZStmlIdESt7complexIT_ERKS2_S4_,"axG",@progbits,_ZStmlIdESt7complexIT_ERKS2_S4_,comdat
	.weak	_ZStmlIdESt7complexIT_ERKS2_S4_
	.type	_ZStmlIdESt7complexIT_ERKS2_S4_, @function
_ZStmlIdESt7complexIT_ERKS2_S4_:
.LFB2288:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmLIdEERS0_RKS_IT_E
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L243
	call	__stack_chk_fail@PLT
.L243:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2288:
	.size	_ZStmlIdESt7complexIT_ERKS2_S4_, .-_ZStmlIdESt7complexIT_ERKS2_S4_
	.section	.text._ZStmlIdESt7complexIT_ERKS2_RKS1_,"axG",@progbits,_ZStmlIdESt7complexIT_ERKS2_RKS1_,comdat
	.weak	_ZStmlIdESt7complexIT_ERKS2_RKS1_
	.type	_ZStmlIdESt7complexIT_ERKS2_RKS1_, @function
_ZStmlIdESt7complexIT_ERKS2_RKS1_:
.LFB2289:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmLEd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L246
	call	__stack_chk_fail@PLT
.L246:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2289:
	.size	_ZStmlIdESt7complexIT_ERKS2_RKS1_, .-_ZStmlIdESt7complexIT_ERKS2_RKS1_
	.section	.text._ZStmlIdESt7complexIT_ERKS1_RKS2_,"axG",@progbits,_ZStmlIdESt7complexIT_ERKS1_RKS2_,comdat
	.weak	_ZStmlIdESt7complexIT_ERKS1_RKS2_
	.type	_ZStmlIdESt7complexIT_ERKS1_RKS2_, @function
_ZStmlIdESt7complexIT_ERKS1_RKS2_:
.LFB2290:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	8(%rax), %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSt7complexIdEmLEd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L249
	call	__stack_chk_fail@PLT
.L249:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2290:
	.size	_ZStmlIdESt7complexIT_ERKS1_RKS2_, .-_ZStmlIdESt7complexIT_ERKS1_RKS2_
	.section	.text._ZNSt7complexIdEpLIdEERS0_RKS_IT_E,"axG",@progbits,_ZNSt7complexIdEpLIdEERS0_RKS_IT_E,comdat
	.align 2
	.weak	_ZNSt7complexIdEpLIdEERS0_RKS_IT_E
	.type	_ZNSt7complexIdEpLIdEERS0_RKS_IT_E, @function
_ZNSt7complexIdEpLIdEERS0_RKS_IT_E:
.LFB2291:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movapd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, (%rax)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movapd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2291:
	.size	_ZNSt7complexIdEpLIdEERS0_RKS_IT_E, .-_ZNSt7complexIdEpLIdEERS0_RKS_IT_E
	.section	.text._ZNSt7complexIdEmIIdEERS0_RKS_IT_E,"axG",@progbits,_ZNSt7complexIdEmIIdEERS0_RKS_IT_E,comdat
	.align 2
	.weak	_ZNSt7complexIdEmIIdEERS0_RKS_IT_E
	.type	_ZNSt7complexIdEmIIdEERS0_RKS_IT_E, @function
_ZNSt7complexIdEmIIdEERS0_RKS_IT_E:
.LFB2292:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movapd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	subsd	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, (%rax)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movapd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm0
	subsd	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2292:
	.size	_ZNSt7complexIdEmIIdEERS0_RKS_IT_E, .-_ZNSt7complexIdEmIIdEERS0_RKS_IT_E
	.section	.text._ZNSt7complexIdEmLIdEERS0_RKS_IT_E,"axG",@progbits,_ZNSt7complexIdEmLIdEERS0_RKS_IT_E,comdat
	.align 2
	.weak	_ZNSt7complexIdEmLIdEERS0_RKS_IT_E
	.type	_ZNSt7complexIdEmLIdEERS0_RKS_IT_E, @function
_ZNSt7complexIdEmLIdEERS0_RKS_IT_E:
.LFB2293:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movq	%xmm0, %rax
	movq	%rax, -32(%rbp)
	movsd	-24(%rbp), %xmm0
	movsd	-32(%rbp), %xmm1
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm0, -8(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movsd	-32(%rbp), %xmm1
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm0, -8(%rbp)
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm1
	movq	-40(%rbp), %rax
	movsd	8(%rax), %xmm2
	movsd	-24(%rbp), %xmm0
	movq	-32(%rbp), %rax
	movapd	%xmm2, %xmm3
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	call	__muldc3@PLT
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm1
	movq	-40(%rbp), %rax
	movsd	%xmm1, (%rax)
	movq	-40(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	movq	-40(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2293:
	.size	_ZNSt7complexIdEmLIdEERS0_RKS_IT_E, .-_ZNSt7complexIdEmLIdEERS0_RKS_IT_E
	.section	.text._ZNSt7complexIdEdVIdEERS0_RKS_IT_E,"axG",@progbits,_ZNSt7complexIdEdVIdEERS0_RKS_IT_E,comdat
	.align 2
	.weak	_ZNSt7complexIdEdVIdEERS0_RKS_IT_E
	.type	_ZNSt7complexIdEdVIdEERS0_RKS_IT_E, @function
_ZNSt7complexIdEdVIdEERS0_RKS_IT_E:
.LFB2294:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movq	%xmm0, %rax
	movq	%rax, -32(%rbp)
	movsd	-24(%rbp), %xmm0
	movsd	-32(%rbp), %xmm1
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm0, -8(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movsd	-32(%rbp), %xmm1
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm0, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	-40(%rbp), %rdx
	movsd	8(%rdx), %xmm0
	movsd	-24(%rbp), %xmm2
	movsd	-32(%rbp), %xmm1
	movapd	%xmm2, %xmm3
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	call	__divdc3@PLT
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm1
	movq	-40(%rbp), %rax
	movsd	%xmm1, (%rax)
	movq	-40(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	movq	-40(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2294:
	.size	_ZNSt7complexIdEdVIdEERS0_RKS_IT_E, .-_ZNSt7complexIdEdVIdEERS0_RKS_IT_E
	.section	.text._ZStpsIdESt7complexIT_ERKS2_,"axG",@progbits,_ZStpsIdESt7complexIT_ERKS2_,comdat
	.weak	_ZStpsIdESt7complexIT_ERKS2_
	.type	_ZStpsIdESt7complexIT_ERKS2_, @function
_ZStpsIdESt7complexIT_ERKS2_:
.LFB2295:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm1
	movsd	8(%rax), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2295:
	.size	_ZStpsIdESt7complexIT_ERKS2_, .-_ZStpsIdESt7complexIT_ERKS2_
	.section	.text._ZStngIdESt7complexIT_ERKS2_,"axG",@progbits,_ZStngIdESt7complexIT_ERKS2_,comdat
	.weak	_ZStngIdESt7complexIT_ERKS2_
	.type	_ZStngIdESt7complexIT_ERKS2_, @function
_ZStngIdESt7complexIT_ERKS2_:
.LFB2296:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4imagB5cxx11Ev
	movapd	%xmm0, %xmm1
	movq	.LC1(%rip), %xmm0
	xorpd	%xmm0, %xmm1
	movsd	%xmm1, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7complexIdE4realB5cxx11Ev
	movapd	%xmm0, %xmm1
	movq	.LC1(%rip), %xmm0
	xorpd	%xmm1, %xmm0
	leaq	-32(%rbp), %rax
	movsd	-48(%rbp), %xmm1
	movq	%rax, %rdi
	call	_ZNSt7complexIdEC1Edd
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L262
	call	__stack_chk_fail@PLT
.L262:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2296:
	.size	_ZStngIdESt7complexIT_ERKS2_, .-_ZStngIdESt7complexIT_ERKS2_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2546:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L265
	cmpl	$65535, -8(%rbp)
	jne	.L265
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L265:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2546:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZplRK7ComplexS1_, @function
_GLOBAL__sub_I__ZplRK7ComplexS1_:
.LFB2547:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2547:
	.size	_GLOBAL__sub_I__ZplRK7ComplexS1_, .-_GLOBAL__sub_I__ZplRK7ComplexS1_
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZplRK7ComplexS1_
	.section	.rodata
	.align 16
.LC1:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.align 16
.LC6:
	.long	4294967295
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC7:
	.long	2696277389
	.long	1051772663
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
