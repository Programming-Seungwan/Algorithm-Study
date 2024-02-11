# 1261 알고스팟
# https://www.acmicpc.net/problem/1261

import heapq
import sys
input=sys.stdin.readline

M, N = map(int, input().split())
graph = [list(map(int, input().rstrip())) for _ in range(N)]
INF=int(1e9)
distance = [[INF]*M for _ in range(N)]

dx=[-1,1,0,0]
dy=[0,0,-1,1]

def dijkstra(start, end):
    pq=[]
    start_x,start_y=start
    end_x,end_y=end
    heapq.heappush(pq,(0,start_x,start_y))

    while pq:
        cur_cost, cur_sx, cur_sy = heapq.heappop(pq)
        for i in range(4):
            next_x = cur_sx + dx[i]
            next_y = cur_sy + dy[i]
            if not(0<=next_y<M and 0<=next_x<N):
                continue
            if distance[next_x][next_y] > cur_cost+graph[next_x][next_y]:
                distance[next_x][next_y] = cur_cost+graph[next_x][next_y]
                heapq.heappush(pq, (distance[next_x][next_y], next_x, next_y))
    print(distance[end_x][end_y])

dijkstra((0,0),(N-1,M-1))
