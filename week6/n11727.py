n = int(input())
rectangular = [0] * 1001
rectangular[1] = 1

if n >= 2:
    rectangular[2] = 3
    for i in range(3, n+1):
        rectangular[i] = (rectangular[i-2]*2) + rectangular[i-1]

print(rectangular[n]%10_007)