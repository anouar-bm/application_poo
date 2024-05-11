-- pour ajouter
EXEC GestionAeroport 'Ajouter', @nom = 'Aéroport Charles de Gaulle', @nom_ville = 'Paris';
EXEC GestionAeroport 'Ajouter', @nom = 'Aéroport Menara', @nom_ville = 'marrakech';
EXEC GestionAeroport 'Ajouter', @nom = 'Aéroport Rabat-Salé', @nom_ville = 'rabat';
EXEC GestionAeroport 'Ajouter', @nom = 'Aéroport Mohammed V', @nom_ville = 'casa';

--pour supprimer
EXEC GestionAeroport 'Supprimer', @id_aeroport = 1;
--pour afficher 
EXEC GestionAeroport 'AfficherTous';
--pour afficher un specifique
EXEC GestionAeroport 'Afficher', @id_aeroport = 2
--pour modifier
EXEC GestionAeroport 'Modifier', @id_aeroport = 1, @nom = 'Nouveau nom de l''aéroport', @nom_ville = 'Nouveau nom de la ville';
--pour afficher
EXEC GestionAeroport 'AfficherTous';


