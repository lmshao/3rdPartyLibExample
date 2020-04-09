CC = g++
LD = g++

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %cpp, %o, $(SRC))

CPPFLAGS = -I./include
LDFLAGS = -lcrypto

TARGET = JWT-ABC

.PHONY: all clean
all: $(TARGET)

$(TARGET) : $(OBJ)
	$(LD) -g -o $@ $^ $(LDFLAGS)

%.o:%.cpp
	$(CC) $(CPPFLAGS) -g -c $^

clean:
	rm -f $(OBJ) $(TARGET)
