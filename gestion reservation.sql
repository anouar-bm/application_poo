create PROCEDURE GestionReservation
    @action VARCHAR(20), -- Action à effectuer : Reserver, AfficherParClient
    @id_client INT = NULL,
    @id_vol INT = NULL
AS
BEGIN
    IF @action = 'Reserver'
    BEGIN
        -- Récupérer le prix du vol en fonction de l'ID du vol spécifié
        DECLARE @prix FLOAT;
        SELECT @prix = prix FROM Vol WHERE id_vol = @id_vol;
        
        -- Ajouter une nouvelle réservation avec le prix du vol récupéré
        INSERT INTO Reservation (date_reservation, prix, id_vol, id_client)
        VALUES (GETDATE(), @prix, @id_vol, @id_client);
        
        PRINT 'Réservation effectuée avec succès.';
    END
    ELSE IF @action = 'AfficherParClient'
    BEGIN
        -- Afficher les réservations pour un client donné avec les détails du vol
        SELECT r.id_reservation, r.date_reservation, v.prix AS prix_vol, v.jour_depart, v.heure_depart, v.jour_arrivee, v.heure_arrivee, v.statut
        FROM Reservation r
        INNER JOIN Vol v ON r.id_vol = v.id_vol
        WHERE r.id_client = @id_client;
    END
END;
