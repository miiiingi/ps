def solution(n):
    answer = ''
    for s in sorted(str(n), reverse=True):
        answer += s
    return int(answer)

if __name__ == "__main__":
    print(solution(118372))