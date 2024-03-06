# 10026 적록색약

from collections import deque
import sys

input = sys.stdin.readline

N = int(input())
list = [list(map(str, input().rstrip())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(a, b, visited):
    q = deque()
    q.append((a, b))
    visited[a][b] = True

    while q:
        cur_x, cur_y = q.popleft()
        for i in range(4):
            next_x = cur_x + dx[i]
            next_y = cur_y + dy[i]
            if (
                0 <= next_x < N
                and 0 <= next_y < N
                and not visited[next_x][next_y]
                and list[cur_x][cur_y] == list[next_x][next_y]
            ):
                visited[next_x][next_y] = True
                q.append((next_x, next_y))


def not_weak():
    visited = [[False] * N for _ in range(N)]
    count = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] == False:
                bfs(i, j, visited)
                count += 1
    return count


def weak():
    visited = [[False] * N for _ in range(N)]
    count = 0
    for i in range(N):
        for j in range(N):
            if list[i][j] == "R":
                list[i][j] = "G"

    for i in range(N):
        for j in range(N):
            if visited[i][j] == False:
                bfs(i, j, visited)
                count += 1
    return count

print(not_weak(),weak())
