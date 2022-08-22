#include "lib.hpp"
#include <cstdint>
#include <stdexcept>
#include <string>

int32_t part1(std::istream *input) {
  int32_t hpos = 0;
  int32_t depth = 0;

  for (std::string line; std::getline(*input, line);) {
    auto action = Action::parse(line);
    switch (action->direction) {
    case Direction::Forward:
      hpos += action->amount;
      break;
    case Direction::Down:
      depth += action->amount;
      break;
    case Direction::Up:
      depth -= action->amount;
      break;
    }
  }

  return hpos * depth;
}

int32_t part2(std::istream *input) {
  int32_t hpos = 0;
  int32_t aim = 0;
  int32_t depth = 0;

  for (std::string line; std::getline(*input, line);) {
    auto action = Action::parse(line);
    switch (action->direction) {
    case Direction::Forward:
      hpos += action->amount;
      depth += aim * action->amount;
      break;
    case Direction::Down:
      aim += action->amount;
      break;
    case Direction::Up:
      aim -= action->amount;
      break;
    }
  }

  return hpos * depth;
}

Direction parse_direction(const std::string &str) {
  if (str == "forward") {
    return Direction::Forward;
  } else if (str == "down") {
    return Direction::Down;
  } else if (str == "up") {
    return Direction::Up;
  } else {
    throw std::invalid_argument("not a valid direction");
  }
}

Action::Action(Direction direction, uint32_t amount) {
  this->direction = direction;
  this->amount = amount;
}

bool Action::operator==(const Action &other) const {
  return this->direction == other.direction && this->amount == other.amount;
}

Action *Action::parse(std::string str) {
  auto space = str.find(' ');
  auto direction = parse_direction(str.substr(0, space));
  auto amount = std::stoul(str.substr(space + 1, str.length()));
  return new Action(direction, amount);
}
