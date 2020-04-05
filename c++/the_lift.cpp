#include <vector>

bool subsets_empty(std::vector<std::vector<int>> queues)
{
    for (std::vector<int> &v : queues)
        if (!v.empty())
            return false;
    return true;
}
bool call(std::vector<std::vector<int>> queues, std::vector<int> psng, int pos, int height, int dir)
{
    bool rtn = false;
    for (int p = pos; ((p < height && dir == 1) || (p >= 0 && dir == -1)); p += dir)
    {
        for (int i = 0; i < queues[p].size(); i++)
            if ((queues[p][i] - pos) * dir > 0)
                return true;
        for (int q = 0; q < psng.size(); q++)
            if (p + dir == psng[q])
                return true;
    }
    for (int c = pos + dir; ((c < height && dir == 1) || (c >= 0 && dir == -1)); c += dir)
    {
        if (rtn == false && !queues[c].empty())
            return true;
    }
    return rtn;
}
std::vector<int> the_lift(std::vector<std::vector<int>> queues, int capacity)
{
    int pos = 0, height = queues.size(), dir = 1;
    std::vector<int> psng, result;
    result.push_back(0);
    while (subsets_empty(queues) == false || psng.empty() == false)
    {
        if (!call(queues, psng, pos, height, dir))
            dir *= -1;
        for (int p = 0; p < psng.size(); p++)
            if (pos == psng[p])
            {
                if (result.back() != pos)
                    result.push_back(pos);
                psng.erase(psng.begin() + p);
                p--;
            }
        for (int q = 0; q < queues[pos].size(); q++)
            if ((queues[pos][q] - pos) * dir > 0)
            {
                if (result.back() != pos)
                    result.push_back(pos);
                if (psng.size() < capacity)
                {
                    psng.push_back(queues[pos][q]);
                    queues[pos].erase(queues[pos].begin() + q);
                    q--;
                }
            }
        if ((pos < height && dir == 1) || (pos > 0 && dir == -1))
            pos += dir;
    }
    if (result.back() != 0)
        result.push_back(0);
    return result;
}
