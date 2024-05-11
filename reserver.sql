--reserver un vol
EXEC GestionReservation 'Reserver', @id_client = 2, @id_vol = 2;
EXEC GestionReservation 'Reserver', @id_client = 2, @id_vol = 3;

-- Afficher les réservations pour un client donné
EXEC GestionReservation 'AfficherParClient', @id_client = 2;



