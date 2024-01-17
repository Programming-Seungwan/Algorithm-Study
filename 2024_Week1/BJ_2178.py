# 2178 미로탐색
# https://www.acmicpc.net/problem/2178

import sys
from collections import deque

input=sys.stdin.readline

N,M=map(int, input().split())
grid=[list(map(int, input().rstrip())) for _ in range(N)]

def bfs():
    queue=deque()
    queue.append((0,0))
    dx=[-1,1,0,0]
    dy=[0,0,-1,1]
    while queue:
        cur_x,cur_y=queue.popleft()
        for i in range(4):
            next_x=cur_x+dx[i]
            next_y=cur_y+dy[i]
            if 0<=next_x<N and 0<=next_y<M and grid[next_x][next_y]==1:
                    grid[next_x][next_y]=grid[cur_x][cur_y]+1
                    queue.append((next_x,next_y))
    return grid[N-1][M-1] 

print(bfs())
