N = int(input())

schedule = []

for _ in range(N):
    schedule.append(list(map(int, input().split())))

dp = [0] * (N+1)

for i in range(n-1, -1, -1):
    if i + schedule[i][0] > N:
        dp[i] = dp[i+1]
    else:
        dp[i] = max(schedule[i][1] + dp[i+schedule[i][0]], dp[i+1])

# print(dp)
print(dp[0])