# 1753 최단경로
# https://www.acmicpc.net/problem/1753

import heapq
import sys
input=sys.stdin.readline

V,E = map(int, input().split())
start = int(input())

graph = [[] for _ in range(V+1)]
INF=int(1e9)
distance = [INF] * (V+1)

for _ in range(E):
    u,v,w = map(int,input().split())
    graph[u].append((v,w))

def dijkstra(start):
    pq=[]
    heapq.heappush(pq,(0,start))
    distance[start] = 0
    while pq:
        dist, now = heapq.heappop(pq)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist+ i[1]
            if cost < distance[i[0]] :
                distance[i[0]] = cost
                heapq.heappush(pq,(cost,i[0]))

dijkstra(start)

for i in range(1,V+1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])
