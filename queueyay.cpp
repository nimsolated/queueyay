#include "Queue.h"

int main()
{
    // Create Queue objects
    Queue<int> q1;
    Queue<std::string> q2;

    // Push (insert) values into the Queue
    int n = 4;
    while (--n != 0) {
        q1.push(n);
    }
    
    // Emplace (construct then insert) values into the Queue
    q2.emplace("Potato"); q2.emplace("Tomato");

    // Output the size of the Queues
    std::cout << "Size of q1: " << q1.size() << std::endl
              << "Size of q2: " << q2.size() << std::endl;

    // Output the contents of the Queues
    std::cout << "q1: " << q1 << std::endl
              << "q2: " << q2 << std::endl;

    // Pop and display the Queue's most front element
    // Queue<T>::isEmpty() will return true when the Queue is empty
    // (in other words, Queue's size is 0)
    while (!q1.isEmpty()) {
        std::cout << q1.pop() << " ";
    }
    std::cout << '\n';
    while (!q2.isEmpty()) {
        std::cout << q2.pop() << " ";
    }
    std::cout << '\n';

    // Refilling q1 for further testing
    std::cout << "Refilling q1..." << std::endl;
    q1.emplace(5); q1.emplace(13); q1.emplace(27);

    // Output the Queue's front and back data value
    std::cout << "q1's front: " << q1.front() << std::endl
              << "q1's back: " << q1.back() << std::endl;

    // q3 to test the swapping of two Queues
    Queue<int> q3;
    q3.emplace(9); q3.emplace(99); q3.emplace(999);

    std::cout << "q1: " << q1 << std::endl
              << "q3: " << q3 << std::endl;

    // Swap contents of q1 with q3
    std::cout << "Swapping q1 and q3..." << std::endl;
    q1.swap(q3);
    std::cout << "q1: " << q1 << std::endl
              << "q2: " << q3 << std::endl;
}