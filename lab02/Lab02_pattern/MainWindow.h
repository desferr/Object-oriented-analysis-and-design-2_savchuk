#pragma once

#include <QtWidgets/QMainWindow>
#include <memory>
#include "ui_MainWindow.h"
#include "TextVisualizer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void onCellClicked(int row, int column);
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void onReadButtonClicked();
    void onColorRadioToggled();
    void onColorSelectedToggled(bool checked);
    void showMemoryUsage();

private:
    void applyColorToSelected();
    void saveToFile();
    QString tagForColor(const QColor& color) const;
    size_t getCurrentMemoryUsage();

private:
    Ui::MainWindowClass ui;
    std::unique_ptr<TextVisualizer> m_visualizer;
    int m_selectedRow = -1;
    int m_selectedColumn = -1;
    QColor m_currentColor = Qt::black;
    bool m_colorSelectedActive = false;
};