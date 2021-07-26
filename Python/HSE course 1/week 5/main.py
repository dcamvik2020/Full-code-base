# THEORY 1 : tuples
# tuples can store different types
# non-changeable type
# example of const tuple : testTuple = (1, 2, 3)
# operations with string ---> with tuples
# a = (1, 2, 3)    # for strings s1 and s2
# b = (4, 5, 6)    # s1 + s2 = s --- string too
# print(a + b)     # for tuples t1, t2 : t1+t2 tuple too
# (1, 2) * 2 = (1, 2, 1, 2) --- like for strings
# (1,2) + (3,4) = (1,2,3,4)     # parenthesis are important
# 1,2 + 3,4 = 1,5,4

# THEORY 2 : create tuples
# from string s='string' : new_tuple = tuple(s)
# str(tuple) = new_string
# len(new_tuple)
# indexes (even negative) are allowed : new_tuple[3]
# myTuple = (('a', 1, 3.14), 'abc', ((1), (2, )))
# ----> myTuple[0] = ('a', 1, 3.14) -- tuple
# ----> myTuple[1] = 'abc'          -- string
# ----> myTuple[2] = ((1), (2, ))   -- tuple
# tuple with one element : singleton = (x, )
# ----> myTuple[2][1] = (2, )
# ----> myTuple[2][1][0] = 2

# THEORY 3 : tuple cuts (like string cuts)
# cut, 1 param(s) ---> element
# cut, 2 param(s) ---> several elements (subtuple)
# cut, 3 param(s) ---> from, to, step
# print((1, 2, 3)[2]) = 3
# print((1, 2, 3)[1:]) = (2, 3)
# print((1, 2, 3)[2:]) = (3, ) ----- singleton (tuple with 1 element)

# THEORY 4 : tuple unpacking
# manDesc = ('Ivan', 'Ivanov', 28)
# firstName, lastName, age = manDesc
# elements of tuple are copied to other variables

# THEORY 5 : function range()
# range() ----> type iterable (sequence access), all numbers
# print iterable : print(tuple(range(10)))
# range(n) = iterable of (0, 1, 2, ..., n-1)
# range(from, to) = (from, ..., to - 1)
# range(from, to, set) = (from, from + step, ...)
# range(10, 0, -2) = (10, 8, 6, 4, 2)

# THEORY 6 : cycle for
# works with iterable types (iterable or tuple)
# for color in ('red', 'blue', 'green'):
#     print(color, end=' ')
# for i in range(1, 11):
#     for j in range(1, 11):
#         print(i*j, end=' ')
#     print()


# Task 1 : sequence - 1
# print all numbers from A to B inclusively
# A, B = int(input()), int(input())  # A <= B
# for x in range(A, B + 1):
#     print(x, end=' ')

# Task 2 : sequence - 2
# print all numbers from A to B
# if A =< B --> ascending, else --> descending
# A, B = int(input()), int(input())
# if A <= B:
#     for x in range(A, B + 1):
#         print(x, end=' ')
# else:
#     for x in range(A, B-1, -1):
#         print(x, end=' ')

# Task 3 : sequence - 3
# N ---> print all odd numbers with N digits descending
# N = int(input())
# for x in range(10 ** N - 1, 10 ** (N-1) - 1, -2):
#     print(x, end=' ')

# Task 4 : squares sum 1^2 + ... + N^2
# N = int(input())
# sumSquares = 0
# for x in range(1, N + 1):
#     sumSquares += x * x
# print(sumSquares)

# Task 5 : Flags (draw N flags with numbers within them)
# N = int(input())  # 1 <= N <= 9
# for i in range(N):
#     print('+___ ', end='')
# print()
# for i in range(1, N+1):
#     print('|' + str(i) + ' / ', end='')
# print()
# for i in range(N):
#     print('|__\ ', end='')
# print()
# for i in range(N):
#     print('|    ', end='')

# Task 6 : numbers of zeros in sequence
# N = int(input())
# cntZeros = 0
# for i in range(N):
#     x = int(input())
#     if x == 0:
#         cntZeros += 1
# print(cntZeros)

# Task 7 : stairs (1 <= N <= 9)
# step i is like "123...i"
# N = int(input())
# for i in range(1, N+1):
#     for j in range(1, i+1):
#         print(j, end='')
#     print()

# Task 8 : nice numbers - 1
# print 2-digit numbers that = 2 * digits_product
# for num in range(10, 100):
#     d1, d2 = num // 10, num % 10
#     if num == 2 * d1 * d2:
#         print(num, end=' ')

# Task 9 : Diafant's equation - 2
# (ax^3 + bx^2 + cx + d) / (x-e) = 0 --> count
# solutions from 0 to 1000 inclusively
# a, b, c = int(input()), int(input()), int(input())
# d, e = int(input()), int(input())
# cntSolutions = 0
# for x in range(1001):
#     if x == e:
#         continue
#     if a * x**3 + b * x**2 + c * x + d == 0:
#         cntSolutions += 1
# print(cntSolutions)

# Task 10 : sum of factorials 1! + ... + n!
# n = int(input())
# sumFactorial = 0
# curFactorial = 1
# for i in range(1, n+1):
#     curFactorial *= i
#     sumFactorial += curFactorial
# print(sumFactorial)

# Task 11 : N-1 numbers from 1 to N , find "lost"
# N = int(input())
# lostNumber = 0
# for i in range(1, N):
#     x = int(input())
#     lostNumber ^= x
#     lostNumber ^= i
# lostNumber ^= N
# print(lostNumber)

# Task 12 : nice numbers - 4
# from A to B print all 4-dogots palindroms
# A, B = int(input()), int(input())
# for num in range(A, B+1):
#   part1, part2 = num // 100, num % 100
#   isPalindrome = (part1 % 10 == part2 // 10) and (part1 // 10 == part2 % 10)
#   if isPalindrome:
#     print(num)


# THEORY 7 : lists
# list ~ array, vector
# list = set of references to objects
# list is changeable (but not tuple)
# const list : my_list = [1, 2, 3]
# all other features are like for tuples
# easy : tuples <----> lists : tuple() or list()
# list() can be applied for string --> list of chars
# list('abc') = ['a', 'b', 'c']
# list() ----> len(my_list), cuts like string cuts
# cuts work like as for tuples
# myList = [1, 2, 3]      # list is changeable
# myList[1] = 4           # OK, takes O(1) time
# print(myList)

# THEORY 8 : changing lists
# list = reference to list of references
# a = [1, 2]   # list = reference
# b = a        # in Python "=" <--> creating reference
# b[0] = 3     #
# print(a)     #
# its changeable (mutable) ---> 2 equaled lists = 2 objects
# EXAMPLE
# a = [1, 2]   # 1 object
# b = [1, 2]   # 2 object
# a[0] = 3     # change 1 object
# print(b)     # print [1, 2] = 2 object != 1 object
# ANOTHER EXAMPLE
# a = [1, 2]   # 1 object
# b = a        # 2nd reference to 1 object
# a = [3, 4]   # 1st reference to 2 object
# print(b)     # print 1 object by 2nd reference

# THEORY 9 : lists as functions params
# def replaceFirst(myList):    # myList = reference ---> changeable
#     myList[0] = 'x'          # change list (content) by reference
# nowList = list('abcdef')     # ['a', 'b', 'c', 'd', 'e', 'f']
# replaceFirst(nowList)        # this function changes list
# print(nowList)               # ['x', 'b', 'c', 'd', 'e', 'f']
# important : reference can't be changed by function
# ---> list's content can be changed,
# ---> reference to the list --- NO (myList = anotherList)
# EXAMPLE
# def reverseList(funcList):      # mainList = ['a','b','c']
#     funcList = funcList[::-1]   # funcList = mainList
# mainList = list('abc')          # funcList = funcList[::-1]
# reverseList(mainList)           # print(mainList) --- ['a','b','c']
# print(mainList)                 # look higher ---> theory for answer
# it's because cut operation doesn't change old, creates new object

# THEORY 10 : string's method split
# string.split() ----> string for words (tokens)
# separator can be ' ', '\t' or '\n' (several in raw -- OK)
# split() DOESN'T change string, returns list of tokens
# 'red green        blue'.split() = ['red', 'green', 'blue']

# THEORY 11 : map(func, iterable_object)
# func() is applied for every element of iterable_object
# map() returns another_iterable_object of results
# list(map(len, ['red', 'green', 'blue'])) = [3, 5, 4]

# THEORY 12 : string's method split() and function map()
# myList = list(map(int, input().split())) --- read numbers from line

# THEORY 13 : string's method join()
# join() unites ITERABLE OF STRINGS (ONLY) via some string
# ', '.join(['Veni', 'Vidi', 'Vici'])
# ', ' = separator ---> after last word NOT placed


# tASK 13 : print numbers with even indexes
# numbers are on one line
# map(int, input().split()) ---> iterable object
# list(...)[::2] -----> create list and its cut
# print(*list(map(int, input().split()))[0::2])

# tASK 14 : print even numbers in list
# numbers are on one line
# map(int, input().split()) ---> iterable object
# numList = list(map(int, input().split()))
# for num in numList:
#     if num % 2 == 0:
#         print(num, end=' ')

# Task 15 : number of positive numbers
# numbers are on one line
# numList = list(map(int, input().split()))
# cntPositive = 0
# for num in numList:
#     if num > 0:
#         cntPositive += 1
# print(cntPositive)

# Task 16 : last max element in list
# numbers are on one line
# find max value and index of last max
# numList = list(map(int, input().split()))
# maxNum, maxLastID = numList[0], 0
# for i in range(len(numList)):
#     if numList[i] >= maxNum:
#         maxNum = numList[i]
#         maxLastID = i
# print(maxNum, maxLastID)

# Task 17 : print numbers that are bigger predecessor
# numbers are on one line
# numList = list(map(int, input().split()))
# for i in range(1, len(numList)):
#     if numList[i] > numList[i-1]:
#         print(numList[i], end=' ')

# Task 18 : is the list ascending or not ?
# def IsAscending(A):
#     asc = True
#     for i in range(1, len(numList)):
#         if numList[i - 1] >= numList[i]:
#             asc = False
#             break
#     return asc
# numList = list(map(int, input().split()))
# if IsAscending(numList):
#     print('YES')
# else:
#     print('NO')

# Task 19 : neighbours of one sign
# no one such pair -- print nothing
# several pairs -- print first
# numList = list(map(int, input().split()))
# for i in range(1, len(numList)):
#     if numList[i - 1] * numList[i] > 0:
#         print(numList[i - 1], numList[i])
#         break

# Task 20 : bigger neighbours
# numList = list(map(int, input().split()))
# cntElemsBiggerNeighbours = 0
# for i in range(1, len(numList) - 1):
#     if numList[i - 1] < numList[i] > numList[i + 1]:
#         cntElemsBiggerNeighbours += 1
# print(cntElemsBiggerNeighbours)

# Task 21 : max element
# numList = list(map(int, input().split()))
# maxNum, maxLastID = numList[0], 0
# for i in range(len(numList)):
#     if numList[i] > maxNum:
#         maxNum = numList[i]
#         maxLastID = i
# print(maxNum, maxLastID)

# Task 22 : min positive (1 positive at least exist)
# numList = list(map(int, input().split()))
# minPositive = 1001  # know : abs of any element <= 1000
# for i in range(len(numList)):
#     if 0 < numList[i] < minPositive:
#         minPositive = numList[i]
# print(minPositive)

# Task 23 : min odd number (1 odd at least exists)
# numList = list(map(int, input().split()))
# minOdd = 0  # for first odd number
# for i in range(len(numList)):
#     if numList[i] % 2 == 1 and (minOdd == 0 or numList[i] < minOdd):
#         minOdd = numList[i]
# print(minOdd)

# Task 24 : reverse list with no modification
# numList = list(map(int, input().split()))
# for i in range(len(numList) - 1, -1, -1):
#     print(numList[i], end=' ')

# Task 25 : reverse list with no modification
# but here we need to swap A[0] with A[A.size() - 1], ...
# numList = list(map(int, input().split()))
# listLen = len(numList)
# for i in range(listLen // 2):
#     numList[i], numList[listLen-1-i] = numList[listLen-1-i], numList[i]
# print(*numList)


# THEORY 14 : useful methods for lists
# NOT CHANGING LIST, RETURNING VALUE :
#       count(x)         O(N)
#       index(x)         O(N)   first index
#       index(x, from)
# CHANGING LIST, NOT RETURNING VALUE :
#       append(x)
#       extend(otherList)     otherList to the end
#       remove(x)             O(N)    first index
#       insert(x, index)      O(N)
#       reverse()             O(N)
# CHANGING LIST, RETURNING VALUE :
#       pop()                 removes, returns last element
#       pop(index)            removes, returns list[index], O(N)


# Task 26 : remove element with index k without pop(index)
# do not use other list
# numList = list(map(int, input().split()))
# k = int(input())
# numList = numList[0:k] + numList[k+1:]
# print(*numList)

# Task 27 : insert element in index k without insert(x, index)
# do not use other list
# numList = list(map(int, input().split()))
# k, C = tuple(map(int, input().split()))
# numList = numList[0:k] + [C] + numList[k:]
# print(*numList)


# THEORY 15 : modifying lists
# example : remove all odd numbers from the list
# way 1: (wrong solution)
# numbers = list(map(int, input().split()))
# for i in range(len(numbers)):
#     if numbers[i] % 2 != 0:
#         numbers.pop(i)
# print(' '.join(map(str, numbers)))
# way 2:
# (OK, but not effective) ---> O(N^2)
# numbers = list(map(int, input().split()))
# i = 0
# while i < len(numbers):
#     if numbers[i] % 2 != 0:
#         numbers.pop(i)
#     else:
#         i += 1
# print(' '.join(map(str, numbers)))
# way 3:
# if we have enough memory ---> O(N), O(N)
# numbers = list(map(int, input().split()))
# newList = []
# for i in range(len(numbers)):
#     if numbers[i] % 2 == 0:
#         newList.append(numbers[i])
# print(' '.join(map(str, newList)))


# Task 28 : nearest number
# N = int(input())  # array size
# myList = list(map(int, input().split()))
# x = int(input())  # "aim" number --> find nearest to it
# nearest = myList[0]
# for i in range(1, N):
#     if abs(x - myList[i]) < abs(x - nearest):
#         nearest = myList[i]
# print(nearest)

# Task 29 : find index for x to insert in list
# list of not ascending numbers ---> if there
# are other x --> insert after all of them
# myList = list(map(int, input().split()))
# x = int(input())
# id = 0
# while id < len(myList):
#     if myList[id] < x:
#         break
#     id += 1
# print(id + 1)  # since indexes from 1

# Task 30 : count different elements
# list is not descending
# myList = list(map(int, input().split()))
# cntDifferent = 0
# prev = myList[0] + 1
# for i in range(len(myList)):
#     if myList[i] != prev:
#         cntDifferent += 1
#     prev = myList[i]
# print(cntDifferent)

# Task 31 : swap neighbours
# myList = list(map(int, input().split()))
# for i in range(0, len(myList), 2):
#     if i == len(myList) - 1:
#         break
#     myList[i], myList[i+1] = myList[i+1], myList[i]
# print(*myList)

# Task 32 : cycle move to the right
# do not use cuts
# myList = list(map(int, input().split()))
# last = myList[len(myList) - 1]
# for i in range(len(myList) - 1, 0, -1):
#     myList[i] = myList[i-1]
# myList[0] = last
# print(*myList)

# Task 33 : swap min, max in list (all numbers are different)
# myList = list(map(int, input().split()))
# minID, maxID = 0, 0
# for i in range(1, len(myList)):
#     if myList[i] > myList[maxID]:
#         maxID = i
#     elif myList[i] < myList[minID]:
#         minID = i
# myList[minID], myList[maxID] = myList[maxID], myList[minID]
# print(*myList)

# Task 34 : find 2 numbers with max product
# myList = list(map(int, input().split()))
# min1, min2 = myList[0], myList[0]
# max1, max2 = myList[0], myList[0]
# for i in range(1, len(myList)):
#     if myList[i] >= max1:
#         max2 = max1
#         max1 = myList[i]
#     elif myList[i] > max2:
#         max2 = myList[i]
#     if myList[i] <= min1:
#         min2 = min1
#         min1 = myList[i]
#     elif myList[i] < min2:
#         min2 = myList[i]
# if min2 >= 0 or min1 * min2 <= max1 * max2:
#     print(max2, max1)
# else:
#     print(min1, min2)

# Task 35 : find 3 numbers with max product
# myList = list(map(int, input().split()))
# min1, min2, min3 = 0, -1, -1  # indexes : -1 means don't know index
# max1, max2, max3 = 0, -1, -1  # indexes : -1 means don't know index
# for i in range(1, len(myList)):
#     if myList[i] >= myList[max1]:
#         max3 = max2
#         max2 = max1
#         max1 = i
#     elif myList[i] >= myList[max2] or max2 == -1:
#         max3 = max2
#         max2 = i
#     elif myList[i] > myList[max3] or max3 == -1:
#         max3 = i
#     if myList[i] <= myList[min1]:
#         min3 = min2
#         min2 = min1
#         min1 = i
#     elif myList[i] <= myList[min2] or min2 == -1:
#         min3 = min2
#         min2 = i
#     elif myList[i] < myList[min3] or min3 == -1:
#         min3 = i
# IDs = [min1, min2, min3, max3, max2, max1]    # save 'extremal' indexes
# # print('IDs =', *IDs)
# IDsDistinct = []                              # remove duplicates
# for i in IDs:
#     if IDsDistinct.count(i) == 0:
#         IDsDistinct.append(i)
# # print('IDsDisticnt =', *IDsDisticnt)
# newList = []                                  # get <= 6 elements
# for i in IDsDistinct:
#     newList.append(myList[i])
# maxProduct = newList[0] * newList[1] * newList[2]
# id1, id2, id3 = 0, 1, 2                       # get max product for newList
# for i in range(len(newList)):                 # O(1) iterations
#     for j in range(i+1, len(newList)):        # O(1) iterations
#         for k in range(j+1, len(newList)):    # O(1) iterations
#             if newList[i] * newList[j] * newList[k] > maxProduct:
#                 maxProduct = newList[i] * newList[j] * newList[k]
#                 id1, id2, id3 = i, j, k
# print(newList[id1], newList[id2], newList[id3])  # total O(N)

# Task 36 : count equaled pairs
# myList = list(map(int, input().split()))
# N = len(myList)
# cntEqualPairs = 0
# for i in range(N):
#     for j in range(i+1, N):
#         if myList[i] == myList[j]:
#             cntEqualPairs += 1
# print(cntEqualPairs)

# Task 37 : unique elements (remove duplicates)
# myList = list(map(int, input().split()))
# N = len(myList)
# for i in range(N):
#     if myList.count(myList[i]) == 1:
#         print(myList[i], end=' ')

# Task 38 : N bottles in raw (1 2 3 ... N)
# throw K balls, ball_i kicks bottles from l_i to r_i
# which bottles are not kicked ?
# N, K = tuple(map(int, input().split()))
# areAlive = ['I'] * N
# for k in range(K):
#     l, r = tuple(map(int, input().split()))
#     for i in range(l, r+1):
#         areAlive[i-1] = '.'
# print(*areAlive, sep='')

# Task 39 : chess queens
# know : can put 8 queens on chess desk ---> they don't kick each other
# get the desk ---> are their pairs that kick partner ?
# queens = []  # positions of 8 queens on chess desk
# for i in range(8):
#     cur_queen_pos = list(map(int, input().split()))
#     queens.append(cur_queen_pos)
# rivalsExist = False  # exist 2 queens that kick each other
# for i in range(8):
#     x, y = tuple(queens[i])
#     for j in range(i+1, 8):
#         x1, y1 = tuple(queens[j])
#         canFight = x == x1 or y == y1 or abs(x - x1) == abs(y - y1)
#         if canFight:
#             rivalsExist = True
#             break
#     if rivalsExist:
#         break
# if rivalsExist:
#     print('YES')
# else:
#     print('NO')

# Task 40 : compress list
# move all zeros to the end of list
# save order of other numbers
# myList = list(map(int, input().split()))
# read, write, end = 0, 0, len(myList)
# while read != end:
#     if myList[read] == 0:
#         read += 1
#         continue
#     myList[write] = myList[read]
#     read += 1
#     write += 1
# while write != end:
#     myList[write] = 0
#     write += 1
# print(*myList)

# Task 41 : most frequent number
# no changing list, no creating other lists
# myList = list(map(int, input().split()))
# size = len(myList)
# maxCount, ans = -1, -1
# for i in range(size):
#     curCnt = myList.count(myList[i])
#     if maxCount == -1 or curCnt > maxCount:
#         ans = myList[i]
#         maxCount = curCnt
# print(ans)
