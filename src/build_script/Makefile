CC = g++
STD = -std=c++17
TARGET = ./../../build/atm.out
TARGET_PATH = ./../../build
SOURCE_PATH = ./../src
INC = -I./../src
NETWORK = Network.o
ATM = ATM.o
MAIN = main.o

all: main

$(NETWORK): $(SOURCE_PATH)/Network.cpp
	$(CC) -c $(SOURCE_PATH)/Network.cpp 

$(ATM): $(NETWORK) $(SOURCE_PATH)/ATM.cpp
	$(CC) -c $(SOURCE_PATH)/ATM.cpp 

$(MAIN): $(ATM) $(SOURCE_PATH)/main.cpp
	$(CC) -c $(SOURCE_PATH)/main.cpp

main: $(MAIN)
	$(CC) $(STD) $(INC) -o $(TARGET) ATM.o Network.o main.o
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf ./../../build/*
