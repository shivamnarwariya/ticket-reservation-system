#include <iostream>
#include <string>
using namespace std;

class RailwayReservation {
    
private:
    int ticketID[100];
    string passengerName[100];
    int age[100];
    string trainName[100];
    string source[100];
    string destination[100];
    int seats = 0;
    int nextID = 1001;

public:

    // Display available trains
    void showTrains() {
        cout << "\n----- AVAILABLE TRAINS -----\n";
        cout << "1. Express Train\n";
        cout << "2. Superfast Express\n";
        cout << "3. Passenger Train\n";
    }

    // Book ticket
    void bookTicket() {

        if (seats >= 100) {
            cout << "\nNo seats available!\n";
            return;
        }

        int choice;

        cout << "\nEnter Passenger Name: ";
        cin >> ws;
        getline(cin, passengerName[seats]);

        cout << "Enter Age: ";
        cin >> age[seats];

        cout << "\nSelect Train:\n";
        showTrains();

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
            trainName[seats] = "Express Train";
        else if (choice == 2)
            trainName[seats] = "Superfast Express";
        else if (choice == 3)
            trainName[seats] = "Passenger Train";
        else {
            cout << "Invalid Train Choice!\n";
            return;
        }

        cout << "Enter Source Station: ";
        cin >> source[seats];

        cout << "Enter Destination Station: ";
        cin >> destination[seats];

        ticketID[seats] = nextID++;

        cout << "\nTicket Booked Successfully!\n";
        cout << "Your Ticket ID: " << ticketID[seats] << endl;

        seats++;
    }

    // Display all booked tickets
    void showTickets() {

        if (seats == 0) {
            cout << "\nNo Tickets Booked Yet!\n";
            return;
        }

        cout << "\n----- BOOKED TICKETS -----\n";

        for (int i = 0; i < seats; i++) {

            if (ticketID[i] != -1) {
                cout << "\nTicket ID: " << ticketID[i];
                cout << "\nPassenger: " << passengerName[i];
                cout << "\nAge: " << age[i];
                cout << "\nTrain: " << trainName[i];
                cout << "\nFrom: " << source[i];
                cout << "\nTo: " << destination[i];
                cout << "\n-------------------------\n";
            }
        }
    }

    // Cancel ticket
    void cancelTicket() {

        int id;
        cout << "\nEnter Ticket ID to Cancel: ";
        cin >> id;

        for (int i = 0; i < seats; i++) {

            if (ticketID[i] == id) {
                ticketID[i] = -1;
                cout << "\nTicket Cancelled Successfully!\n";
                return;
            }
        }

        cout << "\nTicket Not Found!\n";
    }

    // Search ticket
    void searchTicket() {

        int id;
        cout << "\nEnter Ticket ID: ";
        cin >> id;

        for (int i = 0; i < seats; i++) {

            if (ticketID[i] == id) {
                cout << "\nTicket Found!\n";
                cout << "Passenger: " << passengerName[i] << endl;
                cout << "Train: " << trainName[i] << endl;
                cout << "From: " << source[i] << endl;
                cout << "To: " << destination[i] << endl;
                return;
            }
        }

        cout << "\nTicket Not Found!\n";
    }
};

int main() {

    RailwayReservation railway;
    int choice;

    do {

        cout << "\n================================\n";
        cout << " RAILWAY TICKET RESERVATION SYSTEM\n";
        cout << "================================\n";

        cout << "1. Show Available Trains\n";
        cout << "2. Book Ticket\n";
        cout << "3. View All Tickets\n";
        cout << "4. Search Ticket\n";
        cout << "5. Cancel Ticket\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                railway.showTrains();
                break;

            case 2:
                railway.bookTicket();
                break;

            case 3:
                railway.showTickets();
                break;

            case 4:
                railway.searchTicket();
                break;

            case 5:
                railway.cancelTicket();
                break;

            case 6:
                cout << "\nThank You for Using Railway System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}