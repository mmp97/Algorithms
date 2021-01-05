def last_digit(lst):
    # Dictionary with periodic values of factoring operation
    periods = {2:[6, 2, 4, 8], 
               3:[1, 3, 9, 7],
               4:[6, 4],
               7:[1, 7, 9, 3],
               8:[6, 8, 4, 2],
               9:[1, 9]}
    # Handle short lists
    if len(lst) == 0:
        return 1
    if len(lst) == 1:
        return lst[0]%10
    if len(lst) == 2:
        return pow(lst[0]%10, lst[1], 10)
    # Parse list to exclude zeros
    for i in range(len(lst)-1, 0, -1):
        if lst[i] == 0:
            lst[i-1] = 1
            lst.pop(i)
    # Value whose last digit will be calculated
    x = lst[0]%10
    # Sinular period scenario (0, 1, 5, 6)
    single_period = [0,1,5,6]
    if x in single_period:
        return x
    # Dual period scenario (4, 9)
    if (len(periods[x]) == 2):
        return periods[x][lst[1]%2]
    # Quadruple period scenario (2, 3, 7, 8)
    if (lst[1]%4 == 3):
        if(lst[2]%2 == 0):
            return periods[x][1]
        else:
            return periods[x][3]
    if (lst[1]%4 == 2):
        if (lst[2] > 1):
            return periods[x][0]
        else:
            return periods[x][2]
    return periods[x][lst[1]%4]
