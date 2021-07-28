# Task 1 : merge not descending lists A,B
# def merge(a, b):
#     c = []  # need merged not ascending list
#     i, j = 0, 0
#     while i < len(a) or j < len(b):
#         if i == len(a):
#             c.append(b[j])
#             j += 1
#         elif j == len(b):
#             c.append(a[i])
#             i += 1
#         elif a[i] < b[j]:
#             c.append(a[i])
#             i += 1
#         else:
#             c.append(b[j])
#             j += 1
#     return c
#
#
# A = list(map(int, input().split()))
# B = list(map(int, input().split()))
# C = merge(A, B)
# print(*C)

# Task 2 : intersect ascending lists A,B
# in A, B all elements are different
# def Intersection(a, b):
#     c = []  # need ascending list too
#     i, j = 0, 0
#     while i < len(a) and j < len(b):
#         if a[i] < b[j]:
#             i += 1
#         elif a[i] > b[j]:
#             j += 1
#         else:
#             c.append(a[i])
#             i += 1
#             j += 1
#     return c
# A = list(map(int, input().split()))
# B = list(map(int, input().split()))
# C = Intersection(A, B)
# print(*C)


# THEORY 1 : sorting lists
# 1 way :
# list.sort()
# only for lists, modifies list
# myList = list(map(int, input().split()))
# myList.sort()
# print(' '.join(map(str, myList)))
# 2 way :
# sorted(param)
# for lists, tuples, strings, iterable
# returns sorted LIST always, no modification param
# myList = list(map(int, input().split()))
# sortedList = sorted(myList)
# print(' '.join(map(str, sortedList)))
# reverse
# list.sort(reverse=True)
# sorted(list, reverse=True)
# print(sorted((1, 3, 2)))             # [1, 2, 3]
# print(sorted(range(10, -1, -2)))     # [0, 2, 4, 6, 8, 10]
# print(sorted("cba"))                 # ['a', 'b', 'c']

# THEORY 2 : compare tuples, lists
# compare elem by elem, sequentially
# just like for strings
# (1, 2, 3) < (2, 3, 4)  ---> True
# [1, 2, 3] < [1, 2]      ---> False
# IMPORTANT :
# tuples at respecting positions have comparable elems
#     (1, 2) cmp ("Some text", 42) ----> ERROR
# BUT (1, 2) cmp (42, "Some text") ----> OK
# it is helpful in difficult tasks for sorting


# Task 3 : sorting with embedded sort
# N = int(input())
# myList = list(map(int, input().split()))
# myList.sort()
# print(*myList)

# Task 4 : shoes shop
# 1 pair of shoes can be put into another
# <----> difference in sizes >= 3
# ? = max # of shoes that customer can wear SIMULTANEOUSLY
# feet = int(input())  # customer's feet size
# shoes = list(map(int, input().split()))  # in shop
# shoes.sort()
# i = 0
# while i < len(shoes) and shoes[i] < feet:
#     i += 1
# ans, last_shoes = 0, -1
# while i < len(shoes):
#     if last_shoes == -1 or last_shoes + 3 <= shoes[i]:
#         last_shoes = shoes[i]
#         ans += 1
#     i += 1
# print(ans)

# Task 5 : creating archive
# size(store) can be < sum of sizes(users files)
# S, N = tuple(map(int, input().split()))
# sizes = []
# for i in range(N):
#     size = int(input())
#     sizes.append(size)
# sizes.sort()
# totalSize, cntSavedUsers = 0, 0
# for i in range(N):
#     if totalSize + sizes[i] > S:
#         break
#     totalSize += sizes[i]
#     cntSavedUsers += 1
# print(cntSavedUsers)


# THEORY 3 : parameter key
# in list.sort(key=func), sorted(list, key=func)
# EXAMPLE 1 :
# sort people by height ASCENDING
# with equaled heights --> lexicographical
# n = int(input())
# peopleList = []
# for i in range(n):
#     tempManData = input().split()
#     manData = (int(tempManData[0]), tempManData[1])
#     peopleList.append(manData)
# peopleList.sort()
# for manData in peopleList:
#     print(' '.join(map(str, manData)))
# EXAMPLE 2:
# sort people by height DESCENDING
# with equaled heights --> lexicographical too
# bad code with "tricks" (tough situation)
# n = int(input())
# peopleList = []
# for i in range(n):
#     tempManData = input().split()
#     manData = (-int(tempManData[0]), tempManData[1])
#     peopleList.append(manData)
# peopleList.sort()
# for badManData in peopleList:
#     manData = (-badManData[0], badManData[1])
#     print(' '.join(map(str, manData)))
# EXAMPLE
# FOR PARAM KEY: sort str by len
# n = int(input())
# strings = []
# for i in range(n):
#     strings.append(input())
# print('\n'.join(sorted(strings, key=len)))
# EXAMPLE
# FOR PARAM KEY : sort (x,y) by dist from (0,0)
# def dist(point):
#     return point[0] ** 2 + point[1] ** 2
#
# n = int(input())
# points = []
# for i in range(n):
#     point = tuple(map(int, input().split()))
#     points.append(point)
# points.sort(key=dist)
# for point in points:
#     print(' '.join(map(str, point)))


# Task 6 :
# point <---> number <---> coordinate
# on line : n + m points (2 sets of points : A, B)
# for each point in A find the nearest in B in input order
#  print not points, but their numbers in input
#  note : create list of pairs (point_A, initial_number_in_A)
#         create list of pairs (point_B, initial_number_in_B)
#         sort them (tmpA, tmpB) ascending
#         for point in A the nearest are neighbours
#         ---> choose 1 of 2
# n = int(input())
# A = list(map(int, input().split()))
# m = int(input())
# B = list(map(int, input().split()))
# # _____
# A_point_number = []
# B_point_number = []
# for i in range(n):
#     A_point_number.append((A[i], i))
# for j in range(m):
#     B_point_number.append((B[j], j))
# A_point_number.sort()
# B_point_number.sort()
# # _____
# cities = A_point_number
# castles = B_point_number
# # _____
# ans = [0] * n
# left, right, nearest = -1, -1, -1
# for i in range(n):
#     city_id = cities[i][1]
#     point = cities[i][0]
#     while left + 1 < m and castles[left + 1][0] < point:
#         left += 1
#     right = left + 1
#     if left == -1:
#         nearest = castles[right][1]
#     elif right == m:
#         nearest = castles[left][1]
#     else:
#         dist_left = abs(point - castles[left][0])
#         dist_right = abs(point - castles[right][0])
#         if dist_left < dist_right:
#             nearest = castles[left][1]
#         else:
#             nearest = castles[right][1]
#     ans[city_id] = nearest + 1  # id from 1
#     right = left
#     i += 1
# print(*ans)


# THEORY 4 : structures, classes
# in Python there is no pure structures
# we can use : namedtuple from collections
#              dictionaries
#              classes as structures (now about it)
# classes : remember the task about sorting people
#           by height descending and if h1=h2 -->
#           by name ascending (lexicographical)
# solution :
# class Man:
#     height = 0
#     name = ''
# def manKey(man):
#     return (-man.height, man.name)
# n = int(input())
# peopleList = []
# for i in range(n):
#     tempManData = input().split()
#     man = Man()
#     man.height = int(tempManData[0])
#     man.name = tempManData[1]
#     peopleList.append(man)
# peopleList.sort(key=manKey)
# for man in peopleList:
#     print(man.height, man.name)


# THEORY 5 : lambda functions
# get square of x ---> lambda x: x**2
# instead of sqr(x) : def sqr(x) \n return x ** 2
# can pass it in sort() and map()
# # _____
# example :
# print 1^2 ... 100^2
# print(' '.join(map(lambda x: str(x**2), range(1, 101))))
# # _____
# example :
# sort (x, y) by dist from (0,0)
# n = int(input())
# points = []
# for i in range(n):
#     point = tuple(map(int, input().split()))
#     points.append(point)
# points.sort(key=lambda point: point[0]**2 + point[1]**2)
# for point in points:
#     print(' '.join(map(str, point)))
# # _____
# note : lambda can have > 1 param
# note : function = object ---> reference !!
# def traditionalSqr(x):
#     return x**2
# # _____
# lambdaSqr = lambda x: x**2
# print(traditionalSqr(3))
# print(lambdaSqr(3))


# THEORY 6 : names params, ellipsis (...)
# it's like params with default values in C++
# print() : sep=, end=
# list.sort(), sorted(list) : key=
# our example :
# func() that prints any iterable_object of anything
# def printList(myList, sep=' '):
#     print(sep.join(map(str, myList)))
# printList([1, 2, 3])
# printList([3, 2, 1], sep='\n')

# THEORY 7 : ellipsis (...)
# random number of params
# def mySum(*args):
#     nowSum = 0
#     for now in args:
#         nowSum += now
#     return nowSum
# # _____
# print(mySum(1, 2))
# print(mySum(1, 2, 3, 4))
# # _____
# def myMin(first, *others):
#     nowMin = first
#     for now in others:
#         if now < nowMin:
#             nowMin = now
#     return nowMin
# # _____
# print(myMin(1))
# print(myMin(3, 1, 2))

# THEORY 8 : read till end of input
# - read text with N lines (N unknown)
# - best : not input(), but file methods reading fully and by line
# example :
# read input.txt
# write to output.txt
# inFile = open('input.txt', 'r', encoding='utf8')
# outFile = open('output.txt', 'w', encoding='utf8')
# lines = inFile.readlines()
# for line in lines:
#     print(line[-2::-1], file=outFile)   # cause of '\n' ??
# inFile.close()    # it works only with files that have
# outFile.close()   # '\n after the last line
# # _____
# we can use : for line in inFile
# without    : lines = inFile.readlines()
# # _____
# files are ITERABLE ---> can return line , not saving whole file
# method file.read() ---> saves all in one string with '\n'
# # _____
# read from console : import sys, use descriptor 'stdin' :
#       for line in sys.stdin: ... (END <--> Ctrl+D in Unix-like)


# Task 7 : average result for 9,10,11 grades
# read from input.txt, line by line
# file = open('input.txt', 'r', encoding='utf8')
# avg9, avg10, avg11 = 0, 0, 0
# cnt9, cnt10, cnt11 = 0, 0, 0
# for line in file:
#     if line == '\n':
#         break
#     line = line[:-1]
#     # print(line, end='\t')
#     name, surname, grade, result = tuple(line.split())
#     grade, result = int(grade), int(result)
#     # print(grade, result)
#     if grade == 9:
#         avg9 += result
#         cnt9 += 1
#     if grade == 10:
#         avg10 += result
#         cnt10 += 1
#     if grade == 11:
#         avg11 += result
#         cnt11 += 1
# avg9 /= cnt9
# avg10 /= cnt10
# avg11 /= cnt11
# print(avg9, avg10, avg11)
# file.close()

# Task 8 : sort list of competitors
# file : line = surname name school result
# out  : line = surname name result
# sorted by surname lexicographical
# from input.txt to output.txt
# def get_surname(line):
#     whitespace = line.find(' ')
#     return line[:whitespace]
# # _____
# inFile = open('input.txt', 'r', encoding='utf8')
# outFile = open('output.txt', 'w', encoding='utf8')
# lines = inFile.readlines()
# lines.sort(key=get_surname)
# # lines.remove('\n')
# # print((lines))
# for line in lines:
#     if line == '\n':
#         break
#     line = line[:-1]
#     name, surname, school, result = tuple(line.split())
#     print(name + " " + surname + " " + result, file=outFile)
# inFile.close()
# outFile.close()


# Task 9 : counting sort
# N numbers in [0, 100] --> sort not descending
# def CountSort(A):
#     cntNumbers = [0] * 101
#     for x in A:
#         cntNumbers[x] += 1
#     j = 0
#     for i in range(101):
#         if cntNumbers[i] == 0:
#             continue
#         while cntNumbers[i] > 0:
#             A[j] = i
#             j += 1
#             cntNumbers[i] -= 1
# myList = list(map(int, input().split()))
# CountSort(myList)
# print(*myList)

# Task 10 : keyboard (keys can broke)
# n keys, for every know its using limit
# k presses ---> which keys will broke ??
# n = int(input())
# keyLives = list(map(int, input().split()))
# k = int(input())
# presses = list(map(int, input().split()))  # 1 <= key <= n
# for key in presses:
#     keyLives[key - 1] -= 1
# for i in range(n):
#     if keyLives[i] < 0:
#         print('YES')
#     else:
#         print('NO')

# Task 11 : max result for each grade
# read from 'input.txt'
# file = open('input.txt', 'r', encoding='utf8')
# max9, max10, max11 = -1, -1, -1
# for line in file:
#     if line == '\n':
#         break
#     line = line[:-1]
#     name, surname, grade, result = tuple(line.split())
#     grade, result = int(grade), int(result)
#     if grade == 9 and max9 < result:
#         max9 = result
#     if grade == 10 and max10 < result:
#         max10 = result
#     if grade == 11 and max11 < result:
#         max11 = result
# print(max9, max10, max11)
# file.close()

# Task 12 : olympiad result
# N people --> all results are distinct
# sort people by result descending
# line = surname result
# class Man:
#     surname = ''
#     result = 0
# # _____
# def getResult(man):
#     return man.result
# # _____
# N = int(input())
# manResults = []
# for i in range(N):
#     surname, result = tuple(input().split())
#     result = int(result)
#     man = Man()
#     man.surname = surname
#     man.result = result
#     manResults.append(man)
# manResults.sort(reverse=True, key=getResult)
# for man in manResults:
#     print(man.surname)

# Task 13 : count winner for grades
# look at task 11 ---> same conditions
# in all grades >= 1 person
# read from 'input.txt'
# file = open('input.txt', 'r', encoding='utf8')
# max9, max10, max11 = -1, -1, -1
# cntMax9, cntMax10, cntMax11 = 0, 0, 0
# for line in file:
#     if line == '\n':
#         break
#     line = line[:-1]
#     name, surname, grade, result = tuple(line.split())
#     grade, result = int(grade), int(result)
#     if grade == 9:
#         if max9 < result:
#             max9 = result
#             cntMax9 = 1
#         elif max9 == result:
#             cntMax9 += 1
#     if grade == 10:
#         if max10 < result:
#             max10 = result
#             cntMax10 = 1
#         elif max10 == result:
#             cntMax10 += 1
#     if grade == 11:
#         if max11 < result:
#             max11 = result
#             cntMax11 = 1
#         elif max11 == result:
#             cntMax11 += 1
# print(cntMax9, cntMax10, cntMax11)
# file.close()

# Task 14 : OK result for exams is 40
# competition : N people --> 3 exams, K will 'win'
# for each exam >= 40 points needed
# < 40 ---> out of competition
# for other people ---> sum of 2 results
# inFile = open('input.txt', 'r', encoding='utf8')
# outFile = open('output.txt', 'w', encoding='utf8')
# K = -1  # number of people that will be applied to university
# manResults = []  # here we should know only results, numbers
# firstLine = True
# for line in inFile:
#     if line == '\n':
#         break
#     line = line[:-1]  # remove '\n'
#     if firstLine:
#         K = int(line)
#         firstLine = False
#         continue
#     # print(line)
#     params = tuple(line.split())  # name can be > of 2 words
#     exam1, exam2, exam3 = int(params[-3]), int(params[-2]), int(params[-1])
#     if exam1 < 40 or exam2 < 40 or exam3 < 40:
#         continue
#     # print(*params)
#     manResults.append(exam1 + exam2 + exam3)
# manResults.sort(reverse=True)
# # print(*manResults)
# # print(K)
# N = len(manResults)
# if N <= K:  # all students with 'good' results (>=40 for exams) are applied
#     print(0)  # it's like 0 is result to apply to university (all passed)
# elif manResults.count(manResults[0]) > K:
#     print(1)
# else:
#     # OK result <---> if we add people with max result < Ok result
#     #  then we will have > K people
#     probableMinOkResult = manResults[K-1]
#     i = K - 1
#     while manResults[i] == manResults[i+1]:
#         i += 1
#     if i >= K:
#         while manResults[i] == manResults[K-1]:
#             i -= 1
#     print(manResults[i], file=outFile)
# inFile.close()
# outFile.close()

# Task 15 :
# schools with max # of participants in olympiad
# N people --> read line by line, not save all
# line : name surname school result
# school : [1, 99], result : [0, 100]
# file = open('input.txt', 'r', encoding='utf8')
# cntSchoolStudents = [0] * 100
# maxCntStudents = 0
# for line in file:
#     if line == '\n':
#         break
#     line = line[:-1]
#     surname, name, school, result = tuple(line.split())
#     school = int(school)
#     cntSchoolStudents[school] += 1
#     if cntSchoolStudents[school] > maxCntStudents:
#         maxCntStudents = cntSchoolStudents[school]
# for school in range(100):
#     if cntSchoolStudents[school] == maxCntStudents:
#         print(school, end=' ')
# file.close()

# Task 16 : max result of not winner
# line : surname name grade result
# file = open('input.txt', 'r', encoding='utf8')
# maxResults = [0] * 3      # 0-1-2 for grades 9-10-11
# max_2Results = [0] * 3    # 0-1-2 for grades 9-10-11
# for line in file:
#     if line == '\n':
#         break
#     line = line[:-1]
#     # print(line)
#     surname, name, grade, result = tuple(line.split())
#     grade, result = int(grade), int(result)
#     if maxResults[grade - 9] < result:
#         max_2Results[grade - 9] = maxResults[grade - 9]
#         maxResults[grade - 9] = result
#     elif max_2Results[grade - 9] < result < maxResults[grade - 9]:
#         max_2Results[grade - 9] = result
# print(*max_2Results)
# file.close()

# Task 17 : taxi
# N places --> from start X_i km
# N taxis with own pay per km
# need min total pay for N taxis with different tariffs
# dist = list(map(int, input().split()))
# tariffs = list(map(int, input().split()))
# dist.sort()
# tariffs.sort(reverse=True)
# totalSum = 0
# N = len(dist)
# for i in range(N):
#     totalSum += dist[i] * tariffs[i]
# print(totalSum)

# Task 18 : 7% barrier
# parties ---> people vote for them --->
# only parties with >= 7% of votes will 'win'
# print all 'winners' in input order
# file = open('input.txt', 'r', encoding='utf8')
# parties = []          # names --> string
# partiesVotes = []     # votes --> numbers
# totalVotes = 0
# getParties = False
# getVotes = False
# for line in file:
#     if line == '\n':
#         break
#     line = line[:-1]
#     if line == 'PARTIES:':
#         getParties = True
#         continue
#     elif line == 'VOTES:':
#         getVotes = True
#         getParties = False
#         continue
#     if getParties:
#         parties.append(line)
#         partiesVotes.append(0)
#     if getVotes:
#         index = parties.index(line)
#         partiesVotes[index] += 1
#         totalVotes += 1
# cntWinners = 0  # parties that have >= 7 %
# for i in range(len(parties)):
#     if 100 * partiesVotes[i] >= totalVotes * 7:
#         print(parties[i])
#         # cntWinners += 1
# # print(cntWinners)
# file.close()

# Task 19 : sort parties by votes
# format look at prev task
# sort parties descending by votes,
# if votes_1 = votes_2 ---> lexicographical
class Party:
    name = ''
    votes = 0


file = open('input.txt', 'r', encoding='utf8')
parties = []          # names --> string
partiesVotes = []     # votes --> numbers
getParties = False
getVotes = False
for line in file:
    if line == '\n':
        break
    line = line[:-1]
    if line == 'PARTIES:':
        getParties = True
        continue
    elif line == 'VOTES:':
        getVotes = True
        getParties = False
        continue
    if getParties:
        parties.append(line)
        partiesVotes.append(0)
    if getVotes:
        index = parties.index(line)
        partiesVotes[index] += 1
party_votes = []  # list of objects of class Party
for i in range(len(parties)):
    party = Party()                    # funny ... I try to use classes
    party.name = parties[i]            # but 3 line below I use tuple
    party.votes = partiesVotes[i]      # as key ---> it's bad way, I suppose
    party_votes.append(party)          # I need to use only 1 of these 2 ways
party_votes.sort(key=lambda any_party: (-any_party.votes, any_party.name))
for i in range(len(party_votes)):
    print(party_votes[i].name)
file.close()
