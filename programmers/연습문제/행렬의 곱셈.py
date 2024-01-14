def solution(arr1, arr2):
    answer = [[] for _ in range(len(arr1))]
    for j in range(len(arr1)):
        for k in range(len(arr2[0])):
            cnt = 0
            for i in range(len(arr1[0])):
                cnt += arr1[j][i] * arr2[i][k]
            answer[j].append(cnt)
    return answer

if __name__ == "__main__":
    # print(solution([[1, 4], [3, 2], [4, 1]], [[3, 3], [3, 3]]))
    print(solution([[2, 3, 2], [4, 2, 4], [3, 1, 4]], [[5, 4, 3], [2, 4, 1], [3, 1, 1]]))