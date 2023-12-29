#include <iostream>
#include <vector>

using namespace std;


const int NUM_TRIPS = 4;
const int NUM_COACHES = 6;
const int SEATS_PER_COACH = 80;
const int UP_COST = 25;
const int DOWN_COST = 25;

class ElectricMountainRailway {
private:
    vector<int> passengers_up;
    vector<int> passengers_down;
    vector<int> money_up;
    vector<int> money_down;

    int calculateAvailableTickets(int trip, bool isUpward) const {
        int numCoaches = isUpward ? NUM_COACHES : (NUM_COACHES + 2);
        return numCoaches * SEATS_PER_COACH - (isUpward ? passengers_up[trip] : passengers_down[trip]);
    }

public:
    ElectricMountainRailway() : passengers_up(NUM_TRIPS, 0), passengers_down(NUM_TRIPS, 0),
                                money_up(NUM_TRIPS, 0), money_down(NUM_TRIPS, 0) {}

    void bookTickets(int trip, bool isUpward) {
        vector<int>& passengers = isUpward ? passengers_up : passengers_down;
        vector<int>& money = isUpward ? money_up : money_down;

        cout << "\nBooking tickets for " << (isUpward ? "upward" : "downward") << " trip " << trip + 1 << ":\n";

        int availableTickets = calculateAvailableTickets(trip, isUpward);

        if (availableTickets <= 0) {
            cout << "No available tickets. The trip is closed.\n";
            return;
        }

        int numTickets;
        while (true) {
            cout << "Enter the number of tickets (1-" << availableTickets << "): ";
            cin >> numTickets;

            if (numTickets >= 1 && numTickets <= availableTickets) {
                break;
            } else {
                cout << "Invalid input. Please enter a valid number of tickets.\n";
            }
        }

        passengers[trip] += numTickets;
        int cost = numTickets * (isUpward ? UP_COST : DOWN_COST);
        money[trip] += cost;

        cout << "\n" << numTickets << " tickets booked for " << (isUpward ? "upward" : "downward") << " trip " << trip + 1 << ".\n";
        cout << "Total cost: $" << cost << "\n";
        cout << "Total passengers for " << (isUpward ? "upward" : "downward") << " trip " << trip + 1 << ": " << passengers[trip] << "\n";
        cout << "Total money for " << (isUpward ? "upward" : "downward") << " trip " << trip + 1 << ": $" << money[trip] << "\n";
    }

    void displayStartOfDaySummary() const {
        cout << "\n*** Start of the Day Summary ***\n";
        for (int trip = 0; trip < NUM_TRIPS; ++trip) {
            cout << "\nTrain " << trip + 1 << " - Upward Journey:\n";
            cout << "Total passengers: " << passengers_up[trip] << "\n";
            cout << "Total money: $" << money_up[trip] << "\n";

            cout << "\nTrain " << trip + 1 << " - Downward Journey:\n";
            cout << "Total passengers: " << passengers_down[trip] << "\n";
            cout << "Total money: $" << money_down[trip] << "\n";
        }
    }
};

int main() {
    ElectricMountainRailway railway;

    cout << "Welcome to the Electric Mountain Railway Booking System!\n";
    cout << "Initializing data for the start of the day...\n";

    for (int trip = 0; trip < NUM_TRIPS; ++trip) {
        
        railway.bookTickets(trip, true);

      
        railway.bookTickets(trip, false);
    }

   
    railway.displayStartOfDaySummary();

    return 0;
}
