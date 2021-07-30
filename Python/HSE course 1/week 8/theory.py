# THEORY 1 : functional programming
# ---> functions for working with sequences
#      old : sum, max, min, sort, map
#      new : filter (for sequence too)
# ______
# numbers = map(int, input().split())
# print(*filter(lambda x: x > 0, numbers)) ---> returns sequence
# other form of this:
# print(                           # 6 thing to read
#     *filter(                     # 5 thing to read
#         lambda x: x > 0,         # 4 thing to read
#         map(                     # 3 thing to read
#             int,                 # 1 thing to read
#             input().split()      # 2 thing to read
#         )
#     )                            # read from most deep level
# )                                $ to the highest level
# ______
# enumerate():
# numerates elems of sequence, has unnecessary param 'from'
# receives ANY ITERABLE
# print(*enumerate('abcde')) ---> return tuples (id, obj)
# file example :
# f = open('data.txt', 'r', encoding='utf8')
# for i, line in enumerate(f):
#     if line.strip() == '':
#         print('Blank line at line', i)
# ______
# any() : returns True if at least one == True
# all() : returns True if all == True
# example : all elems in sequence > 0
# print(
#     all(
#         map(
#             lambda x: x > 0,
#             map(
#                 int,
#                 input().split()
#             )
#         )
#     )
# )
# ______
# zip(iterA, iterB, ...) - returns tuples (iterA[0], iterB[0], ...),
#                                         (iterA[1], iterB[1], ...), ...


# THEORY 2 : DIFFICULT TASK
# in pure functional programming style
# N people ---> N taxes for their homes with different tariffs
# idea : who lives the furthest --> uses the cheapest taxi
#        sort 2 sequences (dist, cost) ---> max(dist) * min(cost), ...
# 1 way : readable
# pas = map(int, input().split())
# sortedPas = sorted(enumerate(pas), key=lambda x: x[1])
# taxi = map(int, input().split())
# sortedTaxi = sorted(enumerate(taxi), key=lambda x: x[1], reverse=True)
# ans = zip(sortedPas, sortedTaxi)
# sortedAns = sorted(ans, key=lambda x: x[0][0])
# print(*map(lambda x: x[1][0], sortedAns))
# 2 way : pure functional programming style
# print(
#     *map(
#         lambda x: x[1][0],
#         sorted(
#             zip(
#                 sorted(
#                     enumerate(
#                         map(
#                             int,
#                             input().split()
#                         )
#                     ),
#                     key=lambda x: x[1]
#                 ),
#                 sorted(
#                     enumerate(
#                         map(
#                             int,
#                             input().split()
#                         )
#                     ),
#                     key=lambda x: x[1],
#                     reverse=True
#                 )
#             ),
#             key=lambda x: x[0][0]
#         )
#     )
# )


# THEORY 3 : libraries 'itertools', 'functools'
# import itertools
# combinatorics --->
# itertools.combinations(iterable, size) returns tuples with size elems
# get combinations of K elems, K = second param
# print(*itertools.combinations([1, 2, 3], 1))
# permutations ---->
# lexicographical, of K elems = second param
# print(*itertools.permutations([1, 2, 3], 2))
# combinations with duplicates of K elems
# print(*itertools.combinations_with_replacement([1, 2, 3], 2))
# example:
# 3 numbers --> max product
# from itertools import combinations
#
# nums = list(map(int, input().split()))
# combs = combinations(range(len(nums)), 3)
# print(max(map(lambda x: nums[x[0]] * nums[x[1]] * nums[x[2]], combs)))
# ______
# import functools
# default parameters :
# prints = like extension for print()
# prints = functools.partial(print, end=' ')
# prints(1)  # prints '1'
# prints(2)  # prints on same line ' 2'
# prints(3)  # prints on same line ' 3'
# ______
# import functools
# reduce sequentially calculates result
# print(functools.reduce(lambda x, y: x + y, [1, 2, 3]))  # = 6 = 1 + 2 + 3
# import itertools
# accumulates temporary results ---> for prefixes of sequence, for example
# print(*itertools.accumulate([1, 4, 3, 5], max))  # 1 4 4 5 = local maximums


# EXAMPLES :
# 1) int(number_as_string, base_of_nubmber) ---> get in decimal
# binNum = '1010101'
# decNum = int(binNum, base=2)
# print(decNum)
# # or better :
# from functools import partial
#
# binStrToInt = partial(int, base=2)
# print(binStrToInt('10010'))
# ______
# 2) reduce's work :
#    myList = [A, B, C],
#    reduce(f, myList) -------> f(f(A, B), C)
# ---> we can get GCD of sequence
# from functools import reduce
# def gcd(a, b):
#     while b != 0:
#         a, b = b, a % b
#     return a
# print(reduce(gcd, map(int, input().split())))
# ______
# 3) accumulate's work:
#     itertools.accumulate(iterable, func)
#     returns iterable of all temporary results for prefixes
#     myList = [A, B, C]
#     accumulate(f, myList) ----> [A, f(A, B), f(f(A, B), C)]
# from itertools import accumulate
#
# print(*accumulate(map(int, input().split()), max))


# THEIRY 4 : iterators, generators
# s = 0                          # idea : not store all numbers
# for i in range(100 ** 3):      # know only the rule of getting
#     s += 1                     # next number
# print(s)

# iterators
# they have method __next__ and can get next element
# myList = [1, 2, 3]
# for i in iter(myList):   # way 1
#     print(i)
# for i in myList:         # way 2 = way 1
#     print(i)

# know the rule for getting next element with needed properties ... ?
# ---> create our own iterator, using special functions : generators
# our own range() : generator
# generator returns ITERABLE
# def myRange(n):
#     i = 0              # yield i ---> we stop function,
#     while i < n:       # return current i, remember i
#         yield i        # go to next line and do next command
#         i += 1         # myRange() -- generator
#
#
# s = 0
# for i in myRange(100 ** 3):
#     s += 1
# print(s)

# print all squares from 0 to 100
# def myRange_1(n):
#     i = 0
#     while i < n:
#         yield i**2
#         i += 1
#
#
# # sqrSum = 0
# for i in myRange_1(10):
#     print(i)

# difficult recursive generator
def genDecDigs(cntDigits, maxDigit):
    if cntDigits > 0:
        for nowDigit in range(maxDigit + 1):
            for tail in genDecDigs(cntDigits - 1, nowDigit):
                yield nowDigit * 10 ** (cntDigits - 1) + tail
    else:
        yield 0


print(*genDecDigs(2, 3))  # 0 10 11 20 21 22 30 31 32 33
