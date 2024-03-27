import sys
input = sys.stdin.readline

t, w = map(int, input().split())
dp = [[[0 for _ in range(w + 2)] for _ in range(t + 1)] for _ in range(3)]