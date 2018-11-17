
CXX = g++
CXXFLAGS = -std=c++11
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o searchSort.o

SRCS = main.cpp menu.cpp inputValidation.cpp searchSort.cpp

HEADERS = menu.hpp inputValidation.hpp searchSort.hpp

#target: dependencies
#	rule to build
#

searchSort: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o searchSort

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
