#include "videotesterwindow.h"
#include "ui_videotesterwindow.h"
#include <QDebug>
VideoTesterWindow::VideoTesterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoTesterWindow)
{
    ui->setupUi(this);
    //1
    connect(ui->lineEdit_rawFile, SIGNAL(gotLocalFileUrlList(QList<QUrl>)),
            this, SLOT(setRawFileName(QList<QUrl>)));
    connect(ui->videoPlayer, SIGNAL(finished()),
            this, SLOT(on_pushButton_play_clicked()));
    ui->seekSlider->setMediaObject(ui->videoPlayer->mediaObject());

    //2
    connect(ui->lineEdit_rawFile_2, SIGNAL(gotLocalFileUrlList(QList<QUrl>)),
            this, SLOT(setRawFileName2(QList<QUrl>)));
    ui->seekSlider_2->setMediaObject(ui->videoPlayer_2->mediaObject());
}

VideoTesterWindow::~VideoTesterWindow()
{
    delete ui;
}

void VideoTesterWindow::setRawFileName(QList<QUrl> urlList)
{
    if( urlList.size() > 0){
        i_rawFile.setFileName(urlList[0].toLocalFile());
        ui->label_rawFile_name->setText(urlList[0].toLocalFile());
    }
}

void VideoTesterWindow::setRawFileName2(QList<QUrl> urlList)
{
    if( urlList.size() > 0){
        i_rawFile_2.setFileName(urlList[0].toLocalFile());
        ui->label_rawFile_name_2->setText(urlList[0].toLocalFile());
    }
}

void VideoTesterWindow::on_pushButton_play_clicked()
{
    ui->videoPlayer->play(Phonon::MediaSource(i_rawFile.fileName()));
    qDebug() << ui->videoPlayer->mediaObject()->currentSource().deviceName();

}

void VideoTesterWindow::on_pushButton_stop_clicked()
{
    ui->videoPlayer->stop();
}

void VideoTesterWindow::on_pushButton_pause_clicked()
{
    if(ui->videoPlayer->isPlaying())
        ui->videoPlayer->pause();
    else
        ui->videoPlayer->play();
}

void VideoTesterWindow::on_pushButton_pause_2_clicked()
{
    if(ui->videoPlayer_2->isPlaying())
        ui->videoPlayer_2->pause();
    else
        ui->videoPlayer_2->play();
}

void VideoTesterWindow::on_pushButton_stop_2_clicked()
{
    ui->videoPlayer_2->stop();

}

void VideoTesterWindow::on_pushButton_play_2_clicked()
{
    ui->videoPlayer_2->play(Phonon::MediaSource(i_rawFile_2.fileName()));
    qDebug() << ui->videoPlayer_2->mediaObject()->currentSource().deviceName();

}
