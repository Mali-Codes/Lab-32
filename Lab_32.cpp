#include "Car.h"
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

const int initalSize = 2;




void fourlanes() {
    const int lanes = 4;
    const int initalQueue = 2;

    deque<Car> tollbooth[lanes];

    for (int i = 0; i < lanes; i++) {
        for (int j = 0; j < initalQueue; j++) {
            Car c;
            tollbooth[i].push_back(c);
        }
    }

    for (int i = 0; i < lanes; i++) {
        cout << "  Lane " << i << ": " << tollbooth[i].size() << " cars \n";
    }

    cout << "Created" << lanes << "lanes" << endl;

    cout << "test the queue" << endl;

    cout << "First car in lane 2: ";
    tollbooth[2].front().print();

    cout << "First car in lane 0: ";
    tollbooth[0].front().print();
}

void testprobabilities() {
    const int lanes = 4;
    const int initalQueue = 2;
    const double payTollProb = 46;
    const double newCarProb = 39;
    const double laneSwitchProb = 15;

    deque<Car> tollbooth[lanes];

    for (int i = 0; i < lanes; i++) {   // from 4 lanes function
        for (int j = 0; j < initalQueue; j++) {
            Car c;
            tollbooth[i].push_back(c);
        }
    }

    cout << "Inital lanes: \n";
    for (int i = 0; i < lanes; i++) {
        cout << "lane " << i << ": " << tollbooth[i].size() << " cars \n";
    }

    cout << "siming one time period";

    for (int i = 0; i < lanes; i++) {
        if (tollbooth[1].empty()){
            
            int action = rand() % 2;

                if (action == 0) {
                    Car newCar;
                    tollbooth[i].push_back(newCar);
                    cout << "New car joined\n";
                } else {
                    cout << "No action\n";
                }
                continue;
            }
    }

        int randValue = rand() % 100 ;

        if (randValue < payTollProb) {
            cout << "toll paid";
            tollbooth[i].pop_front();
        } 
        else if (randValue < payTollProb + newCarProb) {
            cout << "New car joined" << randValue;
            Car newCar;
            tollbooth[i].push_back(newCar);

        }
}








int main() {
    // srand(time(0));

    // deque<Car> tollbooth;

    // for (int i = 0; i < initalSize; i++) {
    //     Car c;
    //     tollbooth.push_back(c);
    // }

    // cout << "Start queue" << endl;
    
    // for (auto& car : tollbooth) {
    //     cout << "    ";
    //     car.print();
    // }


    // int time = 1;

    // while (!tollbooth.empty()) {
    //     cout << "\nTime " << time << ":\n";

    //     int action = rand() % 2;

    //     if (action == 0) {
    //         Car newCar;
    //         tollbooth.push_back(newCar);
    //         cout << "    New car arrived: ";
    //         newCar.print();
    //     }
    //     else {
    //         cout << "Paid toll: ";
    //         tollbooth.front().print();
    //         tollbooth.pop_front(); // take it out 
    //     }

    //     cout << "Queue: \n";

    //     if (tollbooth.empty()) {
    //         cout << "empty queue \n";
    //     } else {
    //         for (auto& car : tollbooth) {
    //             cout << "    ";
    //             car.print();
    //         }
    //     }
        
    //     time ++;
    
    // }

    testprobabilities();

    return 0;

}

