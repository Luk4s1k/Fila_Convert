//
//  main.cpp
//  Fila_Convert
//
//  Created by Luca Mitrovich on 04/02/2020.
//  Copyright © 2020 Luca Mitrović. All rights reserved.
//

// replace readFile with readfile


#include "fileconverting.hpp"
//#include "Interval.hpp"

 


int main() {
    ScryptFile intervalfile("inteval.txt","Word.txt");
    intervalfile.removeNumeration();
    
    intervalfile.toAlphabeticalInterval();
    intervalfile.splitFileintoWords();
    intervalfile.removePaddings();
    intervalfile.removeBasicWordsFromFile();
    intervalfile.toIntrervatFormatFile();
    ScryptFile parsedfile("input.txt","Word.txt");
    parsedfile.makeparsedFile();
    parsedfile.removeBasicWordsFromFile();
    parsedfile.makeNonSortedHashOfWords();
    parsedfile.createSignalWords(10);
    
    return 0;
}
