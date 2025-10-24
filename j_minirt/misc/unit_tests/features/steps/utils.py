import ctypes
import os

lib = ctypes.CDLL(os.getcwd() + "/test_lib/test_lib.so")


class Tuple(ctypes.Structure):
    _fields_ = [('x', ctypes.c_float),
                ('y', ctypes.c_float),
                ('z', ctypes.c_float),
                ('w', ctypes.c_float)]


Mat4Row = ctypes.c_float * 4
Mat4 = Mat4Row * 4


lib.creat_tuple.restype = Tuple
lib.creat_tuple.argtypes = [ctypes.c_float, ctypes.c_float,
                            ctypes.c_float, ctypes.c_float]
lib.point.restype = Tuple
lib.point.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]
lib.vector.restype = Tuple
lib.vector.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]

lib.add_tuple.restype = Tuple
lib.add_tuple.argtypes = [Tuple, Tuple]

lib.sub_tuple.restype = Tuple
lib.sub_tuple.argtypes = [Tuple, Tuple]

lib.negatif_tuple.restype = Tuple
lib.negatif_tuple.argtype = Tuple

lib.multi_tuple.restype = Tuple
lib.multi_tuple.argtypes = [Tuple, ctypes.c_float]

lib.div_tuple.restype = Tuple
lib.div_tuple.argtypes = [Tuple, ctypes.c_float]

lib.magnitude.restype = ctypes.c_float
lib.magnitude.argtype = Tuple

lib.normalize_tuple.restype = Tuple
lib.normalize_tuple.argtype = Tuple

lib.dot_product.restype = ctypes.c_float
lib.dot_product.argtypes = [Tuple, Tuple]

lib.cross_product.restype = Tuple
lib.cross_product.argtypes = [Tuple, Tuple]

lib.color.restype = Tuple
lib.color.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]

lib.add_colors.restype = Tuple
lib.add_colors.argtypes = [Tuple, Tuple]

lib.sub_colors.restype = Tuple
lib.sub_colors.argtypes = [Tuple, Tuple]

lib.scalar_multi_color.restype = Tuple
lib.scalar_multi_color.argtypes = [ctypes.c_float, Tuple]

lib.blend_colors.restype = Tuple
lib.blend_colors.argtypes = [Tuple, Tuple]

lib.multi_mat4.restype = Mat4
lib.multi_mat4.argtypes = [Mat4, Mat4]

lib.multi_mat4_tuple.restype = Tuple
lib.multi_mat4_tuple.argtypes = [Mat4, Tuple]

lib.creat_identity_matrix.restype = Mat4
lib.creat_identity_matrix.argtype = None

EPSILON = 1e-5

VECTOR = 0.0
POINT = 1.0


def is_float_equal(a, b):
    return abs(a - b) < EPSILON


def are_tuples_equal(t1, t2):
    return (
        is_float_equal(t1.x, t2.x) and
        is_float_equal(t1.y, t2.y) and
        is_float_equal(t1.z, t2.z) and
        is_float_equal(t1.w, t2.w)
    )


def are_matrices_equal(m1, m2):
    for y in range(4):
        for x in range(4):
            if not is_float_equal(m1[y][x], m2[y][x]):
                return False
    return True


def build_zeroed_mat4():
    return Mat4(*[Mat4Row(0.0, 0.0, 0.0, 0.0) for _ in range(4)])

def build_mat4(rows):
    return Mat4(*(Mat4Row(*row) for row in rows))
