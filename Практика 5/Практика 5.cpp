// Практика 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
class DoublyLinkedList {
    struct Node {
        int data;
        Node* next; // следующий
        Node* prev; // предыдущий

        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head; // голова
    Node* tail; // хвост
    size_t size; // размер списка

public:
    DoublyLinkedList() :head(nullptr), tail(nullptr), size(0) {}; // конструктор

    void PushFront(int n) { //Добавление элемента в начало списка
        Node* newNode = new Node(n);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void PushBack(int n) { //Добавление элемента в конец списка
        Node* newNode = new Node(n);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    void PopFront() { //Удаление элемента с начала списка
        if (head == nullptr) {
            std::cout << "Двусвязный список пуст\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        size--;
    }
    void PopBack() { //Удаление элемента с конца списка
        if (tail == nullptr) {
            std::cout << "Двусвязный список пуст\n";
            return;
        }
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }
    void Display() { //Вывод всех элементов списка на экран
        Node* current = head;
        std::cout << "Элементы двусвязного списка:\n";
        while (current != nullptr) {
            std::cout << current->data << "\n";
            current = current->next;
        }
    }
    void BubbleSort() { // Сортировка элементов по возрастанию
        if (head == nullptr || head->next == nullptr) {
            std::cout << "Двусвязный список пуст или содержит один элемент \n";
            return;
        }
        bool swap;
        do {
            swap = false;
            Node* current = head;
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swap = true;
                }
                current = current->next;
            }
        } while (swap);
    }
    void RemoveDuplicates() { // Удаление дубликатов
        if (head == nullptr || head->next == nullptr) {
            std::cout << "Двусвязный список пуст или содержит один элемент \n";
            return;
        }
        Node* current = head;
        while (current!= nullptr) {
            Node* run = current ->next;
            Node* prevRun = current;
            while (run != nullptr) {
                if (run->data == current->data) {
                    Node* toDelete = run;

                    if (run == tail) {
                        tail = prevRun;
                        tail->next = nullptr;
                    }
                    else {
                        prevRun->next = run->next;
                        run->next->prev = prevRun;
                    }
                    run = run->next;
                    delete toDelete;
                    size--;
                }
                else {
                    prevRun = run;
                    run = run->next;
                }
            }
            current = current->next;
        }
    }
};
int main()
{
    DoublyLinkedList list;
    std::cout << "Меню:\n1 - Добавить элемент в начало.\n2 - Добавить элемент в конец.\n3 - Удалить элемент с начала.\n4 - Удалить элемент с конца.\n5 - Отобразить список.\n6 - Сортировать список.\n7 - Удалить дубликаты.\n8 - Выйти.\n";
    int menu = 0;
    int n = 0;
    do {
        std::cin >> menu;
        switch (menu) {
        case 1:
            std::cout << "Введите элемент для добавления:\n";
            std::cin >> n;
            list.PushFront(n);
            list.Display();
            break;
        case 2:
            std::cout << "Введите элемент для добавления:\n";
            std::cin >> n;
            list.PushBack(n);
            list.Display();
            break;
        case 3:
            list.PopFront();
            list.Display();
            break;
        case 4:
            list.PopBack();
            list.Display();
            break;
        case 5:
            list.Display();
            break;
        case 6:
            list.BubbleSort();
            list.Display();
            break;
        case 7:
            list.RemoveDuplicates();
            list.Display();
            break;
        case 8:
            std::cout << "Выход";
            break;
        default:
            std::cout << "Неверный ввод!";
        }
    } while (menu != 8);
}

    // Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
    // Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

    // Советы по началу работы 
    //   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
    //   2. В окне Team Explorer можно подключиться к системе управления версиями.
    //   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
    //   4. В окне "Список ошибок" можно просматривать ошибки.
    //   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
    //   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.