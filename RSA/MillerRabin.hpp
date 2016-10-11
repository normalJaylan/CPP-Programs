#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

class MillerRabin {
public:
		MillerRabin(){};
		bool MillerRabin_Test(string p);
		string modulo(string str1, string str2, string str3);
		string mulmod(string str1, string str2, string str3);
public :
		Prime pri;
};

bool MillerRabin::MillerRabin_Test(string p)
{
	string t = p;
	int x = t[49] - 48;
	x -= 1;
	t[49] = x + 48;				// 计算得到 p - 1		
	
	cout << "MillerRabin..." << endl;
	
	string str = t;
	while (pri.div(t, "2", 0) == "0")
	{
		t = pri.div(t, "2", 1);
	}
	
	string temp;
	for (int i=0; i < 1; i++)
	{
		temp = t;
		string a = "2";
		string mod =  modulo(a, temp, p);

		 while (temp != str && mod != "1" && mod != str)  
        {  
			mod = mulmod(mod, mod, p);  
			temp = pri.mul(temp, "2");									// temp *= 2;  
		}  
        if (mod != str && pri.div(temp, "2", 0) == "0")  
        {  
			cout << "is not prime" << endl;
			return false;  
        }  
	}
	cout << "is prime" << endl;
	return true;
}

string MillerRabin::modulo(string a, string b, string n)
{
	string x = "1";  
    string y = a;  
    while (b != "0")  
    {  
        if (pri.div(b, "2", 0) == "1") 		// b % 2 == 1
            x = pri.div(pri.mul(x, y), n, 0); 							// (x * y) % mod; 
        y = pri.div(pri.mul(y, y), n, 0);								// (y * y) % mod;
		b = pri.div(b, "2", 1);													// b = b / 2;
    }  
    return pri.div(x, n, 0);  								// x % mod
}

string MillerRabin::mulmod(string a, string b, string n)
{
	string x = "0";
	string y = pri.div(a, n, 0);  
    while (b != "0")  
    {  
        if (pri.div(b, "2", 0) == "1")  
        {      
            x = pri.div(pri.add(x, y), n, 0);						// (x + y) % mod;  
        }  
        y = pri.div(pri.mul(y, "2"), n, 0);									// (y * 2) % mod;  
        b = pri.div(b, "2", 1);	 
    }  
    return pri.div(x, n, 0);  
}
