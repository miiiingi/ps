def solution(n):
    answer = []
    for num in range(1, n+1):
        cnt = 0
        for temp in range(1, num + 1):
            if num % temp == 0:
                cnt += 1
        if cnt >= 3:
            answer.append(num)
    return len(answer)


if __name__ == "__main__":
    print(solution(10))
    print(solution(15))
