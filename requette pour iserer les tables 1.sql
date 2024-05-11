CREATE TABLE Admin (
            id INT PRIMARY KEY IDENTITY,
            nom NVARCHAR(100),
            password NVARCHAR(100)
        );

        CREATE TABLE Avion (
            id_avion INT PRIMARY KEY IDENTITY,
            nombre_places INT,
            nom NVARCHAR(100) 
        );

        CREATE TABLE Aeroport (
            id_aeroport INT PRIMARY KEY IDENTITY,
            nom NVARCHAR(100)
        );

        CREATE TABLE Client (
            id_client INT PRIMARY KEY IDENTITY,
            nom NVARCHAR(100),
            prenom NVARCHAR(100),
            password NVARCHAR(100),
            email NVARCHAR(100)
        );

        CREATE TABLE Vol (
            id_vol INT PRIMARY KEY IDENTITY,
            jour_depart DATE,
            heure_depart TIME,
            jour_arrivee DATE,
            heure_arrivee TIME,
            dernier_place INT,
            statut NVARCHAR(100),
            id_avion INT,
            id_aeroport_depart INT,
            id_aeroport_arrivee INT,
            FOREIGN KEY (id_avion) REFERENCES Avion(id_avion),
            FOREIGN KEY (id_aeroport_depart) REFERENCES Aeroport(id_aeroport),
            FOREIGN KEY (id_aeroport_arrivee) REFERENCES Aeroport(id_aeroport)
        );

        CREATE TABLE Reservation (
            id_reservation INT PRIMARY KEY IDENTITY,
            date_reservation DATE,
            prix FLOAT,
            id_vol INT,
            id_client INT,
            FOREIGN KEY (id_vol) REFERENCES Vol(id_vol),
            FOREIGN KEY (id_client) REFERENCES Client(id_client)
        );
