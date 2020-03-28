#include<string>

std::string parseCommandLine(int argc, char* argv[]);
std::string parseArg(char* argv[], int argc,std::string arg);
bool parseFlag(char* argv[], int argc,std::string arg);
