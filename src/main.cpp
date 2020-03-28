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
  createCollectionFromDir(parseArg(argv,argc,"-d"),parseArg(argv,argc,"-o"));
}

