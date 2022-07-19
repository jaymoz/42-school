import os
import sys

try:
    get_name = os.environ['VIRTUAL_ENV'].split("/")[-1]
    if get_name == 'lross':
        os.system('pip3 install -r requirements.txt')
        os.system('pip3 freeze')
        os.system('pip3 freeze > result.txt')
    else:
        print("wrong virtual environment")

except Exception as e:
    print(e, type(e));
    sys.exit(1)
