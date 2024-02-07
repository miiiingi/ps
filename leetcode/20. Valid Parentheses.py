class Solution:
    def __init__(self) -> None:
        self.stack = []

    def isValid(self, s: str) -> bool:
        for i in range(len(s)):
            if s[i] == "(" or s[i] == "{" or s[i] == "[":
                self.stack.append(s[i])
            elif s[i] == ")":
                if self.stack and self.stack[-1] == "(":
                    self.stack.pop()
                else:
                    return False
            elif s[i] == "}":
                if self.stack and self.stack[-1] == "{":
                    self.stack.pop()
                else:
                    return False
            elif s[i] == "]":
                if self.stack and self.stack[-1] == "[":
                    self.stack.pop()
                else:
                    return False
        if len(self.stack) == 0:
            return True
        else:
            return False


if __name__ == "__main__":
    s = "()"
    obj = Solution()
    print(obj.isValid(s))
