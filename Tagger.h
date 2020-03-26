#ifndef TAGGER_H
#define TAGGER_H

#include <taglib/fileref.h>
#include "FileReader.h"

using namespace std;

void tagFile(std::string filePath,string album,string artist,string titlePattern);
string calculateName(string filename,string pattern);
void updateTracksInformation(int argc, char* argv[]);
TagLib::String getArtist(string path);

#endif
