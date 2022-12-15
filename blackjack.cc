#include <iostream>
#include <string>
#include <vector>

bool IsAce(const std::string& card_name) {
  std::vector<std::string> ace_card{"A"};
  for (const std::string& ace : ace_card) {
    if (card_name == ace) {
      return true;
    }
  }
  return false;
}

bool IsFaceCard(const std::string& card_name) {
  std::vector<std::string> face_card{"J", "K", "Q"};
  for (const std::string& face : face_card) {
    if (card_name == face) {
      return true;
    }
  }
  return false;
}

bool IsNumberCard(const std::string& card_name) {
  std::vector<std::string> card_numbers{"2", "3", "4", "5", "6",
                                        "7", "8", "9", "10"};
  for (const std::string& card : card_numbers) {
    if (card_name == card) {
      return true;
    }
  }
  return false;
}

bool IsCardName(const std::string& str) {
  if (IsAce(str) || IsFaceCard(str) || IsNumberCard(str)) {
    return true;
  }
  return false;
}

bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  bool first_one{false};
  bool arguments_total;
  bool single{false};
  if (arguments.size() == 1) {
    single = true;
    arguments_total = true;
    return arguments_total;
  }
  for (const std::string& name : arguments) {
    if (first_one) {
      return false;
      continue;
    } else {
      arguments_total = IsCardName(name);
      if (arguments_total == true) {
        continue;
      } else {
        arguments_total = false;
      }
    }
  }
  return arguments_total;
}

int CardPoints(const std::string& card_name) {
  int points{0};
  if (IsAce(card_name) == true) {
    points += 1;
    return points;
  } else if (IsFaceCard(card_name) == true) {
    points += 10;
    return points;
  } else if (IsNumberCard(card_name) == true) {
    points += (std::stoi(card_name));
    return points;
  } else {
    return false;
  }
  return points;
}

bool HandContainsAce(const std::vector<std::string>& arguments) {
  bool is_ace{false};
  bool first_two_args{true};
  for (const std::string& check_ace : arguments) {
    if (first_two_args) {
      first_two_args = false;
      continue;
    } else {
      if (IsAce(check_ace) == true) {
        is_ace = true;
      }
    }
  }
  return is_ace;
}

bool IsBust(int score) {
  if (score > 21) {
    return true;
  } else {
    return false;
  }
  return score;
}

int HandScore(const std::vector<std::string>& arguments) {
  int total{0};
  bool single_one{false};
  bool first_three{true};
  if (single_one == true) {
    return total;
  }
  for (const std::string& arg_handscore : arguments) {
    if (first_three) {
      first_three = false;
      continue;
    }
    if ((HandContainsAce(arguments) == true)) {
      if (arg_handscore == "A") {
        if (IsBust(total + 11) == false) {
          total -= 1;
          total += 11;
        }
      }
    }
    total += CardPoints(arg_handscore);
  }
  return total;
}

void PrintScore(int score) {
  if (!IsBust(score)) {
    std::cout << "Score is " << score << "\n";

  } else {
    std::cout << "Score is " << score << ", BUST\n";
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (!AllArgumentsValid(arguments)) {
    std::cout << "error: unknown card\n";
    return 1;
  } else {
    PrintScore(HandScore(arguments));
  }
  return 0;
}
