def solution(s):
    sorted_s = sorted(s.split(' '), key=lambda x: int(x))
    return f'{sorted_s[0]} {sorted_s[-1]}'


if __name__ == "__main__":
    print(solution("-1 -1"))
