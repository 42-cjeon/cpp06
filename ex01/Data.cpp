/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:20:17 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 03:29:43 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data *getData(std::string firstname, std::string lastname,
                     std::string nickname) {
  Data *data = new Data;
  data->firstname = new std::string(firstname);
  data->lastname = new std::string(lastname);
  data->nickname = new std::string(nickname);
  return data;
}

void disposeData(Data *data) {
  delete data->firstname;
  delete data->lastname;
  delete data->nickname;
  delete data;
}

std::ostream &operator<<(std::ostream &lhs, const Data *data) {
  lhs << "<DATA>" << std::endl
      << "  | firstname : " << *data->firstname << std::endl
      << "  | lastname  : " << *data->lastname << std::endl
      << "  | nickname  : " << *data->nickname << std::endl
      << "</DATA>";
  return lhs;
}
