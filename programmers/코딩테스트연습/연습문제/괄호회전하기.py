import collections


def isBalanced(s) -> bool:
    stack = []
    for i in range(len(s)):
        if s[i] == "(" or s[i] == "{" or s[i] == "[":
            stack.append(s[i])
        elif s[i] == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                return False
        elif s[i] == "}":
            if stack and stack[-1] == "{":
                stack.pop()
            else:
                return False
        elif s[i] == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                return False
    if len(stack) == 0:
        return True
    else:
        return False


def solution(s):
    answer = 0
    deque = collections.deque(s)
    for _ in range(len(s)):
        deque.rotate(-1)
        if isBalanced(deque):
            answer += 1
    return answer


if __name__ == "__main__":
    print(solution("[](){}"))
