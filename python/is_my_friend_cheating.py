def remov_nb(n):
    a = lambda b : ((n+1)*n/2 - b)/(b+1)
    return [ (b, a(b)) for b in range(1,n) if a(b).is_integer() and a(b) <= n ]
