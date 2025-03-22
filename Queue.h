#pragma once
#include <iostream>

template <typename various>
struct Node {
    Node<various>* m_next = nullptr;
    various m_data;

    Node() = default;
    Node(various data) : m_data(data) {}
    template <typename... Args>
    Node(Args&&... args) : m_data(std::forward<Args>(args)...) {}
};

template <typename T>
class Queue {
private:
    size_t m_size;
    Node<T>* m_front;
    Node<T>* m_back;
public:
    Queue() : m_size(0), m_front(nullptr), m_back(nullptr) {}
    ~Queue() {
        if (m_size == 0) {
            return;
        }

        Node<T>* curr = m_front;
        while (curr->m_next) {
            curr = curr->m_next;
            m_front->m_next = nullptr;
            delete m_front;
            m_front = curr;
        }
        delete curr;
    }
    bool isEmpty() {
        return m_size == 0;
    }
    size_t size() {
        return m_size;
    }
    Node<T>* front() {
        return m_front;
    }
    Node<T>* back() {
        return m_back;
    }
    void push(T& val) {
        Node<T>* newNode = new Node<T>(val);

        if (m_size == 0) {
            m_front = newNode;
            m_back = newNode;
        }
        else {
            m_back->m_next = newNode;
            m_back = newNode;
        }

        m_size++;
    }
    template <typename... Args>
    void emplace(Args&&... args) {
        Node<T>* newNode = new Node<T>(std::forward<Args>(args)...);

        if (m_size == 0) {
            m_front = newNode;
            m_back = newNode;
        }
        else {
            m_back->m_next = newNode;
            m_back = newNode;
        }

        m_size++;
    }
    T pop() {
        if (m_size == 0) {
            throw std::runtime_error("Nothing to pop from the Queue!");
        }

        T r = m_front->m_data;

        if (m_front == m_back) {
            delete m_front;
        }
        else {
            Node<T>* temp = m_front;
            m_front = m_front->m_next;
            temp->m_next = nullptr;
            delete temp;
        }
        m_size--;

        return r;
    }
    void swap(Queue<T>& other) noexcept {
        if (this != &other) {
            Node<T>* tempnode = this->m_front;
            this->m_front = other.m_front;
            other.m_front = tempnode;
            tempnode = this->m_back;
            this->m_back = other.m_back;
            other.m_back = tempnode;
            size_t tempsizet = this->m_size;
            this->m_size = other.m_size;
            other.m_size = tempsizet;
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Queue<T>& q) {
    os << "F [";
    if (q.front()) {
        Node<T>* curr = q.front();
        do {
            os << curr->m_data;
            if (curr->m_next) {
                os << ", ";
                curr = curr->m_next;
            }
            else {
                curr = nullptr;
            }
        } while (curr);
    }
    os << "] B";
    return os;
}