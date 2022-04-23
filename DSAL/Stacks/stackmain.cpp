#include<iostream>
#include<bits/stdc++.h>
#include "stacks.cpp"

using namespace std;

class Expression{
    private:
    string inf,post,pre;
    public:
    int precedence(char c);
    int associativity(char c1,char c2);
    void inftopost();
    void inftopre();
    string strreverse(string e);                                                                                                                                                                                                                                                                                                                                    
    void EvalPost();
    void EvalPre();
};

int Expression::precedence(char c){
    if(c == '+' or c=='-') return 1;
    else if(c=='/' or c=='*') return 2;
    else if(c=='^') return 3;
    return 0;
}

int Expression::associativity(char c1,char c2){
    if(c1=='^' and c2=='^') return 1;
    else return 0;
}

string Expression::strreverse(string e){
    Stack<char> s;
    
    for(int i=0;i<e.length();i++){
        s.push(e[i]);
    }
    e = "";
    while(!s.isempty()){
        e = e + s.peek();
        s.pop();
    }
    return e;
}

void Expression::inftopost(){
    Stack<char> s;
    cout<<"Enter infix expression: ";
    cin>>inf;
    post = "";
    for(int i=0;i<inf.length();i++){
        switch(inf[i]){
            case '(':
            s.push('(');
            break;
            case '+':
            case '*':
            case '/':
            case '-':
            case '^':
            while(!s.isempty() and s.peek()!='(' and precedence(inf[i])<=precedence(s.peek()) ){
                if(precedence(inf[i])==precedence(s.peek()) and associativity(inf[i],s.peek())) break;
                post = post + s.peek();
                s.pop();
            }
            s.push(inf[i]);
            break;
            case ')':
            while(s.peek()!='('){
                post = post+s.peek();
                s.pop();
            }
            s.pop();
            break;
            default:
            post = post+inf[i];
            break;
        }
    }
    while(!s.isempty()) {
        post = post + s.peek();
        s.pop();
    }
    cout<<"Postfix expression is: "<<post<<endl;
}

void Expression::inftopre(){
    Stack<char> s;
    cout<<"Enter infix expression: ";
    cin>>inf;
    pre = "";
    for(int i=inf.length()-1;i>=0;i--){
        switch(inf[i]){
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
            while(!s.isempty() and s.peek()!=')' and precedence(inf[i])<=precedence(s.peek())){
                if(precedence(inf[i])==precedence(s.peek()) and !associativity(inf[i],s.peek())) break;
                pre = pre + s.peek();
                s.pop();
            }
            s.push(inf[i]);
            break;
            case ')':
            s.push(')');
            break;
            case '(':
            while(s.peek()!=')'){
                pre = pre + s.peek();
                s.pop();
            }
            s.pop();
            break;
            default:
            pre = pre + inf[i];
            break;
        }
    }
    while(!s.isempty()) {
        pre = pre + s.peek();
        s.pop();
    }
    pre = strreverse(pre);
    cout<<"Prefix expression is: "<<pre<<endl;
}

void Expression::EvalPost(){
    Stack<int> s;
    string post2="";
    int val[26];
    for(int i=0;i<post.length();i++){
        if(isalpha(post[i])){
            cout<<"Enter value of "<<post[i]<<" : ";
            cin>>val[int(post[i])-97];
        }
    }
    for(int i=0;i<post.length();i++){
        if(isalpha(post[i])){
            post2 = post2+to_string((val[int(post[i])-97]))+',';
        }
        else post2 = post2+post[i]+',';
    }
    post2.erase(post2.length()-1);
    int op1,op2,i=0;
    while(i<post2.length()){
        string p = "";
        bool isdig=true;
        while(post2[i]!=','){
            if(!isdigit(post2[i])) {
                isdig= false;
                i++;
                break;
            }
            p = p + post2[i];
            i++;
        }
        if(isdig){
            s.push(stoi(p));
        }
        else{
            op2 = s.peek();
            s.pop();
            op1 = s.peek();
            s.pop();
            if (post2[i-1] == '+')
				s.push(op1+op2);
			else if (post2[i-1] == '-')
				s.push(op1-op2);
			else if (post2[i-1] == '*')
				s.push(op1*op2);
			else if (post2[i-1] == '/')
				s.push(op1/op2);
			else
				s.push(pow(op1,op2));
        }
        i++;
    }
    int res = s.peek();
    s.pop();
    cout<<"Result: "<<res<<endl;
}

void Expression::EvalPre(){
    Stack<int> s;
    string pre2="";
    int val[26],j=0;
    for(int i=0;i<pre.length();i++){
        if(isalpha(pre[i])){
            cout<<"Enter value of "<<pre[i]<<" : ";
            cin>>val[int(pre[i])-97];
        }
    }
    for(int i=0;i<pre.length();i++){
        if(isalpha(pre[i])){
            pre2 = pre2+to_string((val[int(pre[i])-97]))+',';
        }
        else pre2 = pre2+pre[i]+',';
    }
    pre2.erase(pre2.length()-1);
    int op1,op2,i=pre2.length()-1;
    for(i;i>=0;i--){
        string p = "";
        bool isdig=true;
        while(pre2[i]!=','){
            if(!isdigit(pre2[i])) {
                isdig= false;
                i--;
                break;
            }
            p = p + pre2[i];
            i--;
        }p = strreverse(p);
        if(isdig){
            s.push(stoi(p));
        }
        else{
            op1 = s.peek();
            s.pop();
            op2 = s.peek();
            s.pop();
            if (pre2[i+1] == '+')
				s.push(op1+op2);
			else if (pre2[i+1] == '-')
				s.push(op1-op2);
			else if (pre2[i+1] == '*')
				s.push(op1*op2);
			else if (pre2[i+1] == '/')
				s.push(op1/op2);
			else
				s.push(pow(op1,op2));
        }
    }
    int res = s.peek();
    s.pop();
    cout<<"Result: "<<res<<endl;
}

int main(){

    
     int ch;
     Expression e1;
    while(true){
        cout<<endl;
        cout<<"1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre"<<endl;
        cout<<"Enter command: ";
        cin>>ch;
        switch(ch){
            case 1:
            e1.inftopost();
            break;
            case 2:
            e1.inftopre();
            break;
            case 3:
            e1.EvalPost();
            break;
            case 4:
            e1.EvalPre();
            break;
            case 5:
            exit(0);
        }
    }
    return 0;
}

/*

1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre
Enter command: 1
Enter infix expression: a+b*c
Postfix expression is: abc*+

1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre
Enter command: 3
Enter value of a : 4 
Enter value of b : 5
Enter value of c : 3
Result: 19

1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre
Enter command: 1
Enter infix expression: a^b^c
Postfix expression is: abc^^

1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre
Enter command: 1
Enter infix expression: a+b+c
Postfix expression is: ab+c+

1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre
Enter command: 2
Enter infix expression: a+b*c
Prefix expression is: +a*bc

1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre
Enter command: 4
Enter value of a : 5 
Enter value of b : 6
Enter value of c : 3
Result: 23

1.Inf to Post, 2.Inf to Pre, 3.Eval Post, 4.Eval Pre
Enter command: 5

*/