#include "CommandLineParser.h"

std::string parseArg(char* argv[], int argc,std::string arg){
  for(int i = 0; i < argc; i++){
    if(std::string(argv[i]) == arg){
      return argv[i+1];
    }
  }
  return "";
}

bool parseFlag(char* argv[], int argc,std::string arg){
  for(int i = 0; i < argc; i++){
    if(std::string(argv[i]) == arg){
      return true;
    }
  }
  return false;
}

bool isHelp(char* argv[]){
  return std::string(argv[1]) == "--help";
}

bool isCreateCollection(int argc,char* argv[]){
  bool isCollection = parseFlag(argv,argc,"-c");
  std::string dir = parseArg(argv,argc,"-d");
  std::string output = parseArg(argv,argc,"-o");
  if(!isCollection){
    return false;
  }
  if(dir.empty()){
    return false;
  }
  if(output.empty()){
    return false;
  }

  return true;
}

bool isTagCollection(int argc,char* argv[]){
  bool isTagCollection = parseFlag(argv,argc,"-t");
  std::string dir = parseArg(argv,argc,"-d");
  std::string pattern = parseArg(argv,argc,"-p");
  if(!isTagCollection){
    return false;
  }
  if(dir.empty()){
    return false;
  }
  if(pattern.empty()){
    return false;
  }

  return true;
}

bool isTagAlbum(int argc,char* argv[]){
  bool isTagAlbum = parseFlag(argv,argc,"-a");
  std::string dir = parseArg(argv,argc,"-d");
  std::string pattern = parseArg(argv,argc,"-p");
  if(!isTagAlbum){
    return false;
  }
  if(dir.empty()){
    return false;
  }
  if(pattern.empty()){
    return false;
  }

  return true;
}

std::string parseCommandLine(int argc, char* argv[]){
  if(isHelp(argv)){
    return "HELP";
  }
  if(isCreateCollection(argc,argv)){
    return "CREATE_COLLECTION";
  }
  if(isTagCollection(argc,argv)){
    return "TAG_COLLECTION";
  }
  if(isTagAlbum(argc,argv)){
    return "TAG_ALBUM";
  }
  return "NOT_EXPECTED";
}
