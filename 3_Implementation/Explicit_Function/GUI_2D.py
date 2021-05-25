from PyQt5.QtWidgets import *
from PyQt5.QtCore import *

from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
from matplotlib.pyplot import imsave
import numpy as np
import sys

import Decode
import Code


Min = -10
Max = 10
prec = 500


class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        """ CENTRAL WIDGET """ 
        self.form = Form()
        self.setCentralWidget(self.form)
        self.setMinimumSize(QSize(500, 500))    
        self.setWindowTitle("GRAPHILIA")
         
class Form(QDialog) :
    def __init__(self, parent=None) :
        super(Form, self).__init__(parent)
        self.plot = MatplotlibCanvas()
        self.function_edit = QLineEdit('')
        self.Min_edit = QLineEdit(str(Min))
        self.Min_edit.selectAll()
        self.Max_edit = QLineEdit(str(Max))
        self.Max_edit.selectAll()
        self.clear_button = QPushButton('Clear')
        Minlabel = QLabel('Min X')
        Maxlabel = QLabel('Max X')
        grid = QGridLayout()
        grid.setSpacing(15)
        grid.addWidget(self.plot, 0,0, 1,8)
        grid.addWidget(self.function_edit, 1,1, 1,6)
        grid.addWidget(Minlabel, 2,1)
        grid.addWidget(self.Min_edit, 2,2)
        grid.addWidget(Maxlabel, 2,3)
        grid.addWidget(self.Max_edit, 2,4)
        grid.addWidget(self.clear_button, 2,6)
        self.setLayout(grid)
        self.function_edit.setFocus()
        self.function_edit.returnPressed.connect(self.updateUI)
        self.Max_edit.returnPressed.connect(self.updateUI)
        self.Min_edit.returnPressed.connect(self.updateUI)
        self.clear_button.clicked.connect(self.plot.initial_figure)
        
    def updateUI(self):
        try :
            Min = float(self.Min_edit.text())
            Max = float(self.Max_edit.text())
            x = np.linspace(Min, Max, prec)
            Inp_expr = self.function_edit.text()
            if (Code.braceChk(Inp_expr)):
                Infx_expr = Code.codeInp(Inp_expr)
                Postfx_expr = Code.Infix_2_Postfix(Infx_expr)
            else:
                return
            y = Decode.value(Postfx_expr, x)
            self.plot.update_figure(x, y)
        except Exception as e:
            self.function_edit.setText(str(e))


class MatplotlibCanvas(FigureCanvas) :
    def __init__(self, parent=None, width=5, height=4, dpi=100) :
        self.fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = self.fig.add_subplot(111)
        self.initial_figure()
        FigureCanvas.__init__(self, self.fig)
        self.setParent(parent)
        FigureCanvas.setSizePolicy(self, QSizePolicy.Expanding, QSizePolicy.Expanding)
        FigureCanvas.updateGeometry(self)

    def initial_figure(self):
        self.minY = Min
        self.maxY = Max
        self.axes.cla()
        self.axes.set_xlabel('x', fontsize = 13)
        self.axes.set_ylabel('f(x)', fontsize = 13)
        self.axes.set_xlim(Min, Max)
        self.axes.set_ylim(Min, Max)
        self.axes.axvline(0, color = 'black')
        self.axes.axhline(0, color = 'black')
        self.axes.grid()
        
    def update_figure(self, x, y):
        if (min(y) < self.minY) and (min(y) != -np.float64('inf')):
            self.minY = min(y)
        if (max(y) > self.maxY) and (max(y) != np.float64('inf')):
            self.maxY = max(y)        
        if (max(x) > 0) and (min(x) < 0):
            self.axes.axvline(0, color = 'black')
        if (max(y) > 0) and (min(y) < 0):
            self.axes.axhline(0, color = 'black')
        self.axes.plot(x, y)
        self.axes.set_xlabel('x', fontsize = 13)
        self.axes.set_ylabel('f(x)', fontsize = 13)
        self.axes.grid()
        self.axes.set_xlim(min(x), max(x))
        self.axes.set_ylim(self.minY, self.maxY)
        self.axes.grid()
        self.draw()
        
if not QApplication.instance():
    app = QApplication(sys.argv)
else:
    app = QApplication.instance()
main = MainWindow()
main.show()
app.exec_()