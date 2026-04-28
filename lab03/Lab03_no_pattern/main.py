import sys
import random
from PySide6.QtWidgets import QApplication, QMainWindow, QMessageBox, QInputDialog
from PySide6.QtCore import QTimer
from ui_mainwindow import Ui_MainWindow

class Card:

    def __init__(self, question: str, answer: str):
        self.question = question
        self.answer = answer

class Deck:

    def __init__(self, setted_cards: list = None):
        self.cards = setted_cards if setted_cards is not None else []

    def set_cards(self, setted_cards: list):
        self.cards = setted_cards

    def length(self) -> int:
        return len(self.cards)

    def set_card(self, pos, text, is_answer = False):
        if is_answer:
            self.cards[pos].answer = text
        else:
            self.cards[pos].question = text

    def insert_card(self, pos, card):
        self.cards.insert(pos, card)

    def delete_card(self, pos):
        self.cards.pop(pos)

class MyApp(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Lab03_no_pattern")
        self.deck = Deck()
        self.order = list(range(self.deck.length()))
        self.is_card_flipped = False
        self.animation_timer = None
        self.is_animating = False
        self.edit_mode = False
        self.current_pos = 0
        self.saved_pos = 0

        self.editCardButton.setVisible(False)
        self.addCardButton.setVisible(False)
        self.deleteCardButton.setVisible(False)

        self.readCardsButton.clicked.connect(self.read_cards)
        self.prevCardButton.clicked.connect(self.prev_card)
        self.flipCardButton.clicked.connect(self.flip_card)
        self.nextCardButton.clicked.connect(self.next_card)
        self.firstCardButton.clicked.connect(self.to_first)
        self.lastCardButton.clicked.connect(self.to_last)
        self.shuffleDeckButton.clicked.connect(self.shuffle_deck)
        self.changeModeButton.clicked.connect(self.change_mode)
        self.editCardButton.clicked.connect(self.edit_card)
        self.addCardButton.clicked.connect(self.add_card)
        self.deleteCardButton.clicked.connect(self.delete_card)
        self.saveCardsButton.clicked.connect(self.save_cards)

        self.init_without_cards()

    def read_cards(self):
        file_path = self.readCardsTextEdit.toPlainText()
        if not file_path:
            QMessageBox.warning(self, "Ошибка", "Укажите путь к файлу!")
            return

        cards = []
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                for line_num, line in enumerate(file, 1):
                    line = line.strip()
                    if not line:
                        continue
                    if ':' not in line:
                        raise ValueError(f"Строка {line_num} не содержит ':'!")
                    question = line.split(':', 1)[0].strip()[1:-1]
                    answer = line.split(':', 1)[1].strip()[1:-1]
                    if not question or not answer:
                        raise ValueError(f"Строка {line_num}: пустой вопрос или ответ!")
                    cards.append(Card(question, answer))
        except FileNotFoundError:
            QMessageBox.critical(self, "Ошибка", f"Файл не найден:\n{file_path}")
            return
        except Exception as e:
            QMessageBox.critical(self, "Ошибка", f"Ошибка при чтении файла:\n{e}")
            return
        if not cards:
            QMessageBox.warning(self, "Ошибка", "Файл не содержит карточек!")
            return

        self.deck.set_cards(cards)
        self.current_pos = 0
        self.order = list(range(self.deck.length()))
        QMessageBox.information(self, "Успех", f"Загружено {len(cards)} карточек!")
        self.init_cards()

    def init_cards(self):
        self.cardLabel.setText(f"{self.deck.cards[self.order[self.current_pos]].question}")
        self.cardCountLabel.setText(f"{self.current_pos + 1} / {self.deck.length()}")
        self.set_buttons_enabled(True)

    def init_without_cards(self):
        self.set_buttons_enabled(False)
        if not self.edit_mode:
            self.change_mode()
        self.addCardButton.setEnabled(True)
        self._update_display()

    def set_buttons_enabled(self, enabled):
        self.prevCardButton.setEnabled(enabled)
        self.flipCardButton.setEnabled(enabled)
        self.nextCardButton.setEnabled(enabled)
        self.firstCardButton.setEnabled(enabled)
        self.lastCardButton.setEnabled(enabled)
        self.shuffleDeckButton.setEnabled(enabled)
        self.changeModeButton.setEnabled(enabled)
        self.editCardButton.setEnabled(enabled)
        self.addCardButton.setEnabled(enabled)
        self.deleteCardButton.setEnabled(enabled)

    def prev_card(self):
        if self.current_pos > 0:
            if self.is_card_flipped:
                self.is_card_flipped = False
            self.current_pos -= 1
            self._update_display()

    def flip_card(self):
        if self.is_card_flipped:
            self.cardLabel.setText(f"{self.deck.cards[self.order[self.current_pos]].question}")
            self.is_card_flipped = False
        else:
            self.cardLabel.setText(f"{self.deck.cards[self.order[self.current_pos]].answer}")
            self.is_card_flipped = True


    def next_card(self):
        if self.current_pos < self.deck.length() - 1:
            if self.is_card_flipped:
                self.is_card_flipped = False
            self.current_pos += 1
            self._update_display()

    def to_first(self):
        if self.is_animating:
            return
        if self.current_pos == 0:
            return
        if self.is_card_flipped:
            self.is_card_flipped = False
        self.set_buttons_enabled(False)
        self.is_animating = True
        self._animate_to_first()

    def _animate_to_first(self):
        if self.current_pos == 0:
            self._stop_animation()
            return
        self.current_pos -= 1
        self._update_display()
        self.animation_timer = QTimer.singleShot(30, self._animate_to_first)

    def to_last(self):
        if self.is_animating:
            return
        if self.current_pos == self.deck.length() - 1:
            return
        if self.is_card_flipped:
            self.is_card_flipped = False
        self.set_buttons_enabled(False)
        self.is_animating = True
        self._animate_to_last()

    def _animate_to_last(self):
        if self.current_pos == self.deck.length() - 1:
            self._stop_animation()
            return
        self.current_pos += 1
        self._update_display()
        self.animation_timer = QTimer.singleShot(30, self._animate_to_last)

    def _stop_animation(self):
        if self.animation_timer:
            self.animation_timer.stop()
        self.is_animating = False
        self.set_buttons_enabled(True)

    def _update_display(self):
        if self.deck.length() == 0:
            self.cardLabel.setText("Добавьте новые карточки или загрузите их из файла!")
            self.cardCountLabel.setText("0 / 0")
            return
        if self.is_card_flipped:
            self.cardLabel.setText(f"{self.deck.cards[self.order[self.current_pos]].answer}")
        else:
            self.cardLabel.setText(f"{self.deck.cards[self.order[self.current_pos]].question}")
        self.cardCountLabel.setText(f"{self.current_pos + 1} / {self.deck.length()}")

    def shuffle_deck(self):
        if self.is_card_flipped:
            self.is_card_flipped = False
        random.shuffle(self.order)
        self._update_display()

    def change_mode(self):
        if self.deck.length() > 0:
            self.order = list(range(self.deck.length()))
        self._update_display()
        if self.edit_mode:
            self.shuffleDeckButton.setVisible(True)
            self.editCardButton.setVisible(False)
            self.addCardButton.setVisible(False)
            self.deleteCardButton.setVisible(False)
            self.edit_mode = False
            self.changeModeButton.setText("Просмотр")
        else:
            self.shuffleDeckButton.setVisible(False)
            self.editCardButton.setVisible(True)
            self.addCardButton.setVisible(True)
            self.deleteCardButton.setVisible(True)
            self.edit_mode = True
            self.changeModeButton.setText("Редактирование")

    def edit_card(self):
        if self.is_card_flipped:
            text, ok = QInputDialog.getText(self, "Окно ввода", f"Введите ответ для карточки:\n{self.deck.cards[self.order[self.current_pos]].question} : {self.deck.cards[self.order[self.current_pos]].answer}")
            if ok and text:
                self.saved_pos = self.order[self.current_pos]
                self.deck.set_card(self.saved_pos, text, True)
                self.current_pos = self.saved_pos
                self.order = list(range(self.deck.length()))
                self._update_display()
        else:
            text, ok = QInputDialog.getText(self, "Окно ввода", f"Введите вопрос для карточки:\n{self.deck.cards[self.order[self.current_pos]].question} : {self.deck.cards[self.order[self.current_pos]].answer}")
            if ok and text:
                self.saved_pos = self.order[self.current_pos]
                self.deck.set_card(self.saved_pos, text)
                self.current_pos = self.saved_pos
                self.order = list(range(self.deck.length()))
                self._update_display()

    def add_card(self):
        text, ok = QInputDialog.getText(self, "Окно ввода", f"Введите данные для новой карточки в формате:\n\"Вопрос\" : \"Ответ\"")
        if ok and text:
            if self.deck.length() == 0:
                self.saved_pos = 0
            else:
                self.saved_pos = self.order[self.current_pos] + 1
            question = text.split(':', 1)[0].strip()[1:-1]
            answer = text.split(':', 1)[1].strip()[1:-1]
            new_card = Card(question, answer)
            self.deck.insert_card(self.saved_pos, new_card)
            self.current_pos = self.saved_pos
            self.order = list(range(self.deck.length()))
            self._update_display()
            if self.deck.length() == 1:
                self.set_buttons_enabled(True)

    def delete_card(self):
        if self.deck.length() != 0:
            reply = QMessageBox.question(self, "Подтверждение", f"Вы уверены, что хотите удалить карточку:\n{self.deck.cards[self.order[self.current_pos]].question} : {self.deck.cards[self.order[self.current_pos]].answer}", QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No, QMessageBox.StandardButton.No)
            if reply == QMessageBox.StandardButton.Yes:
                self.saved_pos = self.order[self.current_pos]
                self.deck.delete_card(self.saved_pos)
                if self.saved_pos > 0:
                    self.saved_pos -= 1
                if self.deck.length() == 0:
                    self.init_without_cards()
                else:
                    self.current_pos = self.saved_pos
                    self.order = list(range(self.deck.length()))
                    self._update_display()

    def save_cards(self):
        if self.deck.length() == 0:
            QMessageBox.warning(self, "Ошибка", "Нет карточек для сохранения!")
            return
        file_path = self.saveCardsTextEdit.toPlainText().strip()
        if not file_path:
            QMessageBox.warning(self, "Ошибка", "Укажите путь для сохранения в текстовом поле!")
            return
        try:
            with open(file_path, 'w', encoding='utf-8') as file:
                self.saved_pos = self.current_pos
                self.current_pos = 0
                while True:
                    file.write(f"\"{self.deck.cards[self.order[self.current_pos]].question}\" : \"{self.deck.cards[self.order[self.current_pos]].answer}\"\n")
                    if self.current_pos == self.deck.length() - 1:
                        break
                    self.current_pos += 1
                self.current_pos = self.saved_pos
                QMessageBox.information(self, "Успех", f"Колода сохранена в:\n{file_path}\nВсего карточек: {self.deck.length()}!")
        except Exception as e:
            QMessageBox.critical(self, "Ошибка", f"Не удалось сохранить файл:\n{e}")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec())