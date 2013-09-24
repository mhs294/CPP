////////////////////////////////////////////////////////////////////// 
/// @file main.cpp 
/// @author Maximilian Schroeder
/// @brief "Simple Logic" Sudoku Solver
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>

using namespace std;

unsigned long iterations = 0;
vector<vector<string> > grid;
vector<vector<bool> > solved;
vector<vector<int> > solution;

string itoa(int a)
{
	stringstream s;
	s << a;
	return s.str();
}

bool valid(string data)
{
	for(int i = 0; i < 9; i++)
	{
		int x = (int)data[i];
		if(!((x >= 48 && x <= 57) || x == 45))
		{
			return false;
		}
	}
	return true;
}

int convertData(char a)
{
	int x = (int)a;
	if(x >= 49 && x <= 57)
	{
		return (x - 48);
	}
	return 0;
}

bool contains(string s, int a)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(convertData(s[i]) == a)
		{
			return true;
		}
	}
	return false;
}

void stripRow(int x, int y, int val)
{
	for(int i = 0; i < 9; i++)
	{
		string s = "";
		if(i == x)
		{
			continue;
		}
		string temp = grid[i][y];
		for(int j = 0; j < temp.length(); j++)
		{			
			if(convertData(temp[j]) != val)
			{
				s += temp[j];
			}
		}
		grid[i][y] = s;
	}
}

void stripCol(int x, int y, int val)
{
	for(int i = 0; i < 9; i++)
	{
		string s = "";
		if(i == y)
		{
			continue;
		}
		string temp = grid[x][i];
		for(int j = 0; j < temp.length(); j++)
		{			
			if(convertData(temp[j]) != val)
			{
				s += temp[j];
			}
		}
		grid[x][i] = s;
	}
}

void stripBox(int x, int y, int val)
{
	int a = x / 3;
	int b = y / 3;
	a *= 3;
	b *= 3;
	for(int i = a; i < (a + 3); i++)
	{
		for(int j = b; j < (b + 3); j++)
		{
			string s = "";
			if(i == x && j == y)
			{
				continue;
			}
			string temp = grid[i][j];
			for(int k = 0; k < temp.length(); k++)
			{
				if(convertData(temp[k]) != val)
				{
					s += temp[k];
				}
			}
			grid[i][j] = s;
		}
	}
}

void solve(int x, int y, int val)
{
	solved[x][y] = true;
	solution[x][y] = val * -1;
	grid[x][y] = itoa(val);
	stripRow(x,y,val);
	stripCol(x,y,val);
	stripBox(x,y,val);
}

void printGrid()
{
	ofstream outFile("smartSolution.txt");
	for(int i = 0; i < 9; i++)
	{
		if(i != 0)
		{
			if(i % 3 == 0)
			{
				for(int b = 0; b < 39; b++)
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
			for(int a = 0; a < 39; a++)
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
				for(int b = 0; b < 39; b++)
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
		for(int j = 0; j < 9; j++)
		{
			int x = solution[i][j];
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

bool soloRow(int y) //check row at index y
{
	for(int i = 0; i < 9; i++)
	{
		if(grid[i][y].length() == 1 && !solved[i][y])
		{
			int temp = atoi(grid[i][y].c_str());
			solve(i,y,temp);
			return true;			
		}
	}
	return false;
}

bool soloCol(int x) //check column at index x
{
	for(int i = 0; i < 9; i++)
	{
		if(grid[x][i].length() == 1 && !solved[x][i])
		{
			int temp = atoi(grid[x][i].c_str());
			solve(x,i,temp);
			return true;			
		}
	}
	return false;
}

bool soloBox(int n) //check box #n
{
	int x = n % 3;
	int y = n / 3;
	x *= 3;
	y *= 3;
	for(int i = x; i < (x + 3); i++)
	{
		for(int j = y; j < (y + 3); j++)
		{
			if(grid[i][j].length() == 1 && !solved[i][j])
			{
				int temp = atoi(grid[i][j].c_str());
				solve(i,j,temp);
				return true;			
			}
		}
	}
	return false;
}

bool singRow(int y, int val) //check row at index y for val
{
	int total = 0;
	int index = -1;
	for(int i = 0; i < 9; i++)
	{		
		if(contains(grid[i][y], val) && !solved[i][y])
		{
			total++;
			index = i;
		}
	}	
	if(total == 1)
	{
		solve(index,y,val);		
		return true;
	}
	return false;
}

bool singCol(int x, int val) //check row at index x for val
{
	int total = 0;
	int index = -1;
	for(int i = 0; i < 9; i++)
	{		
		if(contains(grid[x][i], val) && !solved[x][i])
		{
			total++;
			index = i;
		}
	}	
	if(total == 1)
	{
		solve(x,index,val);
		return true;
	}
	return false;
}

bool singBox(int n, int val) //check box #n for val
{
	int x = n % 3;
	int y = n / 3;
	x *= 3;
	y *= 3;
	int total = 0;
	int a = -1, b = -1;
	for(int i = x; i < (x + 3); i++)
	{
		for(int j = y; j < (y + 3); j++)
		{
			if(contains(grid[i][j], val) && !solved[i][j])
			{
				total++;
				a = i;
				b = j;
			}
		}
	}
	if(total == 1)
	{
		solve(a,b,val);
		return true;
	}
	return false;
}

int main()
{
	grid.resize(9);
	solved.resize(9);
	solution.resize(9);
	for(int i = 0; i < 9; i++)
	{
		grid[i].resize(9);
		solved[i].resize(9);
		solution[i].resize(9);
	}
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			grid[i][j] = "123456789";
			solved[i][j] = false;
			solution[i][j] = 0;
		}
	}
	string input="";
	cout<<"Enter the puzzle by line, 9 numbers per line. Use '-' for blank spaces."<<endl<<endl;
	for(int i = 0; i < 9; i++)
	{
		getline(cin, input);
		if(input.length() != 9)
		{
			cout<<"ERROR - Invalid row length."<<endl<<endl;
			i--;
			continue;
		}
		for(int j = 0; j < 9; j++)
		{
			if(!valid(input))
			{
				cout<<"ERROR - Input contains invalid data."<<endl<<endl;
				i--;
				break;
			}
			if(input[j] != '-')
			{
				solve(i,j,convertData(input[j]));
				solution[i][j] *= -1;
			}
		}
	}
	
	//calculate  of empty squares
	cerr<<"Calculate # of empty squares..."<<endl;
	int empty = 0;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(!solved[i][j])
			{
				empty++;
			}
		}
	}
	
	//start clock
	cerr<<endl<<"Start clock..."<<endl;
	clock_t start, stop;
	double t = 0.0;
	assert((start = clock()) != -1);
	
	//call iterative solve function
	cerr<<"Solving..."<<endl;
	
	while(empty > 0)
	{
		bool check = false;
		for(int i = 0; i < 9; i++)
		{
			if(soloRow(i)) //checks for cell in row with only one possible value
			{
				empty--;
				check = true;
			}
			else if(soloCol(i)) //check checks for cell in column with only one possible value
			{
				empty--;
				check = true;
			}
			else if(soloBox(i)) //checks for cell in box with only one possible value
			{
				empty--;
				check = true;
			}
			else
			{
				for(int j = 1; j <= 9; j++)
				{
					if(singRow(i,j)) //checks for value in row that appears in only one cell
					{
						empty--;
						check = true;
					}
					else if(singCol(i,j)) //checks for value in column that appears in only one cell
					{
						empty--;
						check = true;
					}
					else if(singBox(i,j)) //checks for value in box that appears in only one cell
					{
						empty--;
						check = true;
					}
					iterations++;
				}
			}
			iterations++;
		}
		if(!check) //ERROR - no solution was found in iteration
		{
			break;
		}
	}
	
	//stop clock	
	cerr<<"Stop clock..."<<endl;
	stop = clock();
	t = (double) (stop-start)/CLOCKS_PER_SEC;
	
	if(empty == 0)
	{
		//generate solution file
		cerr<<"Writing solution to file..."<<endl;		
		printGrid();
		cerr<<"DONE."<<endl<<endl<<"Solution completed in "<<t<<" seconds."<<endl;
		cerr<<"Solution required "<<iterations<<" total iterations."<<endl<<endl;
	}
	else
	{
		//error in solving
		cerr<<"ERROR - Program malfunction or puzzle not solvable."<<endl<<endl;
	}
	
	return 0;
}
