from behave import given, then
from assertpy import assert_that


from utils import lib, Tuple, are_tuples_equal, VECTOR, POINT


# Adding two tuples
@given("a1 = creat_tuple(3, -2, 5, 1)")
def tuple1(context):
    context.a1 = lib.creat_tuple(3, -2, 5, 1)


@given("a2 = creat_tuple(-2, 3, 1, 0)")
def tuple2(context):
    context.a2 = lib.creat_tuple(-2, 3, 1, 0)


@then("a1 + a2 == creat_tuple(1, 1, 6, 1)")
def add_tuple(context):
    a3 = lib.add_tuple(context.a1, context.a2)
    assert_that(are_tuples_equal(a3, Tuple(1, 1, 6, 1))).is_true()


# Substracting two points
@given("p1 = point(3, 2, 1)")
def point1(context):
    context.p1 = lib.point(3, 2, 1)


@given("p2 = point(5, 6, 7)")
def point2(context):
    context.p2 = lib.point(5, 6, 7)


@then("p1 - p2 = vector(-2, -4, -6)")
def sub_tuple(context):
    p1 = context.p1
    p2 = context.p2
    p3 = lib.sub_tuple(p1, p2)
    res = are_tuples_equal(p3, Tuple(-2, -4, -6, VECTOR))
    assert_that(res).is_true()


# Substracting a vector from a point
@given("p = point(3, 2, 1)")
def point3(context):
    context.p = lib.point(3, 2, 1)


@given("v = vector(5, 6, 7)")
def vec(context):
    context.v = lib.vector(5, 6, 7)


@then("p - v = point(-2, -4, -6)")
def sub_point_vec(context):
    p2 = lib.sub_tuple(context.p, context.v)
    res = are_tuples_equal(p2, Tuple(-2, -4, -6, POINT))
    assert_that(res).is_true()


# Substracting two vectors
@given("v1 = vector(3, 2, 1)")
def vec1(context):
    context.v1 = lib.vector(3, 2, 1)


@given("v2 = vector(5, 6, 7)")
def vec2(context):
    context.v2 = lib.vector(5, 6, 7)


@then("v1 - v2 = vector(-2, -4, -6)")
def sub_two_vec(context):
    v3 = lib.sub_tuple(context.v1, context.v2)
    res = are_tuples_equal(v3, Tuple(-2, -4, -6, VECTOR))
    assert_that(res).is_true()


# Substracting a vector from the zero vector
@given("zero = vector(0, 0, 0)")
def vec_zero(context):
    context.zero = lib.vector(0, 0, 0)


@given("v = vector(1, -2, 3)")
def vec4(context):
    context.v4 = lib.vector(1, -2, 3)


@then("zero - v = vector(-1, 2, -3)")
def sub_vec_zero(context):
    v5 = lib.sub_tuple(context.zero, context.v4)
    res = are_tuples_equal(v5, Tuple(-1, 2, -3, VECTOR))
    assert_that(res).is_true()


@given('a = tuple(1, -2, 3, -4)')
def mk_tuple(context):
    context.a = lib.creat_tuple(1, -2, 3, -4)


@then('-a = tuple(-1, 2, -3, 4)')
def negate_tuple(context):
    neg_a = lib.negatif_tuple(context.a)
    res = are_tuples_equal(neg_a, Tuple(-1, 2, -3, 4))
    assert_that(res).is_true()


# Multiplying a tuple by a scalar
@then(u'a * 3,5 = tuple(3.5, -7, 10.5, -14)')
def scalar_mult(context):
    mult_a = lib.multi_tuple(context.a, 3.5)
    res = are_tuples_equal(mult_a, Tuple(3.5, -7, 10.5, -14))
    assert_that(res).is_true()


# Multiplying a tuple by a fraction
@then(u'a * 0,5 = tuple(0.5, -1, 1.5, -2)')
def scalar_mult_frac(context):
    mult_a = lib.multi_tuple(context.a, 0.5)
    res = are_tuples_equal(mult_a, Tuple(0.5, -1, 1.5, -2))
    assert_that(res).is_true()


# Dividing a tuple by a scalar
@then(u'a / 2 = tuple(0.5, -1, 1.5, -2)')
def scalar_div(context):
    mult_a = lib.div_tuple(context.a, 2)
    res = are_tuples_equal(mult_a, Tuple(0.5, -1, 1.5, -2))
    assert_that(res).is_true()
