/*#include "color.h"
#include <string>
#include <iostream>
#include <fstream>

Member Variables:





//Definitions: 

//This function reads through one file using 'reader' to locate every instance of the # symbol which indicates a Hexadecimal color. If the following characters are appropriate for a hex color, it writes those characters to a new file AFTER converting any capital letters to lowercase. 
void color::FindHexColors (fstream & reader, fstream & writer){
  string line = "";

  while (!reader.eof()){
    getline(reader,line);

    for (int i = 0; i < line.size(); i ++) {

      if (line[i] == '#'){
        int count = i + 1;

        while ((line[count] >= 'a' && line[count] <= 'f') ||
        (line[count] >= 'A' && line[count] <= 'F') || 
        (line[count] >=  '0' && line[count] <= '9')){
          if(line[count] <= 'F' && line[count] >= 'A'){
            char lowerCase = line[count] + 32;
            writer << lowerCase;
          }     
          else{
            writer << line[count];
          }
          count++; 
        }
        writer << endl;
      }
    }
  }
}

//This function opens the file that contains a list of all the Hexadecimal colors. It adds the strings to the vector one by one after comparing the new line with all the previous ones to ensure only unique colors are being added.
void color::ListUniqueColors (fstream & reader, vector<string> & vect){
  string line = "";
  do{
    getline(reader, line);
    vect.push_back(line);

    if(!((line[0] >= 'a' && line[0] <= 'f') || 
    (line[0] >= 'A' && line[0] <= 'F') || 
    (line[0] >=  '0' && line[0] <= '9'))){
      vect.pop_back();
    }

    if(vect.size() > 1){
      for(int i=0; i < vect.size()-1; i++){
        if (vect[i] == line){
          vect.pop_back();
        }
      }
    }
  }while(!reader.eof());
}

//This function is used to display all the unique items in a string vector in a numbered list in the console.
void color::dispList (const vector<string> & list){
  cout <<"The unique colors in this list are:\n";

  if (list.size() >= 1) {
      for( int index = 0; index < list.size(); index ++) {
      cout << index + 1 << ". " << list[index] << endl;
    }
  }
}


determind brightness
if length is 3
 use the character twice
if length is 6
 use pairs of two characters
 
(0.21 × R) + (0.72 × G) + (0.07 × B)

*/