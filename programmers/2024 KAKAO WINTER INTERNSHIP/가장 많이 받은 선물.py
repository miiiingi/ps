import collections
import itertools
def solution(friends, gifts):
    cnt_index = dict()
    cnt_friend = collections.defaultdict(int)
    for f in friends:
        cnt_index[f] = 0
    cnt_gift = collections.Counter(gifts)
    for k, v in cnt_gift.items():
        giver = k.split()[0]
        gived = k.split()[1]
        cnt_index[giver] += v
        cnt_index[gived] -= v
    for comp in list(itertools.combinations(friends, 2)):
        s = f'{comp[0]} {comp[1]}'
        r_s = f'{comp[1]} {comp[0]}'
        if s in cnt_gift.keys() and r_s in cnt_gift.keys():
            if cnt_gift[s] > cnt_gift[r_s]:
                cnt_friend[comp[0]] += 1
            elif cnt_gift[s] < cnt_gift[r_s]:
                cnt_friend[comp[1]] += 1
            else:
                if cnt_index[comp[0]] > cnt_index[comp[1]]:
                    cnt_friend[comp[0]] += 1
                elif cnt_index[comp[0]] < cnt_index[comp[1]]:
                    cnt_friend[comp[1]] += 1
        elif s in cnt_gift.keys():
            cnt_friend[comp[0]] += 1
        elif r_s in cnt_gift.keys():
            cnt_friend[comp[1]] += 1
        else:
            if cnt_index[comp[0]] > cnt_index[comp[1]]:
                cnt_friend[comp[0]] += 1
            elif cnt_index[comp[0]] < cnt_index[comp[1]]:
                cnt_friend[comp[1]] += 1
    if cnt_friend.values():
        return max(cnt_friend.values())
    else:
        return 0


if __name__ == "__main__":
    # print(solution(["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]))
    # print(solution(["joy", "brad", "alessandro", "conan", "david"], ["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]))
    print(solution(["a", "b", "c"], ["a b", "b a", "c a", "a c", "a c", "c a"]))
