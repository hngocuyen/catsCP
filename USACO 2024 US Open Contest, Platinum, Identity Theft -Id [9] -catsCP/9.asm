#traidepluyenthuattoan - hngocuyen - [9]>> solutions
	.globl	_start
_start:
	xorl	%ebp, %ebp
	andq	$-16, %rsp
	callq	o
	movl	$60, %eax
	xorl	%edi, %edi
	syscall
	.text
	.globl	a
	.p2align	4
a:
	movq	%rdi, %rax
	testq	%rdx, %rdx
	je	c
	xorl	%ecx, %ecx
	.p2align	4
b:
	movb	%sil, (%rax,%rcx)
	incq	%rcx
	cmpq	%rcx, %rdx
	jne	b
c:
	retq
d:
	.globl	e
	.p2align	4
e:
	movq	%rdi, %rax
	testq	%rdx, %rdx
	je	g
	xorl	%ecx, %ecx
	.p2align	4
f:
	movzbl	(%rsi,%rcx), %edi
	movb	%dil, (%rax,%rcx)
	incq	%rcx
	cmpq	%rcx, %rdx
	jne	f
g:
	retq
h:
	.globl	i
	.p2align	4
i:
	movq	%rdi, %rax
	cmpq	%rsi, %rdi
	jae	k
	testq	%rdx, %rdx
	je	m
	xorl	%ecx, %ecx
	.p2align	4
j:
	movzbl	(%rsi,%rcx), %edi
	movb	%dil, (%rax,%rcx)
	incq	%rcx
	cmpq	%rcx, %rdx
	jne	j
	jmp	m
k:
	testq	%rdx, %rdx
	je	m
	movq	%rdx, %rcx
	.p2align	4
l:
	decq	%rcx
	movzbl	-1(%rsi,%rdx), %edi
	movb	%dil, -1(%rax,%rdx)
	movq	%rcx, %rdx
	jne	l
m:
	retq
n:
	.globl	o
	.p2align	4
o:
	pushq	%rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	movl	cu(%rip), %r9d
	movl	cv(%rip), %eax
	cmpl	%eax, %r9d
	jne	p
	xorl	%r9d, %r9d
	movl	$cw, %esi
	movl	$65536, %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	syscall
	movl	%eax, cv(%rip)
	movl	$0, cu(%rip)
	testl	%eax, %eax
	jle	aob
p:
	leal	1(%r9), %r8d
	movl	%r8d, cu(%rip)
	movslq	%r9d, %rcx
	movzbl	cw(%rcx), %r9d
q:
	cmpl	$45, %r9d
	sete	%cl
	leal	-58(%r9), %edx
	cmpl	$-10, %edx
	setae	%dl
	orb	%cl, %dl
	jne	u
	movl	$cw, %esi
	jmp	t
	.p2align	4
r:
	movslq	%r8d, %rcx
	leal	1(%r8), %edx
	movl	%edx, cu(%rip)
	movzbl	cw(%rcx), %r9d
	movl	%edx, %r8d
	cmpl	$45, %r9d
	je	u
s:
	leal	-58(%r9), %ecx
	cmpl	$-10, %ecx
	jae	u
t:
	testl	%r9d, %r9d
	js	ant
	cmpl	%eax, %r8d
	jne	r
	xorl	%r8d, %r8d
	movl	$65536, %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	syscall
	movl	%eax, cv(%rip)
	movl	$0, cu(%rip)
	testl	%eax, %eax
	jg	r
	movl	$0, cv(%rip)
	movl	$-1, %r9d
	xorl	%eax, %eax
	xorl	%r8d, %r8d
	cmpl	$45, %r9d
	jne	s
u:
	cmpl	$45, %r9d
	jne	w
	cmpl	%eax, %r8d
	jne	v
	xorl	%r8d, %r8d
	movl	$cw, %esi
	movl	$65536, %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	syscall
	movl	%eax, cv(%rip)
	movl	$0, cu(%rip)
	movl	$0, %ebx
	testl	%eax, %eax
	jle	aa
v:
	movslq	%r8d, %rcx
	leal	1(%r8), %edx
	movl	%edx, cu(%rip)
	movzbl	cw(%rcx), %ecx
	movl	%edx, %r8d
	jmp	x
w:
	movl	%r9d, %ecx
x:
	addl	$-48, %ecx
	xorl	%ebx, %ebx
	cmpl	$9, %ecx
	ja	ab
	xorl	%ebx, %ebx
	movl	$cw, %esi
	jmp	z
	.p2align	4
y:
	leal	1(%r8), %r10d
	movl	%r10d, cu(%rip)
	movslq	%r8d, %rcx
	movzbl	cw(%rcx), %ecx
	addl	$-48, %ecx
	movl	%r10d, %r8d
	cmpl	$10, %ecx
	jae	ac
z:
	leal	(%rbx,%rbx,4), %edx
	leal	(%rcx,%rdx,2), %ebx
	cmpl	%eax, %r8d
	jne	y
	xorl	%r8d, %r8d
	movl	$65536, %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	syscall
	movl	%eax, cv(%rip)
	movl	$0, cu(%rip)
	testl	%eax, %eax
	jg	y
aa:
	movl	$0, cv(%rip)
	xorl	%eax, %eax
	xorl	%r10d, %r10d
	jmp	ac
ab:
	movl	%r8d, %r10d
ac:
	movl	%ebx, %r8d
	negl	%r8d
	cmpl	$45, %r9d
	cmovnel	%ebx, %r8d
	movl	$1, ck(%rip)
	xorl	%ebx, %ebx
	testl	%r8d, %r8d
	jle	bk
	movabsq	$4294977024, %r9
	jmp	af
	.p2align	4
ad:
	movslq	%r10d, %rsi
	movl	%edx, %r10d
ae:
	incl	cp(,%rsi,4)
	incl	%ebx
	cmpl	%r8d, %ebx
	je	aw
af:
	cmpl	%eax, %r10d
	jne	ag
	xorl	%r10d, %r10d
	movl	$cw, %esi
	movl	$65536, %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	syscall
	movl	%eax, cv(%rip)
	movl	$0, cu(%rip)
	testl	%eax, %eax
	jle	at
ag:
	leal	1(%r10), %edx
	movl	%edx, cu(%rip)
	movslq	%r10d, %rcx
	movzbl	cw(%rcx), %esi
amt:
	movl	%eax, %ecx
	movl	%edx, %r10d
	cmpl	$32, %esi
	jbe	aj
	jmp	ak
	.p2align	4
ai:
	movslq	%r10d, %rdx
	leal	1(%r10), %edi
	movl	%edi, cu(%rip)
	movzbl	cw(%rdx), %esi
	movl	%edi, %r10d
	cmpl	$32, %esi
	ja	ak
aj:
	movl	%esi, %edx
	btq	%rdx, %r9
	jae	ak
	cmpl	%ecx, %r10d
	jne	ai
	xorl	%r10d, %r10d
	movl	$cw, %esi
	movl	$65536, %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	syscall
	movl	%eax, cv(%rip)
	movl	$0, cu(%rip)
	movl	%eax, %ecx
	testl	%eax, %eax
	jg	ai
	movl	$0, cv(%rip)
	movl	$-1, %esi
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	xorl	%r10d, %r10d
	cmpl	$32, %esi
	jbe	aj
	.p2align	4
ak:
	cmpl	$32, %esi
	jle	as
	movl	$1, %edi
	movl	$1, %r11d
	jmp	am
	.p2align	4
amx:
	leal	1(%r10), %edx
	movl	%edx, cu(%rip)
	movslq	%r10d, %rsi
	movzbl	cw(%rsi), %esi
	leaq	1(%r15), %rdi
	leal	1(%r14), %r11d
	movl	%edx, %r10d
	cmpb	$32, %sil
	jbe	an
am:
	movq	%rdi, %r15
	movl	%r11d, %r14d
	movb	%sil, aox-1(%rdi)
	cmpl	%ecx, %r10d
	jne	amx
	xorl	%r10d, %r10d
	movl	$cw, %esi
	movl	$65536, %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	syscall
	movl	%eax, cv(%rip)
	movl	$0, cu(%rip)
	movl	%eax, %ecx
	testl	%eax, %eax
	jg	amx
	movl	$0, cv(%rip)
	xorl	%eax, %eax
	xorl	%edx, %edx
an:
	movl	%r15d, %ecx
	movb	$0, aox(%rcx)
	movl	ck(%rip), %ecx
	testl	%r15d, %r15d
	jle	au
	movl	%r14d, %esi
	xorl	%edi, %edi
	xorl	%r10d, %r10d
	jmp	aq
	.p2align	4
ao:
	movslq	%r10d, %r14
	movl	(%r11,%r14,4), %r10d
	testl	%r10d, %r10d
	je	ar
ap:
	incq	%rdi
	cmpq	%rdi, %rsi
	je	ad
aq:
	cmpb	$48, aox(%rdi)
	movl	$cm, %r11d
	je	ao
	movl	$cn, %r11d
	jmp	ao
	.p2align	4
ar:
	movl	%ecx, (%r11,%r14,4)
	movl	co(,%r14,4), %r11d
	incl	%r11d
	movl	%ecx, %r10d
	movslq	%ecx, %rcx
	movl	%r11d, co(,%rcx,4)
	incl	%ecx
	movl	%ecx, ck(%rip)
	jmp	ap
	.p2align	4
as:
	movb	$0, aox(%rip)
	movl	ck(%rip), %ecx
	jmp	av
at:
	movl	$0, cv(%rip)
	movl	$-1, %esi
	xorl	%eax, %eax
	xorl	%edx, %edx
	jmp	amt
au:
	movl	%edx, %r10d
av:
	xorl	%esi, %esi
	jmp	ae
aw:
	cmpl	$2, %ecx
	jl	bi
	movl	cy(%rip), %r14d
	movl	%ecx, %r15d
	xorl	%ebx, %ebx
	jmp	ay
	.p2align	4
anj:
	movl	%eax, cq(,%r12,4)
	cmpq	$2, 8(%rsp)
	movq	%r12, %r15
	jle	bj
ay:
	leaq	-1(%r15), %r12
	movslq	cm-4(,%r15,4), %rax
	movl	cq(,%rax,4), %edi
	movslq	cn-4(,%r15,4), %rax
	movl	cq(,%rax,4), %esi
	callq	cd
	cmpl	$0, cm-4(,%r15,4)
	movl	cn-4(,%r15,4), %ecx
	movq	%r15, 8(%rsp)
	je	az
	testl	%ecx, %ecx
	jne	bd
	jmp	ba
	.p2align	4
az:
	testl	%ecx, %ecx
	je	bb
ba:
	movl	co(,%r12,4), %ecx
	leal	2(,%rcx,2), %ecx
	jmp	bc
bb:
	movl	co(,%r12,4), %ecx
	addl	%ecx, %ecx
bc:
	leal	1(%r14), %ebp
	movl	%ebp, cy(%rip)
	movslq	%r14d, %rdx
	movl	%ecx, cr+4(,%rdx,4)
	movl	$0, ct+4(,%rdx,4)
	movl	$0, ape+4(,%rdx,4)
	movl	$1, apj+4(,%rdx,4)
	movl	%eax, %edi
	movl	%ebp, %esi
	callq	cd
	movl	%ebp, %r14d
bd:
	movl	cp(,%r12,4), %r13d
	testl	%r13d, %r13d
	movq	%r12, 16(%rsp)
	jg	bg
	jmp	anj
	.p2align	4
be:
	leal	5(%r15), %ecx
	movslq	%ebp, %rdx
	movl	%ecx, cr(,%rdx,4)
	movl	$0, ct(,%rdx,4)
	movl	$0, ape(,%rdx,4)
	movl	$1, apj(,%rdx,4)
	movl	%eax, %edi
	movl	%ebp, %esi
	callq	cd
bf:
	sarl	%r15d
	movslq	%r15d, %rcx
	subq	24(%rsp), %rcx
	addq	%rcx, %rbx
	movl	%ebp, cy(%rip)
	movl	%ebp, %r14d
	decl	%r13d
	je	anj
bg:
	cltq
	movl	cr(,%rax,4), %r15d
	movl	ape(,%rax,4), %edi
	movl	ct(,%rax,4), %esi
	callq	cd
	movslq	co(,%r12,4), %rcx
	movq	%rcx, 24(%rsp)
	leal	1(%r14), %ebp
	testb	$1, %r15b
	je	be
	movq	%rbx, %r12
	leal	2(%r15), %ebx
	movl	%ebp, cy(%rip)
	movslq	%ebp, %rsi
	movl	%ebx, cr(,%rsi,4)
	movl	$0, ct(,%rsi,4)
	movl	$0, ape(,%rsi,4)
	movl	$1, apj(,%rsi,4)
	movl	%eax, %edi
	callq	cd
	movslq	%r14d, %rcx
	addl	$2, %r14d
	movl	%ebx, cr+8(,%rcx,4)
	movq	%r12, %rbx
	movq	16(%rsp), %r12
	movl	$0, ct+8(,%rcx,4)
	movl	$0, ape+8(,%rcx,4)
	movl	$1, apj+8(,%rcx,4)
	movl	%eax, %edi
	movl	%r14d, %esi
	callq	cd
	movl	%r14d, %ebp
	jmp	bf
ant:
	movl	$1, ck(%rip)
bi:
	xorl	%ebx, %ebx
	jmp	bk
bj:
	testq	%rbx, %rbx
	js	bq
bk:
	xorl	%ecx, %ecx
	movabsq	$-3689348814741910323, %rsi
	.p2align	4
anx:
	movq	%rbx, %rax
	mulq	%rsi
	shrq	$3, %rdx
	leal	(%rdx,%rdx), %eax
	leal	(%rax,%rax,4), %eax
	movl	%ebx, %edi
	subl	%eax, %edi
	orb	$48, %dil
	movb	%dil, 32(%rsp,%rcx)
	incq	%rcx
	cmpq	$9, %rbx
	movq	%rdx, %rbx
	ja	anx
	movslq	%ecx, %r9
	movl	ci(%rip), %r8d
	movl	$1, %edi
	jmp	bn
	.p2align	4
bm:
	decq	%r9
	leal	1(%rbx), %r8d
	movl	%r8d, ci(%rip)
	movslq	%ebx, %rax
	movb	%r10b, cj(%rax)
	testq	%r9, %r9
	je	aoj
bn:
	movzbl	31(%rsp,%r9), %r10d
	movl	%r8d, %ebx
	cmpl	$65536, %r8d
	jne	bm
	xorl	%r8d, %r8d
	.p2align	4
bo:
	movslq	ci(%rip), %rdx
	xorl	%ebx, %ebx
	subq	%r8, %rdx
	jle	bm
	leaq	cj(%r8), %rsi
	movl	$1, %eax
	syscall
	addq	%rax, %r8
	testq	%rax, %rax
	jg	bo
	jmp	bm
aob:
	movl	$0, cv(%rip)
	movl	$-1, %r9d
	xorl	%eax, %eax
	xorl	%r8d, %r8d
	jmp	q
bq:
	movl	ci(%rip), %r9d
	cmpl	$65536, %r9d
	jne	bs
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	movl	$1, %edi
	.p2align	4
br:
	movslq	ci(%rip), %rdx
	subq	%r8, %rdx
	jle	bs
	leaq	cj(%r8), %rsi
	movl	$1, %eax
	syscall
	addq	%rax, %r8
	testq	%rax, %rax
	jg	br
bs:
	leal	1(%r9), %r8d
	movl	%r8d, ci(%rip)
	movslq	%r9d, %rax
	movb	$45, cj(%rax)
	negq	%rbx
	xorl	%ecx, %ecx
	movabsq	$-3689348814741910323, %rsi
	.p2align	4
aof:
	movq	%rbx, %rax
	mulq	%rsi
	shrq	$3, %rdx
	leal	(%rdx,%rdx), %eax
	leal	(%rax,%rax,4), %eax
	movl	%ebx, %edi
	subl	%eax, %edi
	orb	$48, %dil
	movb	%dil, 32(%rsp,%rcx)
	incq	%rcx
	cmpq	$9, %rbx
	movq	%rdx, %rbx
	ja	aof
	movslq	%ecx, %r9
	movl	$1, %edi
	jmp	bv
	.p2align	4
bu:
	decq	%r9
	leal	1(%rbx), %r8d
	movl	%r8d, ci(%rip)
	movslq	%ebx, %rax
	movb	%r10b, cj(%rax)
	testq	%r9, %r9
	je	aoj
bv:
	movzbl	31(%rsp,%r9), %r10d
	movl	%r8d, %ebx
	cmpl	$65536, %r8d
	jne	bu
	xorl	%r8d, %r8d
	.p2align	4
bw:
	movslq	ci(%rip), %rdx
	xorl	%ebx, %ebx
	subq	%r8, %rdx
	jle	bu
	leaq	cj(%r8), %rsi
	movl	$1, %eax
	syscall
	addq	%rax, %r8
	testq	%rax, %rax
	jg	bw
	jmp	bu
aoj:
	cmpl	$65536, %r8d
	jne	bz
	xorl	%r8d, %r8d
	xorl	%r9d, %r9d
	movl	$1, %edi
	.p2align	4
by:
	movslq	ci(%rip), %rdx
	subq	%r9, %rdx
	jle	bz
	leaq	cj(%r9), %rsi
	movl	$1, %eax
	syscall
	addq	%rax, %r9
	testq	%rax, %rax
	jg	by
bz:
	leal	1(%r8), %eax
	movl	%eax, ci(%rip)
	movslq	%r8d, %rax
	movb	$10, cj(%rax)
	xorl	%r8d, %r8d
	movl	$1, %edi
	.p2align	4
ca:
	movslq	ci(%rip), %rdx
	subq	%r8, %rdx
	jle	cb
	leaq	cj(%r8), %rsi
	movl	$1, %eax
	syscall
	addq	%rax, %r8
	testq	%rax, %rax
	jg	ca
cb:
	movl	$0, ci(%rip)
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
cc:
	.p2align	4
cd:
	pushq	%r14
	pushq	%rbx
	pushq	%rax
	testl	%edi, %edi
	je	cf
	movl	%edi, %ebx
	testl	%esi, %esi
	je	cg
	movslq	%ebx, %rax
	movl	cr(,%rax,4), %eax
	movslq	%esi, %rcx
	cmpl	cr(,%rcx,4), %eax
	movl	%esi, %eax
	cmovgl	%ebx, %eax
	cmovgl	%esi, %ebx
	movslq	%ebx, %r14
	movl	ct(,%r14,4), %edi
	movl	%eax, %esi
	callq	cd
	movl	%eax, ct(,%r14,4)
	movslq	ape(,%r14,4), %rdx
	movl	apj(,%rdx,4), %ecx
	movslq	%eax, %rsi
	movl	apj(,%rsi,4), %esi
	cmpl	%esi, %ecx
	jge	ce
	movl	%eax, ape(,%r14,4)
	movl	%edx, ct(,%r14,4)
	movl	%ecx, %esi
ce:
	incl	%esi
	movl	%esi, apj(,%r14,4)
	jmp	cg
cf:
	movl	%esi, %ebx
cg:
	movl	%ebx, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	retq
aot:
	.local	ci
	.comm	ci,4,4
	.local	cj
	.comm	cj,65536,16
	.local	ck
	.comm	ck,4,4
	.local	aox
	.comm	aox,1000005,16
	.local	cm
	.comm	cm,4000020,16
	.local	cn
	.comm	cn,4000020,16
	.local	co
	.comm	co,4000020,16
	.local	cp
	.comm	cp,4000020,16
	.local	cq
	.comm	cq,4000020,16
	.local	cr
	.comm	cr,12800020,16
	.local	ape
	.comm	ape,12800020,16
	.local	ct
	.comm	ct,12800020,16
	.local	cu
	.comm	cu,4,4
	.local	cv
	.comm	cv,4,4
	.local	cw
	.comm	cw,65536,16
	.local	apj
	.comm	apj,12800020,16
	.local	cy
	.comm	cy,4,4
