-- Procédure pour gérer les opérations CRUD sur les aéroports
CREATE PROCEDURE GestionAeroport
    @action VARCHAR(20), -- Action à effectuer : Ajouter, Supprimer, AfficherTous, AfficherParID, Modifier
    @id_aeroport INT = NULL,
    @nom NVARCHAR(100) = NULL,
    @nom_ville NVARCHAR(100) = NULL
AS
BEGIN
    IF @action = 'Ajouter'
    BEGIN
        DECLARE @id_ville INT;
    
        -- Vérifier si la ville existe, sinon l'ajouter
        IF NOT EXISTS (SELECT 1 FROM Ville WHERE nom = @nom_ville)
        BEGIN
            INSERT INTO Ville (nom)
            VALUES (@nom_ville);
        END;

        -- Récupérer l'ID de la ville
        SELECT @id_ville = id_ville FROM Ville WHERE nom = @nom_ville;

        -- Ajouter l'aéroport avec l'ID de la ville
        INSERT INTO Aeroport (nom, id_ville)
        VALUES (@nom, @id_ville);

        PRINT 'Aéroport ajouté avec succès.';
    END
    ELSE IF @action = 'Supprimer'
    BEGIN
        DELETE FROM Aeroport
        WHERE id_aeroport = @id_aeroport;

        PRINT 'Aéroport supprimé avec succès.';
    END
    ELSE IF @action = 'AfficherTous'
    BEGIN
        SELECT Aeroport.*, Ville.nom AS nom_ville
        FROM Aeroport
        INNER JOIN Ville ON Aeroport.id_ville = Ville.id_ville;

        PRINT 'Affichage de tous les aéroports avec leurs villes effectué avec succès.';
    END
    ELSE IF @action = 'AfficherParID'
    BEGIN
        SELECT Aeroport.*, Ville.nom AS nom_ville
        FROM Aeroport
        INNER JOIN Ville ON Aeroport.id_ville = Ville.id_ville
        WHERE Aeroport.id_aeroport = @id_aeroport;

        PRINT 'Affichage de l''aéroport spécifique effectué avec succès.';
    END
    ELSE IF @action = 'Modifier'
    BEGIN
        DECLARE @id_ville INT;
    
        -- Vérifier si la ville existe, sinon l'ajouter
        IF NOT EXISTS (SELECT 1 FROM Ville WHERE nom = @nom_ville)
        BEGIN
            INSERT INTO Ville (nom)
            VALUES (@nom_ville);
        END;

        -- Récupérer l'ID de la ville
        SELECT @id_ville = id_ville FROM Ville WHERE nom = @nom_ville;

        -- Mettre à jour l'aéroport avec le nouveau nom et l'ID de la ville
        UPDATE Aeroport
        SET nom = @nom, id_ville = @id_ville
        WHERE id_aeroport = @id_aeroport;

        PRINT 'Aéroport modifié avec succès.';
    END
END;
