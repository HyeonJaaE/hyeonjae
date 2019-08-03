T = int(input())

for i in range(0,T):

    # N * N 크기의 밭 ( N 은 홀수)
    N = int(input())

    li = []
    ans = 0
    r = 1

    for j in range(0, N):
        tmp = input()
        mid = N//2

        if(j <= mid):
            li.append(tmp[mid-j:mid+j+1])
        else:
            li.append(tmp[mid-mid+r:mid+mid+1-r])
            r += 1


    for j in range(0, N):
        for k in li[j]:
            ans += int(k)

    print("#", end='')
    print(i+1, end=' ')
    print(ans)
