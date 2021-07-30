import copy
import functools
from sys import stdin


class MatrixError(BaseException):
    def __init__(self, matrix1, matrix2):
        self.matrix1 = matrix1
        self.matrix2 = matrix2


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


def solve_gauss(A, b):  # Ax = b = free_values
    matr = copy.deepcopy(A)
    coef = copy.deepcopy(b)
    eps = 1e-7
    for i in range(0, len(b)):  # get diagonal matrix
        j = i + 1
        if -eps < matr[i][i] < eps:
            while j < len(b) and -eps < matr[j][i] < eps:
                j += 1
            if j == len(b):
                raise Exception(A, b)
            matr[i], matr[j] = matr[j], matr[i]
        while j < len(b):
            if -eps < matr[j][i] < eps:
                j += 1
                continue
            k = matr[j][i] / matr[i][i]
            matr[j] = list(
                map(
                    lambda pair: pair[1] - k * pair[0],
                    zip(matr[i], matr[j])
                )
            )
            coef[j] -= coef[i] * k
            j += 1
    x = []
    for i in range(len(b) - 1, -1, -1):
        tmp_sum = 0
        for j in range(i + 1, len(b)):
            tmp_sum += matr[i][j] * x[len(x)-1 - (j - (i+1))]
        new_x = (coef[i] - tmp_sum) / matr[i][i]
        x.append(new_x)
    x.reverse()
    return x


class Matrix:
    def __init__(self, matr=None):
        if matr is None:
            matr = list(list())
        self.matr = list(list())
        for line in matr:
            self.matr.append(line.copy())  # copy of line

    def solve_cramer(self, free_values):  # solve Ax = b
        A = self.matr
        b = free_values
        x = []
        det_a = deteminant(A)
        if det_a == 0:
            raise Exception(A, b)
        for i in range(len(b)):
            a_i = copy.deepcopy(A)
            for j in range(len(b)):
                a_i[j][i] = b[j]
            det_i = deteminant(a_i)
            x.append(det_i / det_a)
        return x

    def solve(self, free_values):  # Ax = b = free_values
        return solve_gauss(self.matr, free_values)

    @staticmethod
    def transposed(matrix):
        # result = matrix  # wrong way : result is reference to matrix
        result = Matrix()
        result.matr = list(list())
        for line in matrix.matr:
            result.matr.append(line.copy())  # copy of line
        return result.transpose()

    def transpose(self):
        tmp = Matrix()
        tmp.matr = list(map(list, zip(*self.matr)))
        self.matr.clear()
        for line in tmp.matr:
            self.matr.append(line.copy())  # copy of line
        return self

    def __add__(self, other):
        if not isinstance(other, Matrix) or self.size() != other.size():
            raise MatrixError(self, other)
        res_matr = Matrix()
        res_matr.matr = list(list())
        for line in self.matr:
            res_matr.matr.append(line.copy())  # copy of line
        for i in range(len(res_matr.matr)):
            for j in range(len(res_matr.matr[0])):
                res_matr.matr[i][j] += other.matr[i][j]
        return res_matr

    def __mul__(self, other):  # other = int or float
        res_matr = Matrix()
        res_matr.matr = list(list())
        if isinstance(other, Matrix):
            if self.size()[1] != other.size()[0]:
                raise MatrixError(self, other)
            m1 = self.matr
            m2 = other.matr
            res_matr.matr = list(
                map(
                    lambda line_1:
                    list(
                        map(
                            lambda line_2: functools.reduce(
                                lambda x, y: x + y,
                                map(
                                    lambda pair: pair[0] * pair[1],
                                    zip(line_1, line_2)
                                )
                            ),
                            zip(*m2)
                        )
                    ),
                    m1
                )
            )

        elif isinstance(other, int) or isinstance(other, float):
            res_matr.matr = list(
                map(
                    lambda line: list(map(lambda x: x * other, line)),
                    self.matr
                )
            )
        else:
            raise MatrixError(self, other)
        return res_matr

    __rmul__ = __mul__

    def __str__(self):
        result = ''
        for line in self.matr:
            curline = ''
            for num in line:
                curline += str(num) + '\t'
            if curline[-1] == '\t':
                curline = curline[:-1]
            result += curline + '\n'
        if result[-1] == '\n':
            result = result[:-1]
        return result

    def size(self):
        rows, cols = len(self.matr), 0
        if rows > 0:
            cols = len(self.matr[0])
        return rows, cols


exec(stdin.read())
