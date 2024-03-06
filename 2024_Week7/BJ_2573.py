# 2573 빙산

from collections import deque 
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
iceberg = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 1년 후 빙산 만들기
def one_year():
    melt_index = []
    for i in range(N):
        for j in range(M):
            if iceberg[i][j] != 0:
                melt = 0
                for k in range(4):
                    next_x = i + dx[k]
                    next_y = j + dy[k]
                    if (
                        0 <= next_x < N
                        and 0 <= next_y < M
                        and iceberg[next_x][next_y] == 0
                    ):
                        melt += 1
                melt_index.append((i, j, melt))
    for x, y, m in melt_index:
        iceberg[x][y] = max(iceberg[x][y] - m, 0)  # 음수가 되면 0으로 바꿈.


# bfs
def bfs(x, y, visited):
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    while q:
        cur_x, cur_y = q.popleft()
        for i in range(4):
            next_x = cur_x + dx[i]
            next_y = cur_y + dy[i]
            if (
                0 <= next_x < N
                and 0 <= next_y < M
                and not visited[next_x][next_y]
                and iceberg[next_x][next_y] > 0
            ):
                visited[next_x][next_y] = True
                q.append((next_x, next_y))


# 빙산 쪼개진 상태 체크
year = 0
while True:
    visited = [[False] * M for _ in range(N)]
    iceberg_count = 0
    for i in range(N):
        for j in range(M):
            if iceberg[i][j] > 0 and not visited[i][j]:
                bfs(i, j, visited)
                iceberg_count += 1

    if iceberg_count == 0:
        print(0)
        break

    if iceberg_count >= 2:
        print(year)
        break

    one_year()
    year += 1
