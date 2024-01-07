def solution(citations):
    answer = []
    for h in range(max(citations)):
        cnt = 0
        for cite in citations:
            if h <= cite:
                cnt += 1
        if cnt >= h:
            answer.append(h)
    return max(answer) 

if __name__ == "__main__":
    print(solution( [3, 0, 6, 1, 5] ))