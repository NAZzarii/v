#include <iostream>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int a, int b) {
        x = a;
        y = b;
    }

    void print() {
        cout << "(" << x << ", " << y << ")";
    }
};

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T d) {
        data = d;
        next = nullptr;
    }
};

template <typename T>
class List {
public:
    Node<T>* head;

    List() {
        head = nullptr;
    }

    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void pop_front() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Vector {
public:
    int size;
    List<Point> points;

    Vector() {
        size = 0;
    }

    void addFront(Point p) {
        points.push_front(p);
        size++;
    }

    void addBack(Point p) {
        points.push_back(p);
        size++;
    }

    void removeFront() {
        if (size > 0) {
            points.pop_front();
            size--;
        }
    }

    void Print() {
        Node<Point>* temp = points.head;
        while (temp != nullptr) {
            temp->data.print();
            cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Vector v;
    
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);

    v.addBack(p1);
    v.addBack(p2);
    v.addFront(p3);

    v.Print();

    v.removeFront();
    
    v.Print();

    return 0;
}
