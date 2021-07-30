# fact 1
# tmp task : scalar product of 2 strings
# import copy
# import functools

#
# linea = [1, 2, 3, 4, 5]
# lineb = [6, 7, 8, 9, 10]
# print(*zip(linea, lineb))  # noy only lists, but all iterables
# print(
#     *map(
#         lambda pair: pair[0] * pair[1],
#         zip(linea, lineb)
#     )
# )
# print(
#     functools.reduce(
#         lambda x, y: x + y,
#         map(
#             lambda pair: pair[0] * pair[1],
#             zip(linea, lineb)
#         )
#     )
# )


# fact 2 : matrix mul
# m1 = [[1, 2], [2, 1]]
# m2 = [[3, 2], [-10, 0]]
# print(
#     *list(
#         map(
#             lambda line_1:
#                 list(
#                     map(
#                         lambda line_2: functools.reduce(
#                             lambda x, y: x + y,
#                             map(
#                                 lambda pair: pair[0] * pair[1],
#                                 zip(line_1, line_2)
#                             )
#                         ),
#                         zip(*m2)
#                     )
#                 ),
#             m1
#         )
#     )
# )

import copy
import functools


def deteminant(matrix):
    if len(matrix) == 2:
        a, b = matrix[0][0], matrix[0][1]
        c, d = matrix[1][0], matrix[1][1]
        return a * d - b * c
    else:
        det = 0
        for i in range(len(matrix)):
            tmp_matrix = copy.deepcopy(matrix)
            tmp_matrix.pop(0)
            for line in tmp_matrix:
                line.pop(i)
            tmp_det = deteminant(tmp_matrix)
            det += ((-1) ** i) * tmp_det * matrix[0][i]
        return det
# print(
#     deteminant(
#         [
#             [1, 0, 0],
#             [0, 1, 0],
#             [0, 0, 1]
#
#         ]
#     )
# )
# print(
#     deteminant(
#         [
#             [1, 1, 1],
#             [0, 1, 0],
#             [0, 1, 4]
#
#         ]
#     )
# )
# print(
#     deteminant(
#         [
#             [1, 2, 3, 4],
#             [5, 6, 7, 8],
#             [9, 10, 11, 12],
#             [13, 14, 15, 16]
#         ]
#     )
# )
# print(
#     deteminant(
#         [
#             [1, 2],
#             [2, 1]
#         ]
#     )
# )


A = matr = [
    [1, 1, 1],
    [1, 2, 3],
    [4, 1, 2]
]
b = [1, 1, 1]
coef = copy.deepcopy(b)
isNull = lambda x: -1e-7 < x < 1e-7
