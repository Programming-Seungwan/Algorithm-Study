import sys
from collections import deque

N, K= map(int, sys.stdin.readline().strip().split())

Q = deque()
Q.append(N) # 수빈이 위치

sec = 0
flag = True 
visited = [0]  * 100001 

while flag:
  # 현재 큐 위치 기준으로 X-1, X+1, 2*X을 이동해 큐의 끝에 삽입
  length = len(Q)

  for _ in range(length):
    x = Q.popleft()
    if x == K:
      print(sec)
      flag = False
      break
    
    # 이동할 수 있는 경우의 위치들을 큐에 삽입
    for nx in [x-1, x+1, 2*x]:
      # 메모리초과 오류
      if 0 <= nx and nx <= 100000 and visited[nx] == 0:
        Q.append(nx)
        visited[nx] = 1

  sec += 1