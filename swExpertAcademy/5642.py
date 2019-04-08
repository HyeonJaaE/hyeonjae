T = int(input())
for i in range(0,T):
    N = int(input())
    a = list(map(int, input().split()))
    print("#", end='')
    print(i+1, end=' ')

    max = a[0]

    for j in range(0, N):
        tmp = a[j]
        if max < tmp :
            max =tmp

        for t in range(j, N):
            if t+1 < N :
                tmp += a[t+1]
            if max < tmp :
                max = tmp
    print(max)
