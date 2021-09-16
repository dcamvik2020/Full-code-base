import sys
sys.setrecursionlimit(100000)
total_knapsack_volume = int(input())
number_of_items: int = int(input())

item_volumes = []
item_values = []
relative_values = []
taken_items_max = []
items = []

for i in range(number_of_items):
    data = input().split()
    item_volumes.append(int(data[0]))
    item_values.append(int(data[1]))
    relative_values.append((item_values[i] / item_volumes[i], item_volumes[i], item_values[i]))
    taken_items_max.append(0)
    items.append((item_volumes[i], item_values[i], item_values[i] / item_volumes[i]))

relative_values.sort(key=lambda relative: relative[0])
relative_values.reverse()

# print(relative_values)

flag = 0


def search_max(chosen, taken_items_m, current_value, current_volume):
    # global flag
    # for i in range(number_of_items - chosen):
    #     taken_items_m[i + chosen] = 0
    for i in range(number_of_items - chosen):
        if current_volume + relative_values[i + chosen][1] <= total_knapsack_volume:
            taken_items_m[i + chosen] = 1
            current_value += relative_values[i + chosen][2]
            current_volume += relative_values[i + chosen][1]
        else:
            # if total_knapsack_volume - current_volume == 0:
            #     flag = 1
            taken_items_m[i + chosen] = (total_knapsack_volume - current_volume) / relative_values[i + chosen][1]
            current_value += taken_items_m[i + chosen] * relative_values[i + chosen][2]
            break
    # print(taken_items_m)
    return (taken_items_m, current_value)

max_value = []
max_value.append(relative_values)
data = search_max(0, taken_items_max, 0, 0)
max_value.append(data[0])
max_value.append(data[1])

if flag == 1:
    print(data[1])
    exit()

# print(max_value[2])

items.sort(key=lambda volume: volume[0])
items.reverse()

current_volume = 0
current_value = 0

for i in range(number_of_items):
    if current_volume + items[i][0] > total_knapsack_volume:
        if current_volume != 0:
            break
    else:
        current_volume += items[i][0]
        current_value += items[i][1]

min_value_1 = current_value

current_volume = 0
current_value = 0
items.reverse()

for i in range(number_of_items):
    if current_volume + items[i][0] > total_knapsack_volume:
        break
    else:
        current_volume += items[i][0]
        current_value += items[i][1]

min_value_2 = current_value
min_value = max(min_value_1, min_value_2)

# print(min_value, max_value[2])

items.sort(key=lambda relative: relative[2])
items.reverse()

chosen_items = []

for i in range(number_of_items):
    chosen_items.append(None)

# print(chosen_items)


# print(items)
# print(taken_items_max)
# print(relative_values)

deep = 0


def search(chosen_number, chosen_items, current_value, current_volume):
    global deep
    deep += 1
    if chosen_number == number_of_items:
        return 0

    global min_value
    results = []
    results.append(0)
    flag = 0

    if taken_items_max[chosen_number] == 1:
        flag = 1
        chosen_items[chosen_number] = 1
        results.append(search(chosen_number + 1, chosen_items,
                     current_value + relative_values[chosen_number][2],
                     current_volume + relative_values[chosen_number][1]) +
                       relative_values[chosen_number][2])

    for i in range(2 - flag):
        chosen_items[chosen_number] = (i + 1 + flag) % 2

        if current_volume + ((i + 1 + flag) % 2) * relative_values[chosen_number][1] <= total_knapsack_volume:
            res = search_max(chosen_number + 1, chosen_items,
                             current_value + ((i + 1 + flag) % 2) * relative_values[chosen_number][2],
                             current_volume + ((i + 1 + flag) % 2) * relative_values[chosen_number][1])
            # print("res[1]: ", res[1])

            if res[1] > min_value:
                results.append(search(chosen_number + 1, chosen_items,
                                  current_value + ((i + 1 + flag) % 2) * relative_values[chosen_number][2],
                                  current_volume + ((i + 1 + flag) % 2) * relative_values[chosen_number][1]) +
                               ((i + 1 + flag) % 2) * relative_values[chosen_number][2])

    res_max = max(results)

    # print(res_max)

    if res_max + current_value > min_value:
        min_value = res_max + current_value
    return res_max



search(0, chosen_items, 0, 0)
print(min_value)

print(deep)
