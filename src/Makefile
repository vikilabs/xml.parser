#Compiler
CC = gcc
AR = ar
STRIP = strip

TARGET_PATH=../lib
TARGET =${TARGET_PATH}/xml_parser.a
OBJECT =xml_parser.o

CP = cp
RM = rm -f
CFLAGS = -DDEBUG

#DEFINITIONS
DEFS = -DTRACES_VERIFICATION 
DEFS += -DDEBUG_TRACES

#Source Files
SOURCE_FILE = *.c

#LIBS to include
#LIBS = -ldl

all:
	mkdir -p ${TARGET_PATH}
	$(CC) -c -Wall $(DEFS) ${CFLAGS} -o $(OBJECT) $(SOURCE_FILE) $(E_LIB_SRC) $(INC1) $(INC2) $(E_INC) ${LIBS} 
	$(AR) rcs $(TARGET) $(OBJECT)
	$(RM) $(OBJECT)
