from typing import List
from collections import defaultdict
def solution(participant: List , completion: List):
    p_dict = defaultdict(int)
    for p in participant:
        p_dict[p] += 1
    for c in completion:
        p_dict[c] -= 1
    for ind, v in enumerate(p_dict.values()):
        if v != 0:
            return list(p_dict.keys())[ind]

if __name__ == "__main__":
    solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"])