# 11403 경로찾기
# https://www.acmicpc.net/problem/11403

from collections import deque
import sys
input=sys.stdin.readline

n = int(input())
n_matrix = [list(map(int, input().split())) for _ in range(n)]
visited = [[0 for _ in range(n)] for _ in range(n)]

def bfs(start):
    q = deque()
    q.append(start)
    while q:
        next=q.popleft()
        for i in range(n):
            if n_matrix[next][i] == 1 and visited[start][i] == 0:
                q.append(i)
                visited[start][i] = 1

for i in range(n):
    bfs(i)
    
print('\n'.join([' '.join(map(str, visited[i])) for i in range(n)]))
