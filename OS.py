import sys
from PyQt5.QtWidgets import QApplication, QFileDialog, QInputDialog, QMainWindow, QMessageBox, QPlainTextEdit, QTreeView, QFileSystemModel, QVBoxLayout, QMenu, QAction, QWidget
from PyQt5.QtCore import QThread, pyqtSignal
import os
import subprocess
import time

# CustomThread class inherits from QThread to create a separate thread for executing tasks
class CustomThread(QThread):
    progress = pyqtSignal(str)
    finished = pyqtSignal(str)

    def __init__(self, thread_name, shared_data, text_output):
        super().__init__()
        self.thread_name = thread_name
        self.shared_data = shared_data
        self.text_output = text_output

    def run(self):
        for i in range(5):
            time.sleep(1)
            # Emit progress updates during the thread's execution
            progress_message = f"{self.thread_name}: Working... {i + 1}/5"
            self.progress.emit(progress_message)

        # Emit finished signal when the thread completes its task
        result_message = f"{self.thread_name}: Task completed!"
        self.finished.emit(result_message)
        self.text_output.appendPlainText(result_message)

# CustomProcess class inherits from QThread to manage external processes
class CustomProcess(QThread):
    finished = pyqtSignal(str)

    def __init__(self, process_name, shared_data, text_output):
        super().__init__()
        self.process_name = process_name
        self.shared_data = shared_data
        self.text_output = text_output

    def run(self):
        # Simulating an external process
        result_message = subprocess.check_output(['echo', 'Hello from ' + self.process_name]).decode('utf-8')
        # Emit finished signal when the process completes
        self.finished.emit(result_message)
        self.text_output.appendPlainText(result_message)

# ProcessManager class inherits from QThread to manage process creation and termination
class ProcessManager(QThread):
    process_created = pyqtSignal(str)
    process_ended = pyqtSignal(str)

    def __init__(self, text_output):
        super().__init__()
        self.text_output = text_output
        self.process_id = 1
        self.processes = {}

    def run(self):
        while True:
            time.sleep(1)

    def create_process(self, process_name):
        custom_process = CustomProcess(process_name, {}, self.text_output)
        custom_process.finished.connect(self.process_ended)
        custom_process.start()
        self.processes[self.process_id] = custom_process
        self.process_created.emit(f"Process {self.process_id} created.")
        self.process_id += 1

    def end_process(self, process_id):
        process = self.processes.get(process_id)
        if process:
            process.terminate()
            result_message = f"Process {process_id} terminated."
            self.process_ended.emit(result_message)
            self.processes.pop(process_id)
        else:
            result_message = f"Process {process_id} not found."
            self.process_ended.emit(result_message)

# CustomOS class provides the main application window
class CustomOS(QMainWindow):
    def __init__(self):
        super().__init__()
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Custom OS')

        # Setting up the file system model and view
        file_model = QFileSystemModel()
        file_model.setRootPath(os.path.expanduser('~'))
        file_tree = QTreeView()
        file_tree.setModel(file_model)
        file_tree.setRootIndex(file_model.index(os.path.expanduser('~')))

        # Creating menus and actions for the main window
        process_menu = QMenu('Processes', self)
        create_process_action = QAction('Create Process', self)
        create_process_action.triggered.connect(self.create_process_dialog)
        process_menu.addAction(create_process_action)

        kill_process_action = QAction('Kill Process', self)
        kill_process_action.triggered.connect(self.kill_process_dialog)
        process_menu.addAction(kill_process_action)

        thread_menu = QMenu('Threads', self)
        create_thread_action = QAction('Create Thread', self)
        create_thread_action.triggered.connect(self.create_thread)
        thread_menu.addAction(create_thread_action)

        # Adding menus to the menu bar
        main_menu = self.menuBar()
        file_menu = main_menu.addMenu('File')
        file_menu.addAction('Create Folder', self.create_folder)
        file_menu.addAction('Create File', self.create_file)
        file_menu.addAction('Change Rights', self.change_rights)
        file_menu.addAction('Search Files', self.search_files)
        file_menu.addAction('Open Application', self.open_application)

        main_menu.addMenu(process_menu)
        main_menu.addMenu(thread_menu)

        layout = QVBoxLayout()
        layout.addWidget(file_tree)

        self.text_output = QPlainTextEdit(self)
        layout.addWidget(self.text_output)

        central_widget = QWidget()
        central_widget.setLayout(layout)
        self.setCentralWidget(central_widget)

        # Shared data between processes and threads
        self.shared_data = {"Process1": "", "Process2": "", "Thread1": "", "Thread2": ""}

        # Store custom threads and processes
        self.custom_threads = []
        self.custom_processes = []

        # Create and start the process manager
        self.process_manager = ProcessManager(self.text_output)
        self.process_manager.process_created.connect(self.process_created)
        self.process_manager.process_ended.connect(self.process_ended)
        self.process_manager.start()

    def create_folder(self):
        folder_name, ok_pressed = QInputDialog.getText(self, 'Create Folder', 'Enter folder name:')
        if ok_pressed and folder_name:
            try:
                os.makedirs(folder_name)
                result_message = f"Folder '{folder_name}' created successfully."
                self.text_output.appendPlainText(result_message)
            except Exception as e:
                error_message = f"Error creating folder: {e}"
                self.text_output.appendPlainText(error_message)

    def create_file(self):
        file_name, ok_pressed = QInputDialog.getText(self, 'Create File', 'Enter file name:')
        if ok_pressed and file_name:
            try:
                with open(file_name, 'w'):
                    pass
                result_message = f"File '{file_name}' created successfully."
                self.text_output.appendPlainText(result_message)
            except Exception as e:
                error_message = f"Error creating file: {e}"
                self.text_output.appendPlainText(error_message)

    def change_rights(self):
        file_name, ok_pressed = QInputDialog.getText(self, 'Change Rights', 'Enter file name:')
        if ok_pressed and file_name:
            try:
                permissions, ok_pressed = QInputDialog.getText(self, 'Change Rights', 'Enter new permissions (e.g., 755):')
                if ok_pressed and permissions:
                    os.chmod(file_name, int(permissions, 8))
                    result_message = f"Rights for '{file_name}' changed successfully."
                    self.text_output.appendPlainText(result_message)
            except Exception as e:
                error_message = f"Error changing file rights: {e}"
                self.text_output.appendPlainText(error_message)

    def search_files(self):
        file_path, _ = QFileDialog.getOpenFileName(self, 'Search Files', os.path.expanduser('~'))
        if file_path:
            result_message = f"File selected: {file_path}"
            self.text_output.appendPlainText(result_message)

    def open_application(self):
        app_name, ok_pressed = QInputDialog.getText(self, 'Open Application', 'Enter application name:')
        if ok_pressed and app_name:
            subprocess.run([app_name])

    def create_process_dialog(self):
        process_name, ok = QInputDialog.getText(self, 'Create Process', 'Enter process name:')
        if ok:
            self.process_manager.create_process(process_name)

    def kill_process_dialog(self):
        process_id, ok_pressed = QInputDialog.getInt(self, 'Kill Process', 'Enter process ID:')
        if ok_pressed:
            self.process_manager.end_process(process_id)

    def create_thread(self):
        thread_name, ok = QInputDialog.getText(self, 'Create Thread', 'Enter thread name:')
        if ok:
            custom_thread = CustomThread(thread_name, self.shared_data, self.text_output)
            custom_thread.finished.connect(self.thread_finished)
            custom_thread.progress.connect(self.update_progress)
            custom_thread.start()
            self.custom_threads.append(custom_thread)

    def process_created(self, result):
        self.text_output.appendPlainText(result)

    def process_ended(self, result):
        self.text_output.appendPlainText(result)

    def thread_finished(self, result):
        # Update shared data when a thread finishes
        sender_thread_name = self.sender().thread_name
        self.shared_data[sender_thread_name] = result
        result_message = f'Thread {sender_thread_name} finished with result: {result}'
        self.text_output.appendPlainText(result_message)

    def update_progress(self, progress_message):
        # Update progress messages from threads
        self.text_output.appendPlainText(progress_message)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    custom_os = CustomOS()
    custom_os.show()
    sys.exit(app.exec_())
