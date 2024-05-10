#include <iostream>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <vector>
#include <string>

// Handle ODBC pour environnement et connexion
SQLHENV env; // Handle d'environnement
SQLHDBC dbc; // Handle de connexion

// Fonction pour se connecter à SQL Server via ODBC
void connecterSQLServer() {
    // Allocation des handles ODBC
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);

    // Chaîne de connexion à SQL Server
    SQLWCHAR connectionString[] = L"DRIVER={SQL Server};SERVER=DESKTOP-977PH46\\SQLEXPRESS;DATABASE=projet_poo;Integrated Security=True;Trust Server Certificate=True;";

    // Connexion au serveur SQL Server
    SQLRETURN ret = SQLDriverConnect(dbc, NULL, connectionString, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);

    if (SQL_SUCCEEDED(ret)) {
        std::cout << "Connexion réussie à SQL Server." << std::endl;
    }
    else {
        std::cout << "Connexion échouée à SQL Server." << std::endl;
        exit(1); // Quitter en cas d'échec de connexion
    }
}

// Fonction pour exécuter une requête SQL et afficher les résultats
void afficherAdministrateurs() {
    SQLHSTMT stmt; // Handle pour la requête SQL
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

    // Requête SQL pour obtenir la liste des administrateurs
    std::wstring requete = L"SELECT id, nom, password FROM Admin;";

    // Exécution de la requête SQL
    SQLRETURN ret = SQLExecDirect(stmt, (SQLWCHAR*)requete.c_str(), SQL_NTS);

    if (SQL_SUCCEEDED(ret)) {
        SQLINTEGER id;
        SQLWCHAR nom[100], password[100];
        SQLLEN idLen, nomLen, passwordLen;

        std::cout << "Liste des Administrateurs:" << std::endl;

        // Boucle pour récupérer et afficher les données
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            SQLGetData(stmt, 1, SQL_C_SLONG, &id, 0, &idLen); // Récupérer l'ID
            SQLGetData(stmt, 2, SQL_C_WCHAR, nom, sizeof(nom), &nomLen); // Récupérer le nom
            SQLGetData(stmt, 3, SQL_C_WCHAR, password, sizeof(password), &passwordLen); // Récupérer le mot de passe

            std::wcout << "ID: " << id << ", Nom: " << nom << ", Mot de passe: " << password << std::endl;
        }
    }
    else {
        std::cout << "Erreur lors de l'exécution de la requête SQL." << std::endl;
    }

    // Libérer le handle de la requête
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
}

int main() {
    connecterSQLServer(); // Se connsecter à SQL Server

    // Appeler la fonction pour afficher les administrateurs
    afficherAdministrateurs();

    // Libérer les ressources ODBC
    SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    SQLFreeHandle(SQL_HANDLE_ENV, env);

    return 0;
}
