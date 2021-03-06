#ifndef GREENSNOWFLAKE_H
#define GREENSNOWFLAKE_H

#include <QObject>
#include <QWidget>
#include "snowflakes.h"

class greenSnowflake:public snowflake
{
    Q_OBJECT
public:
    greenSnowflake(double size);
    
    /**
     * updateSnowflake() checks for collisions and emits signal to capture snowflake, effectively adding plus life
     * image
     *
     */
    void updateSnowflake();
    ~greenSnowflake();
signals:
    /**
     * green_snowflake_captured() is a signal emitted by updateSnowFlake() function which checks whether paddle has captured snowflake
     */
    void green_snowflake_captured();
private:
    QPixmap* plusLifePic = nullptr;
};

#endif // GREENSNOWFLAKE_H
