#include "Collection.h"

void writeCollection(std::string path, std::vector<std::string> collection){
  writeFile(path,collection);
}

std::string toJson(std::string artist, std::string album, std::string title, std::string year){
  std::replace( artist.begin(), artist.end(), '"', ' ');
  std::replace( album.begin(), album.end(), '"', ' ');
  std::replace( title.begin(), title.end(), '"', ' ');
  std::replace( year.begin(), year.end(), '"', ' ');
  std::string s = "{\"artist\":\"" + artist + "\",\"album\":\"" + album + "\",\"title\":\"" + title + "\",\"year\": \"" + year + "\"}";
  return s;
}

void createCollection(std::string path, std::string outputPath){
  std::vector<std::string> files = getFilesFromDir(path);
  std::vector<std::string> collection;
  int filesSize = files.size();
  cout << "Number of files in collection: " << files.size() << endl;
  cout << "Generation has started..." << endl;
  auto i = files.begin();
  collection.push_back("[");
    while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      Mp3Info mp3Info = getMp3Info(*i);
      std::string json = toJson(mp3Info.artist,mp3Info.album,mp3Info.title,mp3Info.year);
      if(files.end() - i == 1){
        collection.push_back(toJson(mp3Info.artist,mp3Info.album,mp3Info.title,mp3Info.year)); // Last one doesnt have comma
      }else{
        collection.push_back(toJson(mp3Info.artist,mp3Info.album,mp3Info.title,mp3Info.year) + ",");
      }
    }
    ++i;
  }
  collection.push_back("]");
  writeCollection(outputPath,collection);
}



