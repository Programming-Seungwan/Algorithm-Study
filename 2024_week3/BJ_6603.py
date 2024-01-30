# 6603 로또
# https://www.acmicpc.net/problem/6603

import sys
input = sys.stdin.readline

result = []
n_list = list(map(int, input().split()))

while True:
    k = n_list[0]

    def recur(start):
        if len(result) == 6:
            print(" ".join(map(str, result)))
        for i in range(start, len(n_list)):
            result.append(n_list[i])
            recur(i + 1)
            result.pop()

    recur(1)
    n_list = list(map(int, input().split()))
    if n_list[0] == 0:
        break
    result = []
    print()
