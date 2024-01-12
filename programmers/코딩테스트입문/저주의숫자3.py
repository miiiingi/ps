def solution(n):
    answer = []
    for num in range(1, n * 3):
        if len(answer) == n:
            return answer[-1]
        if num % 3 == 0 or '3' in str(num):
            continue
        else:
            answer.append(num)


if __name__ == "__main__":
    print(solution(15))
