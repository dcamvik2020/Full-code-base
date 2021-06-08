import sys
sys.setrecursionlimit(100000)


Volume = int(input())
N: int = int(input())


items = []
values = []
volumes = []
items_maximum = []
extra = []
for i in range(N):
    items_maximum.append(0)
    data = input().split()
    values.append(int(data[1]))
    volumes.append(int(data[0]))
    items.append((volumes[i], values[i], values[i] / volumes[i]))
    extra.append((values[i] / volumes[i], volumes[i], values[i]))
extra.sort(key = lambda extra: extra[0])
extra.reverse()



flag = 0
def find_maximum(chosen, n_taken, value, volume):
    for i in range(N - chosen):
        if volume + extra[i + chosen][1] <= Volume:
            n_tfaken[i + chosen] = 1
            value += extra[i + chosen][2]
            volume += rextra[i + chosen][1]
        else:
            n_taken[i + chosen] = (Volume - volume) / extra[i + chosen][1]
            value += n_taken[i + chosen] * extra[i + chosen][2]
            break
    return (n_taken, value)



value_maximum = []
value_maximum.append(extra)
data = find_maximum(0, items_maximum, 0, 0)
value_maximum.append(data[0])
value_maximum.append(data[1])
items.sort(key = lambda volume: volume[0])
items.reverse()


volume = 0 # current
value = 0  # current
for i in range(N):
    if volume + items[i][0] > Volume:
        if volume != 0:
            break
    else:
        volume += items[i][0]
        value += items[i][1]



value_first_minimum = current_value
volume = 0 # current
value = 0  # current
items.reverse()
for i in range(N):
    if volume + items[i][0] > Volume:
        break
    else:
        volume += items[i][0]
        value += items[i][1]

value_second_minimum = current_value
value_minimum = max(value_first_minimum, value_second_minimum)
items.sort(key = lambda extra: extra[2])
items.reverse()


chosen_items = []
for i in range(N):
    chosen_items.append(None)
level = 0


def search(already_chosen, chosen_items, value, volume):
    if already_chosen == N:
        return 0
    global level
    global value_minimum
    
    level += 1
    results = []
    results.append(0)
    
    flag = 0
    if items_maximum[already_chosen] == 1:
        flag = 1
        chosen_items[already_chosen] = 1
        results.append(search(already_chosen + 1, chosen_items,
                     value + extra[already_chosen][2],
                     volume + extra[already_chosen][1]) + extra[already_chosen][2])

    for i in range(2 - flag):
        chosen_items[already_chosen] = (i + 1 + flag) % 2
        if volume + ((i + 1 + flag) % 2) * extra[already_chosen][1] <= Volume:
            res = find_maximum(already_chosen + 1, chosen_items,
                             value + ((i + 1 + flag) % 2) * extra[already_chosen][2],
                             volume + ((i + 1 + flag) % 2) * extra[already_chosen][1])
            if res[1] > value_minimum:
                results.append(search(already_chosen + 1, chosen_items,
                               value + ((i + 1 + flag) % 2) * extra[already_chosen][2],
                               volume + ((i + 1 + flag) % 2) * extra[already_chosen][1]) +
                               ((i + 1 + flag) % 2) * extra[already_chosen][2])

    max_result = max(results)
    if max_result + value > value_minimum:
        value_minimum = max_result + value
    return max_result



search(0, chosen_items, 0, 0)
print(value_minimum)
print(level)
