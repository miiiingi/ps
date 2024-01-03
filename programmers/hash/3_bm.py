import collections
def solution(phone_book):
    phone_book = collections.deque(sorted(phone_book))
    while phone_book:
        phone = phone_book.popleft()
        for p in phone_book:
            if p[:len(phone)] == phone:
                return False
    return True

if __name__ == "__main__":
    print(solution(	["119", "97674223", "1195524421"]))