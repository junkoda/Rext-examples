dyn.load("hello2.so")

hello2 <- function(arg)
  .Call("hello2", arg)

hello2("world")               # => Hello world
hello2(c("world1", "world2")) # => Hello world1
                              #    Hello world2
