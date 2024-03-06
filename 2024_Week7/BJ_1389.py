# 1389 케빈 베이컨의 6단계 법칙

import sys
from collections import deque

input=sys.stdin.readline

N, M = map(int, input().split())
list = [[] for _ in range(N + 1)]
result = [] * (N + 1)

for _ in range(M):
    a, b = map(int, input().split())
    list[a].append(b)
    list[b].append(a)

q = deque()
def bfs(x):
    q.append(x)
    while q:
        cur = q.popleft()
        visited[cur] = True
        for next in list[cur]:
            if not visited[next]:
                q.append(next)
                visited[next] = True
                distance[next] = distance[cur] + 1
for i in range(1, N + 1):
    # i번 사람에 대한 재료들
    distance = [0 for _ in range(N + 1)]
    visited = [False for _ in range(N + 1)]
    bfs(i)
    result.append(sum(distance))
    
print(result.index(min(result)) + 1)
