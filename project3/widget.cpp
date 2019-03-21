#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(halfUpdate()));
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
    delete timer;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 6; j++) {
            painter.setBrush(QColor::fromRgb(rand()%256, rand()%256, rand()%256));
            painter.drawRect((height()/6)*i, (width()/8)*j, height()/6, width()/8 );
         }
     }
}

void Widget::halfUpdate()
{
    update(0,0,width(),height()/2);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->matches(QKeySequence::Copy)) {
        update(0,height()/2,width(),height()/2);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton) {
       update(0,height()/2,width(),height()/2);
    }
}
