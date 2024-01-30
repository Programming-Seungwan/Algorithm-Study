# 1759 암호만들기
# https://www.acmicpc.net/problem/1759

import sys
input = sys.stdin.readline

L, C = map(int, input().split())
n_list = list(map(str, input().split()))
n_list.sort()
result = []
aeiou = ["a", "e", "i", "o", "u"]

def recur(start):
    global result
    if len(result) == L:
        count = 0
        for i in result:
            if i in aeiou:
                count += 1
        if count >= 1 and L - count >= 2:
            print(''.join(map(str,result)))
    for i in range(start, C):
        result.append(n_list[i])
        recur(i + 1)
        result.pop()

recur(0)
