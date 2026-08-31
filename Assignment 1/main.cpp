#include "Cell.h"
#include "Exceptions.h"
#include "Sudoku.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
   int test1=5; Cell delta;
Sudoku game;
   const Cell& test=delta;const Sudoku& test1=game;
   Cell();
Cell(test1);
int possible=12;
int possible1[possible]={1,2,5,4,7,9,6,4,2,3,3,2};
int* possible2=possible1;
Cell(possible2, possible);
Cell(test); 
delta.~Cell();
delta.isFilledIn();
delta.setValue(5);
delta.getValue();
delta.getNumPossibilities();
delta.getPossibility(test1);
delta.isPossible(test1);
int rows=4;
int columns=3;
string file="easySudoku";
Sudoku(rows,columns);
Sudoku(file);
Sudoku(test1);
game.~Sudoku();
game.resetFunctionCounts();
game.printFunctionCounts();
bool dare=false;
game.solve (dare);
game.solveAndPrint(dare);

    Sudoku easySudoku("easySudoku.txt");
    cout << easySudoku.toStringVerbose();
    easySudoku.solveAndPrint(true);
    Sudoku emptySudoku(3, 3);
    cout << emptySudoku.toStringVerbose();
    emptySudoku.solveAndPrint();
    return 0;
}