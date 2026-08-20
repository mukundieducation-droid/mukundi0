#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Sudoku.h"
#include "Exceptions.cpp"
#include "Cell.h"

using namespace std;

Sudoku::Sudoku(int numRows, int numCols){
this->numCols=numCols;
this->numRows=numRows;
if(n>15){throw SudokuTooBig();/*throw*/}
/*Shoulda do else?*/
board= new Cell**[numRows];
for(int i=0;i<numRows;i++){
board[i]=new Cell*[numCols];
for(int j=0;j<numCols;j++)
{
 board[i][j]=new Cell[numCols];/*exchange j and i? should icreate a default constructor*/
}
}
catch(string e){cout<<e;}
}


Sudoku::Sudoku(string fileName){string reading;
if (n>15){throw SudokuTooBig();/*throw*/}
ifstream infile;
infile.open(fileName);
infile>>numRows;
infile>>numCols;




catch(string e){cout<<e;}

}
