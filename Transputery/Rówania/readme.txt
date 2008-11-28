ułożone 2 równania. Działają w tym rozszerzonym lp_solve pod windowsem - pod linuchem nie znalazlem biblioteki odpowiedniej.
architektura na razie dla  max szybkich proców - w razie czego latwo zmienic:
1 5 6
2 - 7
3
4

zakładam, że w miarę oddalania się od 1 proca, każdy następny jest 2x wolniejszy, tzn. gdy as - szybkość szybkiego proca, a aw - wolnego, to:
a1=as, a2=as/2, a3=as/4, a4=as/8, a5=aw/2, a6=aw/4, a7=aw/8

Model równoległy:
zakładam że węzeł 1 wysyła na raz w obie strony. Zakładam że setup time się nie wlicza w czas obliczeń. :

Model szeregowy:
zakładam przesyłanie najpierw do 5,6,7 a potem do 2,3,4 z węzła 1. Czyli najpierw w lewo a potem na dól.

Mam nadzieje, że równania są poprawne, ponieważ dają w miare sensowne wyniki.

Resztę napiszę jutro, bo dzisiaj stracilem kupę czasu na nauczenie sie formatu pliku i próbach uruchomienia tego zmodyfikowanego lp_solve'a.
Teraz już powinno być z gorki.

odpalenie:
lp_solvebleble.exe -rxli xli_MathProg <nazwapliku>
