import sys
string = sys.stdin.readline().strip()
accum_plus = 0
accum_minus = 0
for i, num in enumerate(string.split('-')):
    if i == 0:
        list_plus = list(map(int, num.split('+')))
        accum_plus += sum(list_plus)
    else:
        list_minus = list(map(int, num.split('+')))
        accum_minus += sum(list_minus)
print(accum_plus - accum_minus)
