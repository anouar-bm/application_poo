/*
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <string>

using namespace std;

// Constante pour la chaîne de connexion à la base de données
const wstring CONNECTION_STRING = L"DRIVER={SQL Server};SERVER=DESKTOP-977PH46\\SQLEXPRESS;DATABASE=NomDeVotreBaseDeDonnees;Trusted_Connection=Yes;";

// Fonction pour établir une connexion avec la base de données
SQLHDBC connecterBDD() {
    SQLHENV env;
    SQLHDBC dbc;
    SQLRETURN ret;

    // Allouer un handle d'environnement
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    if (!SQL_SUCCEEDED(ret)) {
        cerr << "Erreur d'allocation de l'environnement." << endl;
        return NULL;
    }

    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);

    // Allouer un handle de connexion
    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    if (!SQL_SUCCEEDED(ret)) {
        cerr << "Erreur d'allocation de la connexion." << endl;
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return NULL;
    }

    // Établir la connexion
    ret = SQLDriverConnectW(dbc, NULL, (SQLWCHAR*)CONNECTION_STRING.c_str(), SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
    if (!SQL_SUCCEEDED(ret)) {
        cerr << "Erreur de connexion à la base de données." << endl;
        SQLFreeHandle(SQL_HANDLE_DBC, dbc);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return NULL;
    }

    return dbc;
}

// Fonction pour déconnecter la base de données
void deconnecterBDD(SQLHDBC dbc) {
    SQLDisconnect(dbc);
    SQLFreeHandle(SQL_HANDLE_DBC, dbc);
}

class Admin {
public:
    int id;
    wstring nom;
    wstring password;

    // Méthode statique pour ajouter un administrateur en utilisant la procédure stockée
    static void ajouter(const wstring& nom, const wstring& password) {
        // Se connecter à la base de données
        SQLHDBC dbc = connecterBDD();
        if (!dbc) return;

        // Allouer un handle de commande
        SQLHSTMT stmt;
        SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

        // Préparer l'appel à la procédure stockée
        const wstring query = L"EXEC GestionAdmin 'Ajouter', NULL, '" + nom + L"', '" + password + L"'";

        // Exécuter la commande
        SQLRETURN ret = SQLExecDirectW(stmt, (SQLWCHAR*)query.c_str(), SQL_NTS);
        if (!SQL_SUCCEEDED(ret)) {
            cerr << "Erreur lors de l'exécution de la procédure stockée." << endl;
        }

        // Libérer les handles
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        deconnecterBDD(dbc);
    }

    // Méthode statique pour vérifier les informations de connexion de l'administrateur
    static bool login(const wstring& nom, const wstring& password) {
        // Se connecter à la base de données
        SQLHDBC dbc = connecterBDD();
        if (!dbc) return false;

        // Allouer un handle de commande
        SQLHSTMT stmt;
        SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

        // Préparer l'appel à la procédure stockée
        const wstring query = L"EXEC GestionAdmin 'Login', NULL, '" + nom + L"', '" + password + L"'";

        // Exécuter la commande
        SQLRETURN ret = SQLExecDirectW(stmt, (SQLWCHAR*)query.c_str(), SQL_NTS);
        if (!SQL_SUCCEEDED(ret)) {
            cerr << "Erreur lors de l'exécution de la procédure stockée." << endl;
            return false;
        }

        // Récupérer les résultats et vérifier le résultat de connexion
        SQLCHAR colData[256];
        SQLLEN colDataLength;
        if (SQL_SUCCEEDED(SQLFetch(stmt))) {
            SQLGetData(stmt, 1, SQL_C_CHAR, colData, sizeof(colData), &colDataLength);
            colData[colDataLength] = 0;
            bool resultat = (wstring(colData) == L"True");
            SQLFreeHandle(SQL_HANDLE_STMT, stmt);
            deconnecterBDD(dbc);
            return resultat;
        }

        // Libérer les handles
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        deconnecterBDD(dbc);
        return false;
    }
};

int main() {
    // Ajout d'un administrateur
    Admin::ajouter(L"AdminTest", L"PasswordTest");

    // Connexion de l'administrateur
    if (Admin::login(L"AdminTest", L"PasswordTest")) {
        cout << "Connexion réussie." << endl;
    }
    else {
        cout << "Erreur de connexion." << endl;
    }

    return 0;
}
*/
