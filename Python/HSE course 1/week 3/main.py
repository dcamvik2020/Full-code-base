# THEORY 1 : float numbers
#  1 bit  sign
# 52 bits mantissa (15-16 decimal digits)
# 11 bits exponent
# every number = someNum / deg_of_two
# 0.125 <---> 1/8
# 0.1 ~ 3602879701896397/3602879701896396
# a lot of 'nice' numbers can't be presented like this
# X <----> [X - epsilon; X + epsilon]
# epsilon <---> relative , not absolute accuracy
# for X -----> epsilon = X * 2**(-54)
# (X + epsilon) * (Y + epsilon) =
#       XY + (X + Y) * epsilon + epsilon**2
# epsilon**2 << 1    -----> forget it

# THEORY 2 : float numbers
# x = float(input())
# 123.456 = 1.23456e2 = 1.23456 * 10**2
# x = 0.1
# print('{0:.25f}'.format(x)) ---> 0..1000000000000000055511151
# if 0.1 + 0.2 == 0.3:
#     print('Yes')
# else:
#     print('No')    # this will be the answer

# THEORY 3 : float numbers
# (X == Y) <-----> (abs(X-Y) < epsilon)
# (X < Y) <-----> (X < Y - epsilon)
#       compare X, Y
# x = float(input())
# y = float(input())
# epsilon = 10 ** -6
# if abs(x - y) < epsilon:
#     print('Equal')
# else:
#     print('Not equal')
# if with X, Y we do operations like multiplication
# then we need to compute epsilon like in example for X*Y


# Task 1 : triangle's area
# a, b, c = float(input()), float(input()), float(input())
# p = (a + b + c) / 2
# area = (p * (p-a) * (p-b) * (p-c)) ** 0.5
# print(area)

# Task 2 : sum of sequence 1/k^2 from 1 to n
# n = int(input())
# sumReverseSquares = 0.0
# i = 1
# while i <= n:
#     sumReverseSquares += 1 / (i ** 2)
#     i += 1
# print(sumReverseSquares)

# THEORY 4 : round float numbers
# int()   --- removes fractional part, "to the zero"
# round() --- to nearest integer, if 0.5 --> to even number
# floor() --- to the nearest less number
# ceil()  --- to the nearest bigger number
# func   2.5	3.5 	-2.5
# int	 2	    3	    -2
# round	 2	    4	    -2
# floor	 2	    3	    -3
# ceil	 3	    4	    -2
# for floor() and ceil() need "import math"
# then use them : math.floor(-2.5)
# or we can use "from math import floor, ceil"
# and after that use them like "floor(2.5)"


# Task 3 : get fractional part of positive number
# from math import floor
# x = float(input())
# fractional_part = x - int(x)
# print(fractional_part)

# Task 4 : price of product
# price = float(input())  # like 12543.23
# rubles = int(price)
# cents = round((price - rubles) * 100)
# print(rubles, cents)

# Task 5 : round with russian rules
# round to the nearest integer, if frac = 0.5 --> to bigger
# from math import ceil
# x = float(input())  # x >= 0
# fractional = x - int(x)
# if 0.5 - 1e-6 < fractional:
#     print(ceil(x))
# else:
#     print(int(x))

# Task 6 : percents ---> P percent per year = growth
# initially have X rubles, Y cents --> over year = ?
# P, X, Y = int(input()), int(input()), int(input())
# cents = 100 * X + Y
# # growthPerYear = (100 + P) / 100
# centsOverYear = cents * (100 + P) // 100
# rublesOver = centsOverYear // 100
# centsOverYear = centsOverYear % 100
# print(rublesOver, centsOverYear)

# Task 6 : percents ---> P percent per year = growth
# initially have X rubles, Y cents --> over K years = ?
# P, X, Y, K = int(input()), int(input()), int(input()), int(input())
# cents = 100 * X + Y
# # growthPerYear = (100 + P) / 100
# centsOverKYears, rublesOverKYears = 0, 0
# while K > 0:
#     centsOverYear = cents * (100 + P) // 100
#     rublesOver = centsOverYear // 100
#     centsOverYear = centsOverYear % 100
#     centsOverKYears = centsOverYear
#     rublesOverKYears = rublesOver
#     cents = rublesOverKYears * 100 + centsOverKYears
#     K -= 1
# print(rublesOverKYears, centsOverKYears)

# Task 7 : Gorner's scheme
# P(x) = a[n]x^n + a[n-1]x^(n-1) + ... + a[1]x + a[0]
# calculate it in point x with scheme of Gorner
# P(x) = ( ... ( ( ( a[n] x + a[n-1] ) x + a[n-2] ) x + a[n-3] ) ... ) x + a[0]
# n = int(input())
# x = float(input())
# polynomValue = 0.0
# while n > 0:
#     coeff = float(input())
#     polynomValue = (polynomValue + coeff) * x
#     n -= 1
# coeff = float(input())
# polynomValue += coeff
# print(polynomValue)

# Task 8 : standard deviation (sigma, like in physics)
# σ=sqrt(((x₁-s)²+(x₂-s)²+…+(xn-s)²) / (n-1))
# s = ((x₁+x₂+…+xn) / n)
# (x₁-s)²+(x₂-s)²+…+(xn-s)² = x₁²+x₂²+…+xn² + n*s² -2n*s²
# σ^2 * (n-1) = (x₁-s)²+(x₂-s)²+…+(xn-s)² = x₁²+x₂²+…+xn² - n*s²
# lenSeq = -1
# sumSquares = -1
# sumNumbers = 1
# now = -1
# sigma = 0.0
# while now != 0:
#     lenSeq += 1
#     sumSquares += now ** 2
#     sumNumbers += now
#     now = int(input())
# if lenSeq > 0:
#     s = sumNumbers / lenSeq
#     tmp = sumSquares - lenSeq * s * s
#     if lenSeq > 1:
#         tmp = float(tmp / (lenSeq - 1))
#     else:
#         tmp = 0.0
#     sigma = tmp ** 0.5
# print(sigma)

# Task 9 : quadratic equation : a,b,c and a!=0
# a, b, c = float(input()), float(input()), float(input())
# D = b * b - 4 * a * c
# if -1e-7 < D < 1e-7:
#     print(-b / (2 * a))
# elif 1e-7 < D:
#     x1 = (-b - D ** 0.5) / (2*a)
#     x2 = (-b + D ** 0.5) / (2*a)
#     # a < 0 also possible
#     if x1 > x2:
#         x1, x2 = x2, x1
#     print(x1, x2)

# Task 10 : quadratic equation : a,b,c any real numbers
# a, b, c = float(input()), float(input()), float(input())
# eps = 1e-7
# if -eps < a < eps:
#     if -eps < b < eps:
#         if -eps < c < eps:
#             print(3)
#         else:
#             print(0)
#     else:
#         print(1, -c / b)
# else:
#     D = b * b - 4 * a * c
#     if -eps < D < eps:
#         print(1, -b / (2 * a))
#     elif eps < D:
#         x1 = (-b - D ** 0.5) / (2*a)
#         x2 = (-b + D ** 0.5) / (2*a)
#         # a < 0 also possible
#         if x1 > x2:
#             x1, x2 = x2, x1
#         print(2, x1, x2)
#     else:
#         print(0)

# Task 11 : system of linear algebraic equations - 1
# ax + by = e    # we know that this system has
# cx + dy = f    # only one solution ---> (x,y) = ?
# a, b = float(input()), float(input())
# c, d = float(input()), float(input())
# e, f = float(input()), float(input())
# d0 = a * d - b * c
# d1 = e * d - b * f
# d2 = a * f - e * c
# print(d1 / d0, d2 / d0)

# Task 12 : system of linear algebraic equations - 2
# ax + by = e    # we don't know anything
# cx + dy = f    # (x,y) = ?
# a, b = float(input()), float(input())
# c, d = float(input()), float(input())
# e, f = float(input()), float(input())
# d0 = a * d - b * c
# d1 = e * d - b * f
# d2 = a * f - e * c
# eps = 1e-6
# d0IsNull = -eps < d0 < eps
# if not d0IsNull:
#     print(2, d1 / d0, d2 / d0)
# else:
#     d1IsNotNull = not (-eps < d1 < eps)
#     d2IsNotNull = not (-eps < d2 < eps)
#     if d1IsNotNull or d2IsNotNull:
#         print(0)
#     else:
#         aNull, aNotNull = (-eps < a < eps), not (-eps < a < eps)
#         bNull, bNotNull = (-eps < b < eps), not (-eps < b < eps)
#         cNull, cNotNull = (-eps < c < eps), not (-eps < c < eps)
#         dNull, dNotNull = (-eps < d < eps), not (-eps < d < eps)
#         eNull, eNotNull = (-eps < e < eps), not (-eps < e < eps)
#         fNull, fNotNull = (-eps < f < eps), not (-eps < f < eps)
#         wrongEquation1 = (aNull and bNull and eNotNull)
#         wrongEquation2 = (cNull and dNull and fNotNull)
#         allNull_1 = aNull and bNull and eNull
#         allNull_2 = cNull and dNull and fNull
#         if wrongEquation1 or wrongEquation2:
#             print(0)
#         elif allNull_1 and allNull_2:
#             print(5)
#         else:
#             if allNull_1:
#                 a, b, e = c, d, f
#             #  !! if we change a, b, e ---->
#             # we need to change aNull, bNull
#             aNull = (-eps < a < eps)
#             bNull = (-eps < b < eps)
#             if bNull:
#                 print(3, e / a)
#             elif aNull:
#                 print(4, e / b)
#             else:  # y = px + q
#                 print(1, -a/b, e/b)


# THEORY 5 : string's part (string's cut)
# len(s), s1 + s2, s * 5
# string's cut = new string, old doesn't change
# simplest cut : s[i], if i >= len(s) ---> error
# s[-1] = last symbol of s
# s[-2] = one before last symbol of s
# s[a:b] = s[a]s[a+1]...s[b-1] ---> s[b] not included
# s = 'string' ----> s[1:5] = s[1:-1] = 'trin'
# if b >= len(s) ---> s[a:b] = s[a:] = s[a]...s[len(s)-1]
# s = 'string' = s[:] ---> s[2:] = 'ring', s[:2] = 'st'
# if a > b --> s[a:b] = ''
# s[start:finish:step] = s[a:b:step]
# s = 'string' ---> s[::2] = 'srn'
# if step < 0 ----> first symbol is the last in s
# s[::-1] = reversed s


# THEORY 6 : method find
# finds substring in string ----> index of first entrance
# if there is no substring ---> -1 is returned
# 'String'.find('ing') = 3
# s.find(substring, from) ---> find in s[from:]
# 'String'.find('ing', 1) = 3
# parameters can be negative like in cuts of strings
#       find all substring's entrances
# string = input()
# substring = input()
# pos = string.find(substring)
# while pos != -1:
#     print(pos)
#     pos = string.find(substring, pos + 1)


# Task 13 : make cuts (do just what coded)
# string = input()
# print(string[2])       # third symbol
# print(string[-2])      # one before last symbol
# print(string[:5])      # first 5 symbols
# print(string[:-2])     # all except last 2 symbols
# print(string[::2])     # all symbols with even indexes
# print(string[1::2])    # all symbols with odd indexes
# print(string[::-1])    # all symbols in reversed order
# print(string[::-2])    # last, 2 before last, ... , reversed order
# print(len(string))     # length of string

# Task 14 : first, last entrance of 'f'
# string = input()
# cur = string.find('f')
# first, last = cur, cur
# while cur != -1:
#     last = cur
#     cur = string.find('f', cur + 1)
# if first != -1:
#     print(first, end=' ')
#     if first != last:
#         print(last)

# Task 15 : delete part
# find first, last entrances of 'h' and delete
# them and all symbols between them
# granted : there are minimum 2 'h' in string
# string = input()
# cur = string.find('h')
# first, last = cur, cur
# while cur != -1:
#     last = cur
#     cur = string.find('h', cur + 1)
# answer = string[:first] + string[last + 1:]
# print(answer)

# Task 16 : double part
# find first, last entrances of 'h'
# double part between them
# granted : there are minimum 2 'h' in string
# string = input()
# cur = string.find('h')
# first, last = cur, cur
# while cur != -1:
#     last = cur
#     cur = string.find('h', cur + 1)
# answer = string[:first + 1] + string[first+1:last] * 2 + string[last:]
# print(answer)

# Task 17 : secons entrance of 'f' in string
# only 1 'f' --> -1, none at all --> -2
# s = input()
# first = s.find('f')
# second = s.find('f', first + 1)
# if first == -1:
#     print(-2)
# elif second == -1:
#     print(-1)
# else:
#     print(second)

# Task 18 : swap 2 words in string
# s = 2 words with whitespace between ---> swap them
# s = input()
# whitespace = s.find(' ')
# answer = s[whitespace + 1:] + " " + s[:whitespace]
# print(answer)


# THEORY 7 : methods replace, rfind, count
# rfind             --- like find, but from the end
# replace(old, new) --- all entrances of old --> new
# replace creates a new string
# 'AAAAAA'.replace('AA', 'A') = 'AAA'
#  A A A ---> have 'AAA' (it replaces part and searches FURTHER)
# replace(old, new, count) --- replaces no more than count entrances of old
# count(substr) ... acts like find
# count() can be with 2 and 3 parameters like find()

# Task 19 : count words in line
# s = input()
# words_cnt = 1
# whitespace = s.find(' ')
# while whitespace != -1 and whitespace != len(s) - 1:
#     words_cnt += 1
#     whitespace = s.find(' ', whitespace + 1)
# print(words_cnt)

# Task 20 : replace '1' with 'one'
# s = input()
# answer = s.replace('1', 'one')
# print(answer)

# Task 21 : remove all '@' from string
# s = input()
# answer = s.replace('@', '')
# print(answer)

# Task 22 : replace in part of string
# replace 'h' with 'H' except first, last
# s = input()
# first = s.find('h')
# cur, last = first, first
# while cur != -1:
#     last = cur
#     cur = s.find('h', cur + 1)
# answer = s[:first + 1] + \
#          s[first + 1:last].replace('h', 'H') +\
#          s[last:]
# print(answer)

# Task 23 : insert after every symbol '*'
# s = input()   # '' is before first, after last and between
# answer = s.replace('', '*')[1:-1]   # every 2 nearest symbols
# print(answer)

# Task 24 : remove symbols with (id % 3 == 0)
# s = input()
# answer = ''
# i = 1
# while i < len(s):
#     answer += s[i:i+2]
#     i += 3
# print(answer)
