import collections
def solution(arr):
    answer = []
    for elem in collections.deque(arr):
        if answer and answer[-1] == elem:
            continue
        else:
            answer.append(elem)
    return answer

if __name__ == "__main__":
    solution([1,1,3,3,0,1,1])