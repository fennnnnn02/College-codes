// Expression Conversion

#include <iostream>
#include "stacks.cpp"

class ExpressionConversion{

    // Infix to Postfix Conversion
    private:
    string inf,post;
    public:
    int precedence(char c);
    int associativity(char c1,char c2);
    void inftopost();
};

int ExpressionConversion::precedence(char c){

    // Returns precedence according to the operator

    if(c == '+' or c=='-') return 1;
    else if(c=='/' or c=='*') return 2;
    else if(c=='^') return 3;
    return 0;
}

int ExpressionConversion::associativity(char c1,char c2){

    // Right to Left
    if(c1=='^' and c2=='^') return 1;

    // Left to Right
    else return 0;
}

void ExpressionConversion::inftopost(){
    Stack<char> s;
    cout<<"Enter infix expression: ";
    cin>>inf;
    post = "";
    for(int i=0;i<inf.length();i++){

        switch(inf[i]){

            // Case : '('
            case '(':
            s.push('(');
            break;

            // Case: Operators
            case '+':
            case '*':
            case '/':
            case '-':
            case '^':
            while(!s.isempty() and s.peek()!='(' and precedence(inf[i])<=precedence(s.peek()) ){

                // if precedence is equal and associativity is from right to left dont pop
                if(precedence(inf[i])==precedence(s.peek()) and associativity(inf[i],s.peek())) break;
                post = post + s.peek();
                s.pop();
            }

            // Push the operator after checking of previous operators is done
            s.push(inf[i]);
            break;

            // Case: '('
            case ')':
            // Pop until '(' is found
            while(s.peek()!='('){
                post = post+s.peek();
                s.pop();
            }
            s.pop();
            break;

            // Case: Operands
            default:
            post = post+inf[i];
            break;
        }
    }
    // If stack is still not empty pop all elements and add it to postfix expression
    while(!s.isempty()){
        post = post + s.peek();
        s.pop();
    }
    cout<<"Postfix expression is: "<<post<<endl;
}

int main(){
    ExpressionConversion e;
    int i = 3;
    while(i--){
    cout<<"-------------------------------------------------------"<<endl;
    e.inftopost();
    cout<<"-------------------------------------------------------"<<endl;
    }
    return 0;
}


/*

Output

-------------------------------------------------------
Enter infix expression: k+l-m*n+(o^p)*w/u/v*t+q
Postfix expression is: kl+mn*-op^w*u/v/t*+q+
-------------------------------------------------------
-------------------------------------------------------
Enter infix expression: a^b^c
Postfix expression is: abc^^
-------------------------------------------------------
-------------------------------------------------------
Enter infix expression: a+b+c
Postfix expression is: ab+c+
-------------------------------------------------------  

*/