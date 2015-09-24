CC       = c++
FLAGS    = 
CFLAGS   = -g -O2 -w
DFLAGS   = -DPACKAGE=\"threadsystem\" -DVERSION=\"1.0\" -DPTHREAD=1 -DUNIX_MSG_Q=1 -DSTDC_HEADERS=1
IFLAGS   = -I ../include
TMLIB    =  ../Visual/libthreadclass.a
TMLIB_NV    = ../NoVisual/libthreadclass.a

OBJ_FILE = merge.o merge-main.o
EXE_FILE = merge 

${EXE_FILE}: ${OBJ_FILE}
	${CC} ${FLAGS}  -o ${EXE_FILE}  ${OBJ_FILE} ${TMLIB} -lpthread

merge.o: merge.cpp
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c merge.cpp

merge-main.o: merge-main.cpp
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c merge-main.cpp

noVisual: ${OBJ_FILE}
	${CC} ${FLAGS}  -o ${EXE_FILE}  ${OBJ_FILE} ${TMLIB_NV} -lpthread
					
clean:
	rm -f ${OBJ_FILE} ${EXE_FILE}

