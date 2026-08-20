#include "BasicMath.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
 int C=0; int rem;
 string storage="";
static string getIndent(int level) {
    if (level <= 0) {
        return "";
    }

    return "  " + getIndent(level - 1);
}

static string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}
string calculate_summation(int lower, int upper){
 try{

    if(lower>upper || upper-lower>10000){ InvalidRangeError five;
        five.message="Caught exception: Both numbers cannot be zero\n";
        throw five;}
 
    if(lower<=upper)
{C+=lower;
    storage+=getIndent(upper)+"calling summation("+intToString(C)+","+" "+intToString(upper)+")"+'\n';
calculate_summation(lower+1, upper);}
 else if(C>upper){return storage+="Base case: return 0";}

    }catch(InvalidRangeError range){return range.message;}
    return "";
}

string calculate_power(int base, int exponent){
try{string power="";int z=1;
if(exponent<0){NegativeExponentError four;
    four.message="Caught exception: Negative exponent not supported\n";
    throw four;}
if(exponent==0){return power; }
else 
if (exponent>0)  
{z=z*base;
    if (z==base){z=z*base;}
    
    power+=
    getIndent(exponent)+intToString(z)+'\n';
    calculate_power(base, exponent-1);
}}

catch(NegativeExponentError exp){
return  exp.message;}
return "";
}

string calculate_gcd(int a, int b){
if (a<0){a=a*(-1);}
 if(b<0){b=b*(-1);}
 if (b!=0){rem=a%b;
int temp=a;
a=b;
b=temp;
b=rem;}
storage=getIndent(a);
return "";

}













