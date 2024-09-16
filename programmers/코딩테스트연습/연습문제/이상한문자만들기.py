def solution(s):
    answer = ''
    ind = 0
    for splitted in s:
        if splitted == ' ':
            answer += splitted
            ind = 0
        elif ind % 2 == 0:
            answer += splitted.upper()
            ind += 1
        else:
            answer += splitted.lower()
            ind += 1
    return answer

if __name__ == "__main__":
    print(solution("try hello world"))