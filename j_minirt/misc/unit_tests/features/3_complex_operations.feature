Feature: complex operations on tuples


	# MAGNITUDE
	Scenario: Computing the magnitude of vector(1, 0, 0)
		Given v = vector(1, 0, 0)
		Then magnitude(v) == 1

	Scenario: Computing the magnitude of vector(0, 1, 0)
		Given v = vector(0, 1, 0)
		Then magnitude(v) == 1

	Scenario: Computing the magnitude of vector(0, 0, 1)
		Given v = vector(0, 0, 1)
		Then magnitude(v) == 1

	Scenario: Computing the magnitude of vector(1, 2, 3)
		Given v = vector(1, 2, 3)
		Then magnitude(v) == sqrt(14)

	Scenario: Computing the magnitude of vector(-1, -2, -3)
		Given v = vector(-1, -2, -3)
		Then magnitude(v) == sqrt(14)


	# NORMALIZATION
	Scenario: Normalizing vector(4, 0, 0) gives (1, 0, 0)
		Given v = vector(4, 0, 0)
		Then normalize(v) == vector(1, 0, 0)

	Scenario: Normalizing vector(1, 2, 3)
		Given v = vector(1, 2, 3)
		Then normalize(v) =~ vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14))
	
	Scenario: the magnitude of a normalized vector
		Given v = vector(1, 2, 3)
		When norm = normalize(v)
		Then magnitude(norm) = 1


	# DOT PRODUCT
	Scenario: The dot product of two tuples
		Given v = vector(1, 2, 3)
		And b = vector(2, 3, 4)
		Then dot(v, b) == 20

	# CROSS PRODUCT
	Scenario: The cross product of two vectors
		Given v = vector(1, 2, 3)
		And b = vector(2, 3, 4)
		Then cross(v, b) == vector(-1, 2, -1)
		And cross(b, v) == vector(1, -2, 1)
