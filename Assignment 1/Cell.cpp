#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Cell.h"
#include "Exceptions.h"

using namespace std;


Cell::Cell(){
possibilities=NULL;
numPossibilities=0;
value=NULL;   
filledIn=false;
}


Cell::Cell(int value){
possibilities=NULL;
numPossibilities=-1;
this->value=NULL;
filledIn=true;
}

Cell::Cell(int* possibilities, int numPossibilities){
this->possibilities=possibilities;
this->numPossibilities=numPossibilities;
value=NULL;
filledIn=false;
}

Cell::Cell(const Cell& other){
possibilities=  new int[numPossibilities];
for(int i=0;i<numPossibilities;i++){
possibilities[i]=other.possibilities[i];
}
numPossibilities=other.numPossibilities;
value=NULL;
filledIn=other.filledIn;
}

Cell::~Cell(){
delete [] possibilities;
delete value;

}

bool Cell::isFilledIn(){
return filledIn;
}



void Cell::setValue(int value){
if(filledIn==true){
throw CellAlreadyFilledIn();
}



if(value ==1 || value ==2 || value ==3 || value ==4 || value ==5 || value ==6 || value ==7 || value ==8 ||value ==9 || value ==10 || value ==11 || value ==12 )
{Cell(value);
}else{throw IllegalCellValue(value);}/*********/


}

int Cell::getValue(){
    if (filledIn != true){

throw CellNotFilledIn();


    } else{
    return *value;}



}

int Cell::getNumPossibilities(){

    return numPossibilities;
}

int Cell::getPossibility(int index){
if (index>12 || index<0){throw IllegalIndex(); }
else{return possibilities[index];}

}


bool Cell::isPossible(int value){

    if(value !=1 || value !=2 || value !=3 || value !=4 || value !=5 || value !=6 || value !=7 || value !=8 ||value !=9 || value !=10 || value !=11 || value !=12 )
    {return true;}else{return false;}
}
 

void Cell::removePossibility(int value){

int NewArray[numPossibilities];

    for(int i=0;i<numPossibilities;i++){

        if(value==possibilities[i]){
int newIndex=numPossibilities-1;
for(int j=0;j<newIndex;j++){int x;
if(j!=i){ 
  NewArray[j]=possibilities[j];
}else{ x=j+1; 
    NewArray[j]=possibilities[x] ;    }
        }
    }
    }}












