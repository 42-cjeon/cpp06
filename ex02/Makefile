# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 03:31:51 by cjeon             #+#    #+#              #
#    Updated: 2022/03/20 03:56:28 by cjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -pedantic -Wall -Wextra -Werror
CXXDEBUGFLAGS = -fsanitize=address -fsanitize=undefined

NAME = main
SRCS = main.cpp ABC.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

debug : CXXFLAGS += $(CXXDEBUGFLAGS)
debug : re

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all debug clean fclean re
