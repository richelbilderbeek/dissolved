#ifndef DISSOLVEDWIDGET_H
#define DISSOLVEDWIDGET_H

#include <QWidget>

namespace Ui {
class DissolvedWidget;
}

class DissolvedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DissolvedWidget(QWidget *parent = 0);
private slots:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(  QMouseEvent *e);
    void resizeEvent(QResizeEvent *);
    void onTimer();
private:
    QPixmap m_composit;
    QPixmap m_scope;
    enum Location{Map, Patient, Office, Lab1, Lab2, Lab3};
    Location m_location;
    double m_xscale;
    double m_yscale;
};

#endif // SOLVEDWIDGET_H
