C++ = g++
DEPS = operations.h stringProcessing.h
OBJ = stringCalc.o operations.o stringProcessing.o
CFLAGS = -I.

%.o: %.c $(DEPS)
	$(C++)  -c -o $@ $< $(CFLAGS)

calculator: $(OBJ) 
	$(C++) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o