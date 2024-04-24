---
title: "Ćwiczenie 14: Przechowywanie danych w pamięci Flash"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: no
colorlinks: yes
header-right: "\\faEdit"
footer-left: "Sprawozdanie z laboratorium"
header-includes: |
  \usepackage{awesomebox}
  \usepackage{tikz}
  \usepackage{xfrac}
  \usetikzlibrary{positioning}
  \usetikzlibrary{positioning}
  \usepackage[raster]{tcolorbox}
...

\lstset{language=[11]C++}

_W trosce o Państwa wyniki proszę o czytelne wpisywanie nazwisk._

**Data**: \dotfill

**Autorzy**: \dotfill

# Część praktyczna

## Zadanie podstawowe

**Ocena prowadzącego**: \dotfill

## Zadanie rozszerzone

**Ocena prowadzącego**: \dotfill

# Część teoretyczna

## Zadanie podstawowe

Jaki jest rozmiar pamięci programu (Flash) a jaki rozmiar pamięci danych (SRAM) w mikrokontrolerze ATmega328P?

\vspace{1.5cm}

Jaki jest rozmiar programu w pamięci Flash i rozmiar danych w pamięci RAM po wprowadzeniu poprawek?

\vspace{1.5cm}

Oszacuj zajętość obu pamięci przed wprowadzeniem poprawek (gdyby linker nie weryfikował rozmiaru pamięci).

\vspace{1.5cm}

## Zadanie rozszerzone

Jeżeli zwiększymy rozmiar tablicy `buf`, np. o 10&nbsp;bajtów:

```
char buf[DISPLAY_LENGTH + 1 + 10];
```

rozmiar zajętej pamięci danych, raportowany przez kompilator, nie zmienia się. Dlaczego?

\vspace{1.5cm}

Czy zajętość pamięci RAM wskazywana przez kompilator pozwala w pełni ocenić obciążenie pamięci danych przez program?

\vspace{1.5cm}
