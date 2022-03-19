/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Numeric.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:54:38 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/20 02:06:06 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMERIC_H_
#define NUMERIC_H_

class Numeric {
  public:
    Numeric(const char *str);
    ~Numeric(void);
    Numeric &operator=(const Numeric &rhs);
    Numeric(const Numeric &origin);

    void print(void);

  private:
    Numeric(void);
    
    enum {
      kCharRep = 1,
      kIntRep = 2,
      kFloatRep = 4,
      kDoubleRep = 8
    };

    bool parse_char(void);
    bool parse_int(void);
    bool parse_float(void);
    bool parse_double(void);

    void printFromCharRep(void);
    void printFromIntRep(void);
    void printFromFloatRep(void);
    void printFromDoubleRep(void);
    void printAllImpossible(void);
    void printNan(void);

    const char *raw_string_;
    unsigned int rep_type_;
    char char_rep_;
    int int_rep_;
    float float_rep_;
    double double_rep_;
};

#endif
