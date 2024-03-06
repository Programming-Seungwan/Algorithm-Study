# 7569 토마토

from collections import deque
import sys

input = sys.stdin.readline

M, N, H = map(int, input().split())  # 열, 행, 높이
list = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]

dx = [-1, 1, 0, 0, 0, 0]  # 열
dy = [0, 0, -1, 1, 0, 0]  # 행
dz = [0, 0, 0, 0, -1, 1]  # 높이

day = 0

q = deque()

for h in range(H):
    for n in range(N):
        for m in range(M):
            if list[h][n][m] == 1:
                q.append((h, n, m))


while q:
    cur_z, cur_y, cur_x = q.popleft()
    for i in range(6):
        next_x = cur_x + dx[i]
        next_y = cur_y + dy[i]
        next_z = cur_z + dz[i]
        if (
            0 <= next_x < M
            and 0 <= next_y < N
            and 0 <= next_z < H
            and list[next_z][next_y][next_x] == 0
        ):
            q.append((next_z, next_y, next_x))
            list[next_z][next_y][next_x] = list[cur_z][cur_y][cur_x] + 1

for h in range(H):
    for n in range(N):
        for m in range(M):
            if list[h][n][m] == 0:
                print(-1)
                exit(0)
            day = max(day, list[h][n][m])
print(day - 1)
