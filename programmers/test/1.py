import collections
def solution(movie):
    answer = []
    movie = sorted(collections.Counter(movie).items(), key=lambda x: (-x[1], x[0]))
    for m in movie:
        answer.append(m[0])
    return answer 

if __name__ == "__main__":
    print(solution(["spy", "ray", "spy", "room", "once", "ray", "spy", "once"]))

