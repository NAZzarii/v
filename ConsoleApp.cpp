#include <iostream>
#include <string>

using namespace std;

struct Vagon {
    int number;
    int capacity;
    int passengers;
};

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class List {
public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    List(const List& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node<T>* temp = other.head;
        while (temp != nullptr) {
            PushBack(temp->data);
            temp = temp->next;
        }
    }

    List& operator=(const List& other) {
        if (this == &other) return *this;
        while (head != nullptr) {
            DeleteFromHead();
        }
        Node<T>* temp = other.head;
        while (temp != nullptr) {
            PushBack(temp->data);
            temp = temp->next;
        }
        return *this;
    }

    ~List() {
        while (head != nullptr) {
            DeleteFromHead();
        }
    }

    void PushFront(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void PushBack(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void DeleteFromHead() {
        if (head == nullptr) return;
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void DeleteFromTail() {
        if (tail == nullptr) return;
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void InsertAt(int pos, T val) {
        if (pos <= 0) {
            PushFront(val);
            return;
        }
        if (pos >= size) {
            PushBack(val);
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        Node<T>* newNode = new Node<T>(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void DeleteAt(int pos) {
        if (pos < 0 || pos >= size || head == nullptr) return;
        if (pos == 0) {
            DeleteFromHead();
            return;
        }
        if (pos == size - 1) {
            DeleteFromTail();
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }
};

class Train {
private:
    string model;
    int countVagons;
    List<Vagon> vagons;

public:
    Train() {
        model = "Default Train";
        countVagons = 0;
    }

    Train(string m) {
        model = m;
        countVagons = 0;
    }

    Train(const Train& other) {
        model = other.model;
        countVagons = other.countVagons;
        vagons = other.vagons; 
    }

    void AddFront(Vagon v) {
        vagons.PushFront(v);
        countVagons++;
    }

    void AddBack(Vagon v) {
        vagons.PushBack(v);
        countVagons++;
    }

    void RemoveFront() {
        if (countVagons > 0) {
            vagons.DeleteFromHead();
            countVagons--;
        }
    }

    void RemoveBack() {
        if (countVagons > 0) {
            vagons.DeleteFromTail();
            countVagons--;
        }
    }

    void InsertVagon(int pos, Vagon v) {
        vagons.InsertAt(pos, v);
        countVagons++;
    }

    void DeleteVagon(int pos) {
        if (countVagons > 0 && pos >= 0 && pos < countVagons) {
            vagons.DeleteAt(pos);
            countVagons--;
        }
    }

    void Show() {
        cout << "Модель потяга: " << model << " | Кількість вагонів: " << countVagons << "\n";
        Node<Vagon>* temp = vagons.head;
        while (temp != nullptr) {
            cout << "[Вагон " << temp->data.number 
                 << " | Місць: " << temp->data.capacity 
                 << " | Пасажирів: " << temp->data.passengers << "] -> ";
            temp = temp->next;
        }
        cout << "Кінець\n\n";
    }
};

int main() {
    Train myTrain("Тарпан");

    Vagon v1 = {1, 40, 35};
    Vagon v2 = {2, 40, 40};
    Vagon v3 = {3, 40, 15};
    Vagon v4 = {4, 40, 10};

    myTrain.AddBack(v1);
    myTrain.AddBack(v2);
    myTrain.AddFront(v3);
    myTrain.Show();

    myTrain.InsertVagon(1, v4); 
    myTrain.Show();

    myTrain.DeleteVagon(2); 
    myTrain.Show();

    Train copiedTrain = myTrain;
    copiedTrain.Show();

    return 0;
}
