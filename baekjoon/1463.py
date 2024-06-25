# 목표가 되는 수까지 모든 숫자를 계산해서 저장해놓은 후, 이를 바탕으로 목표 숫자를 계산
# 여기서 중요한 것은, 목표 숫자를 분해하는 것이 이전 숫자들을 이용하여 할 수 있다는 것
import sys
num = int(sys.stdin.readline())
# DP 테이블 초기화
DP = [0] * 1000001

# 다이나믹 프로그래밍 진행(bottom-up)
for i in range(2, num+1):
    # 현재의 수에서 1을 빼는 경우
    DP[i] = DP[i-1] + 1
    # 현재의 수가 2로 나누어 떨어지는 경우
    if i%2 == 0:
        DP[i] = min(DP[i], DP[i//2] + 1)
    # 현재의 수가 3으로 나누어 떨어지는 경우
    if i%3 == 0:
        DP[i] = min(DP[i], DP[i//3] + 1)

# 결과 출력
print(DP[num])