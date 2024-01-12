def solution(s):
    answer = []
    s = s[2:-2].split('},{')
    s = sorted(s, key=lambda x: len(x))
    for i in s:
        if not answer:
            answer.append(int(i))
        else:
            for a in answer:
                i = i.replace(str(a), '')
            answer.append(int(i.replace(',', '')))
    return answer

if __name__ == "__main__":
    # print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
    print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
