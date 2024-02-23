def solution(s):
    cnt_zero = 0
    cnt_phase = 0
    while(not (s.count('0') == 0 and len(s) == 1)):
        cnt_phase += 1
        cnt_zero += s.count('0')
        s = s.replace('0', '')
        length = len(s)
        s = "{0:b}".format(length)
    return [cnt_phase, cnt_zero] 

if __name__ == "__main__":
    print(solution("110010101001"))