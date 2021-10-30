#include "compiler.h"
#include <iostream>

using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

void compile(ifstream& input, ofstream& output) { 
    char c;
while (true) {
  char outByte = 0;
  for (int i = 0; i < 8; i ++) {
  do {
      input >> c;
      if (input.eof()) {
        break;
      }
  } while (c == ' ' || c == '\t' || c == '\n');
    if (input.eof()) {
      break;
    }
  if (c == 'l') {
    outByte |= 1 << (7 - i);
  }else if (c != 'I') {
    cerr << "Error: Unknown character " << c << endl;
    return;
  }
  }
  output << outByte;
  if (input.eof()) {
    break;
  }
  }
}
