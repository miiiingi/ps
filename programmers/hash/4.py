import collections
def solution(clothes):
    result = collections.defaultdict(list)
    cum = 1
    for cloth in clothes:
        result[cloth[1]].append(cloth[0])
    for v in list(result.values()):
        cum *= (len(v) + 1)
    return cum - 1

if __name__ == "__main__":
    print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))