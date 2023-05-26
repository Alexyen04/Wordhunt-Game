#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {
public:
    Settings()
        : soundEnabled(false),
          effectsEnabled(false),
          scoreMultiplierEnabled(false),
          hintsEnabled(false),
          powerupsEnabled(false)
    {
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

private:
    bool soundEnabled;
    bool effectsEnabled;
    bool scoreMultiplierEnabled;
    bool hintsEnabled;
    bool powerupsEnabled;
};

#endif // SETTINGS_H
