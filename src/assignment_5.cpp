#include <RcppEigen.h>

// via the depends attribute we tell Rcpp to create hooks for
// RcppEigen so that the build process will know what to do
//
// [[Rcpp::depends(RcppEigen)]]



double L2norm(const Eigen::VectorXd &x){
  return(std::sqrt(x.dot(x)));
}

//[[Rcpp::export]]
Rcpp::List GramSchmidt(const Eigen::MatrixXd &X){

  int n=X.rows();
  int k=X.cols();
  Eigen::MatrixXd U(n,k);
  Eigen::MatrixXd E(n,k);
  U.setZero();
  E.setZero();
  U.col(0)=X.col(0);
  E.col(0)=U.col(0)/L2norm(U.col(0));

  for(int i=1;i<k;i++){
    ///Your code goes here
  }


  return(Rcpp::List::create(Rcpp::Named("U")=U,Rcpp::Named("E")=E));
}

//[[Rcpp::export]]
Rcpp::List GramSchmidtQR(const Eigen::MatrixXd &X){

  int p=X.rows();


  Rcpp::List GS=GramSchmidt(X);
  Eigen::MatrixXd U=GS["U"];
  Eigen::MatrixXd E=GS["E"];
  Eigen::MatrixXd Q(p,p);
  Eigen::MatrixXd R(p,p);


  //Your code goes here

  return(Rcpp::List::create(Rcpp::Named("Q")=Q,Rcpp::Named("R")=R));
}




//[[Rcpp::export]]
Rcpp::List GramSchmidtSVD(const Eigen::MatrixXd &X){

  int n=X.rows();
  int p=X.cols();

  Eigen::ArrayXd d(std::min(n,p));
  d.setZero();



  Eigen::MatrixXd U(n,n);
  Eigen::MatrixXd V(n,n);


  //Your code goes here:

  return(Rcpp::List::create(Rcpp::Named("d")=d,
                            Rcpp::Named("U")=U,
                            Rcpp::Named("V")=V));
}

//[[Rcpp::export]]
Rcpp::List GramSchmidtPCA(const Eigen::MatrixXd &X){

  int n=X.rows();
  int p=X.cols();
  Eigen::ArrayXd l(p);
  Eigen::MatrixXd U(p,p);

  return(Rcpp::List::create(Rcpp::Named("l")=l,
                            Rcpp::Named("U")=U));
}

