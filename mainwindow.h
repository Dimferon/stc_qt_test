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

	/*!
	 * \brief mScene сцена для отображения точек
	 */
	QGraphicsScene *mScene = nullptr;
	QFileDialog *mFileDialog = nullptr;

	/*!
	 * \brief mPrintPoints список полученных из файлов точек
	 */
	QList<QSharedPointer<QGraphicsEllipseItem>> mPrintPoints;

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	/*!
	 * \brief on_pushButton_clicked выбор и обработка файла при нажатие на кнопку "Открыть XML"
	 */
	void on_pushButton_clicked();

private:
	Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
