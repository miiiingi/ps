import sys
string = sys.stdin.readline().strip()
str_list = [-1 for _ in range(26)]
visited = []
for i, char in enumerate(string):
    if char in visited:
        continue
    visited.append(char)
    str_list[ord(char) - 97] = i
print(' '.join([str(i) for i in str_list]))