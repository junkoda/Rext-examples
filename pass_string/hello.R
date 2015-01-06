dyn.load("hello.so")

hello <- function(str) {
  .C("hello", as.character(str))
  NULL
}

hello("world")  # => Hello world
hello(123)      # => Hello 123
hello(1:3)      # => Hello 1     (only the first element of the array is used)

# What happends Without as.character()?
hello0 <- function(str) {
  .C("hello", str)
  NULL
}

hello0("world") # => Hello world
# If you always call with a string, you don't need as.character().

# but, if you give something else...
#hello0(123)     # => segmentation fault!

# Even with as.character, you get segmentation fault for an object with 0
# elements
#hello(NULL)    # => segmentation fault!

# Vectorised version now length is given as the second argument
hello2 <- function(str) {
  .C("hello2", as.character(str), length(str))
  NULL
}

hello2(1:3)     # => Hello 1
                #    Hello 2
                #    Hello 3

hello2(NULL)    # => OK, no segmentation fault
