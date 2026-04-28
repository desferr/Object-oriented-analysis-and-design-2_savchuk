# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mywindow.ui'
##
## Created by: Qt User Interface Compiler version 6.11.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QFrame, QLabel, QMainWindow,
    QMenuBar, QPushButton, QSizePolicy, QStatusBar,
    QTextEdit, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(800, 600)
        MainWindow.setMinimumSize(QSize(800, 600))
        MainWindow.setMaximumSize(QSize(800, 600))
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.readCardsButton = QPushButton(self.centralwidget)
        self.readCardsButton.setObjectName(u"readCardsButton")
        self.readCardsButton.setGeometry(QRect(10, 510, 200, 40))
        font = QFont()
        font.setPointSize(15)
        self.readCardsButton.setFont(font)
        self.readCardsTextEdit = QTextEdit(self.centralwidget)
        self.readCardsTextEdit.setObjectName(u"readCardsTextEdit")
        self.readCardsTextEdit.setGeometry(QRect(215, 510, 575, 40))
        font1 = QFont()
        font1.setPointSize(12)
        self.readCardsTextEdit.setFont(font1)
        self.readCardsTextEdit.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.readCardsTextEdit.setLineWrapMode(QTextEdit.LineWrapMode.NoWrap)
        self.deckFrame = QFrame(self.centralwidget)
        self.deckFrame.setObjectName(u"deckFrame")
        self.deckFrame.setGeometry(QRect(10, 10, 780, 421))
        self.deckFrame.setFrameShape(QFrame.Shape.StyledPanel)
        self.deckFrame.setFrameShadow(QFrame.Shadow.Raised)
        self.cardFrame = QFrame(self.deckFrame)
        self.cardFrame.setObjectName(u"cardFrame")
        self.cardFrame.setGeometry(QRect(90, 60, 600, 300))
        font2 = QFont()
        font2.setPointSize(9)
        font2.setStyleStrategy(QFont.PreferDefault)
        self.cardFrame.setFont(font2)
        self.cardFrame.setStyleSheet(u"QFrame#cardFrame {\n"
"	background-color: #9a9a9a;\n"
"	border-radius: 20px;\n"
"}\n"
"")
        self.cardFrame.setFrameShape(QFrame.Shape.StyledPanel)
        self.cardFrame.setFrameShadow(QFrame.Shadow.Plain)
        self.cardLabel = QLabel(self.cardFrame)
        self.cardLabel.setObjectName(u"cardLabel")
        self.cardLabel.setGeometry(QRect(20, 40, 560, 200))
        font3 = QFont()
        font3.setPointSize(22)
        font3.setBold(True)
        self.cardLabel.setFont(font3)
        self.cardLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.cardLabel.setWordWrap(True)
        self.prevCardButton = QPushButton(self.cardFrame)
        self.prevCardButton.setObjectName(u"prevCardButton")
        self.prevCardButton.setEnabled(True)
        self.prevCardButton.setGeometry(QRect(20, 270, 180, 30))
        self.prevCardButton.setStyleSheet(u"QPushButton#prevCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-radius: 0px;\n"
"	border-right: 2px solid black;\n"
"}\n"
"QPushButton#prevCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#prevCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.flipCardButton = QPushButton(self.cardFrame)
        self.flipCardButton.setObjectName(u"flipCardButton")
        self.flipCardButton.setEnabled(True)
        self.flipCardButton.setGeometry(QRect(200, 270, 200, 30))
        self.flipCardButton.setStyleSheet(u"QPushButton#flipCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-radius: 0px;\n"
"}\n"
"QPushButton#flipCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#flipCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.nextCardButton = QPushButton(self.cardFrame)
        self.nextCardButton.setObjectName(u"nextCardButton")
        self.nextCardButton.setEnabled(True)
        self.nextCardButton.setGeometry(QRect(400, 270, 180, 30))
        self.nextCardButton.setStyleSheet(u"QPushButton#nextCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-bottom-right-radius: 0px;\n"
"	border-left: 2px solid black;\n"
"}\n"
"QPushButton#nextCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#nextCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.firstCardButton = QPushButton(self.cardFrame)
        self.firstCardButton.setObjectName(u"firstCardButton")
        self.firstCardButton.setEnabled(True)
        self.firstCardButton.setGeometry(QRect(0, 270, 20, 30))
        self.firstCardButton.setStyleSheet(u"QPushButton#firstCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-bottom-left-radius: 20px;\n"
"	border-right: 2px solid black;\n"
"}\n"
"QPushButton#firstCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#firstCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.lastCardButton = QPushButton(self.cardFrame)
        self.lastCardButton.setObjectName(u"lastCardButton")
        self.lastCardButton.setEnabled(True)
        self.lastCardButton.setGeometry(QRect(580, 270, 20, 30))
        self.lastCardButton.setStyleSheet(u"QPushButton#lastCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-bottom-right-radius: 20px;\n"
"	border-left: 2px solid black;\n"
"}\n"
"QPushButton#lastCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#lastCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.cardCountLabel = QLabel(self.cardFrame)
        self.cardCountLabel.setObjectName(u"cardCountLabel")
        self.cardCountLabel.setGeometry(QRect(250, 10, 100, 20))
        font4 = QFont()
        font4.setPointSize(15)
        font4.setBold(True)
        self.cardCountLabel.setFont(font4)
        self.cardCountLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.shuffleDeckButton = QPushButton(self.cardFrame)
        self.shuffleDeckButton.setObjectName(u"shuffleDeckButton")
        self.shuffleDeckButton.setEnabled(True)
        self.shuffleDeckButton.setGeometry(QRect(0, 0, 100, 35))
        font5 = QFont()
        font5.setPointSize(9)
        font5.setBold(True)
        self.shuffleDeckButton.setFont(font5)
        self.shuffleDeckButton.setStyleSheet(u"QPushButton#shuffleDeckButton{\n"
"	background-color: #D3D3D3;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-right-radius: 30px;\n"
"	border-bottom: 2px solid black;\n"
"	border-right: 2px solid black;\n"
"}\n"
"QPushButton#shuffleDeckButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#shuffleDeckButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.changeModeButton = QPushButton(self.cardFrame)
        self.changeModeButton.setObjectName(u"changeModeButton")
        self.changeModeButton.setEnabled(True)
        self.changeModeButton.setGeometry(QRect(480, 0, 120, 35))
        font6 = QFont()
        font6.setBold(True)
        self.changeModeButton.setFont(font6)
        self.changeModeButton.setStyleSheet(u"QPushButton#changeModeButton{\n"
"	background-color: #D3D3D3;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-left-radius: 30px;\n"
"	border-bottom: 2px solid black;\n"
"	border-left: 2px solid black;\n"
"}\n"
"QPushButton#changeModeButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#changeModeButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.editCardButton = QPushButton(self.cardFrame)
        self.editCardButton.setObjectName(u"editCardButton")
        self.editCardButton.setEnabled(True)
        self.editCardButton.setGeometry(QRect(0, 0, 75, 35))
        self.editCardButton.setFont(font6)
        self.editCardButton.setStyleSheet(u"QPushButton#editCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom: 2px solid black;\n"
"	border-right: 2px solid black;\n"
"}\n"
"QPushButton#editCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#editCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.addCardButton = QPushButton(self.cardFrame)
        self.addCardButton.setObjectName(u"addCardButton")
        self.addCardButton.setEnabled(True)
        self.addCardButton.setGeometry(QRect(75, 0, 75, 35))
        self.addCardButton.setFont(font6)
        self.addCardButton.setStyleSheet(u"QPushButton#addCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-radius: 0px;\n"
"	border-bottom: 2px solid black;\n"
"	border-right: 2px solid black;\n"
"}\n"
"QPushButton#addCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#addCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.deleteCardButton = QPushButton(self.cardFrame)
        self.deleteCardButton.setObjectName(u"deleteCardButton")
        self.deleteCardButton.setEnabled(True)
        self.deleteCardButton.setGeometry(QRect(150, 0, 75, 35))
        self.deleteCardButton.setFont(font6)
        self.deleteCardButton.setStyleSheet(u"QPushButton#deleteCardButton{\n"
"	background-color: #D3D3D3;\n"
"	border-bottom-right-radius: 30px;\n"
"	border-bottom: 2px solid black;\n"
"	border-right: 2px solid black;\n"
"}\n"
"QPushButton#deleteCardButton:hover{\n"
"	background-color: #C0C0C0;\n"
"}\n"
"QPushButton#deleteCardButton:pressed{\n"
"	background-color: #B6B6B6;\n"
"}")
        self.saveCardsButton = QPushButton(self.centralwidget)
        self.saveCardsButton.setObjectName(u"saveCardsButton")
        self.saveCardsButton.setGeometry(QRect(10, 465, 200, 40))
        self.saveCardsButton.setFont(font)
        self.saveCardsTextEdit = QTextEdit(self.centralwidget)
        self.saveCardsTextEdit.setObjectName(u"saveCardsTextEdit")
        self.saveCardsTextEdit.setGeometry(QRect(215, 465, 575, 40))
        self.saveCardsTextEdit.setFont(font1)
        self.saveCardsTextEdit.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAlwaysOff)
        self.saveCardsTextEdit.setLineWrapMode(QTextEdit.LineWrapMode.NoWrap)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 800, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Lab03_pattern", None))
        self.readCardsButton.setText(QCoreApplication.translate("MainWindow", u"\u0421\u0447\u0438\u0442\u0430\u0442\u044c \u041a\u0430\u0440\u0442\u043e\u0447\u043a\u0438", None))
        self.cardLabel.setText("")
        self.prevCardButton.setText("")
        self.flipCardButton.setText("")
        self.nextCardButton.setText("")
        self.firstCardButton.setText("")
        self.lastCardButton.setText("")
        self.cardCountLabel.setText(QCoreApplication.translate("MainWindow", u"0 / 0", None))
        self.shuffleDeckButton.setText(QCoreApplication.translate("MainWindow", u"\u041f\u0435\u0440\u0435\u043c\u0435\u0448\u0430\u0442\u044c", None))
        self.changeModeButton.setText(QCoreApplication.translate("MainWindow", u"\u041f\u0440\u043e\u0441\u043c\u043e\u0442\u0440", None))
        self.editCardButton.setText(QCoreApplication.translate("MainWindow", u"\u0418\u0437\u043c\u0435\u043d\u0438\u0442\u044c", None))
        self.addCardButton.setText(QCoreApplication.translate("MainWindow", u"\u0414\u043e\u0431\u0430\u0432\u0438\u0442\u044c", None))
        self.deleteCardButton.setText(QCoreApplication.translate("MainWindow", u"\u0423\u0434\u0430\u043b\u0438\u0442\u044c", None))
        self.saveCardsButton.setText(QCoreApplication.translate("MainWindow", u"\u0421\u043e\u0445\u0440\u0430\u043d\u0438\u0442\u044c \u041a\u0430\u0440\u0442\u043e\u0447\u043a\u0438", None))
    # retranslateUi

