CC = g++ 
CFLAGS := -Wall -O3 -std=c++0x

INCLUDE = -I ../src/
LIB = #-lcms -L../src/

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
BINS = $(basename $(OBJS))

all: $(BINS)
	rm -fr *.dSYM

%:%.cpp
	$(CC) $(CFLAGS) $< -g -o $@ $(INCLUDE) $(LIB)

clean:
	rm -fr $(BINS)


