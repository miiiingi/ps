def hanoi(n, start, dest, mid, stack):
    if n == 1:
        stack.append([start, dest])
    else:
        hanoi(n - 1, start, mid, dest, stack)
        stack.append([start, dest])
        hanoi(n - 1, mid, dest, start, stack)
def solution(n):
    answer = []
    hanoi(n, 1, 3, 2, answer)
    return answer

if __name__ == "__main__":
    print(solution(3))