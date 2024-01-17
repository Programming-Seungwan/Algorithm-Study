# 2667 단지번호붙이기
# https://www.acmicpc.net/problem/2667

import sys
from collections import deque

input=sys.stdin.readline

N=int(input())
visited=[[False]*N for _ in range(N)]
graph=[list(map(int,input().rstrip())) for _ in range(N)]

def area():
    num=0
    area_list=[]
    
    def bfs(x,y):
        area=1
        queue=deque()
        queue.append((x,y))
        dx=[-1,1,0,0]
        dy=[0,0,-1,1]
        while queue:
            cur_x,cur_y=queue.popleft()
            for i in range(4):
                next_x=cur_x+dx[i]
                next_y=cur_y+dy[i]
                if 0<=next_x<N and 0<=next_y<N and graph[next_x][next_y]==1 and not visited[next_x][next_y]:
                    visited[next_x][next_y]=True
                    queue.append((next_x, next_y))
                    area+=1
        return area
      
    for i in range(N):
        for j in range(N):
            if graph[i][j]==1 and not visited[i][j]:
                visited[i][j]=True
                area_list.append(bfs(i,j))
                num+=1
    area_list.sort()
    print(num)
    print(*area_list)       
# 실행
area() 
