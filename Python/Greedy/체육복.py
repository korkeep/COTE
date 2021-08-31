def solution(n, lost, reserve):
    # students who can borrow
    can_borrow = list(set(reserve) - set(lost))
    # students who need borrow
    need_borrow = list(set(lost) - set(reserve))
    
    answer = n - len(need_borrow)
    
    # start borrowing
    for student in need_borrow:
        if student-1 in can_borrow:
            can_borrow.remove(student-1)
            answer += 1
        elif student+1 in can_borrow:
            can_borrow.remove(student+1)
            answer += 1
    
    return answer
