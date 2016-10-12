#include <iostream>
#include "prime.hpp"
#include "MillerRabin.hpp"
#include <string>
#include <fstream>

using namespace std;

string get_n(string p, string q)			// get n
{
	Prime pri;
	return pri.mul(p, q);
}

string get_euler(string p, string q)		// get euler
{
	Prime pri;
	p = pri.sub(p, "1");
	q = pri.sub(q, "1");
	return pri.mul(p, q);
}

string get_e(string a, string b)					// get e
{
	Prime pri;
	if (b == "0") 
		return a;
	return get_e(b, pri.div(a, b, 0));
}

string get_d(string a, string b, string &x, string &y)			// get d
{
	Prime pri;

	if (b == "0")
	{
		x = "1";
		y = "0";
		return a;
	}

	string r = get_d(b, pri.div(a, b, 0), x, y);
	string t = x;
	x = y;
	y = pri.sub(t, pri.mul(pri.div(a, b, 1), y));			
       
        return r;
}

void print(string e, string d, string n)
{
	char filename[] = "rsa.txt";
	ofstream fout(filename);

	fout << "PU = { " << e << " , " << n << " }" << endl;		
	fout << "PR = { " << d << " , " << n << " }" << endl;		
}

string compute(string a, string b, string n)
{
	Prime pri;
	string x = "1";  
    string y = a;  
    while (b != "0")  
    {  
        if (pri.div(b, "2", 0) == "1") 		
            x = pri.div(pri.mul(x, y), n, 0); 							
        y = pri.div(pri.mul(y, y), n, 0);								
	b = pri.div(b, "2", 1);												
    }  
    return pri.div(x, n, 0);  							
}

int main() 
{
	Prime rand;
	MillerRabin ra;
	string p, q;

	p = rand.get_primenumber();
//	p = "86707127937577762221408860520896503623028541326991";
	while (true)
	{
		if (ra.MillerRabin_Test(p))
			break;
		p = rand.add(p, "2");
		
		while (!rand.division(p))
		{
			p = rand.add(p, "2");
		}
		cout << p << endl;
	}

	q = rand.get_primenumber();
//	q = "77231274707819831629916647894450694734619752612889";
	while (true)
	{
		if (ra.MillerRabin_Test(q))
			break;
		q = rand.add(q, "2");

		while (!rand.division(q))
		{
			q = rand.add(q, "2");
		}
		cout << q << endl;
	}

//        p = "26240867817681868266756659123839583762465154552803";
//        q = "14336816377536066837580608295621274857786649247029"; 

        cout << "" << endl;
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;

	string n = get_n(p, q);						
	string euler = get_euler(p, q);			

	cout << "n = " << n << endl;
	cout << "euler = " << euler << endl;

	string e = "1234567890123456789012";
	while (true)
	{
		if (get_e(euler, e) == "1")
			break;
		e = rand.add(e, "1");
	}
	cout << "e = " << e << endl;
	
	string d = "0";
	string y = "0";
	get_d(e, euler, d, y);

        while (true)
        {
            if (d[0] != '-')
                break;
            d = rand.add(d, euler);
        }
        cout << "d = " << d << endl;

//	print(e, d, n);                             

	string m;
	cout << "" << endl;
	cout << "Plain Text: ";
	cin >> m;
	string text = compute(m, e, n);
        cout << "" << endl;
	cout << "Cipher Text: ";
	cout << text << endl;
	
	cout << "" << endl;
	cout << "Plain Text: ";
	cout << compute(text, d, n) << endl;
 	return 0;
}
