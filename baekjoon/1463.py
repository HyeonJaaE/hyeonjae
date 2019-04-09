X = int(input())
dp = [1000000 for i in range(1000001)]
dp[1] = 0

for i in range(2,X+1):
    if i % 3 == 0:
        if dp[i] > dp[int(i/3)] + 1:
            dp[i] = dp[int(i/3)] + 1

    if i % 2 == 0:
        if dp[i] > dp[int(i/2)] + 1:
            dp[i] = dp[int(i/2)] + 1

    if dp[i] > dp[i-1] + 1:
        dp[i] = dp[i-1] + 1

print(dp[X])
