/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:19:56 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 03:35:52 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <string>

typedef struct _Data {
  std::string *firstname;
  std::string *lastname;
  std::string *nickname;
} Data;

Data *getData(std::string firstname, std::string lastname,
              std::string nickname);
void disposeData(Data *data);

std::ostream &operator<<(std::ostream &lhs, const Data *data);

#endif
