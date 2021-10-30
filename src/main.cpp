#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

enum class Action { COMPILE, INTERPRET };

int main (int argc, char** argv) {
  string fileName;
  Action action = Action::INTERPRET;
  for (int i = 1; i < argc; i++) {
    string arg = string(argv[i]);
    if (arg.starts_with("-")) {
      continue;
    }else {
        if (arg.ends_with(".lii")) {
          action = Action::COMPILE;
          fileName = arg;
        }else if (arg.ends_with(".lli")) {
          action = Action::INTERPRET;
          fileName = arg;
        }
    }
  }
  if (fileName == "") {
    cerr << "Error: no input file" << endl;
    return -1;
  }
  return 0;
}
