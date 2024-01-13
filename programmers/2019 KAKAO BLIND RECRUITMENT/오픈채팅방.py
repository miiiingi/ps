import collections
def solution(record):
    answer = []
    result = []
    character_dict = collections.defaultdict(list)
    for r in record:
        r = r.split(' ')
        if r[0] == "Enter":
            character_dict[r[1]].append(r[2])
            answer.append(f"{r[1]}님이 들어왔습니다.")
        elif r[0] == "Change":
            character_dict[r[1]].append(r[2])
        elif r[0] == "Leave":
            answer.append(f"{r[1]}님이 나갔습니다.")
    for a in answer:
        a = a.split('님이')
        a[0] = a[0].replace(a[0], character_dict[a[0]][-1])
        result.append('님이'.join(a))
    return result 

if __name__ == "__main__":
    print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]))