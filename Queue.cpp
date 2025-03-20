#include "Queue.h"

template <typename T>
Queue<T>::~Queue() {
	Node<T>* curr = m_front;
	while (curr->m_next) {
		curr = curr->m_next;
		m_front->m_next = nullptr;
		delete m_front;
		m_front = curr;
	}
	delete curr;
}

template <typename T>
bool Queue<T>::isEmpty() {
	return m_size == 0;
}

template <typename T>
size_t Queue<T>::size() {
	return m_size;
}

template <typename T>
Node<T>* Queue<T>::front() {
	return m_front;
}

template <typename T>
Node<T>* Queue<T>::back() {
	return m_back;
}

template <typename T>
void Queue<T>::push(const T& val) {
	Node<T>* newNode = new Node<T>;

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

template <typename T>
template <typename... Args>
void Queue<T>::emplace(Args&&... args) {
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

template <typename T>
T Queue<T>::pop() {
	if (!m_front) {
		throw runtime_error("Nothing to pop from the Queue!");
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

template <typename T>
void Queue<T>::swap(Queue<T>& other) noexcept {
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

template <typename T>
std::ostream& operator<<(std::ostream& os, Queue<T>& q) {
	os << "F [";
	if (q.m_front) {
		Node<T>* curr = q.m_front;
		do {
			os << curr->m_data;
			if (curr->m_next) {
				os << ", ";
				curr = curr->m_next;
			}
			else {
				curr = nullptr;
			}
		} while(curr)
	}
	os << "] B"
	return os;
}