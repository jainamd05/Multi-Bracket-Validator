#include <iostream>
using namespace std ;

bool isEmpty(int top ){
    if (top == -1) return true ;
    else return false ;
}

bool isFull(int top){
    if (top == 4) return true ;
    else return false ;
}

class Stack{
    char s[5] ;
    int top ;
    public :
        Stack(){
            top = -1 ;
        }

        void push(char ch){
            if(top == 4){
                cout << "Stack Overflow" << endl ;
            }
            else{
                s[++top] = x ;
            }
        }

        char pop(){
            if(top == -1){
                cout << "Stack Underflow" << endl ;
                return '\0' ;
            }
            else{
                return s[top--] ;
            }
        }

        bool isEmpty( top ) ; 
        bool isFull( top ) ;

        bool checkParenthesis(string expr){
            for(char ch : expr){
                if(ch == '('){
                    push(ch) ;
                }
                else if(ch == ')'){
                    if(isEmpty()){
                        return false ;
                    }
                    pop() ;
                }
            }
            return isEmpty() ;
        }
};