---
title: "Ćwiczenie 12: Obsługa klawiatury analogowej"
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

Wyznacz wartości progowe napięć $V_{threshold}$ dla przycisków w postaci połowy przedziałów między przypisanymi do nich napięciami $V_{key}$. Podaj wzór na wartość pomiaru ADC, której użyjesz w kodzie programu.

\awesomebox[violet]{2pt}{\faBook}{violet}{$V_{key}$ odczytaj ze schematu w instrukcji do ćwiczenia lub ze schematu ideowego płytki.}

\begin{center}
\begin{tabular}{|c|>{\centering}m{15mm}|>{\centering}m{15mm}|c|} 
\hline
Przycisk & $V_{key}$ & $V_{threshold}$ & ADC \\
\hline
\texttt{RIGHT} & $0{,}0~\text{V}$ & $0{,}5~\text{V}$ & $\sfrac{0{,}5}{5} \cdot 1024$ \\
\hline
\texttt{UP} & $1{,}0~\text{V}$ & $1{,}5~\text{V}$ & $\sfrac{1{,}5}{5} \cdot 1024$ \\ 
\hline
\texttt{DOWN} & & & \phantom{WWWWWWWWWWWW} \\[1em]
\hline
\texttt{LEFT} & & & \\[1em]
\hline
\texttt{SELECT} & & & \\[1em]
\hline
\end{tabular}
\end{center}

Czy zmiana napięcia zasilania zaburzy działanie klawiatury? Dlaczego?

\vspace{1.5cm}

## Zadanie rozszerzone

Od czego zależy maksymalna liczba przycisków, jakie możemy podłączyć do takiej klawiatury?

\vspace{3cm}

W jakim zakresie zmienia się licznik `int16_t counter`?

\vspace{1.5cm}

W jakim zakresie zmieniałby się licznik, gdyby był typu `uint16_t`?

\vspace{1.5cm}
