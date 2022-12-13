/*************************
** Program: assign1.cpp
** Author: Brandon Stairs
** Date: 1/18/2020
** Description: Takes a file and sorts information depending on the user inputs
** Input: text file, number to choose options
** Output: Information from the file depending on the users inputs
***************************/

#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H


/****************************
 * function: struct spellbook
 * Description: access the file contents in the array
 * Input: file information
 * Output: Location in the array
 * ***************************/
struct spellbook {
  std::string title;
  std::string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell* s;
};

/****************************
 * function: struct spell
 * Description: access the file contents in the array
 * Input: file information
 * Output: Location in the array
 * ***************************/
struct spell {
  std::string name;
  float success_rate;
  std::string effect; 
};
int checkInput(int, std::string);
/****************************
 * function: void runProgram();
 * Parameters: int, spell*, spellbook*, int
 * Description: is called in main, starts the program
 * Input: number of spells in the array
 * Output: starts user interface part of the program
 * ***************************/
void runProgram(int, spell*, spellbook*, int);

/****************************
 * function: void chooseOption();
 * Parameters: int, spell*, spellbook*, int
 * Description: Ask the user what sorting option they would like to use
 * Input: The option they choose
 * Output: sends their choice to another function
 * ***************************/
void chooseOption(int, spell*, spellbook*, int);

/****************************
 * function: void options();
 * Parameters: int, spell*, spellbook*, int
 * Description: goes to the sorting function based on the users choice
 * Input: the option the user chose
 * Output: the function that goes with the option
 * ***************************/
void options(int, spell*, spellbook*, int);

/****************************
 * function: seeInfo();
 * Parameters: int
 * Description: asks how the user would like to information to be displayed
 * Input: the users choice
 * Output: the users choice
 * ***************************/
int seeInfo(int);

/****************************
 * function: printFile()
 * Parameters: ofstream
 * Description: prints information into a file of the users choice
 * Input: the users choice
 * Output: the users choice
 * ***************************/
void printFile( std::ofstream&);

/****************************
 * function: void sortPaiges()
 * Parameters: int, spellbook*, int
 * Description: sorts the pages of spell books in numerical order
 * Input: Spellbook array and number of spellbook pages
 * Output: sorted pages
 * ***************************/
void sortPaiges(int, spellbook*, int);

/****************************
 * function: Printpages()
 * Parameters: int, spellbook, int
 * Description: prints out the sorted pages for the user to see
 * Input: the sorted pages and number of spell books
 * Output: the pages visiable for the user to see
 * ***************************/
void PrintPages(int, spellbook*, int);

/****************************
 * function: sortEffect()
 * Parameters: int, spellbook, int
 * Description: prints out the sorted effects for the user to see
 * Input: the sorted effects
 * Output: the effects visiable for the user to see
 * ***************************/
void sortEffect(int, spellbook*, int);

/****************************
 * function: printEffect()
 * Parameters: int, spell*, int
 * Description: prints out the sorted effects for the user to see
 * Input: the sorted effects and number of spell books
 * Output: the effects visiable for the user to see
 * ***************************/
void printEffect(int, spell*, spellbook*, int);

/****************************
 * function: spellbook* create_spellboooks()
 * Parameters: int
 * Description: creates an array to store the spellbook
 * Input: number of spellbooks
 * Output: a dynamic array 
 * ***************************/
spellbook* create_spellbooks(int);

/****************************
 * function: spellbNumber()
 * Parameters: char*
 * Description: get the number of spellbooks
 * Input:  number of spell books
 * Output: number of spell books
 * ***************************/
int spellbNumber(char* inputFile);

/****************************
 * function: spell* create_spells()
 * Parameters: int
 * Description: creates an array to store the spellbook
 * Input: number of spells
 * Output: a dynamic array 
 * ***************************/
spell* create_spells(int);

/****************************
 * function: void get_spellbook_data()
 * Parameters: spellbook*, int, ifstream
 * Description: adds the spellbooks to the dynamic array
 * Input: The text file and spellbook array
 * Output: An array full of spellsbooks
 * ***************************/
void get_spellbook_data(spellbook*, int, std::ifstream &);

/****************************
 * function: void get_spell_data()
 * Parameters: spell*, int, ifstream
 * Description: adds the spells to a dynamic array
 * Input: the text file and spell array
 * Output: An array full of spells
 * ***************************/
void get_spell_data(spell*, int, std::ifstream &);

/****************************
 * function: void delete_spellbook_data()
 * Parameters: spellbook*, int
 * Description: deletes the spellbooks and spells stored in arrays
 * Input: spellbook
 * Output: none
 * ***************************/
void delete_spellbook_data(spellbook*, int);


#endif