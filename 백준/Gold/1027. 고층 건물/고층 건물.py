def cald(a,b,l1):
    return (l1[b] - l1[a])/(b - a)

def checkf(idx,l1):
    max_d = 0
    firstFlag = True
    ret = 0
    for i in range(idx+1,len(l1)):
        if firstFlag:
            max_d = l1[i] - l1[idx]
            firstFlag = False
            ret += 1
        if max_d < cald(idx, i,l1):
            max_d = cald(idx,i,l1)
            ret += 1
    return ret

def checkb(idx,l1):
    min_d = 0
    firstFlag = True
    ret = 0
    for i in range(idx-1,-1,-1):
        if firstFlag:
            min_d = l1[idx] - l1[i]
            firstFlag = False
            ret += 1
        if min_d > cald(i, idx,l1):
            min_d = cald(i,idx,l1)
            ret += 1
    return ret


    
N = input()
l = list(map(int,input().split()))
ans = checkf(0,l) + checkb(0,l)
for i in range(0,len(l)):
    ans = max(ans,checkf(i,l)+checkb(i,l))
print(ans)
