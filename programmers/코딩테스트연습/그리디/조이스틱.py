def solution(name):
    answer = 0
    length = len(name)
    for i in range(len(name)):
        if name[i] != "A":
            diff = min(ord(name[i]) - ord("A"), ord("Z") - ord(name[i]) + 1)
        else:
            next_i = i
            while name[next_i] == "A":
                next_i += 1
            forward = next_i - i
            backward = length - next_i
            i = min(forward, backward)
            diff = min(ord(name[i]) - ord("A"), ord("Z") - ord(name[i]) + 1)

        answer += diff
        print(f'alphabet: {name[i]}, cnt: {diff}')
    answer += len(name) - 1
    return answer

def solution(name):
    answer = 0
    length = len(name)
    
    # 1. 초기값 세팅: 시나리오 1 (무지성 직진) 거리를 디폴트 최솟값으로 둡니다.
    min_move = length - 1 
    
    for i in range(length):
        # [미션 1] 알파벳 조작 횟수 (상하) - 작성하신 완벽한 코드 그대로!
        answer += min(ord(name[i]) - ord("A"), ord("Z") - ord(name[i]) + 1)
        
        # [미션 2] 커서 이동 횟수 (좌우)의 최솟값 갱신
        # 2-1. 내 위치(i) 바로 다음부터 연속된 'A'가 끝나는 지점(next_i) 찾기
        next_i = i + 1
        
        # IndexError 방지 조건 추가!
        while next_i < length and name[next_i] == 'A':
            next_i += 1
            
        # 2-2. 3가지 동선 중 가장 짧은 거리를 계산하여 min_move를 계속 갱신
        # 기존 최솟값, 
        # 시나리오 2 (찍고 턴: i*2 + length - next_i), 
        # 시나리오 3 (역주행 턴: i + (length - next_i)*2) 
        min_move = min(min_move, 
                       (i * 2) + (length - next_i), 
                       i + (length - next_i) * 2)
                       
    # 상하 조작 횟수 + 가장 짧은 좌우 이동 횟수
    return answer + min_move

if __name__ == "__main__":
    print(solution("JEROEN"))