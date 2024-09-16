def solution(n, lost, reserve):
    reserve.sort()
    lost.sort()
    while reserve and lost:
        for r in reserve:
            if r in lost:
                lost.remove(r)
                reserve.remove(r)
                break
        else:
            r = reserve.pop(0)
            for l in lost:
                if r - 1 == l:
                    lost.remove(l)
                    break
                elif r + 1 == l:
                    lost.remove(l)
                    break
    else:
        return n - len(lost)
   
if __name__ == "__main__":
    # print(solution(6, [3,4,5], [3,4,6]))
    # print(solution(4, [2,3], [3,4]))
    # print(solution(4, [1, 4], [2, 3] ))
    # print(solution(4, [2], [1, 2] ))
    # print(solution(5, [3, 4], [4, 3]))
    print(solution(5, [4,5], [3, 4]))

