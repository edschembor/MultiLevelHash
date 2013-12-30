C++ = g++
CFLAGS = -c -g

all: part1 part2

part1:		ML_hash.o random_op.o main.o
		$(C++) -o part1 ML_hash.o random_op.o main.o

part2:		ML_hash.o main2.o vehicle.o car.o hybrid.o bus.o motorcycle.o task.o task_list.o
		$(C++) -o part2 ML_hash.o main2.o vehicle.o car.o hybrid.o bus.o motorcycle.o task.o task_list.o

clean:
		rm -f *.o *.exe

%.o:	%.cpp
		$(C++) $(CFLAGS) $*.cpp
