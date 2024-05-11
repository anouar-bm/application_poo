-- Procédure pour ajouter un avion
CREATE PROCEDURE AjouterAvion
    @nombre_places INT,
    @nom NVARCHAR(100)
AS
BEGIN
    INSERT INTO Avion (nombre_places, nom)
    VALUES (@nombre_places, @nom);
    
    PRINT 'Avion ajouté avec succès.';
END;

-- Procédure pour supprimer un avion par ID
CREATE PROCEDURE SupprimerAvion
    @id_avion INT
AS
BEGIN
    DELETE FROM Avion
    WHERE id_avion = @id_avion;

    PRINT 'Avion supprimé avec succès.';
END;

-- Procédure pour afficher tous les avions
CREATE PROCEDURE AfficherTousAvions
AS
BEGIN
    SELECT * FROM Avion;
    PRINT 'Affichage de tous les avions effectué avec succès.';
END;
-- Procédure pour afficher un avion spécifique par ID
CREATE PROCEDURE AfficherAvionParID
    @id_avion INT
AS
BEGIN
    SELECT * FROM Avion
    WHERE id_avion = @id_avion;
    PRINT 'Affichage de l''avion spécifique effectué avec succès.';
END;
-- Procédure pour modifier un avion par ID
CREATE PROCEDURE ModifierAvion
    @id_avion INT,
    @nombre_places INT,
    @nom NVARCHAR(100)
AS
BEGIN
    UPDATE Avion
    SET nombre_places = @nombre_places,
    nom = @nom
    WHERE id_avion = @id_avion;
    PRINT 'Avion modifié avec succès.';
END;
