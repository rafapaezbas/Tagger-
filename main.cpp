#include <string>
#include <vector>
#include <iostream>
#include <experimental/filesystem>
#include <taglib/fileref.h>
namespace fs = std::experimental::filesystem;
using namespace std;

//given a full file path, extract the filename
string getFileNameFromPath(string path){
  size_t found = path.find_last_of("/");
  return path.substr(found+1);
  
}

string parseAlbum(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-a"){
      return argv[i+1];
    }
  }
  return "";
}

string parseTitlePattern(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-t"){
      return argv[i+1];
    }
  }
  return "";
}


vector<string> getFilesFromDir(string path){
  vector<string> v;
  for (auto entry : fs::recursive_directory_iterator(path)){
    v.push_back(entry.path().string());
  }
  return v;
}

/*
  This function is in charge of "calculating" the song title that we want in the tag. We use a pattern to determine how to derive the song title form the file name. The idea is every files name follow a pattern that includes the track name we want. We only have two special chars. -#- is the name we want, ? represents any sigle char. So foe example -01 Last of the Mohicans.mp3- and -??#.mp3-, would return -Last of the Mohicans- which is the name we want for the tag.
*/
string calculateName(string filename,string pattern){
  string trackTitle = "";
  bool match = true;
  for ( int i=0, j=0; i < pattern.length() ; i++ && match){
    switch(pattern[i]){
    case '#':
      while(pattern[i + 1] != filename[j]){
        trackTitle += filename[j];
        j++;
      }
      break;
    case '?':
      j++;
      break;
    default:
      if(pattern[i] == filename[j]){
        j++;
      }else{
        trackTitle = "";
        match = false;
      }
    }
  }
  return trackTitle;
}

void tagFile(string filePath,string album,string titlePattern){
  TagLib::FileRef f(filePath.c_str());
  f.tag()->setAlbum(album);
  f.tag()->setTitle(calculateName(getFileNameFromPath(filePath),titlePattern));
  f.save();
}


int main(int argc, char* argv[]){
  //The path must be a dir, where we will take every mp3 file and tag it with name, album and year
  string path = argv[1];
  string album = parseAlbum(argv, argc);
  string tittlePattern = parseTitlePattern(argv, argc);
  vector<string> files = getFilesFromDir(path);
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      tagFile(*i, album, tittlePattern);
    }
    ++i;
  }
}
