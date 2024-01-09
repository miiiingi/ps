import math
def is_point_inside_sector(x, y, r, d, t):
    t_distance = math.sqrt(t[0]**2 + t[1]**2)
    r_rad = math.atan2(y, x)
    r_deg = math.degrees(r_rad)
    t_rad = math.atan2(t[1], t[0])
    t_deg = math.degrees(t_rad)
    return r >= t_distance and r_deg-d <= t_deg <= r_deg+d
def solution(x, y, r, d, target):
    answer = 0
    for t in target:
        if is_point_inside_sector(x, y, r, d, t):
            print(t)
            answer += 1
    answer = 0
    return answer

if __name__ == "__main__":
    print(solution(-1, 2, 2, 60, [[0, 1], [-1, 1], [1, 0], [-2, 2]]))
