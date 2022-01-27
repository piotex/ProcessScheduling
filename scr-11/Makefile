CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc
OBJ=./obj

__start__: ${OBJ} ${OBJ}/main.o ${OBJ}/Proces.o ${OBJ}/Processor.o 
	g++ -o szer ${OBJ}/main.o ${OBJ}/Proces.o ${OBJ}/Processor.o 
${OBJ}:	
	mkdir ${OBJ}

${OBJ}/main.o: main.cpp Proces.h Processor.h
	g++ ${CPPFLAGS} -o ${OBJ}/main.o main.cpp

${OBJ}/Proces.o: Proces.cpp Proces.h
	g++ ${CPPFLAGS} -o ${OBJ}/Proces.o Proces.cpp

${OBJ}/Processor.o: Processor.cpp Processor.h
	g++ ${CPPFLAGS} -o ${OBJ}/Processor.o Processor.cpp

clear:
	rm ${OBJ}/*.o szer
