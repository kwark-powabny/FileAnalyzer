#pragma once 
#include <string>

struct FileInfo {
  std::string filename;
  unsigned long int lines;
  unsigned long  int words;
  unsigned long int letters;
  unsigned long int chars;
} ;