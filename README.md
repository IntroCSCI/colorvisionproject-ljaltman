# Palette Analyzer

## Description

This program allows a user to select a .css or .txt filetype, then reads through the file to identify the present colors in hexadecimal format. 

### v0.2 Updates

In this update, the program no longer mistakes inappropriate strings following a # symbol as hexadecimal digits. This program now has additional functionality including identifying unique colors and removing repeated strings. Aditionally, an **if else** statement was changed to an **else** statement to improve efficiency. 

### v1.0 Updates

*Coming soon*


## Developer

Lydia Altman

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Which file would you like to open?
text.txt
The unique colors in this list are:
1. abc
2. abcd567
3. 0a1b2c
4. 000
5. 123
Would you like to open another file? ('y' or 'n')
```

## C++ Guide

### Variables and Data Types

**filename**: filename is a user-input string. When prompted, the user should input the name of the file they want to open and analyze. 

**reader/writer**: these two fstream variables are used to access files for reading and writing. Two files may be open at once, so two fstream variables are required.

**uniqueList**: uniqeList is a string vector that is use to store all of the unique colors found in a .css file. 

**userChoice**: this character simply is assigned 'y' or 'n' based on whether the user would like to reenter the filename or enter another filename.

### Console Input and Output

There are several prompts that are displayed to the user. "Which file would you like to open?" is the first one. If the file cannot be opened, the user is informed that the "File could not be opened." The user is asked if they would like to open another file and may select 'y' to input another filename. The unique colors found are displayed in a numbered list in the console.

### Decisions

**if** decision constructs are used to determine that the user-input files are open before reading from or writing to them. If the read file isn't successfully opened, the user is prompted to enter the file name again. If the file is successfully opened, the analysis begins.

**if** statements are also used within functions. One important use is determining whether or not a character is an appropriate hexadecimal character. This is done several times throughout the program.

### Iteration

**do-while**, **while**,and **for** loops are used throughout this program. The first **do-while** loop continues the persistent user-input until the user no longer wants to enter another file. **while** loops instruct the program to read through the files until the end of the file is reached. **for** loops are used to read through strings when a # symbol is identified. A **for** loop is also used to display the list of unique colors. 

### File Input and Output

The user may input a file to be analyzed. The program creates a new file to record the colors it finds. It then reads that list and pulls only unique colors to store in a vector.

### Arrays/Vectors

**uniqueColors** is a vector that stores all of the individual colors located in a file. By comparing the entries in the vector with the new string that may be added, and using the pop_back and push_back functions no repeats are added to the vector.

### Functions

**FindHexColors** uses the fstream of the file being analyzed as a pass-by reference to accomodate large files and to prevent the file from being opened twice. This function then reads through the file line by line and searches for the '#' symbol. If the characters following are appropriate for a hexadecimal value, the function writes the color code as a string to a new file after converting any upper case letters to lower case. 

**ListUniqueColors** opens the new file to read from it. It's other parameter is an empty string vector pass-by reference. It adds lines from the file to the vector only if the line it is reading has not already been added to the vector.

**dispList** displays a numbered list of all of the unique colors to the console.

### Classes

*Coming in version 1.0*
