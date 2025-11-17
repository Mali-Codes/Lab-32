#include "Car.h"
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int initalSize = 2;

int main() {
    srand(time(0));

    deque<Car> tollbooth;

    for (int i = 0; i < initalSize; i++) {
        Car c;
        tollbooth.push_back(c);
    }

    cout << "Start queue" << endl;
    
    for (auto& car : tollbooth) {
        cout << "    ";
        car.print();
    }


    int time = 1;

    while (!tollbooth.empty()) {
        cout << "\nTime " << time << ":\n";

        int action = rand() % 2;

        if (action == 0) {
            Car newCar;
            tollbooth.push_back(newCar);
            cout << "    New car arrived: ";
            newCar.print();
        }
        else {
            cout << "Paid toll: ";
            tollbooth.front().print();
            tollbooth.pop_front(); // take it out 
        }

        cout << "Queue: \n";

        if (tollbooth.empty()) {
            cout << "empty queue \n";
        } else {
            for (auto& car : tollbooth) {
                cout << "    ";
                car.print();
            }
        }
        
        time ++;
    
    }

    return 0;

}

void fourlanes() {
    cont int lanes = 4;
    const int initalQueue = 2;

    deque<Car> tollbooth[lanes];
}
