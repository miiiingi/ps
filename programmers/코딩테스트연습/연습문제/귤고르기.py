import collections


def solution(k, tangerine):
    answer = []
    sorted_dict = dict(sorted(collections.Counter(
        tangerine).items(), key=lambda item: item[1], reverse=True))
    for key, value in sorted_dict.items():
        if k <= 0:
            return len(set(answer))
        if k < value:
            k -= value
            answer.append(key)
            continue
        k -= value
        answer.append(key)
    else:
        return len(set(answer))


if __name__ == "__main__":
    print(solution(6, [1, 3, 2, 5, 4, 5, 2, 3]))
