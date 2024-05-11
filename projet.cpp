#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Reservation class
class Reservation {
private:
    string date;
    double price;
    bool confirmed;
    int flightIndex; // Index of the associated flight

public:
    Reservation(string reservationDate, double reservationPrice, int index)
        : date(reservationDate), price(reservationPrice), confirmed(false), flightIndex(index) {}

    // Method to confirm reservation
    void confirm() {
        confirmed = true;
        cout << "Reservation confirmed." << endl;
    }

    // Method to cancel reservation
    void cancel() {
        confirmed = false;
        cout << "Reservation cancelled." << endl;
    }

    // Getter method for flight index
    string getDate() { return date; }
    double getPrice() { return price; }
    bool isConfirmed() { return confirmed; }
    int getFlightIndex() { return flightIndex; }

    void modify(string newDate, double newPrice) {
        date = newDate;
        price = newPrice;
        cout << "Reservation modified successfully." << endl;
    }
};

// Flight class
class Flight {
private:
    string departureDay;
    string departureTime;
    string arrivalDay;
    string arrivalTime;
    int availableSeats;
    bool isOpenForReservation;
    int departureAirportIndex; // Index of the departure airport
    int arrivalAirportIndex;   // Index of the arrival airport

public:
    Flight(string depDay, string depTime, string arrDay, string arrTime, int seats, int depAirportIndex, int arrAirportIndex)
        : departureDay(depDay), departureTime(depTime), arrivalDay(arrDay), arrivalTime(arrTime), availableSeats(seats), isOpenForReservation(false),
        departureAirportIndex(depAirportIndex), arrivalAirportIndex(arrAirportIndex) {}

    // Getter methods
    string getDepartureDay() { return departureDay; }
    string getDepartureTime() { return departureTime; }
    string getArrivalDay() { return arrivalDay; }
    string getArrivalTime() { return arrivalTime; }
    int getAvailableSeats() { return availableSeats; }
    bool isOpen() { return isOpenForReservation; }
    int getDepartureAirportIndex() { return departureAirportIndex; }
    int getArrivalAirportIndex() { return arrivalAirportIndex; }

    void setDepartureDay(string depDay) { departureDay = depDay; }
    void setDepartureTime(string depTime) { departureTime = depTime; }
    void setArrivalDay(string arrDay) { arrivalDay = arrDay; }
    void setArrivalTime(string arrTime) { arrivalTime = arrTime; }
    void setAvailableSeats(int seats) { availableSeats = seats; }
    void setOpen(bool open) { isOpenForReservation = open; }

    // Method to open flight for reservation
    void openForReservation() {
        isOpenForReservation = true;
        cout << "Flight opened for reservation." << endl;
    }

    // Method to close flight for reservation
    void closeForReservation() {
        isOpenForReservation = false;
        cout << "Flight closed for reservation." << endl;
    }

    // Method to book a seat
    void bookSeat() {
        if (availableSeats > 0) {
            availableSeats--;
            cout << "Seat booked successfully." << endl;
        }
        else {
            cout << "No available seats." << endl;
        }
    }

};

// Aircraft class
class Aircraft {
private:
    string model;
    int capacity;

public:
    Aircraft(string aircraftModel, int aircraftCapacity)
        : model(aircraftModel), capacity(aircraftCapacity) {}

    // Getter methods
    string getModel() { return model; }
    int getCapacity() { return capacity; }
};

// Airport class
class Airport {
private:
    string name;
    int cityIndex; // Index of the associated city

public:
    Airport(string airportName, int cityIndex) : name(airportName), cityIndex(cityIndex) {}

    // Getter method for city index
    int getCityIndex() { return cityIndex; }
};

// City class
class City {
private:
    string name;
    vector<int> airportIndices; // Indices of airports associated with the city

public:
    City(string cityName) : name(cityName) {}

    // Method to add an airport to the city
    void addAirport(int airportIndex) {
        airportIndices.push_back(airportIndex);
    }

    // Method to remove an airport from the city
    void removeAirport(int airportIndex) {
        for (auto it = airportIndices.begin(); it != airportIndices.end(); ++it) {
            if (*it == airportIndex) {
                airportIndices.erase(it);
                break;
            }
        }
    }

    // Method to display all airports associated with the city
    void displayAirports() {
        cout << "Airports in " << name << ":" << endl;
        for (int i = 0; i < airportIndices.size(); ++i) {
            cout << "Airport " << airportIndices[i] + 1 << endl; // Airport indexing starts from 1
        }
    }
};

// Client class
class Client {
private:
    int id;
    string firstName;
    string lastName;
    string password;
    string email;
    vector<Reservation> reservations;

public:
    Client() : id(0), firstName(""), lastName(""), password(""), email("") {}

    Client(int clientId, string clientFirstName, string clientLastName, string clientPassword, string clientEmail)
        : id(clientId), firstName(clientFirstName), lastName(clientLastName), password(clientPassword), email(clientEmail) {}

    // Method to create a reservation
    void createReservation(string date, double price, int flightIndex) {
        Reservation newReservation(date, price, flightIndex);
        reservations.push_back(newReservation);
        cout << "Reservation created successfully." << endl;
    }

    // Method to modify a reservation
    void modifyReservation(int index, string date, double price) {
        if (index >= 0 && index < reservations.size()) {
            reservations[index] = Reservation(date, price, reservations[index].getFlightIndex());
            cout << "Reservation modified successfully." << endl;
        }
        else {
            cout << "Invalid reservation index." << endl;
        }
    }

    // Method to display all reservations
    void displayReservations() {
        cout << "Your Reservations:" << endl;
        for (int i = 0; i < reservations.size(); ++i) {
            cout << "Reservation " << i + 1 << ": Date: " << reservations[i].getDate() << ", Price: " << reservations[i].getPrice() << ", Status: " << (reservations[i].isConfirmed() ? "Confirmed" : "Not Confirmed") << endl;
        }
    }

    void makeReservation(vector<Flight>& flights) {
        // Display available departure cities
        cout << "Choisissez votre ville de depart :" << endl;
        cout << "1. Agadir" << endl;
        cout << "2. Marrakech" << endl;
        cout << "3. Rabat" << endl;
        cout << "4. Casablanca" << endl;
        cout << "Votre choix: ";
        int departureChoice;
        cin >> departureChoice;

        // Display available destination cities
        cout << "Choisissez votre destination :" << endl;
        cout << "1. Tanger" << endl;
        cout << "2. Oujda" << endl;
        cout << "3. Laayoune" << endl;
        cout << "4. Asila" << endl;
        cout << "Votre choix: ";
        int destinationChoice;
        cin >> destinationChoice;

        // Calculate the flight index based on the chosen departure and destination
        int departureIndex = departureChoice - 1;
        int destinationIndex = destinationChoice - 1;
        int flightIndex = -1;

        // Search for the flight index based on the chosen departure and destination
        for (int i = 0; i < flights.size(); ++i) {
            if (flights[i].getDepartureAirportIndex() == departureIndex && flights[i].getArrivalAirportIndex() == destinationIndex) {
                flightIndex = i;
                break;
            }
        }

        // Check if a valid flight index is found
        if (flightIndex != -1) {
            // Get the selected flight
            Flight selectedFlight = flights[flightIndex];

            // Prompt the user to enter the date of the reservation
            string reservationDate;
            cout << "Entrez la date de votre reservation (JJ/MM/AAAA): ";
            cin >> reservationDate;

            // Calculate the price based on the chosen cities


            // Output the reservation details
            cout << "Votre reservation pour le vol de " << selectedFlight.getDepartureDay() << " à " << selectedFlight.getDepartureTime() << " à " << selectedFlight.getArrivalDay() << " à " << selectedFlight.getArrivalTime() << " a ete confirmee pour le " << reservationDate << " au prix de " << endl;
        }
        else {
            cout << "Vol non trouve." << endl;
        }
    }
};

// Admin class
class Admin {
public:
    // Method to add a new flight
    void addFlight(vector<Flight>& flights) {
        string depDay, depTime, arrDay, arrTime;
        int availableSeats, depAirportIndex, arrAirportIndex;
        double price;

        cout << "Entrez le jour de depart (ex: Lundi): ";
        cin >> depDay;
        cout << "Entrez l'heure de depart (ex: 09:00): ";
        cin >> depTime;
        cout << "Entrez le jour d'arrivee (ex: Mardi): ";
        cin >> arrDay;
        cout << "Entrez l'heure d'arrivee (ex: 12:00): ";
        cin >> arrTime;
        cout << "Entrez le nombre de sieges disponibles: ";
        cin >> availableSeats;
        cout << "Entrez l'index de l'aeroport de depart: ";
        cin >> depAirportIndex;
        cout << "Entrez l'index de l'aeroport d'arrivee: ";
        cin >> arrAirportIndex;
        cout << "Entrez le prix du vol: ";
        cin >> price;

        // Create the flight and add it to the vector
        Flight newFlight(depDay, depTime, arrDay, arrTime, availableSeats, depAirportIndex, arrAirportIndex);
        flights.push_back(newFlight);

        cout << "Vol ajoute avec succes." << endl;
    }

    // Method to remove a flight
    void removeFlight(vector<Flight>& flights, int index) {
        if (index >= 0 && index < flights.size()) {
            flights.erase(flights.begin() + index);
            cout << "Flight removed successfully." << endl;
        }
        else {
            cout << "Invalid flight index." << endl;
        }
    }

    void modifyFlight(vector<Flight>& flights, int index) {
        if (index >= 0 && index < flights.size()) {
            Flight& flight = flights[index];
            // Display current flight details
            cout << "Current Flight Details:" << endl;
            cout << "Departure Day: " << flight.getDepartureDay() << endl;
            cout << "Departure Time: " << flight.getDepartureTime() << endl;
            cout << "Arrival Day: " << flight.getArrivalDay() << endl;
            cout << "Arrival Time: " << flight.getArrivalTime() << endl;
            cout << "Available Seats: " << flight.getAvailableSeats() << endl;

            // Prompt for new details
            string newDepartureDay, newDepartureTime, newArrivalDay, newArrivalTime;
            int newAvailableSeats;
            cout << "Enter new departure day (JJ/MM/AAAA): ";
            cin >> newDepartureDay;
            cout << "Enter new departure time (HH:MM): ";
            cin >> newDepartureTime;
            cout << "Enter new arrival day (JJ/MM/AAAA): ";
            cin >> newArrivalDay;
            cout << "Enter new arrival time (HH:MM): ";
            cin >> newArrivalTime;
            cout << "Enter new available seats: ";
            cin >> newAvailableSeats;

            // Update flight details
            flight.setDepartureDay(newDepartureDay);
            flight.setDepartureTime(newDepartureTime);
            flight.setArrivalDay(newArrivalDay);
            flight.setArrivalTime(newArrivalTime);
            flight.setAvailableSeats(newAvailableSeats);

            cout << "Flight details modified successfully." << endl;
        }
        else {
            cout << "Invalid flight index." << endl;
        }
    }

    // Method to display all flights
    void displayFlights(vector<Flight>& flights) {
        if (flights.empty()) {
            cout << "No flights available." << endl;
        }
        else {
            cout << "Available Flights:" << endl;
            for (int i = 0; i < flights.size(); ++i) {
                cout << "Flight " << i + 1 << ":" << endl;
                cout << "Departure Day: " << flights[i].getDepartureDay() << endl;
                cout << "Departure Time: " << flights[i].getDepartureTime() << endl;
                cout << "Arrival Day: " << flights[i].getArrivalDay() << endl;
                cout << "Arrival Time: " << flights[i].getArrivalTime() << endl;
                cout << "Available Seats: " << flights[i].getAvailableSeats() << endl;
                cout << "Status: " << (flights[i].isOpen() ? "Open" : "Closed") << endl;
                cout << "---------------------------------------------------" << endl;
            }
        }
    }
};

// Main Menu function
void displayMainMenu() {
    cout << "Bienvenue!" << endl;
    cout << "Choisissez une option:" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Client" << endl;
    cout << "Votre choix: ";
}

// Admin Menu function
void displayAdminMenu() {
    cout << "Menu Admin:" << endl;
    cout << "1. Ajouter un vol" << endl;
    cout << "2. Modifier un vol" << endl;
    cout << "3. Afficher tous les vols" << endl;
    cout << "4. Annuler" << endl;
    cout << "Votre choix: ";
}



int main() {
    // Initialize your data structures and objects
    vector<Flight> flights;
    Admin admin;
    Client client;

    int mainChoice;
    do {
        // Display main menu
        displayMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: { // Admin
            int adminChoice;
            do {
                // Display admin menu
                displayAdminMenu();
                cin >> adminChoice;
                switch (adminChoice) {
                case 1:
                    // Add a new flight
                    admin.addFlight(flights); // Call the addFlight method of the Admin class
                    break;
                case 2:
                    admin.displayFlights(flights);
                    cout << "Enter the index of the flight to modify: ";
                    int indexToModify;
                    cin >> indexToModify;
                    admin.modifyFlight(flights, indexToModify);

                    break;
                case 3:
                    admin.displayFlights(flights);
                    break;
                case 4:
                    // Cancel
                    break;
                default:
                    cout << "Choix invalide. Veuillez reessayer." << endl;
                    break;
                }
            } while (adminChoice != 4);
            break;
        }
        case 2: { // Client
            int clientChoice;
            do {
                // Display client menu
                cout << "Menu Client:" << endl;
                cout << "1. Faire une reservation" << endl;
                cout << "2. Modifier une reservation" << endl;
                cout << "3. Afficher les details de la reservation" << endl;
                cout << "4. Quitter" << endl;
                cout << "Votre choix: ";
                cin >> clientChoice;

                // Process client choice
                switch (clientChoice) {
                case 1:
                    // Make a reservation
                    client.makeReservation(flights);
                    break;
                case 2:
                    // Modify a reservation
                    // ModifyReservation logic
                    break;
                case 3:
                    // Display reservation details
                    // DisplayReservationDetails logic
                    break;
                case 4:
                    // Quit
                    cout << "Au revoir!" << endl;
                    break;
                default:
                    cout << "Choix invalide. Veuillez reessayer." << endl;
                    break;
                }
            } while (clientChoice != 4);
            break;
        }
        default:
            cout << "Choix invalide. Veuillez reessayer." << endl;
            break;
        }
    } while (mainChoice != 0);

    return 0;
}