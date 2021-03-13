//Author: Lydia Altman
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

  //declare variables...
  fstream reader;
  string filename = "";
  string line = "";
  int index = 0;
  char choice = 'y';

  do{
    //get user input...
    cout << "Which file would you like to open?\n";
    cin >> filename;
    reader.open(filename, ios::in);

    if (reader.is_open()){
      
      cout << "Colors identified: " << endl;
      //reads file line by line
      while (!reader.eof()){

        getline(reader,line);
        index = line.find("#"); //search line for # symbol
        cout << line[index];

        //when a '#' symbol is located do the following...
        if (line[index]){

          //advance the reader by one character...
          for (int counter = index+1; counter < line.size(); counter++){

            //if the character is appropriate for a color, print it...
            if (line[counter] >= 'a' && line[counter] <= 'f' || line[counter] >= 'A' && line[counter] <= 'F' || line[counter] >=  '0' && line[counter] <= '9') {

              cout << line[counter];
            }
          }
          cout << endl;
        }
      }
    }

    else if (reader.fail()){
      cout << "File could not be opened." << endl;
      /*cout << "Try again? ('y' or 'n')" << endl;
      cin >> choice;
      */
    }

    reader.close();
    
    cout << "Would you like to open another file? ('y' or 'n')" << endl;
    cin >> choice;
    
  }while(choice == 'y' || choice == 'Y');

  return 0;
}
