#include <vector>

class Settings {
public:
    Settings()
        : soundEnabled(false),
          effectsEnabled(false),
          scoreMultiplierEnabled(false),
          hintsEnabled(false),
          powerupsEnabled(false),
          setDimensions(4),
          setSoundPercent(50),
          setWordLimit(17),
          setCustomWordList(new std::vector<DataType>()) // Initialize as a pointer to an empty vector
    {
    }

    ~Settings() {
        delete setCustomWordList; // Deallocate memory for the vector
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

    int getDimensions() const {
        return setDimensions;
    }

    void setDimensions(int dimensions) {
        setDimensions = dimensions;
    }

    int getSoundPercent() const {
        return setSoundPercent;
    }

    void setSoundPercent(int percent) {
        setSoundPercent = percent;
    }

    int getWordLimit() const {
        return setWordLimit;
    }

    void setWordLimit(int limit) {
        setWordLimit = limit;
    }

    std::vector<DataType>* getCustomWordList() const {
        return setCustomWordList;
    }

    void addToCustomWordList(const DataType& word) {
        setCustomWordList->push_back(word);
    }

private:
    bool soundEnabled;
    bool effectsEnabled;
    bool scoreMultiplierEnabled;
    bool hintsEnabled;
    bool powerupsEnabled;
    int setDimensions;
    int setSoundPercent;
    int setWordLimit;
    std::vector<DataType>* setCustomWordList; // Pointer to vector
};
