#include "file_analyzer_globals.h"
#include <gtest/gtest.h>


namespace {

   // Testy modułu [file_analyzer_globals]: funkcja [CountWords]

   TEST(CountWordsTest, EnglishTextWithSpecialChars){
      EXPECT_EQ(16, CountWords("\n The text contains  double space, commas, some 2 numbers. Tab\t and \nnew line. It's 16 words   "));
   }

   TEST(CountWordsTest, PolishTextWithSpecialChars){
      EXPECT_EQ(19, CountWords("\n Ten tekst zawiera  podwójne spacje, przecinki, jakieś 2 liczby. Tab\t and \nnew line. To 19 słów: zażółć gęślą jaźń   "));
   }


   // Testy modułu [file_analyzer_globals]: funkcja [IsTextFile]

   TEST(IsTextFileTest, TxtExtension){
      ASSERT_TRUE(IsTextFile(std::filesystem::directory_entry(std::filesystem::path("test files\\level_1_2\\level2_1\\plik2_1_1.txt"))));         
   }

   TEST(IsTextFileTest, NoTxtExtension){
      ASSERT_FALSE(IsTextFile(std::filesystem::directory_entry(std::filesystem::path("test files\\no text file"))));         
   }

   TEST(IsTextFileTest, BinaryFile){
      ASSERT_FALSE(IsTextFile(std::filesystem::directory_entry(std::filesystem::path("test files\\some_binary.bin"))));         
   }


   // Testy modułu [file_analyzer_globals]: funkcja [GetFileInfo]

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