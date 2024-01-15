import itertools
def is_prime(number):
    if number < 2:
        return False  # 2보다 작은 수는 소수가 아님

    for i in range(2, int(number**0.5) + 1):
        if number % i == 0:
            return False  # 나누어 떨어지는 수가 있으면 소수가 아님
    return True


def solution(numbers):
    '''
    1. 숫자 배열 만들기
    2. 소수 판별
    '''
    answer = []
    for i in range(1, len(numbers) + 1):
        numbers_list = list(itertools.permutations(numbers, i))
        for number in numbers_list:
            number = int("".join(number))
            if is_prime(number):
                answer.append(number)
    return len(set(answer))


if __name__ == "__main__":
    # print(solution("17"))
    # print(solution("011"))
    print(solution("123"))
