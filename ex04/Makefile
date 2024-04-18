# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 22:08:03 by mogawa            #+#    #+#              #
#    Updated: 2023/12/06 18:11:55 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		:=	ex04
CXX			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -MMD -MP
LDFLAGS		:=	
GTEST_INC	:=	-I../googletest/googletest/include -I../googletest/googlemock/include
GTEST_LIB	:=	-L../googletest/build/lib
INC			:=	-I../include
SRCDIR		:=	./
OBJDIR		:=	obj
SRC			:=	main.cpp
OBJ			:=	$(SRC:%.cpp=$(OBJDIR)/%.o)
DEPS		:=	$(SRC:%.cpp=$(OBJDIR)/%.d)


all: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INC) $(OBJ) -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(TARGET)

re: fclean
	$(MAKE) all

.PHONY: clean fclean re gtest