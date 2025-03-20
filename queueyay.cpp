#include "Queue.cpp"

template <typename Various>
void QueueInfo(Queue<Various>& q) {
    std::cout << "Size: " << q.size() << std::endl << "Is Empty: " << q.isEmpty() << std::endl;
}

int main()
{
    Queue<std::string> qee;
    QueueInfo(qee);
    qee.push("Yes"); qee.emplace("Maybe"); qee.push("No");
    QueueInfo(qee);
}