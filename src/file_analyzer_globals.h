#pragma once

#include <filesystem>
#include <fstream>
#include "file_info.h"


// --------------------------------------------------
// Counts words in a string. 
// Words means parts separated by one or more space or tab (like in MS Word)
// --------------------------------------------------
int CountWords(std::string);


// --------------------------------------------------
// Counts letters in a string (only Latin at this moment)
// --------------------------------------------------
int CountLetters(std::string);

// --------------------------------------------------
// Checks if the file is a text file (".txt")
// --------------------------------------------------
bool IsTextFile(const std::filesystem::directory_entry &);

// --------------------------------------------------
// Gathers text file info: lines, words, letters
// --------------------------------------------------
FileInfo GetFileInfo(std::string const &);


// --------------------------------------------------
// Gets list (vector) of strings with paths to text files
// Paths are relative to the current directory
// --------------------------------------------------
std::vector<std::string> GetTextFilesRecursively();

