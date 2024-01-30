# 계란으로 바위치기
# 
import sys
input=sys.stdin.readline

N=int(input())
n_list=[list(map(int,input().split())) for _ in range(N)]
# max=0
# count=0
# visit=0

# def recur(visit):
#     global count, max
#     if visit>N:
#         if max<count:
#             max=count
#         return
#     if n_list[visit][0]<=0:
#         recur(visit+1)
#     else:
#         for i in range(0,N):
#             if i!=visit and n_list[i][0]>0:
#                 n_list[visit][0]-=n_list[i][1]
#                 n_list[i][0]-=n_list[visit][1]
#                 if n_list[visit][0]<=0:
#                     count+=1
#                 if n_list[i][0]<=0:
#                     count+=1
#                 print(i)
#                 recur(visit+1)
#                 n_list[visit][1]+=n_list[i][0]
#                 n_list[i][1]+=n_list[visit][0]

# recur(0)
# print(max)
