#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlError>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_createDatabaseButton_clicked();

    void createDatabase();

    void on_openDatabaseButton_clicked();

    void on_addRecordButton_clicked();

    void on_deleteRecordButton_clicked();

    void on_viewDataButton_clicked();

    void on_centralRegionButton_clicked();

    void on_privolzhskyRegionButton_clicked();

    void on_populationASCButton_clicked();

    void on_areaDESCButton_clicked();

signals:
    void databaseCreated();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    void createAndPopulateDatabase();
    void viewDatabaseData();
    void openDatabase(const QString &fileName);
    void loadTableData();
};

#endif // MAINWINDOW_H
