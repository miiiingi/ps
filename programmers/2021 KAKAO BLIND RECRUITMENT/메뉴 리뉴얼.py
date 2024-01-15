import itertools
import collections
def solution(orders, course):
    answer = []
    while course:
        order = []
        c = course.pop()
        for o in orders:
            if len(o) < c:
                continue
            order.extend(itertools.combinations(sorted(o), c))
        if collections.Counter(order).most_common():
            maxValue = collections.Counter(order).most_common()[0][1]
            if maxValue < 2:
                continue
            for k, v in collections.Counter(order).most_common():
                if v == maxValue:
                    answer.append("".join(list(k)))
    return sorted(answer)


if __name__ == "__main__":
    # print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2, 3, 4]))
    # print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2, 3, 5]))
    print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
