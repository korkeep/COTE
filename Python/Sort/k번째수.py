def solution(array, commands):
    answer = []

    for cmd in commands:
        i, j, k = cmd[0], cmd[1], cmd[2]
        sub = array[i-1:j]
        sub.sort()
        answer.append(sub[k-1])

    return answer

arr = [1, 5, 2, 6, 3, 7, 4]
cmd = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]

print(solution(arr, cmd))