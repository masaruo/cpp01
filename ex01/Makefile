# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:54:39 by mogawa            #+#    #+#              #
#    Updated: 2023/12/03 11:49:17 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		=	ex01
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
LDFLAGS		=	
INC			=	-I../include
SRCDIR		=	./
OBJDIR		=	./obj
SRC			=	zombieHorde.cpp \
				Zombie.cpp \
				main.cpp
OBJ			=	$(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

ifdef WITH_LEAK
CXXFLAGS	=	-Wall -Wextra -std=c++98 -g3 -O0 -DLEAK_CHECK
endif

ifdef WITH_ASAN
CXXFLAGS	=	-Wall -Wextra -std=c++98 -g3 -O0 -fsanitize=address
endif

all: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INC) -c $^ -o $@

$(TARGET):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INC) $^ -o $@

gtest: fclean
	$(MAKE) all WITH_GTEST=1
	./$(TARGET)

leak: fclean
	$(MAKE) all WITH_LEAK=1

asan: fclean
	$(MAKE) all WITH_ASAN=1

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(TARGET)

re: fclean
	$(MAKE) all

.PHONY: clean fclean re gtest