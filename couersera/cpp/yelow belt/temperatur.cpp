#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int Q, n;
	long int sum = 0;
	cin >> Q;
	vector<int> a;
	vector<int> b;
	for (int& i: a)
	{
		cin >> i;
		sum += i;
	}
	int arg = sum / Q;
	for (int i = 0; i < Q; i++)
	{
		if (a[i] > arg)
		{
			b.push_back(i);
		}
	}
	cout << b.size() << endl;
	for (auto i : b)
	{
		cout << i << " ";
	}
	return 0;
}
