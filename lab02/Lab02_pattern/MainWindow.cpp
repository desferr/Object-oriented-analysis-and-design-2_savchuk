#include <windows.h>
#include "MainWindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QKeyEvent>
#include <QRadioButton>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.pushButtonRead, &QPushButton::clicked, this, &MainWindow::onReadButtonClicked);

    m_visualizer = std::make_unique<TextVisualizer>(70, 75); // 70x75
    ui.canvasWidget->setTextVisualizer(m_visualizer.get());
    connect(ui.canvasWidget, &Canvas::cellClicked, this, &MainWindow::onCellClicked);
    connect(ui.radioBlack, &QRadioButton::toggled, this, &MainWindow::onColorRadioToggled);
    connect(ui.radioRed, &QRadioButton::toggled, this, &MainWindow::onColorRadioToggled);
    connect(ui.radioGreen, &QRadioButton::toggled, this, &MainWindow::onColorRadioToggled);
    connect(ui.radioBlue, &QRadioButton::toggled, this, &MainWindow::onColorRadioToggled);
    connect(ui.radioYellow, &QRadioButton::toggled, this, &MainWindow::onColorRadioToggled);
    connect(ui.checkBoxColorSelected, &QCheckBox::toggled, this, &MainWindow::onColorSelectedToggled);
    connect(ui.pushButtonSave, &QPushButton::clicked, this, &MainWindow::saveToFile);
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (m_selectedRow != -1 && m_selectedColumn != -1)
    {
        if (event->key() == Qt::Key_CapsLock)
        {
            showMemoryUsage();
            event->accept();
            return;
        }
        else if (event->key() == Qt::Key_Control)
        {
            ui.checkBoxColorSelected->toggle();
            event->accept();
        }
        else if (event->key() == Qt::Key_Alt)
        {
            if (ui.radioBlack->isChecked()) ui.radioRed->toggle();
            else if (ui.radioRed->isChecked()) ui.radioGreen->toggle();
            else if (ui.radioGreen->isChecked()) ui.radioBlue->toggle();
            else if (ui.radioBlue->isChecked()) ui.radioYellow->toggle();
            else if (ui.radioYellow->isChecked()) ui.radioBlack->toggle();
            event->accept();
        }
        else if (event->key() == Qt::Key_Backspace)
        {
            if (m_selectedColumn >= 1) { m_visualizer->removeSymbol(m_selectedRow, m_selectedColumn - 1, m_currentColor); m_selectedColumn--; }
            else if (m_selectedColumn == 0 && m_selectedRow >= 1) { m_selectedRow--; m_selectedColumn = m_visualizer->findLastCharColumn(m_selectedRow); }
            if (m_selectedColumn == m_visualizer->getColumns()) { m_selectedColumn--;  m_visualizer->removeSymbol(m_selectedRow, m_selectedColumn, m_currentColor); }
            ui.canvasWidget->setSelectedCell(m_selectedRow, m_selectedColumn);
            applyColorToSelected();
            ui.canvasWidget->drawTextVisualizer(*m_visualizer);
            event->accept();
        }
        else if (event->key() == Qt::Key_Return)
        {
            if (m_selectedRow < m_visualizer->getRows() - 1) { m_selectedRow++; m_selectedColumn = 0; }
            ui.canvasWidget->setSelectedCell(m_selectedRow, m_selectedColumn);
            applyColorToSelected();
            event->accept();
        }
        else if (event->key() == Qt::Key_Left)
        {
            if (m_selectedColumn >= 1) m_selectedColumn--;
            else if (m_selectedColumn == 0 && m_selectedRow >= 1) { m_selectedRow--; m_selectedColumn = m_visualizer->findLastCharColumn(m_selectedRow); }
            if (m_selectedColumn == m_visualizer->getColumns()) { m_selectedColumn--; }
            ui.canvasWidget->setSelectedCell(m_selectedRow, m_selectedColumn);
            applyColorToSelected();
            event->accept();
        }
        else if (event->key() == Qt::Key_Right)
        {
            if (m_selectedColumn < m_visualizer->getColumns() - 1) { m_selectedColumn++; }
            else if (m_selectedColumn == m_visualizer->getColumns() - 1 && m_selectedRow < m_visualizer->getRows() - 1) { m_selectedRow++; m_selectedColumn = 0; }
            ui.canvasWidget->setSelectedCell(m_selectedRow, m_selectedColumn);
            applyColorToSelected();
            event->accept();
        }
        else if (event->key() == Qt::Key_Up && m_selectedRow >= 1)
        {
            m_selectedRow--;
            if (m_visualizer->isLastSymbolInRow(m_selectedRow + 1, m_selectedColumn)) m_selectedColumn = m_visualizer->findLastCharColumn(m_selectedRow);
            else if (m_selectedColumn > m_visualizer->findLastCharColumn(m_selectedRow)) m_selectedColumn = m_visualizer->findLastCharColumn(m_selectedRow);
            if (m_selectedColumn == m_visualizer->getColumns()) { m_selectedColumn--; }
            ui.canvasWidget->setSelectedCell(m_selectedRow, m_selectedColumn);
            applyColorToSelected();
            event->accept();
        }
        else if (event->key() == Qt::Key_Down && m_selectedRow < m_visualizer->getRows() - 1)
        {
            m_selectedRow++;
            if (m_visualizer->isLastSymbolInRow(m_selectedRow - 1, m_selectedColumn)) m_selectedColumn = m_visualizer->findLastCharColumn(m_selectedRow);
            else if (m_selectedColumn > m_visualizer->findLastCharColumn(m_selectedRow)) m_selectedColumn = m_visualizer->findLastCharColumn(m_selectedRow);
            if (m_selectedColumn == m_visualizer->getColumns()) { m_selectedColumn--; }
            ui.canvasWidget->setSelectedCell(m_selectedRow, m_selectedColumn);
            applyColorToSelected();
            event->accept();
        }
        QString text = event->text();
        if (!text.isEmpty())
        {
            QChar ch = text[0];
            if (TextVisualizer::isAllowedChar(ch))
            {
                m_visualizer->setSymbol(m_selectedRow, m_selectedColumn, ch, m_currentColor);
                m_visualizer->changeLeftNullToSpace(m_selectedRow, m_selectedColumn, m_currentColor);
                ui.canvasWidget->drawTextVisualizer(*m_visualizer);
                if (m_selectedColumn < m_visualizer->getColumns() - 1)
                {
                    m_selectedColumn++;
                }
                else if (m_selectedRow < m_visualizer->getRows() - 1)
                {
                    m_selectedRow++;
                    m_selectedColumn = 0;
                }
                ui.canvasWidget->setSelectedCell(m_selectedRow, m_selectedColumn);
                event->accept();
            }
        }
    }
    else 
    {
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::onCellClicked(int row, int column)
{
    m_selectedRow = row;
    m_selectedColumn = column;
    applyColorToSelected();
}

void MainWindow::onReadButtonClicked()
{
    QString filePath = ui.lineEditFilePath->text();
    if (filePath.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Enter file path!");
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "Cannot open file: " + file.errorString());
        return;
    }
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();
    ui.canvasWidget->clearSelection();
    m_selectedRow = -1;
    m_selectedColumn = -1;
    m_visualizer->parseText(content, m_currentColor);
    ui.canvasWidget->drawTextVisualizer(*m_visualizer);
    ui.canvasWidget->setFocus();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        if (obj != ui.canvasWidget)
        {
            ui.canvasWidget->clearSelection();
            m_selectedRow = -1;
            m_selectedColumn = -1;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::onColorRadioToggled()
{
    if (ui.radioBlack->isChecked()) m_currentColor = Qt::black;
    else if (ui.radioRed->isChecked()) m_currentColor = Qt::red;
    else if (ui.radioGreen->isChecked()) m_currentColor = Qt::green;
    else if (ui.radioBlue->isChecked()) m_currentColor = Qt::blue;
    else if (ui.radioYellow->isChecked()) m_currentColor = Qt::yellow;
    applyColorToSelected();
}

void MainWindow::onColorSelectedToggled(bool checked)
{
    m_colorSelectedActive = checked;
    if (m_colorSelectedActive) applyColorToSelected();
}

void MainWindow::applyColorToSelected()
{
    if (!m_colorSelectedActive) return;
    if (m_selectedRow == -1 || m_selectedColumn == -1) return;
    auto& matrix = m_visualizer->getMatrix();
    if (matrix[m_selectedRow][m_selectedColumn] != nullptr)
    {
        m_visualizer->setSymbolColor(m_selectedRow, m_selectedColumn, m_currentColor);
        ui.canvasWidget->drawTextVisualizer(*m_visualizer);
    }
}

void MainWindow::saveToFile()
{
    QString filePath = ui.lineEditSaveFile->text().trimmed();
    if (filePath.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Enter file path!");
        return;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "Cannot create file: " + file.errorString());
        return;
    }
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    const auto& matrix = m_visualizer->getMatrix();
    int rows = m_visualizer->getRows();
    int columns = m_visualizer->getColumns();
    bool saveColors = ui.checkBoxSaveColor->isChecked();
    QColor currentColor;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            const auto& context = matrix[row][column];
            if (!context) { out << "\n"; break; }
            QChar ch = context->getChar();
            if (saveColors)
            {
                QColor color = context->getColor();
                if (currentColor != color)
                {
                    out << tagForColor(color);
                    currentColor = color;
                }
            }
            out << ch;
        }
    }
    file.close();
    QMessageBox::information(this, "Success", "The file was successfully written to the path: " + filePath);
}

QString MainWindow::tagForColor(const QColor& color) const
{
    if (color == Qt::black) return "<k>";
    if (color == Qt::red) return "<r>";
    if (color == Qt::green) return "<g>";
    if (color == Qt::blue) return "<b>";
    if (color == Qt::yellow) return "<y>";
    return "</>";
}

size_t MainWindow::getCurrentMemoryUsage()
{
    size_t totalMemory = 0;
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    uintptr_t address = (uintptr_t)sysInfo.lpMinimumApplicationAddress;
    uintptr_t maxAddress = (uintptr_t)sysInfo.lpMaximumApplicationAddress;

    while (address < maxAddress)
    {
        MEMORY_BASIC_INFORMATION mbi;
        if (VirtualQuery((LPCVOID)address, &mbi, sizeof(mbi)) == 0) break;
        if (mbi.State == MEM_COMMIT && mbi.Type == MEM_PRIVATE) totalMemory += mbi.RegionSize;
        address = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
    }
    return totalMemory;
}

void MainWindow::showMemoryUsage()
{
    size_t sysMem = getCurrentMemoryUsage();
    double sysMB = static_cast<double>(sysMem) / (1024.0 * 1024.0);
    
    size_t manualMem = 0;
    int nonEmpty = m_visualizer->getNonEmptyCount();
    int uniqueChars = m_visualizer->getUniqueCharCount();

    manualMem += m_visualizer->getRows() * m_visualizer->getColumns() * sizeof(std::shared_ptr<CharContext>);
    manualMem += nonEmpty * sizeof(CharContext);
    manualMem += uniqueChars * sizeof(CharFlyweight);
    double manualMB = static_cast<double>(manualMem) / (1024.0 * 1024.0);

    QString msg = QString("System memory: %1 MB\n""Manual calculated memory: %2 MB\n""Non empty cells: %3\n""Unique symbols: %4").arg(sysMB, 0, 'f', 2).arg(manualMB, 0, 'f', 2).arg(nonEmpty).arg(uniqueChars);
    QMessageBox::information(this, "Memory", msg);
}