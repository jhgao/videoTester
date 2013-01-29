#ifndef VIDEOTESTERWINDOW_H
#define VIDEOTESTERWINDOW_H

#include <QMainWindow>
#include "gui/droplineedit.h"

namespace Ui {
class VideoTesterWindow;
}

class VideoTesterWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit VideoTesterWindow(QWidget *parent = 0);
    ~VideoTesterWindow();
    
private slots:
    void setRawFileName(QList<QUrl> urlList);
    void setRawFileName2(QList<QUrl> urlList);
    void on_pushButton_play_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_pause_2_clicked();

    void on_pushButton_stop_2_clicked();

    void on_pushButton_play_2_clicked();

private:

    QFile i_rawFile;
    QFile i_rawFile_2;
    Ui::VideoTesterWindow *ui;
};

#endif // VIDEOTESTERWINDOW_H
