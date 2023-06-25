#include <bits/stdc++.h>
using namespace std;

int printRev(int n)
{
    if (n == 0)
        return;
    
    return printRev(n--);
}
int main()
{
    printRev(4);
    return 0;
}