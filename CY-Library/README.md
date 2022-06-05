# <san style="color:red">***CY***<san style="color:white">***-***<san style="color:orange">***Library***


## Bibliothèque informatique

CY-Library est une bibliothèque en ligne qui permet de se connecter à un compte et d'emprunter plusieurs livres.
On peut créé un compte, se connecter ou rejoindre en tant qu'invité.<br/> 
Une fois cela fait si on est invité, on peut voir la liste des livres.<br/> 
Si on est élève, on peut en plus emprunté jusqu'à 3 livres pendant 2 minutes et les rendre quand on le souhaite. On peut aussi modifié son mot de passe.<br/> 
Si on est professeur, on peut en plus ajouter ou supprimer des livres de la bibliothèque. De plus on passe à 5 livres pendant 3 minutes.

## Compatibilité système

Le programme est compatible avec les dernières versions de **Ubuntu**.

## Technologies utilisées

* Langage de programmation : <code>C</code>
* Type de programmation : **modulaire**
* Logiciel utilisé : **Visual Studio Code**
  
## Lancement
Afin d'utiliser le programme, veuillez ouvrir un terminal dans le dossier <code>CY-Library/</code>.<br/> 
Executer la commande <code>make</code> pour compiler le projet puis lancer le avec la commande <code>./CY-Library</code>.

## Téléchargement
* Télécharger le zip et extraire le fichier <code>./CY-Library</code>.
* Télécharger une version de [<code>-make</code>] et [<code>-gcc</code>]  (si cela n'est pas déjà fait).
  
## Règles

* Il faut lire les différentes instructions du programme et les respecter.
* Si une liste de chiffres est proposée, pour choisir il faut entrer le chiffre qui correspond à son choix.
* Si (oui/non) est demandé il faut entrer oui ou non pour repondre.
* Lorsque il est demandé de mettre un maximum de caractère,si cela n'est pas respecté, seul les caractéres inférieurs à ce maximum seront entrés<br/> 
--------->   _ex : si on entre bonjour avec 3 caractères max, le programme retiendra "bon"_
* Lorsque il est demandé de ne pas mettre d'espace, si cela n'est pas respecté, le <code>scanf</code> ne retiendra que la partie avant le 1er espace et la partie suivante sera prise par le prochain <code>scanf</code>.