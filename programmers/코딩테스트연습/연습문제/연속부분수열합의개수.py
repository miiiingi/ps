def solution(elements):
    answer = []
    for i in range(len(elements)):
        for j in range(len(elements)):
            if j + i + 1 > len(elements):
                answer.append(sum(elements[j: j+i+1]) + sum(elements[0: j+i+1 - len(elements)]))
            else:
                answer.append(sum(elements[j: j+i+1]))
    return len(set(answer))

if __name__ == "__main__":
    print(solution([7, 9, 1, 1, 4]))
