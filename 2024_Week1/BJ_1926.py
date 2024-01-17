# 1926 그림
# https://www.acmicpc.net/problem/1926

import sys
from collections import deque

input=sys.stdin.readline

row, col = map(int,input().split())
grid=[list(map(int,input().split())) for _ in range(row)]
visited=[[False]*col for _ in range(row)]

def numPic(): 
    max_area=0
    area=0
    num=0

    def bfs(x,y):
        nonlocal area
        area=1
        visited[x][y]=True
        queue=deque()
        queue.append((x,y))
        dx=[-1,1,0,0]
        dy=[0,0,-1,1]
        while queue:
            cur_x,cur_y=queue.popleft()
            for i in range(4):
                next_x=cur_x+dx[i]
                next_y=cur_y+dy[i]
                if 0<=next_x<row and 0<=next_y<col:
                    if grid[next_x][next_y]==1 and not visited[next_x][next_y]:
                        visited[next_x][next_y]=True
                        queue.append((next_x,next_y))
                        area+=1
    for i in range(row):
        for j in range(col):
            if grid[i][j]==1 and not visited[i][j]:
                bfs(i,j)
                if max_area < area:
                    max_area = area
                num+=1
                area=0
                
    print(num)
    print(max_area)
# 실행
numPic()
