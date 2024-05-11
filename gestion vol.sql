Create PROCEDURE GestionVol
    @action VARCHAR(20), -- Action à effectuer : Ajouter, Supprimer, AfficherTous, AfficherParID, Modifier
    @id_vol INT = NULL,
    @jour_depart DATE = NULL,
    @heure_depart TIME = NULL,
    @jour_arrivee DATE = NULL,
    @heure_arrivee TIME = NULL,
    @dernier_place INT = NULL,
    @statut NVARCHAR(100) = NULL,
    @id_avion INT = NULL,
    @id_aeroport_depart INT = NULL,
    @id_aeroport_arrivee INT = NULL,
    @prix FLOAT = NULL 

AS
BEGIN
    IF @action = 'Ajouter'
    BEGIN
        INSERT INTO Vol (jour_depart, heure_depart, jour_arrivee, heure_arrivee, dernier_place, statut, id_avion, id_aeroport_depart, id_aeroport_arrivee, prix)
        VALUES (@jour_depart, @heure_depart, @jour_arrivee, @heure_arrivee, @dernier_place, @statut, @id_avion, @id_aeroport_depart, @id_aeroport_arrivee, @prix);
        PRINT 'Vol ajouté avec succès.';
    END
    ELSE IF @action = 'Supprimer'
    BEGIN
        DELETE FROM Vol
        WHERE id_vol = @id_vol;
        PRINT 'Vol supprimé avec succès.';
    END
    ELSE IF @action = 'AfficherTous'
    BEGIN
        SELECT * FROM Vol;
        PRINT 'Affichage de tous les vols effectué avec succès.';
    END
    ELSE IF @action = 'AfficherParID'
    BEGIN
        SELECT * FROM Vol
        WHERE id_vol = @id_vol;
        PRINT 'Affichage du vol spécifique effectué avec succès.';
    END
    ELSE IF @action = 'Modifier'
    BEGIN    
        UPDATE Vol
        SET jour_depart = @jour_depart,
            heure_depart = @heure_depart,
            jour_arrivee = @jour_arrivee,
            heure_arrivee = @heure_arrivee,
            dernier_place = @dernier_place,
            statut = @statut,
            id_avion = @id_avion,
            id_aeroport_depart = @id_aeroport_depart,
            id_aeroport_arrivee = @id_aeroport_arrivee,
            prix = @prix
        WHERE id_vol = @id_vol;
        PRINT 'Vol modifié avec succès.';
    END
END;
