length = int(input())

for i in range(length):
    a,b=input().split()
    print(f'Case #{i+1}: {a} + {b} = {int(a)+int(b)}')
