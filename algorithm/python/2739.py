num = int(input())
result = [num*(i+1) for i in range(9)]

for i in range(9):
    print(f'{num} * {i+1} = {result[i]}')
