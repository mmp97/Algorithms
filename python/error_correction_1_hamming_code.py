def encode(string):
    bits = ""
    for s in string.encode('ascii'):
        val = s
        binary = ""
        for i in range(8):
            binary += str(int(val%2 ) )*3
            val = (val - val%2 )/2
        bits += binary[::-1]
    return(bits)

def decode(strn):
    binary = ""
    res = ""
    temp = ""
    for s in range(0, len(strn), 3):
        binary += str( round( sum( [ int( strn[s+i] ) for i in range(3) ] )/3) )
    for b in range(0, len(binary), 8):
        temp = "".join( binary[b+i] for i in range(8) )
        res += chr( int(temp, 2) )
    return res
