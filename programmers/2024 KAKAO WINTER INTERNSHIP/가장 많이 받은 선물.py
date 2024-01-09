import collections
def solution(friends, gifts):
    present = collections.defaultdict(lambda: collections.defaultdict(int))
    cnt = collections.Counter(gifts)
    visited = []
    for _ in range(len(friends)):
        f = friends.pop(0)
        for k, v in cnt.items():
            if k in visited:
                continue
            giver = k.split()[0]
            gived = k.split()[1]
            if giver == f:
                present[giver][gived] += v
                visited.append(k)
        friends_copied = friends.copy()
        for f_gived in list(present[f].keys()):
            friends_copied.remove(f_gived)
        for f_remained in friends_copied:
            present[f][f_remained] = 0
        friends.append(f)
    answer = 0
    return answer


if __name__ == "__main__":
    print(solution(["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo",
          "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]))
    # print(solution(["joy", "brad", "alessandro", "conan", "david"], ["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]))
