#include <iostream>
#include <fstream>
#include <string>
#include "compiler.h"
#include "interpreter.h"

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

enum class Action { COMPILE, INTERPRET };

int main (int argc, char** argv) {
  string inputFileName;
  string outputFileName;
  Action action = Action::INTERPRET;
  for (int i = 1; i < argc; i++) {
    string arg = string(argv[i]);
    if (arg.starts_with("-")) {
      if (arg == "-o") {
        outputFileName = string(argv[++i]);
      }
    }else {
        if (arg.ends_with(".lii")) {
          action = Action::COMPILE;
          inputFileName = arg;
        }else if (arg.ends_with(".lli")) {
          action = Action::INTERPRET;
          inputFileName = arg;
        }else {
          cerr << "Unknown file type for " << arg << endl;
          ;
        }
    }
  }
  if (inputFileName == "") {
    cerr << "Error: no input file" << endl;
    return -1;
  }
  ifstream input(inputFileName, ios::binary);
  if (action == Action::INTERPRET) {
    interpret(input);
  }else {
      if (outputFileName == "") {
          outputFileName = inputFileName + ".lli";
      }
    ofstream output(outputFileName, ios::binary);
    compile(input, output);
    output.close();
  }
  input.close();
  return 0;
}
