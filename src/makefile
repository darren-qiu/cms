CC = g++
CFLAGS := -Wall -O3 -std=c++0x

OPENCV_INC_ROOT = ../inc
OPENCV_LIB_ROOT = ../lib

SRC_PATH = .
SRCS += $(wildcard $(SRC_PATH)/*.cpp)
#OBJS := $(SRCS:.cpp=.o)
#OBJS = mbody.o mlist.o overdue.o
OBJS = mbody.o cms_list.o 
LIB = libcms.a

#OPENCV_INC = -I $(OPENCV_INC_ROOT)
OPENCV_INC = -I . 
INCLUDE_PATH = $(OPENCV_INC)
#LIB_PATH = -L $(OPENCV_LIB_ROOT)
LIB_PATH = 

OPENCV_LIB = 

all : $(LIB)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_PATH) $(LIB_PATH) $(OPENCV_LIB)

$(LIB) : $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)
	rm -f $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET) $(LIB)


