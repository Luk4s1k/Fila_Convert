//
//  main.cpp
//  Fila_Convert
//
//  Created by Luca Mitrovich on 04/02/2020.
//  Copyright © 2020 Luca Mitrović. All rights reserved.
//

// replace readFile with readfile


#include "fileconverting.hpp"

 


int main() {
    ScryptFile parsedfile("input.txt","Word.txt");
    parsedfile.makeparsedFile();
    parsedfile.removeBasicWordsFromFile();
    parsedfile.makeNonSortedHashOfWords();
    
    return 0;
}
