#include <iostream>
#define N 9
using namespace std;



// all needed functions for making a sudoku solver
bool isboardfull(int sudoku_board[][9]);
int *allpossibilities(int sudoku_board[][9],int row,int col);
void sudoku_solver(int sudoku_board[][9]);
void printboard(int sudoku_board[][9])
{
    for(int i=0;i<N;i++)
    {if(i==3||i==6)

        cout<<endl;

        for(int j=0;j<N;j++)
        {
            cout<<sudoku_board[i][j]<<"  ";
            if(j==2||j==5)
            cout<<"|  ";
        }

        cout<<endl;


    }
}

bool isboardfull(int sudoku_board[][9])//checks whether the board is full or not
{
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {
        if(sudoku_board[i][j]==0)
            return false;

    }
}
return true;
}

int *allpossibilities(int sudoku_board[][9],int row,int col)
{
    int *possibilities_array=new int[11]{0};
    //Now we check all the horizontal entries
    for(int i=0;i<N;i++)
    {
        if(sudoku_board[row][i]!=0)
          possibilities_array[sudoku_board[row][i]]=1;
    }
    //Now for vertical entries
    for(int j=0;j<N;j++)
    {
       if(sudoku_board[j][col]!=0)
          possibilities_array[sudoku_board[j][col]]=1;
    }

    //Now for calculating the start position of 3*3 square
    int rindex=0,cindex=0;
    if(row>=0&&row<=2)
        rindex=0;
    else if(row>=3&&row<=5)
        rindex=3;
    else
        rindex=6;
    if(col>=0&&col<=2)
        cindex=0;
    else if(col>=3&&col<=5)
        cindex=3;
    else
        cindex=6;

    for(int x=rindex;x<rindex+3;x++)
    {
        for(int y=cindex;y<cindex+3;y++)
        {
            if(sudoku_board[x][y]!=0)
                possibilities_array[sudoku_board[x][y]]=1;
        }
    }
    for(int z=1;z<=9;z++)
    {
        if(possibilities_array[z]==0)
            possibilities_array[z]=z;
        else


         possibilities_array[z]=0;

//for(int t=1;t<=9;t++)
  //  cout<<possibilities_array[t]<<" ";
//cout<<endl;
    }
 return possibilities_array;
 delete []possibilities_array;
}
void sudoku_solver(int sudoku_board[][9])
{
    if(isboardfull(sudoku_board))
     {
        cout<<" \n Sudoku board is fully solved";
        cout<<endl;
     printboard(sudoku_board);
        return;
    }
    int row=0,col=0;
    //finds first empty location
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(sudoku_board[i][j]==0)
            {
                row=i;
                col=j;
                break;
            }
        }
    }
    int *possibility=NULL;
   possibility=allpossibilities(sudoku_board,row,col);
    for(int z=1;z<=9;z++)
    {
        if(possibility[z]!=0)
            {
            sudoku_board[row][col]=possibility[z];
            //recursive call to fill next empty spaces
            sudoku_solver(sudoku_board);
            }
    }
    //does backtracking
    sudoku_board[row][col]=0;

}


int main()
{
    int sudoku_board[9][9]={{0, 0, 9, 0, 5, 0, 0, 0, 7},
                      {0, 8, 0, 0, 0, 7, 0, 0, 0},
                      {7, 0, 0, 9, 0, 0, 5, 0, 0},
                      {8, 0, 0, 0, 0, 6, 0, 4, 0},
                      {0, 0, 3, 8, 1, 0, 0, 0, 0},
                      {0, 2, 0, 0, 0, 0, 7, 0, 0},
                      {9, 0, 0, 6, 0, 0, 0, 0, 5},
                      {0, 0, 0, 0, 2, 3, 0, 6, 0},
                      {0, 1, 0, 0, 0, 0, 4, 0, 0}};
   // for(int i=0;i<N;i++)
    //{
      //  for(int j=0;j<N;j++)
        //{
          //  cin>>sudoku_board[i][j];
        //}
    //}
    printboard(sudoku_board);

    sudoku_solver(sudoku_board);


    return 0;
}
