from collections import deque

N, M = map(int,input().split())

visited = [[False] * M for _ in range(N)]

graph = [list(map(int, input().strip())) for _ in range(N)]

dx = [0,0,-1,1]
dy = [1,-1,0,0]

def bfs(x, y):
  queue = deque()
  queue.append([x, y])  
  
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      
      if x == N -1 and y == M-1:
        print(graph[N -1][M-1])
        break
        
      if 0<=nx<N and 0<=ny<M:      
        if visited[nx][ny] == False and graph[nx][ny] == 1:          
          graph[nx][ny] = graph[x][y] + 1
          visited[nx][ny] = True
          queue.append([nx, ny])
          
bfs(0,0)