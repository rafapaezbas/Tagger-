#include <gtest/gtest.h>

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

TEST(ParseCommandLine, createCollectionFile) {
  char* args[6];
  args[0] = (char*) "tagger";
  args[1] = (char*) "-c";
  args[2] =(char*) "-d";
  args[3] =(char*) "/path/to/collection";
  args[4] =(char*) "-o";
  args[5] =(char*) "/path/to/output.json";
  EXPECT_EQ(parseCommandLine((sizeof(args)/sizeof(*args)), args), "CREATE_COLLECTION");
}

TEST(ParseCommandLine, not_C_or_T_Flags) {
  char* args[4];
  args[0] = (char*) "tagger";
  args[1] =(char*) "-d";
  args[2] =(char*) "/path/to/collection";
  args[3] =(char*) "-o";
  args[4] =(char*) "/path/to/output.json";
  EXPECT_EQ(parseCommandLine((sizeof(args)/sizeof(*args)), args), "NOT_EXPECTED");
}
