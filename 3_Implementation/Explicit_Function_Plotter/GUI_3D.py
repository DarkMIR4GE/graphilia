from PyQt5.QtWidgets import *
from PyQt5.QtCore import *

from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import sys

import Decode
import Code


minX = -1
maxX = 1
minY = -1
maxY = 1
precX = 500
precY = 500
prec = 10e-3

class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        """init display UI"""
        super(MainWindow, self).__init__(parent)

        self.form = Form()
        self.setCentralWidget(self.form)
        self.setMinimumSize(QSize(500, 500))
        self.setWindowTitle("GRAPHILIA")

class Form(QDialog) :
    def __init__(self, parent=None) :
        super(Form, self).__init__(parent)
        self.plot = MatplotlibCanvas()
        self.function_edit = QLineEdit('')
        self.MinX_edit = QLineEdit(str(minX))
        self.MinX_edit.selectAll()
        self.MaxX_edit = QLineEdit(str(maxX))
        self.MaxX_edit.selectAll()
        self.MinY_edit = QLineEdit(str(minY))
        self.MinY_edit.selectAll()
        self.MaxY_edit = QLineEdit(str(maxY))
        self.MaxY_edit.selectAll()
        self.clear_button = QPushButton('Clear')
        MinX_label = QLabel('Min X')
        MaxX_label = QLabel('Max X')
        MinY_label = QLabel('Min Y')
        MaxY_label = QLabel('Max Y')
        grid = QGridLayout()
        grid.setSpacing(15)
        grid.addWidget(self.plot, 0,0, 1,8)
        grid.addWidget(self.function_edit, 1,1, 1,6)
        grid.addWidget(MinX_label, 2,1)
        grid.addWidget(self.MinX_edit, 2,2)
        grid.addWidget(MaxX_label, 2,3)
        grid.addWidget(self.MaxX_edit, 2,4)
        grid.addWidget(MinY_label, 3,1)
        grid.addWidget(self.MinY_edit, 3,2)
        grid.addWidget(MaxY_label, 3,3)
        grid.addWidget(self.MaxY_edit, 3,4)
        grid.addWidget(self.clear_button, 2,6, 2,1)
        self.setLayout(grid)
        self.function_edit.setFocus()
        self.function_edit.returnPressed.connect(self.updateUI)
        self.MaxX_edit.returnPressed.connect(self.updateUI)
        self.MinX_edit.returnPressed.connect(self.updateUI)
        self.MaxY_edit.returnPressed.connect(self.updateUI)
        self.MinY_edit.returnPressed.connect(self.updateUI)
        self.clear_button.clicked.connect(self.plot.initial_figure)

    def updateUI(self):
        try :
            MinX = float(self.MinX_edit.text())
            MaxX = float(self.MaxX_edit.text())
            MinY = float(self.MinY_edit.text())
            MaxY = float(self.MaxY_edit.text())
            x = np.linspace(MinX, MaxX, precX)
            y = np.linspace(MinY, MaxY, precY)
            z = []
            Inp_expr = self.function_edit.text()
            if (Code.braceChk(Inp_expr)):
                Infx_expr = Code.codeInp(Inp_expr)
                Postfx_expr = Code.Infix_2_Postfix(Infx_expr)
            else:
                return
            y_tmp = np.ndarray(len(x))
            for yi in y:
                y_tmp[:] = yi
                z = np.append(z, Decode.value(Postfx_expr, x, y_tmp))
            X = np.outer(np.ones_like(y),x)
            Y = np.outer(y,np.ones_like(x))
            Z = np.reshape(z,(len(x),len(y)))
            self.plot.update_figure(X, Y, Z)
        except Exception as e:
            self.function_edit.setText(str(e))


class MatplotlibCanvas(FigureCanvas) :
    def __init__(self, parent=None, width=5, height=4, dpi=100) :
        """init axes UI"""
        self.fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = self.fig.add_subplot(111, projection = '3d')
        self.initial_figure()
        FigureCanvas.__init__(self, self.fig)
        self.setParent(parent)
        FigureCanvas.setSizePolicy(self, QSizePolicy.Expanding, QSizePolicy.Expanding)
        FigureCanvas.updateGeometry(self)

    def initial_figure(self):
        self.MinZ = minX
        self.MaxZ = maxX
        self.axes.cla()
        self.axes.set_xlabel('X', fontsize = 13)
        self.axes.set_ylabel('Y', fontsize = 13)
        self.axes.set_zlabel('Z', fontsize = 13)
        self.axes.set_xlim(minX, maxX)
        self.axes.set_ylim(minY, maxY)
        self.axes.set_zlim(minX, maxX)
        self.axes.grid()

    def update_figure(self, x, y, z):
        if (np.ndarray.min(z) < self.MinZ) and (np.ndarray.min(z) != -np.float64('inf')):
            self.MinZ = np.ndarray.min(z)
        if (np.ndarray.max(z) > self.MaxZ) and (np.ndarray.max(z) != np.float64('inf')):
            self.MaxZ = np.ndarray.max(z)
        self.axes.plot_surface(x, y, z)#, cmap = 'viridis')
        self.axes.set_xlabel('X', fontsize = 13)
        self.axes.set_ylabel('Y', fontsize = 13)
        self.axes.set_zlabel('Z', fontsize = 13)
        self.axes.grid()
        self.axes.set_xlim(np.ndarray.min(x), np.ndarray.max(x))
        self.axes.set_ylim(np.ndarray.min(y), np.ndarray.max(y))
        self.axes.set_zlim(self.MinZ, self.MaxZ)
        self.axes.grid()
        self.draw()


if not QApplication.instance():
    app = QApplication(sys.argv)
else:
    app = QApplication.instance()
main = MainWindow()
main.show()
app.exec_()
