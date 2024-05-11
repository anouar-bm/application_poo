CREATE TABLE Ville (
    id_ville INT PRIMARY KEY IDENTITY,
    nom NVARCHAR(100)
);
ALTER TABLE Aeroport
ADD id_ville INT,
FOREIGN KEY (id_ville) REFERENCES Ville(id_ville);
