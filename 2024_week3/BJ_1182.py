# 1182 부분수열의 합
# https://www.acmicpc.net/problem/1182

import sys
input = sys.stdin.readline

N, S = map(int, input().split())
N_list = list(map(int, input().split()))

N_sum = 0
count = 0

def recur(start):
    global N_sum, count
    if N_sum == S:
        count += 1
    for i in range(start, N):
        N_sum += N_list[i]
        recur(i + 1)
        N_sum -= N_list[i]

recur(0)
if S==0:
    print(count-1)
else: 
    print(count)
