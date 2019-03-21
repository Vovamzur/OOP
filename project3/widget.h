#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer *timer;

private:
    Ui::Widget *ui;

protected:
    void keyPressEvent ( QKeyEvent * event );
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent * event);
protected slots:
    void halfUpdate();
};

#endif // WIDGET_H
