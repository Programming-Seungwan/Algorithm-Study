import sys
from itertools import permutations


N = int(sys.stdin.readline())
numbers = list(map(int, sys.stdin.readline().split()))
ops = list(map(int, sys.stdin.readline().split()))
ops_list = []


for i, op in enumerate(ops):
    if i == 0:
        ops_list += ['+'] * op
    elif i == 1:
        ops_list += ['-'] * op
    elif i == 2:
        ops_list += ['*'] * op
    else:
        ops_list += ['//'] * op
 
permuted_ops_list = list(set(permutations(ops_list)))
 
totals = []
 
for op in permuted_ops_list:
    total = numbers[0]
    for nums, o in zip(numbers[1:], op):
        if o == '+':
            total += numbers
        elif o == '-':
            total -= numbers
        elif o == '*':
            total *= numbers
        else:
            if total < 0:
                total = (-1) * (((-1) * total) // numbers)
            else:
                total //= numbers
    totals.append(total)
 
print(max(totals))
print(min(totals))
