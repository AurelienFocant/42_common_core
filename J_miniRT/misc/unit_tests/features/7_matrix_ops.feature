Feature: doing stuff with matrices

	# Matrices Multiplication
	Scenario: Multiplying two matrices
		Given the following matrix A:
			| 1 | 2 | 3 | 4 |
			| 5 | 6 | 7 | 8 |
			| 9 | 8 | 7 | 6 |
			| 5 | 4 | 3 | 2 |
		And the following matrix B:
			| -2 | 1 | 2 | 3 |
			| 3 | 2 | 1 | -1 |
			| 4 | 3 | 6 | 5 |
			| 1 | 2 | 7 | 8 |
		Then A * B is the following 4x4 matrix:
			| 20| 22 | 50 | 48 |
			| 44| 54 | 114 | 108 |
			| 40| 58 | 110 | 102 |
			| 16| 26 | 46 | 42 |


	Scenario: A matrix multiplied by a tuple
		Given the following matrix Z:
			| 1 | 2 | 3 | 4 |
			| 2 | 4 | 4 | 2 |
			| 8 | 6 | 4 | 1 |
			| 0 | 0 | 0 | 1 |
		And b ← tuple(1, 2, 3, 1)
		Then Z * b = tuple(18, 24, 33, 1)


	Scenario: Multiplying a matrix by the identity matrix
		Given the following matrix C:
			| 0 | 1 | 2 | 4 |
			| 1 | 2 | 4 | 8 |
			| 2 | 4 | 8 | 16 |
			| 4 | 8 | 16 | 32 |
		Then C * identity_matrix = C

	Scenario: Multiplying the identity matrix by a tuple
		Given a ← tuple(1, 2, 3, 4)
		Then identity_matrix * a = a


	# Scenario: Transposing a matrix
	# 	Given the following matrix D:
	# 		| 0 | 9 | 3 | 0 |
	# 		| 9 | 8 | 0 | 8 |
	# 		| 1 | 8 | 5 | 3 |
	# 		| 0 | 0 | 5 | 8 |
	# 	Then transpose(D) is the following matrix:
	# 		| 0 | 9 | 1 | 0 |
	# 		| 9 | 8 | 8 | 0 |
	# 		| 3 | 0 | 5 | 5 |
	# 		| 0 | 8 | 3 | 8 |
	#
	#
	# #INVERTING MATRICES
	# Scenario: Calculating the determinant of a 2x2 matrix
	# 	Given the following 2x2 matrix E:
	# 		| 1 | 5 |
	# 		| -3 | 2 |
	# 	Then determinant(E) = 17
	#
	# Scenario: A submatrix of a 3x3 matrix is a 2x2 matrix
	# 	Given the following 3x3 matrix F:
	# 		| 1 | 5 | 0 |
	# 		| -3 | 2 | 7 |
	# 		| 0 | 6 | -3 |
	# 	Then submatrix(F, 0, 2) is the following 2x2 matrix:
	# 		| -3 | 2 |
	# 		| 0 | 6 |
	#
	# Scenario: A submatrix of a 4x4 matrix is a 3x3 matrix
	# 	Given the following 4x4 matrix G:
	# 		| -6 | 1 | 1 | 6 |
	# 		| -8 | 5 | 8 | 6 |
	# 		| -1 | 0 | 8 | 2 |
	# 		| -7 | 1 | -1 | 1 |
	# 	Then submatrix(G, 2, 1) is the following 3x3 matrix:
	# 		| -6 | 1 | 6 |
	# 		| -8 | 8 | 6 |
	# 		| -7 | -1 | 1 |
	#
	# Scenario: Calculating a minor of a 3x3 matrix
	# 	Given the following 3x3 matrix H:
	# 		| 3 | 5 | 0 |
	# 		| 2 | -1 | -7 |
	# 		| 6 | -1 | 5 |
	# 	And I ← submatrix(H, 1, 0)
	# 	Then determinant(I) = 25
	# 	And minor(H, 1, 0) = 25
	#
	# Scenario: Calculating a cofactor of a 3x3 matrix
	# 	Given the following 3x3 matrix K:
	# 		| 3 | 5 | 0 |
	# 		| 2 | -1 | -7 |
	# 		| 6 | -1 | 5 |
	# 	Then minor(K, 0, 0) = -12
	# 	And cofactor(K, 0, 0) = -12
	# 	And minor(K, 1, 0) = 25
	# 	And cofactor(K, 1, 0) = -25
	#
	# Scenario: Calculating the determinant of a 3x3 matrix
	# 	Given the following 3x3 matrix L:
	# 		| 1 | 2 | 6 |
	# 		| -5 | 8 | -4 |
	# 		| 2 | 6 | 4 |
	# 	Then cofactor(L, 0, 0) = 56
	# 	And cofactor(L, 0, 1) = 12
	# 	And cofactor(L, 0, 2) = -46
	# 	And determinant(L) = -196
	#
	# Scenario: Calculating the determinant of a 4x4 matrix
	# 	Given the following 4x4 matrix M:
	# 		| -2 | -8 | 3 | 5 |
	# 		| -3 | 1 | 7 | 3 |
	# 		| 1 | 2 | -9 | 6 |
	# 		| -6 | 7 | 7 | -9 |
	# 	Then cofactor(M, 0, 0) = 690
	# 	And cofactor(M, 0, 1) = 447
	# 	And cofactor(M, 0, 2) = 210
	# 	And cofactor(M, 0, 3) = 51
	# 	And determinant(M) = -4071
	#
	# Scenario: Testing an invertible matrix for invertibility
	# 	Given the following 4x4 matrix O:
	# 		| 6 | 4 | 4 | 4 |
	# 		| 5 | 5 | 7 | 6 |
	# 		| 4 | -9 | 3 | -7 |
	# 		| 9 | 1 | 7 | -6 |
	# 	Then determinant(O) = -2120
	# 	And O is invertible
	#
	# Scenario: Testing a noninvertible matrix for invertibility
	# 	Given the following 4x4 matrix P:
	# 		| -4 | 2 | -2 | -3 |
	# 		| 9 | 6 | 2 | 6 |
	# 		| 0 | -5 | 1 | -5 |
	# 		| 0 | 0 | 0 | 0 |
	# 	Then determinant(P) = 0
	# 	And P is not invertible
	#
	# Scenario: Calculating the inverse of a matrix
	# 	Given the following 4x4 matrix Q:
	# 		| -5 | 2 | 6 | -8 |
	# 		| 1 | -5 | 1 | 8 |
	# 		| 7 | 7 | -6 | -7 |
	# 		| 1 | -3 | 7 | 4 |
	# 	And R ← inverse(Q)
	# 	Then determinant(Q) = 532
	# 	And cofactor(Q, 2, 3) = -160
	# 	And R[3,2] = -160/532
	# 	And cofactor(Q, 3, 2) = 105
	# 	And R[2,3] = 105/532
	# 	And R is the following 4x4 matrix:
	# 		| 0.21805 | 0.45113 | 0.24060 | -0.04511 |
	# 		| -0.80827 | -1.45677 | -0.44361 | 0.52068 |
	# 		| -0.07895 | -0.22368 | -0.05263 | 0.19737 |
	# 		| -0.52256 | -0.81391 | -0.30075 | 0.30639 |
	#
	# Scenario: Calculating the inverse of another matrix
	# 	Given the following 4x4 matrix S:
	# 		| 8 | -5 | 9 | 2 |
	# 		| 7 | 5 | 6 | 1 |
	# 		| -6 | 0 | 9 | 6 |
	# 		| -3 | 0 | -9 | -4 |
	# 	Then inverse(S) is the following 4x4 matrix:
	# 		| -0.15385 | -0.15385 | -0.28205 | -0.53846 |
	# 		| -0.07692 | 0.12308 | 0.02564 | 0.03077 |
	# 		| 0.35897 | 0.35897 | 0.43590 | 0.92308 |
	# 		| -0.69231 | -0.69231 | -0.76923 | -1.92308 |
	#
	# Scenario: Calculating the inverse of a third matrix
	# 	Given the following 4x4 matrix T:
	# 		| 9 | 3 | 0 | 9 |
	# 		| -5 | -2 | -6 | -3 |
	# 		| -4 | 9 | 6 | 4 |
	# 		| -7 | 6 | 6 | 2 |
	# 	Then inverse(T) is the following 4x4 matrix:
	# 		| -0.04074 | -0.07778 | 0.14444 | -0.22222 |
	# 		| -0.07778 | 0.03333 | 0.36667 | -0.33333 |
	# 		| -0.02901 | -0.14630 | -0.10926 | 0.12963 |
	# 		| 0.17778 | 0.06667 | -0.26667 | 0.33333 |
	#
	# Scenario: Multiplying a product by its inverse
	# 	Given the following 4x4 matrix U:
	# 		| 3 | -9 | 7 | 3 |
	# 		| 3 | -8 | 2 | -9 |
	# 		| -4 | 4 | 4 | 1 |
	# 		| -6 | 5 | -1 | 1 |
	# 	And the following 4x4 matrix V:
	# 		| 8 | 2 | 2 | 2 |
	# 		| 3 | -1 | 7 | 0 |
	# 		| 7 | 0 | 5 | 4 |
	# 		| 6 | -2 | 0 | 5 |
	# 	And W ← U * V
	# 	Then W * inverse(V) = U
