#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QMessageBox>

#include <game.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    Ui::Widget *ui;
    Game *game;

    void DrawPixmap(int, int, QPixmap, QPainter&);
    void DrawBackground(QPainter&);
    void Final();
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void MoveBullets();

protected:
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent*);
};

#endif // WIDGET_H
