.SUFFIXES: .cpp .o .hpp .h .tpp
.PHONY : all clean re

CPP = c++
RM = rm -rf

OBJ_DIR = objs/

ifndef TARGET
	TARGET = a.out
endif
ifndef SRC
	SRC =
endif
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(TARGET)

clean :
	$(RM) $(OBJ_DIR)
	$(RM) $(TARGET)

re : clean
	make all

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJS) : | $(OBJ_DIR)

$(addprefix $(OBJ_DIR), %.o): %.cpp
	$(CPP) -c $< -o $@ $(CPPFLAGS)

$(TARGET) : $(OBJS)
	$(CPP) -o $@ $^ $(CPPFLAGS)
