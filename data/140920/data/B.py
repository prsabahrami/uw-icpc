def encrypt(s, k):
    count = [0] * 26
    out = ""
    last = ord(s[0])-97
    for i in range(k):
        out += s[i]
        count[ord(s[i])-97] += 1    
    for i in range(k, len(s)):
        ## encrypt this
        shift = count.index(max(count))+1
        out += chr(97+ (ord(s[i]) -97 +shift) % 26)
        count[last] -= 1
        last = ord(s[i-k+1])-97
        count[ord(s[i])-97] += 1  
    return out

k = int(raw_input())
s = raw_input()
print encrypt(s,k)
        
