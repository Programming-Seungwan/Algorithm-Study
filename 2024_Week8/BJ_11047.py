# 11047 동전 0
# https://www.acmicpc.net/problem/11047

import sys
input=sys.stdin.readline

n,k = map(int,input().split())
coins = []
count = 0

for _ in range(n):
    coins.append(int(input()))

for i in range(n-1,-1,-1):
    cnt += k//coins[i]
    k = k%coins[i]
  
print(count)
