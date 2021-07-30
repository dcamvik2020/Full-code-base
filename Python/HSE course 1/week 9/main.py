# THEORY 1 : OOP
# we can spend some resources for convenient programmer's work
# ----> OOP ---> we can create tree-like structures with inheritance
#                we can use parent's properties (circle \in figures --> are)
# inheritance from 2 classes is very strange and difficult
# OOP principles :
# Encapsulation (data, working methods together)
# Inheritance   (new type basing on old type with part pr full set of properties)
# Polymorphism  (same methods-interface for working with different types)
# Class = members, methods ---> objects = variables of this type
# Static members = members for classes, not objects, same for all objects
#                  objects can communicate with each other
#                  Class Ball, static cnt_all_balles, create ball --> cnt++

# THEORY 2 : class of complex numbers
# class Complex:
#     some_static_variable = 4
#
#     def __init__(self, re=0, im=0):  # self = 'this' in C++
#         self.re = re  # member re appears only for current object
#         self.im = im  # member im appears only for current object

# a = Complex()
# b = Complex(1)
# c = Complex(1, 2)
#
# print(b.re, b.im)
# print(c.re, c.im)
#
# d = Complex()
# d.re = 2              # like in structures
# d.im = 3              # constructors look better...
# print(d.re, d.im)


# Task 1 : Matrix class
# constructor from list of lists (all lists not empty, same size)
#           it should COPY content of lists (change list --> matrix same)
# method __str__ : matrix --> to string : elems in one line sep='\t',
#         strings --> sep='\n', after each line NOT '\t', at the end NOT '\n'
# method size() with no arguments returns tuple (rows_number, columns_number)
# test :
# m = Matrix([[1, 0], [0, 1]])
# print(m)
# m = Matrix([[2, 0, 0], [0, 1, 10000]])
# print(m)
# m = Matrix([[-10, 20, 50, 2443], [-5235, 12, 4324, 4234]])
# print(m)
# from sys import stdin    # before program
# exec(stdin.read())       # after program
# class Matrix:
#     def __init__(self, matr=None):
#         if matr is None:
#             matr = list(list())
#         self.matr = list(list())
#         for line in matr:
#             self.matr.append(line.copy())
#
#     def __str__(self):
#         result = ''
#         for line in self.matr:
#             curline = ''
#             for num in line:
#                 curline += str(num) + '\t'
#             if curline[-1] == '\t':
#                 curline = curline[:-1]
#             result += curline + '\n'
#         if result[-1] == '\n':
#             result = result[:-1]
#         return result
#
#     def size(self):
#         rows, cols = len(self.matr), 0
#         if rows > 0:
#             cols = len(self.matr[0])
#         return rows, cols


# THEORY 3:
# class Complex:
#     some_static_variable = 4
#
#     def __init__(self, re=0, im=0):  # self = 'this' in C++
#         self.re = re  # member re appears only for current object
#         self.im = im  # member im appears only for current object
#
#     def __str__(self):  # when we call str(obj) it is called
#         return str(self.re) + ' + ' + str(self.im) + 'i'
#
#     def __add__(self, other):  # returns NEW object  !!!
#         result = Complex(self.re + other.re, self.im + other.im)
#         return result
#
#     def __mul__(self, other):
#         re = self.re * other.re - self.im * other.im  # local var
#         im = self.re * other.im + self.im * other.re  # local var
#         return Complex(re, im)
#
#
# a = Complex(2, 3)
# print(a)         # 2 + 3i : calls __str__
# print(str(a))    # 2 + 3i : calls __str__
# b = Complex(1, 2)
# print(a + b)     # <---> a.__add__(b)
# c = 5
# # print(b + c)  # Error : int isn't complex
# print(b + Complex(c))  # OK
# print(a * b)


# Task 2 : Matrix add, mul
# add 3 methods not modifying matrix:
#       __add__ (sum matr),
#       __mul__ (by number : int or float)
#       __rmul__ = __mul__ (code in class it)
#       __rmul__ is called when matrix is right operand
# from sys import stdin    # before program
# exec(stdin.read())       # after program
# class Matrix:
#     def __init__(self, matr=None):
#         if matr is None:
#             matr = list(list())
#         self.matr = list(list())
#         for line in matr:
#             self.matr.append(line.copy())
#
#     def __add__(self, other):
#         res_matr = Matrix()
#         res_matr.matr = list(list())
#         for line in self.matr:
#             res_matr.matr.append(line.copy())
#         for i in range(len(res_matr.matr)):
#             for j in range(len(res_matr.matr[0])):
#                 res_matr.matr[i][j] += other.matr[i][j]
#         return res_matr
#
#     def __mul__(self, other):  # other = int or float
#         res_matr = Matrix()
#         res_matr.matr = list(list())
#         for line in self.matr:
#             res_matr.matr.append(line.copy())
#         for i in range(len(self.matr)):
#             for j in range(len(self.matr[0])):
#                 res_matr.matr[i][j] *= other
#         return res_matr
#
#     __rmul__ = __mul__
#
#     def __str__(self):
#         result = ''
#         for line in self.matr:
#             curline = ''
#             for num in line:
#                 curline += str(num) + '\t'
#             if curline[-1] == '\t':
#                 curline = curline[:-1]
#             result += curline + '\n'
#         if result[-1] == '\n':
#             result = result[:-1]
#         return result
#
#     def size(self):
#         rows, cols = len(self.matr), 0
#         if rows > 0:
#             cols = len(self.matr[0])
#         return rows, cols
# m = Matrix([[10, 10], [0, 0], [1, 1]])
# print(m.size())
# print()
# m1 = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
# m2 = Matrix([[0, 1, 0], [20, 0, -1], [-1, -2, 0]])
# print(m1 + m2)
# print()
# m3 = Matrix([[1, 1, 0], [0, 2, 10], [10, 15, 30]])
# print(m3)
# print()
# alpha = 15
# print(m3 * alpha)
# print()
# print(alpha * m3)
# print()


# THEORY 4 : Complex mul number
# class Complex:
#     some_static_variable = 4
#
#     def __init__(self, re=0, im=0):  # self = 'this' in C++
#         self.re = re  # member re appears only for current object
#         self.im = im  # member im appears only for current object
#
#     def __str__(self):  # when we call str(obj) it is called
#         return str(self.re) + ' + ' + str(self.im) + 'i'
#
#     def __add__(self, other):  # returns NEW object  !!!
#         result = Complex(self.re + other.re, self.im + other.im)
#         return result
#
#     def __mul__(self, other):
#         if isinstance(other, Complex):  # if other is Complex
#             re = self.re * other.re - self.im * other.im  # local var
#             im = self.re * other.im + self.im * other.re  # local var
#         elif isinstance(other, int) or isinstance(other, float):
#             re = self.re * other
#             im = self.im * other
#         return Complex(re, im)
#
#     __rmul__ = __mul__  # is same as __mul__ ---> copy code in this way
#
# a = Complex()
# b = Complex(1, 1)
# c = Complex(2, 3)
# print(2 * b)        # Error without __rmul__


# THEORY 5 : Complex errors handling
# exceptions are useful during working with files :
#     look, it's used by other .... look, it's a;ready free !!
# print('abc' * Complex(1, 2)) ----> Error ---> exceptions
# class ComplexError(BaseException):  # without BaseException we will have
#     def __init__(self, complex, other):  # error in exception handler below
#         self.first = complex
#         self.second = other
# class Complex:
#     some_static_variable = 4
#
#     def __init__(self, re=0, im=0):  # self = 'this' in C++
#         self.re = re  # member re appears only for current object
#         self.im = im  # member im appears only for current object
#
#     def __str__(self):  # when we call str(obj) it is called
#         return str(self.re) + ' + ' + str(self.im) + 'i'
#
#     def __add__(self, other):  # returns NEW object  !!!
#         result = Complex(self.re + other.re, self.im + other.im)
#         return result
#
#     def __mul__(self, other):
#         if isinstance(other, Complex):  # if other is Complex
#             re = self.re * other.re - self.im * other.im  # local var
#             im = self.re * other.im + self.im * other.re  # local var
#         elif isinstance(other, int) or isinstance(other, float):
#             re = self.re * other
#             im = self.im * other
#         else:
#             error = ComplexError(self, other)    # create exception
#             raise error            # 'throw' exception --> need handler
#         return Complex(re, im)
#
#     __rmul__ = __mul__  # is same as __mul__ ---> copy code in this way
# try:
#     print('abc' * Complex(1, 2))
# except ComplexError as ce:  # ce = object of ComplexError
#     print('Multiplication error, first para, :', ce.first,  # here we will
#           ', second param:', ce.second)  # have error without BaseException
# except AnotherTypeError as ate:    # we can handle other types of exceptions
#     ...


# Task 3 : errors, transposing matrix
# from sys import stdin    # before program
# exec(stdin.read())       # after program
# class MatrixError(BaseException):
#     def __init__(self, matrix1, matrix2):
#         self.matrix1 = matrix1
#         self.matrix2 = matrix2
#
#
# class Matrix:
#     def __init__(self, matr=None):
#         if matr is None:
#             matr = list(list())
#         self.matr = list(list())
#         for line in matr:
#             self.matr.append(line.copy())  # copy of line
#
#     @staticmethod
#     def transposed(matrix):
#         # result = matrix  # wrong way : result is reference to matrix
#         result = Matrix()
#         result.matr = list(list())
#         for line in matrix.matr:
#             result.matr.append(line.copy())  # copy of line
#         return result.transpose()
#
#     def transpose(self):
#         tmp = Matrix()
#         tmp.matr = list(map(list, zip(*self.matr)))
#         self.matr.clear()
#         for line in tmp.matr:
#             self.matr.append(line.copy())  # copy of line
#         return self
#
#     def __add__(self, other):
#         if not isinstance(other, Matrix) or self.size() != other.size():
#             raise MatrixError(self, other)
#         res_matr = Matrix()
#         res_matr.matr = list(list())
#         for line in self.matr:
#             res_matr.matr.append(line.copy())  # copy of line
#         for i in range(len(res_matr.matr)):
#             for j in range(len(res_matr.matr[0])):
#                 res_matr.matr[i][j] += other.matr[i][j]
#         return res_matr
#
#     def __mul__(self, other):  # other = int or float
#         res_matr = Matrix()
#         res_matr.matr = list(list())
#         for line in self.matr:
#             res_matr.matr.append(line.copy())  # copy of line
#         for i in range(len(self.matr)):
#             for j in range(len(self.matr[0])):
#                 res_matr.matr[i][j] *= other
#         return res_matr
#
#     __rmul__ = __mul__
#
#     def __str__(self):
#         result = ''
#         for line in self.matr:
#             curline = ''
#             for num in line:
#                 curline += str(num) + '\t'
#             if curline[-1] == '\t':
#                 curline = curline[:-1]
#             result += curline + '\n'
#         if result[-1] == '\n':
#             result = result[:-1]
#         return result
#
#     def size(self):
#         rows, cols = len(self.matr), 0
#         if rows > 0:
#             cols = len(self.matr[0])
#         return rows, cols
# print('\n\ntest 6 :')
# m1 = Matrix([[1, 2, 3], [4, 5, 6]])
# print(m1, end='\n')
# m1.transpose()
# print(m1, end='\n')
# print(m1.transpose(), end='\n\n')
# print(Matrix.transposed(m1), end='\n\n')
# print(m1, end='\n\n')


# Task 4 : add mul to Matrix class
# update __mul__ to mul matr1 * matr2 (if impossible --> exception)
# class MatrixError(BaseException):
#     def __init__(self, matrix1, matrix2):
#         self.matrix1 = matrix1
#         self.matrix2 = matrix2
#
# import functools
# class Matrix:
#     def __init__(self, matr=None):
#         if matr is None:
#             matr = list(list())
#         self.matr = list(list())
#         for line in matr:
#             self.matr.append(line.copy())  # copy of line
#
#     @staticmethod
#     def transposed(matrix):
#         # result = matrix  # wrong way : result is reference to matrix
#         result = Matrix()
#         result.matr = list(list())
#         for line in matrix.matr:
#             result.matr.append(line.copy())  # copy of line
#         return result.transpose()
#
#     def transpose(self):
#         tmp = Matrix()
#         tmp.matr = list(map(list, zip(*self.matr)))
#         self.matr.clear()
#         for line in tmp.matr:
#             self.matr.append(line.copy())  # copy of line
#         return self
#
#     def __add__(self, other):
#         if not isinstance(other, Matrix) or self.size() != other.size():
#             raise MatrixError(self, other)
#         res_matr = Matrix()
#         res_matr.matr = list(list())
#         for line in self.matr:
#             res_matr.matr.append(line.copy())  # copy of line
#         for i in range(len(res_matr.matr)):
#             for j in range(len(res_matr.matr[0])):
#                 res_matr.matr[i][j] += other.matr[i][j]
#         return res_matr
#
#     def __mul__(self, other):  # other = int or float
#         res_matr = Matrix()
#         res_matr.matr = list(list())
#         if isinstance(other, Matrix):
#             if self.size()[1] != other.size()[0]:
#                 raise MatrixError(self, other)
#             m1 = self.matr
#             m2 = other.matr
#             res_matr.matr = list(
#                 map(
#                     lambda line_1:
#                     list(
#                         map(
#                             lambda line_2: functools.reduce(
#                                 lambda x, y: x + y,
#                                 map(
#                                     lambda pair: pair[0] * pair[1],
#                                     zip(line_1, line_2)
#                                 )
#                             ),
#                             zip(*m2)
#                         )
#                     ),
#                     m1
#                 )
#             )
#
#         elif isinstance(other, int) or isinstance(other, float):
#             res_matr.matr = list(
#                 map(
#                     lambda line: list(map(lambda x: x * other, line)),
#                     self.matr
#                 )
#             )
#         else:
#             raise MatrixError(self, other)
#         return res_matr
#
#     __rmul__ = __mul__
#
#     def __str__(self):
#         result = ''
#         for line in self.matr:
#             curline = ''
#             for num in line:
#                 curline += str(num) + '\t'
#             if curline[-1] == '\t':
#                 curline = curline[:-1]
#             result += curline + '\n'
#         if result[-1] == '\n':
#             result = result[:-1]
#         return result
#
#     def size(self):
#         rows, cols = len(self.matr), 0
#         if rows > 0:
#             cols = len(self.matr[0])
#         return rows, cols

# print('test 1:')
# a, b = Matrix([[1, 2]]), Matrix([[1], [2]])
# print(a), print(), print(b), print(), print(a * b), print(), print(b * a)
# ________
# print('test 2:')
# mid = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
# m1 = Matrix([[3, 2], [-10, 0], [14, 5]])
# m2 = Matrix([[5, 2, 10], [-0.5, -0.25, 18], [-22, -2.5, -0.125]])
# print(mid * m1)
# print(mid * m2)
# print(m2 * m1)
# try:
#     m = m1 * m2
#     print("WA It should be error")
# except MatrixError as e:
#     print(e.matrix1)
#     print(e.matrix2)
#


# Task 4 check 2
# mid = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
# m1 = Matrix([[3, 2], [-10, 0], [14, 5]])
# m2 = Matrix([[5, 2, 10], [-0.5, -0.25, 18], [-22, -2.5, -0.125]])
# print(0.5 * m2)
# print(m2 * (0.5 * mid * m1))

# Task 4 check 3
# mid = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
# m1 = Matrix([[3, 2], [-10, 0], [14, 5]])
# m2 = Matrix([[5, 2, 10], [-0.5, -0.25, 18], [-22, -2.5, -0.125]])
# print(5 * m2)
# print(m2 * (120 * mid * m1))
#


# THEORY 6 : Inheritance
# class ComplexError(BaseException):  # without BaseException we will have
#     def __init__(self, complex, other):  # error in exception handler below
#         self.first = complex
#         self.second = other
#
#
# class Complex:
#     some_static_variable = 4
#
#     def __init__(self, re=0, im=0):  # self = 'this' in C++
#         self.re = re  # member re appears only for current object
#         self.im = im  # member im appears only for current object
#
#     def __str__(self):  # when we call str(obj) it is called
#         return str(self.re) + ' + ' + str(self.im) + 'i'
#
#     def __add__(self, other):  # returns NEW object  !!!
#         result = Complex(self.re + other.re, self.im + other.im)
#         return result
#
#     def __mul__(self, other):
#         if isinstance(other, Complex):  # if other is Complex
#             re = self.re * other.re - self.im * other.im  # local var
#             im = self.re * other.im + self.im * other.re  # local var
#         elif isinstance(other, int) or isinstance(other, float):
#             re = self.re * other
#             im = self.im * other
#         else:
#             error = ComplexError(self, other)    # create exception
#             raise error            # 'throw' exception --> need handler
#         return Complex(re, im)
#
#
# class Point(Complex):
#     def length(self):
#         return (self.re**2 + self.im**2) ** 0.5
#
#     def __str__(self):
#         return str((self.re, self.im))

# Point is inherited from Complex ---> has all that haas Complex
# p1 = Point(1, 1)  # Point() not implemented, but Complex() will be called
# p2 = Complex(2, 2)
# p3 = p1 + p2          # ---> Complex + Complex = Complex
# print(p3.length())    # ---> Complex() has no jeght(self)
# print(p3)             # Complex ---> print
# print(p1)         # Point ---> print as Complex if no __str__ in Point class
# print(p1)         # Point ---> print (x, y) if have __str__ in Point class


# Task 5 : Linear algebra
# Matrix ---> matrix of system of linear algebraic equations
# need to add method solve(self, column) where column = 'free coefficients'

# look at Matrix.py

