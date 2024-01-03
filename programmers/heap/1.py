from heapq import heapify, heappop, heappush
def solution(scoville, K):
    answer = 0
    heapify(scoville)
    while any(s < K for s in scoville):
        if len(scoville) == 1:
            return -1
        first_elem = heappop(scoville)
        second_elem = heappop(scoville)
        mixed = first_elem + second_elem * 2
        heappush(scoville, mixed)
        answer += 1
    return answer

if __name__ == "__main__":
    print(solution([1, 2, 3, 9, 10, 12], 7))