import sys
from collections import deque

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

M, N= map(int, sys.stdin.readline().strip().split())

tray = []

for _ in range(N):
  tray.append(list(map(int, sys.stdin.readline().strip().split())))

Q = deque()

for r in range(N):
  for c in range(M):
    if tray[r][c] == 1:
      Q.append([r, c])

while Q:

  length = len(Q)
  for _ in range(length):
    r, c = Q.popleft()

    for i in range(4):
      nr = r + dr[i]
      nc = c + dc[i]

      # 토마토 칸의 범위에서 벗어나지 않거나
      # 익지 않은 토마토인 경우에만
      if nr >= 0 and nr < N and nc >= 0 and nc < M and tray[nr][nc] == 0:
        # 현재 칸까지의 소요일
        # 1로 시작했으므로 마지막에 -1
        tray[nr][nc] = tray[r][c] + 1
        
        Q.append([nr, nc])
        
day = 0

for row in tray:

  for tomato in row:
    # 토마토가 익지 않은 경우
    if tomato == 0:
      print(-1)
      exit(0)

  day = max(day, max(row))

print(day - 1)