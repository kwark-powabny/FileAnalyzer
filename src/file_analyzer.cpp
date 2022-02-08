#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <filesystem>
#include <fstream>
#include "thread_pool.h"
#include "file_analyzer_globals.h" 
#include "file_info.h"

using namespace std;
 
mutex mu;
vector<string> file_names;
vector<FileInfo> files_info;
int threads_count;

// --------------------------------------------------
// Program takes a list of text files (".txt") recursively and analyzes:
// 		* how many files there are,
// 		* how many lines each file has,
// 		* how many words each file has,
// 		* how many letters each file has (currently only Latin). 
//
// As a parameter, the program takes the number of threads. 
// When the parameter is missing, the program runs as a single thread 
// --------------------------------------------------
int main(int argc, char* argv[])
{

	// ------- check parameters ------- 
    if (argc >= 2)
    {
		char *p; int num;
		errno = 0;
		threads_count = strtol(argv[1], &p, 10);
		    // Check for errors: e.g., the string does not represent an integer  or the integer is larger than int
		if (errno != 0 || *p != '\0' || threads_count > INT_MAX || threads_count < INT_MIN) {
			cout << "Wrong number of threads.\n";
			return 0;
		}
	} else {
		threads_count = 0; // no thread pool
	}

	// ------- get list of text files ------- 
	file_names = GetTextFilesRecursively();

	// ------- run analysis ------- 
	// hardware concurency
	if (threads_count < 0){  
		// TODO tp = thread_pool(); 
	
	// single-thread 
	} else if (threads_count == 0) {  
		for (auto &file_name: file_names) {
			files_info.push_back(GetFileInfo(file_name));
		}
	// multi-thread
	} else { 
		thread_pool tp(threads_count);
		for (auto &file_name: file_names)
		{
			tp.AddTask([&file_name]() mutable
			{
				lock_guard<mutex> lg(mu); 
				GetFileInfo(file_name);
			});
		}
		tp.TerminateThreadPool();
	}


	// ------- print out analysis -----------
	cout << "\n\n";
	const string separator = "-----------------------------------------------------------------------------------------------------------\n";
	cout << '\n';
	cout << separator;
	cout << "File name\n";
	cout << "\t\t\t\t\t\t\tLines\t\tWords\t\tLetters\n";
	cout << separator;

	FileInfo total{"", 0, 0, 0, 0};
	for (auto &file_info: files_info)
	{
		cout << file_info.filename << '\n';
		cout << "\t\t\t\t\t\t\t" << file_info.lines << "\t\t" << file_info.words << "\t\t" << file_info.letters << "\n\n";
		total.lines = total.lines + file_info.lines;
		total.words = total.words + file_info.words;
		total.letters = total.letters + file_info.letters;
	}
	cout << separator;
	cout << "\n Total number of files: " << file_names.size() << "\n";
	cout << " Total number of lines: " << total.lines << "\n";
	cout << " Total number of words: " << total.words << "\n";
	cout << " Total number of letters: " << total.letters << "\n";	
	cout << '\n';
} 