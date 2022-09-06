#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "KeywordSearch.h"
using namespace std;


int main()
{
    KeywordSearch test{"keyword.txt","text.txt"};
    
    //This will print all keywords and how many times they appear in the text
    std::cout << test;
    
    std::cout << "--------------------------\n";

    //This will print the number of times the keyword was found in the text (ENTER YOUR KEYWORD IN THE STRING BELOW)
    std::cout << "Total Occurrences: " << test.TotalOccurrences("ENTER KEYWORD") << "\n";

    //This will print 0 or 1 depending on whether your keyword was in the text or not (ENTER YOUR KEYWORD IN THE STRING BELOW)
    std::cout << test.KeywordFound("ENTER KEYWORD") << "\n";

    //This will print the amount of times the keyword was found in the specified line (ENTER KEYWORD AND LINE NUMBER BELOW)
    std::cout << test.KeywordInLine("ENTER KEYWORD",0) << "\n";
}