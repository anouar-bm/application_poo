CREATE TABLE Admin (
    id INT PRIMARY KEY IDENTITY,
    nom NVARCHAR(100),
    password NVARCHAR(100)
);
INSERT INTO Admin (nom, password) VALUES ('admin', 'admin'); 