# Dane
## Menu
Menu będzie wykorzystywała trzewo binarne. 
W menu dane są: ID, nazwa, deskrypcja, cena, categoria, subkategoria, ingredienty, waga, calorie

## Zamówienia 
Zamówienia wykorzystuje drzewa AVL.
W zamówieniach dane są: ID, status zamówienia, numer stolu, ID produktu (Menu).

### Platnosci
Platności sa powiązane z zamówieniami, jakoż oni nie mogą istnieć bez zamówienia.
W płatnościach dane są: ID, ID zamówienia, data, suma, status płatności, metoda płatności.

## Stoly
Odłegoci miedzy stołami będzie zachowana w grafach.


# Functions
## Zarządzanie sceną
Zarzadzanie funkcjami będzie prowadzone poprzez zarzadzanie scena.

## Zarządzanie menu
Dodawaj, edytuj i usuwaj pozycje menu, definiuj kategorie i podkategorie pozycji menu, określaj ceny, opisy i obrazy pozycji menu, zarządzaj informacjami o składnikach i alergenach.

## Zarządzanie zamówieniami
Twórz, edytuj i usuwaj zamówienia, określ typ zamówienia: na miejscu, na wynos lub z dostawą, śledź status zamówienia: oczekujące, w toku, dostarczone lub anulowane, przypisuj zamówienia do stolików lub dostawców.

## Zarządzanie płatnościami
Przetwarzaj i śledź płatności za zamówienia, obsługuj różne metody płatności: gotówka, karta kredytowa, cyfrowe portfele, generuj i wysyłaj faktury do klientów.
