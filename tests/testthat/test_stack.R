context("stack demo")


test_that("pushing and popping works as expected",{


  keys <- 1:10

  pushA <- sample(c(T,F),length(keys),replace=T)

  popA <- sample(c(T,F),length(keys),replace=T)

  two_stack_fun(keys,pushA,popA)
})

test_that("pushing only on A and popping on A works",{

  keys <- 1:10
  pushA <- rep(T,length(keys))
  popA <- rep(T,length(keys))
  two_stack_fun(keys,pushA,popA)

})


test_that("pushing only on A and popping on B works",{

  keys <- 1:10
  pushA <- rep(T,length(keys))
  popA <- rep(F,length(keys))
  two_stack_fun(keys,pushA,popA)

})

test_that("pushing only on B and popping on A works",{

  keys <- 1:10
  pushA <- rep(F,length(keys))
  popA <- rep(T,length(keys))
  two_stack_fun(keys,pushA,popA)

})