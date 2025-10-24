# Feature: matrices are everywhere
#
# 	Scenario: constructing and inspecting a 4x4 matrix
# 		Given the following 4x4 matrix M:
# 			| 1	 | 2  | 3  | 4  |
# 			| 5  | 6  | 7  | 8  |
# 			| 9  | 10 | 11 | 12 |
# 			| 13 | 14 | 15 | 16 |
# 		Then M[0,0] == 1
# 		And M[0,3] == 4
# 		And M[1,0] == 5
# 		And M[1,2] == 7
# 		And M[2,2] == 11
# 		And M[3,0] == 13
# 		And M[3,2] == 15
#
# 	Scenario: a 2x2 matrix ought to be representable
# 		Given the following 2x2 matrix M:
# 			| -3 |  5 |
# 			|  1 | -2 |
# 		Then M[0, 0] == -3
# 		And M[0, 1] == 5
# 		And M[1, 0] == 1
# 		And M[1, 1] == -2
#
# 	Scenario: a 3x3 matrix ought to be representable
# 		Given the following 3x3 matrix M:
# 			| -3 |  5 |  0 |
# 			|  1 | -2 | -7 |
# 			|  0 |  1 |  1 |
# 		Then M[0, 0] == -3
# 		And M[1, 1] == -2
# 		And M[2, 2] == 1
#
# 	Scenario: matrix equality with another matrices
# 		Given the following matrix A:
# 			| 1 | 2 | 3 | 4 |
# 			| 5 | 6 | 7 | 8 |
# 			| 9 | 8 | 7 | 6 |
# 			| 5 | 4 | 3 | 2 |
# 		And the following matrix B:
# 			| 1 | 2 | 3 | 4 |
# 			| 5 | 6 | 7 | 8 |
# 			| 9 | 8 | 7 | 6 |
# 			| 5 | 4 | 3 | 2 |
# 		Then A = B
#
# 	Scenario: matrix equality with another matrices
# 		Given the following matrix A:
# 			| 1 | 2 | 3 | 4 |
# 			| 5 | 6 | 7 | 8 |
# 			| 9 | 8 | 7 | 6 |
# 			| 5 | 4 | 3 | 2 |
# 		And the following matrix B:
# 			| 1 | 2 | 3 | 1 |
# 			| 5 | 6 | 7 | 8 |
# 			| 9 | 8 | 7 | 6 |
# 			| 5 | 4 | 3 | 2 |
# 		Then A != B
