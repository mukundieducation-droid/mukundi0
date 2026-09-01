#include "Worker.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

   Worker::Worker(string name, double salary)
   {
this->name=name;
this->salary=salary;
ID=idCounter;
idCounter++;
/*where should i initialise the ID counter*/
   }
