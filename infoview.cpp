#include <QtGui>
#include "infoview.h"

InfoView::InfoView(QWidget* parent) : QWidget(parent) {
  QGridLayout *mainLayout = new QGridLayout;
  setLayout(mainLayout);
}

