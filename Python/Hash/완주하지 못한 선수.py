def solution(participant, completion):
    participant.sort()
    completion.sort()

    for p, c in zip(participant, completion):
        if p != c:
            return p
    
    return participant.pop()

p = ["leo", "kiki", "eden"]
c = ["eden", "kiki"]

print(solution(p, c))