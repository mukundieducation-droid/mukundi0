#include "Permutations.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
  
int x=0;
   int j=0;
   int i=-1;
   int combinations=0;
   int prefix;
static string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}
int helper(int base1, int exponent1){
if (exponent1==0){return 1;}
else{return base1*helper(base1,exponent1-1);}
}
void validateInput(char set[], int k, int n){
  
if (set == NULL){
    NullPointerError one;
    one.message="Caught exception: Set cnnot be empty\n";
    throw one;}

    if (n<=0){
         EmptySetError two;
         two.message="Caught exception: Set cannot be empty\n";
         throw two;
    }

    if (k<0){
        NegativeKError three;
        three.message="Caught exception: Set pointer is Null\n";
        throw three;
    }
}
string helper2(char set[],int k,int n){
string permutations="";
int cat=helper(n,k);
int sizer = sizeof(set)/sizeof(set[0]);
if(cat<=0){return permutations+'\n'
    +"Total_combinations:" +" "+intToString(combinations)+'\n'
    +"Max_recursion_depth:"+" "+intToString(k)+'\n'+"All_prefixes:"+" "+intToString(prefix);}
if(x!=k && i!=sizer){
permutations+=set[i];combinations++;prefix++;
x++;i++;}
else if(x==k && i!=sizer){permutations+=set[i]+'\n';
    x=0;j++;i=0;i=j; combinations++;                 
i++;}        
else if(x==k && i==sizer){permutations+=set[i];combinations++;}
return permutations+helper2(set,k,cat-1);
}
string printAllKLength(char set[], int k, int n)
{  
    string permutations="";
 struct Statistics {
    int totalCombinations=0;
    int maxDepth=0;
    int allPrefixes=0;};
    Statistics combinations;
    Statistics depth;
    Statistics prefix;
    
    try {
        validateInput( set, k, n);
    }

catch(NullPointerError XE)
{return XE.message;} 
catch(EmptySetError y)
{return y.message;}
catch(NegativeKError z)
{return z.message;}

return helper2(set, k, n);


}

  




