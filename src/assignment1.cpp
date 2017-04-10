#include <Rcpp.h>
#include <math.h>
#include <list>
//[[Rcpp::depends(Rcpp)]]
// [[Rcpp::plugins(cpp11)]]


//[[Rcpp::export(name="sample_hash_func")]]
void simple_hash_fn(Rcpp::IntegerVector keys, int num_slots=9){

  const int slots=num_slots;
  std::vector<std::list<int> > hash_table(slots,std::list<int>());

  for(auto key=keys.begin(); key!=keys.end(); key++){
    int k = *key;

    int hash_index = k % slots;

    Rcpp::Rcout<<"Key: "<<k<<" is being inserted at index: "<<hash_index<<std::endl;

    auto *hash_list = &hash_table[hash_index];

    hash_list->push_front(k);

    int post_size = hash_list->size();

    for(auto it=hash_list->begin(); it!=hash_list->end(); it++){
      Rcpp::Rcout<<*it<<"\t";
    }
    Rcpp::Rcout<<std::endl;
  }
}



//[[Rcpp::export(name="two_stack_fun")]]
void two_stacks_fn(const Rcpp::IntegerVector keys, const Rcpp::LogicalVector pushStackA, const Rcpp::LogicalVector popStackA){
  using namespace Rcpp;
  //The plan is to grow the stacks from opposite sides of the array
  // Rcpp::IntegerVector retvec();
  if(keys.size()!=pushStackA.size()){
    Rcpp::stop("keys must be the same size as isStackA");
  }
  size_t n=keys.size();
  std::vector<int> stacks(n,0);

  int A_front=NA_INTEGER;

  int B_front=NA_INTEGER;


  //First we'll demonstrate pushing on to the stack
  for(int i=0; i<n; i++){
    if(pushStackA[i]==TRUE){
      if(Rcpp::IntegerVector::is_na(A_front)){
        A_front=n-1;
      }else{
        A_front--;
      }
      //If the tops of the stacks meet, we quit in protest
      if(A_front==B_front){
        Rcpp::stop("Out of room!");
      }
      Rcpp::Rcout<<"Pushing key["<<i<<"]"<<":("<<keys[i]<<") on stack A"<<std::endl;
      stacks[A_front]=keys[i];
    }else{
      if(Rcpp::IntegerVector::is_na(A_front)){
        B_front=0;
      }else{
        B_front++;
      }
      if(A_front==B_front){
        Rcpp::stop("Out of room!");
      }
      Rcpp::Rcout<<"Pushing key["<<i<<"]"<<":("<<keys[i]<<") on stack B"<<std::endl;
      stacks[B_front]=keys[i];
    }
  }

  int n_pop=popStackA.size();
  for(int i=0; i<n_pop; i++){
    if(popStackA[i]==TRUE){
      if(Rcpp::IntegerVector::is_na(A_front)){
        Rcpp::Rcout<<"Stack A is empty!"<<std::endl;
      }else{
        Rcpp::Rcout<<"Popping  element "<<stacks[A_front]<<" from stack A"<<std::endl;
        A_front++;
        if(A_front==n){
          A_front=NA_INTEGER;
        }
      }
    }else{
      if(Rcpp::IntegerVector::is_na(B_front)){
        Rcpp::Rcout<<"Stack B is empty!"<<std::endl;
      }else{
        Rcpp::Rcout<<"Popping  element "<<stacks[B_front]<<" from stack B"<<std::endl;
        B_front--;
        if(B_front==0){
          B_front=NA_INTEGER;
        }
      }
    }
  }
}
