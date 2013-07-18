
.constant
teste	3
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
L3:
		BIPUSH 0
		ISTORE r
		ILOAD y
		BIPUSH 1
		IF_ICMPEQ L3
		ILOAD c
		BIPUSH 0
		IF_ICMPEQ L4
L4:
		BIPUSH 5
		ISTORE r
.end-main