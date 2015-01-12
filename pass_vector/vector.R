dyn.load("vector.so")

ivector <- function(val) {
  .Call("ivector", val)
}

# > ivector(1:3)
# 1
# 2
# 3

# > ivector(c(1.1, 1.2, 1.3))
# Error in ivector(v) :
#   INTEGER() can only be applied to a 'integer', not a 'double'
