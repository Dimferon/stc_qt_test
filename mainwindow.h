#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QObject>
#include <QtXml/QXmlReader>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QGraphicsScene *mScene = nullptr;
	QFileDialog *mFileDialog = nullptr;

	QList<QSharedPointer<QGraphicsEllipseItem>> mPrintPoints;

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_pushButton_clicked();

private:
	Ui::MainWindow *ui;
	bool event(QEvent *event) override;
};
#endif // MAINWINDOW_H
