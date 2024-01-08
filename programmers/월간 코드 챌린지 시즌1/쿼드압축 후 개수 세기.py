def solution(arr):
    answer = []
    div = len(arr) // 2
    for _ in range(len(arr)):
        if _ == 0:
            answer.append(arr[:div][:div])
        elif _ == 1:
            answer.append(arr[:div][div:])
        elif _ == 2:
            answer.append(arr[div:][:div])
        elif _ == 3:
            answer.append(arr[div:][div:])
    divided = arr // 2

    for ind in range(len(arr)):
        answer[ind]
        pass
    return answer

if __name__ == "__main__":
    solution([[1, 1, 0, 0], [1, 0, 0, 0], [1, 0, 0, 1], [1, 1, 1, 1]])