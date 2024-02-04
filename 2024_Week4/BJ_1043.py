# 1043 거짓말
# https://www.acmicpc.net/problem/1043

import sys
input=sys.stdin.readline

n, m = map(int, input().split())
fact = set(input().split()[1:])
parties = []
cnt = 0

for _ in range(m):
    parties.append(set(input().split()[1:]))

for _ in range(m):
    for party in parties:
        if party & fact:
            fact = fact.union(party)

for party in parties:
    if party & fact:
        continue
    cnt += 1

print(cnt)
