# 7569 토마토
# https://www.acmicpc.net/problem/7569

import sys
from collections import deque
input=sys.stdin.readline

col, row, height = map(int,input().split())
graph = [list(list(map(int,input().split())) for _ in range(row)) for _ in range(height)]

def answer():
    day=0
    q=deque()
    for i in range(height):
        for j in range(row):
            for k in range(col):
                if graph[i][j][k]==1:
                    q.append((i,j,k))
    
    def bfs():
        dx=[-1,1,0,0,0,0]
        dy=[0,0,-1,1,0,0]
        dz=[0,0,0,0,1,-1]
        while q:
            cz,cx,cy=q.popleft()
            for i in range(6):
                nx=cx+dx[i]
                ny=cy+dy[i]
                nz=cz+dz[i]
                if 0<=nx<row and 0<=ny<col and 0<=nz<height and graph[nz][nx][ny]==0:
                    q.append((nz,nx,ny))
                    graph[nz][nx][ny]=graph[cz][cx][cy]+1
    bfs()                
    for i in range(height):
        for j in range(row):
            for k in range(col):
                if graph[i][j][k]==0:
                    print(-1)
                    exit(0)
                day=max(day, graph[i][j][k])
    print(day-1)

answer()
