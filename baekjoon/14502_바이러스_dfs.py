import copy
num = 0
max = 0
answer = []
li = ""
N, M = map(int, input().split())
for i in range(0, N):
    li += input() + " "

li = list(li.split())

'''print(li)
print("=" * 35)'''

def bfs(li, r, c):
    if r-1 in range(0, N):
        if li[r-1][c] == '0':
            li[r-1][c] = '2'
            bfs(li, r-1, c)
    if r+1 in range(0, N):
        if li[r+1][c] == '0':
            li[r+1][c] = '2'
            bfs(li, r+1, c)
    if c-1 in range(0, M):
        if li[r][c-1] == '0':
            li[r][c-1] = '2'
            bfs(li, r, c-1)
    if c+1 in range(0, M):
        if li[r][c+1] == '0':
            li[r][c+1] = '2'
            bfs(li, r, c+1)

def dfs(li, i, d):
    tmpli = copy.deepcopy(li)
    tmpli[i] = '1'

    if d == 3:
        ttmpli = []
        for j in range(1, N+1):
            ttmpli.append(tmpli[(j-1)*M:M*j])

        #벽 세우고 바이러스 확산
        for r in range(0, N):
            for c in range(0, M):
                if ttmpli[r][c] == '2':
                    bfs(ttmpli, r, c)

        cnt = 0
        global answer, max

        # 바이러스가 퍼지지 않은 지역 수 확인
        for r in range(0, N):
            for c in range(0, M):
                if ttmpli[r][c] == '0':
                    cnt += 1

        if cnt >= max:
            max = cnt
        return

    for _i in range(i, N * M):
            if tmpli[_i] == '0':
                dfs(tmpli, _i, d+1)

for i in range(0, N * M):
    if li[i] == '0':
        dfs(li, i, 1)

print(max)
#print(answer)
