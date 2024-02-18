# 14501 퇴사
# https://www.acmicpc.net/problem/14501

import sys
input=sys.stdin.readline

n = int(input())
list = [list(map(int, input().split())) for _ in range(n)]

memo = [0 for _ in range(n+1)]

for i in range(n - 1, -1, -1):
    if i + list[i][0] <= n:  # 퇴사 전에 상담 완료 가능
        memo[i] = max(memo[i + 1], memo[i + list[i][0]] + list[i][1])
    else:
        memo[i]=memo[i+1]
print(memo[0])
