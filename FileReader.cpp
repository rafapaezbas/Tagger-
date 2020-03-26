#include "FileReader.h"

std::vector<std::string> getFilesFromDir(std::string path){
  std::vector<std::string> v;
  for (auto entry : fs::recursive_directory_iterator(path)){
    v.push_back(entry.path().string());
  }
  return v;
}

std::string getFileNameFromPath(std::string path){
  size_t found = path.find_last_of("/");
  return path.substr(found+1);
}
