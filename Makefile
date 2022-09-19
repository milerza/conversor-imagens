CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=program

BUILD_DIR   = ./bin
OBJ_DIR   = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${BUILD_DIR}/${TARGET}

run: ./conversor_imagem

${BUILD_DIR}/${TARGET}: ${OBJ_DIR}/Celula.o ${OBJ_DIR}/Pgm.o ${OBJ_DIR}/Ppm.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o  conversor_imagem

${OBJ_DIR}/Celula.o: ${INCLUDE_DIR}/Celula.hpp ${SRC_DIR}/Celula.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Celula.cpp -o ${OBJ_DIR}/Celula.o

${OBJ_DIR}/Pgm.o: ${INCLUDE_DIR}/Pgm.hpp ${SRC_DIR}/Pgm.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Pgm.cpp -o ${OBJ_DIR}/Pgm.o

${OBJ_DIR}/Ppm.o: ${INCLUDE_DIR}/Ppm.hpp ${SRC_DIR}/Ppm.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Ppm.cpp -o ${OBJ_DIR}/Ppm.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/Pgm.hpp ${INCLUDE_DIR}/Ppm.hpp ${INCLUDE_DIR}/Celula.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

clear:
	rm -f ./*.o
	rm -f ./*.gcda
	rm -f ./*.gcno
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.gcda
	rm -f ${OBJ_DIR}/*.gcno
