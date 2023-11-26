import sys
input = sys.stdin.readline
test_case = int(input())

for _ in range(test_case):
    N, M = map(int, input().split())  #N:국가의 수, M:비행기 수
    for _ in range(M):
        a, b = map(int, input().split())


#n개의 정점을 가지는 그래프의 최소 간선의 수: n-1
print(N-1)