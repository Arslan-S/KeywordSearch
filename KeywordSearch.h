#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>

class KeywordSearch
{
    public:
        KeywordSearch(const std::string filename_with_keywords, const std::string filename_with_text);

        KeywordSearch() = delete;

        ~KeywordSearch() = default; //destructor
        KeywordSearch(const KeywordSearch & rhs) = default; //copy constructor
        KeywordSearch(KeywordSearch && rhs) = default; //move cunstructor
        KeywordSearch & operator=(const KeywordSearch & rhs) = default; //copy assignment
        KeywordSearch & operator=(KeywordSearch && rhs) = default; //move assignment

        bool KeywordFound(const std::string & keyword) const;
        int KeywordInLine(const std::string & keyword, int line_number) const;
        int TotalOccurrences(const std::string & keyword);
        friend std::ostream & operator<<(std::ostream & output, KeywordSearch & temp);

    private:
        std::unordered_map<std::string, int> my_map_;
        std::vector<std::vector<std::string>> keyword_line_; //my 2D vector to hold keywords in line
                                                             // the row is the line number starting with 
                                                             //an empty 0 line and the columns are the keywords
};