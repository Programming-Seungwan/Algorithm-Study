# 1446 지름길

import heapq
import sys

input = sys.stdin.readline
INF=int(1e9)

N,D = map(int, input().split())
graph = [[] for _ in range(D+1)]

distance = [INF]*(D+1)

for i in range(D):
    graph[i].append((1,i+1))

for _ in range(N):
    start,end,cost=map(int, input().split())
    if end>D: 
        continue
    graph[start].append((cost, end))

pq=[]
heapq.heappush(pq,(0,0))

while pq:
    cur_cost, cur_v = heapq.heappop(pq)

    if cur_cost>distance[cur_v]:
        continue

    for cost, next_v in graph[cur_v]:
        next_cost=cur_cost+cost
        if next_cost < distance[next_v]:
            distance[next_v]=next_cost
            heapq.heappush(pq,(next_cost,next_v))

print(distance[D])
