stack = dict()
def solution(n):
    for i in range(n + 1):
        if i == 0 or i == 1:
            stack[i] = i
        else:
            stack[i] = stack[i-2] + stack[i-1]
    return stack[n] % 1234567

if __name__ == "__main__":
    print(solution(5))