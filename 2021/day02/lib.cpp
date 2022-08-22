#include "../../common/lib.hpp"

using namespace std;

enum class Direction { Forward, Down, Up };
Direction parse_direction(const string &str) {
  if (str == "forward") {
    return Direction::Forward;
  } else if (str == "down") {
    return Direction::Down;
  } else if (str == "up") {
    return Direction::Up;
  } else {
    throw invalid_argument("not a valid direction");
  }
}

class Action {
public:
  Direction direction;
  uint32_t amount;

  explicit Action(Direction direction, uint32_t amount) {
    this->direction = direction;
    this->amount = amount;
  }

  bool operator==(const Action &other) const {
    return this->direction == other.direction && this->amount == other.amount;
  }

  static Action *parse(string str) {
    auto space = str.find(' ');
    auto direction = parse_direction(str.substr(0, space));
    auto amount = stoul(str.substr(space + 1, str.length()));
    return new Action(direction, amount);
  }
};

int part1(std::istream &input) {
  int32_t hpos = 0;
  int32_t depth = 0;

  for (string line; getline(input, line);) {
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

int part2(std::istream &input) {
  int32_t hpos = 0;
  int32_t aim = 0;
  int32_t depth = 0;

  for (string line; getline(input, line);) {
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
