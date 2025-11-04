#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MyList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int v): data(v), next(nullptr) {}
    };
    Node* head;
public:
    MyList(): head(nullptr) {}
    ~MyList() { clear(); }
    void push_back(int value) {
        Node* n = new Node(value);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    void print() const {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
    void sort() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* cur = head;
            while (cur->next) {
                if (cur->data > cur->next->data) {
                    int tmp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = tmp;
                    swapped = true;
                }
                cur = cur->next;
            }
        } while (swapped);
    }
    void clear() {
        Node* t = head;
        while (t) {
            Node* nx = t->next;
            delete t;
            t = nx;
        }
        head = nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(nullptr));
    int n;
    cout << "Введите размер списка: ";
    cin >> n;
    MyList lst;
    for (int i = 0; i < n; ++i) lst.push_back(rand() % 100);
    cout << "\nИсходный список: ";
    lst.print();
    lst.sort();
    cout << "\nСписок после сортировки: ";
    lst.print();
    return 0;
}
