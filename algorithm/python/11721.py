word=input()
length = len(word)

for i in range(0,length,10):
    th = i + 10
    print(word[i:th])
