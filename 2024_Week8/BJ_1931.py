# 1931 회의실 배정
# https://www.acmicpc.net/problem/1931

import sys
input=sys.stdin.readline

N = int(input())
meetings = [list(map(int, input().split())) for _ in range(N)]
meetings = sorted(meetings, key=lambda x: (x[1], x[0]))
time_table =[]
time_table.append(meetings[0])

if N>1:
    for i in range(1,N):
        if time_table[-1][1]<=meetings[i][0]:
            time_table.append(meetings[i])
print(len(time_table))
