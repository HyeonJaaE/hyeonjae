T = 10

for i in range(0,T):

    N = int(input())
    li = list(map(int, input().split()))
    ans = 0

    print("#", end='')
    print(i+1, end=' ')

    for j in range(0, N):
        if(li[j] == 0):
            continue

        if(li[j - 1] >= li[j] or li[j - 2] >= li[j]):
            continue

        if(li[j] <= li[j + 1] or li[j] <= li[j + 2]):
            continue

        tmp = li[j - 2]
        if(li[j - 1] > tmp):
            tmp = li[j - 1]
        if(li[j + 1] > tmp):
            tmp = li[j + 1]
        if(li[j + 2] > tmp):
            tmp = li[j + 2]

        ans = ans + (li[j] - tmp)

    print(ans)
