#include "lib.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 1) {
    perror("no file");
    return EXIT_FAILURE;
  }

  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    perror("open");
    return EXIT_FAILURE;
  }

  std::vector<uint32_t> input;
  for (std::string line; getline(file, line);) {
    input.push_back(std::stoul(line));
  }

  int result = count_increasing_groups(&input);
  std::cout << result << "\n";

  file.close();
  return EXIT_SUCCESS;
}
