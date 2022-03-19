/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:33:19 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 03:56:10 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABC_H_
#define ABC_H_

class Base {
 public:
  virtual ~Base(void);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif
