import sys

def DFS(r, c, cp):
  global cnt
  apts[r][c] = cp

  cnt += 1

  visited[r][c] = 1
  
  for i in range(4):
    nr = r + dr[i]
    nc = c + dc[i]

    # 지도 범위 내 + not visited + 집이 있는 곳(1)인 경우에만
    if 0 <= nr < N and 0 <= nc < N and visited[nr][nc] == 0 and apts[nr][nc] != 0:
      # DFS 재귀 호출
      DFS(nr, nc, cp)

N = int(sys.stdin.readline().strip())

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

# 단지 정보 입력
apts = []
for _ in range(N):
  apts.append(list(map(int, sys.stdin.readline().strip())))

# 해당 집에 방문했는지 확인
visited = [[0]*N for _ in range(N)]

cnts = [] 
global cnt
cp = 0  # 단지 번호

for i in range(N):
  for j in range(N):
    if apts[i][j] != 0 and visited[i][j] == 0:
      cnt = 0
      cp += 1
      DFS(i, j, cp)
      cnts.append(cnt)
      
print(cp)
cnts.sort()
for i in range(len(cnts)):
  print(cnts[i])