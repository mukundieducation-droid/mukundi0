#include "Folder.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Metadata.h"
#include "File.h"

using namespace std;

Folder::Folder()
:name("untitled"),metadata(Metadata()), files(NULL),subFolders(NULL)
{
numFiles = numFolders = totalFiles = 0;

}

Folder::Folder(const string& name,const string& description, Date dateCreated, File*& inputFiles, int count)
{
if (count>0 && inputFiles!=NULL){
totalFiles=count;
 files= new File*[totalFiles];
for(int i=0;i<totalFiles;i++)
{
files[i]=new File[numFiles];
for(int j=0;j<numFiles;j++){
int x=(i*totalFiles) +j ;
  files[i][j]=inputFiles[x];
}

}
subFolders=NULL;
numFiles = totalFiles = count;
}
else if(count==0 && inputFiles==NULL){
    subFolders=new Folder*[0];
    subFolders[0]=new Folder[0];
}
}


Folder::Folder(const Folder& other) :totalFiles(other.totalFiles)
{
name=other.name;
metadata=other.metadata;
numFiles=other.numFiles;
numFolders=other.numFolders;
totalFiles=other.totalFiles;
subFolders=other.subFolders;

subFolders= new Folder*[numFolders];
for(int a=0;a<numFiles;a++){
subFolders[a]=new Folder[numFiles];
for(int b=0;b<numFiles;b++){
  subFolders[a][b]=other.subFolders[a][b];}}

files=new File*[totalFiles];
for(int i=0;i<totalFiles;i++)
{
files[i]=new File[numFiles];
for(int j=0;j<numFiles;j++){
  files[i][j]=other.files[i][j];


}}}

const string& Folder::getName() const{
return name;

}

const Metadata& File::getMetadata() const{
return metadata;
}

 int Folder::getNumFiles() const
 {
return numFiles;
 }

int Folder::getNumFolders() const
{
    return numFolders;
}

int Folder::getTotalFiles() const{

return totalFiles;

}

void Folder::addFile(const File& file, Date lastModified){

for(int i=0;i<totalFiles;i++)
{
files[i]=new File[numFiles];
for(int j=0;j<numFiles;j++){
  files[i][j]=files[i+1][j+1];}



}
numFiles+1;totalFiles+1;
metadata.setDateModified(lastModified);}


void Folder::addFolder(const Folder& file, Date lastModified){
for(int a=0;a<numFiles;a++){
subFolders[a]=new Folder[numFiles];
for(int b=0;b<numFiles;b++){
  subFolders[a][b]=subFolders[a+1][b+1];}}
numFolders += 1;
  metadata.setDateModified(lastModified);
}

Folder::~Folder(){
for(int i=0;i<totalFiles;i++)
{
  delete [] files[i];
}
delete [] files;
files=NULL;

for(int j=0;j<numFiles;j++){

  delete[] subFolders;
}
delete [] subFolders;

subFolders=NULL;

}

