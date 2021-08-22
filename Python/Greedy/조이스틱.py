def solution(name):
    answer = 0
    min_move = len(name) - 1
    next = 0
    
    for i, char in enumerate(name):
        
        # go up, or go down?
        answer += min(ord(char) - ord('A'), ord('Z') - ord(char) + 1)
        
        # if there is 'A' in the way to go next not 'A', we have to think about it.
        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
        
        # go right, or go left?
        min_move = min(min_move, i + i + len(name) - next)
        
    answer += min_move
    return answer
