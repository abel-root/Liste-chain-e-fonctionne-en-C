# Liste chainée

C'est une structure de donne qui permet de stocker des données sans connaître la taille de la données à stocker.
Contrairement au tableau static ou la taille de la données doit être connue. 
La particularite de la liste chainée c'est que les élements de cette liste sont reliés entre eux par des 
object. 

1. Dans une liste chaînée, la taille est inconnue au départ, la liste peut avoir autant d'éléments que votre mémoire
le permet.
2. Il est en revanche impossible d'accéder directement à l'élément i de la liste chainée. Pour ce faire, il vous faudra traverser les i-1 éléments précédents de la liste.
3. Pour déclarer une liste chaînée, il suffit de créer le pointeur qui va pointer sur le premier élément de votre
liste chaînée, aucune taille n'est donc à spécifier.
4. Il est possible d'ajouter, de supprimer, d'intervertir des éléments d'une liste chaînée sans avoir à recréer la liste
en entier, mais en manipulant simplement leurs pointeurs.