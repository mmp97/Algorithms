#include <math.h>
#include <sstream>
long long missing(std::string s)
{
    if (s.length() < 3)
        return -1;
    int size = 0, inc = 0;
    long long v1, v2;
    int *err = new int[s.length() / 2](), *gap = new int[s.length() / 2]();
    std::string val1 = "", val2 = "";
    while (size <= s.length() / 2)
    {
        size = size + 1 - inc;
        inc = 0;
        for (int i = 0; i < s.length() - size; i = i + val1.length())
        {
            val1 = "", val2 = "";
            for (int j = i; j < size + i; j++)
                val1.push_back(s[j]);
            std::istringstream(val1) >> v1;
            for (int k = i + val1.length(); k < i + val1.length() + size; k++)
                val2.push_back(s[k]);
            std::istringstream(val2) >> v2;
            if ((v1 + 1) % (int)pow(10, size) == 0 || ((v1 + 2) % (int)pow(10, size) == 0 && (v2 + 1) % (int)pow(10, size) != 0))
            {
                size++;
                inc++;
            }
            val2 = "";
            for (int k = i + val1.length(); k < i + val1.length() + size; k++)
                val2.push_back(s[k]);
            std::istringstream(val2) >> v2;
            if (v2 - v1 != 1 && v2 - v1 != 2)
                err[size - 1 - inc]++;
            if (v2 - v1 == 2)
                gap[size - 1 - inc]++;
            if (err[size - 1 - inc] > 0)
                break;
        }
        if (err[size - 1 - inc] == 0 && gap[size - 1 - inc] == 1)
        {
            size = size - inc;
            break;
            if (size == s.length() && err[size - 1 - inc] != 0)
                return -1;
        }
    }
    for (int i = 0; i < s.length() - size; i = i + val1.length())
    {
        val1 = "", val2 = "";
        for (int j = i; j < size + i; j++)
            val1.push_back(s[j]);
        std::istringstream(val1) >> v1;
        for (int k = i + val1.length(); k < i + val1.length() + size; k++)
            val2.push_back(s[k]);
        std::istringstream(val2) >> v2;
        if ((v1 + 1) % (int)pow(10, size) == 0 || ((v1 + 2) % (int)pow(10, size) == 0 && (v2 + 1) % (int)pow(10, size) != 0))
        {
            size++;
            inc++;
        }
        val2 = "";
        for (int k = i + val1.length(); k < i + val1.length() + size; k++)
            val2.push_back(s[k]);
        std::istringstream(val2) >> v2;
        if (v2 - v1 == 2)
            return v1 + 1;
    }
    return -1;
}
