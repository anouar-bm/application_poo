-- Ajouter un nouvel administrateur
EXEC GestionAdmin 'Ajouter', @nom = 'compte4', @password = 'compte4';

-- Supprimer un administrateur par ID
EXEC GestionAdmin 'Supprimer', @id = 1;

-- Afficher tous les administrateurs
EXEC GestionAdmin 'AfficherTous';

-- Afficher un administrateur spécifique par ID
EXEC GestionAdmin 'AfficherParID', @id = 2;