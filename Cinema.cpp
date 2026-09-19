
#ifndef CINEMA_CPP
#define CINEMA_CPP
#include <vector>
#include <string>
using namespace std;

class Cinema {
private:
    string name;
    vector<Screen> screens; // COMPOSITION

public:
    Cinema(string name) : name(name) {}

    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }

    string getName() const { return name; }

    vector<Screen>& getScreens() {
        return screens;
    }

    void listMovies(const vector<Movie*>& movies) const {
        cout << "\n--- Movies Currently Playing ---\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". "
                 << movies[i]->getTitle()
                 << " (" << movies[i]->getLanguage()
                 << ", " << movies[i]->getDuration() << " min)\n";
        }
    }
};
#endif
