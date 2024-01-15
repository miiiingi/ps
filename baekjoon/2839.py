n = int(input())
answer = 0
while n != 0:
    if n % 5 == 0:
        answer += n // 5
        print(answer)
        break
    elif n % 3 == 0:
        if n // 5 >= 1:
            answer += 1
            n -= 5
        else:
            answer += n // 3
            print(answer)
            break
# else:
#     if n % 3 == 0:
#         answer += n // 3
#         print(answer)
#         break
