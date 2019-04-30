T = int(input())
for i in range(0,T):
    N = int(input())
    li = list(map(int, input().split()))
    dp = [1000000 for i in range(1000001)]

    print("#", end='')
    print(i+1, end=' ')

    dp[0] = li[0]
    max = dp[0]

    for j in range(1, N):
        if dp[j-1] < 0:
            dp[j] = li[j]
            if dp[j] > max:
                max = dp[j]
        else:
            dp[j] = dp[j-1] + li[j]
            if dp[j] > max:
                max = dp[j]
    print(max)
