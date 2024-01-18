def sieve_of_eratosthenes(n):
    if n < 1:
        return []
    # 2부터 n까지의 숫자를 포함하는 리스트 생성
    primes = [True] * (n + 1)
    primes[0], primes[1] = False, False  # 0과 1은 소수가 아님

    # 에라토스테네스의 체 알고리즘 적용
    for i in range(2, int(n**0.5) + 1):
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False
    # 소수만을 담은 리스트 생성
    result = [num for num in range(2, n + 1) if primes[num]]
    return result

M, N = map(int, input().split())
for num in sorted(list(set(sieve_of_eratosthenes(N)) - set(sieve_of_eratosthenes(M-1)))):
    print(num)
