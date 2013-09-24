////////////////////////////////////////////////////////////////////// 
/// @file main.cpp 
/// @author Maximilian Schroeder
/// @brief "Brute Force" Sudoku Solver
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

unsigned long iterations = 0;
vector<vector<short> > grid;
vector<short> pos;

void printGrid()
{
	ofstream outFile("solution.txt");
	for(short i = 0; i < 9; i++)
	{
		if(i != 0)
		{
			if(i % 3 == 0)
			{
				for(short b = 0; b < 39; b++)
				{
					if(b == 12 || b == 26)
					{
						outFile<<"|";
						continue;
					}
					outFile<<" ";
				}
				outFile<<endl;
			}
			for(short a = 0; a < 39; a++)
			{
				if(i % 3 == 0)
				{
					if(a == 12 || a == 26)
					{
						outFile<<"+";
					}
					else
					{
						outFile<<"-";
					}
				}
				else
				{
					if(a == 3 || a == 7 || a == 12 || a == 17 || a == 21 || a == 26 || a == 31 || a == 35)
					{
						outFile<<"+";
					}
					else
					{
						outFile<<"-";
					}
				}
			}
			outFile<<endl;
			if(i % 3 == 0)
			{
				for(short b = 0; b < 39; b++)
				{
					if(b == 12 || b == 26)
					{
						outFile<<"|";
						continue;
					}
					outFile<<" ";
				}
				outFile<<endl;
			}
		}
		for(short j = 0; j < 9; j++)
		{
			short x = grid[i][j];
			if(j != 0)
			{
				if(j % 3 == 0)
				{
					outFile<<" | ";
				}
				else
				{
					outFile<<"|";
				}
				
			}
			if(x > 0)
			{
				outFile<<" "<<x<<" ";
			}
			else if(x <= 0)
			{
				outFile<<"("<<x * -1<<")";
			}	
		}
		outFile<<endl;
	}
	outFile.close();
}

bool valid(string data)
{
	for(short i = 0; i < 9; i++)
	{
		short x = (short)data[i];
		if(!((x >= 48 && x <= 57) || x == 45))
		{
			return false;
		}
	}
	return true;
}

short convertData(char a)
{
	short x = (short)a;
	if(x >= 49 && x <= 57)
	{
		return (x - 48);
	}
	return 0;
}

short createPos(short i, short j)
{
	short pos = i * 9;
	pos += j;
	return pos + 1;	
}

short get_i(short pos)
{
	short i = pos % 9;
	if(i == 0)
	{
		return (pos / 9) - 1;
	}	
	pos -= i;
	return pos / 9;
}

short get_j(short pos)
{
	short j = pos % 9;
	if(j == 0)
	{
		return 8;
	}
	return j - 1;
}

bool validRow(short spot, short value)
{
	short i = get_i(spot);
	short j = get_j(spot);	
	for(short a = 0; a < 9; a++)
	{
		if(a == j)
		{
			continue;
		}
		if(grid[i][a] == value || grid[i][a] == (value * -1))
		{
			return false;
		}
	}
	return true;
}

bool validCol(short spot, short value)
{
	short i = get_i(spot);
	short j = get_j(spot);
	for(short a = 0; a < 9; a++)
	{
		if(a == i)
		{
			continue;
		}
		if(grid[a][j] == value || grid[a][j] == (value * -1))
		{
			return false;
		}
	}
	return true;
}

bool validBox(short spot, short value)
{
	short i = get_i(spot);
	short j = get_j(spot);
	short x = j / 3;
	short y = i / 3;
	x *= 3;
	y *= 3;
	for(short a = y; a < y + 3; a++)
	{
		if(a == i)
		{
			continue;
		}
		for(short b = x; b < x + 3; b++)
		{
			if(b == j)
			{
				continue;
			}
			if(grid[a][b] == value || grid[a][b] == (value * -1))
			{
				return false;
			}
		}
	}
	return true;
}

bool validValue(short spot, short value)
{
	return validRow(spot, value) && validCol(spot, value) && validBox(spot, value);
}

short try_next_value(short spot, short value)
{
	short i = get_i(spot);
	short j = get_j(spot);
	if(value >= -9)
	{	
		if(validValue(spot, value * -1))
		{
			grid[i][j] = value;
			return 1;
		}
		else if(!validValue(spot, value * -1) && value > -9)
		{
			grid[i][j] = value;
			return 0;
		}
	}
	grid[i][j] = 0;
	return -1;
}

void solve(short empty, short index)
{		
	if(empty > 0)
	{	
		iterations++;
		short spot = pos[index];
		short value = grid[get_i(spot)][get_j(spot)] - 1;		
		if(try_next_value(spot, value) == 1) //successful value
		{		
			solve(empty - 1, index + 1); 
		}
		else if(try_next_value(spot, value) == 0) //failed value, value > -9
		{
			solve(empty, index); 
		}
		else if(try_next_value(spot, value) == -1) //failed value, value = -9
		{
			solve(empty + 1, index - 1); 
		}		
	}
}

int main() 
{
	pos.resize(0);
	grid.resize(9);
	for(short i = 0; i < 9; i++)
	{
		grid[i].resize(9);
	}
	string input="";
	cout<<"Enter the puzzle by line, 9 numbers per line. Use '-' for blank spaces."<<endl<<endl;
	for(short i = 0; i < 9; i++)
	{
		getline(cin, input);
		if(input.length() != 9)
		{
			cout<<"ERROR - Invalid row length."<<endl<<endl;
			i--;
			continue;
		}
		for(short j = 0; j < 9; j++)
		{
			if(!valid(input))
			{
				cout<<"ERROR - Input contains invalid data."<<endl<<endl;
				i--;
				break;
			}
			grid[i][j] = convertData(input[j]);
		}
	}
	
	//calculate  of empty squares
	cerr<<"Calculate # of empty squares..."<<endl;
	short empty = 0;
	for(short i = 0; i < 9; i++)
	{
		for(short j = 0; j < 9; j++)
		{
			if(grid[i][j] == 0)
			{
				empty++;
			}
		}
	}
	
	//determine positions of empty squares	
	cerr<<"Find positions of empty squares..."<<endl;
	for(short i = 0; i < 9; i++)
	{
		for(short j = 0; j < 9; j++)
		{
			if(grid[i][j] == 0)
			{
				pos.push_back(createPos(i,j));
			}
		}
	}
	
	//start clock
	cerr<<"Start clock..."<<endl;
	clock_t start, stop;
	double t = 0.0;
	assert((start = clock()) != -1);
	
	//call solve function
	cerr<<"Call recursive solve function..."<<endl;
	solve(empty, 0);
	
	//stop clock	
	cerr<<"Stop clock..."<<endl;
	stop = clock();
	t = (double) (stop-start)/CLOCKS_PER_SEC;
	
	//generate solution file
	cerr<<"Writing solution to file..."<<endl;		
	printGrid();
	cerr<<"DONE."<<endl<<endl<<"Solution completed in "<<t<<" seconds."<<endl;
	cerr<<"Solution required "<<iterations<<" total iterations."<<endl<<endl;
	
    return 0;
}
