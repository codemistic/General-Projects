from PyQt5 import QtCore, QtGui, QtWidgets
from collections import Counter
class Ui_MainWindow(object):
    res1=''
    res2=''
    inp1=''
    inp2=''
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("Flames")
        MainWindow.resize(480, 640)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.bg = QtWidgets.QLabel(self.centralwidget)
        self.bg.setGeometry(QtCore.QRect(-30, -30, 521, 711))
        self.bg.setText("")
        self.bg.setPixmap(QtGui.QPixmap("D:\\Projects\\RegProj3\\pic\\flame2.png"))
        self.bg.setScaledContents(True)
        self.bg.setObjectName("bg")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(100, 220, 91, 21))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.label.setStyleSheet("color: white")
        self.label.setFont(font)
        self.label.setMidLineWidth(3)
        self.label.setTextFormat(QtCore.Qt.PlainText)
        self.label.setObjectName("label")
        self.textEdit = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit.setGeometry(QtCore.QRect(70, 250, 151, 41))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.textEdit.setStyleSheet("background-color: rgb(255,0,0,0.3);border: 1px solid white")
        self.textEdit.setFont(font)
        self.textEdit.setObjectName("textEdit")

        
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(290, 220, 91, 21))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setStyleSheet("color: white")
        self.label_2.setFont(font)
        self.label_2.setMidLineWidth(3)
        self.label_2.setTextFormat(QtCore.Qt.PlainText)
        self.label_2.setObjectName("label_2")
        self.textEdit_2 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_2.setGeometry(QtCore.QRect(260, 250, 151, 41))
        self.textEdit_2.setStyleSheet("background-color: rgb(255,0,0,0.3);border: 1px solid white")
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(100)
        self.textEdit_2.setFont(font)
        self.textEdit_2.setObjectName("textEdit_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(160, 350, 171, 21))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(17)
        font.setBold(True)
        font.setUnderline(True)
        font.setWeight(75)
        self.label_3.setStyleSheet("color: white")
        self.label_3.setFont(font)
        self.label_3.setMidLineWidth(3)
        self.label_3.setTextFormat(QtCore.Qt.PlainText)
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(230, 320, 16, 21))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setStyleSheet("color: white")
        self.label_4.setFont(font)
        self.label_4.setMidLineWidth(3)
        self.label_4.setTextFormat(QtCore.Qt.PlainText)
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(230, 260, 16, 21))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)
        self.label_5.setStyleSheet("color: white")
        self.label_5.setFont(font)
        self.label_5.setMidLineWidth(3)
        self.label_5.setTextFormat(QtCore.Qt.PlainText)
        self.label_5.setObjectName("label_5")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)

        self.label_6.setGeometry(QtCore.QRect(170, 400, 170, 50))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)
        self.label_6.setFont(font)
        self.label_6.setMidLineWidth(3)
        self.label_6.setText("")
        self.label_6.setTextFormat(QtCore.Qt.PlainText)
        self.label_6.setObjectName("label_6")
        self.label_6.setAlignment(QtCore.Qt.AlignCenter)
        
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setGeometry(QtCore.QRect(0, 400, 481, 221))
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)

        self.label_7.setFont(font)
        self.label_7.setMidLineWidth(3)
        self.label_7.setText("")
        self.label_7.setTextFormat(QtCore.Qt.PlainText)
        self.label_7.setObjectName("label_7")
        
        
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(180, 530, 111, 41))
        self.pushButton.setObjectName("pushButton")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.pushButton.setStyleSheet("background-color: rgb(255,0,0,0.3);border: 1px solid white;color: white;border-radius: 50px")
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)
        
        self.pushButton.clicked.connect(self.calculate)
        self.label_7.mousePressEvent = self.delevry
        
        
    def delevry(self,event):
        self.textEdit.setText("")
        self.textEdit_2.setText("")
        self.label_6.setText("")
        
        
    def calculate(self):
        self.inp1 = self.textEdit.toPlainText()
        self.inp2 = self.textEdit_2.toPlainText()
        total_len = self.removeDup(self.inp1.lower(),self.inp2.lower())
        lst = ['F','L','A','M','E','S']
        indx = 0
        while(len(lst)> 1):
            if indx == -1:
                indx = 0
            indx =  (indx + total_len) % len(lst) - 1
            lst.pop(indx)
        if total_len == 0:
            self.label_6.setText(" ")
        else:
            res = {'F':['Friendship','rgb(5, 66, 158)'],'L':['Lovers','rgb(135, 5, 77)'],'A':['Affectionate','rgb(187, 64, 214)'],'M':['Marriage','rgb(196, 219, 20)'],'E':['Enemies','rgb(245, 2, 2)'],'S':['Sibling','rgb(2, 245, 30)']}
            self.label_6.setText(res[lst[0]][0])
            color = res[lst[0]][1]
            self.label_6.setStyleSheet('color : {};border: 2px solid white;background-color: rgb(242, 242, 242,0.1);'.format(color))
        # (242, 244, 248,0.3)
    
    def removeDup(self,inp1, inp2):
        ocur = Counter(inp1)

        for i in inp2:
            ocur[i] -= 1;

        ans = 0
        for i in ocur:
            if ocur[i] != 0:
                ans += abs(ocur[i])
        return ans
        

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "FLAMES"))
        self.label.setText(_translate("MainWindow", "1st Name:"))
        self.label_2.setText(_translate("MainWindow", "2nd Name:"))
        self.label_3.setText(_translate("MainWindow", "Your Relation"))
        self.label_4.setText(_translate("MainWindow", "="))
        self.label_5.setText(_translate("MainWindow", "+"))
        self.pushButton.setText(_translate("MainWindow", "Find Relation"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
