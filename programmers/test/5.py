def solution(foods):
    if len(foods) < 3:
        return 0
    potion = sum(foods) / 3
    answer = 0
    q = len(foods) // 3
    while foods:
        foods_copied = foods.copy()
        memory = []
        for i in range(len(foods_copied[:q+2])):
            if sum(foods_copied[:i]) == potion:
                memory.append(i)
        if len(memory) == 0:
            return 0
        elif len(memory) == 1:
            for j in range(memory[-1]):
                foods_copied.pop(0)
            foods = foods_copied
        else:
            return len(memory)


if __name__ == "__main__":
    print(solution([1, 2, 3, 0, 3]))
