#include "MorseStat.h"

#include <QtCore/QSettings>

#include "qdebug.h"

MorseStat::MorseStat(QObject *parent) :
    QObject(parent), maxTimeCount(20), m_tryCount(0), m_goodCount(0), m_timeList()
{
}

int MorseStat::getTryCount() {
    return m_tryCount;
}

int MorseStat::getGoodCount() {
    return m_goodCount;
}

int MorseStat::getGoodPercentage() {
    if (m_tryCount == 0)
        return 0;
    return int(100.0 * float(m_goodCount)/float(m_tryCount));
}

float MorseStat::getAverageTime() {
    QList<float>::iterator iter;
    QList<float>::iterator end = m_timeList.end();
    float total = 0.0;

    if (m_tryCount == 0)
        return -1.0;

    for(iter = m_timeList.begin(); iter != end; iter++) {
        total = total + *iter;
    }
    return total/m_tryCount;
}

void MorseStat::addTime(float newtime) {
    m_timeList.append(newtime);
    if (m_tryCount >= maxTimeCount)
        m_timeList.pop_front();
    else
        m_tryCount++;
}

void MorseStat::addStat(float newtime, bool successful) {
    addTime(newtime);
    if (successful)
        m_goodCount++;
}

void MorseStat::saveStats(QSettings &settings, const QString &statSetName) {
}
