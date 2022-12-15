#include <cmath>
#include <iostream>

const float kInchesInFeet = 12.0;
const float kEighthsInInch = 8.0;

int main(int argc, char const *argv[]) {
  float input_decimal_feet = NAN;
  std::cout << "Enter the number of feet you wish to convert to feet-inch: ";
  std::cin >> input_decimal_feet;
  std::string sign;
  if (input_decimal_feet < 0.0) {
    input_decimal_feet *= -1.0;
    sign = "-";
  }
  int feet_integer_component = 0;
  float feet_fractional_component = NAN;
  feet_integer_component = static_cast<int>(std::trunc(input_decimal_feet));
  feet_fractional_component = input_decimal_feet - feet_integer_component;
  float decimal_inches = NAN;
  decimal_inches = feet_fractional_component * kInchesInFeet;
  int inches_integer_component = 0;
  float inches_fractional_component = NAN;
  inches_integer_component = static_cast<int>(decimal_inches);
  inches_fractional_component = decimal_inches - inches_integer_component;
  float eighths = NAN;
  eighths = inches_fractional_component * kEighthsInInch;
  int eighths_integer_component = 0;
  eighths_integer_component = static_cast<int>(eighths);
  std::cout << sign << input_decimal_feet << " feet is " << sign
            << feet_integer_component << " feet, " << inches_integer_component;
  if (eighths_integer_component != 0) {
    std::cout << " and " << eighths_integer_component << " /8 ";
  }
  std::cout << " inches\n";
  return 0;
}
