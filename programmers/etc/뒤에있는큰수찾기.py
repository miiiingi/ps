def solution(numbers):
    stack =[]
    answer = [-1 for _ in range(len(numbers))]
    for i in range(len(numbers)-1, -1, -1):
        while stack:
            if stack[-1] > numbers[i]:
                answer[i] = stack[-1]
                break
            else:
                stack.pop()
            
        stack.append(numbers[i])
    return answer