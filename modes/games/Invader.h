#ifndef INVADER_H
#define INVADER_H

#include <QGraphicsItem>
#include <QGraphicsWidget>

class Invader : public QGraphicsItem
{
public:
    explicit Invader(QGraphicsWidget *graphWidget = 0, const QString &text = "");

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void advance();
protected:

signals:

public slots:

private:
    QString m_text;

};

#endif // INVADER_H
