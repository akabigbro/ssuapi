objects=$(shell ls *.mk | sed 's/.mk/.o/g')

all: $(objects)

lib: $(objects)
	$(CXX) $(CFLAGS) --shared -o libsocketutils.so $(objects)

clean:
	rm -f *.o *.so

include $(wildcard *.mk)
