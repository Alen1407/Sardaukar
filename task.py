import sys
import os
import shutil
import argparse

parser = argparse.ArgumentParser()

parser.add_argument('path', metavar = 'path', type = str, help = 'the path to list')
parser.add_argument('-v', '--version', action = 'store_true', help = 'show program`s version number and exit')
args = parser.parse_args()

if args.version:
    print('0.0.1')

folder_name = args.path

try:
    os.chdir(folder_name)
except:
    print("No such directory")
    exit()

number_of_files = len(os.listdir(folder_name))
try: os.mkdir("Images")
except: pass
try: os.mkdir("Texts")
except: pass
try: os.mkdir("Documents")
except: pass
try: os.mkdir("Other")
except: pass

documents_extensions = ('.pdf', '.docx', '.doc', '.xlsx', '.xls', 'csv')
texts_extensions = ('.txt', '.ini', '.log')
images_extensions = ('.png', '.jpg', '.jpeg', '.gif', '.bmp')

for item in os.listdir():
    file_extension = os.path.splitext(item)[1]
    if file_extension in documents_extensions:
        shutil.move(item, folder_name + '/Documents')
    elif file_extension in texts_extensions:
        shutil.move(item, folder_name + '/Texts')
    elif file_extension in images_extensions:
        shutil.move(item, folder_name + '/Images')
    elif not os.path.isdir(item):
        shutil.move(item, folder_name + '/Other')

print('Organized ' + str(number_of_files) + ' files')
