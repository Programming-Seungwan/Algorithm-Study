# 15649 N과 M(1)
# https://www.acmicpc.net/problem/15649

import sys
input=sys.stdin.readline

N,M=map(int,input().split())
result=[]
visited=[False]*(N+1)

def recur(num):
    if num==M:
        print(' '.join(map(str,result)))
        return
    for i in range(1, N+1):
        if visited[i]==False:
            visited[i]=True            
            result.append(i)
            recur(num+1)
            visited[i]=False
            result.pop()

recur(0)
