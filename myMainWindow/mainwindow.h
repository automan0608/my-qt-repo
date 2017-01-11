#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QDialog;

class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void newFile();
    bool maybeSave();
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);

private slots:
    void on_actionNew_File_N_triggered();

    void on_actionSave_S_triggered();

    void on_actionSave_as_A_triggered();

    void on_actionNew_N_triggered();

    void showFindText();

private:
    Ui::MainWindow *ui;

    bool isUntitled;
    QString curFile;

    QLineEdit *findLineEdit;
    QDialog *findDlg;

    QLabel *statusLabel;
};

#endif // MAINWINDOW_H
