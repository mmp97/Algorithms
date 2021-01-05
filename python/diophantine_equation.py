def sol_equa(n):
    factors = [ i for i in range(1, round(n**0.5 + 1) ) if n%i == 0 ]
    x = lambda f : (n/f + f)/2
    y = lambda f : (n/f - f)/4
    return [ [x(f), y(f)] for f in factors if x(f).is_integer() and y(f).is_integer() ]

