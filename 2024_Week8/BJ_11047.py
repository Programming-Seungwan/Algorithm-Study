# 11047 동전 0
# https://www.acmicpc.net/problem/11047

import sys
input=sys.stdin.readline

n,k = map(int,input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))

cnt=0

for i in range(n-1,-1,-1):
    cnt += k//coins[i]
    k = k%coins[i]
  
print(cnt)
