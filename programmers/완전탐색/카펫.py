def find_divisor_pairs(n):
    pairs = []  # 약수 쌍을 저장할 리스트

    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            divisor1 = i
            divisor2 = n // i

            if divisor1 <= divisor2:
                pairs.append((divisor1, divisor2))  # 약수 쌍 추가

    return pairs


def solution(brown, yellow):
    # 1. yellow 약수의 갯수 구하기
    # 2. brown이 감당할 수 있는 yellow 약수 갯수 선택하기
    for d in find_divisor_pairs(yellow):
        heigth = d[0]
        width = d[1]
        if (width * 2 + heigth * 2 + 4 == brown):
            # print(f'brwon : {brown}, width: {width}, height: {heigth}')
            return [width + 2, heigth + 2]


if __name__ == "__main__":
    print(solution(24, 24))
