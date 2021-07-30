import functools

print(
    *filter(
        lambda num: num in {2, 3, 5} or True not in set(
            map(lambda d: num % d == 0, range(2, int(num ** 0.5) + 1))
        ),
        range(2, int(input()) + 1)
    )
)
