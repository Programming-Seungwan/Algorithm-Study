# 1916 최소비용구하기
# https://www.acmicpc.net/problem/1916

import heapq
import sys
input=sys.stdin.readline

N = int(input())
M = int(input())
graph = [[] for _ in range(N+1)]

for _ in range(M):
    start,end,cost=map(int, input().split())
    graph[start].append((cost, end))

depature, arrival = map(int, input().split())      

def dijkstra(depature,arrival):
    costs={}
    pq=[]
    heapq.heappush(pq,(0,depature))

    while pq:
        cur_cost, cur_v = heapq.heappop(pq)
        if cur_v not in costs:
            costs[cur_v] = cur_cost
            for cost, next_v in graph[cur_v]:
                next_cost=cur_cost+cost
                heapq.heappush(pq,(next_cost,next_v))
    print(costs[arrival])

dijkstra(depature,arrival)
