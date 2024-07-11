#1013번
def isOk(s):
    ls = len(s)
    #0으로 시작햇으면 01이어야하고
    #1으로 시작햇다면 1 0두개이상 1한개이상 이어야함
    #저 마지막 1이 다먹을건지, 한개 남겨줄건지가 중요한데
    #마지막 1 다음에 0이 2개이상이면 하나 남겨줘야 가능성이 남고
    #1개뿐이면 다 먹어야 가능성이 남네
    if ls==1 :
        return False
    elif ls==0 :
        return True

    
    if s[0] == '0':
        if s[1] == '1':
            return isOk(s[2:])
        else :
            return False
    elif s[0] =='1':
        if ls<4 :
            return False
        if s[1]!='0' or s[2] !='0':
            return False
        idx = 3
        while True:
            if idx>=ls :
                return False
            if s[idx] == '1':
                break
            idx+=1
        #현재 idx는 1의 시작점
        while True:
            if idx>=ls :
                break
            if s[idx] == '0':
                break
            idx+=1
        #현재 idx는 1이 끝난 첫지점 : 아예 끝이거나, 0이거나
        if s[idx-2]=='1':
            return isOk(s[idx-1:]) or isOk(s[idx:])
        else :
            return isOk(s[idx:])
    
N = int(input())
for i in range(N):
    if isOk(input()):
        print("YES")
    else:
        print("NO")
