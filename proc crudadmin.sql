CREATE PROCEDURE GestionAdmin
    @action VARCHAR(20), -- Paramètre pour spécifier l'action à effectuer (Ajouter, Supprimer, AfficherTous, AfficherParID)
    @id INT = NULL,      -- Paramètre pour l'ID (utilisé pour Supprimer et AfficherParID)
    @nom NVARCHAR(100) = NULL,     -- Paramètre pour le nom (utilisé pour Ajouter)
    @password NVARCHAR(100) = NULL -- Paramètre pour le mot de passe (utilisé pour Ajouter)
AS
BEGIN
    IF @action = 'Ajouter'
    BEGIN
        INSERT INTO Admin (nom, password)
        VALUES (@nom, @password);
    END
    ELSE IF @action = 'Supprimer'
    BEGIN
        DELETE FROM Admin
        WHERE id = @id;
    END
    ELSE IF @action = 'AfficherTous'
    BEGIN
        SELECT * FROM Admin;
    END
    ELSE IF @action = 'AfficherParID'
    BEGIN
        SELECT * FROM Admin
        WHERE id = @id;
    END
END;
