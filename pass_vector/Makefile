
all: vector.so

%.so: %.c
	R CMD SHLIB $<

.PHONY: clean

clean:
	rm -f vector.o vector.so
