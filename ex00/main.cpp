/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:46:20 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/19 21:43:12 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << ": 'string to convert'" << std::endl;
    return 1;
  }

  double d;
  float f;
  //char c;
  //int i;
  long l;

  char *endptr;
  l = std::strtol(argv[1], &endptr, 10);

  
  d = std::strtod(argv[1], &endptr);
  std::cout << d << std::endl;
  std::cout << endptr - argv[1] << std::endl;

  f = std::strtof(argv[1], &endptr);
  std::cout << f << std::endl;
  std::cout << endptr - argv[1] << std::endl;
  return 0;
}
