#ifndef TAGGER_H
#define TAGGER_H

#include <taglib/fileref.h>
#include "FileManager.h"

using namespace std;


struct Mp3Info{
  std::string artist;
  std::string album;
  std::string title;
  std::string year;
};

void tagFile(std::string filePath,string album,string artist,string titlePattern);
string calculateName(string filename,string pattern);
void updateTracksInformation(int argc, char* argv[]);
Mp3Info getMp3Info(string path);

#endif
