def solution(n):
    cnt_n = bin(n).count('1')
    for num in range(n+1, 1000001):
        if bin(num).count('1') == cnt_n:
            return num


if __name__ == "__main__":
    print(solution(78))
