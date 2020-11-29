# Bash-build

_Le projet de fin de semestre a pour objectif de mettre en application toutes les connaissances que vous avez acquises durant les différentes séances d’Algo&Prog3. Pour le réaliser, vous formerez des groupes de 3 étudiants et disposerez de 2 semaines de travail. Lors de la dernière séance vous disposerez alors de 6 min pour présenter en quelques slides votre solution suivi de 4 min de questions-réponses._

*Proposer un jeu de stratégie de construction de bâtiment en langage C*

## Cahier des charges

* **Présentation générale :** Bash-Build est un jeu de construction codé en langage C et s’exécutant dans un terminal. Il dispose d’une interface ergonomique composée de multiples menus interactifs permettant de naviguer dans les fonctionnalités.

* **Démarrage :** Au lancement de Bash-Build, le menu de démarrage permet de choisir les dimensions du plateau de jeu (par défaut à minima 10x10). Le joueur peut donc choisir son plateau parmi les propositions du système mais également saisir les dimensions de son plateau. Dans ce cas-là, le système devra contrôler que ces dimensions soient supérieures ou égales à 10x10.

* **Au cours du jeu :** Le joueur dispose d’une certaine somme d’argent au début du jeu, assez pour construire au moins 1 à 2 bâtiments de faible coût. Le joueur, en construisant un bâtiment de type Banque, peut alors obtenir un prêt à hauteur de 3 fois son capital, avec un pourcentage d’au moins 5%, sur une durée inférieure à 5 ans, avec des mensualités proportionnelles aux données.

* **Mode Avatar :** Quand ce mode est actif, le joueur dispose d’un personnage qui peut se déplacer sur le plateau pour interagir avec les bâtiments et les terrains vides.

* **Interface graphique :** Le système peut disposer d’une interface graphique permettant ainsi à l’utilisateur de visualiser le plateau et d’interagir directement avec les bâtiments ou terrains vides.

* **Multijoueur :** Le joueur au démarrage peut choisir de jouer sur un plateau commun. Le système devra donc créer des fichiers qui seront en commun aux différents utilisateurs d’un même système.