#설탕배달
# 3x + 5y = N
N = int(input())
cnt = 0

for y in range (0, 5001):
    tmp = N - 5 * y
    if tmp < 0:
        break

    if tmp % 3 == 0:
        x = int(tmp / 3)
        cnt = x + y

if cnt == 0:
    print(-1)
else:
    print(cnt)
