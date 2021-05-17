//HEADER file for color class
#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::vector;

class color{
  private:
    string HexColor;
    string rgbColor;
    string brightness;

  public:
    //Prototypes:
      void FindHexColors (fstream &, fstream &);

    //Add function to find colors in r,g,b, and r,g,b,a formats

    void ListUniqueColors (fstream &, vector<string> &);

    void dispList (const vector<string> &);
};

#endif