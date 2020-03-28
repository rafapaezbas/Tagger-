#include "Help.h"
#include "Tagger.h"
#include "Collection.h"

bool isHelp(char* argv[]){
  return string(argv[1]) == "--help";
}

bool isCollection(char* argv[],int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-c"){
      return true;
    }
  }
  return false;
}

string parseAlbum(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-l"){
      return argv[i+1];
    }
  }
  return "";
}

string parseArtist(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-a"){
      return argv[i+1];
    }
  }
  return "";
}

string parseDir(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-d"){
      return argv[i+1];
    }
  }
  return "";
}

string parseTitlePattern(char* argv[], int argc){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == "-p"){
      return argv[i+1];
    }
  }
  return "";
}


int main(int argc, char* argv[]){
  /*
  if(isHelp){
    help::printHelp();
    return 0;
  }
  */
  createCollectionFromDir(parseDir(argv,argc));
}
