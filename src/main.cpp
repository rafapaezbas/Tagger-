#include "Help.h"
#include "Tagger.h"
#include "Collection.h"
#include <gtest/gtest.h>


bool isHelp(char* argv[]){
  return string(argv[1]) == "--help";
}

bool isTest(char* argv[]){
  return string(argv[1]) == "--test";
}

string parseArg(char* argv[], int argc,string arg){
  for(int i = 0; i < argc; i++){
    if(string(argv[i]) == arg){
      return argv[i+1];
    }
  }
  return "";
}

string parseCommandLine(int argc, char* argv[]){
  if(isHelp(argv)){
    return "HELP";
  }
  if(isCreateCollection(argc,argv)){
  }
  return "NOT_EXPECTED"
}


int main(int argc, char* argv[]){
  if(isTest(argv)){
    return RUN_ALL_TESTS();
  }
  createCollectionFromDir(parseArg(argv,argc,"-d"),parseArg(argv,argc,"-o"));
}

TEST(ParseCommandLine, showHelp) {
  char* args[2];
  args[0] = (char*) "tagger";
  args[1] =(char*) "--help";
     EXPECT_EQ(parseCommandLine((sizeof(args)/sizeof(*args)), args), "HELP");
}

TEST(ParseCommandLine, showHelpEvenWithUnexpected) {
  char* args[4];
  args[0] = (char*) "tagger";
  args[1] =(char*) "--help";
  args[2] =(char*) "--zz";
  args[3] =(char*) "-d";
  EXPECT_EQ(parseCommandLine((sizeof(args)/sizeof(*args)), args), "HELP");
}
