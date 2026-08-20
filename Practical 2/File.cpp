#include "File.h"
#include "Metadata.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

File::File()
 :name("Untitled"), ext(txt), metadata(Metadata()), dataSize(0), data(NULL)
 {/*Body intentionally empty*/ }

File::File(const string& name, Extension ext, const string& description, Date dateCreated)
: name(name), ext(ext),dataSize(0), data(NULL)
{Metadata(0, description, dateCreated);
}


File::File(const File& other){
  name=other.name;
ext=other.ext;
metadata=other.metadata;
copyDataFrom(other);

}

void File::copyDataFrom(const File& other) 
{dataSize=other.dataSize;
if(other.data==NULL){this->data=NULL;
return;}
else{
data=new int[dataSize];
for(int i=0;i<dataSize;i++)
{ data[i]=1;}
}
}


 void File::clearFile(){
delete [] data;
data=NULL;
dataSize=0;
metadata.setSize(0);
 }

 void File::allocateFile(int dataSize){
delete [] data;
data=NULL;
data=new int[dataSize];
for(int i=0;i<dataSize;i++)
{ data[i]=1;}
this->dataSize = dataSize;   

 }


bool File::writeToFile(int size, Date lastModified)
 {
if(size==0 || size<0 || metadata.getPermission() == read)
{return false;} else{allocateFile(size);
  metadata.setSize(size*sizeof(int));
  metadata.setDateModified(lastModified);
return true;

}}

const string& File::getName() const
{
return name;
}

Extension File::getExt() const
{
return ext;

}

const Metadata& File::getMetadata() const{

return metadata;
}

int File::getDataSize() const{
return dataSize;
}

void File::setName(const string& name){
this->name=name;
}


void File::setExt(Extension ext){
this->ext=ext;
}

string File::fullName() const
{
return name+"." + extensionToString(ext);

}

 File::~File()
 {
delete [] data;
data=NULL;
 }


     














