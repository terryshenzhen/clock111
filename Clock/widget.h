#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void RecvTimer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *m_timer;
};

#endif // WIDGET_H
