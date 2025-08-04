#include <bits/stdc++.h>
using namespace std;
class Stack
{
    // properties
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack is Overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack is underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0 && top < size)
            return arr[top];

        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    Stack st(2);
    st.push(22);
    st.push(43);
    st.push(32);

    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.push(39);
    if (st.isEmpty())
    {
        cout << "Stack EMPTY" << endl;
    }
    else
    {
        cout << "Stack is NOT EMPTY" << endl;
    }

    /*
stack<int> s;

//push operation
s.push(3);
s.push(2);

//pop opeartion
s.pop();
cout<<"Printing top elemnt :"<<s.top()<<" ";
cout<<endl;
if(s.empty()){
    cout<<"Stack  is empty";
}
else{
    cout<<"Stack is not empty";
}
cout<<endl;*/
}