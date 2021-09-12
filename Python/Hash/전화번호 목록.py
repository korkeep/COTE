def solution(phone_book):
    phone_book.sort()

    for p1, p2 in zip(phone_book, phone_book[1:]):
        if p2[:len(p1)] == p1:
            return False
    
    return True

pb = ["123", "456", "789"]
print(solution(pb))