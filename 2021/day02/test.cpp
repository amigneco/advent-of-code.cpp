#include "lib.hpp"
#include <gtest/gtest.h>
#include <istream>
#include <sstream>

using namespace std;

TEST(day02, part1) {
  istringstream data("forward 5\n"
                     "down 5\n"
                     "forward 8\n"
                     "up 3\n"
                     "down 8\n"
                     "forward 2\n");
  EXPECT_EQ(part1(&data), 150);
}

TEST(day02, part2) {
  istringstream data("forward 5\n"
                     "down 5\n"
                     "forward 8\n"
                     "up 3\n"
                     "down 8\n"
                     "forward 2\n");
  EXPECT_EQ(part2(&data), 900);
}

TEST(day02, parse_direction) {
  EXPECT_EQ(parse_direction("forward"), Direction::Forward);
  EXPECT_EQ(parse_direction("down"), Direction::Down);
  EXPECT_EQ(parse_direction("up"), Direction::Up);
}

TEST(day02, Action_parse) {
  EXPECT_EQ(*Action::parse("forward 5"), *new Action(Direction::Forward, 5));
  EXPECT_EQ(*Action::parse("down 5"), *new Action(Direction::Down, 5));
  EXPECT_EQ(*Action::parse("forward 8"), *new Action(Direction::Forward, 8));
  EXPECT_EQ(*Action::parse("up 3"), *new Action(Direction::Up, 3));
  EXPECT_EQ(*Action::parse("down 8"), *new Action(Direction::Down, 8));
  EXPECT_EQ(*Action::parse("forward 2"), *new Action(Direction::Forward, 2));
}
