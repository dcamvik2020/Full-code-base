# THEORY 1 : sets, hash-functions
# hash-function reduces the number of indexes needed to
# identify elements from big set (numbers from 1 to 10^9 ---> x % k \in [0, k))
# in Python all immutable (not changeable) objects get hash during 'birth'
# example : string are IM_mutable
# string = 'abcdefg'     # reference to obj_1
# string = 'asd'         # reference to obj_2
# string[2] = 'e'        # ERROR : str doesn't support item assignment
# ______
# dictionaries : (key, value)
# count hash(key) ---> less memory needed for array
# key = phone number, value = person / company
# value can be any type (mutable or immutable too)
# set is mutable ---> can't be element of another set
# but there are frozen sets : func frozenset() --> ok

# THEORY 2 : creating sets
# constant set 1 : fSet = {1, 2, 3}
# constant set 2 : sSet = {1, 2, 3}
# print(fSet == sSet)
# ______
# functions set() receives ANYTHING ITERABLE, returns set
# ITERABLE : list, tuple, string, range, map, set
# myList = list(map(int, input().split()))
# mySet = set(myList)
# print(mySet)
# ______
# BUT : set can be not sorted !!
# myList = [100000000, 1, 2, 1000000222000000000]
# mySet = set(myList)
# print(mySet)  # {100000000, 1, 2, 1000000222000000000} -- old order

# THEORY 3 : elems of set
# mutable object ---> no hash --> can't be element of set
# set = set of IM_mutable obj (numbers, strings, tuples)
# set can contain different data types
# mySet = {1, 3.14, 'abc', (1, 2)}
# print(mySet)  # random order
#  !! list = mutable --> no hash --> can't be in set
#  !! set  = mutable --> no hash --> can't be in set
# frozenset({1, 2}) --- immutable set --> can be in another set
# mySet = {1, 3.14, 'abc', frozenset((1, 2))}  # setFromTuple
# print(frozenset(mySet))
# print(*sorted(list(mySet)))  # set is ITERABLE --> sorted(mySet) is OK
# print(', '.join(sorted(mySet)))
# mySet = set('abcdabc')
# print(len(mySet))
# map() can be applied to set

# THEORY 4 : work with sets
# emptySet = set()
# ______
# mySet = {1, 2, 3, 4000000}
# for elem in mySet:
#     print(elem)
# ______
# primes = {2, 3, 5, 7, 11, 13}
# n = int(input())
# if n in primes:
#     print('YES')
# else:
#     print('not in set')
# if n not in primes:
#     print('not in set')
# else:
#     print('YES')
# ______
# primes.add(17)
# print(*primes)
# ______
# primes.remove(99)     # if 99 not in set ---> ERROR ---> better
# primes.discard(99)    # if 99 not in set ---> OK, old state
# often we need to remove elem that as in set
# ______
# change elem --> can't --> remove(old), add(new)
# ______
# a = {1, 2, 3, 4}
# b = {1, 3}
# print(a == b)  # False
# print(a != b)  # True
# print(a < b)   # False
# print(a > b)   # True
# print(a <= b)   # False
# print(a >= b)   # True
# ______
# a = {1, 2, 3, 4}
# b = {1, 3, 5}
# # print(a + b)  # ERROR
# print(a | b)  # OK : union
# print(a & b)  # OK : intersection
# print(a - b)  # OK : all elem in a, not in b
# print(a ^ b)  # symmetric subtract : {2, 4, 5}
# a ^ b = (a | b) - (a & b)
# |=, &=. -=, ^= exist too
#   !!! all operations ~ O(size(a) + size(b))


# Task 1 : number of distinct numbers
# myList = list(map(int, input().split()))
# mySet = set(myList)
# print(len(mySet))

# Task 2 : size of intersection of 2 lists
# myList1 = list(map(int, input().split()))
# myList2 = list(map(int, input().split()))
# mySet1 = set(myList1)
# mySet2 = set(myList2)
# print(len(mySet1 & mySet2))

# Task 3 : intersection of sets in sorted order!
# myList1 = list(map(int, input().split()))
# myList2 = list(map(int, input().split()))
# mySet1 = set(myList1)
# mySet2 = set(myList2)
# print(*sorted(mySet1 & mySet2))
# or ... in 1 line ... :)
# print(*sorted(set(map(int, input().split()))
# & set(map(int, input().split()))))

# Task 4 : did we see the number earlier .. ??
# for each number in myList --> has duplicate earlier or nor
# myList = list(map(int, input().split()))
# mySet = set()
# for x in myList:
#     if x not in mySet:
#         print('NO')
#         mySet.add(x)
#     else:
#         print('YES')

# Task 5 : A, B --> 2 sets of cubes
# in A, B all cubes are different colors
# colors --> numbers
# how many colors exist : A, B contain cube of this color
# N, M = tuple(map(int, input().split()))  # sizes of A, B
# A = set()
# for i in range(N):
#     color_A = int(input())
#     A.add(color_A)
# B = set()
# for j in range(M):
#     color_B = int(input())
#     B.add(color_B)
# both = A & B
# print(len(both))            # info : intersection
# print(*sorted(both))
# print(len(A - both))        # info : A \ (A & B)
# print(*sorted(A - both))
# print(len(B - both))        # info : B \ (A & B)
# print(*sorted(B - both))

# Task 6 : count distinct words in file
# file = open('input.txt', 'r', encoding='utf8')
# wordsSet = set()
# for line in file:
#     if line == '\n':
#         break
#     line = line[:-1]
#     curLineWordsSet = set(line.split())
#     wordsSet |= curLineWordsSet
# print(len(wordsSet))
# file.close()

# Task 7 : guess the number
# n = max possible number
# line = question = set of numbers
# for each line --> we get the answer from ... Coursera
# answer = 'YES' or 'NO' --- is needed number in question
# we need to print all numbers that can be the needed number
# after command 'HELP', in sorted order
# n = int(input())
# # !!! we know n = max number
# possibleNumbers = set(range(1, n+1))
# while 1:
#     question = input()
#     if question == 'HELP':
#         break
#     numbers = set(map(int, question.split()))
#     answer = input()
#     isNeededNumberInSet = True
#     if answer == 'YES':
#         isNeededNumberInSet = True
#     elif answer == 'NO':
#         isNeededNumberInSet = False
#     if isNeededNumberInSet:
#         possibleNumbers &= numbers
#     else:
#         possibleNumbers -= numbers
# print(*sorted(possibleNumbers))

# Task 8 : guess the number - 2
# now answer are from 'bad' Boris , who wants the set of possible
# number to be at every step the biggest --> he answers as he wants
# we get questions from A, then we need to print Boris's answers for each
# after question 'HELP' we stop and print current possible_numbers_set
# n = int(input())  # max possible number
# possibleNumbers = set(range(1, n+1))
# while 1:
#     question = input()
#     if question == 'HELP':
#         print(*sorted(possibleNumbers))
#         break
#     numbers = set(map(int, question.split()))
#     intersection = possibleNumbers & numbers  # if answer = YES
#     numbersIfYES = len(intersection)
#     numbersIfNO = len(possibleNumbers) - numbersIfYES
#     if numbersIfYES < numbersIfNO or \
#             numbersIfYES == numbersIfNO:
#         # second condition : Boris is 'bad', so .. he just says NO
#         # if A guessed a half of currently possible number
#         print('NO')
#         possibleNumbers -= intersection
#     elif numbersIfYES > numbersIfNO:
#         print('YES')
#         possibleNumbers = intersection

# Task 9 : polyglots
# N students ---> M_i languages
# which languages are known by every student
# which languages are known by at least 1 student
# N = int(input())
# everyStudentLangs = set()
# anyStudentLangs = set()
# first = True
# for i in range(N):
#     M_i = int(input())
#     curStudentLangs = set()
#     for j in range(M_i):
#         lang = input()
#         curStudentLangs.add(lang)
#     anyStudentLangs |= curStudentLangs
#     if first:
#         everyStudentLangs = curStudentLangs
#         first = False
#     else:
#         everyStudentLangs &= curStudentLangs
# print(len(everyStudentLangs))
# print(*everyStudentLangs, sep='\n')
# print(len(anyStudentLangs))
# print(*anyStudentLangs, sep='\n')

# Task 10 : transport swaps
# road ---> coordinate line ---> 2 parts that are just segments on it
# we can change part (transport road) at common points of roads
# road (part, transport line) <---> s, f (start, finish)
# count points : we can change transport line
# s1, f1, s2, f2 = tuple(map(int, input().split()))  # 1 <= ... <= 100
# if s1 > f1:
#     s1, f1 = f1, s1
# if s2 > f2:
#     s2, f2 = f2, s2
# road_1 = set(range(s1, f1 + 1))
# road_2 = set(range(s2, f2 + 1))
# common_stages = road_1 & road_2
# print(len(common_stages))

# Task 11 : political life --> meetings
# K parties --> often 1 of them organizes meeting
# party i : meeting on days a_i, a_i + b_i, a_i + 2 * b_i, ...
# year : N days, first = Monday, 6th and 7th -- weekends, week = 7 days
# every meeting at WORKING (1-5) days --- big damage to economy
# print # of meetings at WORKING days in year
# N, K = tuple(map(int, input().split()))
# allMeetingDays = set()
# weekends = set()                      # idea : time limit exceeded
# for day in range(6, N + 1, 7):        #  --> use embedded methods
#     weekends.add(day)                 #  and range() since we know
# for day in range(7, N + 1, 7):        #  'a' (start) and 'b' (step)
#     weekends.add(day)                 # use as less objects as possible
# for i in range(K):                    # Keep It Simple, Stupid
#     a, b = tuple(map(int, input().split()))
#     allMeetingDays |= set(range(a, N + 1, b))
# allMeetingDays -= weekends
# print(len(allMeetingDays))

# THEORY 5 : dictionaries
# capitals = {'Russia': 'Moscow', 'France': 'Paris'}  # key: value
# print(capitals['Russia'])        # OK
# # print(capitals['USA'])         # Error : key not in capitals
# capitals['USA'] = 'Washington'
# print(capitals['USA'])
# print(*capitals)                 # all keys
# del capitals['France']           # only for dictionaries
# # print(capitals['France'])      # Error
# print('Russia' in capitals)      # True

# THEORY 6 : create dict
# myDict = {}
# myDict[1] = 3
# myDict[2] = 4
# myDict[3] = 5
# print(myDict)
# myDict = dict()   # receives only PAIRS of objects
# myDict = dict([('x', 5), ('y', 7)])
# for i in myDict:   # in random order cause of hash functions
#     print(i, myDict[i])            # i = key
# for key, value in myDict.items():
#     print(key, value)

# THEORY 7 : when use dictionaries
# - usual dictionary
# - count entrances of objects
# ______
# s = input()
# letters = dict()
# for c in s:                 # we can do better :
#     if c in letters:        # if c not in letters:
#         letters[c] += 1     #     letters[c] = 0
#     else:                   # letters[c] += 1
#         letters[c] = 1      # oe even better :
# for c in sorted(letters):   # for c in s:
#     print(c, letters[c])    #     letters[c] = letters.get(c, 0) + 1
# ______
# method get(key, default_value)
# returns letters[key] ot default_value
# ______
# ANOTHER EXAMPLE :
# keep arrays with not many values in wide diapason with

# THEORY 8 : useful string methods
# s = input()
# print(s.isalpha())   # is string only of letters
# print(s.isdigit())   # is string only of digits
# print(s.isalnum())   # is string only of letters, digits
# print(s.islower())   # is string only of lowercase
# print(s.isupper())   # is string only of uppercase
# s.lower()            # covert symbols to lowercase
# s.upper()            # covert symbols to uppercase
# s.strip()            # cut whitespaces from sides (left, right)
# s.lstrip()            # cut whitespaces from left
# s.rstrip()            # cut whitespaces from right

# EXAMPLE : have eng-latin dictionary ---> want latin-eng
# sort meanings lexicographical
# fin = open('input.txt')
# myDict = {}
# for line in fin:
#     eng, latins = line.split('-')   <---> (  apple - numan, dfsdfs, sdfsdf)
#     latinsList = latins.split(',')
#     eng = eng.strip()
#     for latin in latinsList:
#         if latin.strip() not in myDict:
#             myDict[latin.strip()] = []
#         myDict[latin.strip()].append(latin.strip())
# print(myDict)
# fin.close()


# Task 12 : phone numbers
# have : number that want to add and set of 3 numbers
# for each of 3 number need to check == it to given number or not
# phone formats : +7<code><number>, 8<code><number>
#                 or <number> (<code> = 495 default)
#                 number = 7 digits, code = 3 digits (maybe in () )
#                 between any 2 digits '-' can be put
# def convertPhoneToString(phone):
#     digitsInPhone = ''
#     converted = ''
#     i = 0
#     if phone[i] == '+':
#         digitsInPhone += '8'
#         i = 2
#     else:
#         digitsInPhone += phone[i]
#         i = 1
#     while i < len(phone):
#         c = phone[i]
#         if c.isdigit():
#             digitsInPhone += c
#         i += 1
#     if len(digitsInPhone) == 7:
#         converted = '8495' + digitsInPhone
#     else:
#         converted = digitsInPhone
#     return converted
# ______
# givenPhone = convertPhoneToString(input().strip())
# otherPhones = []
# for ind in range(3):
#     newPhone = input().strip()
#     newPhone = convertPhoneToString(newPhone)
#     if newPhone == givenPhone:
#         print('YES')
#     else:
#         print('NO')
#     otherPhones.append(newPhone)
#     print('\tnew :', newPhone)
# print('given :', givenPhone)
# print(*otherPhones, sep='\n')

# THEORY 9 : example of difficult task
# EXAMPLE : have eng-latin dictionary ---> want latin-eng
# sort meanings lexicographical
# fin = open('input.txt')
# myDict = {}
# for line in fin:
#     eng, latins = line.split('-')   # <---> (  apple - numan, dfsdfs, sdfsdf)
#     latinsList = latins.split(',')
#     eng = eng.strip()
#     for latin in latinsList:
#         if latin.strip() not in myDict:
#             myDict[latin.strip()] = []
#         myDict[latin.strip()].append(latin.strip())
# for latin in sorted(myDict):                              # print all data
#     print(latin, '-', ','.join(sorted(myDict[latin])))    # in sorted way
# fin.close()
# ______
# EXAMPLE : genealogical tree ---> PEP 8 is quite important and ... difficult
# tree = {
#     'a':
#         {
#             'b':
#                 dict(),
#             'c':
#                 {
#                     'd':
#                         dict(),
#                     'e':
#                         dict()
#                 }
#         }
# }

# Task 13 : countries and cities
# N countries ---> for every country get list of cities
# M cities    ---> for every city print country
# N = int(input())
# city_country = dict()  # key = string, value = list(strings)
# for i in range(N):
#     line = input().split()
#     country, cities = line[0], line[1:]
#     for city in cities:
#         city_country[city] = country
# M = int(input())
# for j in range(M):
#     city = input()
#     print(city_country[city])

# Task 14 : number of word's entrance
# for every word in text ---> # of entrances before in text
# file = open('input.txt')  # 'r', encoding='utf8' are default
# word_cnt = dict()
# for line in file:
#     if line[-1] == '\n':
#         line = line[:-1]
#     if line == '':
#         break
#     new_words = list(line.split())
#     for word in new_words:
#         if word not in word_cnt:
#             word_cnt[word] = 0
#         print(word_cnt[word], end=' ')
#         word_cnt[word] += 1
# file.close()

# Task 15 : dictionary for synonyms
# we receive a dict of pairs of words (synonyms)
# all words are different ---> for one given word print synonym
# N = int(input())  # number of pairs
# synonyms = dict()
# for i in range(N):
#     word1, word2 = tuple(input().split())
#     synonyms[word1] = word2
#     synonyms[word2] = word1
# givenWord = input()
# print(synonyms[givenWord])

# Task 16 : USA elections (politics)
# 2 levels of elections : in every state firstly
#         after that final elections for USA
# on level 2 each state has certain # of votes
# for every candidate (lexicographical) we need to get # of votes
# file = open('input.txt')
# candidate_votes = dict()
# for line in file:
#     # each line = 'candidate_surname votes_from_state'
#     if line[-1] == '\n':
#         line = line[:-1]
#     if line == '':
#         break
#     candidate, votes = tuple(line.split())
#     if candidate not in candidate_votes:
#         candidate_votes[candidate] = 0
#     candidate_votes[candidate] += int(votes)
# for candidate in sorted(candidate_votes):
#     print(candidate, candidate_votes[candidate])
# file.close()

# Task 17 : most frequent word
# if there are > 1 such words --> the smallest in lexicographical order
# file = open('input.txt')
# words_cnt = dict()
# ans, cnt_ans = '', 0
# for line in file:
#     if line[-1] == '\n':
#         line = line[:-1]
#     if line == '':
#         break
#     new_words = list(line.split())
#     for word in new_words:
#         if word not in words_cnt:
#             words_cnt[word] = 0
#         words_cnt[word] += 1
#         if words_cnt[word] > cnt_ans:
#             cnt_ans = words_cnt[word]
#             ans = word
# for word in sorted(words_cnt):
#     if words_cnt[word] == cnt_ans:
#         print(word)
#         break
# file.close()

# Task 18 : frequency analysis
# text ---> print all words on new_line descending by frequency
# if frequency_1 == frequency_2 ---> words in lexicographical order
# file = open('input.txt')
# words_cnt = dict()
# for line in file:
#     if line[-1] == '\n':
#         line = line[:-1]
#     if line == '':
#         break
#     new_words = list(line.split())
#     for word in new_words:
#         if word not in words_cnt:
#             words_cnt[word] = 0
#         words_cnt[word] += 1
# pairsList = []  # list of pairs
# for word in words_cnt:
#     pairsList.append((-words_cnt[word], word))
# pairsList.sort()
# for pair in pairsList:
#     print(pair[1])
# file.close()

# Task 19 : RUS president elections
# winner = candidate with > 50% votes
# if there is no winner ---> second tour for 2 'winners' with most # of votes
# line in file = 'name_of_candidate' --- one person's vote for candidate
# know : total # of candidates <= 20
# winner exist --> print him, else print 'winner 1' then 'winner 2'
# inFile = open('input.txt', 'r', encoding='utf8')
# outFile = open('output.txt', 'w', encoding='utf8')
# candidate_votes = dict()
# total_votes = 0
# for name in inFile:
#     if name[-1] == '\n':
#         name = name[:-1]
#     if name == '':
#         break
#     candidate_votes[name] = candidate_votes.get(name, 0) + 1
#     total_votes += 1
# list_votes_candidate = []
# for candidate in candidate_votes:
#     list_votes_candidate.append(
#         (-candidate_votes[candidate], candidate)
#     )
# list_votes_candidate.sort()
# winner1, votes1 = list_votes_candidate[0][1], -list_votes_candidate[0][0]
# if len(list_votes_candidate) == 1 or votes1 * 2 > total_votes:
#     print(winner1, file=outFile)
# else:
#     # important : 1 candidate can be ---> index out of range
#     winner2, votes2 = list_votes_candidate[1][1], -list_votes_candidate[1][0]
#     print(winner1, winner2, sep='\n', file=outFile)
# inFile.close()
# outFile.close()


# Task 20 : parties in voting for parliament
# 450 people from different parties
# 1) count votes for every party and total # of votes for all parties
# 2) this sum / 450 ---> "first voting division result" = num_0 = number of
#           votes to receive 1 place of 450 in parliament
# 3) every party receives (votes//num_0) places in parliament
# after 1st round if sum of places < 450 ---> places 1 by 1 are given to
# other parties in order of descending fractional part of (votes / num_0)
# if 2 fractional part equal -----> priority to party : has more votes
# print result in initial order of input parties
# IDEA : party <---> name, votes, places, rest of votes ---> classes
# PROBLEM : it's difficult to control several dictionaries and lists
# class Party:
#     order = 0
#     name = ''
#     votes = 0
#     places = 0
#     rest_of_votes = 0  # for second tour
#
#
# file = open('input.txt')
# parties = []  # (party, votes) --> (party, places)
# total_votes = 0
# order = 0
# for line in file:
#     if line == '\n':
#         break
#     params = line.split()
#     name, votes = ' '.join(params[:-1]), int(params[-1])
#     new_party = Party()             # constructing new_party is easier
#     new_party.order = order         # we can sort by all fields of class
#     new_party.name = name           # in task second tour : sort by
#     new_party.votes = votes         # -rest_of_places <---> fractional part
#     parties.append(new_party)       # -votes  <---> look the task
#     total_votes += votes
#     order += 1
# # print('__________')
# num_0 = total_votes / 450  # who said that it should be integer ... ?
# # print(num_0)
#
# places_given = 0
# for party in parties:
#     party.places = int(party.votes // num_0)
#     places_given += party.places
#     party.rest_of_votes = party.votes - party.places * num_0
#
# parties.sort(key=lambda x: (-x.rest_of_votes, -x.votes))  # 2nd : not x.places
#
# while places_given < 450:
#     for party in parties:
#         if places_given != 450:
#             places_given += 1
#             party.places += 1
#
# parties.sort(key=lambda x: x.order)
# for party in parties:
#     print(party.name, int(party.places))
# file.close()


# Task 21 : sells
# have info about customers, bought things (names, counts)
# print customers in lexicographical order and list of their things
# in lexicographical order too with their quantities
# file = open('input.txt')
# customers = dict()  # (customer, dict(thing, count))
# for line in file.readlines():
#     if line[-1] == '\n':
#         line = line[:-1]
#     if line == '':
#         break
#     name, product, count = line.split()
#     count = int(count)
#     if name not in customers:
#         customers[name] = dict()
#     if product not in customers[name]:
#         customers[name][product] = 0
#     customers[name][product] += count
# for name in sorted(customers):
#     print(name, ':', sep='')
#     for product in sorted(customers[name]):
#         print(product, customers[name][product])
# file.close()

# Task 22 : bank accounts
# DEPOSIT name sum
# WITHDRAW name sum
# BALANCE name
# TRANSFER name1 name2 sum
# INCOME percent
# file = open('input.txt')
# info = dict()  # dict : person --> sum
# for line in file:
#     if line[-1] == '\n':
#         line = line[:-1]
#     if line == '':
#         break
#     params = line.split()
#     op = params[0]
#     if op == "BALANCE":
#         person = params[1]
#         # print(info)
#         # print(person)
#         # print()
#
#         if person in info:
#             print(info[person])
#         else:
#             print('ERROR')
#     elif op == "INCOME":
#         percent = int(params[1])
#         for person in info:
#             money = info[person]
#             if money > 0:
#                 money = money * (100 + percent) // 100
#             info[person] = money
#     elif op == "DEPOSIT":
#         name, money = params[1], params[2]
#         money = int(money)
#         if name not in info:
#             info[name] = 0
#         info[name] += money
#     elif op == "WITHDRAW":
#         name, money = params[1], params[2]
#         money = int(money)
#         if name not in info:
#             info[name] = 0
#         info[name] -= money
#     elif op == "TRANSFER":
#         name1, name2, money = tuple(params[1:])
#         money = int(money)
#         if name1 not in info:
#             info[name1] = 0
#         if name2 not in info:
#             info[name2] = 0
#         info[name1] -= money
#         info[name2] += money
# file.close()

# Task 23 : homework for stresses control in words
# N = words in dictionary with put stresses, we get N and N words
# after that we get text of homework (line) ---> consider homework
# if word not in dict ---> think that it is correct if only 1 stress
# if stress can be put > 1 way --> any stress ---> OK, if it's the only stress
# def getLowerCase(word):
#     stresses = 0
#     converted = word.lower()
#     for index in range(len(word)):
#         if word[index] != converted[index]:
#             stresses += 1
#     return stresses
# ______
# file = open('input.txt')
# i, N = 0, -1
# wordsSet = set()       # dict
# lowerCaseSet = set()   # dict without stresses
# homework = ''
# for line in file:
#     # print(line, end='')
#     if line[-1] == '\n':
#         line = line[:-1]
#     if line == '':
#         break
#     if N == -1:
#         N = int(line)
#         continue
#     if i < N:
#         word = line
#         wordsSet.add(word)
#         word = word.lower()
#         lowerCaseSet.add(word)
#         i += 1
#     else:
#         homework = line
# cntErrors = 0
# homework = homework.split()
# # get word from homework
# for word in homework:
#     stresses = getLowerCase(word)
#     condition_1 = (word not in wordsSet) and (word.lower() in lowerCaseSet)
#     condition_2 = (word.lower() not in lowerCaseSet) and (stresses != 1)
#     if condition_1 or condition_2:
#         cntErrors += 1
# print(cntErrors)
# file.close()

# Task 24 : family tree -- count levels
# genealogical tree ---> everybody except root has the only parent
# node of tree <---> number = height
# height(root) = 0, height(node) = 1 + height(node->parent)
# get tree ---> print all heights
# print in lexicographical order all nodes of tree and its height
# NOTE : at first here were > 50 lines ... that were wrong ...
# def height(node, node_parent):
#     if node not in node_parent:
#         return 0
#     else:
#         return 1 + height(node_parent[node], node_parent)
# ______
# node_parent = dict()
# all_nodes = set()
# for i in range(1, int(input())):
#     child, parent = input().split()
#     node_parent[child] = parent
#     all_nodes.add(child)
#     all_nodes.add(parent)
# for node in sorted(all_nodes):
#     print(node, height(node, node_parent))