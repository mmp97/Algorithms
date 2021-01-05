alphabet = "!abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? "
l = len(alphabet)
def decode(string):
    result = ""
    temp = ""
    for s in range(len(string)):
        if string[s] in alphabet:
            for a in range(l):
                temp = alphabet[(a*(2**(s+1) )%l ) ]
                if temp == string[s]:
                    result += alphabet[a]
        else:
            result += string[s]
    return result