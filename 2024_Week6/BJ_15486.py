# 퇴사 2
# https://www.acmicpc.net/problem/15486
import sys
input=sys.stdin.readline

n = int(input())
list = [list(map(int, input().split())) for _ in range(n)]

memo = [0 for _ in range(n+1)]

for i in range(n - 1, -1, -1):
    if i + list[i][0] <= n:
        memo[i] = max(memo[i + 1], memo[i + list[i][0]] + list[i][1])
    else:
        memo[i]=memo[i+1]
print(memo[0])
