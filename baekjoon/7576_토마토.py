## 2 <= R, C <= 1000
C, R = map(int, input().split()) 

li = []
visit = [[0 for c in range(C)] for r in range(R)]
q = []

for i in range(R):
    tmp = list(map(int, input().split()))
    li.append(tmp)

sum = 0
_q = []
##토마토가 있는 칸 q에 등록
for i in range(R):
    for j in range(C):
        if li[i][j] == 1:
            tmp = [i, j]
            visit[i][j] == 1
            _q.append(tmp)
            sum += 1    
        
        if li[i][j] == -1:
            sum += 1

q.append(_q)

##저장될 때부터 모두 익어있는 상태일 때
if sum == R * C:
    print(0)
else:
    cnt = 0
    while len(q) > 0:
        cnt += 1
        tmp = []
        for tomatoIdx in q[0]:
            row = tomatoIdx[0]
            col = tomatoIdx[1]

            if row - 1 >= 0:
                if li[row-1][col] == 0 and visit[row-1][col] == 0:
                    visit[row-1][col] = 1
                    li[row-1][col] = 1
                    sum += 1
                    tmp.append([row-1, col])

            if row + 1 < R:
                if li[row+1][col] == 0 and visit[row+1][col] == 0:
                    visit[row+1][col] = 1
                    li[row+1][col] = 1
                    sum += 1
                    tmp.append([row+1, col])

            if col - 1 >= 0:
                if li[row][col-1] == 0 and visit[row][col-1] == 0:
                    visit[row][col-1] = 1
                    li[row][col-1] = 1
                    sum += 1
                    tmp.append([row, col-1])

            if col + 1 < C:
                if li[row][col+1] == 0 and visit[row][col+1] == 0:
                    visit[row][col+1] = 1
                    li[row][col+1] = 1
                    sum += 1
                    tmp.append([row, col+1])

        if len(tmp) > 0:
            q.append(tmp)
        del q[0]
        
    if sum == R * C:
        print(cnt-1)
    else:
        print(-1)