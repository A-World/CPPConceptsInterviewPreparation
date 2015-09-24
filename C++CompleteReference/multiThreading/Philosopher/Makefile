CC       = c++
FLAGS    = 
CFLAGS   = -g -O2 -w
DFLAGS   = -DPACKAGE=\"threadsystem\" -DVERSION=\"1.0\" -DPTHREAD=1 -DUNIX_MSG_Q=1 -DSTDC_HEADERS=1
IFLAGS   = -I ../include
TMLIB    =  ../Visual/libthreadclass.a
TMLIB_NV    = ../NoVisual/libthreadclass.a

OBJ_FILE = Philosopher.o Philosopher-main.o
EXE_FILE = Philosopher 

${EXE_FILE}: ${OBJ_FILE}
	${CC} ${FLAGS}  -o ${EXE_FILE}  ${OBJ_FILE} ${TMLIB} -lpthread

Philosopher.o: Philosopher.cpp
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c Philosopher.cpp

Philosopher-main.o: Philosopher-main.cpp
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c Philosopher-main.cpp

noVisual: ${OBJ_FILE}
	${CC} ${FLAGS}  -o ${EXE_FILE}  ${OBJ_FILE} ${TMLIB_NV} -lpthread
					
clean:
	rm -f ${OBJ_FILE} ${EXE_FILE}

