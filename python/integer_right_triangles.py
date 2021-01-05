def integer_right_triangles(p):
    f1 = lambda b: p*(p/2 - b)/(p-b)
    f2 = lambda a,b: (a**2+b**2)**0.5
    return sorted([list(x) for x in set([tuple(x) for x in [sorted([b, f1(b), f2(f1(b), b)]) for b in range(1, round(p/2)) if f1(b).is_integer()]])], key = lambda x: x[0])
