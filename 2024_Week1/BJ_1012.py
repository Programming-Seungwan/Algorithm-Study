# 1012 유기농배추
# https://www.acmicpc.net/problem/1012

import sys
from collections import deque

input=sys.stdin.readline
T=int(input())

def countNum(): # 총괄 함수
    num=0
    # 입력값에 대한 2차원 리스트 생성 (재료준비)
    M,N,K=map(int, input().split())
    grid=[[0]*M for _ in range(N)]
    for _ in range(K):
        X,Y=map(int, input().split())
        grid[Y][X]=1
     
    def bfs(y,x): # bfs 구현 (레시피)
        queue=deque()
        queue.append((y,x))
        dy=[-1,1,0,0]
        dx=[0,0,-1,1]
        while queue:
            cur_y,cur_x=queue.popleft()
            for i in range(4):
                next_x=cur_x+dx[i]
                next_y=cur_y+dy[i]
                if 0<=next_x<M and 0<=next_y<N and grid[next_y][next_x]==1:
                        grid[next_y][next_x]=2
                        queue.append((next_y,next_x))
    # 결과내기               
    for i in range(N): 
        for j in range(M):
            if grid[i][j]==1:
                grid[i][j]=2
                bfs(i,j)
                num+=1
    print(num)
                
# 실행  
for _ in range(T):
    countNum()

