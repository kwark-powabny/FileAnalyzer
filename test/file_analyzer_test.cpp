#include "file_analyzer_globals.h"
#include <gtest/gtest.h>


namespace {


     // TEST(IsTextFileTest, TextFile){
     //    ASSERT_TRUE(condition);        
     // }

     TEST(GetFileInfoTest, EmptyFile){
        FileInfo file_info_e {"test files\\empty file.txt", 0, 0};
        FileInfo file_info_r = GetFileInfo("test files\\empty file.txt");
        EXPECT_EQ(file_info_e.lines, file_info_r.lines);
        EXPECT_EQ(file_info_e.words, file_info_r.words);
     }

     TEST(GetFileInfoTest, ShortEnglishText){
        FileInfo file_info_e {"test files\\short english text.txt", 4, 14};
        FileInfo file_info_r = GetFileInfo("test files\\short english text.txt");
        EXPECT_EQ(file_info_e.lines, file_info_r.lines);
        EXPECT_EQ(file_info_e.words, file_info_r.words);
     }

     TEST(GetFileInfoTest, ShortPolishText){
        FileInfo file_info_e {"test files\\what is lorem ipsum.txt", 16, 511};
        FileInfo file_info_r = GetFileInfo("test files\\what is lorem ipsum.txt");
        EXPECT_EQ(file_info_e.lines, file_info_r.lines);
        EXPECT_EQ(file_info_e.words, file_info_r.words);
     }

}