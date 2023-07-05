import sys
import traceback
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton

class Example(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self): 
        self.setGeometry(300, 300, 300, 300)
        self.setWindowTitle('Первая программа')

        btn = QPushButton("->", self)
        btn.setGeometry(100, 100, 50, 20)
        btn.clicked.connect(self.tap)

    def tap(self):
        print(0/0)

def excepthook(exc_type, exc_value, exc_tb):
    tb = "".join(traceback.format_exception(exc_type, exc_value, exc_tb))
    print("Oбнаружена ошибка !:", tb)


if __name__ == '__main__':
    sys.excepthook = excepthook
    app = QApplication(sys.argv)
    ex = Example()
    ex.show()
    sys.exit(app.exec())