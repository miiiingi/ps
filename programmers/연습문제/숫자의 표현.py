def solution(n):
    answer = 0
    for nn in range(1, n + 1):
        cnt = 0
        for nnn in range(nn, n + 1):
            if cnt > n:
                break
            elif cnt < n:
                cnt += nnn
            if cnt == n:
                answer += 1
                break 
    return answer

if __name__ == "__main__":
    print(solution(15))