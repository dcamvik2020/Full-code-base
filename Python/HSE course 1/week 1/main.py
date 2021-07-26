# THEORY 1
# print('2 + 3 =', 2 + 3, sep=' ')
# print('1', '2', '3', sep=' + ', end='')
# print('=', 1 + 2 + 3)

# THEORY 2
#     11 ^ 2 ,    3,    3,(6),     4,       2,        23
# print(11 ** 2, 11 // 3, 11 / 3, 12 // 3, 11 % 3, (7 - 8) % 24)
# speed = 108
# time = 12
# path = speed * time
# print(path)

# THEORY 3
# phrase = 'bye-bye'
# who = '"boy"'  # will print "boy", not boy
# print(phrase, ', ', who, sep='')
# ans = 2 + 3                  # use str() to convert
# expr = '2 + 3 = '            # number to string
# print(expr + str(ans))       # str(expr) = expr anyway

# THEORY 4
# print('abc' * 3)         # abcabcabc
# name = input()           # reads whole line till "\n"
# print('Hello, ' + name)
# a = input()     # string
# b = input()     # string
# print(a + b)    # concatenation
# print(int(a) + int(b))  # number + number = number
# print(int('100' * 100) ** 2)


# TASK 1 "hello, %username"
# name = input()
# print("Hello", name, sep=', ', end='!')

# TASK 2 "Penguins"
# N = int(input())
# print('   _~_    ' * N)
# print('  (o o)   ' * N)
# print(' /  V  \\  ' * N)
# print('/(  _  )\\ ' * N)
# print('  ^^ ^^   ' * N)

# TASK 3, 4 "Divide apples 1, 2"
# pupils = int(input())
# apples = int(input())
# for_each_pupil = apples // pupils
# # print(for_each_pupil)
# apples_in_rest = apples % pupils
# print(apples_in_rest)

# TASK 5 "Paw of 2"
# N = int(input())
# print(2 ** N)

# Task 6 "Last digit"
# N = int(input())
# print(N % 10)

# Task 7 "First digit of 2-digit number:
# N = int(input())
# print(N // 10)

# Task 8 "2nd digit from th end"
# N = int(input())
# print((N % 100) // 10)

# Task 9 "3-digit numer : sum of digits"
# N = int(input())
# print(N // 100 + (N % 100) // 10 + N % 10)

# Task 10 "print 100 'A'"
# print('A' * 100)

# Task 11 "Clocks"
# minutes = int(input())
# minutes = minutes % (24 * 60)
# time = str(minutes // 60) + ' ' + str(minutes % 60)
# print(time)


# THEORY 5
# round up a/b
# a = int(input())
# b = int(input())
# print((a + b - 1) // b)


# Task 12 "Cost of pie"
# rubles = int(input())
# cents = int(input())
# pies = int(input())
# cost_per_one = rubles * 100 + cents
# total_cost = pies * cost_per_one
# total_rubles = total_cost // 100
# total_cents = total_cost % 100
# print(total_rubles, total_cents)

# Task 13 "Prev & Next numbers
# number = int(input())
# print('The next number for the number', end=' ')
# print(number, 'is', number + 1, sep=' ', end='.\n')
# print('The previous number for the number', end=' ')
# print(number, 'is', number - 1, sep=' ', end='.')

# Task 14 "0 to 1 and 1 to 0"
# number = int(input())    # 0 or 1
# print((number + 1) % 2)

# Task 15 "Next odd number"
# number = int(input())
# print(number + 2 - (number % 2))

# Task 16 "100 times in row and result sqquared"
# number = input()
# print(int(number * 100) ** 2)

# Task 17 "Moscow Circle Road"
# circle_len = 109
# speed = int(input())
# time = int(input())
# start = 0
# finish = start + speed * time
# print(finish % circle_len)

# Task 18 "Clock 2" ---> format  hh:mm:ss
# seconds = int(input())
# seconds = seconds % (24 * 3600)
# hours = seconds // 3600
# seconds = seconds % 3600
# minutes = seconds // 60
# seconds = seconds % 60
# print(hours, end=':')
# print(minutes // 10, minutes % 10, sep='', end=':')
# print(seconds // 10, seconds % 10, sep='')

# Task 19 "clock, 2 time moments difference", 2nd >= 1st
# hours_1 = int(input())
# minutes_1 = int(input())
# seconds_1 = int(input())
# hours_2 = int(input())
# minutes_2 = int(input())
# seconds_2 = int(input())
# time_1 = hours_1 * 3600 + minutes_1 * 60 + seconds_1
# time_2 = hours_2 * 3600 + minutes_2 * 60 + seconds_2
# time_dif = time_2 - time_1
# print(time_dif)

# Task 20 "Car's path"
# path_per_day = int(input())
# total_path = int(input())
# days_needed = (total_path + path_per_day - 1) // path_per_day
# print(days_needed)

# Task 21 "Snail"
# total_height = int(input())
# up_per_day = int(input())
# down_per_day = int(input())
# per_day = up_per_day - down_per_day
# without_last_day = total_height - up_per_day
# days_needed_to_get_to_the_top = (without_last_day + per_day - 1) // per_day + 1
# print(days_needed_to_get_to_the_top)
