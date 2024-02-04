# 1389 케빈 베이컨의 6단계 법칙
# https://www.acmicpc.net/problem/1389

from collections import deque
import sys
input=sys.stdin.readline

n,m = map(int,input().split())
n_list=[[]for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    n_list[a].append(b)
    n_list[b].append(a)
result=[]

q=deque()

def bfs(start):
    q.append(start)
    while q:
        cur=q.popleft()
        visited[cur]=True
        for next in n_list[cur]:
            if not visited[next]:
                q.append(next)
                visited[next]=True
                distance[next]=distance[cur]+1

for i in range(1, n+1):
    distance=[0 for _ in range(n+1)]
    visited=[False for _ in range(n+1)]
    bfs(i)
    result.append(sum(distance))

print(result.index(min(result))+1)
