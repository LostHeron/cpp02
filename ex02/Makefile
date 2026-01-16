# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 13:36:07 by jweber            #+#    #+#              #
#    Updated: 2026/01/15 13:21:27 by jweber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./a.out
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std="c++98" -MMD -MP -g3

SOURCE_FILES := main.cpp \
				Fixed.cpp \

OBJECT_DIR := .obj/
OBJECT_FILES := $(addprefix $(OBJECT_DIR), $(SOURCE_FILES:.cpp=.o))

DEPS_FILES := $(OBJECT_FILES:.o=.d)

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):  $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

-include $(DEPS_FILES)

$(OBJECT_DIR)%.o: %.cpp | $(OBJECT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJECT_DIR)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
