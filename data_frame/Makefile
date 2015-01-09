
all: dataframe.so

%.so: %.c
	R CMD SHLIB $<

.PHONY: clean

clean:
	rm -f dataframe.o dataframe.so
