import collections
def solution(friends, gifts):
    present = collections.defaultdict(list)
    score = collections.defaultdict(int)
    for k, v in collections.Counter(gifts).items():
        giver = k.split(" ")[0]
        gived = k.split(" ")[1]
        score[giver] += v
        score[gived] -= v
        present[giver].append(gived)
    answer = 0
    return answer

if __name__ == "__main__":
    print(solution(["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]))