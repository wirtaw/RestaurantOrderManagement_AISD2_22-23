# RestaurantOrderManagement_AISD2_22-23
"Restaurant order management"
projekt zaprojektowany, aby pomóc właścicielom restauracji i menedżerom usprawnić ich działania poprzez zarządzanie menu, zamówieniami, płatnościami, zapasami, raportami i analizami. System oferuje szereg funkcji, w tym zarządzanie menu, zarządzanie zamówieniami, zarządzanie płatnościami, zarządzanie zapasami, raportowanie i analitykę oraz integrację z platformami innych firm. System oferuje różne role, w tym administratora, kierownika, kasjera, szefa kuchni, dostawcę i klienta, z których każda ma określone uprawnienia i dostęp do różnych funkcji. Dzięki systemowi zarządzania zamówieniami w restauracjach właściciele i menedżerowie restauracji mogą efektywnie zarządzać swoją działalnością, zwiększać zadowolenie klientów i zwiększać rentowność.

## Schematy: 
### Menu:
* Name : tytul pozycji menu
* Description : opis slowny
* Price : cena
* Category : kategoria (pierwsze, drugie, bar...)
* Subcategory : pod kategoria
* Image : obrazek
* Ingredients : lista składników
* Allergens : lista alergenów
* Weight : ogolna waga
* Calories : kalorie
### Orders: zamowienia
* ID : unikalny identyfikator dla każdego zamowienia
* Type : typ (na miejscu, na wynos lub z dowozem)
* Status : oczekujące, w toku, dostarczone lub anulowane
* Table Number : numer stoliku na zamówienia na obiad
* Delivery Address : adres do realizacji zamówień
* Delivery Driver : imię i nazwisko kierowcy dostawy przypisanego do zamówienia
* Items : lista pozycji menu w zamówieniu (powiązany ze schematem Menu)
* Total Amount : całkowita kwota zamówienia
* Payment Status : status płatności za zamówienie (oczekujące, opłacone lub zwrócone)
* Payment Method : karta kredytowa, gotówka, płatność online
### Payments: płatności
* ID : unikalny identyfikator dla każdej płatności
* Order ID : powiązany ze schematem Orders
* Date : data
* Amount : suma płatności
* Method : karta kredytowa, gotówka, płatność online
* Status : status płatności (oczekująca, opłacona lub zwrócona)
### Functions
* Menu Management : Dodawaj, edytuj i usuwaj pozycje menu, definiuj kategorie i podkategorie pozycji menu, określaj ceny, opisy i obrazy pozycji menu, zarządzaj informacjami o składnikach i alergenach.
* Order Management : Twórz, edytuj i usuwaj zamówienia, określ typ zamówienia: na miejscu, na wynos lub z dostawą, śledź status zamówienia: oczekujące, w toku, dostarczone lub anulowane, przypisuj zamówienia do stolików lub dostawców.
* Payment Management : Przetwarzaj i śledź płatności za zamówienia, obsługuj różne metody płatności: gotówka, karta kredytowa, cyfrowe portfele, generuj i wysyłaj faktury do klientów.
* Reporting and Analytics : Śledź poziomy zapasów pozycji menu, ustawiaj punkty ponownego zamawiania i alerty o niskim poziomie zapasów, zarządzaj informacjami o dostawcach i zamówieniami.
### Roli :
* Admin : Ma pełny dostęp do wszystkich funkcji systemu. Może zarządzać użytkownikami, menu, zamówieniami, płatnościami, zapasami, raportami i analizami.
* Manager : Może zarządzać menu, zamówieniami, płatnościami, zapasami, raportami i analizami. Nie można zarządzać użytkownikami.
* Cashier : Może tworzyć i zarządzać zamówieniami, przetwarzać płatności, generować i wysyłać faktury do klientów. Nie może zarządzać menu, zapasami ani raportami.
* Chef : Może wyświetlać zamówienia i zarządzać nimi, oznaczać pozycje jako przygotowane lub podane. Nie może zarządzać menu, zapasami, płatnościami ani raportami.
* Delivery Driver: : Może wyświetlać zamówienia dostawy i zarządzać nimi, oznaczać zamówienia jako dostarczone. Nie może zarządzać menu, zapasami, płatnościami ani raportami.
* Customer : Może przeglądać menu, składać zamówienia i dokonywać płatności. Brak dostępu do innych funkcji systemu.
