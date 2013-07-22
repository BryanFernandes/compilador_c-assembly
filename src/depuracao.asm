
.constant
teste	3
abcdef	10
bryanhf	5
.end-constant

.main

.var
y
x
.end-var
		BIPUSH 3
		ISTORE x
		ILOAD x
		ILOAD p
		ISUB
		ISTORE x
		ILOAD x
		BIPUSH 3
		IF_ICMPEQ L1
L1:
		BIPUSH 4
		ISTORE y
		ILOAD y
		BIPUSH 4
		IF_ICMPEQ L2
L2:
		BIPUSH 5
		ISTORE x
		ILOAD y
		ISTORE x
.end-main