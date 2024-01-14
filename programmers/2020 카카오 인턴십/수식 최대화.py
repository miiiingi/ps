def solution(expression):
    '''
    1. 곱하기 중에서 가장 큰 수의 부호를 파악한다.
    2. 가장 큰 곱하기의 부호가 플러스라면, 뺄셈을 먼저 수행하고 덧셈을 수행한다.
    3. 가장 큰 곱하기의 부호가 마이너스라면, 덧셈을 먼저 수행하고 뺄셈을 수행한다.
    '''
    answer = 0
    return answer

if __name__ == "__main__":
    print(solution("100-200*300-500+20"))