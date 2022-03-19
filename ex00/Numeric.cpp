/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Numeric.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:57:07 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 02:40:07 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Numeric.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>

Numeric::Numeric(const char *str)
    : raw_string_(str),
      rep_type_(0),
      char_rep_(0),
      int_rep_(0),
      float_rep_(0),
      double_rep_(0) {}

Numeric::~Numeric(void) {}

Numeric &Numeric::operator=(const Numeric &rhs) {
  raw_string_ = rhs.raw_string_;
  rep_type_ = rhs.rep_type_;
  char_rep_ = rhs.char_rep_;
  int_rep_ = rhs.int_rep_;
  float_rep_ = rhs.float_rep_;
  double_rep_ = rhs.double_rep_;
  return *this;
}

Numeric::Numeric(const Numeric &origin)
    : raw_string_(origin.raw_string_),
      rep_type_(origin.rep_type_),
      char_rep_(origin.char_rep_),
      int_rep_(origin.int_rep_),
      float_rep_(origin.float_rep_),
      double_rep_(origin.double_rep_) {}

bool Numeric::parse_char(void) {
  if (std::strlen(raw_string_) == 1 && !std::isdigit(*raw_string_) &&
      std::isprint(*raw_string_)) {
    rep_type_ = kCharRep;
    char_rep_ = static_cast<char>(*raw_string_);
    return true;
  }
  return false;
}

bool Numeric::parse_int(void) {
  if (std::isspace(*raw_string_)) {
    return false;
  }
  char *num_end;
  long long_rep = std::strtol(raw_string_, &num_end, 10);
  if (errno != ERANGE && *num_end == '\0' && INT_MIN <= long_rep &&
      INT_MAX >= long_rep) {
    rep_type_ = kIntRep;
    int_rep_ = static_cast<int>(long_rep);
    return true;
  }
  return false;
}

bool Numeric::parse_float(void) {
  if (std::isspace(*raw_string_)) {
    return false;
  }
  char *num_end;
  std::string str_rep(raw_string_);
  float float_rep = std::strtof(raw_string_, &num_end);
  if (errno != ERANGE) {
    if ((str_rep.find('.') != std::string::npos 
        && *num_end == 'f' && *(num_end + 1) == '\0')
        || str_rep == "nanf") {
      rep_type_ = kFloatRep;
      float_rep_ = float_rep;
      return true;
    }
  }
  return false;
}

bool Numeric::parse_double(void) {
  if (std::isspace(*raw_string_)) {
    return false;
  }
  char *num_end;
  double double_rep = std::strtof(raw_string_, &num_end);
  if (errno != ERANGE && *num_end == '\0') {
    rep_type_ = kDoubleRep;
    double_rep_ = double_rep;
    return true;
  }
  return false;
}

void Numeric::print(void) {
  if (parse_char()) {
    printFromCharRep();
  } else if (parse_int()) {
    printFromIntRep();
  } else if (parse_float()) {
    printFromFloatRep();
  } else if (parse_double()) {
    printFromDoubleRep();
  } else {
    printAllImpossible();
  }
}

void Numeric::printFromCharRep(void) {
  std::cout << "char: '" << char_rep_ << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(char_rep_) << std::endl;
  std::cout << "float: " << static_cast<float>(char_rep_) << std::endl;
  std::cout << "double " << static_cast<double>(char_rep_) << std::endl;
}

void Numeric::printFromIntRep(void) {
  std::cout << "char: ";
  if (CHAR_MIN <= int_rep_ && int_rep_ <= CHAR_MAX) {
    if (std::isprint(int_rep_)) {
      std::cout << "'" << static_cast<char>(int_rep_) << "'";
    } else {
      std::cout << "Non displayable";
    }
  } else {
    std::cout << "impossible";
  }
  std::cout << std::endl;
  std::cout << "int: " << int_rep_ << std::endl;
  std::cout << "float: " << static_cast<float>(int_rep_) << 'f' << std::endl;
  std::cout << "double " << static_cast<double>(int_rep_) << std::endl;
}

void Numeric::printFromFloatRep(void) {
  if (float_rep_ != float_rep_) {
    printNan();
    return;
  }
  std::cout << "char: ";
  if (CHAR_MIN <= float_rep_ && float_rep_ <= CHAR_MAX) {
    if (std::isprint(float_rep_)) {
      std::cout << "'" << static_cast<char>(float_rep_) << "'";
    } else {
      std::cout << "Non displayable";
    }
  } else {
    std::cout << "impossible";
  }
  std::cout << std::endl;
  std::cout << "int: ";
  if (INT_MIN <= float_rep_ && float_rep_ <= INT_MAX) {
    std::cout << static_cast<int>(float_rep_);
  } else {
    std::cout << "impossible";
  }
  std::cout << std::endl;
  std::cout << "float: " << float_rep_ << 'f' << std::endl;
  std::cout << "double " << static_cast<double>(float_rep_) << std::endl;
}

void Numeric::printFromDoubleRep(void) {
  if (double_rep_ != double_rep_) {
    printNan();
    return;
  }
  std::cout << "char: ";
  if (CHAR_MIN <= double_rep_ && double_rep_ <= CHAR_MAX) {
    if (std::isprint(double_rep_)) {
      std::cout << "'" << static_cast<char>(double_rep_) << "'";
    } else {
      std::cout << "Non displayable";
    }
  } else {
    std::cout << "impossible";
  }
  std::cout << std::endl;
  std::cout << "int: ";
  if (INT_MIN <= double_rep_ && double_rep_ <= INT_MAX) {
    std::cout << static_cast<int>(double_rep_);
  } else {
    std::cout << "impossible";
  }
  std::cout << std::endl;
  std::cout << "float: " << static_cast<float>(double_rep_) << 'f' << std::endl;
  std::cout << "double " << double_rep_ << std::endl;
}

void Numeric::printNan(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
}

void Numeric::printAllImpossible(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}
