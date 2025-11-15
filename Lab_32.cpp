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
            break;
        }
    }


}

