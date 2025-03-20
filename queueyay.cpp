#include "Queue.cpp"

template <typename Various>
void QueueInfo(Queue<Various>& q) {
    std::cout << "Size: " << q.size() << std::endl << "Is Empty: " << q.isEmpty() << std::endl;
}

int main()
{
    Queue<std::string> qee;
    std::string str1 = "Yes";
    std::string str2 = "No";
    qee.push(str1); qee.emplace("Maybe"); qee.push(str2);
    Queue<std::string> poo;
    poo.emplace("Absolutely"); poo.emplace("Never");
    std::cout << "qee: " << qee << std::endl << "poo: " << poo << std::endl;
    QueueInfo(qee);
    QueueInfo(poo);

    try {
        std::cout << "qee popped: " << qee.pop() << std::endl;
        std::cout << "poo popped: " << poo.pop() << std::endl;
        std::cout << "qee: " << qee << std::endl << "poo: " << poo << std::endl;
        QueueInfo(qee);
        QueueInfo(poo);
        qee.front()->m_data = "Perchance";
        qee.back()->m_data = (qee.back()->m_data == "No") ? "Not a chance!" : "I don't know";
        std::cout << "qee: " << qee << std::endl << "poo: " << poo << std::endl;
        qee.swap(poo);
        std::cout << "qee: " << qee << std::endl << "poo: " << poo << std::endl;
        qee.back()->m_data = (qee.back() == qee.front()) ? "Fart F. Fartington" : "Piss P. Pissington";
        std::cout << "qee: " << qee << std::endl << "poo: " << poo << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}