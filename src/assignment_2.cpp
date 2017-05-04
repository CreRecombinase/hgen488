#include <RcppEigen.h>

// via the depends attribute we tell Rcpp to create hooks for
// RcppEigen so that the build process will know what to do
//
// [[Rcpp::depends(RcppEigen)]]


// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//
using namespace Rcpp;

//[[Rcpp::export]]
NumericMatrix mat_mult(NumericMatrix A, NumericMatrix B){
  size_t n=A.nrow();
  size_t m=A.ncol();
  size_t p=B.ncol();
  NumericMatrix C(n,p);
  for (int i = 0; i < n; i++){
    for(int j = 0;j<p; j++){
      double sum=0;
      for (int k=0;k<m; k++){
        sum+=A(i,k)*B(k,j);
      }
      C(i,j) = sum;
    }
  }
  return(C);
}




//[[Rcpp::export]]
Eigen::MatrixXd mat_mult_eigen(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B){
  return(A*B);
}



//[[Rcpp::export]]
Eigen::MatrixXd rep_mat_mult_eigen(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B,int reps){
  Eigen::MatrixXd C(A.rows(),B.cols());
  for(int i=0; i<reps;i++){
//    Rcpp::Rcout<<i<<std::endl
    C.noalias()+=A*B;
  }
  return(C);
}



