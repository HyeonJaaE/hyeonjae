import itertools

def solution(n, weak, dist):
    answer = 0
    ans = []
    _weak = []
    
    for i in range(len(weak)):
        _weak.append(weak)
        tmp = weak[1:]
        tmp.append(weak[0] + n)
        weak = tmp
    
    cnt = 1

    for i in range(len(dist)):
        myiter = itertools.permutations(dist, cnt + i)
    
        for my in myiter:
            for weaktmp in _weak:
                w = []
                for weakttmp in weaktmp:
                    w.append(weakttmp)

                for m in my:
                    if len(w) == 0:
                        break
                    tmp = w[0] + m
                    while w[0] <= tmp:
                        del w[0]
                        if len(w) == 0:
                            break
                if len(w) == 0:
                    ans.append(len(my))
    
    if len(ans) == 0:
        answer = -1
    else:
        answer = ans[0]
        
    return answer