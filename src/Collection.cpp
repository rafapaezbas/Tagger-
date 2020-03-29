#include "Collection.h"

void writeCollection(std::string path, std::vector<std::string> collection){
  writeFile(path,collection);
}

std::string toJson(std::string artist, std::string album, std::string title, std::string year){
  std::string s = "{\"artist\":\"" + artist + "\",\"album\":\"" + album + "\",\"title\":\"" + title + "\",\"year\": \"" + year + "\"}";
  std::replace( s.begin(), s.end(), '"', ' ');
  return s;
}

void createCollectionFromDir(std::string path, std::string outputPath){
  std::vector<std::string> files = getFilesFromDir(path);
  std::vector<std::string> collection;
  int filesSize = files.size();
  auto i = files.begin();
  collection.push_back("[");
    while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      Mp3Info mp3Info = getMp3Info(*i);
      cout << getMp3Info(*i).artist << " " << i - files.begin() << endl;
      std::string json = toJson(mp3Info.artist,mp3Info.album,mp3Info.title,mp3Info.year);
      collection.push_back(toJson(mp3Info.artist,mp3Info.album,mp3Info.title,mp3Info.year) + ",");
      collection.push_back(json);
    }
    ++i;
  }
  collection.push_back("]");
  writeCollection(outputPath,collection);
}



