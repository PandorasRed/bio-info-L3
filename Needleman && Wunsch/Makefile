CPP=g++

INC=include
CFLAGS= -g -Wall -Wextra -Werror 
NAME=main 
SRC_FILES = Data.cpp  NWMatrix.cpp main.cpp readFastaFile.cpp readMatrixFile.cpp
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst %.cpp, %.o, $(SRCS))


all: clean $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ -I./$(INC)

clean:
	rm -f $(OBJS) $(NAME)
