# 7562 나이트의이동
# https://www.acmicpc.net/problem/7562

import sys
from collections import deque

input=sys.stdin.readline
N=int(input())

def answer(I):
    graph=[[0]*I for _ in range(I)]
    x1,y1=map(int,input().split())
    x2,y2=map(int,input().split())
    graph[x1][y1]=1
    
    def bfs():
        q=deque()
        q.append((x1,y1))
        while q:
            cx,cy=q.popleft()
            if cx==x2 and cy==y2:
                return graph[x2][y2]-1
            for dx,dy in [(-2,-1), (-1,-2), (1,-2), (2,-1), (-2, 1), (-1, 2), (1, 2), (2, 1)]:
                nx=cx+dx
                ny=cy+dy
                if 0<=nx<I and 0<=ny<I and graph[nx][ny]==0:
                    q.append((nx,ny))
                    graph[nx][ny]=graph[cx][cy]+1
                    
    print(bfs())
# 실행    
for _ in range(N):
    I=int(input())
    answer(I)
