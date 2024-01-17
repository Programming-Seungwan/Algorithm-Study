# 2583 영역구하기
# https://www.acmicpc.net/problem/2583

import sys
from collections import deque

input=sys.stdin.readline

M,N,K = map(int, input().split())
grid=[[0]*N for _ in range(M)]
visited=[[False]*N for _ in range(M)]
for _ in range(K):
    x1,y1,x2,y2=map(int, input().split())
    for i in range(M - y2, M - y1 ):
        for j in range(x1, x2):
            grid[i][j]=1
            
def area():
    num=0
    area=0
    area_list=[]
   
    def bfs(x,y):
        nonlocal area
        visited[x][y]=True
        queue=deque()
        queue.append((x,y))
        dx=[-1,1,0,0]
        dy=[0,0,-1,1]
        area=1
        while queue:
            cur_x, cur_y = queue.popleft()
            for i in range(4):
                next_x = cur_x + dx[i]
                next_y = cur_y + dy[i]
                if 0<=next_x<M and 0<=next_y<N:
                    if grid[next_x][next_y]==0 and not visited[next_x][next_y]:
                        queue.append((next_x, next_y))
                        visited[next_x][next_y]=True
                        area+=1
                        
    for i in range(M):
        for j in range(N):
            if grid[i][j]==0 and not visited[i][j]:
                bfs(i,j)
                num+=1
                area_list.append(area)
    area_list.sort()
    print(num)
    print(*area_list)
# 실행    
area()        
