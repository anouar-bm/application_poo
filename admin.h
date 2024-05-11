#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <sql.h>
#include <sqlext.h>
#include <string>

class Admin {
private:
    SQLHDBC dbc;

public:
    Admin(SQLHDBC dbc);

    bool login(const std::wstring& nom, const std::wstring& password);
    void displayAllAdmins();
    bool createAdmin(const std::wstring& nom, const std::wstring& password);
};

#endif // ADMIN_H
