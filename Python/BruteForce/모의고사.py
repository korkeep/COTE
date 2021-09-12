def solution(answers):
    cnt = [0, 0, 0]
    answer = []

    supo1 = [1, 2, 3, 4, 5]
    supo2 = [2, 1, 2, 3, 2, 4, 2, 5]
    supo3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    for idx in range(len(answers)):
        if answers[idx] == supo1[idx%5]:
            cnt[0] = cnt[0] + 1
        if answers[idx] == supo2[idx%8]:
            cnt[1] = cnt[1] + 1
        if answers[idx] == supo3[idx%10]:
            cnt[2] = cnt[2] + 1
    
    for i in range(len(cnt)):
        if cnt[i] == max(cnt):
            answer.append(i + 1)

    return answer

answers1 = [1, 2, 3, 4, 5]
answers2 = [1, 3, 2, 4, 2]
print(solution(answers2))