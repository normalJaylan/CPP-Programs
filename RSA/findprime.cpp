#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool prime(int x)
{
     int y;
     for(y = 2;y <= sqrt(x);y++)
         if (x % y == 0)
            return false;
     return true;
}
int main ()
{
    int n,i;
	char filename[] = "prime.txt";
    cin >> n;

	ofstream fout(filename);

    for(i = 3;i <= n;i++)
        if (prime(i))
            fout << i << endl;

    return 0;
}