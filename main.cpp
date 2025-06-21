#include <iostream>

struct Node{
    int id;
    std::string itemName;
    std::string category;
    int stock;

    struct Node *next;
};

void addItem(Node *&head, int id, const std::string &itemName, const std::string &category, int stock);

int main(){
    Node *inventory = nullptr;

    addItem(inventory, 1, "Mikrotik", "Router", 10);

    Node *current = inventory;
    while(current != nullptr){
        std::cout << "No: " << current->id << " | ";
        std::cout << "Name: " << current->itemName << " | ";
        std::cout << "Category: " << current->category << " | ";
        std::cout << "Stock: " << current->stock << std::endl;

        current = current->next;
    }

}


void addItem(Node *&head, int id, const std::string &itemName, const std::string &category, int stock){
    Node *newNode = new Node{id, itemName, category, stock, nullptr};

    if (head == nullptr){
        head = newNode;
    }else {
        Node *current = head;
        while(current->next != nullptr){
        current = current->next;
        }
        current->next = newNode;
    }

};

