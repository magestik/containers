#include <List.h>
#include <Array.h>

#include <iostream>

int main()
{
    Array<int> a;
    a.add(12);
    a.add(15);
    for (int e : a)
    {
        std::cout << e << std::endl;
    }

    return 0;
}
