#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Metadata.h"
using namespace std;


/*adding constructor*/
Date::Date(int day,int month, int year)
:day(day), month(month), year(year){
    /*Body intentionally empty*/
}


inline bool isBefore(const Date& a, const Date& b) {
    if (a.year != b.year) 
        return a.year < b.year;
    if (a.month != b.month) 
        return a.month < b.month;
    return a.day < b.day;
}

inline string indent(int level) {
    string s;
    for (int i = 0; i < level; i++) 
        s += "  ";
    return s;
} 

 Metadata::Metadata()
     : size(0), description("Newfile/folder"), permission(full), dateCreated(10, 8, 2026), lastModified(10, 8, 2026)
 {/*Body intentionally empty*/ }

 Metadata::Metadata(int size, const string& description, Date dateCreated)
 : lastModified(dateCreated), permission(full), size(size), description(description), dateCreated(dateCreated)
 {/*Body intentionally empty*/ }

  int Metadata::getSize() const
  {return size;}

   const string& Metadata::getDescription() const
   {
    return description;
   }

Date Metadata::getDateCreated() const
{return dateCreated;}

Date Metadata::getDateModified() const
{
    return lastModified;
}

Permission Metadata::getPermission() const{
return permission;
}

bool Metadata::setSize(int size)
{
    if(size<0){return false;}
    else { this->size = size;
        return true;}
}

 void Metadata::setDescription(const string& description)
 { this->description = description;
}

void Metadata::setDateModified(Date lastModified)
{ if(isBefore(lastModified, dateCreated) || isBefore( lastModified,this->lastModified)){
 {/*Does nothing*/}}else{ this->lastModified = lastModified;}
    }

 void Metadata::setPermission(Permission permission) 
 {         
    this->permission=permission;
 }  

Metadata::~Metadata(){
/*no dynamic memory was allocated*/
}



