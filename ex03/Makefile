# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:54:39 by mogawa            #+#    #+#              #
#    Updated: 2023/12/06 18:57:29 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		:=	ex03
CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -MMD -MP
LDFLAGS		:=	
INC			:=	-I../include
SRCDIR		:=	./
OBJDIR		:=	./obj
SRC			:=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ			:=	$(SRC:%.cpp=$(OBJDIR)/%.o)
DEPS		:=	$(SRC:%.cpp=$(OBJDIR)/%.d)

ifdef WITH_LEAK
CXXFLAGS	+=	-g3 -O0 -DLEAK_CHECK
endif

ifdef WITH_ASAN
CXXFLAGS	+=	-g3 -O0 -fsanitize=address
endif

all: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INC) $^ -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(TARGET)

re: fclean
	$(MAKE) all

leak: fclean
	$(MAKE) all WITH_LEAK=1

asan: fclean
	$(MAKE) all WITH_ASAN=1

-include $(DEPS)

.PHONY: clean fclean re leak asan