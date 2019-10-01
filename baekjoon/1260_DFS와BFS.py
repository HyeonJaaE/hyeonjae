
SIZE = 1001
list = [[0 for col in range(SIZE)] for row in range(SIZE)]
dfs = [0 for col in range(SIZE)]
bfs = [0 for col in range(SIZE)]
d = []
b = []

def DFS(idx):
    if dfs[idx] == 1:
        return
    else:
        d.append(idx)
        dfs[idx] = 1

        for i in range(SIZE):
            if list[idx][i] == 1:
                DFS(i)

def BFS(idx):
    q = []
    q.append(idx)
    bfs[idx] = 1

    while len(q) > 0:
        b.append(q[0])

        for i in range(SIZE):
            if list[q[0]][i] == 1 and bfs[i] != 1:
                q.append(i)
                bfs[i] = 1

        del q[0]



N, M, V = map(int, input().split())

for i in range(0, M):
    tmp, ttmp = map(int, input().split())
    list[tmp][ttmp] = 1
    list[ttmp][tmp] = 1

DFS(V)
BFS(V)

for i in d:
    print(i, end=' ')
print()

for i in b:
    print(i, end=' ')
print()
