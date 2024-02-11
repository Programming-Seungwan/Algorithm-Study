import sys
input = sys.stdin.readline
n, d = map(int, input().rstrip().split(' '))

graph = []
for _ in range(n):
    graph.append(list(map(int, input().rstrip().split(' '))))

distance = [i for i in range(d+1)]

for i in range(d+1):
    distance[i] = min(distance[i], distance[i-1]+1)
    for start, end, dist in graph:
        if i == start and end <= d and distance[i] + dist < distance[end]:
            distance[end] = distance[start] + dist
