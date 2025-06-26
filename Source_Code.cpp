#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

//Create double linked list with key and value 
struct Node{
    int key,val;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};

//making class for lru cache 
class LRU_Cache{
private:
    int capacity;
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    //delete function to delete the node which we want to
    void Delete_Node(Node* node){
        
        node->prev->next=node->next;
        node->next->prev=node->prev;
        
    }
    //Funtion to add node after head node
    void Add_front(Node* node){
        head->next->prev=node;
        node->next=head->next;
        head->next=node;
        node->prev=head;
    }

public:
    //Constructor with the value of capactiy of the LRU Cache object
    LRU_Cache(int cap){
        capacity=cap;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }

    //put function with key and value inputs that inserts the key and value in LRU cache 
    void put(int key,int value){
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            temp->val=value;
            Delete_Node(temp);
            Add_front(temp);
        }
        else{
            Node* temp=new Node(key,value);
            if((int)mp.size()<capacity){
                mp[key]=temp;
                Add_front(temp);
            }
            else{
                mp.erase(tail->prev->key);
                Delete_Node(tail->prev);
                delete tail->prev;
                Add_front(temp);
                mp[key]=temp;
            }
        }
    }
    
    //function that returns value is the key is present else returns -1
    int get(int key){
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            Delete_Node(temp);
            Add_front(temp);
            return temp->val;
        }
        else{
            return -1;
        }
    }

    //destructor that wll help to destroy any object created
    ~LRU_Cache() {
        Node* temp=head;
        while(temp){
            Node* next=temp->next;
            delete temp;
            temp=next;
        }
    }


};


int main() {
    fastio
    LRU_Cache cache(3); // capacity = 3
    cout << "Inserting (101, 5001)" << endl;
    cache.put(101, 5001);

    cout << "Inserting (202, 6002)" << endl;
    cache.put(202, 6002);

    cout << "Inserting (303, 7003)" << endl;
    cache.put(303, 7003);

    cout << "Accessing key 101 -> Value = " << cache.get(101) << endl; // Expected: 5001

    cout << "Inserting (404, 8004) -> should evict LRU (202)" << endl;
    cache.put(404, 8004);

    cout << "Accessing key 202 -> Value = " << cache.get(202) << " (Expected: -1, since evicted)" << endl;

    cout << "Overwriting key 303 with new value 9999" << endl;
    cache.put(303, 9999);

    cout << "Accessing key 303 -> Value = " << cache.get(303) << " (Expected: 9999)" << endl;

    cout << "Inserting (505, 10005) -> should evict LRU (404)" << endl;
    cache.put(505, 10005);

    cout << "Accessing key 404 -> Value = " << cache.get(404) << " (Expected: -1, since evicted)" << endl;

    cout << "Accessing key 101 -> Value = " << cache.get(101) << " (Expected: 5001)" << endl;
    cout << "Accessing key 505 -> Value = " << cache.get(505) << " (Expected: 10005)" << endl;

    cout << "\n Testing edge case with capacity = 1\n" << endl;
    LRU_Cache single(1);

    cout << "Inserting (888, 8888)" << endl;
    single.put(888, 8888);

    cout << "Accessing key 888 -> Value = " << single.get(888) << endl;

    cout << "Inserting (999, 9999) -> should evict 888" << endl;
    single.put(999, 9999);

    cout << "Accessing key 888 -> Value = " << single.get(888) << " (Expected: -1, evicted)" << endl;
    cout << "Accessing key 999 -> Value = " << single.get(999) << endl;

    return 0;
}
