class RomanNumerals:
    key = { 
    0:{
        "1":"I", "2":"II", "3":"III", "4":"IV", "5":"V", 
        "6": "VI", "7":"VII", "8":"VIII", "9":"IX", "0":""},
    1:{
        "1":"X", "2":"XX", "3":"XXX", "4":"XL", "5":"L", 
        "6": "LX", "7":"LXX", "8":"LXXX", "9":"XC", "0":""},
    2:{
        "1":"C", "2":"CC", "3":"CCC", "4":"CD", "5":"D", 
        "6": "DC", "7":"DCC", "8":"DCCC", "9":"CM", "0":""},
    3:{
        "1":"M", "2":"MM", "3":"MMM"}
    }
    roman_dict = {"I":1, "V":5, "X":10, "L": 50, "C":100, "D":500, "M":1000}
    
    @staticmethod
    def from_roman(arabic):
        result = 0
        i = 0
        while i < len(arabic):
            if i == len(arabic) - 1:
                result += RomanNumerals.roman_dict[arabic[-1]]
                break
            if RomanNumerals.roman_dict[arabic[i]] >= RomanNumerals.roman_dict[arabic[i+1]]:
                result += RomanNumerals.roman_dict[arabic[i]]
            else:
                result -= RomanNumerals.roman_dict[arabic[i]]
            i += 1
        return result
    @staticmethod
    def to_roman(roman):
        result = ""
        roman = str(roman)
        for i in range(len(roman) - 1, -1, -1):
            result = RomanNumerals.key[len(roman) - 1 - i][roman[i]] + result
        return result
