#pragma once

#include <cstdint>
#include <istream>
#include <string>

int32_t part1(std::istream *input);
int32_t part2(std::istream *input);

enum class Direction { Forward, Down, Up };
Direction parse_direction(std::string const &str);

class Action {
public:
  Direction direction;
  uint32_t amount;

  explicit Action(Direction direction, uint32_t amount);
  bool operator==(const Action &other) const;

  static Action *parse(std::string str);
};
