#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTimer>

#include <QTcpSocket>
#include <QFile>
#include <QHostAddress>
#include <QStandardPaths>
#include <QProcess>
#include <qmessagebox.h>
#include <QtZlib/zlib.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QTimer *timer_update;
    QVector<QVector<QString>> maps_paths;
    QVector<QString> maps_names;
    QVector<QString> maps_descr;
    QVector<QString> preview_paths;

    QPushButton *getNewPath();
    QPushButton *getRu();
    QPushButton *getEn();
    QPushButton *getUa();
    QPushButton *getPol();

    bool check_path();
    void check_installed_maps();
    void add_maps_to_widget();

    QTcpSocket* socket;

private:
    Ui::MainWindow *ui;

public slots:
    void find_path();
    void checkForUpdateReady();
    void set_descr_and_img();
    void set_chosen_maps();
    void set_default_maps();

private slots:
    void readSocket();
    // void on_pushButtonColor_clicked();
    // void on_pushButtonNews_clicked();
    // void on_pushButtonRating_clicked();
    // void on_pushButtonSettings_clicked();
    // void on_pushButtonMaps_clicked();
    // void on_pushButtonSkins_clicked();
    // void on_pushButtonReplay_clicked();
    // void on_pushButtonForms_clicked();
    // void on_pushButtonBuild_clicked();
    void on_pushButtonClose_clicked();
    void on_checkBoxChooseAll_stateChanged(int arg1);
    void on_pushButtonOnMode_clicked();
    void on_pushButtonOffMode_clicked();
    void changeItemColor();
};
#endif // MAINWINDOW_H
