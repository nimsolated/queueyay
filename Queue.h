#pragma once
#include <iostream>

template <typename various>
struct Node {
    various m_data;
    Node<various>* m_next = nullptr;

    Node() = default;
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
    ~Queue();
    bool isEmpty();
    size_t size();
    Node<T>* front();
    Node<T>* back();
    void push(const T& val);
    template <typename... Args>
    void emplace(Args&&... args);
    T pop();
    void swap(Queue<T>& other) noexcept;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Queue<T>& q);