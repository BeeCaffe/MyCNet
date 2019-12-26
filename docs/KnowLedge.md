## Some Points when I use C++
### 1.In C++ we can not return a local object
As a result for C++ compiler will destruct any 
local object when the function is ended.So, if 
you return a local object, it might be an empty
object which may cause some problem.  
### 2.In C++ const object can not call a function which is not return a const value.
        //example
        class A{
            A& operator=(const A& x);
            bool empty();
        }
        
        //there is can not be complied
        //const object can only call const functions.
        A& operator=(const A& x){
            A.empty();//error
        }