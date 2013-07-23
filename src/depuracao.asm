
.constant
palÿ	3
abcdef	10
bryanhf	5
.end-constant

.main

.var
y
x
p
j
.end-var

		BIPUSH 3
		ISTORE x
		ILOAD x
		ILOAD y
		ISUB
		ISTORE x
		ILOAD 3
		BIPUSH 3
		IF_ICMPEQ L1
G1:
		ILOAD PAL
		BIPUSH 3
		IADD
		ISTORE p


halt
L1:
		BIPUSH 7
		ISTORE p
		BIPUSH 29
		ISTORE y
GOTO G1


.end-main