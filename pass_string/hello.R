dyn.load("hello.so")

hello <- function(str) {
  .C("hello", as.character(str))
  NULL
}

hello("world")  # => Hello world
hello(123)      # => Hello 123
hello(1:3)      # => Hello 1     (only the first element of the array is used)
hello(NULL)     # =>             (str == NULL in the C function)
hello(list())   # =>             (zero elements; str == NULL in the C function)


# What happends Without as.character()?
hello0 <- function(str) {
  .C("hello", str)
  NULL
}

hello0("world") # => Hello world
# If you always call with a string, you don't need as.character().
# But, if you give something else...
#hello0(123)    # => segmentation fault


# Vectorised version. Now length is given as the second argument.
hello2 <- function(str) {
  .C("hello2", as.character(str), length(str))
  NULL
}

hello2(1:3)     # => Hello 1
                #    Hello 2
                #    Hello 3

