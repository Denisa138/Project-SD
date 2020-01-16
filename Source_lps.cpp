#include "longest_palindromic_substring.h"

int main()
{
	ifstream FILE("data.in");
	string n;

	while (FILE >> n)
	{
		int size = n.size();
		cout << "\n size " << size;
		cout << "\nMethod 2:";
		auto start = high_resolution_clock::now();

		method_2(n, size);

		auto stop = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(stop - start);

		cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.";

		cout << "\nMethod 1:";
		start = high_resolution_clock::now();

		method_1(n, size);

		stop = high_resolution_clock::now();

		duration = duration_cast<microseconds>(stop - start);

		cout << "\nThe duration of the algorithm: " << duration.count() << " microseconds.\n";
	}
		
	return 0;
}
