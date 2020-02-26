#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//display the result from minmult
void order(int i, int j, int * P[])
{
	int k;
	if (i == j)
		cout << "A" << i;
	else
	{
		k = P[i][j];

		cout << "(";
		order(i, k, P);
		order(k + 1, j, P);
		cout << ")";
		
	}
}

int minmult( const int d[], int numOfMatrices)
{
	int i, j, k, diagonal, min;

	//create a dynamic two dimensional array with size of n*n, where n = number of matrices.
	int **M = new int *[numOfMatrices];

	for (int a = 1; a <= numOfMatrices; a++)
	{
		M[a] = new int[numOfMatrices];
	}

	int **P = new int *[numOfMatrices];

	for (int a = 1; a <= numOfMatrices; a++)
	{
		P[a] = new int[numOfMatrices];
	}

	for (i = 1; i <= numOfMatrices; i++)
		M[i][i] = 0;
		for(diagonal = 1; diagonal <= numOfMatrices-1; diagonal++)
			for (i = 1; i <= numOfMatrices - diagonal; i++)
			{
				j = i + diagonal;
				min = 32767;
				for (k = 1; k <= j - 1; k++)
				{
					//For debugging
					//cout << "q = M[" << i << "][" << k << "] + M[" << k + 1 << "][" << j << "] + d[" << i - 1 << "] * d[" << k << "] * d[" << j << "]" << endl;
					//cout << "q =" << M[i][k] << " + " << M[k + 1][j] << " + " << d[i - 1] << " * " << d[k] << " * " << d[j] ;
					int q = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
					if (q < min && q > 0)
					{
						//cout << " = " << q << endl << endl;
						min = q;
						P[i][j] = k;
						//cout << "P[" << i << "]" << "[" << j << "]" << " = " << k << endl;
					}
				}
				//cout << "M[" << i << "]" << "[" << j << "]" << " = " << min << endl;
				M[i][j] = min;
			}
		cout <<endl<< "Minimum multiplication Solution: ";

		//call the function to display the result
		order(1, numOfMatrices,P);
		cout << endl << endl;


		cout << "M: " << endl;

		//display the matrix that stores the minimum multiplication
		for (int a = 1; a <= numOfMatrices; a++)
		{
			cout << endl;
			for (int b = 1; b <= numOfMatrices; b++)
			{
				if (M[a][b]>=0)
				cout << M[a][b] << " ";
				else
					cout << "   ";
			}
		}

		cout <<endl<< "P: " << endl;

		//display the matrix that shows where to split the parenthesize
		for (int a = 1; a <= numOfMatrices; a++)
		{
			cout << endl;
			for (int b = 1; b <= numOfMatrices; b++)
			{
				if (P[a][b] >= 0)
					cout << P[a][b] << " ";
				else
					cout << "  ";
			}
		}
		cout << endl;

	return 0;

}

int main()
{

	bool flag = true;
	string userQuitInput;// store user input for quiting the program for continue
	int numOfMatrices;// store number of matrices from the user



	while (flag)
	{
		cout << "Please enter the number of matrices:";
		cin >> numOfMatrices;

		int * matrixAry = new int[numOfMatrices+1]; // dynamic array for storing the dimensions of matrices

		// ask user for the input for matrice dimensions and store them in the array
		for (int i = 0; i < numOfMatrices; i++)
		{
			int r,c;
			cout << "Please enter the dimension for A" << i+1 << " :";
			cin >> r >> c;
			matrixAry[i] = r;
			if (i + 1 == numOfMatrices)
				matrixAry[i + 1] = c;
		}

		// call the function to get the minimum way of parenthesizing the matrices
		minmult(matrixAry, numOfMatrices);

		//ask user input for quiting for continuing the program
		cout << "Enter any key to continue. Enter Q to quite." << endl;
		cin >> userQuitInput;

		if (userQuitInput == "q")
			flag = false;
	}


	char c;
	cin >> c;

	return 0;
}