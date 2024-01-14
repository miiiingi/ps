def solution(n):
    ans = 1
    while n != 1:
        ans += n % 2
        n -= n % 2
        n /= 2
    else:
        return ans

if __name__ == "__main__":
    # print(solution(5))
    # print(solution(6))
    print(solution(5000))