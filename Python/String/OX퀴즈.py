# Baekjoon: 8958

n = int(input())

for i in range (n):
    str = input()
    tmp = result = 0
    
    for j in str:
        if j == 'O':
            tmp = tmp + 1
        else:
            tmp = 0
        result = result + tmp
    
    print(result)