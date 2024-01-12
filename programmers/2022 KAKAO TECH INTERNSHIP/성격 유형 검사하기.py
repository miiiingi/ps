def solution(survey, choices):
    answer = {"RT": 0, "CF": 0, "JM": 0, "AN": 0}
    result = ''
    for s, c in zip(survey, choices):
        if s not in answer.keys():
            s = s[::-1]
            answer[s] -= c - 4
        else:
            answer[s] += c - 4
    for k in answer.keys():
        if answer[k] > 0:
            result += k[1]
        else:
            result += k[0]
    return result


if __name__ == "__main__":
    print(solution(["AN", "CF", "MJ", "RT", "NA"], [5, 3, 2, 7, 5]))
    # print(solution(["RT", "RT", "RT"], [7, 2, 4]))
    # print(solution(["RT", "RT", "RT"], [7, 5, 2]))
    #  ["RT", "RT", "RT"], [7, 2, 4] "TCJA"
    #  ["RT", "RT", "RT"], [7, 5, 2] "TCJA"
