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

TEST(ParseCommandLine,tagAlbum) {
  char* args[6];
  args[0] = (char*) "tagger";
  args[1] =(char*) "-a";
  args[2] =(char*) "-d";
  args[3] =(char*) "/path/to/dir";
  args[4] =(char*) "-p";
  args[5] =(char*) "?? - ##";
  EXPECT_EQ(parseCommandLine((sizeof(args)/sizeof(*args)), args), "TAG_ALBUM");
}

TEST(ParseCommandLine,tagAlbumWithoutDir) {
  char* args[5];
  args[0] = (char*) "tagger";
  args[1] =(char*) "-a";
  args[2] =(char*) "-c";
  args[3] =(char*) "/path/to/dir";
  args[4] =(char*) "-p";
  args[4] =(char*) "?? - ##";
  EXPECT_EQ(parseCommandLine((sizeof(args)/sizeof(*args)), args), "NOT_EXPECTED");
}

TEST(ParseCommandLine,tagAlbumWithoutPattern) {
  char* args[4];
  args[0] = (char*) "tagger";
  args[1] =(char*) "-a";
  args[2] =(char*) "-d";
  args[3] =(char*) "/path/to/dir";
  EXPECT_EQ(parseCommandLine((sizeof(args)/sizeof(*args)), args), "NOT_EXPECTED");
}
