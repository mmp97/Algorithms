from collections import deque
def last_digit(n1, n2):
    if n2 == 0:
        return 1
    if n1 == 0:
        return 0
    x = n1%10
    period = deque([])
    while x**(len(period) + 1)%10 not in period:
        period.append(x**(len(period) + 1)%10)
    if len(period) == 1:
        return x
    period.insert(0, period.pop())
    return period[n2%len(period)]