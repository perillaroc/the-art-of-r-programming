mtl <- function(ichunk, m) {
  n <- ncol(m)
  matches <- 0
  for (i in ichunk) {
    if (i < n) {
      rowi <- m[i,]
      matches <- matches + 
        sum(m[(i+1):n,] %*% rowi)
    }
  }
}

mutlinks <- function(cls, m) {
  n <- nrow(m)
  nc <- length(cls)
  
  ichunks <- split(1:n, 1:nc)
  
  counts <- clusterApply(cls, ichunks, mtl, m)
  do.call(sum, counts) / (n*(n-1)/2)
}