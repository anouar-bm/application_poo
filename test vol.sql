EXEC GestionVol 'Ajouter', 
                @jour_depart = '2024-06-10',@heure_depart = '10:30:00', @jour_arrivee = '2024-06-10',@heure_arrivee = '12:30:00', 
                @dernier_place = 200, @statut = 'En cours', @id_avion = 2, @id_aeroport_depart = 3, 
                @id_aeroport_arrivee = 4;
-- Ajouter un vol
EXEC GestionVol 'Ajouter', 
                @jour_depart = '2024-05-20', @heure_depart = '08:00:00', @jour_arrivee = '2024-05-20', @heure_arrivee = '10:00:00', 
                @dernier_place = 150, @statut = 'En cours', @id_avion = 3, @id_aeroport_depart = 3, 
                @id_aeroport_arrivee = 2;
-- Afficher tous les vols
EXEC GestionVol 'AfficherTous';
-- Afficher un vol spécifique par ID (remplacez @id_vol avec l'ID du vol que vous souhaitez afficher)
EXEC GestionVol 'AfficherParID', @id_vol = 1;

-- Modifier un vol (remplacez @id_vol avec l'ID du vol que vous souhaitez modifier)
EXEC GestionVol 'Modifier', 
                @id_vol = 1, 
                @jour_depart = '2024-05-20', @heure_depart = '09:00:00',@jour_arrivee = '2024-05-20',@heure_arrivee = '11:00:00', 
                @dernier_place = 120, @statut = 'Terminé', @id_avion = 4, @id_aeroport_depart = 2, 
                @id_aeroport_arrivee = 3;

-- Supprimer un vol (remplacez @id_vol avec l'ID du vol que vous souhaitez supprimer)
EXEC GestionVol 'Supprimer', @id_vol = 1;


EXEC GestionVol 
    @action = 'Ajouter',    @jour_depart = '2024-05-20',
    @heure_depart = '08:00:00',    @jour_arrivee = '2024-05-20',
    @heure_arrivee = '10:00:00',    @dernier_place = 150,
    @statut = 'En cours',    @id_avion = 3,
    @id_aeroport_depart = 4,
    @id_aeroport_arrivee = 2,
    @prix = 800.00; -- Prix du vol

-- Afficher tous les vols
EXEC GestionVol 'AfficherTous';
