# 11501 주식
# https://www.acmicpc.net/problem/11501

import sys
input=sys.stdin.readline

T = int(input())
for i in range(T):
    num = int(input())
    stock = list(map(int, input().split()))
    max_stock=0
    benefit=0
    for j in range(len(stock)-1,-1,-1):
        if max_stock<stock[j]:
            max_stock=stock[j]
        elif max_stock>stock[j]:
            benefit+=max_stock-stock[j]
    print(benefit)
