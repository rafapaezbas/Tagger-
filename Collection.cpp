#include "Collection.h"

struct Album {
  int year;
  std::string name;
  std::vector<std::string> tracks;
};

struct Artist {
  std::string name;
  std::vector<Album> albums;
};

struct Mp3File{
  std::string artist;
  std::string album;
  std::string title;
  std::string year;
};

void createCollectionFromDir(std::string path){
  std::vector<std::string> files = getFilesFromDir(path);
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      cout << getArtist(*i) << endl;
    }
    ++i;
  }
}

bool collectionContainsArtist(std::vector<Artist> collection,std::string artist){
  auto i = collection.begin();
  while(i != collection.end()){
    if(i->name == artist){
      return true;
    }
  }
  return false;
}
