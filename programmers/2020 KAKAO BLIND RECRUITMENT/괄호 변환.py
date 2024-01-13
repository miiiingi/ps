def checkBalanced(p):
    cnt = 0
    for i in range(len(p)):
        if p[i] == "(":
            cnt += 1
        else:
            cnt -= 1
        if cnt == 0:
            return i
def checkRight(p):
    result = []
    p = list(p)
    while p:
        b = p.pop(0)
        if b == "(":
            result.append(b)
        elif result and result[-1] == "(":
            result.pop()
        else:
            result.append(b)
    if result:
        return False
    else:
        return True 
def createRightS(u, v):
    result = '(' + createRightF(v) + ')'
    u = list(u[1:-1])
    for ind, b in enumerate(u):
        if b == "(":
            u[ind] = ")"
        else:
            u[ind] = "(" 
    return result + "".join(u)
def createRightF(p):
    if p == "":
        return ""
    i = checkBalanced(p)
    u = p[:i+1]
    v = p[i+1:]
    if checkRight(u):
        return u + createRightF(v)
    else:
        return createRightS(u, v)
def solution(p):
    return createRightF(p)

if __name__ == "__main__":
    # print(solution(")("))
    # print(solution("()))((()"))
    print(solution("(()())()"))