# Baekjoon 11049

N = int(input())
matrix = []
dp = []

for i in range(N):
    r, c = input().split()
    matrix.append(list((int(r), int(c))))

for i in range(N):
    dp.append([0 for i in range(N)])

# i, j = 행, 열
for i in range(1, N):
    for j in range(0, N-i):
        if i == 1:
            dp[j][j+1] = matrix[j][0] * matrix[j][1] * matrix[j+1][1]
            continue
        dp[j][j+i] = 2**32
        for k in range(j, j+i):
            dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + (matrix[j][0] * matrix[k][1] * matrix[j+i][1]))

print(dp[0][N-1])