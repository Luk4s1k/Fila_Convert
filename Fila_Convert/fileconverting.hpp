//
//  fileconverting.hpp
//  Fila_Convert
//
//  Created by Luca Mitrovich on 21/02/2020.
//  Copyright © 2020 Luka Mitrović. All rights reserved.
//

#ifndef fileconverting_hpp
#define fileconverting_hpp


#include <stdio.h>
#include <fstream>
#include <vector>
#include <map>
#include <string>

typedef std::map<std::string,std::vector<std::string>> IntervalMap;
typedef std::map<std::string, int> StrIntMap;
typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;


class ScryptFile {
public:
    std::string filename;
    std::string basicWordsListFile;
    std::vector<std::string> words;
    StrIntMap map;
    IntervalMap intervalmap;
    std::vector<std::string> signalWords;
    
    
public:
    //ScryptFile();
    ScryptFile(std::string filename);
    ScryptFile(std::string filename,std::string basicWordsListFile);

    void rewriteFile();
    void toAlphabetical();
    void removeSpaces();
    void removePaddings();
    void removeNumeration();
    void removeUnwantedWord(std::string Word);
    void splitFileintoWords();
    void removeBasicWordsFromFile();
    void toAlphabeticalInterval();
    void makeparsedFile();
    
    void toIntrervatFormatFile();
    void makeIntervalmap();
    
    void makeNonSortedHashOfWords();
    void createSignalWords(int positions);

//  void addsignalWord(std::string word);
};



#endif /* fileconverting_hpp */
