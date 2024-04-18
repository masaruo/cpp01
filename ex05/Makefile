# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:12:23 by mogawa            #+#    #+#              #
#    Updated: 2023/12/04 15:18:19 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		=	ex05
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
LDFLAGS		=	
GTEST_INC	=	-I../googletest/googletest/include -I../googletest/googlemock/include
GTEST_LIB	=	-L../googletest/build/lib
INC			=	-I../include
SRCDIR		=	./
OBJDIR		=	./obj
SRC			=	Harl.cpp \
				main.cpp
OBJ			=	$(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

ifdef WITH_GTEST
CXXFLAGS	=	-Wall -Wextra -std=c++17 $(GTEST_INC) -g3 -O0
LDFLAGS		=	$(GTEST_LIB) -lpthread -lgtest -lgtest_main -lgmock 
SRC			=	Harl.cpp Harl.gtest.cpp
endif

ifdef WITH_LEAK
CXXFLAGS	=	-Wall -Wextra -std=c++98 -g3 -O0
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