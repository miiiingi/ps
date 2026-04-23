import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
MOVE = [[-1, 0], [1, 0], [0, -1], [0, 1]]
student = dict()
for _ in range(N * N):
    temp = deque(map(int, input().split()))
    poped = temp.popleft()
    student[poped] = temp
room = [[0 for _ in range(N)] for _ in range(N)]
registered = []
for k, v in student.items():
    seat_candidate = []
    for i in range(N):
        for j in range(N):
            if room[i][j] != 0:
                continue
            liked_friend = 0
            blank_seat = 0
            for m in MOVE:
                x, y = m
                nx, ny = i + x, j + y
                if nx < 0 or nx >= N or ny < 0 or ny >= N:
                    continue
                if room[nx][ny] == 0:
                    blank_seat += 1
                if room[nx][ny] in v:
                    liked_friend += 1
            seat_candidate.append([liked_friend, blank_seat, i, j])
    seat_candidate.sort(key=lambda x: (-x[0], -x[1], x[2], x[3]))
    best_candidate = seat_candidate[0]
    room[best_candidate[2]][best_candidate[3]] = k

room_satisfaction = 0
for i in range(N):
    for j in range(N):
        student_satisfaction = 0
        for m in MOVE:
            x, y = m
            nx, ny = i + x, j + y
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if room[nx][ny] in student[room[i][j]]:
                student_satisfaction += 1
        if student_satisfaction == 0:
            room_satisfaction += 0
        elif student_satisfaction == 1:
            room_satisfaction += 1
        elif student_satisfaction == 2:
            room_satisfaction += 10
        elif student_satisfaction == 3:
            room_satisfaction += 100
        elif student_satisfaction == 4:
            room_satisfaction += 1000
print(room_satisfaction)
