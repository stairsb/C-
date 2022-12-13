#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "assignment1.h"

using namespace std;

int main(int argc, char ** argv){
    int spellNum = 0;
    int num = 0;
    spellbook* book;
    spell* spellArr;
    ifstream spellb;
    
    spellb.open(argv[1]);
    
    checkInput(argc, argv[1]);
    spellNum = spellbNumber(argv[1]);
    book = create_spellbooks(spellNum);
    get_spellbook_data(book, spellNum, spellb);
    runProgram(num, spellArr, book, spellNum);
    spellb.close();
    
    delete_spellbook_data(book, spellNum);
    
    return 0;
}

