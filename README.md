# Palette Analyzer

## Description

This program allows a user to select a .css or .txt filetype, then reads through the file to identify the present colors in hexadecimal format. 

### v0.2 Updates

*Coming soon*

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
Colors identified: 
#0a1b2cb
#000
#123
Would you like to open another file? ('y' or 'n')
```

## C++ Guide

### Variables and Data Types

**filename**: filename is a user-input string. When prompted, the user should input the name of the file they want to open. 

**line**: string data is pulled from the file line by line and assigned to this variable. One line at a time is analyzed to locate a color in hexadecimal format.

**index**: index is an integer variable. When the '#' symbol is located on a line of text, the index of the character is stored in this variable.

**choice**: this character simply is assigned 'y' or 'n' based on whether the user would like to reenter the filename or enter another filename.

### Console Input and Output

There are several prompts that are displayed to the user. "Which file would you like to open?" is the first one. If the file cannot be opened, the user is informed that the "File could not be opened." The user is asked if they would like to open another file and may select 'y' to input another filename. The other outputs are the colors that are identified in the file. 

### Decisions

The first decision construct in this program is an **if** statement that checks for the condition that the user-input file is open. If it isn't successfully opened, the user is prompted to enter the file name again. If the file is successfully opened, the analysis begins.

Nested within the first, the second **if** construct confirms that a '#' symbol was found and the location was assigned to the variable *index*. 

The remaining **if** statement confirms that the character after the '#' symbol is a hexadecimal character before the position is advanced. 

### Iteration

Both a **while** loop and a **for** loop are used in this program. The **while** loop instructs the program to read through the file until the end of the file is reached. When a '#' symbol is identified, the **for** loop starts at the position after the '#' and outputs the characters until a non-hexadecimal character is read. The **counter** is informed by the index of the '#' symbol.

### File Input and Output

The user may input a file to be analyzed. 

### Arrays/Vectors

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
