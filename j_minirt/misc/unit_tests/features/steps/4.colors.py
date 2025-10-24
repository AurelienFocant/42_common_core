from behave import given, then, when
from assertpy import assert_that
from numpy import sqrt


from utils import lib, Tuple, are_tuples_equal, VECTOR, POINT, EPSILON


@given("c = color(-0.5, 0.4, 1.7)")
def color(context):
    context.c = lib.color(-0.5, 0.4, 1.7)


@then("c.red == -0.5")
def check_red(context):
    assert_that(context.c.x).is_close_to(-0.5, EPSILON)


@then("c.green = 0.4")
def check_green(context):
    assert_that(context.c.y).is_close_to(0.4, EPSILON)


@then("c.blue = 1.7")
def check_blue(context):
    assert_that(context.c.z).is_close_to(1.7, EPSILON)


@given("c1 = color(0.9, 0.6, 0.75)")
def c1(context):
    context.c1 = lib.color(0.9, 0.6, 0.75)


@given("c2 = color(0.7, 0.1, 0.25)")
def c2(context):
    context.c2 = lib.color(0.7, 0.1, 0.25)


@then("c1 + 2 = color(1.6, 0.7, 1.0)")
def add_c(context):
    add_c = lib.add_colors(context.c1, context.c2)
    res = are_tuples_equal(add_c, Tuple(1.6, 0.7, 1.0, 0))
    assert_that(res).is_true()


@then("c1 - c2 = color(0.2, 0.5, 0.5)")
def sub_c(context):
    sub_c = lib.sub_colors(context.c1, context.c2)
    res = are_tuples_equal(sub_c, Tuple(0.2, 0.5, 0.5, 0))
    assert_that(res).is_true()


@given("c3 = color(0.2, 0.3, 0.4)")
def c3(context):
    context.c3 = lib.color(0.2, 0.3, 0.4)


@then("c3 * 2 = color(0.4, 0.6, 0.8)")
def scal_mult_col(context):
    mu_c = lib.scalar_multi_color(2, context.c3)
    res = are_tuples_equal(mu_c, Tuple(0.4, 0.6, 0.8, VECTOR))
    assert_that(res).is_true()


@given("c4 = color(1, 0.2, 0.4)")
def c4(context):
    context.c4 = lib.color(1, 0.2, 0.4)


@given("c5 = color(0.9, 1, 0.1)")
def c5(context):
    context.c5 = lib.color(0.9, 1, 0.1)


@then("c4 * c5 = color(0.9, 0.2, 0.04)")
def blend_col(context):
    bl_c = lib.blend_colors(context.c4, context.c5)
    res = are_tuples_equal(bl_c, Tuple(0.9, 0.2, 0.04))
    assert_that(res).is_true()
