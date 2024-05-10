/*
#include <iostream>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

SQLHENV env; // Handle d'environnement ODBC
SQLHDBC dbc; // Handle de connexion ODBC

// Fonction pour établir une connexion avec SQL Server via ODBC
void connecterSQLServer() {
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);

    SQLWCHAR retConString[1024];
    SQLRETURN ret = SQLDriverConnect(dbc, NULL,
        (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=DESKTOP-977PH46\\SQLEXPRESS;DATABASE=NomDeVotreBaseDeDonnees;Trusted_Connection=Yes;",
        SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT);

    if (!SQL_SUCCEEDED(ret)) {
        std::wcout << L"Connexion échouée." << std::endl;
        exit(1);
    }
    else {
        std::wcout << L"Connexion réussie à SQL Server." << std::endl;
    }
}
// Fonction pour exécuter une requête SQL
void executerSQL(const std::string& sql) {
    SQLHSTMT stmt;
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

    SQLRETURN ret = SQLExecDirect(stmt, (SQLCHAR*)sql.c_str(), SQL_NTS);

    if (!SQL_SUCCEEDED(ret)) {
        std::cout << "Erreur lors de l'exécution de la requête SQL." << std::endl;
    }

    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

int main() {

    // Requête SQL pour créer toutes les tables
    std::string createTablesSQL = R"(
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
            statut_paiement NVARCHAR(20),
            mode_paiement NVARCHAR(50),
            transaction_id NVARCHAR(100),
            id_vol INT,
            id_client INT,
            FOREIGN KEY (id_vol) REFERENCES Vol(id_vol),
            FOREIGN KEY (id_client) REFERENCES Client(id_client)
        );
    )";

    // Exécuter la requête pour créer les tables
    executerSQL(createTablesSQL);

    // Libérer les ressources
    SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    SQLFreeHandle(SQL_HANDLE_ENV, env);

    return 0;
}
*/
