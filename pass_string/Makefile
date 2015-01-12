
all: hello.so hello2.so

%.so: %.c
	R CMD SHLIB $<

.PHONY: clean

clean:
	rm -f hello.o hello.so hello2.o hello2.so
