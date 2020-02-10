#include <string>
#include <vector>
#include <iostream>
#include <experimental/filesystem>
#include <taglib/fileref.h>
namespace fs = std::experimental::filesystem;
using namespace std;

string parseAlbum(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-a"){
      return argv[i+1];
    }
  }
  return "";
}

string parseTitle(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-t"){
      return argv[i+1];
    }
  }
  return "";
}


vector<string> getFilesFromCurrentDir(){
  vector<string> v;
  for (auto entry : fs::recursive_directory_iterator(fs::current_path())){
    v.push_back(entry.path().string());
  }
  return v;
}

void tagFile(string file,string album){
  TagLib::FileRef f(file.c_str());
  f.tag()->setAlbum(album);
  f.save();
}

string deriveName(string filename,string regex){
  string trackTitle = "";
  bool match = true;
  for ( int i=0, j=0; i < regex.length() ; i++ && match){
    switch(regex[i]){
    case '#':
      while(regex[i + 1] != filename[j]){
        trackTitle += filename[j];
        j++;
      }
      break;
    case '?':
      j++;
      break;
    default:
      if(regex[i] == filename[j]){
        j++;
      }else{
        trackTitle = "";
        match = false;
      }
    }
  }
  return trackTitle;
}

int main(int argc, char* argv[]){
  string album = parseAlbum(argv, argc);
  vector<string> files = getFilesFromCurrentDir();
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") != string::npos){ //If file path contains .mp3
      tagFile(*i, album);
    }
    ++i;
  }
}

