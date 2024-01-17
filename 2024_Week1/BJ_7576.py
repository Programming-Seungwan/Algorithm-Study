# 7576 토마토
# https://www.acmicpc.net/problem/7576

import sys
from collections import deque

input=sys.stdin.readline

M,N=map(int,input().split())
graph=[list(map(int,input().split())) for _ in range(N)]

# !!!!!!!! 좀 더 공부 필요 !!!!!!!!!
def answer():
    day=0
    q=deque()
    for i in range(N):
        for j in range(M):
            if graph[i][j]==1:
                q.append((i,j)) 
    def bfs():
        dx=[-1,1,0,0]
        dy=[0,0,-1,1]
        while q:
            cx,cy=q.popleft()
            for i in range(4):
                nx=cx+dx[i]
                ny=cy+dy[i]
                if 0<=nx<N and 0<=ny<M and graph[nx][ny]==0:
                    q.append((nx,ny))
                    graph[nx][ny]=graph[cx][cy]+1
    bfs()
    for i in range(N):
        for j in range(M):
            if graph[i][j]==0:
                print(-1)
                exit(0)
            day=max(day, graph[i][j])
    print(day-1)
# 실행
answer()
