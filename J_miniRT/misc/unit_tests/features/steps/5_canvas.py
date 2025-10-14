from behave import given, then, when
from assertpy import assert_that
from numpy import sqrt


from utils import lib, Tuple, are_tuples_equal, VECTOR, POINT, EPSILON


# @given("c = canvas(10, 20)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Given c = canvas(10, 20)")
#
#
# @then("c.width == 10")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then c.width == 10")
#
#
# @then("c.height == 20")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then c.height == 20")
#
#
# @then("every pixel of c ic color(0, 0, 0)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then every pixel of c ic color(0, 0, 0)")
#
#
# @given("red = color(1, 0, 0)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Given red = color(1, 0, 0)")
#
#
# @when("write_pixel(c, 2, 3, red)")
# def step_impl(context):
#     raise NotImplementedError("STEP: When write_pixel(c, 2, 3, red)")
#
#
# @then("pixel_at(c, 2, 3) = red")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then pixel_at(c, 2, 3) = red")


# @given("c = canvas(5, 3)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Given c = canvas(5, 3)")
#
#
# @when("ppm = canvas_to_ppm(c)")
# def step_impl(context):
#     raise NotImplementedError("STEP: When ppm = canvas_to_ppm(c)")
#
#
# @then("lines 1-3 of ppm are")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then lines 1-3 of ppm are")
#
#
# @given("c1 = color(1.5, 0, 0)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Given c1 = color(1.5, 0, 0)")
#
#
# @given("c2 = color(0, 0.5, 0)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Given c2 = color(0, 0.5, 0)")
#
#
# @given("c3 = color(-0.5, 0, 1)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Given c3 = color(-0.5, 0, 1)")
#
#
# @when("write_pixel(c, 0, 0, c1)")
# def step_impl(context):
#     raise NotImplementedError("STEP: When write_pixel(c, 0, 0, c1)")
#
#
# @when("write_pixel(c, 2, 1, c2)")
# def step_impl(context):
#     raise NotImplementedError("STEP: When write_pixel(c, 2, 1, c2)")
#
#
# @when("write_pixel(c, 4, 2, c3)")
# def step_impl(context):
#     raise NotImplementedError("STEP: When write_pixel(c, 4, 2, c3)")
#
#
# @then("lines 4-6 of ppm are")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then lines 4-6 of ppm are")
#
#
# @given("c = canvas(10, 2)")
# def step_impl(context):
#     raise NotImplementedError("STEP: Given c = canvas(10, 2)")
#
#
# @when("everu pixel of c is set to color(1, 0.8, 0.6)")
# def step_impl(context):
#     raise NotImplementedError("STEP: When everu pixel of c is set to color(1, 0.8, 0.6)")
#
#
# @then("lines of 4-7 of ppm are")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then lines of 4-7 of ppm are")
#
#
# @then("ppm ends with a newline character")
# def step_impl(context):
#     raise NotImplementedError("STEP: Then ppm ends with a newline character")
