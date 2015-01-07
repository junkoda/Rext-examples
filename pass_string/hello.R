dyn.load("hello.so")

hello <- function(val) {
  .C("hello", as.character(val))
  NULL
}

hello("world")  # => Hello world
hello(123)      # => Hello 123
hello(1:3)      # => Hello 1     (only the first element of the array is used)
hello(NULL)     # =>             (str == NULL in the C function)
hello(list())   # =>             (zero elements; str == NULL in the C function)


# What happends without as.character()?
hello0 <- function(val) {
  .C("hello", val)
  NULL
}

hello0("world") # => Hello world
# If you always call with a string, you don't need as.character().
# But, if you give something else...
#hello0(123)    # => segmentation fault


# Vectorised version. Now length is given as the second argument.
vhello <- function(val) {
  .C("hello2", as.character(val), length(val))
  NULL
}

vhello(1:3)     # => Hello 1
                #    Hello 2
                #    Hello 3

