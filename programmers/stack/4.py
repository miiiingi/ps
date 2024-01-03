import collections
def solution(priorities, location):
    elem_list = collections.deque()
    for i in range(len(priorities)):
        elem_list.append((priorities[i], i))
    stack = []
    while elem_list:
        p = elem_list.popleft()
        if elem_list:
            max_value = max(enumerate(elem_list), key=lambda x: x[1][0])[1][0]
            if p[0] < max_value:
                elem_list.append(p)
            else:
                if p[1] == location:
                    return len(stack) + 1
                stack.append(p)
        else:
            if p[1] == location:
                return len(stack) + 1
            stack.append(p)
    return stack.index(priorities[location]) + 1
def solution2(priorities, location):
    answer = 0
    elem_list = collections.deque()
    for i in range(len(priorities)):
        elem_list.append((priorities[i], i))
    while elem_list:
        elem = elem_list.popleft()
        judge = any(elem[0] < p[0] for p in elem_list)
        if judge:
            elem_list.append(elem)
        else:
            answer += 1
            if elem[1] == location:
                return answer

if __name__ == "__main__":
    # solution([1, 1, 9, 1, 1, 1], 0)
    print(solution2([1, 1, 9, 1, 1, 1], 0))