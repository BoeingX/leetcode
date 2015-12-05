/**
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */
#include <queue>
using namespace std;
class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
        void push(int x) {
            q.push(x);
        }
    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmp;
        while(q.size() > 1){
            int x = q.front();
            q.pop();
            tmp.push(x);
        }
        q = tmp;
    }
    // Get the top element.
    int top() {
        queue<int> tmp;
        int x;
        while(q.size() > 0){
            if(q.size() == 1)
                x = q.front();
            int y = q.front();
            q.pop();
            tmp.push(y);
        }
        q = tmp;
        return x;
    }
    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
