## Część1: 
 Stwórz program, który będzie synchronizował pliki pomiędzy różnymi maszynami. My zrobimy to pomiędzy folderami. Każdy folder może sie zmienić (dodać, zmodyfikować usunąć) plik. Naszym zadaniem jest zsynchronizowanie tego i spropagowanie wszystkich zmian do pozostałych folderów, tak by każdy folder zawsze miał te same dane. 

___

## Część2: 
Rozbuduj poprzedni program. Każdy z folderów ma obsługiwać osobny wątek. Zatem jak mamy 6 maszyn (6 folderów) to 6 każdy skanuje jeden z nich. Jeżeli wykryje jakaś zmianę, poinformuje o tym pozostałe wątki, które zsynchronizują dane. Dodatkowo wątek główny ma za zadanie wypisywać za każdym razem kompletne informacje o zmianach (w formie diffa). 

  
Output:
```
04.08.2022:13:14:24[Maszyna1]: 
Dodano: [file1, file3, file4] 
Zmodyfikowano: [file2, file5] 
Usunięto: [file6, file7]
____________________________________
04.08.2022:13:15:21[Maszyna3]: 
Dodano: [file9] 
Zmodyfikowano: [file3, file7] 
Usunięto: []
____________________________________
04.08.2022:13:17:03[Maszyna2]: 
Dodano: [] 
Zmodyfikowano: [file1, file9] 
Usunięto: [file3]
____________________________________  
```
  
Jedynym sposobem na dodawanie plików ma być wgrywanie nowej konfiguracji do programu. Czyli Istnieje jakiś folder `tmp` do którego możemy wrzucać pliki. Następnie w wątku głównym podajemy ścieżkę do folderu i jakie pliki ma z niego przenieść (skopiować) oraz dla jakiej maszyny ma to dodać (nasz folder). Następnie watek główny oddelegowuje zadanie, pliki są przenoszone (kopiowane) na dana maszynę, a pozostałe watki oczywiście synchronizują się. Zabezpieczcie program tak, aby w przypadku dużego obciążenia nie doszło do sytuacji, ze modyfikujemy kilka Maszyn (folderów) na raz przez co nie będzie dało się zsynchronizować 

___

## Część3: 
Rozbuduj poprzedni program, tak aby streamował wybrany plik na wiele odbiorników. Program będzie miał możliwość uruchomienia w 2 trybach: 

- Zarządcza (zarządza plikami, umożliwia ich oddawanie oraz streamowanie) 

- Odbiornik (odbiera plik i wypisuje jego zawartość) 

  

Będziemy mieć kilka odbiorników uruchamianych osobno na terminalu. Następnie odpalony zostanie Zarządca, który umożliwi streamowanie danych na wybrane adresy i porty) Oczywiście zarządca, dalej będzie umożliwiał dodawanie nowych plików oraz ich synchronizację itd.. 

