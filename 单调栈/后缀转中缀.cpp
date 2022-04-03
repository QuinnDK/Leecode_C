#include<bits/stdc++.h>
using namespace std;

int level(char ch){
    switch (ch){
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return 0;
    }
}

string InToPost(string str){
    stack<char> temp; 
    string back = ""; 
    for (int i = 0; i < str.length(); i++){
        switch (str[i]){
        case '(': 
            temp.push('(');
            break;
        case ')': 
            while (!temp.empty() && temp.top() != '('){
                back += temp.top();
                temp.pop();
            }
            temp.pop();
            break;
        default:
            if (str[i] >= '0' && str[i] <= '9') {
                if (str[i + 1] < '0' || str[i + 1] > '9'){
                    back += str[i];
                    back += ' '; 
                }else{
                    back += str[i];
                }
            }else if (temp.empty() || temp.top() == '(' || (temp.top() != '(' && level(str[i]) > level(temp.top()))){
                temp.push(str[i]);
            }else{
                while (!temp.empty() && level(str[i]) <= level(temp.top())){
                    back += temp.top();
                    temp.pop();
                }
                temp.push(str[i]);
            }
            break;
        }
    }

    while (!temp.empty()){
        back += temp.top();
        temp.pop();
    }
    return back;
}

double Result(string back){
    double tempNum, num1, num2;
    stack<double> tempStack; 
    for (int i = 0; i < back.length(); i++){
        string tempStr = "";
        if (back[i] >= '0' && back[i] <= '9')
        {
            while (back[i] != ' ')
            {
                tempStr += back[i];
                i++;
            }
            tempNum = stod(tempStr);
            tempStack.push(tempNum);
        }
        else if (back[i] != ' ')
        {
            num1 = tempStack.top();
            tempStack.pop();
            num2 = tempStack.top();
            tempStack.pop();
        }
        switch (back[i])
        {
        case '+':
            tempNum = num2 + num1;
            tempStack.push(tempNum);
            break;
        case '-':
            tempNum = num2 - num1;
            tempStack.push(tempNum);
            break;
        case '*':
            tempNum = num2 * num1;
            tempStack.push(tempNum);
            break;
        case '/':
            tempNum = num2 / num1;
            tempStack.push(tempNum);
            break;
        }
    }
    return tempStack.top();
}



int main(){
    string str;
    cin >> str;
    string back = InToPost(str);
    cout << back << endl;
    double r = Result(back);
    cout << r;
    return 0;
}