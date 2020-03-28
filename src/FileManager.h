#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <experimental/filesystem>
#include <vector>
#include <string>
#include <iostream>
namespace fs = std::experimental::filesystem;

std::vector<std::string> getFilesFromDir(std::string path);
std::string getFileNameFromPath(std::string path);

#endif
