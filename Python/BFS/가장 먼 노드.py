from collections import deque

def solution(n, edge):
    distance = dict()

    for e1, e2 in edge:
        distance.setdefault(e1, []).append(e2)
        distance.setdefault(e2, []).append(e1)

    deck = deque([[1, 0]]) # node, depth
    check = [-1]*(n+1)
    while deck:
        index, depth = deck.popleft()
        check[index] = depth
        for i in distance[index]:
            if check[i] == -1:
                check[i] = 0
                deck.append([i, depth+1])
        depth = depth + 1

    return check.count(max(check))

n = 6
vertex = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
print(solution(n, vertex))