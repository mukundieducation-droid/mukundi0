#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Sudoku.h"
#include "Exceptions.h"
#include "Cell.h"
\
using namespace std;
Sudoku::Sudoku(){
  board=NULL;
numRows=4;
numCols=3;
n=numCols*numRows;

}
Sudoku::Sudoku(int numRows, int numCols){
this->numCols=numCols;
this->numRows=numRows;
if(n>15){throw SudokuTooBig();}

board= new Cell**[numRows];
for(int i=0;i<numRows;i++){
board[i]=new Cell*[numCols];
for(int j=0;j<numCols;j++)
{
 board[i][j]=new Cell[numCols];/*************/
}
}

}


Sudoku::Sudoku(string fileName){string reading;

ifstream infile;
infile.open(fileName);
infile>>numRows;
infile>>numCols;
n=numRows*numCols;
if (n>15){throw SudokuTooBig();}
string tester;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++){infile>>tester;
if(tester=="."){ ;}else {
{;}}



}

}}




Sudoku::Sudoku(const Sudoku& other){
board= new Cell**[numRows];
for(int i=0;i<numRows;i++){
board[i]=new Cell*[numCols];
for(int j=0;j<numCols;j++)
{
 board[i][j]=new Cell[numCols];
 for(int x=0;x<numRows;x++){
    board[numRows][numCols][numRows]=other.board[numRows][numCols][numRows];
    /*exchange j and i? should i create a default constructor*/
}

}
}
numRows=other.numRows;
numCols=other.numCols;
n=other.n;
}

Sudoku::~Sudoku(){
for(int i=0; i<numRows;i++){
for(int j=0;j<numCols;j++){
    delete [] board[i][j];


}delete []board[i];}delete []board;
}

void Sudoku::placeDigit(int row, int col, int value){

}

bool Sudoku:: isSolved(){;

}

bool Sudoku::onlyOnePossibility(bool verbose = false){


}

bool Sudoku::onlyPlace(bool verbose = false){

}

void Sudoku::guessDigit(bool verbose = false)
{

}

void Sudoku::resetFunctionCounts(){
 onlyOnePossibilityCount=0;
 onlyPlaceCount=0;
guessDigitCount=0;
solveCount=0;
}

void Sudoku::printFunctionCounts()
{
cout<<"Function call counts"<<endl;
cout<<"onlyOnePossibility:"<<" "<<onlyOnePossibilityCount<<endl;
cout<<"onlyPlace:"<<" "<<onlyPlaceCount<<endl;
cout<<"numGuessed:"<<" "<<guessDigitCount<<endl;
cout<<"solve:"<<" "<<endl;
}

  void Sudoku::solve (bool verbose = false){
solveCount++;


 }

void Sudoku::solveAndPrint(bool verbose = false){
resetFunctionCounts();
solve(verbose);
if (verbose==true){cout<<toStringVerbose;}else{cout<<toString;}
printFunctionCounts();
}






