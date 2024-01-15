def solution(phone_book):
    phone_book = sorted(phone_book)
    for i in range(len(phone_book)):
        if phone_book[i] == phone_book[i+1][:len(phone_book[i])]:
            return False
    return True

if __name__ == "__main__":
    print(solution(["119", "97674223", "1195524421"]))
    # print(solution(["123", "456", "789"]))
