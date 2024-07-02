class Solution:
    def longestPalindrome(self, s: str) -> str:
        p_list = []
        for i in range(1, len(s) + 1):
            for j in range(len(s) + 1 - i):
                t = s[j: j+i]
                if t == t[::-1]:
                    p_list.append(t)
        return max(p_list, key = len)
S = Solution()
print(S.longestPalindrome("cbbd"))
        