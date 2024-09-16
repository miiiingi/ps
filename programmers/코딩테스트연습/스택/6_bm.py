import collections
def solution(prices):
    result = []
    prices = collections.deque(prices)
    while prices:
        price = prices.popleft()
        answer = 0
        for comp in prices:
            answer += 1
            if price > comp:
                break
        result.append(answer)
    return result

if __name__ == "__main__":
    # print(solution([1, 2, 3, 2, 3]))
    print(solution([4,5,1,2,6,1,1]))