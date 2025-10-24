from behave import given, then, when
from assertpy import assert_that

from utils import *

@given('a = tuple(4.3, -4.2, 3.1, 1.0)')
def make_tuple_point(context):
    context.data = lib.creat_tuple(4.3, -4.2, 3.1, 1.0)


@given('a = tuple(4.3, -4.2, 3.1, 0)')
def make_tuple_vec(context):
    context.data = lib.creat_tuple(4.3, -4.2, 3.1, 0)


@then('a.x == 4.3')
def verif_x(context):
    assert_that(context.data.x).is_close_to(4.3, 1e-5)


@then('a.y == -4.2')
def verif_y(context):
    assert_that(context.data.y).is_close_to(-4.2, 1e-5)


@then('a.z == 3.1')
def verif_z(context):
    assert_that(context.data.z).is_close_to(3.1, 1e-5)


@then('a.w == 1.0')
def verif_w_point(context):
    assert_that(context.data.w).is_equal_to(1.0)


@then('a.w == 0')
def verif_w_vec(context):
    assert_that(context.data.w).is_equal_to(0)


@then('a is a point')
def is_point(context):
    assert_that(context.data.w).is_equal_to(1.0)


@then('a is not a point')
def is_not_point(context):
    assert_that(context.data.w).is_not_equal_to(1.0)


@then('a is a vector')
def is_vec(context):
    assert_that(context.data.w).is_equal_to(0)


@then('a is not a vector')
def is_not_vec(context):
    assert_that(context.data.w).is_not_equal_to(0)


@given('p = create_point(4, -4, 3)')
def create_point(context):
    context.point = lib.point(4, -4, 3)


@then('p == tuple(4, -4, 3, 1)')
def check_point(context):
    expected = Tuple(4, -4, 3, 1)
    assert_that(context.point.x).is_close_to(expected.x, 1e-5)
    assert_that(context.point.y).is_close_to(expected.y, 1e-5)
    assert_that(context.point.z).is_close_to(expected.z, 1e-5)
    assert_that(context.point.w).is_close_to(expected.w, 1e-5)


@given('v = create_vector(4, -4, 3)')
def create_vector(context):
    context.vector = lib.vector(4, -4, 3)


@then('v == tuple(4, -4, 3, 0)')
def check_vector(context):
    expected = Tuple(4, -4, 3, 0)
    assert_that(context.vector.x).is_close_to(expected.x, 1e-5)
    assert_that(context.vector.y).is_close_to(expected.y, 1e-5)
    assert_that(context.vector.z).is_close_to(expected.z, 1e-5)
    assert_that(context.vector.w).is_close_to(expected.w, 1e-5)
