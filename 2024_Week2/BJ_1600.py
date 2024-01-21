# 1600 말이되고픈원숭이
# https://www.acmicpc.net/problem/1600

from collections import deque
input=sys.stdin.readline

K = input()
col, row= map(int, input().split())
graph=[map(int,input().split()) for _ in range(row)]

def answer():
    visited=[[False]*col for _ in range(row)]
    min=0
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    # 말의 움직임 K번

    def bfs(x,y):
        visited[x][y]==True
        q=deque()
        q.append(x,y)
        while q:
            cx,cy=q.popleft()
            for i in range(4):
                nx=cx+dx[i]
                ny=cy+dy[i]
                # if 0<=nx<I and 0<=ny<I and graph[nx][ny]==0 and
                    # q.append((nx,ny))
                    # graph[nx][ny]=graph[cx][cy]+1
                
    for i in range(row):
        for j in range(col):
            #if절
                bfs(i,j)

answer()

