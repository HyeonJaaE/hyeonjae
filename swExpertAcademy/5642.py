T = int(input())
for i in range(0,T):
    N = int(input())
    li = list(map(int, input().split()))
    dp_li = [0]
    dp_li_tmp = [0]

    print("#", end='')
    print(i+1, end=' ')

    max = li[0]

    for j in range(0, N):
        dp_li_tmp[0] = li[j]
        if dp_li_tmp[0] > max:
            max = dp_li_tmp[0]

        for k in range(1, j+1):
            dp_li_tmp.append = dp_li_tmp[0] + dp_li[k-1]
            if dp_li_tmp[k] > max:
                max = dp_li_tmp[k]

        dp_li = dp_li_tmp

    print(max)
