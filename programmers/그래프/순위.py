import collections
def makeGraph(results):
    answer = collections.defaultdict(list)
    for r in results:
        answer[r[0]].append(r[1])
        answer[r[1]].append(r[0])
    return answer
def solution(n, results):
    answer = 0
    graph = makeGraph(results)
    return answer

if __name__ == "__main__":
    print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))