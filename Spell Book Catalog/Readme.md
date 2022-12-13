#The Magician Spellbook Catalog
## Introduction
The great magic university of Fakebills has been adding a lot of new spellbooks to their library lately. The school administration has hired you to create a spellbook catalog program that will make searching for spellbooks easier.
To simplify your task, the school has provided you with their spellbook information. These come in the form of a text file that file contains a list of Fakebill's spellbooks and their included spells, all of the information that your program will display.

## Requirements
Command Line Argument:
When starting the program, the user will provide one command line argument. The command line argument will be the name of the file that contains the information about spellbooks and included spells. If the user does not provide the name of an existing file the program should print out an error message and quit.

## Sorting and Printing:
Once the program begins, the user should be prompted with a list of different ways to display the spellbook and spell information. After the user has chosen an option, they should be asked if they want the information printed to the screen or written to a file. If they choose to write to a file, they should be prompted for a file name. If the file name already exists, the information should be appended to the file. If the file name does not exist, a file should be created and the information should be written to the file. 

## Available Options:
```
Sort spellbooks by number of pages: If the user picks this option the books must be sorted in ascending order by number of pages. Once they are sorted, you should print/write to file the title of the book and the number of pages it has.
Sort spells by effect: There are five types of spells: fire, bubble, memory_loss, death, poison. The spells with bubble as the effect should be listed first, followed by memory_loss, fire, poison, and death. Once they are sorted, you should print/write to file the spell name and its effect.
Sort by average success rate of spells: You must create a list of books sorted by the average success rate of all the spells contained within the book. Once calculated, you should print/write to file the title of each applicable book and the corresponding average success rate. 
Quit: The program will exit.
```
