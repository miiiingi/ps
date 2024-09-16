def solution(n):
    answer = dict()
    for i in range(n+1):
        if i == 0 or i == 1:
            answer[i] = i
        else:
            answer[i] = answer[i-1] + answer[i-2]
    return answer[n]


if __name__ == "__main__":
    print(solution(5))
