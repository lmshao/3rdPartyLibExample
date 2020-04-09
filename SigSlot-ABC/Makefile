CC = g++
LD = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %cpp, %o, $(SRC))

TARGET = SigSlot-ABC

.PHONY: all clean
all: $(TARGET)

$(TARGET) : $(OBJ)
	$(LD) -g -o $@ $^

%.o:%.cpp
	$(CC) -g -c $^

clean:
	rm -f $(OBJ) $(TARGET)
