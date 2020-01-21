#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

size_t getVolume(size_t r)
{
    return r * r * r;
}

size_t getSurfaceArea(size_t r)
{
    return r * r;
}

bool isFun(size_t go1, size_t go2, size_t so1, size_t so2)
{
    return (go1 != so1 && go1 != so2 && go2 != go1 && go2 != so1 && go2 != so2 && so1 != so2);
}

bool isValid(size_t go1, size_t go2, size_t so1, size_t so2)
{
    return getVolume(go1) + getVolume(go2) == getVolume(so1) + getVolume(so2);
}

size_t interestingVal(size_t o1, size_t o2)
{
    o2 = max(o1, o2);
    o2 = min(o1, o2);
    return (o2 * o2 - o1 * o1);
}

int main()
{
    size_t orbSizeMin;
    size_t orbSizeMax;
    cin >> orbSizeMin >> orbSizeMax;
    cin.ignore();
    size_t glowingSize1;
    size_t glowingSize2;
    cin >> glowingSize1 >> glowingSize2;
    cin.ignore();

    map<size_t, pair<size_t, size_t>> interesting;

    for (size_t i = orbSizeMin; i <= orbSizeMax; ++i)
    {
        for (size_t j = orbSizeMin; j < orbSizeMax; ++j)
        {
            if (isValid(glowingSize1, glowingSize2, i, j))
            {
                if (isFun(glowingSize1, glowingSize2, i, j))
                {
                    interesting.insert({interestingVal(i, j), {i, j}});
                }
            }
        }
    }

    if (interesting.size() == 0)
    {
        cout << "VALID\n";
        return 0;
    }

    auto f = interesting.begin();

    cout << f->second.first << " " << f->second.second << "\n";
}