def solution(n, times):
    answer = 0
    
    # left - the most effective case, minimum time
    # right - the most ineffective case, maximum time
    left = 1 # case; only 1 waiting person, only 1 minute needed
    right = max(times)*n # case; the slowest man deal to all n people
    
    while left <= right:
        mid = (left + right)//2
        
        # people - total number of people passed during mid-minutes
        people=0
        for time in times:
            people += mid//time
            if people >= n:
                break
        
        #if the total number of people passed is equl to or bigger than n, go to left-tree
        if people >= n:
            right = mid - 1
            answer = mid
        
        #if the total number of people passed is smaller than n, go to right-tree
        if people < n:
            left = mid + 1
            
    return answer
