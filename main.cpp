#include <iostream>
#include <string>

int currentId = 1; // ID otomatis

struct Node
{
    int id;
    std::string itemName;
    std::string category;
    int stock;
    struct Node *next;
};

void dMenu();
void addItem(Node *&head, const std::string &itemName, const std::string &category, int stock);
void deleteItem(Node *&head, int id);
void insertItem(Node *prevNode, const std::string &itemName, const std::string &category, int stock);
void insertItemSorted(Node *&head, int id, const std::string &itemName, const std::string &category, int stock);
void updateItem(Node *head, int id, const std::string &itemName = "", const std::string &category = "", int stock = -1);
void displayItems(Node *head);

int main()
{
    Node *inventory = nullptr;
    int pilihan;

    do
    {
        dMenu();
        std::cout << "Pilih menu: ";
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan)
        {
        case 1:
        {
            int stock;
            std::string name, category;
            std::cout << "Masukkan Nama Barang: ";
            std::getline(std::cin, name);
            std::cout << "Masukkan Kategori: ";
            std::getline(std::cin, category);
            std::cout << "Masukkan Jumlah Stok: ";
            std::cin >> stock;

            addItem(inventory, name, category, stock);
            break;
        }
        case 2:
        {
            int id;
            std::cout << "\nMasukkan ID yang ingin dihapus: ";
            std::cin >> id;
            deleteItem(inventory, id);
            break;
        }
        case 3:
        {
            int id, stock;
            std::string name, category;
            std::cout << "\nMasukkan ID item yang ingin diupdate: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Nama baru (biarkan kosong jika tidak diubah): ";
            std::getline(std::cin, name);
            std::cout << "Kategori baru (biarkan kosong jika tidak diubah): ";
            std::getline(std::cin, category);
            std::cout << "Stok baru (-1 jika tidak diubah): ";
            std::cin >> stock;

            updateItem(inventory, id, name, category, stock);
            break;
        }
        case 4:
        {
            int id, stock;
            std::string name, category;
            std::cout << "Masukkan ID baru: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Masukkan Nama Barang: ";
            std::getline(std::cin, name);
            std::cout << "Masukkan Kategori: ";
            std::getline(std::cin, category);
            std::cout << "Masukkan Jumlah Stok: ";
            std::cin >> stock;

            insertItemSorted(inventory, id, name, category, stock);
            break;
        }
        case 5:
            displayItems(inventory);
            break;
        case 6:
            std::cout << "\nTerima kasih! Program selesai.\n";
            break;
        default:
            std::cout << "Pilihan tidak valid!\n";
            break;
        }

        std::cout << "\nTekan Enter untuk melanjutkan...";
        std::cin.ignore();
        std::cin.get();
    } while (pilihan != 6);

    return 0;
}

void dMenu()
{
    system("cls");
    std::cout << "=== Aplikasi Inventaris Barang ===" << std::endl;
    std::cout << "1. Tambah Item" << std::endl;
    std::cout << "2. Hapus Item" << std::endl;
    std::cout << "3. Update Item" << std::endl;
    std::cout << "4. Insert Item" << std::endl;
    std::cout << "5. Tampilkan Semua Item" << std::endl;
    std::cout << "6. Keluar" << std::endl;
}

void addItem(Node *&head, const std::string &itemName, const std::string &category, int stock)
{
    Node *newNode = new Node{currentId++, itemName, category, stock, nullptr};

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteItem(Node *&head, int id)
{
    if (head == nullptr)
    {
        std::cout << "Inventory is empty" << std::endl;
    }
    else if (head->id == id)
    {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        std::cout << "Item deleted successfully!" << std::endl;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr && current->next->id != id)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            std::cout << "Item not found" << std::endl;
        }
        else
        {
            Node *hapus = current->next;
            current->next = hapus->next;
            delete hapus;
            std::cout << "Item deleted successfully!" << std::endl;
        }
    }
}

void insertItem(Node *prevNode, const std::string &itemName, const std::string &category, int stock)
{
    if (prevNode == nullptr)
    {
        std::cout << "Previous Node cannot be NULL";
        return;
    }
    else
    {
        Node *newNode = new Node{currentId++, itemName, category, stock, prevNode->next};
        prevNode->next = newNode;
    }
}

void insertItemSorted(Node *&head, int id, const std::string &itemName, const std::string &category, int stock)
{
    // Cek duplikasi ID
    Node *cek = head;
    while (cek != nullptr) {
        if (cek->id == id) {
            std::cout << "ID sudah ada, silakan gunakan ID lain.\n";
            return;
        }
        cek = cek->next;
    }

    Node *newNode = new Node{id, itemName, category, stock, nullptr};

    if (head == nullptr || id < head->id) {
        newNode->next = head;
        head = newNode;
        std::cout << "Item berhasil disisipkan!\n";
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->id < id) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    std::cout << "Item berhasil disisipkan!\n";
}

void updateItem(Node *head, int id, const std::string &itemName, const std::string &category, int stock)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->id == id)
        {
            if (itemName != "")
                current->itemName = itemName;
            if (category != "")
                current->category = category;
            if (stock != -1)
                current->stock = stock;

            std::cout << "Item updated successfully!" << std::endl;
            return;
        }

        current = current->next;
    }

    std::cout << "Item with id " << id << " is not found!" << std::endl;
}

void displayItems(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Inventaris kosong.\n";
        return;
    }

    std::cout << "\nDaftar Inventaris:\n";
    std::cout << "ID\tNama\tKategori\tStok\n";
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->id << "\t" << current->itemName << "\t" << current->category << "\t\t" << current->stock << "\n";
        current = current->next;
    }
}
