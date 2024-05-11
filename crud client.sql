-- Ajouter un client
EXEC GestionClient 'Ajouter', @nom = 'Doe', @prenom = 'John', @password = 'password123', @email = 'john@example.com';
EXEC GestionClient 'Ajouter', @nom = 'ben moussa', @prenom = 'anouar', @password = 'bma123', @email = 'anouar@example.com';


-- Afficher tous les clients
EXEC GestionClient 'AfficherTous';

-- Afficher un client spécifique par ID (remplacez @id_client avec l'ID du client que vous souhaitez afficher)
EXEC GestionClient 'AfficherParID', @id_client = 1;

-- Modifier un client (remplacez @id_client avec l'ID du client que vous souhaitez modifier)
EXEC GestionClient 'Modifier', @id_client = 1, @nom = 'Doe', @prenom = 'Jane', @password = 'newpassword', @email = 'jane@example.com';

-- Supprimer un client (remplacez @id_client avec l'ID du client que vous souhaitez supprimer)
EXEC GestionClient 'Supprimer', @id_client = 1;

-- Connexion d'un client
EXEC GestionClient 'Login', @email = 'anouar@example.com', @password = 'bma123';
