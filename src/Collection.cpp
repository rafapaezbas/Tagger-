#include "Collection.h"

void writeCollection(std::string path, std::vector<std::string> collection){
  writeFile(path,collection);
}

void createCollectionFromDir(std::string path, std::string outputPath){
  std::vector<std::string> files = getFilesFromDir(path);
  std::vector<std::string> collection;
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      cout << getMp3Info(*i).artist << endl;
      collection.push_back(getMp3Info(*i).artist);
    }
    ++i;
    writeCollection(outputPath,collection);
  }
}


