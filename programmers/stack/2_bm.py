import collections
def solution(progresses, speeds):
    answer = []
    progresses = collections.deque(progresses)
    speeds = collections.deque(speeds)
    while progresses:
        deploy_num = 0
        p = progresses.popleft()
        s = speeds.popleft()
        remained_day = (100 - p) // s
        deploy_num += 1
        while progresses and (remained_day * speeds[0]) + progresses[0] >= 100:
            progresses.popleft()
            speeds.popleft()
            deploy_num += 1
        answer.append(deploy_num)
    return answer
if __name__ == "__main__":
    solution([95, 90, 99, 99, 80, 99], 	[1, 1, 1, 1, 2, 1])