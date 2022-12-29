# Svenja-project
Aby uruchomić ten Kod musisz go:
1.Pobrać W Zielonym przycisku z napisem Code jest pobierz Zip.
2. Wypakuj zip (prawy na plik pobrany -> Wyodrębnij wszystkie...). Wpisujesz do folderu C:\ i klikasz Wyodrębnij.
3. Pobierz Cmake:https://github.com/Kitware/CMake/releases/download/v3.25.1/cmake-3.25.1-windows-x86_64.msi <- to do windowsa.
4. Zaistaluj, i jak masz Intall Options wybierasz: Add Cmake to system PATH for for all users. Nie musisz zaznaczać ikonki.
5. Klikasz kombinacje Logo windows + R. Pojawi się małe okno wpisujesz w nie cmd i klikasz OK.
6. Otworzy sie czarne pudło. Kopiujesz : cd C:\Svenja-project-master i Klikasz enter.
7. Powino by linia ostatni : C:\Svenja-project-master>_
8. Kopiujesz: cmake -S . -B ./build  Modlisz się że skończy się tekstem -- Build files have been written to: C:/Svenja-project-master/build, jak nie musisz do mnie napisać.
9. Kopiujesz cmake --build ./build -- Nie może być na czerwono inaczej jak na górze.
10. Kopiujesz cd ./build/Debug i potem jeżeli chcesz uruchomić program to wpisz: Svfenia.exe <- tak do zmiany nazwa.
Jeżeli pokazało się coś normalnego: to gratuluje właśnie udało ci się zrobić rzecz którą większość studentów informatyki nie potrafi na 2 roku studiów.
# TODO:
1. Przerobić gotowy produkt od waszego kochanego Code::Blocksa <- Relikt przeszłości.
