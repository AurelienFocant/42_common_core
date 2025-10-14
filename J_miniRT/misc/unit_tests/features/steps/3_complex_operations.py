from behave import given, then, when
from assertpy import assert_that
from numpy import sqrt


from utils import lib, Tuple, are_tuples_equal, VECTOR, POINT, EPSILON


# MAGNITUDE
@given("v = vector(1, 0, 0)")
def vec100(context):
    context.v = lib.vector(1, 0, 0)


@then("magnitude(v) == 1")
def mag1(context):
    res = lib.magnitude(context.v)
    assert_that(res).is_equal_to(1)


@given("v = vector(0, 1, 0)")
def vec010(context):
    context.v = lib.vector(0, 1, 0)


@given("v = vector(0, 0, 1)")
def vec001(context):
    context.v = lib.vector(0, 0, 1)


@given("v = vector(1, 2, 3)")
def vec123(context):
    context.v = lib.vector(1, 2, 3)


@then("magnitude(v) == sqrt(14)")
def mag14(context):
    res = lib.magnitude(context.v)
    assert_that(res).is_close_to(sqrt(14), EPSILON)


@given("v = vector(-1, -2, -3)")
def vecn1n2n3(context):
    context.v = lib.vector(-1, -2, -3)


# Normalization

@given("v = vector(4, 0, 0)")
def vec400(context):
    context.v = lib.vector(4, 0, 0)


@then("normalize(v) == vector(1, 0, 0)")
def norm1(context):
    v2 = lib.normalize_tuple(context.v)
    res = are_tuples_equal(v2, Tuple(1, 0, 0, VECTOR))
    assert_that(res).is_true()


@then("normalize(v) =~ vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14))")
def norm2(context):
    v2 = lib.normalize_tuple(context.v)
    res = are_tuples_equal(v2, Tuple(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)))
    assert_that(res).is_true()


@when("norm = normalize(v)")
def norm(context):
    context.norm = lib.normalize_tuple(context.v)


@then("magnitude(norm) = 1")
def magn_norm(context):
    res = lib.magnitude(context.norm)
    assert_that(res).is_close_to(1, EPSILON)


# DOT PRODUCT
@given("b = vector(2, 3, 4)")
def vec234(context):
    context.b = lib.vector(2, 3, 4)


@then("dot(v, b) == 20")
def dot_product(context):
    prod = lib.dot_product(context.v, context.b)
    print(prod)


@then("cross(v, b) == vector(-1, 2, -1)")
def cross1(context):
    cross = lib.cross_product(context.v, context.b)
    res = are_tuples_equal(cross, Tuple(-1, 2, -1, VECTOR))
    print(cross.x)
    assert_that(res).is_true()


@then("cross(b, v) == vector(1, -2, 1)")
def cross2(context):
    cross = lib.cross_product(context.b, context.v)
    res = are_tuples_equal(cross, Tuple(1, -2, 1, VECTOR))
    assert_that(res).is_true()
