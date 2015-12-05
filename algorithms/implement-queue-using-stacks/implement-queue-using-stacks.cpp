/**
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */
#include <stack>
using namespace std;
class Queue {
private:
    stack<int> s;
public:
    //Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }
    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        while(s.size() > 1){
            int x = s.top();
            s.pop();
            tmp.push(x);
        }
        s.pop();
        while(!tmp.empty()){
            int x = tmp.top();
            tmp.pop();
            s.push(x);
        }
    }
    // Get the front element.
    int peek(void) {
        stack<int> tmp;
        int y;
        while(!s.empty()){
            if(s.size() == 1)
                y = s.top();
            int x = s.top();
            s.pop();
            tmp.push(x);
        }
        while(!tmp.empty()){
            int x = tmp.top();
            tmp.pop();
            s.push(x);
        }
        return y;
    }
    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
