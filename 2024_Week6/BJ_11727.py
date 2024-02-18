# 11727 2xn 타일링2
# https://www.acmicpc.net/problem/11727
import sys
input=sys.stdin.readline

n = int(input())
dp=[0]*n
dp[0]=1

if n==2:
    dp[1]=3
  
if n>=3:
    dp[1]=3
    for i in range(2,n):
        dp[i]=dp[i-1]+(dp[i-2]*2)
    
ans=dp[n-1]%10007
print(ans)
