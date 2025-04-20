#include <iostream>
#include <vector>

// Deque의 기능을 구현해보는 문제

class Deque {
private:
    std::vector<int> queue; 
    int front = 0;
    int rear = 0;
    int capacity = 2000000;  

public:
    Queue() {
        queue.resize(capacity);
    }

    void Push(int elm) {
        queue[rear++] = elm;
    }

    int Pop() {
        if (Empty()) {
            return -1;
        }
        else {
            return queue[front++];
        }
    }

    int Size() const {
        return (rear - front);
    }

    int Empty() const {
        return (front == rear);
    }

    int Front() {
        if (!Empty())
            return queue[front];
        else
            return -1;
    }

    int Back() {
        if (!Empty())
            return queue[rear - 1];  
        else
            return -1;
    }
};

int main() {
    int num;
    std::cin >> num;

    Deque deq;

    while (num--) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push") {
            int elm;
            std::cin >> elm;
            deq.Push(elm);
        }
        else if (cmd == "pop") {
            std::cout << deq.Pop() << std::endl;
        }
        else if (cmd == "size") {
            std::cout << deq.Size() << std::endl;
        }
        else if (cmd == "empty") {
            std::cout << deq.Empty() << std::endl;
        }
        else if (cmd == "front") {
            std::cout << deq.Front() << std::endl;
        }
        else if (cmd == "back") {
            std::cout << deq.Back() << std::endl;
        }
    }

    return 0;
}
