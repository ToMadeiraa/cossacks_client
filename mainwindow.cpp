#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Cossacks 3 Launcher");
    //setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);

    QFile old_ver(QDir::currentPath() + "/ver.ini");
    old_ver.open(QIODevice::ReadWrite);
    QString version = old_ver.readLine();
    ui->labelVer->setText("Ver. " + version);

    //запускаем таймер поиска обновления
    timer_update = new QTimer();
    connect(timer_update, SIGNAL(timeout()), this, SLOT(checkForUpdateReady()));
    timer_update->start(1000);

    //connecting
    socket = new QTcpSocket(this);
    //socket->connectToHost(QHostAddress::LocalHost,10001);
    socket->connectToHost("91.245.227.149",10001);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);

    if(socket->waitForConnected()) {
    qDebug() << "Connected to Server";
    QString pth = QDir::currentPath() + "/ver.ini";
    QFile file_vers(pth);
    file_vers.open(QIODevice::ReadOnly);
    QString version = file_vers.readAll();
    qDebug() << "VERSION:" << version;

    //send verison message
    if(socket)
    {
        if(socket->isOpen())
        {

            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QByteArray header;
            header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(version.size()).toUtf8());
            header.resize(128);

            QByteArray byteArray = version.toUtf8();
            byteArray.prepend(header);

            socketStream << byteArray;

        }
        else qDebug() << "Socket doesn't seem to be opened";
    }
    else qDebug() << "Not connected";

    } else {
        qDebug() << "The error occurred";
    }

    connect(getNewPath(), SIGNAL(clicked(bool)), this, SLOT(find_path()));
    bool isRightPath = check_path();
    if (isRightPath) {
        ui->stackedWidget->setCurrentWidget(ui->MainMenu);
    }

    this->getRu()->setIconSize(QSize(35, 25));
    this->getEn()->setIconSize(QSize(35, 25));
    this->getUa()->setIconSize(QSize(35, 25));
    this->getPol()->setIconSize(QSize(35, 25));

    check_installed_maps();
    //connect(timer_update, SIGNAL(timeout()), this, SLOT(checkForUpdateReady()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(set_descr_and_img()));
    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(changeItemColor()));

    connect(ui->setChosenMaps,SIGNAL(clicked(bool)), this, SLOT(set_chosen_maps()));
    connect(ui->setDefaultMaps,SIGNAL(clicked(bool)), this, SLOT(set_default_maps()));


}

void MainWindow::readSocket()
{
    ui->labelVer->setText("Обновление... Пожалуйста, подождите.");
    ui->labelVer->setStyleSheet("color: rgb(255, 0, 0);");
    qDebug() << "-----------------------------------";
    qDebug() << "READ...";
    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);

    socketStream.startTransaction();
    socketStream >> buffer;

    if(!socketStream.commitTransaction())
    {
        qDebug() << "Waiting for more data to come from descriptor " << socket->socketDescriptor();
        return;
    }

    QString header = buffer.mid(0,128);
    QString fileType = header.split(",")[0].split(":")[1];

    buffer = buffer.mid(128);

    if(fileType=="attachment"){
        qDebug() << "GOT ATTACHMENT";
        QString fileName = header.split(",")[1].split(":")[1];
        QString ext = fileName.split(".")[1];
        QString size = header.split(",")[2].split(":")[1].split(";")[0];
        //if (QMessageBox::Yes == QMessageBox::question(this, "QTCPServer", QString("You are receiving an attachment from sd:%1 of size: %2 bytes, called %3. Do you want to accept it?").arg(socket->socketDescriptor()).arg(size).arg(fileName)))
        if (1)
        {
            //QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"+fileName, QString("File (*.%1)").arg(ext));
            QString filePath = QDir::currentPath() + "/Updates/" + fileName;
            QFile file(filePath);
            if(file.open(QIODevice::WriteOnly)){
                file.write(buffer);
                qDebug() << "FILE " << fileName << " SAVED";
            }else qDebug() << "An error occurred while trying to write the attachment.";
        }else{
            qDebug() << "Attachment discarded, socket descriptor:" << socket->socketDescriptor();
        }
    }//else if(fileType=="message"){
    else {
        qDebug() << "Socket Descriptor: " << socket->socketDescriptor() << "   Message:  " << QString::fromStdString(buffer.toStdString());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_path() {

    QFile file("path.ini");
    QString line;
    file.open(QIODevice::ReadWrite);
    if (file.exists()) {
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            if (file.exists(line + "/cossacks.ini")) {
                return 1;
            }
        }
    }
    return 0;
}

void MainWindow::find_path() {
    QString str = QFileDialog::getExistingDirectory(0, "Выбор папки", "");
    ui->lineEditPath->setText(str);
    QFile file;
    if(!file.exists(str + "/cossacks.ini")){
        ui->label->setText("Неверный путь");
    } else {
        ui->label->setText("");
        QFile file("path.ini");
        file.open(QIODevice::WriteOnly);
        QTextStream stream( &file );
        stream << str;
        ui->stackedWidget->setCurrentWidget(ui->MainMenu);
    }
}
QPushButton*    MainWindow::getNewPath() {return ui->pushButtonPath;}
QPushButton*    MainWindow::getRu() {return ui->pushButtonRU;}
QPushButton*    MainWindow::getEn() {return ui->pushButtonEN;}
QPushButton*    MainWindow::getUa() {return ui->pushButtonUA;}
QPushButton*    MainWindow::getPol() {return ui->pushButtonPOL;}


// void MainWindow::on_pushButtonColor_clicked()
// {
//     QColor color = QColorDialog::getColor(QColor(255,100,200,255));
//     if (color.isValid()) {
//         ui->widget_colorOfSelecting->repaint();
//     }
// }


// void MainWindow::on_pushButtonNews_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->news);
// }


// void MainWindow::on_pushButtonRating_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->rating);
// }


// void MainWindow::on_pushButtonSettings_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->settings);
// }


// void MainWindow::on_pushButtonMaps_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->maps);
// }


// void MainWindow::on_pushButtonSkins_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->models);
// }



// void MainWindow::on_pushButtonReplay_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->replays);
// }


// void MainWindow::on_pushButtonForms_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->formations);
// }


// void MainWindow::on_pushButtonBuild_clicked()
// {
//     ui->stackedWidget_Main->setCurrentWidget(ui->builds);
// }


void MainWindow::checkForUpdateReady()
{

    //если обновление еще не загрузилось или его нет, то ничего не делаем
    QString rdyFileUpdate = QDir::currentPath() + "/Updates/new_version.txt";
    QFile f(rdyFileUpdate);
    f.open(QIODevice::ReadOnly);
    if (!f.isOpen()){
        //qDebug() << "NOT READY TO UPDATE";
        return;
    }
    //если обновление скачалось, то раскидываем файлы по папкам



    qDebug() << "READY TO UPDATE";
    QString version = f.readLine();
    qDebug() << "NEW VERSION: " << version;
    QFile old_ver(QDir::currentPath() + "/ver.ini");
    old_ver.open(QIODevice::ReadWrite);
    old_ver.remove();
    QFile::copy(QDir::currentPath() + "/Updates/new_version.txt", QDir::currentPath() + "/ver.ini");
    f.remove();
    QDir directory(QDir::currentPath() + "/Updates");
    QStringList files = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files);
    for (auto x : files) {
        qDebug() << x;
        QFile upd(QDir::currentPath() + "/Updates/" + x);
        upd.open(QIODevice::ReadOnly);
        QTextStream stream(&upd);
        for (QString line = stream.readLine(); !line.isNull(); line = stream.readLine()) {
            QStringList tmp_file_line_list = line.split(";");
            QString current_file = QDir::currentPath() + "/Updates/" + tmp_file_line_list[0];
            QString dest_file = QDir::currentPath() + tmp_file_line_list[1] + "/" + tmp_file_line_list[0];
            qDebug() << current_file;
            qDebug() << dest_file;
            QFile::copy(current_file, dest_file);
            QFile del(current_file);
            del.remove();
        };
        upd.close();
        upd.remove();
    }
    QFile exefile(QDir::currentPath() + "/Updates/cossacks_qt.exe");
    if (exefile.exists()) {
        QMessageBox::information(this, "Обновление", "Обновление содержит изменение .exe файла. Для установки \
                                 обновления запустите \"update.bat\" от имени администратора \
                                 (Нажмите на update.bat правой кнопкой мыши - Запустить от имени администратора)");
        exit(0);
    } else {
        QProcess process;
        QStringList arguments;
        arguments << "/C"<<"start"<<QDir::currentPath() + "/restart.bat";
        process.setArguments(arguments);
        process.setProgram("cmd.exe");
        process.startDetached();
    }
}


void MainWindow::check_installed_maps() {
    QString Maps_path = QDir::currentPath() + "/Maps";
    QDir directory(Maps_path);
    QStringList files = directory.entryList(QStringList() << "*.ini"<< "*.ini", QDir::Files);
    for (auto x : files) {
        QFile map_ini_file(QDir::currentPath() + "/Maps/" + x);
        map_ini_file.open(QIODevice::ReadOnly);
        QString all = map_ini_file.readAll();
        QStringList tmp_file_line_list = all.split(":\r\n");
        QStringList maps_to_vector = tmp_file_line_list[0].split(";");
        QVector<QString> vec_of_maps;
        vec_of_maps.clear();
        for (auto y : maps_to_vector) {
            vec_of_maps.push_back(y);
        }

        maps_paths.push_back(vec_of_maps);
        maps_names.push_back(tmp_file_line_list[1]);
        maps_descr.push_back(tmp_file_line_list[2]);
        preview_paths.push_back(tmp_file_line_list[3]);

        map_ini_file.close();
    }

    // for (auto x : maps_paths) {
    //     for (auto y : x) {
    //         qDebug() << y;
    //     }
    // }
    // for (auto x : maps_names) {
    //     qDebug() << x;
    // }

    // for (auto x : maps_descr) {
    //     qDebug() << x;
    // }

    // for (auto x : preview_paths) {
    //     qDebug() << x;
    // }

    add_maps_to_widget();
}

void MainWindow::add_maps_to_widget() {
    for (auto x : maps_names) {
        ui->listWidget->addItem(x);
    }
}

void MainWindow::set_descr_and_img() {
    int indx = ui->listWidget->currentRow();
    ui->mapDescription->setText(maps_descr[indx]);
    QString preview_path = QDir::currentPath() + "/Maps/" + preview_paths[indx];
    qDebug() << preview_path;
    QPixmap pix;
    /** to check wether load ok */
    if(pix.load(preview_path)){
        /** scale pixmap to fit in label'size and keep ratio of pixmap */
        pix = pix.scaled( ui->mapPreview->size(),Qt::KeepAspectRatio);
         ui->mapPreview->setPixmap(pix);
    }
}

void MainWindow::set_chosen_maps()
{
    QFile pathini(QDir::currentPath() + "/path.ini");
    pathini.open(QIODevice::ReadOnly);
    QString cossacks_maps_path = pathini.readAll() + "/data/gen/terrainmasks.dlc5/rivers/";


    QDir().mkdir(cossacks_maps_path + "default_maps_");
    QDir directory(cossacks_maps_path);
    QStringList files = directory.entryList(QStringList() << "*.tga"<< "*.tga", QDir::Files);
    for (auto x : files) {
        QFile file(cossacks_maps_path + x);
        file.rename(cossacks_maps_path + x, cossacks_maps_path + "default_maps_/" + x);
        file.remove();
    }

    //copy files to csx folder
    QListWidget *qlw = ui->listWidget;
    for (int i = 0; i < maps_names.size(); i++) {
        if (qlw->item(i)->isSelected()) {
            for (auto y : maps_paths[i]) {
                //qDebug() << y;

                QFile::copy(QDir::currentPath() + "/Maps/" + y, cossacks_maps_path + y);
            }
        }
    }
}



void MainWindow::set_default_maps() {
    QFile pathini(QDir::currentPath() + "/path.ini");
    pathini.open(QIODevice::ReadOnly);
    QString cossacks_maps_path = pathini.readAll() + "/data/gen/terrainmasks.dlc5/rivers/";

    //delete all files from csx folder
    QDir directory(cossacks_maps_path);
    QStringList files = directory.entryList(QStringList() << "*.tga"<< "*.tga", QDir::Files);
    for (auto x : files) {
        //qDebug() << "Deleting  " + x;
        QFile::remove(cossacks_maps_path + x);
    }

    //copy files to csx folder
    QDir directory_def_maps(cossacks_maps_path + "default_maps_");
    //qDebug() << directory_def_maps;
    QStringList def_maps = directory_def_maps.entryList(QStringList() << "*.tga"<< "*.tga", QDir::Files);

    for (auto z : def_maps) {
        QFile::copy(cossacks_maps_path + "default_maps_/" + z, cossacks_maps_path + z);
        QFile::remove(cossacks_maps_path + "default_maps_/" + z);
    }
}

void MainWindow::on_pushButtonClose_clicked()
{
    exit(0);
}


void MainWindow::on_checkBoxChooseAll_stateChanged(int arg1)
{
    if (ui->checkBoxChooseAll->isChecked()) {
        for (int i = 0; i < maps_names.size(); i++) {
            ui->listWidget->item(i)->setSelected(true);
            ui->listWidget->item(i)->setBackground(QColor(230, 138, 0, 255));
        }
    } else {
        for (int i = 0; i < maps_names.size(); i++) {
            ui->listWidget->item(i)->setSelected(false);
            ui->listWidget->item(i)->setBackground(QColor(255, 50, 0, 0));
        }
    }
}


void MainWindow::on_pushButtonOnMode_clicked()
{
    ui->pushButtonOnMode->setHidden(true);
    ui->pushButtonOffMode->setHidden(false);

    QFile pathini(QDir::currentPath() + "/path.ini");
    pathini.open(QIODevice::ReadOnly);
    QString cossacks_path = pathini.readAll();
    QString mode_path = QDir::currentPath() + "/Mode14players/";


    QFile::remove(cossacks_path + "/data/hud/textures/ui/logo_small.bmp");
    QFile::copy(mode_path + "data/hud/textures/ui/logo_small_Xpl.bmp", cossacks_path + "/data/hud/textures/ui/logo_small.bmp");

    QFile::remove(cossacks_path + "/data/scripts/dmscript.global");
    QFile::copy(mode_path + "/data/scripts/dmscript_Xpl.global", cossacks_path + "/data/scripts/dmscript.global");

    QFile::remove(cossacks_path + "/data/scripts/common.inc/dogenerate.inc");
    QFile::copy(mode_path + "/data/scripts/common.inc/dogenerate_Xpl.inc", cossacks_path + "/data/scripts/common.inc/dogenerate.inc");

    QFile::remove(cossacks_path + "/data/scripts/common.inc/initmapgen.inc");
    QFile::copy(mode_path + "/data/scripts/common.inc/initmapgen_Xpl.inc", cossacks_path + "/data/scripts/common.inc/initmapgen.inc");

    QFile::remove(cossacks_path + "/data/scripts/common.inc/texturemap.inc");
    QFile::copy(mode_path + "/data/scripts/common.inc/texturemap_Xpl.inc", cossacks_path + "/data/scripts/common.inc/texturemap.inc");

    QFile::remove(cossacks_path + "/data/scripts/lib/classes.script");
    QFile::copy(mode_path + "/data/scripts/lib/classes_Xpl.script", cossacks_path + "/data/scripts/lib/classes.script");

    QFile::remove(cossacks_path + "/data/scripts/lib/misc.script");
    QFile::copy(mode_path + "/data/scripts/lib/misc_Xpl.script", cossacks_path + "/data/scripts/lib/misc.script");
}


void MainWindow::on_pushButtonOffMode_clicked()
{
    ui->pushButtonOnMode->setHidden(false);
    ui->pushButtonOffMode->setHidden(true);

    QFile pathini(QDir::currentPath() + "/path.ini");
    pathini.open(QIODevice::ReadOnly);
    QString cossacks_path = pathini.readAll();
    QString mode_path = QDir::currentPath() + "/Mode14players/";


    QFile::remove(cossacks_path + "/data/hud/textures/ui/logo_small.bmp");
    QFile::copy(mode_path + "data/hud/textures/ui/logo_small.bmp", cossacks_path + "/data/hud/textures/ui/logo_small.bmp");

    QFile::remove(cossacks_path + "/data/scripts/dmscript.global");
    QFile::copy(mode_path + "/data/scripts/dmscript.global", cossacks_path + "/data/scripts/dmscript.global");

    QFile::remove(cossacks_path + "/data/scripts/common.inc/dogenerate.inc");
    QFile::copy(mode_path + "/data/scripts/common.inc/dogenerate.inc", cossacks_path + "/data/scripts/common.inc/dogenerate.inc");

    QFile::remove(cossacks_path + "/data/scripts/common.inc/initmapgen.inc");
    QFile::copy(mode_path + "/data/scripts/common.inc/initmapgen.inc", cossacks_path + "/data/scripts/common.inc/initmapgen.inc");

    QFile::remove(cossacks_path + "/data/scripts/common.inc/texturemap.inc");
    QFile::copy(mode_path + "/data/scripts/common.inc/texturemap.inc", cossacks_path + "/data/scripts/common.inc/texturemap.inc");

    QFile::remove(cossacks_path + "/data/scripts/lib/classes.script");
    QFile::copy(mode_path + "/data/scripts/lib/classes.script", cossacks_path + "/data/scripts/lib/classes.script");

    QFile::remove(cossacks_path + "/data/scripts/lib/misc.script");
    QFile::copy(mode_path + "/data/scripts/lib/misc.script", cossacks_path + "/data/scripts/lib/misc.script");
}

void MainWindow::changeItemColor()
{
    int indx = ui->listWidget->currentRow();
    if (ui->listWidget->currentItem()->isSelected()) {
        ui->listWidget->item(indx)->setBackground(QColor(230, 138, 0, 255));
    } else {
        ui->listWidget->item(indx)->setBackground(QColor(0, 0, 0, 0));
    }
}

