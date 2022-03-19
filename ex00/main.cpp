/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:46:20 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 02:42:33 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "Numeric.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << ": 'string to convert'" << std::endl;
    return 1;
  }
  std::cout << std::showpoint;
  Numeric n(argv[1]);
  n.print();
  return 0;
}
