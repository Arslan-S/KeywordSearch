#include "KeywordSearch.h"

KeywordSearch::KeywordSearch(const std::string filename_with_keywords, const std::string filename_with_text)
{
    std::ifstream file;
    file.open(filename_with_keywords);
    if(file.fail()) //if the file doesn't open then exit
    {
        exit(1);
    }

    std::string str1;
    while(getline(file, str1))
    {
        std::string temp = "";
        for(const char & c : str1) //search through file by character
        {
            if(isalpha(c)) //check if it's an alphabet
            {
                temp += c; //add the alphabet to the string
            }
            else if(temp != "") //when the string is non-empty and and the next character is not an alphabet then insert into my map
            {
               my_map_.insert({temp, 0}); //insert the word into the map but don't add the occurrence
               temp = ""; //reset for another word
            }
        }
        if(temp != "") //when the string is non-empty and and the next character is not an alphabet then insert into map
        {
           my_map_.insert({temp, 0}); //insert the word into the map but don't add the occurrence
           temp = ""; //reset for another word
        }
    }
    file.close();

    file.open(filename_with_text);
    if(file.fail()) //if the file doesn't open then exit
    {
        exit(1);
    }

    std::vector<std::string> temp;
    keyword_line_.push_back(temp); //store nothing at line 0

    std::string str2;
    while(getline(file, str2))
    {
        std::string temp = "";
        std::vector<std::string> v1;

        for(const char & c : str2) //search through file by character
        {
            if(isalpha(c)) //check if it's an alphabet
            {
                temp += c; //add the alphabet to the string
            }
            else if(temp != "") //if there's a word in the string
            {
                if(my_map_.count(temp)) //if the string is already in the map
                {
                    my_map_.at(temp)++; //add occurrence
                }
                v1.push_back(temp);
                temp = ""; //reset for another word
            }
        }
        if(temp != "") //to get the last word
        {
            if(my_map_.count(temp)) //if the string is already in the map
            {
                my_map_.at(temp)++; //add occurrence
            }
            v1.push_back(temp);
            temp = ""; //reset for another word
        }
        keyword_line_.push_back(v1); //start from line 1
    }
    file.close();
}

bool KeywordSearch::KeywordFound(const std::string & keyword) const
{
    if(my_map_.count(keyword) > 0) //if it's actually in the map
    {
        if(my_map_.at(keyword) > 0) //if the occurrence is greater than 0
        {
            return true; //found
        }
    }
    return false; //not found
}

int KeywordSearch::KeywordInLine(const std::string & keyword, int line_number) const
{
    if(!KeywordFound(keyword)) //invalid keyword
    {
        return false;
    }
    if(line_number > keyword_line_.size() || line_number < 0) //invalid line number
    {
        return false;
    }

    int count = 0;
    for(auto i : keyword_line_[line_number]) //go to the line number row in my 2d vector
    {
        if(i == keyword) //if the keyword matches
        {
            count++; //add an occurrence
        }
    }
    return count;
}

int KeywordSearch::TotalOccurrences(const std::string & keyword)
{
    if(my_map_.count(keyword) > 0) //if the keyword is in the map
    {
        return my_map_.at(keyword); //returns value given the key    
    }
    return false;
}

std::ostream & operator<<(std::ostream & output, KeywordSearch & temp) //print all keywords and how many times they appeared in the map
{
    for(const auto i : temp.my_map_)
    {
        output << i.first << " : " << i.second << std::endl;
    }
    std::cout << std::endl;
    return output;
}