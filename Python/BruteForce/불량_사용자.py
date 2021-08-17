from itertools import permutations 

def check(users,banned_id):
    for i in range(len(banned_id)):
        if len(users[i]) != len(banned_id[i]):
            return False

        for j in range(len(users[i])):
            if banned_id[i][j] == "*":
                continue
            if banned_id[i][j] != users[i][j]:
                return False
            
    return True

def solution(user_id, banned_id):
    # list of all permutations about user_id whose length is len(banned-id)
    user_permutation = list(permutations(user_id, len(banned_id)))
    
    # set of all banned users
    banned_set = []

    for users in user_permutation:
        if not check(users, banned_id):
            # check the next tuple
            continue
        else:
            # to ignore the order, transform to just "set"
            users = set(users)
            if users not in banned_set:
                banned_set.append(users)

    return len(banned_set)
