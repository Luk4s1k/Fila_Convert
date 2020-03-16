//
//  fileconverting.cpp
//  Fila_Convert
//
//  Created by Luca Mitrovich on 21/02/2020.
//  Copyright © 2020 Luca Mitrović. All rights reserved.
//

#include "fileconverting.hpp"
ScryptFile::ScryptFile(std::string filename)
:filename(filename){
}

ScryptFile::ScryptFile(std::string filename,std::string basicWordsListFile)
:filename(filename),basicWordsListFile(basicWordsListFile){
    std::ifstream readFile(basicWordsListFile);
       std::string word;
       while (std::getline(readFile, word))
           words.push_back(word);
       readFile.close();
}
void ScryptFile::rewriteFile()
{
    std::ifstream readFile ("tmp.txt", std::ifstream::in);
    std::ofstream writeFile (this->filename, std::ofstream::out);
    std::string str;
    
    while(readFile){
        getline(readFile,str);
        writeFile << str << std::endl;
    }
    readFile.close();
    writeFile.close();
}

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}


static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

void ScryptFile::removeSpaces(){
    std::ifstream readFile (this->filename, std::ifstream::in);
    std::ofstream tmpFile ("tmp.txt", std::ofstream::out);
    std::string str;
    
    while(readFile){
        getline(readFile, str);
        trim(str);
        tmpFile << str;
        tmpFile << std::endl;
    }
    readFile.close();
    tmpFile.close();
    rewriteFile();
    
}

void ScryptFile::toAlphabetical(){
    std::ifstream readFile (this->filename, std::ifstream::in);
    std::ofstream tmpFile ("tmp.txt", std::ofstream::out);

    std::string str;
    while(readFile){
        getline(readFile,str);
        for(int i = 0; i < str.size(); ++i)
        {
            if (!((str[i] >= 'a' && str[i]<='z') || (str[i] >= 'A' && str[i]<='Z'))){
                str[i] = ' ';
            }
        }
        tmpFile << str;
        tmpFile << std::endl;
    }
    
    readFile.close();
    tmpFile.close();
    rewriteFile();
}

void ScryptFile::removePaddings()
{
    std::ifstream readFile(this->filename, std::ifstream::in);
    std::ofstream tmpFile("tmp.txt", std::ofstream::out);


    std::string str;
    while (readFile){
        std::getline(readFile, str);
        if (!str.empty()){
            tmpFile << str;
            tmpFile << std::endl;
        }
    }
    readFile.close();
    tmpFile.close();
    rewriteFile();
}

void ScryptFile::removeNumeration(){
    std::ifstream readFile (this->filename, std::ifstream::in);
    std::ofstream tmpFile ("tmp.txt", std::ofstream::out);

    int lineInt = 1;
    std::string str;
    while (readFile){
        std::getline(readFile, str);
        if (str.compare(std::to_string(lineInt))){
            tmpFile << str;
            tmpFile << std::endl;
        }
        else lineInt++;
    }
    readFile.close();
    tmpFile.close();
    rewriteFile();
}

void ScryptFile::splitFileintoWords(){
    std::ifstream readFile (this->filename, std::ifstream::in);
    std::ofstream tmpFile ("tmp.txt", std::ofstream::out);
    
    std::string token;
    while (std::getline(readFile, token, ' ')){
        tmpFile << token;
        tmpFile << std::endl;
    }
    readFile.close();
    tmpFile.close();
    rewriteFile();
}

void ScryptFile::removeUnwantedWord(std::string Word){
    std::ifstream readFile (this->filename, std::ifstream::in);
    std::ofstream tmpFile ("tmp.txt", std::ofstream::out);

    std::string str;
        while (readFile){
            getline(readFile,str);
            if(str.compare(Word))
                tmpFile << str;//to upper
                tmpFile << std::endl;
        }
    rewriteFile();
    
    readFile.close();
    tmpFile.close();
}

void ScryptFile::makeparsedFile(){
    this->removeNumeration();
    this->toAlphabetical();
    this->removeSpaces();
    this->splitFileintoWords();
    this->removePaddings();
}

void ScryptFile::removeBasicWordsFromFile(){
    for (std::string word : words)
        removeUnwantedWord(word);
    removePaddings();
}
void ScryptFile::makeNonSortedHashOfWords(){
    std::ifstream readFile(this->filename ,std::ifstream::in);
    std::string word;

    while (readFile >> word) {
       ++map[word];
    }
}

static bool value_comparer(StrIntMap::value_type &it1, StrIntMap::value_type &it2)
{
return it1.second < it2.second;
}

void ScryptFile::createSignalWords(int positions){
    
    for (int i = 1; i < positions ; i++){
        StrIntMap::iterator it = std::max_element(map.begin(), map.end(),
        value_comparer);
        signalWords.push_back(it->first);
        map.erase(it);
    }
}

//void ScryptFile::addWordtoList(std::string word){
//    std::ofstream inputFile (this->filename, std::ofstream::out);
//    inputFile << word;
//    inputFile.close();
//}
//
