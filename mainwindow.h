#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QvkRegionController.h"
#include "QvkWinInfo.h"

#include <QMainWindow>

#include <gst/gst.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QvkRegionController *regionController;
    const QString VK_Gstr_Pipe = " ! ";
    QString VK_GStreamer_Version();
    QString VK_getXimagesrc();
    QString VK_getCapsFilter();
    QString VK_getMuxer();
    void makeAndSetValidIcon( int index );

    GstElement *pipeline;
    GError *error = NULL;

    QvkWinInfo *vkWinInfo;


private slots:
    void slot_preStart();
    void slot_Start();
    void slot_Stop();
    void slot_Pause();
    void slot_Continue();
    void slot_screenCountChanged(int newCount );
    void slot_setFramesStandard( bool value );
    void slot_audioIconOnOff(bool state );
    void slot_clearVerticalLayoutAudioDevices(bool value);
    void slot_getPulsesDevices(bool value);
    void slot_getAlsaDevices( bool value );
    void slot_VideoPath();


signals:
    void signal_close();


protected:
    void closeEvent( QCloseEvent * event );


};

#endif // MAINWINDOW_H
