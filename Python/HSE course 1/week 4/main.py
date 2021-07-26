# THEORY 1 : functions
# can have no parameters
# rules : good name, can be places on 1 screen
# better them to be 10-15 lines

# THEORY 2 : create function
# def hypot(a, b):
#     sqrSum = a**2 + b**2
#     return sqrSum ** (1/2)

# THEORY 3 : use functions
# def factorial(n):
#     res = 1
#     while n > 1:
#         res *= n
#         n -= 1
#     return res
# def C_n_k(n, k):
#     return factorial(n) // factorial(k) // factorial(n-k)
# print(factorial(5))
# print(C_n_k(4, 2))


# Task 1 : def func min of 4 numbers
# def min4(a, b, c, d):
#     min_ab = min(a, b)
#     min_cd = min(c, d)
#     res_min = min(min_ab, min_cd)
#     return res_min
# a, b, c, d = int(input()), int(input()), int(input()), int(input())
# print(min4(a, b, c, d))

# Task 2 : segment's length
# def seglen(x1, y1, x2, y2):
#     dx = x1 - x2
#     dy = y1 - y2
#     length = (dx**2 + dy**2) ** 0.5
#     return length
# x1, y1 = float(input()), float(input())
# x2, y2 = float(input()), float(input())
# print(seglen(x1, y1, x2, y2))

# Task 3 : triangle's perimeter
# def seglen(x1, y1, x2, y2):
#     dx = x1 - x2
#     dy = y1 - y2
#     length = (dx**2 + dy**2) ** 0.5
#     return length
# def perimeter(x1, y1, x2, y2, x3, y3):
#     a = seglen(x1, y1, x2, y2)
#     b = seglen(x3, y3, x2, y2)
#     c = seglen(x1, y1, x3, y3)
#     p = a + b + c
#     return p
# x1, y1 = float(input()), float(input())
# x2, y2 = float(input()), float(input())
# x3, y3 = float(input()), float(input())
# print(perimeter(x1, y1, x2, y2, x3, y3))


# THEORY 4 : return values from functions
# we can return several values together in tuples
# def sort2(a, b):
#     if a < b:
#         return a, b
#     return b, a


# Task 4 : is point within square ??
# square : (1,1) ; (1,-1) ; (-1,-1) ; (-1,1)
# def IsPointInSquare(x, y):
#     correctX = -1 <= x <= 1
#     correctY = -1 <= y <= 1
#     ok = correctY and correctX
#     return ok
# x, y = float(input()), float(input())
# if IsPointInSquare(x, y):
#     print('YES')
# else:
#     print('NO')

# Task 5 : is point within square ?? -- part 2
# square : (1,0) ; (0,1) ; (-1,0) ; (0,-1)
# def IsPointInSquare(x, y):
#     betweenLines1 = -1 <= x + y <= 1
#     betweenLines2 = -1 <= y - x <= 1
#     ok = betweenLines1 and betweenLines2
#     return ok
# x, y = float(input()), float(input())
# if IsPointInSquare(x, y):
#     print('YES')
# else:
#     print('NO')

# Task 6 : is point in circle ??
# def IsPointInCircle(x, y, xc, yc, r):
#     dist = ((x-xc)**2 + (y-yc)**2) ** 0.5
#     return dist <= r
# x, y = float(input()), float(input())
# xc, yc = float(input()), float(input())
# r = float(input())
# if IsPointInCircle(x, y, xc, yc, r):
#     print('YES')
# else:
#     print('NO')

# Task 7 : is point in some area ???
# area = area1 \cup area2:
# area1: in sircle (xc,yc,r) = (-1,1,2) and
#        higher two lines : y = 2x+2, y = -x
# area2 : out od the circle and under these two lines
# def IsPointInArea(x, y):
#     xc, yc, r = -1, 1, 2
#     inCircle = (((x-xc)**2 + (y-yc)**2) ** 0.5) <= r
#     outCircle = (((x-xc)**2 + (y-yc)**2) ** 0.5) >= r
#     higherLine1 = (y >= 2*x + 2)
#     underLine1 = (y <= 2*x + 2)
#     higherLine2 = (y >= -x)
#     underLine2 = (y <= -x)
#     inArea1 = inCircle and higherLine1 and higherLine2
#     inArea2 = outCircle and underLine1 and underLine2
#     inArea = inArea1 or inArea2
#     return inArea
# x, y = float(input()), float(input())
# if IsPointInArea(x, y):
#     print('YES')
# else:
#     print('NO')

# Task 8 : XOR
# def xor(x, y):  # x,y are bool, x*y != True
#     res = (x + y) % 2
#     return res
# x, y = int(input()), int(input())
# print(xor(x, y))

# Task 9 : minimal divisor
# def MinDivisor(n):
#     d = 2
#     while d ** 2 <= n and n % d != 0:
#         d += 1
#     if n % d != 0:
#         return n
#     return d
# n = int(input())
# print(MinDivisor(n))


# THEORY 5 : local and global variables
# def f():       # 'a' is global ---> even if we don't
#     print a    # declare the variable before f()
# a = 1          # we can use it
# f()            # it works, OK
# if variable is modified in function ---> local
# def f():
#     global a, b, c        # now we can modify global
#     a, b, c = 1, 2, 2     # variables a,b,c, defined
#     return True           # out of functions


# Task 10 : is number simple ?
# def IsPrime(n):  # n > 1
#     d = 2
#     while d * d <= n and n % d != 0:
#         d += 1
#     return n % d != 0 or n == 2
# n = int(input())
# if IsPrime(n):
#     print('YES')
# else:
#     print('NO')

# THEORY 6 : recursion
# def rec():               # read and print
#     n = int(input())     # sequence ending with 0
#     if n != 0:
#         print(n)
#         rec()
# sequence ending with 0, print even numbers towards, odd numbers reversed
# def rec():
#     n = int(input())
#     if n != 0:
#         if n % 2 == 0:
#             print(n)
#         rec()
#         if n % 2 != 0:
#             print(n)
# rec()


# Task 11 : a ** n, real a > 0, integer n >= 0
# def power(a, n):
#     if n == 0:
#         return 1
#     return a * power(a, n-1)
# a = float(input())  # a > 0
# n = int(input())    # n >= 0
# print(pow(a, n))

# Task 12 : negative degree, real a > 0, integer n
# def power(a, n):
#     if n < 0:
#         return 1 / power(a, -n)
#     if n == 0:
#         return 1
#     return a * power(a, n-1)
# a = float(input())  # a > 0
# n = int(input())    # n >= 0
# print(pow(a, n))

# Task 13 : sum without summarizing
# a, b are integers >= 0, we can use only +1, -1
# def sum(a, b):
#     if b == 0:
#         return a
#     return sum(a+1, b-1)
# a, b = int(input()), int(input())
# print(sum(a, b))

# Task 14 : fast paw(a, n)
# def fast_power(a, n):
#     if n == 0:
#         return 1
#     if n % 2 == 0:
#         sqrt = fast_power(a, n // 2)
#         return sqrt ** 2
#     else:
#         sqrt = fast_power(a, n // 2)
#         return a * (sqrt ** 2)
# a = float(input())
# n = int(input())
# print(fast_power(a, n))

# Task 15 : Euclid's algorithm
# def gcd(a, b):  # initially a,b are integers > 0
#     if b == 0:
#         return a
#     if a < b:
#         a, b = b, a
#     return gcd(b, a % b)
# a, b = int(input()), int(input())
# print(gcd(a, b))

# Task 16 : correct fraction (p/q, gcd(p,q) = 1)
# def gcd(a, b):  # initially a,b are integers > 0
#     if b == 0:
#         return a
#     if a < b:
#         a, b = b, a
#     return gcd(b, a % b)
# def ReduceFraction(n, m):
#     pq_gcd = gcd(n, m)
#     p = n // pq_gcd
#     q = m // pq_gcd
#     return p, q
# n, m = int(input()), int(input())
# print(*ReduceFraction(n, m))

# Task 17 : Fibonacci's numbers
# def phib(n):  # n is integer >= 0
#     if n <= 1:
#         return n
#     return phib(n-1) + phib(n-2)
# n = int(input())
# print(phib(n))

# Task 18 : number od combinations C_n_k
# def C_n_k(n, k):  # integers 0 <= k <= n
#     if k == 0 or k == n:
#         return 1
#     return C_n_k(n-1, k) + C_n_k(n-1, k-1)
# N, K = int(input()), int(input())
# print(C_n_k(N, K))

# Task 19 : sum of sequence
# def sumSeq():
#     now = int(input())
#     if now != 0:
#         return now + sumSeq()
#     return 0
# print(sumSeq())

# Task 20 : reverse sequence
# def reverseSeq():
#     now = int(input())
#     if now != 0:
#         reverseSeq()
#     print(now)
#     return
# reverseSeq()

# Task 21 : Hanoi's tower
# def move(n, x, y):  # 3 heaps, initially n on 1, 2 and 3 empty
#     if n == 0:
#         return
#     move(n-1, x, 6 - x - y)
#     print(n, x, y)  # print number of the disk that is moved
#     move(n-1, 6 - x - y, y)
# n = int(input())
# move(n, 1, 3)

# Task 22 : Lagrange's theorem
# any natural number = a^2 + b^2 + c^2 + d^2
# def getMax4Numbers(n):
#     i = int(n ** 0.5)
#     while i >= 1:
#         if i * i == n:
#             print(i)
#             return
#         j = int((n - i*i) ** 0.5)
#         while j >= 1:
#             if i*i + j*j == n:
#                 print(i, j)
#                 return
#             k = int((n - i*i - j*j) ** 0.5)
#             while k >= 1:
#                 if i*i + j*j + k*k == n:
#                     print(i, j, k)
#                     return
#                 m = int((n - i*i - j*j - k*k) ** 0.5)
#                 while m >= 1:
#                     if i*i + j*j + k*k + m*m == n:
#                         print(i, j, k, m)
#                         return
#                     m -= 1
#                 k -= 1
#             j -= 1
#         i -= 1
#
#
# N = int(input())
# getMax4Numbers(N)

# OTHER SOLUTION for Task 22
# def rec(n, level):
#     i = int(n ** 0.5)
#     if i ** 2 == n:
#         return str(i)
#     elif level == 1:
#         return ''
#     else:
#         while i >= 1:
#             other = rec(n-i*i, level-1)
#             if other != '':
#                 return str(i) + ' ' + other
#             i -= 1
#         return ''
#
#
# N = int(input())
# ans = rec(N, 4)
# print(ans)


# Task 23 : get num as sum of <= 7 cubes of naturals
# def rec(n, level):  # level = # of allowed numbers, level <= 7
#     i = int(n ** (1/3))
#     if i ** 3 == n:
#         return str(i ** 3)
#     elif level == 1:
#         return '0'
#     else:
#         while i >= 1:
#             answer = rec(n - i**3, level - 1)
#             if answer != '0':
#                 return str(i ** 3) + ' ' + answer
#             i -= 1
#         return '0'  # if it's impossible -- output = '0'
# N = int(input())
# print(rec(N, 7))

# Task 24 : only squares from sequence in reversed order
# def getSquaresReversedOrder(other_exist):
#     now = int(input())
#     if now == 0:
#         return other_exist
#     other_exist = getSquaresReversedOrder(other_exist)
#     if int(now ** 0.5) ** 2 == now:
#         print(now, end=' ')
#         return True
#     return other_exist
#
# exist = getSquaresReversedOrder(False)
# if not exist:
#     print(0)
