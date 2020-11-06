#ifndef _GAMEWINDOW_H
#define _GAMEWINDOW_H

class GameWindow {
    private:
        GameWindow();
        static GameWindow* instance;
        float screenRatio;
    
    public:
        static GameWindow* getInstance();
        float getScreenRatio();
        void setScreenRatio(float screenRatio);
};

#endif