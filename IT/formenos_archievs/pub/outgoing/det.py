#!/usr/bin/python

def minor(A, i, j):
    return [[A[r][c] for c in range(len(A[0])) if c != j] for r in range(len(A)) if r != i]

def det(A):
    if len(A) == 1:
        return A[0][0]
    return sum([(-1) ** j * A[0][j] * det(minor(A, 0, j)) for j in range(len(A[0]))])







n = int(input())
A = []
for i in range(n):
    A.append(list(map(int, raw_input().split())))

print det(A)
