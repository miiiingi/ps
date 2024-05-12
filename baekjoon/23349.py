# 문제 조건 잘 보자! 
import sys
N = int(sys.stdin.readline())
name_table = dict()
flight_table = dict()
extracted_table = dict()
max_number = 0
for _ in range(N):
    name, flight, time_s, time_e = sys.stdin.readline().split()
    if name not in name_table:
        name_table[name] = [flight, [int(time_s), int(time_e)]]
        if flight_table.get(flight) == None:
            flight_table[flight] = [0 for _ in range(50001)]
        # 어떻게 겹치는 것을 표현할 것 인가? -> 시간들을 돌면서 하나씩 더해줌
        for num in range(name_table[name][1][0], name_table[name][1][1]):
            flight_table[flight][num] += 1
for k, v in flight_table.items():
    if max(v) >= max_number:
        max_number = max(v)
        extracted_table[k] = v
# 일단 이전 시간의 최댓값보다 많은 비행기들을 모두 선택한 후, 배열의 최댓값으로 정렬하고, 비행기 이름대로 정렬함
# 같은 이름일 때 뒤에 시간에 일어나더라도 많은 시간대를 어떻게 선택할 것인가 ?  -> 최댓값으로 선택해주니 상관 없음
k = sorted(extracted_table.items(), key = lambda x: (-max(x[1]), x[0]))[0][0]
# 가장 빠른 시간대를 출력해주어야함
for ind in range(50001):
    if extracted_table[k][ind] == max_number:
        time_s = ind
        break
for ind in range(time_s, 50001):
    if extracted_table[k][ind] != max_number:
        time_e = ind
        break
result = [k, time_s, time_e]
print(' '.join(map(str, result)))