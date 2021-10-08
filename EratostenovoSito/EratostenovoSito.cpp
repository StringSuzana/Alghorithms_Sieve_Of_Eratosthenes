#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Finding all prim numbers in firs n numbers.
//TODO: Heavy refactoring and exception handling.
int main() {
	int i;
	char* prim; //prim flag
	int n; //from 0 to n

	scanf_s("%d", &n); //load n

	prim = static_cast<char*>(malloc(sizeof(char) * (n + 1)));//instead of int[]. Because I can.

	for (i = 0; i <= n; i++)
		prim[i] = 1; //Set everything to be prim

	//Remove 0 and 1
	prim[0] = 0;
	prim[1] = 0; 

	const int boundary = sqrt(n);

	for(i=2; i<= boundary; i++)
	{
		if(prim[i])//if number is not already set as prim
		{
			for (int j = i * 2; j<=n; j+=i)
			{
				prim[j] = 0; //set it to prime
			}
		}
	}

	//print it to console
	for(i=0; i<=n; i++)
	{
		if(prim[i])
		{
			std::cout << i << ", ";
		}
	}
}


