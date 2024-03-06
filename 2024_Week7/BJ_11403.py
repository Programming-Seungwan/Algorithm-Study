# 경로찾기

from collections import deque
import sys
input=sys.stdin.readline

N = int(input())
list = [list(map(int, input().split())) for _ in range(N)]
graph = [[] for _ in range(N)]

for i in range(N):
    for j in range(N):
        if list[i][j] == 1:
            graph[i].append(j)

q = deque()

def bfs(x):
    q.append(x)
    while q:
        cur = q.popleft()
        for next in graph[cur]:
            if not visited[next]:
                visited[next] = True
                q.append(next)
                result[next] = 1

for i in range(N):
    visited = [False for _ in range(N)]
    result = [0 for _ in range(N)]
    bfs(i)
    print(' '.join(map(str,result)))
