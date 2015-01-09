dyn.load("dataframe.so")

return.data.frame <- function() {
  .Call("return_data_frame")
}

d <- return.data.frame()
print(d)

print(is.data.frame(d)) #=> TRUE
