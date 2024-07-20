import collections
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        answer_dict = collections.defaultdict(list)
        for i in range(len(s)):
            queue = f"{s[i]}"
            for j in range(i+1, len(s)):
                if s[j] in queue:
                    answer_dict[len(queue)].append(queue)
                    break
                else:
                    queue += s[j]
            else:
                answer_dict[len(queue)].append(queue)
        else:
            answer_dict[len(queue)].append(queue)
        return sorted(answer_dict.keys(), reverse = True)[0]