import itertools
def solution(nums):
    max_num = 0
    for i in itertools.combinations(nums, len(nums) // 2):
        if len(set(i)) >= max_num:
            max_num = len(set(i))
    return max_num 

if __name__ == "__main__":
    solution([3,3,3,2,2,4])