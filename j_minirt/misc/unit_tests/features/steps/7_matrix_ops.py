from behave import given, then, when
from assertpy import assert_that
from numpy import sqrt


from utils import *

@given("the following matrix A")
def mat4_A(context):
    context.mat4_A = build_mat4([
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 8, 7, 6],
        [5, 4, 3, 2]
        ])


@given("the following matrix B")
def mat4_B(context):
    context.mat4_B = build_mat4([
        [-2, 1, 2, 3],
        [3, 2, 1, -1],
        [4, 3, 6, 5],
        [1, 2, 7, 8]
        ])


@then("A * B is the following 4x4 matrix")
def mat_A_mult_mat_B(context):
    lib.creat_identity_matrix(mat4)
    # mat4_C = lib.multi_mat4(context.mat4_A, context.mat4_B)
    # mat4_D = build_mat4([
    #     [20, 22, 50, 48],
    #     [44, 54, 114, 108],
    #     [40, 58, 110, 102],
    #     [16, 26, 46, 42]
    #     ])
    print(mat4_C[0][0])
    # for row in mat4_C:
    #     print([row[i] for i in range(4)])
    # res = are_matrices_equal(mat4_C, mat4_D)
    assert_that(res).is_true()


# @given(u'the following matrix Z')
# def mat4_Z(context):
#     context.mat4_Z = build_mat4([
#         [1, 2, 3, 4],
#         [2, 4, 4, 2],
#         [8, 6, 4, 1],
#         [0, 0, 0, 1]
#         ])
#
#
# @given(u'b ← tuple(1, 2, 3, 1)')
# def tuple1(context):
#     context.tuple_b = lib.creat_tuple(1, 2, 3, 1)
#
#
# @then(u'Z * b = tuple(18, 24, 33, 1)')
# def mat_mult_tuple(context):
#     tuple_res = lib.creat_tuple(18, 24, 33, 1)
#     lib.multi_mat4_tuple(context.mat4_Z, context.tuple_b, ctypes.byref(tuple_res))
#     res = are_tuples_equal(Tuple(18, 24, 33, 1), tuple_res)
#     assert_that(res).is_true()
#
#
# @given(u'the following matrix C')
# def mat_c(context):
#     context.mat4_C = build_mat4([
#         [0, 1, 2, 4],
#         [1, 2, 4, 8],
#         [2, 4, 8, 16],
#         [4, 8, 16, 32]
#         ])
#
#
# @then(u'C * identity_matrix = C')
# def identity1(context):
#     id = build_zeroed_mat4()
#     lib.creat_identity_matrix(id)
#     mat_res = build_zeroed_mat4()
#     lib.multi_mat4(context.mat4_C, id, mat_res)
#     res = are_matrices_equal(context.mat4_C, mat_res)
#     assert_that(res).is_true()
#
#
# @given(u'a ← tuple(1, 2, 3, 4)')
# def step_impl(context):
#     raise NotImplementedError(u'STEP: Given a ← tuple(1, 2, 3, 4)')
#
#
# @then(u'identity_matrix * a = a')
# def step_impl(context):
#     raise NotImplementedError(u'STEP: Then identity_matrix * a = a')
