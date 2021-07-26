# THEORY 1
# logical type (bool) --> 0/1, True/False (non-changeable)
# and, or, not, ==, !=, <=, >=, >, <
#       is number even
# n = int(input())
# isEven = (n % 2 == 0)
# print(isEven)

# THEORY 2
#       intersection of segments
# start1 = int(input())
# finish1 = int(input())
# start2 = int(input())
# finish2 = int(input())
# isS1in2 = start2 <= start1 <= finish2
# isS2in1 = start1 <= start2 <= finish1
# isF1in2 = start2 <= finish1 <= finish2
# isF2in1 = start1 <= finish2 <= finish1
# intersection = isS2in1 or isS1in2 or isF1in2 or isF2in1
# print(intersection)
# #      other solution
# intersection_2 = start1 <= finish2 and start2 <= finish1
# print(intersection_2)

# THEORY 3 : operator if
#       abs(x)
# x = int(input())
# if x < 0:
#     x = -x
# print(x)
#       abs(x)
# x = int(input())
# if x >= 0:
#     print(x)
# else:
#     print(-x)
#       abs(x)
# x = int(input())
# if x >= 0:
#     print(x)
# if not (x >= 0):
#     print(-x)


# Task 1 : max(A, B)
# A = int(input())
# B = int(input())
# if A >= B:
#     print(A)
# else:
#     print(B)


# THEORY 4 : interior if-else
#       coordinate quadrant
# x = int(input())
# y = int(input())
# if x > 0:
#     if y > 0:
#         print(1)
#     else:
#         print(4)
# else:
#     if y > 0:
#         print(2)
#     else:
#         print(3)
#       name number (1, 2 or 3)
# number = int(input())
# if number == 1:
#     print('One')
# else:
#     if number == 2:
#         print('Two')
#     else:
#         if number == 3:
#             print('Three')
#         else:
#             print('Other')
# if number == 1:
#     print('One')
# elif number == 2:
#     print('Two')
# elif number == 3:
#     print('Three')
# else:
#     print('Other')


# Task 2 : which number is bigger
# num1 = int(input())
# num2 = int(input())
# if num1 > num2:
#     print(1)
# elif num1 < num2:
#     print(2)
# else:
#     print(0)

# Task 3 : max of three numbers
# a = int(input())
# b = int(input())
# c = int(input())
# max_ab = a
# if a < b:
#     max_ab = b
# max_abc = max_ab
# if max_ab < c:
#     max_abc = c
# print(max_abc)

# Task 4 : leap year ( % 4 == 0 and % 100 != 0 or % 400 == 0)
# year = int(input())
# isLeap = year % 4 == 0 and year % 100 != 0 or year % 400 == 0
# if isLeap:
#     print('YES')
# else:
#     print('NO')

# Task 5 : can chess king go x1,y1 --> x2,y2 ?
# x1 = int(input())
# y1 = int(input())
# x2 = int(input())
# y2 = int(input())
# canGo = -1 <= x1 - x2 <= 1 and -1 <= y1 - y2 <= 1
# if canGo:
#     print('YES')
# else:
#     print('NO')

# Task 6 : flats
# entrance --> flatsPerEntrance = const, firstFlat = 1
# Can in any entrance first = x, last flat = y ?
# x = int(input())
# y = int(input())
# flatsPerEntrance = y - x + 1
# thatCanBe = (x-1) % flatsPerEntrance == 0
# if thatCanBe:
#     print('YES')
# else:
#     print('NO')

# Task 7 : are 2 chess cells same color ?
# x1 = int(input())  # consider point (x1, y2) ---> if
# y1 = int(input())  # color_1 != color_2 and color_2 != color_3
# x2 = int(input())  # color_1 = color_2 and color_2 = color_3
# y2 = int(input())  # then color_1 = 3
# evenXDiff = (x1 - x2) % 2 == 0
# evenYDiff = (y1 - y2) % 2 == 0
# evenXYDiffs = evenXDiff and evenYDiff
# oddXYDiffs = not evenXDiff and not evenYDiff
# sameColor = evenXYDiffs or oddXYDiffs
# if sameColor:
#     print('YES')
# else:
#     print('NO')

# Task 8 : chocolate = rectangle
# n = int(input())
# m = int(input())
# k = int(input())
# canGetKByOneDivision = (k <= n * m) and (k % n == 0 or k % m == 0)
# if canGetKByOneDivision:
#     print('YES')
# else:
#     print('NO')

# Task 9 : cows, cnt_cows < 100
# cnt_cows = int(input())
# print(cnt_cows, end=' ')
# if cnt_cows % 10 == 1 and cnt_cows != 11:
#     print('korova')
# elif 2 <= cnt_cows % 10 <= 4 and cnt_cows // 10 != 1:
#     print('korovy')
# else:
#     print('korov')

# Task 10 : number's sign
# number = int(input())
# if number > 0:
#     print(1)
# elif number < 0:
#     print(-1)
# else:
#     print(0)

# Task 11 : coordinate quadrants
# x1 = int(input())
# y1 = int(input())
# x2 = int(input())
# y2 = int(input())
# inSameQuadrant = x1 * x2 > 0 and y1 * y2 > 0
# if inSameQuadrant:
#     print('YES')
# else:
#     print('NO')

# Task 12 : can get to x2,y2 in checkers (like chess)
# x1 = int(input())
# y1 = int(input())
# x2 = int(input())
# y2 = int(input())
# evenXDiff = (x1 - x2) % 2 == 0
# evenYDiff = (y1 - y2) % 2 == 0
# evenXYDiffs = evenXDiff and evenYDiff
# oddXYDiffs = not evenXDiff and not evenYDiff
# sameColor = evenXYDiffs or oddXYDiffs
# X2Y2inCorrectAngle = x2+y2 >= x1+y1 and y2-x2 >= y1-x1
# canGetToSecondPoint = sameColor and X2Y2inCorrectAngle
# if canGetToSecondPoint:
#     print('YES')
# else:
#     print('NO')

# Task 13 : triangle type
# a = int(input())
# b = int(input())
# c = int(input())
# if a > b:
#     tmp = a
#     a = b
#     b = tmp
# if b > c:
#     tmp = c
#     c = b
#     b = tmp
# if a > b:
#     tmp = b
#     b = a
#     a = tmp
# #       now a <= b <= c
# if a + b <= c:
#     print('impossible')
# elif a**2 + b**2 == c**2:
#     print('rectangular')
# elif a**2 + b**2 > c**2:
#     print('acute')  # 'sharp' angle
# elif a ** 2 + b ** 2 < c ** 2:
#     print('obtuse')  # 'not sharp' angle

# Task 14 : even and odd numbers
# find out : {a, b, c} has 1 even and 1 odd number
# a = int(input())
# b = int(input())
# c = int(input())
# haveEvenNumber = (a % 2 == 0) or (b % 2 == 0) or (c % 2 == 0)
# haveOddNumber = (a % 2 == 1) or (b % 2 == 1) or (c % 2 == 1)
# if haveEvenNumber and haveOddNumber:
#     print('YES')
# else:
#     print('NO')

# Task 15 : sort ascending 3 numbers
# a, b, c = int(input()), int(input()), int(input())
# if a > b:
#     a, b = b, a
# if b > c:
#     b, c = c, b
# if a > b:
#     a, b = b, a
# #       now a <= b <= c
# print(a, b, c)

# Task 16 : number repeats in 3 numbers --> count
# a, b, c = int(input()), int(input()), int(input())
# if a > b:
#     a, b = b, a
# if b > c:
#     b, c = c, b
# if a > b:
#     a, b = b, a
# #       now a <= b <= c
# if a == c:
#     print(3)
# elif a == b or b == c:
#     print(2)
# else:
#     print(0)

# Task 17 : IF-castle's prisoner (stone a*b*c, hole m*n)
# a, b, c = int(input()), int(input()), int(input())
# m, n = int(input()), int(input())
# if m > n:
#     m, n = n, m
# #       now m <= n
# if a > b:
#     a, b = b, a
# if b > c:
#     b, c = c, b
# if a > b:
#     a, b = b, a
# #       now a <= b <= c
# canPushStoneThoughHole = (b <= n and a <= m)
# if canPushStoneThoughHole:  # the smallest side should go throw
#     print('YES')
# else:
#     print('NO')

# Task 18 : 2 boxes (a_12, b_12, c_12) --> 1/2 into 2/1 ??
# a1, b1, c1 = int(input()), int(input()), int(input())
# a2, b2, c2 = int(input()), int(input()), int(input())
# if a1 > b1:
#     a1, b1 = b1, a1
# if b1 > c1:
#     b1, c1 = c1, b1
# if a1 > b1:
#     a1, b1 = b1, a1
# #       now a1 <= b1 <= c1
# if a2 > b2:
#     a2, b2 = b2, a2
# if b2 > c2:
#     b2, c2 = c2, b2
# if a2 > b2:
#     a2, b2 = b2, a2
# #       now a2 <= b2 <= c2
# if a1 == a2 and b1 == b2 and c1 == c2:
#     print('Boxes are equal')
# elif c1 <= c2 and b1 <= b2 and a1 <= a2:
#     print('The first box is smaller than the second one')
# elif c2 <= c1 and b2 <= b1 and a2 <= a1:
#     print('The first box is larger than the second one')
# else:
#     print('Boxes are incomparable')

# Task 19 : laptops store
# store, laptop = parallelograms --> max # of laptops in store
# A, B, C = int(input()), int(input()), int(input())
# a, b, c = int(input()), int(input()), int(input())
# # since we will check all combinations ---> can miss sort
# ans_1 = (A // a) * (B // b) * (C // c)  # try to place
# ans_2 = (A // a) * (B // c) * (C // b)  # laptops in
# ans_3 = (A // b) * (B // a) * (C // c)  # different ways
# ans_4 = (A // b) * (B // c) * (C // a)  # and find the
# ans_5 = (A // c) * (B // a) * (C // b)  # best way to
# ans_6 = (A // c) * (B // b) * (C // a)  # place them
# max_number_of_laptops = ans_1
# if max_number_of_laptops < ans_2:
#     max_number_of_laptops = ans_2
# if max_number_of_laptops < ans_3:
#     max_number_of_laptops = ans_3
# if max_number_of_laptops < ans_4:
#     max_number_of_laptops = ans_4
# if max_number_of_laptops < ans_5:
#     max_number_of_laptops = ans_5
# if max_number_of_laptops < ans_6:
#     max_number_of_laptops = ans_6
# print(max_number_of_laptops)

# Task 20 : ice cream in a cafe
# 2 ways : 3 pieces and 5 pieces ---> can get k ??
# # if can --> k = 3x + 5y, x and y >= 0
# # simple solution for 3x+5y=1 --> (2,-1) or (-3,2)
# # x0 = k * 2, y0 = k * -1 ---> solutions are
# # x = x0 - m*5, y = y0 + m*3 ; x >= 0 and y >= 0
# k = int(input())
# x0 = 2 * k
# y0 = -k  # need y = y0 + 3 * m >= 0 ---> m >= -y0/3
# m_min = (-y0 + 2) // 3  # round up
# x = x0 - m_min * 5
# y = y0 + m_min * 3
# if x < 0:
#     print('NO')
# else:
#     print('YES')  # print('YES : x =', x, '  and y =', y)

# Task 21 : difficult equation (ax + b) / (cx + d) = 0
# know : c^2 + d^2 != 0
# a, b = int(input()), int(input())
# c, d = int(input()), int(input())
# numerator_has_null = True
# numerator_null = 0
# if a == 0 and b != 0:
#     numerator_has_null = False
# elif b != 0:
#     if b % a == 0:
#         numerator_null = -b // a
#     else:
#         numerator_has_null = False
# denominator_has_null = True
# denominator_null = 0
# if c == 0 and d != 0:
#     denominator_has_null = False
# elif d != 0:
#     if d % c == 0:
#         denominator_null = -d // c
#     else:
#         denominator_has_null = False
# if a == 0 and b == 0:
#     print('INF')
# elif not numerator_has_null:
#     print('NO')
# elif denominator_has_null and numerator_null == denominator_null:
#     print('NO')
# else:
#     print(numerator_null)

# TODO
# Task 22 : k cotlets on span can be at one time
# each cotlet must be fried for m minutes ; have n cotlets
# min time for frying n cotlets = ??
# k, m, n = int(input()), int(input()), int(input())
# rest = n % k
# full_span = n // k
# time = full_span * m * 2
# if rest != 0:
#     time += 2 * m
# print(time)


# THEORY 5 : while loop
#       print 1, 2, ..., 100
# i = 1
# while i <= 100:
#     print(i, end=' ')
#     i = i + 1
# print()
#       max of sequence
# now = int(input())
# maxNum = now
# while now != 0:
#     if now > maxNum:
#         maxNum = now
#     now = int(input())
# print(maxNum)


# Task 23 : square list
# N = int(input())
# i = 1
# while i ** 2 <= N:
#     print(i ** 2, end=' ')
#     i = i + 1
# print()

# Task 24 : min divisor of N >= 2
# N = int(input())
# min_divisor = 2
# while min_divisor <= N:
#     if N % min_divisor == 0:
#         print(min_divisor)
#         break
#     min_divisor += 1

# Task 25 : list of degrees of 2
# N = int(input())
# deg = 1
# while deg <= N:
#     print(deg, end=' ')
#     deg *= 2

# Task 26 : accurate degree of 2
# N = int(input())
# deg = 1
# isDegOfTwo = 'YES'
# while deg < N:
#     deg *= 2
# if deg != N:
#     isDegOfTwo = 'NO'
# print(isDegOfTwo)

# Task 27 : binary logarithm
# N = int(input())
# k = 1
# deg = 0
# while k < N:
#     k *= 2
#     deg += 1
# print(deg)

# Task 28 : morning jogging
# first day --> X km, every day 10% more
# need number of the day : he ran >= Y km
# X, Y = int(input()), int(input())
# day = 1
# while X < Y:
#     day += 1
#     X *= 1.1
# print(day)

# Task 29 : max of sequence ended by zero
#       max of sequence
# now = int(input())
# maxNum = now
# while now != 0:
#     if now > maxNum:
#         maxNum = now
#     now = int(input())
# print(maxNum)

# THEORY 6 : continue, sum of sequence
#       sum of sequence
# now = int(input())
# sumSeq = now
# while now != 0:
#     now = int(input())
#     sumSeq += now
# print(sumSeq)
#       operator continue
#       print only positive numbers
# now = int(input())
# while now != 0:
#     if now > 0:
#         print(now)
#     now = int(input())
#           another way
# now = -1
# while now != 0:
#     now = int(input())
#     if now <= 0:
#         continue
#     print(now)


# Task 30 : sum of squares
# N = int(input())
# sumSquares = 0
# while N > 0:
#     sumSquares += N * N
#     N -= 1
# print(sumSquares)

# Task 31 : len of sequence
# lenSeq = -1
# now = -1
# while now != 0:
#     now = int(input())
#     lenSeq += 1
# print(lenSeq)

# Task 32 : sum pf sequence
#       sum of sequence
# now = int(input())
# sumSeq = now
# while now != 0:
#     now = int(input())
#     sumSeq += now
# print(sumSeq)

# Task 33 : average of sequence
# lenSeq = -1
# now = -1
# sumSeq = 0
# while now != 0:
#     now = int(input())
#     lenSeq += 1
#     sumSeq += now
# print(sumSeq / lenSeq)

# Task 34 : count even numbers in sequence
# cntEvenNum = 0
# now = int(input())
# while now != 0:
#     if now % 2 == 0:
#         cntEvenNum += 1
#     now = int(input())
# print(cntEvenNum)

# Task 35 : count number > previous
# cntBiggerPreviousNum = 0
# prev, now = -1, -1
# lenSeq = 0
# while now != 0:
#     if lenSeq >= 2 and now > prev:
#         cntBiggerPreviousNum += 1
#     prev = now
#     now = int(input())
#     lenSeq += 1
# print(cntBiggerPreviousNum)

# Task 36 : second max in sequence of integer numbers > 0
# now = int(input())
# max_1, max_2 = now, -1
# lenSeq = 1
# while now != 0:
#     if lenSeq >= 2:
#         if now > max_1:
#             max_2 = max_1
#             max_1 = now
#         elif now > max_2:
#             max_2 = now
#     now = int(input())
#     lenSeq += 1
# print(max_2)

# Task 37 : count numbers that = max og sequence
# now = int(input())
# max_1 = now
# cnt_max = 1
# lenSeq = 1
# while now != 0:
#     if lenSeq >= 2:
#         if now > max_1:
#             cnt_max = 1
#             max_1 = now
#         elif now == max_1:
#             cnt_max += 1
#     now = int(input())
#     lenSeq += 1
# print(cnt_max)

# Task 38 : Fibbonachi's numbers, F[0] = 0, F[1] = 1
# N = int(input())
# F0, F1, F2 = 0, 1, 1
# i = 2
# while i <= N:
#     F2 = F0 + F1
#     F0 = F1
#     F1 = F2
#     i += 1
# print(F2)

# Task 39 : Fibbonachi's number's number (order)
# A, N = int(input()), 0
# F0, F1, F2 = 0, 1, 1
# if A == F0:
#     print(0)
# elif A == F1:
#     print(1)
# else:
#     i = 2
#     while F2 < A:
#         F2 = F0 + F1
#         F0 = F1
#         F1 = F2
#         i += 1
#     i -= 1
#     if F2 == A:
#         print(i)
#     else:
#         print(-1)

# Task 40 : employee who divides task by 2
# 2 commands : "dec by 1" and "div by 2" (only even numbers)
# odd numbers can't be divided by 2
# A, B = int(input()), int(input())  # A > B
# # we want A ---> B with operations "-1" and ":2"
# # know : 2-->1 better be with ":2" for testing system
# while A > B:
#     if A % 2 == 0 and A >= 2 * B:
#         print(':2')
#         A /= 2
#     else:
#         print('-1')
#         A -= 1

# Task 41 : number reversion
# N = int(input())
# while N > 0:
#     print(N % 10, end='')
#     N //= 10

# Task 42 : number of palindromes from 1 to K
# K = int(input())
# num, cnt_palindromes = 1, 0
# while num <= K:
#     copy_num = num
#     reversed_num = 0
#     while copy_num > 0:
#         reversed_num = reversed_num * 10 + copy_num % 10
#         copy_num //= 10
#     if num == reversed_num:
#         cnt_palindromes += 1
#     num += 1
# print(cnt_palindromes)


# Task 43 : max number of equaled numbers in raw in sequence
# numbers are integers > 0 (natural numbers)
# now, prev = -1, -1
# lenEqualNum, maxLenEqualNum = 0, 0
# while now != 0:
#     now = int(input())
#     if now == prev:
#         lenEqualNum += 1
#     else:
#         if maxLenEqualNum < lenEqualNum:
#             maxLenEqualNum = lenEqualNum
#         lenEqualNum = 1
#     prev = now
# print(maxLenEqualNum)

# Task 44 : max len of asc/desc part of sequence
# now, prev = -1, -1  # all numbers > 0
# lenAscPart, maxLenAscPart = 1, 1
# lenDescPart, maxLenDescPart = 1, 1
# curPartIsAsc, curPartIsDesc = False, False
# while now != 0:
#     # print('now =', now, '   prev =', prev)
#     if now > prev:
#         if curPartIsAsc:
#             lenAscPart += 1
#         else:
#             lenAscPart = 1
#             if prev != -1:
#                 lenAscPart = 2
#         curPartIsAsc = True
#         curPartIsDesc = False
#     if now < prev:
#         if curPartIsDesc:
#             lenDescPart += 1
#         else:
#             lenDescPart = 2
#         curPartIsDesc = True
#         curPartIsAsc = False
#     if now == prev:
#         curPartIsDesc = False
#         curPartIsAsc = False
#         lenDescPart = 1
#         lenAscPart = 1
#     # print('lenAscPart =', lenAscPart, '   lenDescPart =', lenDescPart)
#     if maxLenAscPart < lenAscPart:
#         maxLenAscPart = lenAscPart
#     if maxLenDescPart < lenDescPart:
#         maxLenDescPart = lenDescPart
#     prev = now
#     now = int(input())
# maxLen = maxLenAscPart
# if maxLen < maxLenDescPart:
#     maxLen = maxLenDescPart
# print(maxLen)

# Task 45 : min distance between local maximums
# these 2 numbers are orders of 2 last maximums in sequence
# curLocalMaxNumber, lastLocalMaxNumber = -1, -1
# # these 2 numbers are minimum distances between local max
# minDistLocalMax = 0
# i = 0  # order of current number in sequence
# prev, now = -1, int(input())
# if now != 0:
#     nextNum = int(input())
#     while nextNum != 0:
#         i += 1
#         if prev != -1 and prev < now > nextNum:
#             if lastLocalMaxNumber != -1:
#                 curDistLocalMax = i - lastLocalMaxNumber
#                 if minDistLocalMax == 0 or curDistLocalMax < minDistLocalMax:
#                     minDistLocalMax = curDistLocalMax
#             lastLocalMaxNumber = i
#             #  print(lastLocalMaxNumber, minDistLocalMax)
#         prev = now
#         now = nextNum
#         nextNum = int(input())
# print(minDistLocalMax)
