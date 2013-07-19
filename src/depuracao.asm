
.constant
teste	3
abcdef	10
bryanhf	5
.end-constant

.main
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
		BIPUSH y
		ISTORE x
.end-main