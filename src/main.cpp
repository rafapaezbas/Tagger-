#include "Help.h"
#include "Tagger.h"
#include "Collection.h"
#include "CommandLineParser.h"
#include "./test/Test.cpp"

bool isTest(char* argv[]){
  return string(argv[1]) == "--test";
}

int main(int argc, char* argv[]){
  if(isTest(argv)){
    return RUN_ALL_TESTS();
  }
  string action = parseCommandLine(argc,argv);
  if(action == "HELP")
    help::printHelp();
  else if(action == "CREATE_COLLECTION")
    createCollectionFromDir(parseArg(argv,argc,"-d"),parseArg(argv,argc,"-o"));
  else if(action == "TAG_ALBUM")
    tagAlbum(parseArg(argv,argc,"-d"),parseArg(argv,argc,"-p"));
  else
    help::printHelp();
}

