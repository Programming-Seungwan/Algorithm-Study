import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().rstrip().split())
art = []
cnt = 0 # 그림의 갯수
res = [0] # 그림의 넓이

# 그림 그리기
for i in range(n):
    art.append(list(map(int,input().rstrip().split())))
    
def bfs(x,y):
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]

    queue = deque()
    queue.append([x,y])

    art[x][y] = 0 
    size = 1

    while queue:
        a,b = queue.popleft()
        for i in range(4):
            nx = a + dx[i]
            ny = b + dy[i]
			# 도화지 안에 위치하고 아직 방문하지 않았다면 방문
            if 0 <= nx < n and 0 <= ny < m and art[nx][ny] == 1:
                size += 1
                art[nx][ny] = 0          
                queue.append([nx, ny])
    res.append(size)

for x in range(n):
    for y in range(m):
        if art[x][y] == 1:
            bfs(x,y)
            cnt += 1

print(cnt)
print(max(res))