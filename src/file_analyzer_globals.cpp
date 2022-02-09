#include "file_analyzer_globals.h" 

// --------------------------------------------------
int CountWords(std::string str)
{   
    int count = 0;
    bool last_was_space = true;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            if (!last_was_space) 
            {
                count++; // Only count when last char wasn't a space
                last_was_space = true;
            }
        }
        else
        {
            // Update flag (unless this char is a newline)
            if (str[i] != '\n') last_was_space = false;
        }
    }
    if (!last_was_space) ++count; // Count the last word if there wasn't a space before

    return count;
}

// --------------------------------------------------
int CountLetters(std::string str){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
			int num = str[i];
			if(( num > 63 && num < 91) || (num > 96 && num < 123)) // only latin letters
				count++;
    }
    return count;
}

// --------------------------------------------------

bool IsTextFile(const std::filesystem::directory_entry& dir_entry){
	    if (dir_entry.is_regular_file())
		{
            std::string path = dir_entry.path().string();
            std::string end_of_path = path.substr(path.size() - 4);  // only ".txt" files
            if (end_of_path == ".txt")
				return true;
			else
				return false; // not a ".txt" file
		} else 
			return false; // not a regular file
}

// --------------------------------------------------
FileInfo GetFileInfo(std::string const &path)
{

    FileInfo file_info{"", 0, 0, 0, 0};
    std::ifstream file(path);
    std::string  line;

    file_info.filename = path;

    while(std::getline(file, line))
    {
        file_info.lines++;
        file_info.words = file_info.words + CountWords(line);
        file_info.letters = file_info.letters + line.size();
    }
	return file_info;
}


// --------------------------------------------------
std::vector<std::string> GetTextFilesRecursively()
{

     std::vector<std::string> paths;
    for (const std::filesystem::directory_entry& dir_entry : std::filesystem::recursive_directory_iterator(".")) // TODO - podawać jako parametr zewnętrzny folder bazowy. W przypadku braku parametru, niech będzie to bieżący
    {
		if(IsTextFile(dir_entry)){
			paths.push_back(dir_entry.path().string());
		}
    }
    return paths;
}

