# 10026 적록색약
# https://www.acmicpc.net/problem/10026

import sys
sys.setrecursionlimit(10**5) # 재귀함수 사용 시 필수. 재귀 깊이제한 1000에 걸리지 않도록 깊이를 확장하는 용도.
input=sys.stdin.readline

N=int(input())
graph=[list(map(str,input().rstrip())) for _ in range(N)]

def count(N):
    visited=[[False]*N for _ in range(N)]
    num=0
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    def dfs(x,y):
        visited[x][y]=1
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<N and 0<=ny<N:
                if graph[nx][ny]== graph[x][y] and not visited[nx][ny]:
                    dfs(nx,ny)
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                dfs(i,j)
                num+=1
    return num

count1=count(N)
for i in range(N):
        for j in range(N):
            graph[i][j]=graph[i][j].replace('R','G')
count2=count(N)

print(count1, count2)
