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
void updateItem(Node *head, int id, const std::string &itemName = "", const std::string &category = "", int stock = -1);

int main(){
    Node *inventory = nullptr;

    addItem(inventory, 1, "Mikrotik", "Router", 1);
    addItem(inventory, 2, "Switch", "Router", 5);
    addItem(inventory, 3, "Ruijie", "Access Point", 30);
    addItem(inventory, 4, "UTP Cable", "Cable", 2);
    updateItem(inventory, 4, "Fiber Optik");

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
        std::cout << "Inventory is empty" << std::endl;
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

        if (current->next == nullptr){
            std::cout << "Item not found" << std::endl;
        }else{
            Node *hapus = current->next;
            current->next = hapus->next;
            delete hapus;
            std::cout << "Item deleted successfully!" << std::endl;
        }
    }
};

void insertItem(Node *prevNode, int id, const std::string &itemName, const std::string &category, int stock){
    if(prevNode == nullptr){
        std::cout << "Previous Node cannot be NULL";
        return;
    }else{
        Node *newNode = new Node{id, itemName, category, stock, prevNode->next};
        prevNode->next = newNode;
    };

};

void updateItem(Node *head, int id, const std::string &itemName, const std::string &category, int stock){
    Node *current = head;
    while(current != nullptr){
        if(current->id == id){
            if(itemName != "") current->itemName = itemName;
            if(category != "") current->category = category;
            if(stock != -1) current->stock = stock;
            
            std::cout << "Item updated successfully!" << std::endl;
            return;
        }

        current = current->next;
    }

    std::cout << "Item with id " << id << " is not found!" << std::endl;
}

