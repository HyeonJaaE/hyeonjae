import sys
sys.setrecursionlimit(10**6)

N = 0
board =[]
visit = []

def isBoard(r, c):
    if r >= 0 and r < N and c >= 0 and c < N:
        return 1
    else:
        return -1

def leftTurnOriginalFivot(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]

    if s == 0:
        if isBoard(r-1,c) == 1 and isBoard(r-1, c+1) == 1:
            if board[r-1][c] == 0 and board[r-1][c+1] == 0:
                return [r-1, c, 1]
    ## l<
    ## --
    
    if s == 1:
        if isBoard(r,c+1) == 1 and isBoard(r+1 , c+1) == 1:
            if board[r][c+1] == 0 and board[r+1][c+1] == 0:
                return [r, c, 0]
    
    ## l-
    ## l>
    
    return -1
    
def rightTurnOriginalFivot(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]

    if s == 0:
        if isBoard(r+1, c) == 1 and isBoard(r+1, c+1) == 1:
            if board[r+1][c] == 0 and board[r+1][c+1] == 0:
                return [r, c, 1]
    
    ## --
    ## l<
    
    if s == 1:
        if isBoard(r,c-1) == 1 and isBoard(r+1, c-1) == 1:
            if board[r][c-1] == 0 and board[r+1][c-1] == 0:
                return [r, c-1, 0]
    
    ## -l
    ## <l
    
    return -1

def leftTurnTmpFivot(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]

    if s == 0:
        if isBoard(r+1, c) == 1 and isBoard(r+1, c+1) == 1:
            if board[r+1][c] == 0 and board[r+1][c+1] == 0:
                return [r, c+1, 1]
    
    ## --
    ## >l
    
    if s == 1:
        if isBoard(r, c-1) == 1 and isBoard(r+1, c-1) == 1:
            if board[r][c-1] == 0 and board[r+1][c-1] == 0:
                return [r+1, c-1, 0]
    
    ## <l
    ## -l
    
    return -1

def rightTurnTmpFivot(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]

    if s == 0:
        if isBoard(r-1, c) == 1 and isBoard(r-1, c+1) == 1:
            if board[r-1][c] == 0 and board[r-1][c+1] == 0:
                return [r-1, c+1, 1]
    
    ## >l
    ## --
    
    if s == 1:
        if isBoard(r, c+1) == 1 and isBoard(r+1 , c+1) == 1:
            if board[r][c+1] == 0 and board[r+1][c+1] == 0:
                return [r+1, c, 0]
    
    ## l>
    ## l-
    
    return -1

def up(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]
    
    if s == 0:
        if isBoard(r-1, c) == 1 and isBoard(r-1, c+1) == 1:
            if board[r-1][c] == 0 and board[r-1][c+1] == 0:
                return [r-1,c,s]

    if s == 1:
        if isBoard(r-1, c) == 1:
            if board[r-1][c] == 0:
                return [r-1,c,s]

    return -1

def down(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]
    
    if s == 0:
        if isBoard(r+1, c) == 1 and isBoard(r+1,c+1) == 1:
            if board[r+1][c] == 0 and board[r+1][c+1] == 0:
                return [r+1,c,s]

    if s == 1:
        if isBoard(r+2, c) == 1:
            if board[r+2][c] == 0:
                return [r+1,c,s]

    return -1

def right(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]

    if s ==0:
        if isBoard(r, c+2) == 1:
            if board[r][c+2] == 0:
                return [r,c+1,s]
            
    if s == 1:
        if isBoard(r,c+1) == 1 and isBoard(r+1, c+1) == 1:
            if board[r][c+1] == 0 and board[r+1][c+1] == 0:
                return [r,c+1,s]

    return -1

def left(loc):
    r = loc[0]
    c = loc[1]
    s = loc[2]

    if s == 0:
        if isBoard(r,c-1) == 1:
            if board[r][c-1] == 0:
                return [r,c-1,s]

    if s == 1:
        if isBoard(r,c-1) == 1 and isBoard(r+1,c-1) == 1:
            if board[r][c-1] == 0 and board[r+1][c-1] == 0:
                return [r, c-1,s]

    return -1 

def BFS(l):

    tmp = []

    tmp.append(leftTurnOriginalFivot(l))
    tmp.append(rightTurnOriginalFivot(l))
    tmp.append(leftTurnTmpFivot(l))
    tmp.append(rightTurnTmpFivot(l))
    tmp.append(up(l))
    tmp.append(down(l))
    tmp.append(right(l))
    tmp.append(left(l))

    ttmp = []
    for t in tmp:
        if t != -1:
            ttmp.append(t)

    return ttmp
        
def solution(_board):
    ## loc[2] => 가로 0 (오른쪽 한칸차지), 세로 1 (아래 한칸차지)
    global board
    global N
    board = _board
    N = len(board[0])
    location = [[0,0,0]]
    visit.append(location)
    d = 0

    while True:
        _location = []
        for l in location:
            if l in visit:
                continue
            else:
                visit.append(l)
            if l == [N-1, N-2, 0] or l == [N-2, N-1, 1]:
                return d
            _location += BFS(l)
        d += 1
        location = _location