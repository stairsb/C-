#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "assignment1.h"
using namespace std;

int checkInput(int argc, string valFile){
    fstream file;
    if(argc != 2){
        cout << "Error: Enter a valid file name " << endl;
        exit(0);
    }
    else if(valFile != "spellbooks.txt"){
        cout << "Error: the file does not exist " << endl;
        exit(0);
    }
    const char * check = valFile.c_str();
    file.open(check, fstream::in);
    if(!file.is_open()){
        cout << "Could not open the file " << endl;
    }
    else{
        cout << "The file opened " << endl;
    }

    return 0;
}

void runProgram(int num, spell* spellArr, spellbook* bookArr, int bookNum){
    num = 0;
    spellbook* book;
    chooseOption(num, spellArr, bookArr, bookNum);
}
void chooseOption(int num, spell* spellArr, spellbook* bookArr, int bookNum){
    num = 0;
    do{
        cout << "Which option would you like to choose? " << endl;
        cout << "Sort spellbooks by number of pages (Press 1): " << endl;
        cout << "Group spells by their effect (Press2): " << endl;
        cout << "Sort spellbooks by average success rate (Press 3): " << endl;
        cout << "Quit (Press 4)" << endl;
        cin >> num;

        if(num >= 1 && num <= 3){
            options(num, spellArr, bookArr, bookNum);
        }
        else if(num != 4){
            cout << "ERROR: You did not enter a number for one of the options" << endl;
            chooseOption(num, spellArr, bookArr, bookNum);
        }
        else{
        cout << "Bye " << endl;
        }
    }
    while(num !=4);
}

int seeInfo(int var){
    var = 0;
    do{
        cout << "How would you like the information to be displayed? " << endl;
        cout << "Print to screen (Press 1) " << endl;
        cout << "Print to file (Press 2 " << endl;
        cin >> var;
        if(var != 1 && var != 2){
            cout << "Error: None of the options were entered " << endl;
        }
    }
    while(var <= 0 && var >= 3);

    return var;
}
void printFile(ofstream& fout){
    cout << "Enter the file name you would like to print to" << endl;
    string file;
    cin >> file;
    fout.open(file.c_str(), ios::app);
    if(!fout.is_open()) {
        cout << "Error: could not open file " << endl;
    
    }
}
void sortPaiges(int num, spellbook* bookArr, int bookNum){
    spellbook swap;

    for(int a = 0; a < bookNum - 1; a++){
        for(int i = 0; i < bookNum - a - 1; i++){
            if(bookArr[i].num_pages > bookArr[i+1].num_pages){
                swap = bookArr[i + 1];
                bookArr[i + 1] = bookArr[i];
                bookArr[i] = swap;
            }
        }
    }
    PrintPages(num, bookArr, bookNum);
    
}

void PrintPages(int num, spellbook *bookArr, int bookNum){
    int decide = 1;
    decide = seeInfo(num);

    
        if (decide == 1){
            for(int i = 0; i < bookNum; i++){
              cout << bookArr[i].title << " ";
              cout << bookArr[i].num_pages << endl;
            }
        }
    
    else{
            ofstream file;
            printFile(file);
            for (int i = 0; i < bookNum; i++){
                file << bookArr[i].title << " " << bookArr[i].num_pages << endl;
            }
                file.close();
                cout << "Append requested information to file " << endl; 
        
        }

}
//this function was long but due to 5 different spells it was hard to break up
void sortEffect(int num, spellbook* bookArr, int bookNum){
    int revolve = 0;
    for(int a = 0; a < bookNum; a++){
        revolve += bookArr[a].num_spells;
    }
    spell* spellArr = new spell[revolve];
        int place = 0;
        for(int i = 1; i <= 5; i++){
            for(int j = 0; j < bookNum; j++){
                for(int l = 0; l < bookArr[j].num_spells; l++){
                    if(i == 1 && bookArr[j].s[l].effect.compare("bubble") == 0){
                        spellArr[place] = bookArr[j].s[l];
                        place += 1;
                    
                    }
                    else if(i == 2 && bookArr[j].s[l].effect.compare("memory_loss") == 0){
                        spellArr[place] = bookArr[j].s[l];
                        place += 1;
                    }
                    else if(i == 3 && bookArr[j].s[l].effect.compare("fire") == 0){
                        spellArr[place] = bookArr[j].s[l];
                        place += 1;
                    }
                    else if(i == 4 && bookArr[j].s[l].effect.compare("poison") == 0){
                        spellArr[place] = bookArr[j].s[l];
                        place += 1;
                    }
                    else if(i == 5 && bookArr[j].s[l].effect.compare("death") == 0){
                        spellArr[place] = bookArr[j].s[l];
                        place += 1;
                    }
                }
            }
        }
    printEffect(num, spellArr, bookArr, revolve);
    delete [] spellArr;
}

void printEffect(int num, spell* spellArr, spellbook* bookArr, int spellNum){
    int sure =0;
    sure = seeInfo(num);
    for(int j = 0; j < spellNum; j++){
       
        if(sure == 1){
            cout << spellArr[j].name << " ";
            cout << spellArr[j].effect << endl;
        }
        else if(sure == 2){
            ofstream file;
            printFile(file);
            for (int i = 0; i < spellNum; i++){
                for(int j = 0; j < bookArr[i].num_spells; j++){
                file << bookArr[i].s[j].effect << " " << bookArr[i].s[j].name << endl;
                }
            }
                file.close();
                cout << "Append requested information to file " << endl; 
        
        }
    } 
    cout << " " << endl; 
}

void options(int num, spell* spellArr, spellbook* bookArr, int bookNum){
    if(num == 1) {
        sortPaiges(num, bookArr, bookNum);
    }
    else if(num == 2){
    
        sortEffect(num, bookArr, bookNum);
    }
    else if(num == 3){
    
    }
    else{
        exit(0);
    }
}
//creats a dynamic array for the spellbook struct
spellbook* create_spellbooks(int bookNum){
    spellbook* bookarr = new spellbook[bookNum];
    return bookarr;
}

spell* create_spells(int spellNum){
    spell* spellArr = new spell[spellNum];
    return spellArr;
}

//gets the number of spell books
int spellbNumber(char* inputFile){
    int spellbn;
    fstream booksData;

    booksData.open(inputFile, fstream::in | fstream::app);

    booksData >> spellbn;
    booksData.close();
    
    return spellbn;
}


// reads the data from the text file and puts it in a struct
void get_spellbook_data(spellbook* bookarr, int booknum, ifstream &bookData){
   string getInfo;
   getline(bookData, getInfo);

    for(int i =0; i < booknum; i++){
    
        bookData >> bookarr[i].title;
        bookData >> bookarr[i].author;
        bookData >> bookarr[i].num_pages;
        bookData >> bookarr[i].edition;
        bookData >> bookarr[i].num_spells;
        
        bookarr[i].s = create_spells(bookarr[i].num_spells);
        get_spell_data(bookarr[i].s, bookarr[i].num_spells, bookData);
    }
}

void get_spell_data(spell* spellArr, int spellNum, ifstream &bookData){
    for(int i = 0; i < spellNum; i++){
        bookData >> spellArr[i].name;
        bookData >> spellArr[i].success_rate;
        bookData >> spellArr[i].effect;
        //cout << spellArr[i].effect << endl;
    }
}

void delete_spellbook_data(spellbook* bookArr, int bookNum){
    for(int i = 0; i < bookNum; i++){
        delete[] bookArr[i].s;
        
    }
    delete [] bookArr;
    bookArr = NULL;
}
