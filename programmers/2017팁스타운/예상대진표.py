import math


def solution(n, a, b):
    # 같은 그룹인지 확인 -> 같은 그룹이 아니면 다음 라운드로 / 같은 그룹이면 종료
    round = 1
    while (n >= 2):
        if math.ceil(a/2) == math.ceil(b/2):
            return round
        else:
            n = n // 2
            round += 1
            a = math.ceil(a/2)
            b = math.ceil(b/2)
    return round


if __name__ == '__main__':
    print(solution(16, 12, 14))
