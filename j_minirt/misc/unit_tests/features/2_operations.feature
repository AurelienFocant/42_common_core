Feature: common tuple operations

	Scenario: Adding two tuples
		Given a1 = creat_tuple(3, -2, 5, 1)
		And a2 = creat_tuple(-2, 3, 1, 0)
		Then a1 + a2 == creat_tuple(1, 1, 6, 1)

	Scenario: Subtracting two points
		Given p1 = point(3, 2, 1)
		And p2 = point(5, 6, 7)
		Then p1 - p2 = vector(-2, -4, -6)

	Scenario: Substracting a vector from a point
		Given p = point(3, 2, 1)
		And v = vector(5, 6, 7)
		Then p - v = point(-2, -4, -6)

	Scenario: Substracting two vectors
		Given v1 = vector(3, 2, 1)
		And v2 = vector(5, 6, 7)
		Then v1 - v2 = vector(-2, -4, -6)
	
	Scenario: Substracting a vector from the zero vector
		Given zero = vector(0, 0, 0)
		And v = vector(1, -2, 3)
		Then zero - v = vector(-1, 2, -3)

	Scenario: Negating a tuple
		Given a = tuple(1, -2, 3, -4)
		Then -a = tuple(-1, 2, -3, 4)

	Scenario: Multiplying a tuple by a scalar
		Given a = tuple(1, -2, 3, -4)
		Then a * 3,5 = tuple(3.5, -7, 10.5, -14)

	Scenario: Multiplying a tuple by a fraction
		Given a = tuple(1, -2, 3, -4)
		Then a * 0,5 = tuple(0.5, -1, 1.5, -2)

	Scenario: Dividing a tuple by a scalar
		Given a = tuple(1, -2, 3, -4)
		Then a / 2 = tuple(0.5, -1, 1.5, -2)
