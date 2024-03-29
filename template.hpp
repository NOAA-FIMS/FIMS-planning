//  tmplate.hpp
//  Fisheries Integrated Modeling System (FIMS)

#ifndef template_hpp
#define template_hpp

//inherit from model_base
#include "../common.hpp" 
#include <map>
#include <vector>
#include <iostream>

/**
 * In this example, we utilize the concept of inheritence and 
 * polymorphism (https://www.geeksforgeeks.org/polymorphism-in-c/). All
 * classes inherit from model_base. Name1 and Name2 inherit from NameBase.
 * Classes Name1 and Name2 must implement they're own version of 
 * "virtual T evaluate(const T& t)", which will be unique. 
 */


/*
 * name namespace
 */
namespace fims{

/**
 * NameBase class. Inherits from modelbase.
 */
template <class T>

class NameBase: public model_base<T>{
protected:

public:
  virtual T Evaluate(const T& t)=0; //"= 0;" means this must be implemented in child
};
  
/* 
* Template class inherits from  NameBase
*/
template <class T>
class Name1: public NameBase<T>{

public:
 
    
  /*
   *Default constructor
   *Initialize any memory here.
   */
  Name1(){
  }
  
 
  /**
   * Destructor; this method destructs Name1 object.
   * Delete any allocated memory here.
   */
  ~ Name1(){
    std::cout <<"I just deleted Name1 object" << std::endl;
  }
  
   /**
    * Note: this function must have the same signature as evaluate in NameBase.
    * Overloaded virtual function. This is polymorphism, meaning the 
    * signature has the same appearance, but the function itself has unique logic.
    * 
    * @param t
    * @return t+1
    */
   virtual T Evaluate(const T& t) {
     std::cout<<"evaluate in Name1 received "<<t<<"as a method parameter, returning "<<(t+1)<<std::endl;
     return t+1; //unique logic for Name1 class
   }

};

  /* 
* Template class inherits from  NameBase
*/
template <class T>
class Name2: public NameBase<T>{

public:
 
    
  /*
   *Default constructor.
   *Initialize any memory here.
   */
  Name2(){
  }
  
 
  /**
   * Destructor; this method destructs the Name2 object.
   * Delete any allocated memory here.
   */
  ~ Name2(){
    std::cout <<"I just deleted Name2 object" << std::endl;
  }
  
   /**
    * Note: this function must have the same signature as evaluate in NameBase.
    * Overloaded virtual function. This is polymorphism, meaning the 
    * signature has the same appearance, but the function itself has unique logic.
    * 
    * @param t
    * @return t^2
    */
   virtual T Evaluate(const T& t) {
     std::cout<<"evaluate in Name2 received "<<t<<"as a method parameter, returning "<<(t*t)<<std::endl;
     return t*t; //unique logic for Name2 class
   }

};
  
/**
 * Add additional implementations below.
 */
  



} //end namespace

/**
 *Example usage:
 *
 * void main(int argc, char** argv){
 *    NameBase<double>* name = NULL; //pointer to a NameBase object
 *    Name1<double> n1; //inherits from NameBase
 *    Name2<double> n2; //inherits from NameBase
 *
 *    name = &n1; //name now points to n1
 *    name->Evalute(2.0); //unique logic for n1
 *
 *    name = &n2; //name now points to n2
 *    name->Evalute(2.0); //unique logic for n2
 * }
 *
 * Output:
 * evaluate in Name1 received 2 as a method parameter, returning 3
 * evaluate in Name2 received 2 as a method parameter, returning 4
 *
 */



#endif /*template_hpp */
