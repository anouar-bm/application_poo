-- Procédure pour gérer les opérations CRUD sur les villes
CREATE PROCEDURE GestionVille
    @action VARCHAR(20), -- Action à effectuer : Ajouter, Supprimer, AfficherTous, AfficherParID, Modifier
    @id_ville INT = NULL,
    @nom NVARCHAR(100) = NULL
AS
BEGIN
    IF @action = 'Ajouter'
    BEGIN
        INSERT INTO Ville (nom)
        VALUES (@nom);
        PRINT 'Ville ajoutée avec succès.';
    END
    ELSE IF @action = 'Supprimer'
    BEGIN
        DELETE FROM Ville
        WHERE id_ville = @id_ville;
        PRINT 'Ville supprimée avec succès.';
    END
    ELSE IF @action = 'AfficherTous'
    BEGIN
        SELECT * FROM Ville;
        PRINT 'Affichage de toutes les villes effectué avec succès.';
    END
    ELSE IF @action = 'AfficherParID'
    BEGIN
        SELECT * FROM Ville
        WHERE id_ville = @id_ville;
        PRINT 'Affichage de la ville spécifique effectué avec succès.';
    END
    ELSE IF @action = 'Modifier'
    BEGIN
        UPDATE Ville
        SET nom = @nom
        WHERE id_ville = @id_ville;
        PRINT 'Ville modifiée avec succès.';
    END
END;
