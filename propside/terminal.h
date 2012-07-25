#ifndef TERMINAL_H
#define TERMINAL_H

#include <QtGui>
#include "console.h"
#include "PortListener.h"
#include "loader.h"
#include "termprefs.h"

class Terminal : public QDialog
{
    Q_OBJECT
public:
    explicit Terminal(QWidget *parent);
    void setPortListener(PortListener *listener);
    void setPosition(int x, int y);
    void accept();
    void reject();
    int  baudRate();
    bool setBaudRate(int baud);

private:
    void init();

public slots:
    void baudRateChange(int index);
    void toggleEnable();
    void setPortEnabled(bool value);
    void clearScreen();
    void copyFromFile();
    void cutFromFile();
    void pasteToFile();
    void showOptions();

public:
    Console *getEditor();
private:
    Console     *termEditor;
    TermPrefs   *options;
    QComboBox   *comboBoxBaud;

private:
    QPushButton     *buttonEnable;
    PortListener    *portListener;
};

#endif // TERMINAL_H
