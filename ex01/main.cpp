/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:46:50 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 03:35:48 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

#include "Data.hpp"

uintptr_t serialize(Data *data) { return reinterpret_cast<uintptr_t>(data); }

Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main(void) {
  Data *data = getData("changmin", "jeon", "cjeon");

  std::cout << "--- original ---" << std::endl;
  std::cout << data << std::endl;

  uintptr_t s_data = serialize(data);
  Data *ds_data = deserialize(s_data);

  std::cout << "--- serialize -> deserialize ---" << std::endl;
  std::cout << ds_data << std::endl;

  disposeData(data);
  return 0;
}
