#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> draw = {
    "   +---+\n"
    "   |   |\n"
    "       |\n"
    "       |\n"
    "       |\n"
    "       |\n"
    "=========\n",  // 0 errori

    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "       |\n"
    "       |\n"
    "       |\n"
    "=========\n",  // 1 errore

    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "   |   |\n"
    "       |\n"
    "       |\n"
    "=========\n",  // 2 errori

    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "  /|   |\n"
    "       |\n"
    "       |\n"
    "=========\n",  // 3 errori

    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "  /|\\  |\n"
    "       |\n"
    "       |\n"
    "=========\n",  // 4 errori

    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "  /|\\  |\n"
    "  /    |\n"
    "       |\n"
    "=========\n",  // 5 errori

    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "  /|\\  |\n"
    "  / \\  |\n"
    "       |\n"
    "=========\n"  // 6 errori -> GAME OVER
};

class Impiccato {
private:
    string parola;
    string parolaHidden;
    int errori;

public:
    Impiccato() {
        vector<string> parole;
        fstream fs("words.txt");

        if (!fs.is_open()) {
            cerr << "Errore: il file 'words.txt' è mancante!\n";
            exit(1);
        }

        string word;
        while (getline(fs, word)) {
            if (!word.empty()) {
                parole.push_back(word);
            }
        }
        fs.close();

        if (parole.empty()) {
            cerr << "Errore\n";
            exit(1);
        }

        // Scegli parola casuale
        parola = parole[rand() % parole.size()];
        parolaHidden = string(parola.length(), '_');
        errori = 0;
    }

    void check(char s) {
        bool guess = false;
        for (size_t i = 0; i < parola.length(); i++) {
            if (tolower(parola[i]) == tolower(s)) {
                parolaHidden[i] = parola[i];
                guess = true;
            }
        }

        if (!guess) {
            errori++;
        }
        display();
    }

    bool win() {
        if (parola == parolaHidden) {
            cout << "\n Hai Vinto! La parola era: " << parola << " \n";
            return false;
        }
        if (errori == 6) {
            cout << "\n Hai Perso! La parola era: " << parola << " \n";
            return false;
        }
        return true;
    }

    void display() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout << "Parola: " << parolaHidden << "\n";
        cout << draw[errori] << endl;
        cout << "Errori: " << errori << "/6\n";
    }
};

int main() {
    srand(time(0));
    Impiccato game;
    char letter;

    game.display();
    while (game.win()) {
        cout << "Inserisci una lettera: ";
        cin >> letter;
        game.check(letter);
    }
    return 0;
}
