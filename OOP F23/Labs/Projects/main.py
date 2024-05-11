import os
import shutil

def delete_unwanted_files(folder_path):
    for root, dirs, files in os.walk(folder_path, topdown=True):
        # Check if the current folder contains only .cpp and .h files
        only_cpp_h_files = all(file.endswith((".cpp", ".h")) for file in files)
        if not only_cpp_h_files:
            for file in files:
                if file != "main.py":
                    file_path = os.path.join(root, file)
                    if not file.endswith((".cpp", ".h")):
                        os.remove(file_path)
            for name in dirs:
                dir_path = os.path.join(root, name)
                files_to_keep = [f for f in os.listdir(dir_path) if f.endswith((".cpp", ".h"))]
                for file_to_keep in files_to_keep:
                    dest_path = os.path.join(root, file_to_keep)
                    if dest_path != dir_path:
                        shutil.move(os.path.join(dir_path, file_to_keep), dest_path)
                if dir_path != folder_path and not os.listdir(dir_path):
                    os.rmdir(dir_path)

            # After moving files, delete all subdirectories within the parent folder
            if root != folder_path:
                for sub_dir in dirs:
                    sub_dir_path = os.path.join(root, sub_dir)
                    shutil.rmtree(sub_dir_path)

if __name__ == "__main__":
    current_directory = os.getcwd()
    delete_unwanted_files(current_directory)
    print("Unwanted files and empty subdirectories have been deleted successfully.")
