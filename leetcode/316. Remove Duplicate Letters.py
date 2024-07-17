import collections
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        # 뒤의 문자열에 나타나는지 검증 -> 나타나는데, stack에 없으면 추가, 있으면 버림
        # 1. 뒤에 해당 문자가 나타나는 지 검증
        # 2. 새로운 문자가 stack의 마지막 원소보다 작은 지 검증. 작다면, stack pop, 크다면 stack에 추가 
        # 3. 유일한 지 검증
        counter, seen, stack = collections.Counter(s), set(), []
        for c in s:
            counter[c] -= 1
            if c in seen:
                continue
            while stack and counter[stack[-1]] >= 1 and stack[-1] > c:
                seen.discard(stack.pop())
            stack.append(c)
            seen.add(c)
        return ''.join(stack)
print(Solution().removeDuplicateLetters("cbacdcbc"))
        