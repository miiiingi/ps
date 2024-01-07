def solution(A,B):
    stacks = []
    indexes = []
    answer = 0
    for i in A:
        stack = []
        for j in B:
            stack.append(i * j)
        stacks.append(stack)
    stacks = sorted(stacks, key = lambda x: sum(x), reverse=True)
    for stack in stacks:
        index = stack.index(min(stack))
        while index and index in indexes:
            stack.remove(stack[index])
            index = stack.index(min(stack))
        else:
            indexes.append(index)
    for ind, m in zip(indexes, range(len(indexes))):
        answer += stacks[m][ind]
    return answer

if __name__ == "__main__":
    print(solution([1, 4, 2], [5, 4, 4]))