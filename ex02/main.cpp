/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:36:37 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 03:56:14 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#include "ABC.hpp"

Base *generate(void) {
  int k = std::rand();

  if (k % 3 == 0) {
    return new A;
  } else if (k % 3 == 1) {
    return new B;
  } else {
    return new C;
  }
}

void identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  B *b = dynamic_cast<B *>(p);
  C *c = dynamic_cast<C *>(p);

  if (a) {
    std::cout << "A" << std::endl;
  } else if (b) {
    std::cout << "B" << std::endl;
  } else if (c) {
    std::cout << "C" << std::endl;
  }
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    (void)a;
  } catch (std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    (void)b;
  } catch (std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    (void)c;
  } catch (std::exception &e) {
  }
}

int main(void) {
  std::srand(std::time(NULL));

  Base *unknown = generate();

  identify(unknown);
  identify(*unknown);

  delete unknown;
}
