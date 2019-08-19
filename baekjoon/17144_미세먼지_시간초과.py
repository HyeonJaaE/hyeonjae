R,C,T = map(int, input().split())

li = []

for i in range(0, R):
    li.append(list(map(int, input().split())))

'''print("=" * 35)
for i in range(0, R):
    print(li[i])
print("=" * 35)'''
while T > 0:
    T -= 1
    _li = [[0 for i in range(0, C)] for i in range(0, R)] #확산된 미세먼지 저장
    for r in range(0, R):
        for c in range(0, C):
            if li[r][c] != 0 and li[r][c] != -1:
                tmp = li[r][c]

                # 아래 위 왼쪽 오른쪽 확인
                if r-1 in range(0, R):
                    if li[r-1][c] != -1: #공기 청정기
                        _li[r-1][c] += tmp // 5
                        li[r][c] -= tmp // 5
                if r+1 in range(0, R):
                    if li[r+1][c] != -1:
                        _li[r+1][c] += tmp // 5
                        li[r][c] -= tmp // 5
                if c-1 in range(0, C):
                    if li[r][c-1] != -1:
                        _li[r][c-1] += tmp // 5
                        li[r][c] -= tmp // 5
                if c+1 in range(0, C):
                    if li[r][c+1] != -1:
                        _li[r][c+1] += tmp // 5
                        li[r][c] -= tmp // 5

    #확산 후 남은 미세먼지 계산
    sum = 0
    for r in range(0, R):
        for c in range(0, C):
            if li[r][c] != -1:
                li[r][c] += _li[r][c]
                sum += li[r][c]

    '''for i in range(0, R):
        print(li[i])'''

    #공기청정기 위치 계산 (가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다)
    for i in range(0, R):
        if li[i][0] == -1:
            air = i
            _air = i+1

            #여과되는 부분
            #좌측
            sum -= li[air-1][0]
            sum -= li[_air+1][0]
            for j in range(air-1, 0, -1):
                li[j][0] = li[j-1][0]
            for j in range(_air+1, R-1):
                li[j][0] = li[j+1][0]

            #상, 하단
            li[0][0:C-1] = li[0][1:C]
            li[R-1][0:C-1] = li[R-1][1:C]

            #우측
            for j in range(0, air):
                li[j][C-1] = li[j+1][C-1]
            for j in range(R-1, _air, -1):
                li[j][C-1] = li[j-1][C-1]

            #중앙
            li[air][2:C] = li[air][1:C-1]
            li[air][1] = 0
            li[_air][2:C] = li[_air][1:C-1]
            li[_air][1] = 0

            #print("=" * 35)
            #반복 불필요
            break



    '''for i in range(0, R):
        print(li[i])'''

print(sum)
