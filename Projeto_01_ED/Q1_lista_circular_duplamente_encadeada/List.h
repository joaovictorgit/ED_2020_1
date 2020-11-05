#ifndef LIST_H
#define LIST_H

struct Node;
class List{
    private:
        Node* head = nullptr;
        int _size_list;
    public:
        List();
        ~List();
        void clear();
        bool isEmpty();
        void push_back(int key); 
        void print();
        int size();
        void printReverse();
        int pop_back();
        void insertAfter(int key, int k); 
        Node* search(int key);
        void remove(int key); 
        void removeAll(int key); 
        void removeNode(Node *p);
        int removeNodeAt(int k);
        void concat(List *lst);
        List *copy(); 
        void copyArray(int n, int arr[]);
        bool equal(List *lst);
        List* separate(int n);
        void merge_lists(List *list2);
};
#endif