#include "Help.h"

void help::printHelp(){
  std::cout << "" << std::endl;
  std::cout << "Utility command line tool for mp3 files collection. Written by Rafa Paez with GNU General Public License v3.0" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Usage:" << std::endl;
  std::cout << "tagger [-c [-i input] -o output] -d directory [[-a|-b] -p pattern]" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "\t -c: creates json file with all the information of the mp3 files contained in directory." << std::endl;
  std::cout << "\t -o: output path of the create json file." << std::endl;
  std::cout << "\t -i: if cmus.log file specified, include such information that can be used for analysis on listening habits." << std::endl;
  std::cout << "\t -d: root path of the mp3 files collection" << std::endl;
  std::cout << "\t -a: change artist, year and album for files under root directory following pattern specified by option -p." << std::endl;
  std::cout << "\t -b: change title for files under root directory following pattern specified by option -p." << std::endl;
  std::cout << "" << std::endl;
}
