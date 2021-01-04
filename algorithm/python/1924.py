mon, day = map(int, input().split())

Day = 0
nums = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
DAY = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']


for i in range(mon-1):
    Day = Day + nums[i]
day = (Day + day) % 7

print(DAY[day])
