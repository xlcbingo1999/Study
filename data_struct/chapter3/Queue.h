class Queue{
public:
    Queue();
    bool empty()const ;
    Error_code serve();
    Error_code retrieve(Queue_entry &x) const;
    Error_code append(const Queue_entry &x); 
    void print()const;
    //void change();
protected:
    int count;
    int front,rear;
    Queue_entry entry[maxQueue];
};
