//  name.hpp
//  Fisheries Integrated Modeling System (FIMS)

#ifndef name_h
#define name_h

#include <map>
#include <vector>
/*
 * name namespace
 */
namespace fims{

/**
 * name base class. Inherits from modelbase.
 */
template <class T>

class name_base:public model_base<T>{
protected:

public:
  virtual T evaluate(const T& i)=0;
};
  
  template <class T>
/* template class implements name_base
 * 
 * This is the default constructor.
 * 
 */
class Name: public NameBase<T>{

  std::vector<std::map<T, T> > local_variable;

public:
  std::map<T, T> local_variable;
  
  enum NAME_TYPE{
    OPTION1=0,
    OPTION2
  }
    
    /*
   *Default constructor
   */
  name(){
  }
  
 
  /**
   * Destructor; this method deleted the von Bertalanffy growth object.
   */
  ~ name(){
    std::cout <<"I just deleted name object" << std::endl;
  }
  
   virtual T evaluate(const T& i, NAME_TYPE t) {
     return this->name[t][i];
   }

};
/**
 *If there is only one implementation of this name type, the file can end here. Add secondary implementations below.
 */



} /end namespace

#endif /*name_h */
