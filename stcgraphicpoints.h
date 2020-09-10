#ifndef STCGRAPHICPOINTS_H
#define STCGRAPHICPOINTS_H

#include <QGraphicsView>

/*!
 * \brief The StcGraphicPoints class переопределение класса работы с графикой для обработки событий
 */
class StcGraphicPoints : public QGraphicsView
{
	int scrollPoint = 0;

public:
	explicit StcGraphicPoints(QWidget *parent = nullptr);
	/*!
	 * \brief wheelEvent обработка события вращения колесика мышки для маштабирования
	 * \param event
	 */
	void wheelEvent(QWheelEvent *event) override;

	/*!
	 * \brief paintEvent обработка события перерисовки виджета для маштабирования рисунка
	 * \param event
	 */
	void paintEvent(QPaintEvent *event) override;
};

#endif // STCGRAPHICPOINTS_H
