import heapq
def solution(scoville, K):
    cnt = 0
    heapq.heapify(scoville)
    while scoville[0] < K and len(scoville) >= 2:
        print(f'scoville: {scoville[0]}')
        first_poped = heapq.heappop(scoville)
        second_poped = heapq.heappop(scoville)
        accum = first_poped + second_poped * 2
        print(f'accum: {accum}')
        heapq.heappush(scoville, accum)
        cnt += 1
    if scoville[0] < K:
        return -1
    return cnt

if __name__ == "__main__":
    print(solution([1, 2, 3, 9, 10, 12], 7))