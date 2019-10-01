SIZE = 25
group = 0
cnt = []

list = [[0 for col in range(SIZE)] for row in range(SIZE)]

N = int(input())

for i in range(N):
    s = input()
    for j in range(N):
        list[i][j] = int(s[j])

def DFS(i, j):

    if list[i][j] == 1:
        list[i][j] = 0
        global tmp
        tmp += 1
    else:
        return

    if (i - 1) >= 0:
        DFS(i-1, j)
    if (i + 1) < SIZE:
        DFS(i+1, j)
    if (j - 1) >= 0:
        DFS(i, j-1)
    if (j + 1) < SIZE:
        DFS(i, j+1)



for i in range(N):
    for j in range(N):
        if list[i][j] == 1:
            group += 1
            tmp = 0
            DFS(i, j)
            cnt.append(tmp)


print(group)
cnt.sort()
for i in cnt:
    print(i)
