print('test 1 :')
m1 = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
m2 = Matrix([[0, 1, 0], [20, 0, -1], [-1, -2, 0]])
print(m1 + m2)
m2 = Matrix([[0, 1, 0], [20, 0, -1]])
try:
    m = m1 + m2
    print('WA\n' + str(m))
except MatrixError as e:
    print(e.matrix1)
    print(e.matrix2)



print('\n\ntest 2 :')
m = Matrix([[10, 10], [0, 0], [1, 1]])
print(m)
m1 = m.transpose()
print(m)
print(m1)



print('\n\ntest 3 :')
m = Matrix([[10, 10], [0, 0], [1, 1]])
print(m)
print(Matrix.transposed(m))
print(m)



print('\n\ntest 4 :')
m = Matrix([[1, 2], [3, 4]])
alpha = 5
try:
    print(m + 5)
except MatrixError as me:
    print('Sum error :\nfirst is', me.matrix1,
          'second is', me.matrix2, sep='\n')



print('\n\ntest 5 :')
m1 = Matrix([[1, 2], [3, 4]])
m2 = Matrix([[1, 2, 3], [4, 5, 6]])
try:
    print(m1 + m2)
except MatrixError as me:
    print('Sum error :\nfirst is', me.matrix1,
          'second is', me.matrix2, sep='\n')



print('\n\ntest 6 :')
m1 = Matrix([[1, 2], [3, 4]])
m2 = Matrix([[1, 2, 3], [4, 5, 6]])
print(transposed(m1), end='\n\n')
print(m1, end='\n\n')
