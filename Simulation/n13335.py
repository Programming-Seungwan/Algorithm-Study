import sys

n, w, l = map(int, input().split())
q = list(map(int, input().split()))
 
b = [0] * w
time = 0
while b: # 마지막 트럭이 들어오고 그 트럭이 빠져나갈 때 까지
	time += 1
	b.pop(0) # 다리 첫번째 요소 pop
	if q: # 트럭이 존재할 때만 다리에 append
		if sum(b) + q[0] <= l:
			b.append(q.pop(0))
		else:
			b.append(0) # 트럭이 있지만 다리에 올리지 못할 경우 다리 공간 채워줘야 함
print(time)