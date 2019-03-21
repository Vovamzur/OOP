#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->game = &this->game->getInstance();
    connect(this->game->bulletTimer, SIGNAL(timeout()), this, SLOT(MoveBullets()));
    this->game->bulletTimer->start(8);
}

Widget::~Widget()
{
    delete this->ui;
}

void Widget::MoveBullets() {
    this->game->gameMoveBullet();
    this->game->gameMoveEnemyBullet();
    update();
//    if(!this->game->map->lolo) {
//        this->game->bulletTimer->stop();
//        QMessageBox::warning(this, "Adventures of Lolo", "You lost!");
//        this->close();
//    }
    if(this->game->enemyBullet) {
        if(this->game->map->lolo.data()->GetPosition() == this->game->enemyBullet->GetPosition()) {
            this->game->bulletTimer->stop();
            QMessageBox::warning(this, "Adventures of Lolo", "You lost!");
            this->close();
        }
    }
}

void Widget::DrawPixmap(int a, int b, QPixmap pix, QPainter& painter) {
    int w = painter.device()->width()/13;
    int h = painter.device()->height()/14;
    painter.drawPixmap(a*w, b*h, w, h, pix);
}

void Widget::DrawBackground(QPainter &painter) {
    QPixmap c(":/imgs/img/bricks.png");
    QPixmap u1(":/imgs/img/paredeFrente1.png");
    QPixmap u2(":/imgs/img/paredeFrente2.png");
    QPixmap d(":/imgs/img/paredeAtras.png");
    QPixmap l(":/imgs/img/paredeLateral.png");
    QPixmap r(":/imgs/img/paredeLateral2.png");
    QPixmap openOut(":/imgs/img/portaAberta.png");
    QPixmap closeOut(":/imgs/img/porta.png");

    for(int i = 1; i < 12; i++) {
        for(int j = 2; j < 13; j++) DrawPixmap(i, j, c, painter);

        DrawPixmap(i,     0,  u1, painter);
        DrawPixmap(i-1/2, 1,  u2, painter);
        DrawPixmap(i,     13, d,  painter);
    }
    DrawPixmap(12-1/2, 1, u2, painter);
    for (int i = 0; i < 14; i++) {
        DrawPixmap(0,  i, l, painter);
        DrawPixmap(12, i, r, painter);
    }
    if(this->game->map->chest.data()->isTaken())
         DrawPixmap(*this->game->out, 1, openOut, painter);
    else DrawPixmap(*this->game->out, 1, closeOut,painter);
}

void Widget::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    DrawBackground(painter);
    this->game->map->Draw(painter);
    if(this->game->enemyBullet) this->game->enemyBullet->Draw(painter);
    if(this->game->bullet) this->game->bullet->Draw(painter);
}

void Widget::Final() {
    if(this->game->map->chest.data()->isTaken()) {
        if( this->game->map->lolo->GetPosition().first == *this->game->out-1 &&
            this->game->map->lolo->GetPosition().second == 0) {
        QMessageBox::warning(this, "Adventures of Lolo", "Congratulations! You completed this level!");
        this->close();
        }
    }
}

void Widget::keyPressEvent(QKeyEvent* e)
{
    switch (e->key()) {
    case Qt::Key_Left:
    {
        this->game->gameMoveLolo(Lolo::Direction::LEFT);
        Final();
        update();
        break;
    }
    case Qt::Key_Right:
    {
        this->game->gameMoveLolo(Lolo::Direction::RIGHT);
        Final();
        update();
        break;
    }
    case Qt::Key_Up:
    {
        this->game->gameMoveLolo(Lolo::Direction::UP);
        Final();
        update();
        break;
    }
    case Qt::Key_Down:
    {
        this->game->gameMoveLolo(Lolo::Direction::DOWN);
        Final();
        update();
        break;
    }
    case Qt::Key_Space:
    {
        if (!this->game->bullet) {
            this->game->bullet = this->game->map->lolo->shoot();
        }
    }
    }
}
