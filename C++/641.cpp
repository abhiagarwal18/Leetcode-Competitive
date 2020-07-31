class MyCircularDeque {
public:
    vector<int> l;
    int size ;
    int k,cnt ;
    int st, end; // HERE ST AND END ARE THE EMPTY POSITIONS FROM WHERE WE WANT TO INSERT/DELETE !!!!
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        l.resize(k);
        size = k;
        st = 0;
        cnt =0;
        end = k-1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(!isFull()){
            l[st] = value;
            st = (st+1)%size;
            cnt ++;
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(!isFull()){
            l[end] = value;
            end = (end -1 + size)%size;
            cnt ++;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(!isEmpty()){
            st = (st -1 +size) %size;
            cnt --;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(!isEmpty()){
            end = (end+1)%size;
            cnt--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return  !isEmpty() ? l[(st -1 + size)%size] : -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return !isEmpty() ? l[(end + 1)%size] : -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */