#include "longest_palindromic_substring.h"

void method_1(string s, int n)
{
	int hight = 0;
	int low = 0;
	bool** array = new bool* [n];


	for (int i = 0; i < n; i++)
	{
		array[i] = new bool[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = false;
		}

	}

	//substring of length 1 are palindromic
	hight = 1;
	for (int i = 0; i < n; i++)
	{
		array[i][i] = true;
	}

	//length 2
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			array[i][i + 1] = true;
			hight = 2;
			low = i;
		}
	}

	for (int iterator = 3; iterator <= n; iterator++)
	{
		for (int contor1 = 0; contor1 < n - iterator + 1; contor1++)
		{
			int contor2 = contor1 + iterator - 1;

			if (array[contor1 + 1][contor2 - 1] == true && s[contor1] == s[contor2])
			{
				array[contor1][contor2] = true;

				if (iterator > hight)
				{
					hight = iterator;
					low = contor1;
				}
			}
		}
	}

	hight = low + hight;
	cout << "\nLongest palindromic substring ";
	for (int i = low; i < hight; i++)
	{
		cout << s[i];
	}

	for (int i = 0; i < n; i++)
	{
		delete[]array[i];
	}

	delete[]array;
}


void method_2(string s, int n)
{
	int hight, low;
	int max_length = 1;
	int begin = 0;

	for (int i = 1; i < n; i++)
	{
		//pt palindrom impar
		low = i - 1;
		hight = i + 1;
		while (low >= 0 && hight < n && s[low] == s[hight])
		{
			if (hight - low + 1 > max_length)
			{
				begin = low;
				max_length = hight - low + 1;
			}
			low--;
			hight++;
		}


		//pt palindrom par
		low = i - 1;
		hight = i;
		while (low >= 0 && hight < n && s[low] == s[hight])
		{
			if (hight - low + 1 > max_length)
			{
				begin = low;
				max_length = hight - low + 1;
			}
			low--;
			hight++;
		}
	}

	hight = begin + max_length;
	cout << "\nLongest palindromic substring ";
	for (int i = begin; i < hight; i++)
	{
		cout << s[i];
	}

}
