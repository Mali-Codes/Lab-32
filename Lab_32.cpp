#include "Car.h"
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int initalSize = 2;

int main() {
    srand(time(0));

    deque<Car> carDeque;

    for (int i = 0; i < initalSize; i++) {
        Car c;
        carDeque.push_back(c);
    }

    cout << "Start queue" << endl;
    

}

