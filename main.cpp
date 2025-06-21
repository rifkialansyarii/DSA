#include <iostream>

struct Node{
    int id;
    std::string itemName;
    std::string category;
    int stock;

    struct Node *next;
};

void addItem(Node *&head, int id, const std::string &itemName, const std::string &category, int stock);
void deleteItem(Node *&head, int id);
void insertItem(Node *prevNode, int id, const std::string &itemName, const std::string &category, int stock);

int main(){
    Node *inventory = nullptr;

    addItem(inventory, 1, "Mikrotik", "Router", 1);
    addItem(inventory, 2, "Switch", "Router", 5);
    addItem(inventory, 3, "Ruijie", "Access Point", 30);
    addItem(inventory, 5, "UTP Cable", "Cable", 2);
    deleteItem(inventory, 3);
    insertItem(inventory->next, 3, "Fiber Optik", "Cable", 5);
    insertItem(inventory->next->next, 4, "Splicer", "Splicing equipment", 2);

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

void deleteItem(Node *&head, int id){
    if (head == nullptr){
        std::cout << "Inventory is empty";
    }else if (head->id == id){
        Node *hapus = head;
        head = head->next;
        delete hapus;
        std::cout << "Item deleted successfully!" << std::endl;
    }else{
        Node *current = head;
        while(current->next != nullptr && current->next->id != id){
            current = current->next;
        }

        Node *hapus = current->next;
        current->next = hapus->next;
        delete hapus;
        std::cout << "Item deleted successfully!" << std::endl;
    }
}

void insertItem(Node *prevNode, int id, const std::string &itemName, const std::string &category, int stock){
    if(prevNode == nullptr){
        std::cout << "Previous Node cannot be NULL";
        return;
    }else{
        Node *newNode = new Node{id, itemName, category, stock, prevNode->next};
        prevNode->next = newNode;
    };

};

