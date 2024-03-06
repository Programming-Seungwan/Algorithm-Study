# 15650 N과 M

import sys

input=sys.stdin.readline

N,M = map(int, input().split())
visited=[False]*(N+1)
result=[]

def dfs(num):
    if len(result)==M:
        print(' '.join(map(str,result)))
        return
    for i in range(num,N+1):
        if visited[i]==False:
            visited[i]=True
            result.append(i)
            dfs(i+1)
            result.pop()
            visited[i]=False
dfs(1)
