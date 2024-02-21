def solution(s):
    splitted = s.split(' ')
    answer = []
    for word in splitted:
        new_word=""
        for ind, w in enumerate(word):
            if ind == 0 and w.islower():
                new_word+=w.upper()
            elif ind == 0 and w.isupper():
                new_word+=w
            elif ind != 0 and w.isupper():
                new_word+=w.lower()
            else:
                new_word+=w
        answer.append(new_word)
    return ' '.join(answer)

if __name__ == "__main__":
    # print(solution("3people unFollowed me"))
    print(solution("for the last week"))