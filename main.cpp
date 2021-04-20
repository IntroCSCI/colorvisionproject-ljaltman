//Author: Lydia Altman
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Prototypes:
void FindHexColors (fstream &, fstream &);
//Add function to find colors in r,g,b, and r,g,b,a formats
void ListUniqueColors (fstream &, vector<string> &);
//void makeLowercase (fstream&);
void dispList (const vector<string> &);

int main(){

  //declare variables...
  fstream reader;
  //fstream readFirstList;
  fstream writer;
  //fstream readAndWrite;
  string filename = "";
  string line = "";
  int index = 0;
  char openAnotherFileChoice = 'y';


  do{
    //get user input...
    cout << "Which file would you like to open?\n";
    cin >> filename;
    reader.open(filename, ios::in);
    writer.open("ListOfHexcolors.txt", ios::out);

    if (reader.is_open()){
      FindHexColors(reader, writer);
    }

    else {
      cout << "File could not be opened." << endl;
    }

    reader.close();
    writer.close();
    
    reader.open("ListOfHexcolors.txt", ios::in);
    vector<string> UniqueList;

    if (reader.is_open()){
      ListUniqueColors (reader, UniqueList);
    }

    reader.close();
    dispList(UniqueList);

    cout << "Would you like to open another file? ('y' or 'n')" << endl;
    cin >> openAnotherFileChoice;
    
  }while(openAnotherFileChoice == 'y' || openAnotherFileChoice == 'Y');

  return 0;
}


//Definitions: 

//This function reads through one file using 'reader' to locate every instance of the # symbol which indicates a Hexadecimal color. If the following characters are appropriate for a hex color, it writes those characters to a new file AFTER converting any capital letters to lowercase. 
void FindHexColors (fstream & reader, fstream & writer){
  string line = "";
  while (!reader.eof()){
    getline(reader,line);
    for (int index = 0; index < line.size(); index ++) {
      if (line[index] == '#'){
        int counter = index +1;
        while (line[counter] >= 'a' && line[counter] <= 'f' || line[counter] >= 'A' && line[counter] <= 'F' || line[counter] >=  '0' && line[counter] <= '9'){
          if(line[counter] <= 'F' && line[counter] >= 'A'){
            char lowerCase = line[counter] + 32;
            writer << lowerCase;
          }      
          else{
            writer << line[counter];
          }
          counter++; 
        }
        writer << endl;
      }
    }
  }
}


//This function opens the file that contains a list of all the Hexadecimal colors. It adds the strings to the vector one by one after comparing the new line with all the previous ones to ensure only unique colors are being added.
void ListUniqueColors (fstream & readFile, vector<string> & vect){
  string lineTwo = "";

  do{
    getline(readFile, lineTwo);
    vect.push_back(lineTwo);

    if(!(lineTwo[0] >= 'a' && lineTwo[0] <= 'f' || lineTwo[0] >= 'A' && lineTwo[0] <= 'F' || lineTwo[0] >=  '0' && lineTwo[0] <= '9')){
      vect.pop_back();
    }

    if(vect.size() > 1){
      for(int i=0; i < vect.size()-1; i++){
        if (vect[i] == lineTwo){
          vect.pop_back();
        }
      }
    }
  }while(!readFile.eof());
}

/*
void makeLowercase (fstream& readerTwo){
  int i = 0;
  string line = "";

  do{
    getline(readerTwo, line);

    for( int j = 0; j < line.length(); j++){
      if( line[j] >= 'A' && line[j] <= 'F'){
        line[j] = line[j] + 32;
      }
    }
    i++;
  }while(!readerTwo.eof());
}
*/

void dispList (const vector<string> & list){
  //this fxn displays the elements in the vector when called
  cout <<"The unique colors in this list are:\n";
  if (list.size() >= 1) {
      for( int index = 0; index < list.size(); index ++) {
      cout << index + 1 << ". " << list[index] << endl;
    }
  }
}
