from datetime import datetime, timedelta
def solution(p, n):
    answer = ""
    t = p.split(' ')
    time = datetime.strptime(t[1], "%H:%M:%S") 
    if t[0] == "PM":
        if time.hour != 12:
            time = time + timedelta(hours=12)
    elif t[0] == "AM" and time.hour == 12:
        time = time - timedelta(hours=12)
    
    time = time + timedelta(seconds=n)
    return time.strftime("%H:%M:%S")

if __name__ == "__main__":
    # print(solution("PM 01:00:00", 200000))
    print(solution("AM 12:11:00", 10))