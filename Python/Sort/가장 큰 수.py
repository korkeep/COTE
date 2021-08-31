def solution(numbers):
    numbers_dic = [str(num) for num in numbers]
    # num is equal to or smaller than 1,000, so *3
    numbers_dic.sort(key=lambda num: num*3, reverse = True)
    answer = str(int(''.join(numbers_dic)))
    return answer
