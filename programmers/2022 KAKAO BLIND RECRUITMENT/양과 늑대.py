import collections
def makeGraph(edges):
    graph = collections.defaultdict(list)
    for e in edges:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    return graph
def solution(info, edges):
    graph = makeGraph(edges)
    answer = 0
    return answer

if __name__ == "__main__":
    print(solution([0,0,1,1,1,0,1,0,1,0,1,1], [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))