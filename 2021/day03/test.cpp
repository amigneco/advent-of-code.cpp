#include "lib.hpp"
#include <gtest/gtest.h>
#include <istream>
#include <sstream>

using namespace std;

TEST(day02, part1) {
  stringstream input;
  input << ("00100\n"
            "11110\n"
            "10110\n"
            "10111\n"
            "10101\n"
            "01111\n"
            "00111\n"
            "11100\n"
            "10000\n"
            "11001\n"
            "00010\n"
            "01010\n");

  EXPECT_EQ(part1(input), 198);
}

TEST(day02, part2) {
  stringstream input;
  input << ("00100\n"
            "11110\n"
            "10110\n"
            "10111\n"
            "10101\n"
            "01111\n"
            "00111\n"
            "11100\n"
            "10000\n"
            "11001\n"
            "00010\n"
            "01010\n");

  EXPECT_EQ(part2(input), 230);
}
