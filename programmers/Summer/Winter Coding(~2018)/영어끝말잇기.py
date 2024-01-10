def solution(n, words):
    visited = []
    cnt = 0
    while words:
        cnt += 1
        word = words.pop(0)
        if visited:
            if visited[-1][-1] != word[0]:
                if cnt % n == 0:
                    return [(cnt // n) + 1, cnt // n]
                else:
                    return [cnt % n, (cnt // n) + 1]
        if  word not in visited:
            visited.append(word)
        else:
            if cnt % n == 0:
                return [(cnt // n) + 1, cnt // n]
            else:
                return [cnt % n, (cnt // n) + 1]
    else:
        return [0, 0]

if __name__ == "__main__":
    # print(solution(3, ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]))
    print(solution(2, ["abc", "dca"]))