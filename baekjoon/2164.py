import sys
import collections
number = int(sys.stdin.readline())
num_list = collections.deque([num for num in range(1, number + 1)])
while(len(num_list) > 1):
    num_list.popleft()
    num_list.rotate(-1)
print(num_list[0])