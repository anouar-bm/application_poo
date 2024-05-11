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
	double price;

public:
    Flight(string depDay, string depTime, string arrDay, string arrTime, int seats, int depAirportIndex, int arrAirportIndex,double price)
        : departureDay(depDay), departureTime(depTime), arrivalDay(arrDay), arrivalTime(arrTime), availableSeats(seats), isOpenForReservation(false),
        departureAirportIndex(depAirportIndex), arrivalAirportIndex(arrAirportIndex),price(price) {}

    // Getter methods
    string getDepartureDay() { return departureDay; }
    string getDepartureTime() { return departureTime; }
    string getArrivalDay() { return arrivalDay; }
    string getArrivalTime() { return arrivalTime; }
    int getAvailableSeats() { return availableSeats; }
    bool isOpen() { return isOpenForReservation; }
    int getDepartureAirportIndex() { return departureAirportIndex; }
    int getArrivalAirportIndex() { return arrivalAirportIndex; }
	double getPrice() { return price; }

    void setDepartureDay(string depDay) { departureDay = depDay; }
    void setDepartureTime(string depTime) { departureTime = depTime; }
    void setArrivalDay(string arrDay) { arrivalDay = arrDay; }
    void setArrivalTime(string arrTime) { arrivalTime = arrTime; }
    void setAvailableSeats(int seats) { availableSeats = seats; }
    void setOpen(bool open) { isOpenForReservation = open; }
	void setPrice(double price) { price = price; }

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
	string getName() { return name; }
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

    string getEmail() const {
        return email;
    }

    // Fonction pour obtenir le mot de passe du client
    string getPassword() const {
        return password;
    }
    static bool login_client(string enteredEmail, string enteredPassword, const vector<Client>& clients) {
        // Parcourir la liste des utilisateurs pour vérifier les identifiants
        for (const auto& client : clients) {
            if (client.email == enteredEmail && client.password == enteredPassword) {
                return true; // Identifiants valides
            }
        }
        return false; // Identifiants invalides
    }
    // Fonction pour créer un nouveau client
    static void create_client(vector<Client>& clients) {
        int id;
        string firstName, lastName, password, email;

        // Demander les informations du nouveau client à l'utilisateur
        cout << "Enter client ID: ";
        cin >> id;
        cout << "Enter client first name: ";
        cin >> firstName;
        cout << "Enter client last name: ";
        cin >> lastName;
        cout << "Enter client email: ";
        cin >> email;
        cout << "Enter client password: ";
        cin >> password;

        // Créer un nouveau client avec les informations fournies
        Client newClient(id, firstName, lastName, password, email);

        // Ajouter le nouveau client au vecteur clients
        clients.push_back(newClient);

        cout << "Client created successfully." << endl;
    }

	// Method to handle client actions
    void handleActions(vector<Flight>& flights) {
        int action;
        cout << "Choisissez une action :" << endl;
        cout << "1. Effectuer une réservation" << endl;
        cout << "2. Voir les réservations existantes" << endl;
        cout << "Votre choix: ";
        cin >> action;
        switch (action) {
        case 1:
            makeReservation(flights);
            break;
        case 2:
            displayReservations();
            break;
        default:
            cout << "Choix invalide." << endl;
            break;
        }
    }

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
private:
    int id;
    string nom;
	string password;

public:
    Admin(const string& u, const string& p) : nom(u), password(p) {}
    string getnom() const {
		return nom;
	}
    string getPassword() const {
		return password;
    }
    static bool connecter(string username, string password, const vector<Admin>& admins) {
        // Vérifier les identifiants dans le vecteur admins
        for (const auto& admin : admins) {
            if (admin.getnom() == username && admin.getPassword() == password) {
                return true; // Identifiants valides
            }
        }
        return false; // Identifiants invalides
    }

    // cree admin
    static void createAdmin(vector<Admin>& admins) {
        string username, password;
        cout << "Entrez le nom d'utilisateur: ";
        cin >> username;
        cout << "Entrez le mot de passe: ";
        cin >> password;
        admins.push_back(Admin(username, password));
        cout << "Compte administrateur créé avec succès." << endl;
    }

    // Méthode pour afficher les comptes administrateurs disponibles
    static void displayAdmins(const vector<Admin>& admins) {
        cout << "Comptes administrateurs disponibles :" << endl;
        for (const auto& admin : admins) {
            cout << "Nom d'utilisateur: " << admin.getnom() << endl;
            // Vous pouvez ajouter d'autres détails si nécessaire
        }
    }



    // CRUD pour les villes
    void creerVille(vector<City>& cities, string name) {
        // Créer une nouvelle ville et l'ajouter à la liste
        cities.push_back(City(name));
        cout << "Ville ajoutee avec succes." << endl;
    }

    void afficherVilles(vector<City>& cities) {
        // Afficher les villes existantes
        cout << "Villes disponibles:" << endl;
        for (int i = 0; i < cities.size(); ++i) {
            cout << i + 1 << ". " << cities[i].getName() << endl;
        }
    }

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
        Flight newFlight(depDay, depTime, arrDay, arrTime, availableSeats, depAirportIndex, arrAirportIndex,price);
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
void afficherMenuPrincipal() {
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

// Fonction pour afficher le menu de l'administrateur
void afficherMenuAdmin() {
    cout << "Menu Admin:" << endl;
    cout << "1. CRUD Villes" << endl;
    cout << "2. CRUD Aeroports" << endl;
    cout << "3. CRUD Avions" << endl;
    cout << "4. CRUD Vols" << endl;
    cout << "5. Quitter" << endl;
    cout << "Votre choix: ";
}

// Fonction pour afficher le menu du client
void afficherMenuClient() {
    cout << "Menu Client:" << endl;
    cout << "1. Se connecter" << endl;
    cout << "2. Creer un compte" << endl;
    cout << "3. Voir les reservations disponibles" << endl;
    cout << "4. Voir mes reservations" << endl;
    cout << "5. Quitter" << endl;
    cout << "Votre choix: ";
}
int main() {
    // Initialiser les données
    vector<City> cities;
    vector<Airport> airports;
    vector<Aircraft> aircrafts;
    vector<Flight> flights;
	vector<Client> clients;
	vector<Admin> admins;
	vector<Admin> admins;
    // Créer une instance de l'administrateur
    

    int choixPrincipal;
    do {
        // Afficher le menu principal
        afficherMenuPrincipal();
        cin >> choixPrincipal;

        switch (choixPrincipal) {
        case 1: { // Admin
            string username, password;
            cout << "Nom d'utilisateur: ";
            cin >> username;
            cout << "Mot de passe: ";
            cin >> password;

            // Vérifier les identifiants de l'administrateur
            if (Admin::connecter(username, password, admins)) {
                int choixAdmin;
                do {
                    // Afficher le menu de l'administrateur
                    afficherMenuAdmin();
                    cin >> choixAdmin;

                    switch (choixAdmin) {
                    case 1:
                        // CRUD Villes
                        // Demander à l'administrateur de choisir l'action (créer, afficher, modifier, supprimer)
                        break;
                    case 2:
                        // CRUD Aeroports
                        break;
                    case 3:
                        // CRUD Avions
                        break;
                    case 4:
                        // CRUD Vols
                        break;
                    case 5:
                        // Quitter
                        break;
                    default:
                        cout << "Choix invalide. Veuillez reessayer." << endl;
                        break;
                    }
                } while (choixAdmin != 5);
            }
            else {
                cout << "Identifiants invalides. Connexion echouee." << endl;
            }
            break;
        }
        case 2: { // Client
            int choixClient;
            cout << "Choisissez une option :" << endl;
            cout << "1. Se connecter" << endl;
            cout << "2. Créer un compte" << endl;
            cout << "Votre choix: ";
            cin >> choixClient;

            switch (choixClient) {
            case 1: {
                // Se connecter
                string enteredEmail, enteredPassword;
                cout << "Entrez votre email: ";
                cin >> enteredEmail;
                cout << "Entrez votre mot de passe: ";
                cin >> enteredPassword;
                for (auto& client : clients) {
                    if (client.getEmail() == enteredEmail && client.getPassword() == enteredPassword) {
                        cout << "Connexion réussie." << endl;
                        // Gérer les actions du client connecté
                        client.handleActions(flights);
                        return 0; // Sortir du programme après traitement
                    }
                }
                cout << "Identifiants incorrects. Connexion échouée." << endl;
				break;
			}
            case 2: {
                // Créer un compte
                Client::create_client(clients);
                // Gérer les actions du client créé
                clients.back().handleActions(flights);
                break;
            }
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
                break;
            }
        }
        }
	} while (choixPrincipal != 3);
   return 0;
}