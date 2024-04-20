def mod4(x):
    if x % 4 == 0:
        return x
    elif x % 4 == 1:
        return 1
    elif x % 4 == 2:
        return x+1
    else:
        return 0
    
def compute(start, fin):
    val = 0
    #for i in range(start, fin+1):
    #    val = val ^ i
    #print val
    return mod4(start-1) ^ mod4(fin)

T = int(raw_input())
for i in range(T):
   line = raw_input()
   (s,f) = line.split()
   print compute(int(s),int(f))
