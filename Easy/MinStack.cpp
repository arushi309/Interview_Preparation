/*  Min Stack  */

/*

    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
 

    Example:

    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]

    Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2

*/

class MinStack {
public:
    /** initialize your data structure here. */
    long long minElm;
    stack<long long>st;
    MinStack() {

    }
    
    void push(long long x) {
        if(st.empty())
        {
            st.push(x);
            minElm = x;
            return;
        }
        if(x>minElm)
        {
            st.push(x);
        }
        else
        {
            st.push(2*(long long)(x)-minElm);
            minElm=x;
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        long long x= st.top();
        st.pop();
        if(x>minElm)
            return;
        else
        {
            int y = minElm;
            minElm = 2*minElm-x;
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long x= st.top();
        return (x>=minElm) ? x : minElm;
    }
    
    int getMin() {
        return minElm;
    }
};