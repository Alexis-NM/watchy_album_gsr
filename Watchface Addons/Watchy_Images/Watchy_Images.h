// src/Watchy_Images.h

#ifndef WATCHY_IMAGES_H
#define WATCHY_IMAGES_H

#include <Watchy_GSR.h>

// Persiste l’ID de votre style entre les deep‐sleeps
extern RTC_DATA_ATTR uint8_t watchyImagesStyle;

class WatchyImages : public WatchyGSR
{
public:
    WatchyImages() : WatchyGSR() { initAddOn(this); }

    // Définit vos styles dans le menu
    void RegisterWatchFaces() override;

    // Initialise le design quand on passe sur ce style
    void InsertInitWatchStyle(uint8_t StyleID) override;

    // Dessine votre face
    void InsertDrawWatchStyle(uint8_t StyleID) override;

private:
    void syncTime();
    void drawBackground();
    void drawTime();
    void drawDate();
    void drawSteps();
    void drawBattery();
};

// Déclaration de l’instance unique
extern WatchyImages watchyImages;

#endif