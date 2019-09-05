def solution(record):
    print(record)
    print("="*50)
    userinfo = {}
    before = []
    after = []

    for r in record:
        tmp = r.split()
        if(tmp[0] == "Enter"):
            str = tmp[1] + " 님이 들어왔습니다."
            before.append(str)
            userinfo[tmp[1]] = tmp[2]
        elif(tmp[0] == "Leave"):
            str = tmp[1] + " 님이 나갔습니다."
            before.append(str)
        else: #change
            userinfo[tmp[1]] = tmp[2]

    for a in before:
        tmp = a.split()
        a = userinfo[tmp[0]] + tmp[1] + " " + tmp[2]
        after.append(a)

    return after

solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])
