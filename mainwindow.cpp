#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsItem>
#include <QXmlStreamReader>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	mScene = new QGraphicsScene(this);
	ui->graphicsView->setScene(mScene);
	mFileDialog = new QFileDialog(this);

	ui->graphicsView->resize(600, 600); // Устанавливаем размер graphicsView
	ui->graphicsView->setRenderHint(QPainter::Antialiasing); // Настраиваем рендер
	ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
	ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	mPrintPoints.clear();
	mScene->clear();

	mScene->setSceneRect(-20, -20, 40, 40);
	ui->graphicsView->fitInView(mScene->sceneRect(), Qt::KeepAspectRatio);

	auto filePath = mFileDialog->getOpenFileUrl(this,
												"Выбирите XML файл",
												QApplication::applicationDirPath(),
												"XML файл (*.xml)");
	ui->lineEdit_fileName->setText(filePath.toString().remove("file:///"));
	QFile file(filePath.toString().remove("file:///"));
	file.open(QFile::OpenModeFlag::ReadOnly);
	auto xmlData = file.readAll();
	file.close();
	QXmlStreamReader readXml(xmlData);
	readXml.readNext();
	readXml.readNext();
	auto atribs = readXml.attributes();
	QStringList atrKeys;
	for (int i = 0; i < atribs.size(); ++i) {
		atrKeys.push_back(atribs[i].name().toString());
	}

	auto caption = atribs[atrKeys.indexOf("Caption")].value().toString();
	int sizePoint = caption.remove("A").remove(" ").remove("Point").remove("s").toInt();

	QPoint point;
	readXml.readNext();
	for (int i = 0; i < sizePoint && !readXml.atEnd(); ++i, readXml.readNext()) {
		foreach (const auto &var, readXml.attributes()) {
			if (var.name() == "X")
				point.setX(var.value().toDouble());
			if (var.name() == "Y")
				point.setY(var.value().toDouble());
		}
		mPrintPoints.push_back(QSharedPointer<QGraphicsEllipseItem>(
			new QGraphicsEllipseItem(point.x(), point.y(), 1, 1)));
	}
	QGraphicsEllipseItem a;
	for (auto p : mPrintPoints) {
		mScene->addItem(p.get());
	}
	this->repaint();
}

bool MainWindow::event(QEvent *event)
{
	QMainWindow::event(event);
	if (event->type() == QEvent::Scroll) {
	}
}
