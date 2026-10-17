class MyCircularQueue {
public:
    int *arr;
    int frontindex;
    int rearindex;
    int cnt;
    int size;
    MyCircularQueue(int k) {
        size  = k;
        arr = new int[k];
        frontindex  = 0;
        rearindex = 0;
        cnt = 0;
    }
    
    bool enQueue(int value) {
        if(cnt==size)
        return false;
        arr[rearindex] = value;
        rearindex = (rearindex+1)%size;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt==0)
        return false;
        arr[frontindex]=-1;
        frontindex = (frontindex+1)%size;
        cnt--;
        return true;
    }
    
    int Front() {
       if(cnt==0)
       return -1;
       return arr[frontindex]; 
    }
    
    int Rear() {
        if(cnt==0)
        return -1;
       return arr[(rearindex-1+size)%size];;   
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */