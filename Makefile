# C compiler
CC = gcc

# C flags
CFLAGS = -c -Wall -fPIC

LIB_NAME = imeclui
LIB_SOURCE = imeclui.h

# Platform
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
RM = rm -f
DYN_LIB_TARGET = lib$(LIB_NAME).so
STT_LIB_TARGET = lib$(LIB_NAME).a
COPY = cp
SYS = 
EXE_EXTENSION =
else
RM = del /Q
DYN_LIB_TARGET = lib$(LIB_NAME).dll
STT_LIB_TARGET = lib$(LIB_NAME).lib
COPY = copy
SYS = -D _WIN32 -O3
EXE_EXTENSION = .exe
endif


all: lib main
	
run: all
	./main$(EXE_EXTENSION)

lib: $(LIB_NAME).h
	$(COPY) $(LIB_SOURCE) $(LIB_NAME).c
# Compile the library:
# Dynamic lib:
	$(CC) $(CFLAGS) -o $(LIB_NAME).o $(LIB_NAME).c -D ADD_EXPORTS -D IMECLUI_IMPLEMENTATION $(SYS)
	$(CC) -o $(DYN_LIB_TARGET) -s -shared $(LIB_NAME).o
	$(RM) $(LIB_NAME).o 
# Static lib:	
	$(CC) $(CFLAGS) -o $(LIB_NAME).o $(LIB_NAME).c -D ADD_EXPORTS -D IMECLUI_IMPLEMENTATION $(SYS)
	ar rcs $(STT_LIB_TARGET) $(LIB_NAME).o
# Cleanup:
	$(RM) $(LIB_NAME).o $(LIB_NAME).c

main: main.c
	$(CC) -I . -c main.c
	$(CC) -o main.exe main.o -L. -l$(LIB_NAME)
	$(RM) main.o

main_static: main.c
	$(CC) -I . -c main.c -D ADD_EXPORTS -D IMECLUI_IMPLEMENTATION $(SYS)
	$(CC) -o main.exe main.o
	$(RM) main.o
