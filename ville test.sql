-- Ajouter une ville
EXEC GestionVille 'Ajouter', @nom = 'Paris';
EXEC GestionVille 'Ajouter', @nom = 'marrakech';
EXEC GestionVille 'Ajouter', @nom = 'rabat';
EXEC GestionVille 'Ajouter', @nom = 'casa';
-- Afficher toutes les villes
EXEC GestionVille 'AfficherTous';
-- Afficher une ville spécifique par ID (remplacez @id_ville avec l'ID de la ville que vous souhaitez afficher)
EXEC GestionVille 'AfficherParID', @id_ville = 1;
-- Modifier une ville (remplacez @id_ville avec l'ID de la ville que vous souhaitez modifier)
EXEC GestionVille 'Modifier', @id_ville = 1, @nom = 'Lyon';
-- Supprimer une ville (remplacez @id_ville avec l'ID de la ville que vous souhaitez supprimer)
EXEC GestionVille 'Supprimer', @id_ville = 1;
select * from ville;
