#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
const int row=30, col=30;          //declaring rows and columns constant for the the grid or board
int num_times;                    //its for number of times the program will run
void playGame();
void fileboard(char board[row][col]);
void boardCopy(char board[row][col],char  board_2[row][col]);
void stop(void);
void displayBoard(char board[row][col]);
int cellNeighbors(char board_2[row][col], int x, int y);
int main()
{
	int choice;
	do{
	
        do
        {
		
				cout << "Menu" << endl;
				cout << "(1) Play The Game of Life" << endl;
				cout << "(2) Quit the program" << endl;
				cout << "Please enter your choice." << endl;
				cout << "Either 1 or 2: ";
				cin  >> choice;
		}while(choice > 2 || choice < 1);            //check to only take input from given two options.
	
		switch(choice)
		{
			case 1 : 	playGame();
						break;
						
			case 2 :    stop();											
		}
	
	}while(choice != 2);
	
	
	
}
void playGame()
{
	char board[row][col];          //declaring the main board as character
	char board_2[row][col];      //declaring the second board for replicating the first
	int neighbors;            //variable for neighbors count
	fileboard(board);        //calling the function for reading the file
	
	
	for(int turns = 0; turns <num_times; ++turns)     //in this loop the program runs num_times,which we get from the file
	{
		
		displayBoard(board);               // it displays the board
		boardCopy(board,board_2);        //the board gets copied
	    
		
		
		for(int i = 1; i <=col; i++)        //in this nested loops the neighbors of copied board is checked, and orignal board is updated
		{
			for(int j = 1; j <= row; j++)
			{
				neighbors = cellNeighbors(board_2, i, j);     //function for checking the neighbours
				if (neighbors < 2)
					board[i][j] = '-';
				else if (neighbors > 3)
					board[i][j] = '-';
				else if (neighbors == 3)
					board[i][j] = '*';
				else if (board_2[i][j] == '*' && neighbors == 2)
					board[i][j] = '*';
				else
					board[i][j] = '-';
			}

		}
		
		system("cls");
		Sleep(0);	//can tweak it to be whatever
	}
	
	
	
}
void fileboard(char board[row][col])        //function for reading the file
{
	char fileName[101];
	int coord,x,y,times;
	fstream infile;

	cout << "Please make sure the file is in the same directory as the program." << endl;
	cout << "Please enter the name of the file: ";
	cin  >> fileName;
	infile.open(fileName, ios::in);
	infile >> times;  //for number of times the program runs
	infile >> coord;       //for number of coordinates

	for(int i =  0; i <coord; i++)
	{
		infile>>x;
		infile>>y;
		board[x][y]='*';
	}
num_times=times;       //num_times is equal to number of times the program will run
}
void boardCopy(char board[row][col],char board_2[row][col])  //board gets replicated 
{
	for(int i = 0; i < col; i++)
	{
		for(int j = 0; j < row; j++)
		{
			board_2[i][j] = board[i][j];
		}
	}
	
}
int cellNeighbors(char board_2[row][col], int x, int y)//function to check the neighbors of the board 2
{
	int neighbor;

	neighbor = 0;

	if(board_2[x-1][y-1] == '*')
		++neighbor;
	if(board_2[x][y-1] == '*')
		++neighbor;
	if(board_2[x-1][y] == '*')
		++neighbor;
	if(board_2[x-1][y+1] == '*')
		++neighbor;
	if(board_2[x+1][y-1] == '*')
		++neighbor;
	if(board_2[x+1][y] == '*')
		++neighbor;
	if(board_2[x][y+1] == '*')
		++neighbor;
	if(board_2[x+1][y+1] == '*')
		++neighbor;

return neighbor;
}
void displayBoard(char board[row][col])   //for displaying the board
{
	fstream file;
	file.open("output_file.txt",ios::app);
	int i, j;
	for(i = 1; i <= row ; i++)
	{
		
		for(j = 1; j <= col; j++)
		{
			if(board[i][j] != '*')
				board[i][j] = ' ';

			cout << board[i][j];
			file << board[i][j];
		}

		cout << endl;
		file<<endl;
	}
	

}
void stop(void)
{
	cout << "End of game of life" << endl;
}
