def solution(n, words):
    visited = []
    cnt = 0
    while words:
        cnt += 1
        word = words.pop(0)
        if visited:
            if visited[-1][-1] != word[0]:
                if cnt % n == 0:
                    return [n, cnt // n]
                else:
                    return [cnt % n, (cnt // n) + 1]
        if word not in visited and len(word) > 1:
            visited.append(word)
        else:
            if cnt % n == 0:
                return [n, cnt // n]
            else:
                return [cnt % n, (cnt // n) + 1]
    else:
        return [0, 0]


if __name__ == "__main__":
    # print(solution(3, ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]))
    # print(solution(2, ["aba", "aba"]))
    # print(solution(2, ["a", "ab"]))
    # print(solution(2, ["a"]))
    # print(solution(3, ["tank", "tick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]))
    print(solution(3, ["tank", "kick", "know", "wheel", "land", "wheel", "mother", "tank"]))
