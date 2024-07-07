#include<iostream>
using namespace std;
 #define SIZE 100
 char stack[SIZE];
 int top = -1;

char pop(){
    if(top == -1){
        return '0';
    }else{
        char x = stack[top];
        top--;
        return x;
    }
}

void push(char x){
    if(top == SIZE-1){
        cout<< "Overflow\n";
    }else{
        top++;
        stack[top] = x;
    }
}

bool opencheck(char c){
    switch(c){
        case '(':
        case '{':
        case '[':
            return true;
            break;
        default:
            return false;
            break;
    }
}
bool closecheck(char c){
    switch(c){
        case ')':
        case '}' :
        case ']':
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool notpair(char o , char c){
    if(o == '[' && c == ']') return false;
    else if(o == '(' && c == ')') return false;
    else if(o == '{' && c == '}') return false;
    else return true;
}

void checky(string str){
    char c = str[0];
    char x;
    int flag = 0;
    int i = 1;
    while(c!='#'){
        if(opencheck(c)){
            push(c);
        }else if(closecheck(c)){
            x = pop();
            if(notpair(x,c) && x == '0' ){
                flag = 1;
                break;
            }
        }
        c = str[i];
        i++;   
    }
    if(flag == 0 && top == -1){
        cout<<"The paranthesis is balanced\n";
    }else{
        cout << "The paranthesis is not balanced\n";
    }
}



int main(){
    cout<<"Enter the expression: ";
    string str;
    cin >> str;
    str = str + '#';
    checky(str);
    return 0;
}