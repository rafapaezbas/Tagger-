#include <string>
#include <vector>
#include <iostream>
#include <experimental/filesystem>
#include <taglib/fileref.h>
namespace fs = std::experimental::filesystem;
using namespace std;

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

int main(){
  vector<string> files;
  files = getFilesFromCurrentDir();
  auto i = files.begin();
  while(i != files.end()){
    if(i->find(".mp3") == string::npos){
      cout << *i << endl;
      i = files.erase(i);
    }else{
      tagFile(*i,"CCC");
      ++i;
    }
  }
}

