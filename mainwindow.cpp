#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QFileDialog>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->createDatabaseButton, &QPushButton::clicked, this, &MainWindow::on_createDatabaseButton_clicked);

    connect(this, &MainWindow::databaseCreated, this, &MainWindow::createDatabase);

    connect(ui->viewDataButton, SIGNAL(clicked()), this, SLOT(on_viewDataButton_clicked()));

    model = new QSqlQueryModel(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createDatabaseButton_clicked()
{
    emit databaseCreated();
}

void MainWindow::createDatabase()
{
    createAndPopulateDatabase();
}

void MainWindow::createAndPopulateDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("places.db");

    if (!db.open()) {
        qDebug() << "Ошибка открытия базы данных:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    if (!query.exec(
            "CREATE TABLE IF NOT EXISTS places ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL, "
            "region TEXT NOT NULL, "
            "population INTEGER, "
            "area REAL, "
            "UNIQUE(name, region))"
        )) {
        qDebug() << "Ошибка создания таблицы:" << query.lastError().text();
        return;
    }

    query.prepare("INSERT INTO places (name, region, population, area) VALUES (?, ?, ?, ?)");

    QList<QList<QVariant> > records;
    QList<QVariant> record1;
    record1.append("Москва");
    record1.append("Центральный");
    record1.append(12615882);
    record1.append(2511);
    records.append(record1);

    QList<QVariant> record2;
    record2.append("Санкт-Петербург");
    record2.append("Северо-Западный");
    record2.append(5383890);
    record2.append(1439);
    records.append(record2);

    QList<QVariant> record3;
    record3.append("Новосибирск");
    record3.append("Сибирский");
    record3.append(1625600);
    record3.append(502);
    records.append(record3);

    QList<QVariant> record4;
    record4.append("Екатеринбург");
    record4.append("Уральский");
    record4.append(1484456);
    record4.append(1143);
    records.append(record4);

    QList<QVariant> record5;
    record5.append("Казань");
    record5.append("Приволжский");
    record5.append(1257391);
    record5.append(614);
    records.append(record5);

    QList<QVariant> record6;
    record6.append("Нижний Новгород");
    record6.append("Приволжский");
    record6.append(1220585);
    record6.append(466);
    records.append(record6);

    QList<QVariant> record7;
    record7.append("Челябинск");
    record7.append("Уральский");
    record7.append(1202371);
    record7.append(530);
    records.append(record7);

    QList<QVariant> record8;
    record8.append("Самара");
    record8.append("Приволжский");
    record8.append(1156655);
    record8.append(541);
    records.append(record8);

    QList<QVariant> record9;
    record9.append("Ростов-на-Дону");
    record9.append("Южный");
    record9.append(1130302);
    record9.append(348);
    records.append(record9);

    QList<QVariant> record10;
    record10.append("Уфа");
    record10.append("Приволжский");
    record10.append(1128272);
    record10.append(707);
    records.append(record10);

    QList<QVariant> record11;
    record11.append("Красноярск");
    record11.append("Сибирский");
    record11.append(1120543);
    record11.append(381);
    records.append(record11);

    QList<QVariant> record12;
    record12.append("Воронеж");
    record12.append("Центральный");
    record12.append(1056674);
    record12.append(596);
    records.append(record12);

    QList<QVariant> record13;
    record13.append("Пермь");
    record13.append("Приволжский");
    record13.append(1037897);
    record13.append(799);
    records.append(record13);

    QList<QVariant> record14;
    record14.append("Волгоград");
    record14.append("Южный");
    record14.append(1011418);
    record14.append(859);
    records.append(record14);

    QList<QVariant> record15;
    record15.append("Краснодар");
    record15.append("Южный");
    record15.append(958719);
    record15.append(341);
    records.append(record15);

    QList<QVariant> record16;
    record16.append("Саратов");
    record16.append("Приволжский");
    record16.append(917320);
    record16.append(456);
    records.append(record16);

    QList<QVariant> record17;
    record17.append("Тюмень");
    record17.append("Уральский");
    record17.append(834146);
    record17.append(236);
    records.append(record17);

    QList<QVariant> record18;
    record18.append("Ижевск");
    record18.append("Приволжский");
    record18.append(646277);
    record18.append(315);
    records.append(record18);

    QList<QVariant> record19;
    record19.append("Барнаул");
    record19.append("Сибирский");
    record19.append(635585);
    record19.append(322);
    records.append(record19);

    QList<QVariant> record20;
    record20.append("Ульяновск");
    record20.append("Приволжский");
    record20.append(613793);
    record20.append(385);
    records.append(record20);

    QList<QVariant> record21;
    record21.append("Владивосток");
    record21.append("Дальневосточный");
    record21.append(600378);
    record21.append(331);
    records.append(record21);

    QList<QVariant> record22;
    record22.append("Ярославль");
    record22.append("Центральный");
    record22.append(606730);
    record22.append(205);
    records.append(record22);

    QList<QVariant> record23;
    record23.append("Иркутск");
    record23.append("Сибирский");
    record23.append(623562);
    record23.append(274);
    records.append(record23);

    QList<QVariant> record24;
    record24.append("Тула");
    record24.append("Центральный");
    record24.append(493813);
    record24.append(147);
    records.append(record24);

    QList<QVariant> record25;
    record25.append("Омск");
    record25.append("Сибирский");
    record25.append(1154000);
    record25.append(572);
    records.append(record25);

    QList<QVariant> record26;
    record26.append("Хабаровск");
    record26.append("Дальневосточный");
    record26.append(618150);
    record26.append(386);
    records.append(record26);

    QList<QVariant> record27;
    record27.append("Кемерово");
    record27.append("Сибирский");
    record27.append(552546);
    record27.append(297);
    records.append(record27);

    QList<QVariant> record28;
    record28.append("Томск");
    record28.append("Сибирский");
    record28.append(577247);
    record28.append(294);
    records.append(record28);

    QList<QVariant> record29;
    record29.append("Оренбург");
    record29.append("Приволжский");
    record29.append(563986);
    record29.append(259);
    records.append(record29);

    QList<QVariant> record30;
    record30.append("Киров");
    record30.append("Приволжский");
    record30.append(489836);
    record30.append(171);
    records.append(record30);

    QList<QVariant> record31;
    record31.append("Пенза");
    record31.append("Приволжский");
    record31.append(515657);
    record31.append(289);
    records.append(record31);

    QList<QVariant> record32;
    record32.append("Тверь");
    record32.append("Центральный");
    record32.append(421416);
    record32.append(152);
    records.append(record32);

    QList<QVariant> record33;
    record33.append("Липецк");
    record33.append("Центральный");
    record33.append(506114);
    record33.append(321);
    records.append(record33);

    QList<QVariant> record34;
    record34.append("Астрахань");
    record34.append("Южный");
    record34.append(532699);
    record34.append(208);
    records.append(record34);

    QList<QVariant> record35;
    record35.append("Махачкала");
    record35.append("Северо-Кавказский");
    record35.append(614974);
    record35.append(462);
    records.append(record35);

    QList<QVariant> record36;
    record36.append("Чебоксары");
    record36.append("Приволжский");
    record36.append(489685);
    record36.append(251);
    records.append(record36);

    QList<QVariant> record37;
    record37.append("Калининград");
    record37.append("Северо-Западный");
    record37.append(489359);
    record37.append(223);
    records.append(record37);

    QList<QVariant> record38;
    record38.append("Севастополь");
    record38.append("Южный");
    record38.append(449241);
    record38.append(864);
    records.append(record38);

    QList<QVariant> record39;
    record39.append("Сочи");
    record39.append("Южный");
    record39.append(426994);
    record39.append(3505);
    records.append(record39);

    QList<QVariant> record40;
    record40.append("Рязань");
    record40.append("Центральный");
    record40.append(538962);
    record40.append(224);
    records.append(record40);

    QList<QVariant> record41;
    record41.append("Якутск");
    record41.append("Дальневосточный");
    record41.append(355443);
    record41.append(122);
    records.append(record41);

    QList<QVariant> record42;
    record42.append("Смоленск");
    record42.append("Центральный");
    record42.append(325556);
    record42.append(166);
    records.append(record42);

    QList<QVariant> record43;
    record43.append("Владикавказ");
    record43.append("Северо-Кавказский");
    record43.append(306487);
    record43.append(292);
    records.append(record43);

    QList<QVariant> record44;
    record44.append("Курск");
    record44.append("Центральный");
    record44.append(442193);
    record44.append(190);
    records.append(record44);

    QList<QVariant> record45;
    record45.append("Курган");
    record45.append("Уральский");
    record45.append(309285);
    record45.append(393);
    records.append(record45);

    QList<QVariant> record46;
    record46.append("Магнитогорск");
    record46.append("Уральский");
    record46.append(407775);
    record46.append(345);
    records.append(record46);

    QList<QVariant> record47;
    record47.append("Таганрог");
    record47.append("Южный");
    record47.append(251939);
    record47.append(111);
    records.append(record47);

    QList<QVariant> record48;
    record48.append("Шахты");
    record48.append("Южный");
    record48.append(235738);
    record48.append(161);
    records.append(record48);

    QList<QVariant> record49;
    record49.append("Брянск");
    record49.append("Центральный");
    record49.append(412520);
    record49.append(248);
    records.append(record49);

    QList<QVariant> record50;
    record50.append("Белгород");
    record50.append("Центральный");
    record50.append(391554);
    record50.append(153);
    records.append(record50);

    for (int i = 0; i < records.size(); ++i) {
        const QList<QVariant> &record = records[i];

        query.addBindValue(record[0]);
        query.addBindValue(record[1]);
        query.addBindValue(record[2]);
        query.addBindValue(record[3]);

        if (!query.exec()) {
            if (query.lastError().text().contains("UNIQUE constraint failed")) {
                qDebug() << "Дубликат записи, пропущено: " << record[0].toString() << ", " << record[1].toString();
            } else {
                qDebug() << "Ошибка добавления записи:" << query.lastError().text();
            }
        }
    }

    qDebug() << "База данных создана и заполнена.";
}

void MainWindow::on_openDatabaseButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть базу данных", "", "SQLite Files (*.db)");
    if (!fileName.isEmpty()) {
        openDatabase(fileName);
    }
}

void MainWindow::openDatabase(const QString &fileName) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(fileName);
    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных: " + db.lastError().text());
        return;
    }
    QMessageBox::information(this, "Успех", "База данных успешно открыта!");
    loadTableData();
}

void MainWindow::loadTableData() {
    QSqlQueryModel *model = new QSqlQueryModel(this);

    model->setQuery("SELECT * FROM places");

    if (model->lastError().isValid()) {
        qDebug() << "Ошибка загрузки данных:" << model->lastError().text();
        return;
    }
}

void MainWindow::on_addRecordButton_clicked() {
    bool populationOk, areaOk;
    int population = ui->lineEdit_Population->text().toInt(&populationOk);
    double area = ui->lineEdit_Area->text().toDouble(&areaOk);

    if (!populationOk) {
        QMessageBox::warning(this, "Ошибка ввода", "Введите корректное значение для населения (целое число).");
        return;
    }

    if (!areaOk) {
        QMessageBox::warning(this, "Ошибка ввода", "Введите корректное значение для площади (число).");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO places (name, region, population, area) VALUES (?, ?, ?, ?)");
    query.addBindValue(ui->lineEdit_Name->text());
    query.addBindValue(ui->lineEdit_Region->text());
    query.addBindValue(population);
    query.addBindValue(area);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Успех", "Запись добавлена!");

    loadTableData();

    ui->lineEdit_Name->clear();
    ui->lineEdit_Region->clear();
    ui->lineEdit_Population->clear();
    ui->lineEdit_Area->clear();
}

void MainWindow::on_deleteRecordButton_clicked() {
    QSqlQuery query;
    query.prepare("DELETE FROM places WHERE id = ?");
    query.addBindValue(ui->lineEdit_ID->text().toInt());
    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", query.lastError().text());
        return;
    }
    loadTableData();
}

void MainWindow::on_viewDataButton_clicked() {
    viewDatabaseData();
}

void MainWindow::viewDatabaseData() {
    QSqlQuery query("SELECT * FROM places");

    if (query.exec()) {
        model->setQuery(query);

        ui->tableView->setModel(model);

        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeColumnsToContents();
    } else {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
    }
}

void MainWindow::on_centralRegionButton_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM places WHERE region = :region");
    query.bindValue(":region", "Центральный");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", query.lastError().text());
        return;
    }

    model->setQuery(query);
    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_privolzhskyRegionButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM places WHERE region = :region");
    query.bindValue(":region", "Приволжский");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", query.lastError().text());
        return;
    }

    model->setQuery(query);
    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_populationASCButton_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM places ORDER BY population ASC");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", query.lastError().text());
        return;
    }

    model->setQuery(query);
    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_areaDESCButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM places ORDER BY area DESC");

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", query.lastError().text());
        return;
    }

    model->setQuery(query);
    ui->tableView->setModel(model);

    ui->tableView->resizeColumnsToContents();
}
