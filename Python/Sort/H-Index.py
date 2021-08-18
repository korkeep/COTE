def solution(citations):
    citations.sort(reverse=True)
    
    # i 
    # == number of paper that has more citation num than citations[i]
    # == h
    # == candidate of H-Index
    for i in range(len(citations)):
        
        # i is candidate of H-Index only if citations[i] >= i
        # if citations[i] <= i, i can't be candidate 
        if citations[i] <= i:
            return i
    
    # if all paper's citations num is same as or bigger than len(citations),
    # H-Index is just len(citations)
    return len(citations)
