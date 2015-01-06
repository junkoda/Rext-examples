
all: hello.so

%.so: %.c
	R CMD SHLIB $<

.PHONY: clean

clean:
	rm -f hello.o hello.so
