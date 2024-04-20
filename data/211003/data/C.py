def extended_gcd(a, b):
    """returns gcd(a, b), s, r s.t. a * s + b * r == gcd(a, b)"""
    s, old_s = 0, 1
    r, old_r = b, a
    while r:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_s, s = s, old_s - q * s
    return old_r, old_s, (old_r - old_s * a) // b if b else 0


def crt(b, m):
    """returns x s.t. x = b[i] (mod m[i]) for all i"""
    x, m_prod = 0, 1
    for bi, mi in zip(b, m):
        g, s, _ = extended_gcd(m_prod, mi)
        if ((bi - x) % mi) % g:
            return (None, None)
        x += m_prod * (s * ((bi - x) % mi) // g)
        m_prod = (m_prod * mi) // g
    return (x % m_prod, m_prod)


b = int(input())
mx = 0
sum_d = 0
q = 1010;
x = [0]*q
vis = [False]*q
bad = False

for i in range(b):
    t,m,d = [int(x) for x in input().split()]
    t -= sum_d
    if t > mx:
        mx = t
    t = (t % m + m) % m
    if not vis[m]:
        vis[m] = True
        x[m] = t
    if vis[m] and x[m] != t:
        bad = True
    sum_d += d

if bad:
    print("-1")
else:
    j = 0
    for v in vis:
        if v:
            j += 1

    xx = [0]*j
    mm = [0]*j
    j = 0
    for i in range(len(vis)):
        if vis[i]:
            xx[j] = x[i]
            mm[j] = i
            j += 1


    (ans, mod) = crt(xx,mm)
    if ans is None:
        print("-1")
    else:
        q = (mx-ans) // mod
        ans += q*mod
        while ans > mx:
            ans -= mod
        while ans < mx:
            ans += mod
        print(ans)
