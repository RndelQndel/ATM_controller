CC = g++
STD = -std=c++17
TARGET = ./../../build/atm.out
TARGET_PATH = ./../../build
SOURCE_PATH = ./../src
INC = -I./../src

all: $(TARGET)
	$(CC) $(STD) $(INC) -o $(TARGET) ATM.o
	rm -rf *.o

$(TARGET):
	$(CC) -c $(SOURCE_PATH)/ATM.cpp $(INC) $(LIB_DIRS) $(LIBS)

clean:
	rm -rf *.o
	rm -rf ./../../build/*
