//
//  main.cpp
//  Priority queue
//
//  Created by Marina Balamoon on 4/26/26.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class PriorityQueue {
private:
    vector<T> data;
    double (*priority)(T);

public:
    PriorityQueue(double (*p)(T)) {
        priority = p;
    }

    void push(T value) {
        data.push_back(value);

        int i = data.size() - 1;

        while (i > 0 && priority(data[i]) > priority(data[i - 1])) {
            T temp = data[i];
            data[i] = data[i - 1];
            data[i - 1] = temp;
            i--;
        }
    }

    T pop() {
        T value = data[0];
        data.erase(data.begin());
        return value;
    }
};

double myPriority(int x) {
    return x;
}

int main() {
    PriorityQueue<int> pq(myPriority);

    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(7);

    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
}
