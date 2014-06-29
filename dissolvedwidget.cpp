#include "dissolvedwidget.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

DissolvedWidget::DissolvedWidget(QWidget *parent) :
    QWidget(parent),
    m_composit(1280,1024),
    m_scope(435,43),
    m_location(Map),
    m_xscale(1.0),
    m_yscale(1.0)
{
    //CREATE TIME
    {
        QTimer * const timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()),this, SLOT(onTimer()));
        timer->setInterval(42);
        timer->start();
    }

}

void DissolvedWidget::resizeEvent(QResizeEvent *){
    m_xscale = 1280.0/this->width();
    m_yscale = 1024.0/this->height();
}

//EVERY TIME
void DissolvedWidget::onTimer(){
    this->repaint();
}

//ON PAINT EVENTS
void DissolvedWidget::paintEvent(QPaintEvent *){
    QPainter scope(&m_scope);
    scope.drawPixmap(-1,0,m_scope.width(),m_scope.height(), m_scope);
    scope.setPen(QPen(QColor(0,0,0,0)));
    scope.setBrush(QColor(0,0,0,255));
    scope.drawRect(m_scope.width()-1,0,1,m_scope.height());
    scope.setBrush(QColor(0,255,0,255));
    int scope_dif = rand()%(m_scope.height()/2);
    scope.drawRect(m_scope.width()-1,scope_dif,1,2*scope_dif);
    QPainter compositor(&m_composit);
    switch (m_location){
        case Map: {
        QPixmap background = QPixmap("://floorplan");
        compositor.drawPixmap(0,0,background.width(),background.height(),background);
        } break;
        case Patient: {
        QPixmap background = QPixmap("://patient");
        compositor.drawPixmap(0,0,background.width(),background.height(),background);
        } break;
        case Lab1: {
        QPixmap background = QPixmap("://lab1");
        compositor.drawPixmap(0,0,background.width(),background.height(),background);
        } break;
        case Lab2: {
        QPixmap background = QPixmap("://lab2");
        compositor.drawPixmap(0,0,background.width(),background.height(),background);
        } break;
        case Lab3: {
        QPixmap background = QPixmap("://lab3");
        compositor.drawPixmap(0,0,background.width(),background.height(),background);
        } break;
        default:
        break;
    }
    QPixmap hud = QPixmap("://hud");
    compositor.drawPixmap(0,800,hud.width(),hud.height(),hud);
    QPixmap item = QPixmap("://dna_green");
    compositor.drawPixmap(  7,810,100,100,item);
    item = QPixmap("://proteine");
    compositor.drawPixmap(117,806,100,100,item);
    item = QPixmap("://gel");
    compositor.drawPixmap(224,806,100,100,item);
    item = QPixmap("://vector");
    compositor.drawPixmap(331,806,100,100,item);

    item = QPixmap("://primer");
    compositor.drawPixmap( 10,913,100,100,item);
    item = QPixmap("://urin");
    compositor.drawPixmap(117,913,100,100,item);
    item = QPixmap("://dna_red");
    compositor.drawPixmap(224,913,100,100,item);

    compositor.drawPixmap(834,919,m_scope.width(),m_scope.height(),m_scope);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPixmap(0,0,this->width(), this->height(), m_composit);
}

void DissolvedWidget::mousePressEvent(  QMouseEvent *e){
    int mousexpos = e->pos().x()*m_xscale;
    int mouseypos = e->pos().y()*m_yscale;
    //QRect
    if (e->button() == Qt::LeftButton){
        switch (m_location){
            case Map: {
            if ( 224.0+509.0 > mousexpos && mousexpos > 224.0 &&
                  19.0+339.0 > mouseypos && mouseypos > 19.0){
                m_location = Patient;
            }
            if ( 827.0+173.0 > mousexpos && mousexpos > 827.0 &&
                  23.0+115.0 > mouseypos && mouseypos > 23.0){
                m_location = Lab1;
            }
            if (1072.0+116.0 > mousexpos && mousexpos > 1072.0 &&
                 138.0+188.0 > mouseypos && mouseypos > 138.0){
                m_location = Lab2;
            }
            if (1072.0+116.0 > mousexpos && mousexpos > 1072.0 &&
                 326.0+188.0 > mouseypos && mouseypos > 326.0){
                m_location = Lab3;
            }
            } break;
            case Patient: {} break;
            case Office: {} break;
            case Lab1: {} break;
            case Lab2: {} break;
            case Lab3: {} break;
            default: break;
        }
        if ( 740 > mousexpos && mousexpos > 540 &&
             mouseypos > 800){
            m_location = Map;
        }
    }
}
/*void SolvedWidget::mouseReleaseEvent(QMouseEvent *e){
    if (e->button() == Qt::LeftButton){

    }
}

void SolvedWidget::mouseMoveEvent(   QMouseEvent *e){

}*/
