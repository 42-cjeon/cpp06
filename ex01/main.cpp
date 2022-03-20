/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:46:50 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/21 02:41:37 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

#include "Data.hpp"

uintptr_t serialize(Data *data) {
  uintptr_t *raw = new uintptr_t[4];

  raw[0] = reinterpret_cast<uintptr_t>(data);
  raw[1] = reinterpret_cast<uintptr_t>(data->firstname);
  raw[2] = reinterpret_cast<uintptr_t>(data->lastname);
  raw[3] = reinterpret_cast<uintptr_t>(data->nickname);

  return reinterpret_cast<uintptr_t>(raw);
}

Data *deserialize(uintptr_t raw) {
  uintptr_t *raw_ptr = reinterpret_cast<uintptr_t *>(raw);

  Data *data = reinterpret_cast<Data *>(raw_ptr[0]);
  data->firstname = reinterpret_cast<std::string *>(raw_ptr[1]);
  data->lastname = reinterpret_cast<std::string *>(raw_ptr[2]);
  data->nickname = reinterpret_cast<std::string *>(raw_ptr[3]);
  delete[] raw_ptr;

  return data;
}

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
