# Task 1 : number of distinct numbers
# print(len(set(map(int, input().split()))))

# Task 2 : number of words in text
# file method read() reads all in one string
# import sys                                # solution is correct
# print(                                    # but Coursera doesn't like
#     len(                                  # comments --> send only code
#         set(                              # in tmp.py file
#             sys.stdin.read().split()
#         )
#     )
# )

# Task 3 : the least odd number
# import functools
#
# print(
#     functools.reduce(
#         min,
#         list(map(
#             int,
#             filter(
#                 lambda x: int(x) % 2 == 1,
#                 input().split()
#             )
#         ))
#     )
# )

# Task 4 : zero or not zero in N numbers
# import sys
#
# # other way :
# print(
#     any(
#         map(
#             lambda x: int(x) == 0,
#             sys.stdin.read().split()
#         )
#     )
# )

# Task 5 : product of fifth degrees
# import functools
# import sys
#
# print(
#     functools.reduce(
#         lambda x, y: x * y,
#         map(
#             lambda x: int(x) ** 5,
#             sys.stdin.read().split()
#         )
#     )
# )

# Task 6 : XOR
# xor(0,0)=0, xor(1,0)=1, xor(0,1)=1, xor(1,1)=0,
# a_i, b_i : 0 or 1 ---> print {c_i} = xor(a_i, b_i)
# print(
#     *list(
#         map(
#             lambda x: (x[0] + x[1]) % 2,
#             zip(
#                 map(
#                     int,
#                     input().split()
#                 ),
#                 map(
#                     int,
#                     input().split()
#                 )
#             )
#         )
#     )
# )

# Task 7 : partial sums of sequence
# import itertools
#
# print(
#     *itertools.accumulate(
#         map(
#             int,
#             input().split()
#         ),
#         lambda x, y: x + y     # if use sum() ---> Error ...
#     )
# )

# Task 8 : factorials 0!, ...n!
# import itertools
#
# print(
#     1,
#     *itertools.accumulate(
#         range(1, int(input()) + 1),
#         lambda x, y: x * y     # we should use lambda func
#     )
# )

# Task 9 : all permutations with fixed len
# N ---> (1, ..., N) --> permutations (0 < N < 10)
# import functools
# import itertools
#
# print(
#     *list(
#         map(
#             lambda x: functools.reduce(
#                 lambda y, z: str(y) + str(z),
#                 x
#             ),
#             itertools.permutations(range(1, int(input()) + 1))
#         )
#     ),
#     sep='\n'
# )

# Task 10 : XOR - 2
# 'recursive' XOR
# xor(a_1,a_2,…,a_n)= xor(a_1, xor(a_2, xor(a_3,… xor(a_n))…)
# XOR of sequences k-elements A_1, ..., A_n, where sequence
#       A_i = (A_i[1], ..., A_i[k]) --> also is sequence C = (C[1]...C[k])
# C[j] = xor(A_1[j], ..., A_n[j]), 1 <= j <= k
# 2 <= n <= 1000, n sequences on n lines
# import functools
# import sys
# input, save
# zip(*map(lambda x: map(int, x.split()), sys.stdin.readlines()[1:]))
# print(*map(lambda x: x.split(), sys.stdin.readlines()[:]))
# print(*map(lambda x: x.split(), sys.stdin.readlines()[:]))
# soltuion of the task :
# import sys
# import functools
# print(
#     *map(
#         lambda tmp_tuple: functools.reduce(
#             lambda bit1, bit2: (int(bit1) + int(bit2)) % 2,
#             tmp_tuple
#         ),
#         zip(*map(lambda x: x.split(), sys.stdin.readlines()[1:]))
#     )
# )
# save
# xor
# output

# Task 11 : prime numbers
# print all prime numbers in [2, n], 2 <= n <= 100000
# import functools
#
# # slow
# print(
#     *filter(
#         lambda num: num in {2, 3, 5} or not functools.reduce(
#             lambda bool1, bool2: bool2 or bool1,
#             map(lambda d: num % d == 0, range(2, int(num ** 0.5) + 1))
#         ),
#         range(2, int(input()) + 1)
#     )
# )
# # faster --> check only set() of 2 elements : True, False
# print(
#     *filter(
#         lambda num: num in {2, 3, 5} or True not in set(
#             map(lambda d: num % d == 0, range(2, int(num ** 0.5) + 1))
#         ),
#         range(2, int(input()) + 1)
#     )
# )

# Task 12 : 1xbet ---> ... ?)) rates, bets (money on sport) (look below)
# import itertools

# 1 2  # ---> get all triples
# 3 4  # where digit1 1 is from 1 line
# 5 6  # digit2 from 2 line, ...
# import sys
# import itertools
# DOESn't WORK
# someLists = [[1, 2], [3, 4], [5, 6]]
# print(
#     *itertools.product(
#         someLists
#     )
# )

# WORKS
# someLists = [[1, 2], [3, 4], [5, 6]]
# print(
#     *itertools.product(
#         *someLists
#     )
# )

# WORKS
# somelists = [
#    [1, 2, 3],
#    ['a', 'b'],
#    [4, 5]
# ]
#
# import itertools
# for element in itertools.product(*somelists):
#     print(element)

# some .... 'playing' with itertools
# def combine_input(level, *args):
#     print(*args, '\n\n')
#     print(list(args), '\n\n')
#     for x in itertools.product(*args):
#         print(x)
#     print('\n' * 3)


# TMP task : check if there are 2 strings that are reversed to each other
# import sys
# import itertools
# print(
#     len(
#         list(
#             filter(
#                 lambda pair: pair[0] == pair[1][::-1],
#                 itertools.combinations(
#                     map(lambda line: line.strip(), sys.stdin.readlines()), 2
#                 )
#             )
#         )
#     ) == 0
# )


# not finish version
# import sys
# import itertools
# print(
#    *filter(
#        lambda x: x[0] != x[1],
#        itertools.product(
#             *list(
#                 map(
#                    lambda x: (x.split()[0:2], x.split()[2:4]),
#                    sys.stdin.readlines()
#                 )
#             )
#         )
#     ),
#     sep='\n'
# )


#  not Decart's prosuct ---> only lists
# print(
#     *itertools.product(
#         *[
#             *zip([1, 2], [3, 4], [5, 6])
#         ]
#     ),
#     sep='\n'
# )

# Decart's product
# print(
#     *itertools.product(
#         *[
#             [1, 2], [3, 4], [5, 6]
#         ]
#     ),
#     sep='\n'
# )



#
# NOT THAT I WANTED (NOT DEKART'S PRODUCT)
# print(
#     *itertools.combinations(
#         [
#             [(2, 1), (2, 3)],
#             [(1, 2), (3, 2)]
#         ],
#         2
#     )
# )

# THAT I WANTED
# PRODUCT OF 2 SETS
# somelist = [[(2, 1), (2, 3)],
#             [(1, 2), (3, 2)]]
# print(
#     *itertools.product(
#         *somelist
#     ),
#     sep='\n'
# )

# Task 12 : races and bets for them
# K = # of animals, N = number of people
# every person --> 2 bets , 1 bet = 'A B' (A faster than B)
# 2 bets in line for every of N people ---> N lines with 4 numbers A B C D
# we need to know : can be only one bet be correct for every of N people
# if YES --> print the race's result, if NO --> print 0

# someone's solution

# import itertools
# import operator
#
# print(next(map(lambda a:
#                ' '.join(map(str, a[0])),
#                filter(lambda a: all(map(lambda b: operator.xor(
#                    *map(lambda c: c in itertools.combinations(a[0], 2), b, )),
#                                         a[1])), (
#                           lambda a, b: zip(itertools.permutations(a),
#                                            itertools.repeat(b)))(
#                    *(lambda k, n: (range(1, k + 1),
#                                    tuple(map(lambda i: (i[:2], i[2:]),
#                                              map(lambda _: tuple(
#                                                  map(int, input().split())),
#                                                  range(n)))))
#                      )(*map(int, input().split()))))), 0))

# someone's solution
# import itertools
# import operator
#
# print(next(map(lambda a:
#                ' '.join(map(str, a[0])),
#                filter(lambda a: all(map(lambda b: operator.xor(
#                    *map(lambda c: c in itertools.combinations(a[0], 2), b, )),
#                    a[1])), (
#                    lambda a, b: zip(itertools.permutations(a),
#                                     itertools.repeat(b)))(
#                    *(lambda k, n: (range(1, k + 1),
#                                    tuple(map(lambda i: (i[:2], i[2:]),
#                                              map(lambda _: tuple(
#                                                  map(int, input().split())),
#                                                  range(n)))))
#                      )(*map(int, input().split()))))), 0))

# someone's solution
# not enough functional
# from itertools import permutations
#
#
# def is_win_bet(bet, race):
#     return bet == tuple(filter(lambda i: i == bet[0] or i == bet[1], race))
#
#
# def is_win_player(player, race):
#     return is_win_bet(player[0], race) ^ is_win_bet(player[1], race)
#
#
# def is_win_race(players, race):
#     return all(map(lambda x: is_win_player(x, race), players))
#
#
# # def win_race(players, races):
# #    return next(filter(lambda x: is_win_race(players, x), races), [0])
# def win_race(ps_rs):
#     return next(filter(lambda x: is_win_race(ps_rs[0], x), ps_rs[1]), [0])
#
#
# def read_info():
#     return (lambda x: [list(
#                          map(
#                              lambda y: [(y[0], y[1]), (y[2], y[3])],
#                              map(
#                                  lambda z: list(map(int,
#                                                     input().split()
#                                                     )
#                                                 ),
#                                  range(x[1])
#                                 )
#                             )
#                         ),
#                        list(permutations(range(1, x[0] + 1)))
#                        ]
#             )(list(map(int, input().split())))
#
#
# print(*win_race(read_info()))

