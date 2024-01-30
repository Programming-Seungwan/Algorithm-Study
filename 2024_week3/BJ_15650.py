# 15650 N과 M(2)
# https://www.acmicpc.net/problem/15650

import sys
input=sys.stdin.readline

N,M=map(int,input().split())
result=[]
visited=[False]*(N+1)

def recur(num):
    if len(result)==M:
        print(' '.join(map(str,result)))
        return
    for i in range(num,N+1):
        if visited[i]==False :
            visited[i]=True
            result.append(i)
            recur(i+1)
            visited[i]=False
            result.pop()

recur(1)
