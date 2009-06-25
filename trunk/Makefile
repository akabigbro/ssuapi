objects=$(shell ls *.mk | sed 's/.mk/.o/g')
CFLAGS+=-I../sockets -I../thread
EXTRAOBJS=../sockets/*.o ../thread/thread.o
LIB=socketutils

all: $(objects)

lib: $(objects)
	$(CXX) $(CFLAGS) --shared -o lib$(LIB).so $(objects) $(EXTRAOBJS)

clean:
	rm -f *.o lib$(LIB).so

include $(wildcard *.mk)
