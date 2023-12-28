#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
    
    bool check(int k){
        Node* current = head;
        while (current) {
            if (current->key == k) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_last(int key) {
        if(!check(key)){
        
        Node* new_node = new Node{key, nullptr};
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }}

    void add_first(int key) {
        Node* new_node = new Node{key, nullptr};
        if (!head) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    void add_after(int key, int target_key) {
        
        
        if(!check(key)){
            
            Node* new_node = new Node{key, nullptr};
        Node* current = head;
        while (current) {
            if (current->key == target_key) {
                new_node->next = current->next;
                current->next = new_node;
                if (current == tail) {
                    tail = new_node;
                }
                return;
            }
            current = current->next;
        }
            
        }
    }

    void add_before(int key, int target_key) {
        if(!check(key)){
            Node* new_node = new Node{key, nullptr};
        if (head && head->key == target_key) {
            new_node->next = head;
            head = new_node;
            return;
        }
        Node* current = head;
        while (current && current->next) {
            if (current->next->key == target_key) {
                new_node->next = current->next;
                current->next = new_node;
                if (current == tail) {
                    tail = new_node;
                }
                return;
            }
            current = current->next;
        }
        }
        
    }

    void remove(int key) {
    while (head && head->key == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
    }
    Node* current = head;
    while (current && current->next) {
        if (current->next->key == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            if (!current->next) {
                tail = current;
            }
        } else {
            current = current->next;
        }
    }
}


    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            Node* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        head = prev;
    }

    void print_list() {
        Node* current = head;
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linked_list;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        linked_list.add_last(key);
    }

    string command;
    int k, u, v;
    while (cin >> command) {
        if (command == "addlast") {
            cin >> k;
            linked_list.add_last(k);
        } else if (command == "addfirst") {
            cin >> k;
            linked_list.add_first(k);
        } else if (command == "addafter") {
            cin >> u >> v;
            linked_list.add_after(u, v);
        } else if (command == "addbefore") {
            cin >> u >> v;
            linked_list.add_before(u, v);
        } else if (command == "remove") {
            cin >> k;
            linked_list.remove(k);
        } else if (command == "reverse") {
            linked_list.reverse();
        } else if (command == "#") {
            break;
        }
    }

    linked_list.print_list();

    return 0;
}
