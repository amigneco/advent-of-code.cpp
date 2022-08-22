#include "lib.hpp"
#include <algorithm>
#include <bits/getopt_core.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <file>\n";
    return EXIT_FAILURE;
  }

  char *filename = argv[1];
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Cannot open file: " << filename << "\n";
    return EXIT_FAILURE;
  }

  stringstream input;
  input << file.rdbuf();

  int part1_res = part1(input);
  cout << "part1: " << part1_res << "\n";

  input.clear();
  input.seekg(0, ios::beg);

  int part2_res = part2(input);
  cout << "part2: " << part2_res << "\n";

  return EXIT_SUCCESS;
}
