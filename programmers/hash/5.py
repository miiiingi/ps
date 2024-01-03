import collections
def solution(genres, plays):
    answer = []
    play_dict = collections.defaultdict(list)
    for genre, play, ind in zip(genres, plays, range(len(genres))):
        play_dict[genre].append([ind, play])
    for record in sorted(play_dict.items(), key=lambda x: sum(map(lambda y: y[1], play_dict[x[0]])), reverse=True):
        for v in sorted(play_dict[record[0]], key=lambda x: (x[1], -x[0]), reverse=True)[:2]:
            answer.append(v[0])
    return answer

if __name__ == "__main__":
    # result = solution(["classic", "pop", "pop", "classic", "jazz", "jazz", "opera"], [400, 300, 300, 150, 2000, 3000, 2500])
    result = solution(["classic", "classic", "classic", "classic", "pop"], [50, 60, 100, 30, 8000])
    print(result)