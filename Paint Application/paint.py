from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
import sys

class Window(QMainWindow):
	def __init__(self):
		super().__init__()

		self.setWindowTitle("Paint with PyQt5")

		self.setGeometry(100, 100, 800, 600)

		self.image = QImage(self.size(), QImage.Format_RGB32)

		self.image.fill(Qt.white)

		self.drawing = False
		self.brushSize = 2
		self.brushColor = Qt.black

		self.lastPoint = QPoint()

		mainMenu = self.menuBar()

		fileMenu = mainMenu.addMenu("File")

		b_size = mainMenu.addMenu("Brush Size")

		b_color = mainMenu.addMenu("Brush Color")

		saveAction = QAction("Save", self)
		saveAction.setShortcut("Ctrl + S")
		fileMenu.addAction(saveAction)
		saveAction.triggered.connect(self.save)

		clearAction = QAction("Clear", self)
		clearAction.setShortcut("Ctrl + C")
		fileMenu.addAction(clearAction)
		clearAction.triggered.connect(self.clear)

		pix_4 = QAction("4px", self)
		b_size.addAction(pix_4)
		pix_4.triggered.connect(self.Pixel_4)

		pix_7 = QAction("7px", self)
		b_size.addAction(pix_7)
		pix_7.triggered.connect(self.Pixel_7)

		pix_9 = QAction("9px", self)
		b_size.addAction(pix_9)
		pix_9.triggered.connect(self.Pixel_9)

		pix_12 = QAction("12px", self)
		b_size.addAction(pix_12)
		pix_12.triggered.connect(self.Pixel_12)

		black = QAction("Black", self)
		b_color.addAction(black)
		black.triggered.connect(self.blackColor)

		white = QAction("White", self)
		b_color.addAction(white)
		white.triggered.connect(self.whiteColor)

		green = QAction("Green", self)
		b_color.addAction(green)
		green.triggered.connect(self.greenColor)

		yellow = QAction("Yellow", self)
		b_color.addAction(yellow)
		yellow.triggered.connect(self.yellowColor)

		red = QAction("Red", self)
		b_color.addAction(red)
		red.triggered.connect(self.redColor)


	def mousePressEvent(self, event):

		if event.button() == Qt.LeftButton:
			self.drawing = True
			self.lastPoint = event.pos()

	def mouseMoveEvent(self, event):
		
		if (event.buttons() & Qt.LeftButton) & self.drawing:
			
			painter = QPainter(self.image)
			
			painter.setPen(QPen(self.brushColor, self.brushSize,
							Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))
			
			painter.drawLine(self.lastPoint, event.pos())
			
			self.lastPoint = event.pos()
			self.update()

	def mouseReleaseEvent(self, event):

		if event.button() == Qt.LeftButton:
			self.drawing = False

	def paintEvent(self, event):
		canvasPainter = QPainter(self)
		
		canvasPainter.drawImage(self.rect(), self.image, self.image.rect())

	def save(self):
		filePath, _ = QFileDialog.getSaveFileName(self, "Save Image", "",
						"PNG(*.png);;JPEG(*.jpg *.jpeg);;All Files(*.*) ")

		if filePath == "":
			return
		self.image.save(filePath)

	def clear(self):
		self.image.fill(Qt.white)
		self.update()

	def Pixel_4(self):
		self.brushSize = 4

	def Pixel_7(self):
		self.brushSize = 7

	def Pixel_9(self):
		self.brushSize = 9

	def Pixel_12(self):
		self.brushSize = 12

	def blackColor(self):
		self.brushColor = Qt.black

	def whiteColor(self):
		self.brushColor = Qt.white

	def greenColor(self):
		self.brushColor = Qt.green

	def yellowColor(self):
		self.brushColor = Qt.yellow

	def redColor(self):
		self.brushColor = Qt.red



App = QApplication(sys.argv)

window = Window()

window.show()

sys.exit(App.exec())
