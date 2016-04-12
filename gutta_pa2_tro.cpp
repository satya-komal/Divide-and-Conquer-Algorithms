#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

class R_Vectors
{
public:
    static vector<vector<int> > ReturnRectangularIntVector(int size1, int size2)
    {
        vector<vector<int> > newVector(size1);
        for (int vector1 = 0; vector1 < size1; vector1++)
        {
            newVector[vector1] = vector<int>(size2);
        }

        return newVector;
    }
};

class tromino
{

private:
	vector<vector<int> > grid;
	int currentNum = 0;

public:
	tromino(int size, int x, int y)
	{

		int actualsize = 1;
		while (actualsize < size)
		{
			actualsize *= 2;
		}

		grid = R_Vectors::ReturnRectangularIntVector(actualsize, actualsize);
		currentNum = 1;

		// Fill in the grid with all empty squares.
		for (int i = 0; i < actualsize; i++)
		{
			for (int j = 0; j < actualsize; j++)
			{
				grid[i][j] = 0;
			}
		}

		// This represents the original hole in the tromino.
		grid[x][y] = -1;
	}

	// Wrapper call for recursive method.
	virtual void tile()
	{
		tileRec(grid.size(), 0, 0);
	}

private:
	void tileRec(int size, int topx, int topy)
	{

		if (size == 2)
		{

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (grid[topx + i][topy + j] == 0)
					{
						grid[topx + i][topy + j] = currentNum;
					}
				}
			}

			// Advance to the next tromino.
			currentNum++;
		}

		// Recursive case...
		else
		{

			int savex = topx, savey = topy;

			for (int x = topx; x < topx + size; x++)
			{
				for (int y = topy; y < topy + size; y++)
				{
					if (grid[x][y] != 0)
					{
						savex = x;
						savey = y;
					}
				}
			}

			// Hole in upper left quadrant.		
			if (savex < topx + size / 2 && savey < topy + size / 2)
			{

				// Recursively tile upper left quadrant.
				tileRec(size / 2, topx, topy);

				// Fill in middle tromino
				grid[topx + size / 2][topy + size / 2 - 1] = currentNum;
				grid[topx + size / 2][topy + size / 2] = currentNum;
				grid[topx + size / 2 - 1][topy + size / 2] = currentNum;

				// Advance to the next tromino
				currentNum++;

				// Now we can make our three other recursive calls.
				tileRec(size / 2, topx, topy + size / 2);
				tileRec(size / 2, topx + size / 2, topy);
				tileRec(size / 2, topx + size / 2, topy + size / 2);

			}

			// Hole in upper right quadrant
			else if (savex < topx + size / 2 && savey >= topy + size / 2)
			{

				// Recursively tile upper right quadrant.
				tileRec(size / 2, topx, topy + size / 2);

				// Fill in middle tromino
				grid[topx + size / 2][topy + size / 2 - 1] = currentNum;
				grid[topx + size / 2][topy + size / 2] = currentNum;
				grid[topx + size / 2 - 1][topy + size / 2 - 1] = currentNum;

				// Advance to the next tromino
				currentNum++;

				// Now we can make our three other recursive calls.
				tileRec(size / 2, topx, topy);
				tileRec(size / 2, topx + size / 2, topy);
				tileRec(size / 2, topx + size / 2, topy + size / 2);

			}

			// Hole in bottom left quadrant
			else if (savex >= topx + size / 2 && savey < topy + size / 2)
			{

				// Recursively tile bottom left quadrant.
				tileRec(size / 2, topx + size / 2, topy);

				// Fill in middle tromino
				grid[topx + size / 2 - 1][topy + size / 2] = currentNum;
				grid[topx + size / 2][topy + size / 2] = currentNum;
				grid[topx + size / 2 - 1][topy + size / 2 - 1] = currentNum;

				// Advance to the next tromino
				currentNum++;

				// Now we can make our three other recursive calls.
				tileRec(size / 2, topx, topy);
				tileRec(size / 2, topx, topy + size / 2);
				tileRec(size / 2, topx + size / 2, topy + size / 2);
			}
			else
			{

				// Recursively tile bottom right quadrant.
				tileRec(size / 2, topx + size / 2, topy + size / 2);

				// Fill in middle tromino
				grid[topx + size / 2 - 1][topy + size / 2] = currentNum;
				grid[topx + size / 2][topy + size / 2 - 1] = currentNum;
				grid[topx + size / 2 - 1][topy + size / 2 - 1] = currentNum;

				// Advance to the next tromino
				currentNum++;

				// Now we can make our three other recursive calls.
				tileRec(size / 2, topx + size / 2, topy);
				tileRec(size / 2, topx, topy + size / 2);
				tileRec(size / 2, topx, topy);
			}

		} 

	} 


public:
	virtual void print()
	{

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if(grid[i][j]== -1) cout<<"X"<<"\t";
				else cout << grid[i][j] << "\t";
			}
			cout << endl;
		}
	}
};
	int main()
	{
                   
		// Get user input...
		cout << "Enter a number " << endl;
                  int n,size;
                  cin>>n;
                  size =pow(2,n);
		
		int x,y;
		x= rand()%size;
		y= rand()%size;
		//cin>>x;
		//cin>>y;

		// Create our object and tile it!
		tromino *thisguy = new tromino(size, x, y);
		thisguy->tile();

		// Print out the trominoed grid.
		cout << "Here's your final tromino matrix:" << endl;
		thisguy->print();
		
		return 0;

	}

