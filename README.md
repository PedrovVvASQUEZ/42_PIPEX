# Pipex

Pipex est un projet de l’école 42 écrit en C. Il reproduit le fonctionnement d’un pipeline shell simple reliant deux commandes, avec redirection de l’entrée et de la sortie :

```text
< fichier_entrée commande1 | commande2 > fichier_sortie
```

Le programme met en pratique la création de processus (`fork`), les tubes (`pipe`), les redirections de descripteurs (`dup2`) et le lancement de commandes (`execve`).

## Fonctionnalités

- Exécute deux commandes successivement, en transmettant la sortie de la première à l’entrée de la seconde.
- Lit l’entrée depuis un fichier et crée ou tronque le fichier de sortie.
- Recherche les exécutables dans les répertoires définis par la variable d’environnement `PATH`.
- Accepte également un chemin de commande contenant `/`.
- Attend les processus enfants et renvoie le statut de la dernière commande.

## Prérequis

- Un environnement Unix/Linux avec les appels système utilisés par le projet.
- `make` et un compilateur C compatible avec `cc`.

La bibliothèque `pedro_lib` utilisée par le projet est incluse dans le dépôt.

## Compilation

À la racine du dépôt :

```sh
make
```

La compilation produit l’exécutable `pipex` à la racine du projet.

Commandes de nettoyage disponibles :

```sh
make clean   # supprime les fichiers objets
make fclean  # supprime également l’exécutable et la bibliothèque compilée
make re      # nettoie puis recompile
```

## Utilisation

```sh
./pipex fichier_entrée "commande1 avec arguments" "commande2 avec arguments" fichier_sortie
```

Exemple :

```sh
./pipex input.txt "grep 42" "wc -l" output.txt
```

Cette invocation correspond à l’opération shell suivante :

```sh
< input.txt grep 42 | wc -l > output.txt
```

Le programme attend exactement quatre paramètres après `./pipex` : le fichier d’entrée, la première commande, la deuxième commande et le fichier de sortie.

## Fonctionnement

1. Le processus parent prépare un tube et crée un processus enfant pour chaque commande.
2. Le premier enfant redirige son entrée depuis le fichier d’entrée et sa sortie vers le tube.
3. Le second enfant lit depuis ce tube et redirige sa sortie vers le fichier de sortie.
4. Chaque enfant recherche puis exécute sa commande ; le parent attend la fin des processus.

```mermaid
flowchart LR
	IN[Fichier d’entrée] --> C1[Commande 1]
	C1 --> P[Tube]
	P --> C2[Commande 2]
	C2 --> OUT[Fichier de sortie]
```

## Organisation du code

- `srcs_mandatory/pipex.c` : valide le nombre d’arguments, initialise le programme et orchestre les processus.
- `srcs_mandatory/init_struct.c` : place les commandes, les fichiers et l’environnement dans la structure de données.
- `srcs_mandatory/child_process.c` et `srcs_mandatory/redirector.c` : configurent chaque processus enfant et ses redirections.
- `srcs_mandatory/file_opener.c` : ouvre les fichiers d’entrée et de sortie.
- `srcs_mandatory/cmd_exec.c`, `srcs_mandatory/cmd_path.c` et `srcs_mandatory/find_env.c` : découpent, localisent et exécutent les commandes.
- `srcs_mandatory/wait_da_boy.c` : attend les processus et récupère le statut final.
- `Includes/pipex.h` : définit la structure et les prototypes du projet.
- `Libraries/pedro_lib/` : bibliothèque C embarquée, notamment utilisée pour les fonctions de chaînes de caractères.

## Limites

Pipex n’interprète pas les commandes comme un shell complet. Les commandes sont séparées sur les espaces ; les guillemets, les expansions de variables, les jokers et les opérateurs shell ne sont donc pas interprétés par Pipex. Les guillemets de l’exemple servent au shell appelant à transmettre chaque commande comme un seul argument.

Ce dépôt contient l’implémentation obligatoire à deux commandes ; la partie bonus n’est pas incluse dans les sources présentées ici.
