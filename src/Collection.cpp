#include "Collection.h"

void createCollectionFromDir(std::string path){
  std::vector<std::string> files = getFilesFromDir(path);
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      cout << getMp3Info(*i).artist << endl;
    }
    ++i;
  }
}
