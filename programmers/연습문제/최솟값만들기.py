def solution(A,B):
    answer = 0
    A = sorted(A)
    B = sorted(B, reverse = True)
    for ind in range(len(A)):
        answer += A[ind] * B[ind]
    return answer

if __name__ == "__main__":
    # print(solution([1, 4, 2], [5, 4, 4]))
    print(solution([1, 2], [3,4]))