def solution(s):
    stacks = []
    for p in s:
        if p == "(":
            stacks.append(p)
        elif not stacks and p == ")":
            return False
        elif stacks and p == ")":
            stacks.pop()
    return len(stacks) == 0 

if __name__ == "__main__":
    print(f'result: {solution("()))")}')