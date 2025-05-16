#include "../Watchface Addons/Watchy_Images/Watchy_Images.h"
#include "../Watchface Addons/Watchy_Images/images.h"
#include <Fonts/FreeMonoBold12pt7b.h>

// Tableau local d’images
static const unsigned char *const albums[] = {
    joy_division_unknown_pleasures};
static constexpr size_t albumCount = sizeof(albums) / sizeof(albums[0]);

static constexpr bool DARKMODE = false;

// Persistance de l’ID
RTC_DATA_ATTR uint8_t watchyImagesStyle = 0;

// Instance unique
WatchyImages watchyImages;

// 1) Enregistrement dans le menu
void WatchyImages::RegisterWatchFaces()
{
    watchyImagesStyle = AddWatchStyle("Images", this);
}

// 2) Setup du design quand on sélectionne le style
void WatchyImages::InsertInitWatchStyle(uint8_t StyleID)
{
    if (StyleID == watchyImagesStyle)
    {
        NoStatus(true);
    }
}

// 3) Dessin à chaque rafraîchissement
void WatchyImages::InsertDrawWatchStyle(uint8_t StyleID)
{
    if (StyleID != watchyImagesStyle || !SafeToDraw())
        return;

    display.fillScreen(DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
    display.setTextColor(DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    display.setFont(&FreeMonoBold12pt7b);

    syncTime();
    drawBackground();
    drawTime();
    drawDate();
    drawSteps();
    drawBattery();

    endWiFi();
}

void WatchyImages::syncTime()
{
    // si besoin d’une synchro NTP :
    // if (WatchTime.Local.Hour == 5 && WatchTime.Local.Minute == 0) StartNTP();
}

void WatchyImages::drawBackground()
{
    auto &LT = WatchTime.Local;
    const unsigned char *img = albums[LT.Minute % albumCount];
    uint16_t w = display.width(), h = display.height();
    display.drawBitmap(0, 0, img, w, h, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    display.fillRect(0, h - 20, w, 20, DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
}

void WatchyImages::drawTime()
{
    auto &LT = WatchTime.Local;
    display.setCursor(0, display.height() - 5);
    if (LT.Hour < 10)
        display.print('0');
    display.print(LT.Hour);
    display.print(':');
    if (LT.Minute < 10)
        display.print('0');
    display.print(LT.Minute);
}

void WatchyImages::drawDate()
{
    auto &LT = WatchTime.Local;
    int16_t x = display.width() - 69;
    display.setCursor(x, display.height() - 5);
    if (LT.Day < 10)
        display.print('0');
    display.print(LT.Day);
    display.print('/');
    if (LT.Month < 10)
        display.print('0');
    display.print(LT.Month);
}

void WatchyImages::drawSteps()
{
    display.setCursor(0, 15);
    display.print(CurrentStepCount());
}

void WatchyImages::drawBattery()
{
    float norm = (getBatteryVoltage() - 3.3f) / 0.9f;
    norm = constrain(norm, 0.0f, 1.0f);
    int len = int(display.width() * norm);
    int y = display.height() - 1;
    display.drawLine(0, y, len, y, GxEPD_BLACK);
}