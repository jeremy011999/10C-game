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
    void updateSnowflake();
    ~greenSnowflake();
signals:
    void green_snowflake_captured();
private:
    QPixmap* plusLifePic = nullptr;
};

#endif // GREENSNOWFLAKE_H
