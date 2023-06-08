#include <vector>
#include <string>

class Settings {
public:
    Settings()
        : soundEnabled(false),
          effectsEnabled(false),
          scoreMultiplierEnabled(false),
          hintsEnabled(false),
          powerupsEnabled(false),
          dimensions("4"),
          soundPercent(50),
          wordLimit("17"),
          time("80"),
          customWordList(new std::vector<std::string>()) // Initialize as a pointer to an empty vector
    {
    }

    ~Settings() {
        delete customWordList; // Deallocate memory for the vector
    }

    bool isSoundEnabled() const {
        return soundEnabled;
    }

    void setSoundEnabled(bool enabled) {
        soundEnabled = enabled;
    }

    bool areEffectsEnabled() const {
        return effectsEnabled;
    }

    void setEffectsEnabled(bool enabled) {
        effectsEnabled = enabled;
    }

    bool isScoreMultiplierEnabled() const {
        return scoreMultiplierEnabled;
    }

    void setScoreMultiplierEnabled(bool enabled) {
        scoreMultiplierEnabled = enabled;
    }

    bool areHintsEnabled() const {
        return hintsEnabled;
    }

    void setHintsEnabled(bool enabled) {
        hintsEnabled = enabled;
    }

    bool arePowerupsEnabled() const {
        return powerupsEnabled;
    }

    void setPowerupsEnabled(bool enabled) {
        powerupsEnabled = enabled;
    }

    string getDimensions() const {
        return dimensions;
    }

    void setDimensions(string dimensions) {
        this->dimensions = dimensions;
    }

    int getSoundPercent() const {
        return soundPercent;
    }

    void setSoundPercent(int percent) {
        soundPercent = percent;
    }

    string getWordLimit() const {
        return wordLimit;
    }

    void setWordLimit(string limit) {
        wordLimit = limit;
    }

    string getTime() const {
        return time;
    }

    void setTime(string time) {
        this->time = time;
    }

    void clearList() {
        customWordList->clear();
        std::cout<<"cleared"<<std::endl;
    }

    std::string getCustomWordList(int index) const {
        if (index >= 0 && index < customWordList->size()) {
            return (*customWordList)[index];
        }
        else {
            // Handle the case when the index is out of bounds
            // You can throw an exception or return a default value as per your requirements
            throw std::out_of_range("Index out of bounds");
        }
    }

    void addToCustomWordList(const std::string& word) {
        customWordList->push_back(word);
    }

private:
    bool soundEnabled;
    bool effectsEnabled;
    bool scoreMultiplierEnabled;
    bool hintsEnabled;
    bool powerupsEnabled;
    string dimensions;
    int soundPercent;
    string wordLimit;
    string time;
    std::vector<std::string>* customWordList; // Pointer to vector
};