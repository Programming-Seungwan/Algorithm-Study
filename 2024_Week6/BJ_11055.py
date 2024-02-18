# 11055 가장 큰 증가하는 부분 수열
# https://www.acmicpc.net/problem/11055
import sys
input=sys.stdin.readline

n = int(input())
list=list(map(int,input().split()))
dp=[0 for _ in range(n)]

dp[0]=list[0]

for i in range(n):
    for j in range(i):
        if list[i]>list[j]:
            dp[i]=max(dp[i],dp[j]+list[i])
        else:
            dp[i]=max(dp[i],list[i])
print(max(dp))
