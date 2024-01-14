def getSeq(k):
    result = [[0, k]]
    while k > 1:
        if k % 2 == 0:
            k = k / 2
        else:
            k = 3 * k + 1
        result.append([result[-1][0] + 1, k])
    else:
        return result
def calTrapezoidal(seq, a, b):
    cnt = 0.0
    for num in range(a, b):
        cnt += (seq[num][1] + seq[num + 1][1]) / 2
    return cnt
def solution(k, ranges):
    '''
    1. 우박수열을 구하기
    2. 구간 계산해서 정적분 계산하기
    3. 예외처리
    '''
    seq = getSeq(k)
    n = len(seq)
    answer = []
    for r in ranges:
        a = r[0]
        b = (n  - 1) + r[1]
        if a > b:
            answer.append(-1.0)
            continue
        answer.append(calTrapezoidal(seq, a, b))
    return answer

if __name__ == "__main__":
    print(solution(5, [[0,0],[0,-1],[2,-3],[3,-3]]))