# Impiccato in C++ 

> Un semplice gioco dell'**Impiccato** realizzato in C++!

## Descrizione
Questo progetto è un'implementazione del classico gioco dell'**Impiccato** (Hangman) scritta in C++.  
L'utente deve **indovinare la parola nascosta** inserendo lettere una alla volta, evitando di esaurire i tentativi!  

⚡ **Caratteristiche del gioco:**
- Selezione casuale delle parole    
- Disegno ASCII dell’impiccato  
- Contatore dei tentativi rimanenti  
- Modalità giocatore singolo  

---

## **Compilazione ed Esecuzione**
### **Prerequisiti**
- **GCC/G++** (installato di default su Linux/Mac, scaricabile per Windows con MinGW)
- **CMake** (opzionale, per build avanzate)

### **Compilazione**
Compila il codice usando `g++`:

```sh
g++ -std=c++17 main.cpp -o impiccato
