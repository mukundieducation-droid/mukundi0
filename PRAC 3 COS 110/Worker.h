#ifndef WORKER_H
#define WORKER_H


#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Worker{
 
    private:
static int idCounter;
int ID;
string name;
double salary;

   public:

   Worker(string name, double salary);
~Worker();/*There was no dynamic memory to free so?*/
Worker& operator=(string name);
Worker& operator=(double salary);
Worker& operator+=(int increase);
Worker& operator-=(int decrease);
bool operator==(const Worker& other);
bool operator!=(const Worker& other);
bool operator>(const Worker& other);
bool operator<(const Worker& other);
bool operator>=(const Worker& other);
bool operator<=(const Worker& other);
Worker& operator=(const Worker& other);
double operator()();
ostream& operator <<(ostream& os, const Worker& worker);/*problem here*/
};







#endif