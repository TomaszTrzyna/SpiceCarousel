# SPICECAROUSEL 

**Inteligentna karuzela na przyprawy sterowana głosowo i z aplikacji mobilnej.**

Projekt realizowany przez dwuosobowy zespół w ramach nauki programowania obiektowego w C++. Urządzenie oparte na ESP32 przechowuje informacje o przyprawach, pozycjonuje pojemniki za pomocą silnika krokowego, odczytuje identyfikatory RFID i realizuje zapisane programy podawania przypraw dla wybranych przepisów.

**Status:** faza projektowania. Opisane funkcjonalności są założeniami projektu.

## Główne funkcjonalności

- **Sterowanie głosowe:** rozpoznawanie komend przez telefon i przekazywanie ich do ESP32.
- **Własne komendy głosowe:** przypisywanie dowolnych fraz do przypraw i przepisów.
- **Aplikacja webowa/mobilna:** zarządzanie zawartością karuzeli, przepisami i ustawieniami.
- **Automatyczne pozycjonowanie:** ustawianie wybranej przyprawy w miejscu odbioru.
- **RFID:** identyfikacja pojemników i przypisywanie ich do pozycji.
- **Magazyn przypraw:** dodawanie, edycja, usuwanie i zapisywanie przypraw.
- **Monitorowanie zapasów:** szacowanie zużycia na podstawie historii pobrań.
- **Menedżer przepisów:** import przepisu z adresu URL, analiza składników i wykrywanie braków.
- **Automatyczne programy:** wykonywanie sekwencji podawania przypraw po uruchomieniu przepisu.
- **Diagnostyka:** kontrola stanów urządzenia i obsługa błędów.

## Menedżer przepisów

Użytkownik może wkleić link do przepisu kulinarnego. Moduł importujący analizuje zawartość strony, pobiera listę składników i, jeśli są dostępne, instrukcje przygotowania.

System następnie:

1. Rozpoznaje przyprawy występujące w przepisie.
2. Porównuje je z zawartością karuzeli.
3. Informuje o dostępnych i brakujących przyprawach.
4. Proponuje kolejność podawania, którą użytkownik może edytować.
5. Zapisuje program i umożliwia przypisanie własnej komendy głosowej.

Przykład:

**Przepis:** Spaghetti bolognese

**Dostępne przyprawy:** oregano, bazylia, pieprz.

**Brakujące przyprawy:** tymianek.

**Komenda:** „Robimy spaghetti”.

**Program:** oregano → bazylia → pieprz.

Po rozpoznaniu komendy system rozpoczyna wykonywanie programu. Następna przyprawa jest udostępniana po zatwierdzeniu kolejnego kroku, z uwzględnieniem stanu czujników.

System nie dozuje automatycznie przypraw. Zwykłe składniki spożywcze pozostają poza magazynem karuzeli.

## Architektura systemu

Projekt składa się z trzech głównych modułów oprogramowania:

**1. Firmware ESP32 – C++**

Odpowiada za zarządzanie przyprawami i przepisami, interpretację komend, wykonywanie sekwencji, pozycjonowanie silnika, RFID, czujniki, LED i trwałe przechowywanie danych.

**2. Aplikacja webowa i mobilna – JavaScript**

Zapewnia interfejs użytkownika, obsługę głosu na telefonie, dodawanie przypraw, import przepisów i przesyłanie poleceń do ESP32.

Docelowo rozważane jest opakowanie interfejsu w aplikację Android za pomocą Capacitor.

**3. Importer przepisów – Python**

Pobiera dane ze stron internetowych i analizuje przepisy w formacie `schema.org/Recipe`. Zwraca listę składników oraz dostępne instrukcje.

Jeżeli strona nie udostępnia czytelnych danych, użytkownik może poprawić wynik lub ręcznie wkleić składniki.

Importer wymaga osobnej usługi działającej na komputerze lub serwerze. Raz zapisane przepisy będą mogły być wykonywane bez niej.

## Struktura repozytorium

- `firmware/` – program ESP32, klasy C++ i testy.
- `app/` – aplikacja webowa i mobilna.
- `importer/` – moduł pobierania i analizowania przepisów.
- `hardware/cad/` – modele konstrukcyjne, części, złożenia i pliki STEP/STL.
- `hardware/electronics/` – schematy, połączenia i lista komponentów.
- `docs/` – architektura, API, konfiguracja pinów i dokumentacja techniczna.
- `.github/` – automatyzacja testów i szablony zgłoszeń.
- `README.md` – dokumentacja główna projektu.

## Podział obowiązków

### Osoba A – CAD i programowanie

Odpowiada za konstrukcję mechaniczną oraz logikę systemu: modele przypraw, zarządzanie magazynem, menedżer przepisów, dopasowywanie składników, wykonywanie sekwencji i rejestr własnych komend. Dodatkowo rozwija importer URL.

### Osoba B – Elektronika i programowanie

Odpowiada za elektronikę, sterowanie silnikiem, RFID, czujniki, LED, trwałą pamięć danych, HTTP API oraz podstawową aplikację i obsługę głosu na telefonie.

Obie osoby wspólnie realizują integrację, testy i dokumentację końcową.

## Technologie

- ESP32
- C++17
- PlatformIO i Arduino Framework
- HTML, CSS i JavaScript
- Python i FastAPI
- Wi-Fi / HTTP API
- RFID
- Silnik krokowy i serwo
- Krańcówki oraz LED RGB
- LittleFS / pamięć nieulotna ESP32
- Git i GitHub

## Etapy realizacji

- [ ] Przygotowanie struktury projektu i repozytorium.
- [ ] Projekt CAD i podstawowy układ elektroniczny.
- [ ] Podstawowe sterowanie karuzelą z aplikacji.
- [ ] Klasy magazynu przypraw i obsługa RFID.
- [ ] Integracja komend głosowych.
- [ ] Dodawanie własnych komend.
- [ ] Import przepisów z Internetu.
- [ ] Analiza składników i wykrywanie braków.
- [ ] Generowanie i wykonywanie programów przepisów.
- [ ] Obsługa błędów, testy i dokumentacja końcowa.

## Uruchomienie

Projekt znajduje się na etapie przygotowania.

Planowane środowiska to PlatformIO dla ESP32, Node.js dla aplikacji oraz Python dla importera.

Szczegółowe instrukcje kompilacji, konfiguracji sieci i uruchomienia modułów zostaną dodane po przygotowaniu pierwszej działającej wersji.

## Zasady pracy z GitHubem

- Gałąź `main` zawiera zintegrowaną wersję projektu.
- Każda nowa funkcja powstaje na osobnej gałęzi `feature/...`.
- Zadania są dokumentowane w GitHub Issues.
- Łączenie zmian odbywa się przez Pull Requests.
- Moduły podlegają testom przed integracją.
- Hasła Wi-Fi i dane dostępowe nie są zapisywane w publicznym repozytorium.

---

**SPICECAROUSEL** – projekt edukacyjny łączący programowanie obiektowe, robotykę, automatykę i projektowanie systemów mechatronicznych.
