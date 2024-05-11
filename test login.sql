-- Exemple d'utilisation de la fonction de login d'administrateur
DECLARE @adminID INT;
SET @adminID = dbo.LoginAdmin('admin', 'admin');
IF @adminID IS NOT NULL
    PRINT 'Connexion réussie. ID de l''administrateur : ' + CAST(@adminID AS NVARCHAR(10));
ELSE
    PRINT 'Identifiants incorrects.';