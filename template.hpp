//  tmplate.hpp
//  Fisheries Integrated Modeling System (FIMS)

#ifndef template_hpp
#define template_hpp

//inherit from model_base
#include "../common.hpp" 
#include <map>
#include <vector>
#include <iostream>


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
  virtual T evaluate(const T& t)=0; //"= 0;" means this must be implemented in child
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
   virtual T evaluate(const T& t) {
     std::cout<<"evaluate in Name1 received "<<t<<"as a method parameter, returning "<<(t+1)<<std::endl;
     return t+1; //unique logic to Name1 class
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
   virtual T evaluate(const T& t) {
     std::cout<<"evaluate in Name2 received "<<t<<"as a method parameter, returning "<<(t*t)<<std::endl;
     return t*t; //unique logic to Name2 class
   }

};
  
/**
 * Add additional implementations below.
 */
  



} //end namespace

#endif /*template_hpp */
