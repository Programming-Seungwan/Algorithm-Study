# 2660 회장뽑기
# https://www.acmicpc.net/problem/2660

from collections import deque
import sys
input=sys.stdin.readline

n = int(input())
n_list = [[] for _ in range(n + 1)]
while True:
    a, b = map(int, input().split())
    if a == -1:
        break
    n_list[a].append(b)
    n_list[b].append(a)

q = deque()
result = [50]

def bfs(start):
    q.append(start)
    while q:
        cur = q.popleft()
        visited[cur] = True
        for next in n_list[cur]:
            if not visited[next]:
                visited[next] = True
                q.append(next)
                friends[next] = friends[cur] + 1


for i in range(1, n + 1):
    visited = [False for _ in range(n + 1)]
    friends = [0 for _ in range(n + 1)]
    bfs(i)
    result.append(max(friends))
min=min(result)

r_print=str(min)+' '+str(result.count(min))
r_list=list(filter(lambda x: result[x]==min, range(n+1)))
print(r_print)
print(' '.join(map(str,r_list)))
