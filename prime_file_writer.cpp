#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cin;
using std::ofstream;
using std::endl;
using std::string;
using std::vector;

void prime(int &range)
{
	ofstream file;
	file.open("prime.txt");
	if (range < 2)
    {
        file << "Your number was lower than 2, the lowest prime number.";
        file.close();
        return;
    }
	vector<int> primes;
	primes.push_back(2);
	file << primes.back() << endl;
	primes.push_back(3);
	file << primes.back() << endl;
	primes.push_back(5);
	file << primes.back() << endl;

	int check = 0;
	for (int i = 7; i <= range; i += 2)
	{
		for (vector<int>::iterator it = primes.begin() ; it != primes.end(); ++it)
        {
            if (i % *it == 0)
            {
                ++check;
                break;
            }
		}
        if (check == 0)
        {
            primes.push_back(i);
            file << primes.back() << endl;
        }
        check = 0;
	}
	file.close();
}
int main()
{
    int range;
    cin >> range;
	prime(range);
}
